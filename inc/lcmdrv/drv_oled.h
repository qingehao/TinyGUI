#ifndef __DRV_OLED_H__
#define __DRV_OLED_H__
#include <rtthread.h>

//OLED¿ØÖÆÓÃº¯Êý
rt_err_t oled_write_byte(uint8_t dat,uint8_t cmd);  
void oled_displayON(void);
void oled_displayOFF(void);
void oled_refreshGram(void);  		    
int rt_hw_oled_init(void);
void oled_clear(void)  ;
void oled_drawPoint(uint8_t x,uint8_t y,uint8_t t);
uint8_t oled_readPoint(uint8_t x,uint8_t y);
void oled_fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void oled_showChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t f_w,uint8_t f_h,uint8_t mode);
void oled_showNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t f_w,uint8_t f_h);
void oled_showString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t f_w,uint8_t f_h);	
void oled_showPicture(uint8_t x,uint8_t y,const uint8_t *p,uint8_t p_w,uint8_t p_h);
#endif
