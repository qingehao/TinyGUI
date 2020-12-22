#ifndef  _TG_MENU_H
#define  _TG_MENU_H
#include <stdbool.h>
#include "stdint.h"
//定义图标菜单32X32
struct tg_menu_item
{  	
	int8_t cursorPosition;			//菜单显示时光标位置
	uint8_t menuItemCount;			//菜单包含项目数
	bool isSelect;					//显示菜单的状态 是否选中
	const uint8_t *icoSelected;		//菜单项目选中的ICO数据地址
	const uint8_t *icoUnselected;	//菜单项目没选中的ICO数据地址
	char *title;			//菜单项目内容
	void (*Function)(void); 		//菜单对应的动作
	struct tg_menu_item* parentMenu;	//上一级菜单
	struct tg_menu_item* childrenMenu;	//下一级菜单
};
typedef struct tg_menu_item* tg_menu_item_t;

uint8_t  GUI_MenuIcoDraw(tg_menu_item_t  ico);
void GUI_MenuItem_Selected(uint32_t x, uint32_t y, tg_menu_item_t  item, bool isSelect);
uint8_t  tg_menu_item_draw(uint32_t x, uint32_t y, tg_menu_item_t  item);


#endif



