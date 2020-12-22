#include "tgui.h"

//设置按钮的状态
void tg_button_selected(tg_button_t  btn,uint8_t state)
{
	uint8_t str_HPixel=0;
	str_HPixel=tg_text_get_strHPixel(default_font,(char *)btn->title);
	if(btn->height<14) return;
	if(btn->width<30)  return;
	if( str_HPixel > btn->width ) return;

	btn->state = state;
	if(btn->state)
	{
		tg_draw_flood_fill(btn->x + BUTTON_RADIUS,btn->y + BUTTON_RADIUS, 1);
		tg_text_show_string(btn->x+(btn->width-str_HPixel)/2,btn->y+(btn->height-default_font->height)/2,default_font,(char *)btn->title,0);
	}
	else
	{
		tg_draw_flood_fill(btn->x + BUTTON_RADIUS,btn->y + BUTTON_RADIUS, 0);

		tg_draw_arc4(btn->x+BUTTON_RADIUS, btn->y+BUTTON_RADIUS, BUTTON_RADIUS,3, 1);
		tg_draw_line(btn->x+BUTTON_RADIUS, btn->y, btn->x+BUTTON_RADIUS+btn->width-1-2*BUTTON_RADIUS, btn->y,1);

		tg_draw_arc4(btn->x+btn->width-1-BUTTON_RADIUS, btn->y+BUTTON_RADIUS, BUTTON_RADIUS,4, 1);	
		tg_draw_line(btn->x+BUTTON_RADIUS, btn->y+btn->height-1, btn->x+BUTTON_RADIUS+btn->width-1-2*BUTTON_RADIUS, btn->y+btn->height-1,1);	

		tg_draw_arc4(btn->x+btn->width-1-BUTTON_RADIUS, btn->y+ btn->height-1-BUTTON_RADIUS, BUTTON_RADIUS,1, 1);	
		tg_draw_line(btn->x, btn->y+BUTTON_RADIUS, btn->x, btn->y+btn->height-1-BUTTON_RADIUS,1);	

		tg_draw_arc4(btn->x+BUTTON_RADIUS, btn->y+ btn->height-1-BUTTON_RADIUS, BUTTON_RADIUS,2, 1);	
		tg_draw_line(btn->x+btn->width-1, btn->y+BUTTON_RADIUS, btn->x+btn->width-1,  btn->y+btn->height-1-BUTTON_RADIUS,1);			 
    tg_text_show_string(btn->x+(btn->width-str_HPixel)/2,btn->y+(btn->height-default_font->height)/2,default_font,(char *)btn->title,1);
	}
}




//画一个按钮
void tg_button_draw(tg_button_t  btn)
{
	uint8_t str_HPixel=0;
	str_HPixel=tg_text_get_strHPixel(default_font,(char *)btn->title);
	if(btn->height<14) return;
	if(btn->width<30)  return;
	if(str_HPixel>btn->width) return;

	tg_draw_arc4(btn->x+BUTTON_RADIUS, btn->y+BUTTON_RADIUS, BUTTON_RADIUS,3, 1);
	tg_draw_line(btn->x+BUTTON_RADIUS, btn->y, btn->x+BUTTON_RADIUS+btn->width-1-2*BUTTON_RADIUS, btn->y,1);

	tg_draw_arc4(btn->x+btn->width-1-BUTTON_RADIUS, btn->y+BUTTON_RADIUS, BUTTON_RADIUS,4, 1);	
	tg_draw_line(btn->x+BUTTON_RADIUS, btn->y+btn->height-1, btn->x+BUTTON_RADIUS+btn->width-1-2*BUTTON_RADIUS, btn->y+btn->height-1,1);	

	tg_draw_arc4(btn->x+btn->width-1-BUTTON_RADIUS, btn->y+ btn->height-1-BUTTON_RADIUS, BUTTON_RADIUS,1, 1);	
	tg_draw_line(btn->x, btn->y+BUTTON_RADIUS, btn->x, btn->y+btn->height-1-BUTTON_RADIUS,1);	

	tg_draw_arc4(btn->x+BUTTON_RADIUS, btn->y+ btn->height-1-BUTTON_RADIUS, BUTTON_RADIUS,2, 1);	
	tg_draw_line(btn->x+btn->width-1, btn->y+BUTTON_RADIUS, btn->x+btn->width-1,  btn->y+btn->height-1-BUTTON_RADIUS,1);	


	if(btn->state)
	{
		//填充按钮
		tg_draw_flood_fill(btn->x + BUTTON_RADIUS,btn->y + BUTTON_RADIUS, 1);
		tg_text_show_string(btn->x+(btn->width-str_HPixel)/2,btn->y+(btn->height-default_font->height)/2,default_font,(char *)btn->title,0);
	}
	else
	{
		tg_text_show_string(btn->x+(btn->width-str_HPixel)/2,btn->y+(btn->height-default_font->height)/2,default_font,(char *)btn->title,1);
	}
};

//删除按钮
void tg_button_delete(tg_button_t  btn)
{
	tg_draw_rect_fill(btn->x, btn->y, btn->x+btn->width-1,  btn->y +btn->height-1, 0);
}

struct tg_button button={
10,
10,
40,
14,
"OK",
1
};
//测试按钮
void test_Button(void)
{
	tg_button_draw(&button);
	button.title = "set";
	button.x = 60;
	tg_button_draw(&button);
	tg_refresh();								//刷新屏幕
	rt_thread_mdelay(2000);

	tg_button_selected(&button,0);
	tg_refresh();								//刷新屏幕
	rt_thread_mdelay(2000);	
	tg_button_delete(&button);
}






