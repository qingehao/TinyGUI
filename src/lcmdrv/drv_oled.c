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
* @brief �л����ݻ�������ģʽ
* @param state:0:����,1:����
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
* @brief ��λ
* @param mode:0:Ƭѡ,1:δѡ
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
    //���ô���ģʽ
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
		oled_write_byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
		oled_write_byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
		oled_write_byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<128;n++)
			oled_write_byte(oledGram[n][i],OLED_DATA); 
	}   
}
void oled_displayON(void)
{
	oled_write_byte(0X8D,OLED_CMD);  //SET DCDC����
	oled_write_byte(0X14,OLED_CMD);  //DCDC ON
	oled_write_byte(0XAF,OLED_CMD);  //DISPLAY ON
}   
void oled_displayOFF(void)
{
	oled_write_byte(0X8D,OLED_CMD);  //SET DCDC����
	oled_write_byte(0X10,OLED_CMD);  //DCDC OFF
	oled_write_byte(0XAE,OLED_CMD);  //DISPLAY OFF
}	
 
void oled_clear(void)  
{  
	uint8_t i,n;  
	for(i=0;i<8;i++)
		for(n=0;n<128;n++)
			oledGram[n][i]=0X00;  
	oled_refreshGram();//������ʾ
}
/**
* @brief ����
* @param 
*/		   
void oled_drawPoint(uint8_t x,uint8_t y,uint8_t t)
{
	uint8_t pos,bx,temp=0;
	if(x>127||y>63)return;//������Χ��.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)oledGram[x][pos]|=temp;
	else oledGram[x][pos]&=~temp;	    
}
/**
* @brief ����
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
* @brief ���
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
	uint8_t csize=(f_h/8+((f_h%8)?1:0))*f_w;//�õ����ɷֱ��ַ���ռ���ֽ���
	chr=chr-' ';//�õ�ƫ�ƺ��ֵ		 
	for(t=0;t<csize;t++)
	{   
		if(f_w==6&&f_h==8)temp=asc2_0608[chr][t];		//����0608ascii����
		else if(f_w==6&&f_h==12)temp=asc2_0612[chr][t];	//����0612ascii����
		else if(f_w==8&&f_h==16)temp=asc2_0816[chr][t];	//����0612ascii����
		else if(f_w==12&&f_h==24)temp=asc2_1224[chr][t];//����1224ascii����
		else return;	//û�е��ֿ�
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
//m^n����
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}
//��ʾ2������
//x,y :�������	 
//len :���ֵ�λ��
//f_w:�ֿ�
//f_h:�ָ�
//mode:ģʽ	0,���ģʽ;1,����ģʽ
//num:��ֵ(0~4294967295);	 		  
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
//��ʾ�ַ���
//x,y:�������  
//f_w:�ֿ�
//f_h:�ָ�
//*p:�ַ�����ʼ��ַ 
void oled_showString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t f_w,uint8_t f_h)
{	
    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
    {       
        if(x>(128-(f_w))){x=0;y+=f_h;}
        if(y>(64-f_h)){y=x=0;oled_clear();}
        oled_showChar(x,y,*p,f_w,f_h,1);	 
        x+=f_w;
        p++;
    }
}
//��ʾͼƬ
//x,y:�������  
//p_w:ͼƬ����λ���أ�
//p_h:ͼƬ�ߣ���λ���أ�
//*p:ͼƬ��ʼ��ַ 
void oled_showPicture(uint8_t x,uint8_t y,const uint8_t *p,uint8_t p_w,uint8_t p_h)
{	
	uint8_t temp,i,col,row;
	uint8_t y0=y;
	uint8_t width=p_w;
	if(x+p_w>128)width=128-p_w;//ʵ����ʾ���
	uint8_t high=p_h;
	if(y+p_h>64)high=64-p_h;//ʵ����ʾ�߶�
	uint8_t exp_col_bytes=(p_h/8+((p_h%8)?1:0));//��ʾһ�е��ֽ���
	uint8_t act_col_bytes=(high/8+((high%8)?1:0));//ʵ����ʾһ�е��ֽ���
	
	for(row=0;row<width;row++)//��++
	{
		for(col=0;col<act_col_bytes;col++)//��ʾһ��
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
    rt_hw_spi_device_attach("spi2", "spi20", GPIOB, GPIO_PIN_1);  //���豸0������SPI������
    oled_gpio_init();
	
	  oled_res_set(1);
	  rt_thread_delay(RT_TICK_PER_SECOND / 10);
	  oled_res_set(0);
	  rt_thread_delay(RT_TICK_PER_SECOND / 10);
	  oled_res_set(1);	
	
	
		oled_write_byte(0xAE,OLED_CMD); //�ر���ʾ
		oled_write_byte(0xD5,OLED_CMD); //����ʱ�ӷ�Ƶ����,��Ƶ��
		oled_write_byte(0x80,OLED_CMD); //[3:0],��Ƶ����;[7:4],��Ƶ��
		oled_write_byte(0xA8,OLED_CMD); //��������·��
		oled_write_byte(0X3F,OLED_CMD); //Ĭ��0X3F(1/64) 
		oled_write_byte(0xD3,OLED_CMD); //������ʾƫ��
		oled_write_byte(0X00,OLED_CMD); //Ĭ��Ϊ0

		oled_write_byte(0x40,OLED_CMD); //������ʾ��ʼ�� [5:0],����.
													    
		oled_write_byte(0x8D,OLED_CMD); //��ɱ�����
		oled_write_byte(0x14,OLED_CMD); //bit2������/�ر�
		oled_write_byte(0x20,OLED_CMD); //�����ڴ��ַģʽ
		oled_write_byte(0x02,OLED_CMD); //[1:0],00���е�ַģʽ;01���е�ַģʽ;10,ҳ��ַģʽ;Ĭ��10;
		oled_write_byte(0xA1,OLED_CMD); //���ض�������,bit0:0,0->0;1,0->127;
		oled_write_byte(0xC0,OLED_CMD); //����COMɨ�跽��;bit3:0,��ͨģʽ;1,�ض���ģʽ COM[N-1]->COM0;N:����·��
		oled_write_byte(0xDA,OLED_CMD); //����COMӲ����������
		oled_write_byte(0x12,OLED_CMD); //[5:4]����
		 
		oled_write_byte(0x81,OLED_CMD); //�Աȶ�����
		oled_write_byte(0xEF,OLED_CMD); //1~255;Ĭ��0X7F (��������,Խ��Խ��)
		oled_write_byte(0xD9,OLED_CMD); //����Ԥ�������
		oled_write_byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
		oled_write_byte(0xDB,OLED_CMD); //����VCOMH ��ѹ����
		oled_write_byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

		oled_write_byte(0xA4,OLED_CMD); //ȫ����ʾ����;bit0:1,����;0,�ر�;(����/����)
		oled_write_byte(0xA6,OLED_CMD); //������ʾ��ʽ;bit0:1,������ʾ;0,������ʾ	    						   
		oled_write_byte(0xAF,OLED_CMD); //������ʾ
	
		oled_clear();


  return RT_EOK;
}
//INIT_DEVICE_EXPORT(rt_hw_oled_init);

