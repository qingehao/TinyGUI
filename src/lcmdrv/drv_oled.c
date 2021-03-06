#include <rtdevice.h>
#include "drv_spi.h"
#include "drv_oled.h"
#include "tg_font.h"
#define DBG_SECTION_NAME    "OLED_096"
#define DBG_COLOR
#define DBG_LEVEL           DBG_LOG
#include <rtdbg.h>

#define OLED_CMD            0   
#define OLED_DATA           1  

#define OLED_DC_PIN    GET_PIN(B, 2)
#define OLED_RES_PIN   GET_PIN(B, 12)
 
static struct rt_spi_device *spi_dev_oled;
static void oled_gpio_init(void);
static void oled_dc_set(rt_uint8_t state);
volatile static uint8_t oledGram[128][8];
static int rt_hw_oled_config(void)
{
    spi_dev_oled = (struct rt_spi_device *)rt_device_find("spi20");

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
        cfg.max_hz = 42 * 1000 * 1000; /* 42M,SPI max 42MHz,lcd 4-wire spi */

        rt_spi_configure(spi_dev_oled, &cfg);
    }

    return RT_EOK;
}
/**
* @brief 切换数据或者命令模式
* @param state:0:命令,1:数据
*/
static void oled_dc_set(uint8_t state)
{
    if (state)
    {
       rt_pin_write(OLED_DC_PIN,PIN_HIGH);
    }
    else
    {
       rt_pin_write(OLED_DC_PIN,PIN_LOW);
    }
}
/**
* @brief 复位
* @param mode:0:片选,1:未选
*/
static void oled_res_set(uint8_t state)
{
    if (state)
    {
       rt_pin_write(OLED_RES_PIN,PIN_HIGH);
    }
    else
    {
       rt_pin_write(OLED_RES_PIN,PIN_LOW);
    }
}
rt_err_t oled_write_byte(uint8_t dat,uint8_t cmd)
{  
	  rt_size_t len;
    //设置传输模式
    oled_dc_set(cmd);

	  len = rt_spi_send(spi_dev_oled, &dat, 1);
    if (len != 1)
    {
        LOG_I("oled_write_cmd error. %d", len);
        return -RT_ERROR;
    }
    else
    {
        return RT_EOK;
    }

} 
static void oled_gpio_init(void)
{
    rt_hw_oled_config();

    rt_pin_mode(OLED_DC_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(OLED_RES_PIN, PIN_MODE_OUTPUT);

    rt_pin_write(OLED_RES_PIN, PIN_HIGH);

    rt_thread_delay(RT_TICK_PER_SECOND / 10);
    rt_pin_write(OLED_RES_PIN, PIN_HIGH);
}	 
void oled_refreshGram(void)
{
	uint8_t i,n;		    
	for(i=0;i<8;i++)  
	{  
		oled_write_byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		oled_write_byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		oled_write_byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)
			oled_write_byte(oledGram[n][i],OLED_DATA); 
	}   
}
void oled_displayON(void)
{
	oled_write_byte(0X8D,OLED_CMD);  //SET DCDC命令
	oled_write_byte(0X14,OLED_CMD);  //DCDC ON
	oled_write_byte(0XAF,OLED_CMD);  //DISPLAY ON
}   
void oled_displayOFF(void)
{
	oled_write_byte(0X8D,OLED_CMD);  //SET DCDC命令
	oled_write_byte(0X10,OLED_CMD);  //DCDC OFF
	oled_write_byte(0XAE,OLED_CMD);  //DISPLAY OFF
}	
 
void oled_clear(void)  
{  
	uint8_t i,n;  
	for(i=0;i<8;i++)
		for(n=0;n<128;n++)
			oledGram[n][i]=0X00;  
	oled_refreshGram();//更新显示
}
/**
* @brief 画点
* @param 
*/		   
void oled_drawPoint(uint8_t x,uint8_t y,uint8_t t)
{
	uint8_t pos,bx,temp=0;
	if(x>127||y>63)return;//超出范围了.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)oledGram[x][pos]|=temp;
	else oledGram[x][pos]&=~temp;	    
}
/**
* @brief 读点
* @param 
*/	
uint8_t oled_readPoint(uint8_t x,uint8_t y)
{
	uint8_t pos,bx,temp=0x00;
	//x = 127-x;
	y = 63-y;
	pos=y/8;
	bx=y%8;
	temp=1<<bx;
  if(temp&oledGram[x][pos]) return 1;
	return 0;
}
/**
* @brief 填充
* @param 
*/	  
void oled_fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot)  
{  
	uint8_t x,y;  
	for(x=x1;x<=x2;x++)
		for(y=y1;y<=y2;y++)
			oled_drawPoint(x,y,dot);											    
}			 
void oled_showChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t f_w,uint8_t f_h,uint8_t mode)
{      			    
	uint8_t temp,t,t1;
	uint8_t y0=y;	
	uint8_t csize=(f_h/8+((f_h%8)?1:0))*f_w;//得到自由分辨字符所占的字节数
	chr=chr-' ';//得到偏移后的值		 
	for(t=0;t<csize;t++)
	{   
		if(f_w==6&&f_h==8)temp=asc2_0608[chr][t];		//调用0608ascii字体
		else if(f_w==6&&f_h==12)temp=asc2_0612[chr][t];	//调用0612ascii字体
		else if(f_w==8&&f_h==16)temp=asc2_0816[chr][t];	//调用0612ascii字体
		else if(f_w==12&&f_h==24)temp=asc2_1224[chr][t];//调用1224ascii字体
		else return;	//没有的字库
		for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)oled_drawPoint(x,y,mode);
			else oled_drawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==f_h)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
	}     
}
//m^n函数
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//f_w:字宽
//f_h:字高
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);	 		  
void oled_showNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t f_w,uint8_t f_h)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				oled_showChar(x+(f_w)*t,y,' ',f_w,f_h,1);
				continue;
			}
			else 
				enshow=1; 
		}
	 	oled_showChar(x+(f_w)*t,y,temp+'0',f_w,f_h,1); 
	}
}
//显示字符串
//x,y:起点坐标  
//f_w:字宽
//f_h:字高
//*p:字符串起始地址 
void oled_showString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t f_w,uint8_t f_h)
{	
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>(128-(f_w))){x=0;y+=f_h;}
        if(y>(64-f_h)){y=x=0;oled_clear();}
        oled_showChar(x,y,*p,f_w,f_h,1);	 
        x+=f_w;
        p++;
    }
}
//显示图片
//x,y:起点坐标  
//p_w:图片宽（单位像素）
//p_h:图片高（单位像素）
//*p:图片起始地址 
void oled_showPicture(uint8_t x,uint8_t y,const uint8_t *p,uint8_t p_w,uint8_t p_h)
{	
	uint8_t temp,i,col,row;
	uint8_t y0=y;
	uint8_t width=p_w;
	if(x+p_w>128)width=128-p_w;//实际显示宽度
	uint8_t high=p_h;
	if(y+p_h>64)high=64-p_h;//实际显示高度
	uint8_t exp_col_bytes=(p_h/8+((p_h%8)?1:0));//显示一列的字节数
	uint8_t act_col_bytes=(high/8+((high%8)?1:0));//实际显示一列的字节数
	
	for(row=0;row<width;row++)//列++
	{
		for(col=0;col<act_col_bytes;col++)//显示一列
		{   
			temp = p[col+row*exp_col_bytes];
			for(i=0;i<8;i++)
			{
				if(temp&0x80)oled_drawPoint(x,y,1);
				else oled_drawPoint(x,y,0);
				temp<<=1;
				y++;
				if((y-y0)==high)
				{
					y=y0;
					x++;
					break;
				}		
			} 
		}
	}		
}
int rt_hw_oled_init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    rt_hw_spi_device_attach("spi2", "spi20", GPIOB, GPIO_PIN_1);  //将设备0挂载在SPI总线上
    oled_gpio_init();
	
	  oled_res_set(1);
	  rt_thread_delay(RT_TICK_PER_SECOND / 10);
	  oled_res_set(0);
	  rt_thread_delay(RT_TICK_PER_SECOND / 10);
	  oled_res_set(1);	
	
	
		oled_write_byte(0xAE,OLED_CMD); //关闭显示
		oled_write_byte(0xD5,OLED_CMD); //设置时钟分频因子,震荡频率
		oled_write_byte(0x80,OLED_CMD); //[3:0],分频因子;[7:4],震荡频率
		oled_write_byte(0xA8,OLED_CMD); //设置驱动路数
		oled_write_byte(0X3F,OLED_CMD); //默认0X3F(1/64) 
		oled_write_byte(0xD3,OLED_CMD); //设置显示偏移
		oled_write_byte(0X00,OLED_CMD); //默认为0

		oled_write_byte(0x40,OLED_CMD); //设置显示开始行 [5:0],行数.
													    
		oled_write_byte(0x8D,OLED_CMD); //电荷泵设置
		oled_write_byte(0x14,OLED_CMD); //bit2，开启/关闭
		oled_write_byte(0x20,OLED_CMD); //设置内存地址模式
		oled_write_byte(0x02,OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
		oled_write_byte(0xA1,OLED_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
		oled_write_byte(0xC0,OLED_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
		oled_write_byte(0xDA,OLED_CMD); //设置COM硬件引脚配置
		oled_write_byte(0x12,OLED_CMD); //[5:4]配置
		 
		oled_write_byte(0x81,OLED_CMD); //对比度设置
		oled_write_byte(0xEF,OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
		oled_write_byte(0xD9,OLED_CMD); //设置预充电周期
		oled_write_byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
		oled_write_byte(0xDB,OLED_CMD); //设置VCOMH 电压倍率
		oled_write_byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

		oled_write_byte(0xA4,OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
		oled_write_byte(0xA6,OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示	    						   
		oled_write_byte(0xAF,OLED_CMD); //开启显示
	
		oled_clear();


  return RT_EOK;
}
//INIT_DEVICE_EXPORT(rt_hw_oled_init);

