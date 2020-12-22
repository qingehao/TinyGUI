#ifndef  _TG_MENU_H
#define  _TG_MENU_H
#include <stdbool.h>
#include "stdint.h"
//����ͼ��˵�32X32
struct tg_menu_item
{  	
	int8_t cursorPosition;			//�˵���ʾʱ���λ��
	uint8_t menuItemCount;			//�˵�������Ŀ��
	bool isSelect;					//��ʾ�˵���״̬ �Ƿ�ѡ��
	const uint8_t *icoSelected;		//�˵���Ŀѡ�е�ICO���ݵ�ַ
	const uint8_t *icoUnselected;	//�˵���Ŀûѡ�е�ICO���ݵ�ַ
	char *title;			//�˵���Ŀ����
	void (*Function)(void); 		//�˵���Ӧ�Ķ���
	struct tg_menu_item* parentMenu;	//��һ���˵�
	struct tg_menu_item* childrenMenu;	//��һ���˵�
};
typedef struct tg_menu_item* tg_menu_item_t;

uint8_t  GUI_MenuIcoDraw(tg_menu_item_t  ico);
void GUI_MenuItem_Selected(uint32_t x, uint32_t y, tg_menu_item_t  item, bool isSelect);
uint8_t  tg_menu_item_draw(uint32_t x, uint32_t y, tg_menu_item_t  item);


#endif



