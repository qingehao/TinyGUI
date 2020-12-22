#include "tgui.h"
/****************************************************************************
* 名称：tg_menu_item_draw()
* 功能：显示条目菜单
* 入口参数：ico		图标菜单句柄
* 出口参数：返回0表示操作失败，返回1表示操作成功
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


