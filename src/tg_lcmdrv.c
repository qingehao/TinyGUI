#include "tg_lcmdrv.h"
#include "drv_oled.h"
/* ����ǰ��ɫ������ɫ����������ASCII�롢���֡����ڡ���ɫλͼ��ʾ */
TCOLOR  disp_color = 1;
TCOLOR	back_color = 0;
/**
* @brief ��ʼ��GUI 
* @param ��
*/
void tg_init(void)
{
	rt_hw_oled_init();//��ʾ����ʼ������
	oled_clear();//����
}
/**
* @brief ȫ����䡣ֱ��ʹ�����������ʾ�������� 
* @param dat     ��������
*/
void tg_fill_scr(TCOLOR dat)
{
	oled_fill(0,0,127,63,dat);
}
/**
* @brief ������
* @param dat     ��������
*/
void tg_clear_scr()
{
	oled_clear();
}
/**
* @brief ��ָ��λ���ϻ��㡣
* @param 
*/
void tg_draw_point(uint16_t x, uint8_t y, TCOLOR color)
{
	oled_drawPoint(x,y,color);
}
/**
* @brief ��ȡָ�������ɫ��
* @param 
*/
uint8_t tg_read_point(uint16_t x, uint8_t y, TCOLOR *ret)
{
	*ret = oled_readPoint(x,y);
	return 0;
}
/**
* @brief ��ˮƽ�ߡ�
* @param 
*/
void tg_draw_HLine(uint16_t x0, uint8_t y0, uint16_t x1, TCOLOR color)
{
	uint8_t  temp;
	if(x0>x1)               // ��x0��x1��С�������У��Ա㻭ͼ
	{
		temp = x1;
		x1 = x0;
		x0 = temp;
	}
	do
	{
		tg_draw_point(x0, y0, color);   // �����ʾ�������ֱ��
		x0++;
	}
	while(x1>=x0);
}
/**
* @brief ����ֱ�ߡ�
* @param 
*/
void tg_draw_VLine(uint16_t x0, uint8_t y0, uint8_t y1, TCOLOR color)
{
    uint8_t  temp;
    if(y0>y1)       // ��y0��y1��С�������У��Ա㻭ͼ
    {
        temp = y1;
        y1 = y0;
        y0 = temp;
    }
    do
    {
        tg_draw_point(x0, y0, color);   // �����ʾ�������ֱ��
        y0++;
    }
    while(y1>=y0);
}
/**
* @brief ˢ����Ļ  
* @param 
*/
void tg_refresh(void)
{
	oled_refreshGram();
}


