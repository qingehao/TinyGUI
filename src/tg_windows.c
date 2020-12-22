#include "tgui.h"


#if  TG_WINDOW_EN==1

/****************************************************************************
* 名称：tg_windows_draw()
* 功能：显示窗口。根据提供的窗口参数进行画窗口。
* 入口参数：win		窗口句柄
* 出口参数：返回0表示操作失败，返回1表示操作成功
****************************************************************************/
uint8_t tg_windows_draw(tg_window_t win)
{  
	/* 参数过滤，若窗口起出范围，则返回0 */
	if( ( (win->width)<20 ) || ( (win->height)<20 ) ) return(0);	// 宽度、高度检查，限制最小窗口
	if( (win->x + win->width ) > SCR_WIDTH ) return(0);			// 窗口宽度是否溢出
	if( (win->y + win->height ) > SCR_HIGH ) return(0);			// 窗口高度是否溢出

	/* 开始画窗口 */
	tg_draw_rect_fill(win->x, win->y, win->x + win->width - 1, win->y + win->height - 1, 0);// 这尼玛不是清屏么（黑）
	tg_draw_rect(win->x, win->y, win->x + win->width - 1, win->y + win->height - 1, 1);	// 画窗口边框
	tg_draw_HLine(win->x, win->y + 14, win->x + win->width - 1, disp_color);					// 画标题目栏下边框	 

	//填充标题栏
	tg_draw_rect_fill(win->x, win->y, win->x + win->width - 1, win->y + 14-1, 1);
	if(tg_text_get_strHPixel(default_font,win->title)>(win->width-2))
	{  
		return 0;//显示的标题超过了窗体的宽度
	}	
	tg_text_show_string_mid(win->x, win->y+1, default_font,win->title,0,win->width);//显示标题
	return(1);
}


/****************************************************************************
* 名称：GUI_WindowsHide()
* 功能：消隐窗口。
* 入口参数：win		窗口句柄
* 出口参数：返回0表示操作失败，返回1表示操作成功
****************************************************************************/
uint8_t tg_windows_delete(tg_window_t win)
{  
	/* 参数过滤，若窗口起出范围，则返回0 */
	if( ( (win->width)<20 ) || ( (win->height)<20 ) ) return(0);	// 宽度、高度检查，限制最小窗口
	if( (win->x + win->width ) > SCR_WIDTH ) return(0);			// 窗口宽度是否溢出
	if( (win->y + win->height ) > SCR_HIGH ) return(0);			// 窗口高度是否溢出

	/* 消隐窗口 */
	tg_draw_rect_fill(win->x, win->y, win->x + win->width - 1, win->y + win->height - 1, back_color);
	return(1);
}



/****************************************************************************
* 名称：tg_windows_clr()
* 功能：清屏窗口。
* 入口参数：win		窗口句柄
* 出口参数：无
* 说明：使用此函数前要先使用tg_windows_draw()将窗口画出。
****************************************************************************/
void tg_windows_clr(tg_window_t win)
{ 
	uint8_t  x0, y0;
	uint8_t  x1, y1;

	/* 设置要清屏的区域 */
	x0 = win->x + 1;
	x1 = win->x + win->width - 2;
	y0 = win->y + 14;
	y1 = win->y + win->height - 2;

	/* 使用填充矩形实现清屏 */
	tg_draw_rect_fill(x0, y0, x1, y1, back_color);
}

#endif












