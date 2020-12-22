#include "tgui.h"
/****************************************************************************
* ���ƣ�tg_menu_item_draw()
* ���ܣ���ʾ��Ŀ�˵�
* ��ڲ�����ico		ͼ��˵����
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
uint8_t tg_menu_item_draw(uint32_t x, uint32_t y, tg_menu_item_t  item)
//uint8_t  tg_menu_item_draw(uint32_t x, uint32_t y, tg_menu_item_t  item)
{  
	if( x>SCR_WIDTH || y>SCR_HIGH) return(0);
	if(y<2) return(0);
	if(x<18) return(0);
	if( (item->title)==NULL )  return(0);

	if(item->isSelect == false)
	{  
		if(item->icoUnselected != NULL)
			tg_draw_picture(x-18, y-2, item->icoUnselected ,16, 16);
		tg_text_show_string(x,y,default_font,item->title,1);
	}
	else
	{  
		if(item->icoSelected != NULL)
			tg_draw_picture(x-18, y-2, item->icoSelected ,16, 16);
	  tg_text_show_string(x,y,default_font,item->title,0);
	}
	return(1);
}


