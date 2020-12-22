#ifndef __TG_FONT_H
#define __TG_FONT_H  
#include "stdint.h"

struct tg_font
{
  uint8_t height;
	uint8_t width;
	uint8_t *asc_bitmap; //字符字库
	uint8_t *hz_bitmap; //汉字字库
	char *index; //计算数组下标所用的数组
};

typedef struct tg_font *tg_font_t;

extern  tg_font_t default_font;
void tg_font_set_default(tg_font_t font);
extern const unsigned char asc2_0608[95][6];
extern const unsigned char asc2_0612[95][12];
extern const unsigned char asc2_0816[95][16];
extern const unsigned char asc2_1224[95][36];
//extern const unsigned char font_1212[159][24];
extern const unsigned char font_2424[6][72];
extern const unsigned char bmp_logo[240];
extern const unsigned char bmp_rssi[6][72];
extern const unsigned char bmp_battery[13][20];
extern const unsigned char bmp_lock[2][120];
extern const unsigned char bmp_flightMode[2][120];
extern const unsigned char bmp_remoter2fly[96];


#endif
