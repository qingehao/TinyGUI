#ifndef  __TG_SCROLLBAR_H
#define  __TG_SCROLLBAR_H

#include "stdint.h"
//����һ������������
struct tg_scrollbar
{
 uint32_t x;             
 uint32_t y;
 uint32_t width;
 uint32_t height;

 uint32_t totalitems;  	  	//����Ŀ��
 uint32_t itemsperpage;		//ÿҳ��ʾ����Ŀ��
 uint32_t topitem;			//��˵���Ŀ
 uint32_t scbbarlen;		//��������	
	
};
typedef struct tg_scrollbar* tg_scrollbar_t    ;
void test_scrollbar(void);

void tg_scrollbar_delete(tg_scrollbar_t scbx);
void tg_scrollbar_setPos(tg_scrollbar_t scbx);
void tg_scrollbar_draw(tg_scrollbar_t scbx);



#endif




