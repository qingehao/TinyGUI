#ifndef  __TG_LCMDRV_H
#define  __TG_LCMDRV_H  
#include "stdint.h"

#define  TCOLOR	  uint8_t 

extern TCOLOR	disp_color;
extern TCOLOR	back_color;

void tg_init(void);
void tg_fill_scr(TCOLOR dat);
void tg_clear_scr(void);
void tg_draw_point(uint16_t x, uint8_t y, TCOLOR color);
uint8_t tg_read_point(uint16_t x, uint8_t y, TCOLOR *ret);
void tg_draw_HLine(uint16_t x0, uint8_t y0, uint16_t x1, TCOLOR color);
void tg_draw_VLine(uint16_t x0, uint8_t y0, uint8_t y1, TCOLOR color);
void tg_refresh(void);


#define  GUI_CmpColor(color1, color2)	( (color1&0x01) == (color2&0x01) )

#define  GUI_CopyColor(color1, color2) 	*color1 = color2


#endif
