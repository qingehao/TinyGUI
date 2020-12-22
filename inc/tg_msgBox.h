#ifndef __TG_MSGBOX_H
#define __TG_MSGBOX_H

#include "stdint.h"

/* ���崰�����ݽṹ */
struct tg_msgBox
{  
	uint32_t  x;		// ����λ��(���Ͻǵ�x����)
	uint32_t  y;		// ����λ��(���Ͻǵ�y����)

	uint32_t  with;		// ���ڿ��
	uint32_t  hight;	// ���ڸ߶�

	char   *title;	// ���������ָ�� 
	char   *msg;		//��Ϣ
	char   *ok;		//ȷ��
	char   *cancel;	//ȡ��
} ;

typedef struct tg_msgBox* tg_msgBox_t;
uint8_t GUI_MessageBoxDelete(tg_msgBox_t  msgBox);
uint8_t tg_msgBox_draw(tg_msgBox_t  msgBox);
void tg_msgBox_set_buttonSta(tg_msgBox_t  msgBox, uint8_t status);
uint8_t tg_msgBox_get_result(tg_msgBox_t  msgBox);
void test_MessageBox(void);



#endif



