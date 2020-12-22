#ifndef __TG_MSGBOX_H
#define __TG_MSGBOX_H

#include "stdint.h"

/* 定义窗口数据结构 */
struct tg_msgBox
{  
	uint32_t  x;		// 窗口位置(左上角的x坐标)
	uint32_t  y;		// 窗口位置(左上角的y坐标)

	uint32_t  with;		// 窗口宽度
	uint32_t  hight;	// 窗口高度

	char   *title;	// 定义标题栏指针 
	char   *msg;		//消息
	char   *ok;		//确定
	char   *cancel;	//取消
} ;

typedef struct tg_msgBox* tg_msgBox_t;
uint8_t GUI_MessageBoxDelete(tg_msgBox_t  msgBox);
uint8_t tg_msgBox_draw(tg_msgBox_t  msgBox);
void tg_msgBox_set_buttonSta(tg_msgBox_t  msgBox, uint8_t status);
uint8_t tg_msgBox_get_result(tg_msgBox_t  msgBox);
void test_MessageBox(void);



#endif



