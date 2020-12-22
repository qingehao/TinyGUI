#ifndef  __TG_SCROLLBAR_H
#define  __TG_SCROLLBAR_H

#include "stdint.h"
//定义一个滚动条类型
struct tg_scrollbar
{
 uint32_t x;             
 uint32_t y;
 uint32_t width;
 uint32_t height;

 uint32_t totalitems;  	  	//总条目数
 uint32_t itemsperpage;		//每页显示的条目数
 uint32_t topitem;			//最顶端的条目
 uint32_t scbbarlen;		//滚条长度	
	
};
typedef struct tg_scrollbar* tg_scrollbar_t    ;
void test_scrollbar(void);

void tg_scrollbar_delete(tg_scrollbar_t scbx);
void tg_scrollbar_setPos(tg_scrollbar_t scbx);
void tg_scrollbar_draw(tg_scrollbar_t scbx);



#endif




