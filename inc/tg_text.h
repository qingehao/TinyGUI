#ifndef __TG_TEXT_H
#define __TG_TEXT_H 
#include <stdint.h>
#include "tg_font.h"
void tg_text_show_string_mid(uint16_t x,uint16_t y,tg_font_t font,char*str,uint8_t mode,uint16_t len);
void tg_text_show_string(uint8_t x,uint8_t y,tg_font_t font,char *str,uint8_t mode);
void tg_text_set_spacing(uint8_t letter,uint8_t line);
uint8_t tg_text_get_strHPixel(tg_font_t font,char *str);
#endif
