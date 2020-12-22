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



#define TG_SCROLL_BTN_WIDTH  10  //��ť�Ŀ��
#define TG_SCROLL_BTN_HEIGHT 10	//��ť�ĸ߶�
#define BUTTON_RADIUS  4

/* �п�ȵ�ֱ�ߺ��� */
#define   TG_DRAW_LINE_With_EN		0
/* ��Բ���� */
#define   TG_DRAW_CIRCLEX_EN		1
/* ��Բ���� */
#define   TG_DRAW_EllipseX_EN		0
/* ��亯�� */
#define   TG_DRAW_FLOOD_FILL_EN		1
/* Բ������ */
#define   TG_DRAW_ARCX_EN		1
/* ���κ��� */
#define   TG_DRAW_Pieslice_EN		0
/* ���ϼ����½ڵ����(��亯��) */
#define   DOWNP_N				20
#define   UPP_N					20
#define   TG_WINDOW_EN			1

#endif
