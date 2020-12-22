#ifndef __TGUI_H__
#define __TGUI_H__
#include "tg_lcmdrv.h"
#include "tg_button.h"
#include "tg_basic.h"
#include "tg_text.h"
#include "tg_font.h"
#include "rtthread.h"
#include "tg_scrollbar.h"
#include "tg_menu.h"
#include "tg_msgBox.h"
#include "tg_windows.h"
#include "stdbool.h"

#define SCR_WIDTH 128
#define SCR_HIGH 64



#define TG_SCROLL_BTN_WIDTH  10  //按钮的宽度
#define TG_SCROLL_BTN_HEIGHT 10	//按钮的高度
#define BUTTON_RADIUS  4

/* 有宽度的直线函数 */
#define   TG_DRAW_LINE_With_EN		0
/* 画圆函数 */
#define   TG_DRAW_CIRCLEX_EN		1
/* 椭圆函数 */
#define   TG_DRAW_EllipseX_EN		0
/* 填充函数 */
#define   TG_DRAW_FLOOD_FILL_EN		1
/* 圆弧函数 */
#define   TG_DRAW_ARCX_EN		1
/* 扇形函数 */
#define   TG_DRAW_Pieslice_EN		0
/* 向上及向下节点个数(填充函数) */
#define   DOWNP_N				20
#define   UPP_N					20
#define   TG_WINDOW_EN			1

#endif
