#include "tgui.h"
#include "rtthread.h"
//声明字体
extern tg_font_t font_test;

void tgui_text_example()
{
	//设置字体间距为1 行间距为2
	tg_text_set_spacing(1,2);
	
	tg_text_show_string(0,1,font_test,"hello TinyGUI",0); //从(0,1)正常显示
	tg_text_show_string(0,1,font_test,"hello TinyGUI",1); //从(0,1)反白显示
	
	tg_text_show_string_mid(0,1,font_test,"hello TinyGUI",1,127)	; //在(0,1) 到 (127,1) 区域居中显示 

}
void tgui_scrollbar_example()
{
	struct tg_scrollbar  Scrollbar=
	{
		118,
		14,
		10,
		50,
		9,
		3,
		9,
		0
	};
	tg_scrollbar_draw(&Scrollbar);
	tg_refresh();								//刷新屏幕
	rt_thread_mdelay(2000);
	Scrollbar.topitem = 1;
	tg_scrollbar_setPos(&Scrollbar);
	tg_refresh();								//刷新屏幕
	rt_thread_mdelay(2000);
	Scrollbar.topitem = 2;
	tg_scrollbar_setPos(&Scrollbar);
	tg_refresh();
}
void tgui_msgBox_example()
{
	struct tg_msgBox  msgBox={
		0,
		0,	
		128,
		64,
		"reset",	
		"system will be resetni hao a1234?",
		"OK",
		"Cancel"
	};
	tg_msgBox_draw(&msgBox);
	tg_refresh();
	rt_thread_mdelay(2000);
	tg_msgBox_set_buttonSta(&msgBox, 1);	
	tg_refresh();
	rt_thread_mdelay(2000);
	tg_msgBox_set_buttonSta(&msgBox, 0);		
	tg_refresh();
	rt_thread_mdelay(2000);	
	tg_msgBox_delete(&msgBox);	
}
