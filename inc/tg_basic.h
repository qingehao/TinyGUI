#ifndef  __TG_BASIC_H_
#define  __TG_BASIC_H_

#include "tg_lcmdrv.h"

typedef  struct
{  
	uint32_t  x;				// x坐标变量
	uint32_t  y;			// y坐标变量
}PointXY;

extern  void  tg_draw_rect(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color);

void  tg_draw_rect_fill(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color);

void  tg_draw_square(uint32_t x0, uint32_t y0, uint32_t  with, TCOLOR  color);

void  tg_draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color);

void  tg_draw_lineWith(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t with, TCOLOR color);
void  tg_draw_lineS(uint32_t const *points, uint8_t no, TCOLOR color);

void  tg_draw_circle(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color);

void  tg_draw_circle_fill(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color);

void  GUI_Ellipse(uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1, TCOLOR color);

void  GUI_EllipseFill(uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1, TCOLOR color);

void  tg_draw_flood_fill(uint32_t x0, uint32_t y0, TCOLOR color);

void  tg_draw_arc4(uint32_t x, uint32_t y, uint32_t r, uint8_t angle, TCOLOR color);

void  tg_draw_arc(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color);


void  GUI_Pieslice(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color);

void tg_draw_picture(uint8_t x,uint8_t y,const uint8_t *p,uint8_t p_w,uint8_t p_h);
#endif
