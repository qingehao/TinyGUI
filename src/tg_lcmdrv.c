#include "tg_lcmdrv.h"
#include "drv_oled.h"
/* 定义前景色及背景色变量，用于ASCII码、汉字、窗口、单色位图显示 */
TCOLOR  disp_color = 1;
TCOLOR	back_color = 0;
/**
* @brief 初始化GUI 
* @param 无
*/
void tg_init(void)
{
	rt_hw_oled_init();//显示屏初始化函数
	oled_clear();//清屏
}
/**
* @brief 全屏填充。直接使用数据填充显示缓冲区。 
* @param dat     填充的数据
*/
void tg_fill_scr(TCOLOR dat)
{
	oled_fill(0,0,127,63,dat);
}
/**
* @brief 清屏。
* @param dat     填充的数据
*/
void tg_clear_scr()
{
	oled_clear();
}
/**
* @brief 在指定位置上画点。
* @param 
*/
void tg_draw_point(uint16_t x, uint8_t y, TCOLOR color)
{
	oled_drawPoint(x,y,color);
}
/**
* @brief 读取指定点的颜色。
* @param 
*/
uint8_t tg_read_point(uint16_t x, uint8_t y, TCOLOR *ret)
{
	*ret = oled_readPoint(x,y);
	return 0;
}
/**
* @brief 画水平线。
* @param 
*/
void tg_draw_HLine(uint16_t x0, uint8_t y0, uint16_t x1, TCOLOR color)
{
	uint8_t  temp;
	if(x0>x1)               // 对x0、x1大小进行排列，以便画图
	{
		temp = x1;
		x1 = x0;
		x0 = temp;
	}
	do
	{
		tg_draw_point(x0, y0, color);   // 逐点显示，描出垂直线
		x0++;
	}
	while(x1>=x0);
}
/**
* @brief 画垂直线。
* @param 
*/
void tg_draw_VLine(uint16_t x0, uint8_t y0, uint8_t y1, TCOLOR color)
{
    uint8_t  temp;
    if(y0>y1)       // 对y0、y1大小进行排列，以便画图
    {
        temp = y1;
        y1 = y0;
        y0 = temp;
    }
    do
    {
        tg_draw_point(x0, y0, color);   // 逐点显示，描出垂直线
        y0++;
    }
    while(y1>=y0);
}
/**
* @brief 刷新屏幕  
* @param 
*/
void tg_refresh(void)
{
	oled_refreshGram();
}


