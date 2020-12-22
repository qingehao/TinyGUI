#ifndef  _TG_BUTTON_H
#define  _TG_BUTTON_H
#include <stdint.h>
struct tg_button
{
	uint32_t x;
	uint32_t y;
	uint32_t width;
	uint32_t height;
	char* title;
	uint8_t state;
};
typedef struct tg_button* tg_button_t;

void test_Button(void);
void tg_button_selected(tg_button_t  btn,uint8_t state);
void tg_button_draw(tg_button_t  btn);
void tg_button_delete(tg_button_t  btn);


#endif


