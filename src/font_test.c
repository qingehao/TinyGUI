#include "tg_font.h"
//06*12==��*�� ASCII�ַ������� (����)
uint8_t fonttest_0612[95][12]={
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x00,0x00,0x3F,0x40,0x00,0x00,0x00,0x00,0x00,0x00},/*"!",1*/
{0x00,0x00,0x30,0x00,0x40,0x00,0x30,0x00,0x40,0x00,0x00,0x00},/*""",2*/
{0x09,0x00,0x0B,0xC0,0x3D,0x00,0x0B,0xC0,0x3D,0x00,0x09,0x00},/*"#",3*/
{0x18,0xC0,0x24,0x40,0x7F,0xE0,0x22,0x40,0x31,0x80,0x00,0x00},/*"$",4*/
{0x18,0x00,0x24,0xC0,0x1B,0x00,0x0D,0x80,0x32,0x40,0x01,0x80},/*"%",5*/
{0x03,0x80,0x1C,0x40,0x27,0x40,0x1C,0x80,0x07,0x40,0x00,0x40},/*"&",6*/
{0x10,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x20,0x40,0x40,0x20},/*"(",8*/
{0x00,0x00,0x40,0x20,0x20,0x40,0x1F,0x80,0x00,0x00,0x00,0x00},/*")",9*/
{0x09,0x00,0x06,0x00,0x1F,0x80,0x06,0x00,0x09,0x00,0x00,0x00},/*"*",10*/
{0x04,0x00,0x04,0x00,0x3F,0x80,0x04,0x00,0x04,0x00,0x00,0x00},/*"+",11*/
{0x00,0x10,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*",",12*/
{0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x00,0x00},/*"-",13*/
{0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*".",14*/
{0x00,0x20,0x01,0xC0,0x06,0x00,0x38,0x00,0x40,0x00,0x00,0x00},/*"/",15*/
{0x1F,0x80,0x20,0x40,0x20,0x40,0x20,0x40,0x1F,0x80,0x00,0x00},/*"0",16*/
{0x00,0x00,0x10,0x40,0x3F,0xC0,0x00,0x40,0x00,0x00,0x00,0x00},/*"1",17*/
{0x18,0xC0,0x21,0x40,0x22,0x40,0x24,0x40,0x18,0x40,0x00,0x00},/*"2",18*/
{0x10,0x80,0x20,0x40,0x24,0x40,0x24,0x40,0x1B,0x80,0x00,0x00},/*"3",19*/
{0x02,0x00,0x0D,0x00,0x11,0x00,0x3F,0xC0,0x01,0x40,0x00,0x00},/*"4",20*/
{0x3C,0x80,0x24,0x40,0x24,0x40,0x24,0x40,0x23,0x80,0x00,0x00},/*"5",21*/
{0x1F,0x80,0x24,0x40,0x24,0x40,0x34,0x40,0x03,0x80,0x00,0x00},/*"6",22*/
{0x30,0x00,0x20,0x00,0x27,0xC0,0x38,0x00,0x20,0x00,0x00,0x00},/*"7",23*/
{0x1B,0x80,0x24,0x40,0x24,0x40,0x24,0x40,0x1B,0x80,0x00,0x00},/*"8",24*/
{0x1C,0x00,0x22,0xC0,0x22,0x40,0x22,0x40,0x1F,0x80,0x00,0x00},/*"9",25*/
{0x00,0x00,0x00,0x00,0x08,0x40,0x00,0x00,0x00,0x00,0x00,0x00},/*":",26*/
{0x00,0x00,0x00,0x00,0x04,0x60,0x00,0x00,0x00,0x00,0x00,0x00},/*";",27*/
{0x00,0x00,0x04,0x00,0x0A,0x00,0x11,0x00,0x20,0x80,0x40,0x40},/*"<",28*/
{0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x00,0x00},/*"=",29*/
{0x00,0x00,0x40,0x40,0x20,0x80,0x11,0x00,0x0A,0x00,0x04,0x00},/*">",30*/
{0x18,0x00,0x20,0x00,0x23,0x40,0x24,0x00,0x18,0x00,0x00,0x00},/*"?",31*/
{0x1F,0x80,0x20,0x40,0x27,0x40,0x29,0x40,0x1F,0x40,0x00,0x00},/*"@",32*/
{0x00,0x40,0x07,0xC0,0x39,0x00,0x0F,0x00,0x01,0xC0,0x00,0x40},/*"A",33*/
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x24,0x40,0x1B,0x80,0x00,0x00},/*"B",34*/
{0x1F,0x80,0x20,0x40,0x20,0x40,0x20,0x40,0x30,0x80,0x00,0x00},/*"C",35*/
{0x20,0x40,0x3F,0xC0,0x20,0x40,0x20,0x40,0x1F,0x80,0x00,0x00},/*"D",36*/
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x2E,0x40,0x30,0xC0,0x00,0x00},/*"E",37*/
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x2E,0x00,0x30,0x00,0x00,0x00},/*"F",38*/
{0x0F,0x00,0x10,0x80,0x20,0x40,0x22,0x40,0x33,0x80,0x02,0x00},/*"G",39*/
{0x20,0x40,0x3F,0xC0,0x04,0x00,0x04,0x00,0x3F,0xC0,0x20,0x40},/*"H",40*/
{0x20,0x40,0x20,0x40,0x3F,0xC0,0x20,0x40,0x20,0x40,0x00,0x00},/*"I",41*/
{0x00,0x60,0x20,0x20,0x20,0x20,0x3F,0xC0,0x20,0x00,0x20,0x00},/*"J",42*/
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x0B,0x00,0x30,0xC0,0x20,0x40},/*"K",43*/
{0x20,0x40,0x3F,0xC0,0x20,0x40,0x00,0x40,0x00,0x40,0x00,0xC0},/*"L",44*/
{0x3F,0xC0,0x3C,0x00,0x03,0xC0,0x3C,0x00,0x3F,0xC0,0x00,0x00},/*"M",45*/
{0x20,0x40,0x3F,0xC0,0x0C,0x40,0x23,0x00,0x3F,0xC0,0x20,0x00},/*"N",46*/
{0x1F,0x80,0x20,0x40,0x20,0x40,0x20,0x40,0x1F,0x80,0x00,0x00},/*"O",47*/
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x24,0x00,0x18,0x00,0x00,0x00},/*"P",48*/
{0x1F,0x80,0x21,0x40,0x21,0x40,0x20,0xE0,0x1F,0xA0,0x00,0x00},/*"Q",49*/
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x26,0x00,0x19,0xC0,0x00,0x40},/*"R",50*/
{0x18,0xC0,0x24,0x40,0x24,0x40,0x22,0x40,0x31,0x80,0x00,0x00},/*"S",51*/
{0x30,0x00,0x20,0x40,0x3F,0xC0,0x20,0x40,0x30,0x00,0x00,0x00},/*"T",52*/
{0x20,0x00,0x3F,0x80,0x00,0x40,0x00,0x40,0x3F,0x80,0x20,0x00},/*"U",53*/
{0x20,0x00,0x3E,0x00,0x01,0xC0,0x07,0x00,0x38,0x00,0x20,0x00},/*"V",54*/
{0x38,0x00,0x07,0xC0,0x3C,0x00,0x07,0xC0,0x38,0x00,0x00,0x00},/*"W",55*/
{0x20,0x40,0x39,0xC0,0x06,0x00,0x39,0xC0,0x20,0x40,0x00,0x00},/*"X",56*/
{0x20,0x00,0x38,0x40,0x07,0xC0,0x38,0x40,0x20,0x00,0x00,0x00},/*"Y",57*/
{0x30,0x40,0x21,0xC0,0x26,0x40,0x38,0x40,0x20,0xC0,0x00,0x00},/*"Z",58*/
{0x00,0x00,0x00,0x00,0x7F,0xE0,0x40,0x20,0x40,0x20,0x00,0x00},/*"[",59*/
{0x00,0x00,0x70,0x00,0x0C,0x00,0x03,0x80,0x00,0x40,0x00,0x00},/*"\",60*/
{0x00,0x00,0x40,0x20,0x40,0x20,0x7F,0xE0,0x00,0x00,0x00,0x00},/*"]",61*/
{0x00,0x00,0x20,0x00,0x40,0x00,0x20,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
{0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10},/*"_",63*/
{0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x02,0x80,0x05,0x40,0x05,0x40,0x03,0xC0,0x00,0x40},/*"a",65*/
{0x20,0x00,0x3F,0xC0,0x04,0x40,0x04,0x40,0x03,0x80,0x00,0x00},/*"b",66*/
{0x00,0x00,0x03,0x80,0x04,0x40,0x04,0x40,0x06,0x40,0x00,0x00},/*"c",67*/
{0x00,0x00,0x03,0x80,0x04,0x40,0x24,0x40,0x3F,0xC0,0x00,0x40},/*"d",68*/
{0x00,0x00,0x03,0x80,0x05,0x40,0x05,0x40,0x03,0x40,0x00,0x00},/*"e",69*/
{0x00,0x00,0x04,0x40,0x1F,0xC0,0x24,0x40,0x24,0x40,0x20,0x00},/*"f",70*/
{0x00,0x00,0x02,0xE0,0x05,0x50,0x05,0x50,0x06,0x50,0x04,0x20},/*"g",71*/
{0x20,0x40,0x3F,0xC0,0x04,0x40,0x04,0x00,0x03,0xC0,0x00,0x40},/*"h",72*/
{0x00,0x00,0x04,0x40,0x27,0xC0,0x00,0x40,0x00,0x00,0x00,0x00},/*"i",73*/
{0x00,0x10,0x00,0x10,0x04,0x10,0x27,0xE0,0x00,0x00,0x00,0x00},/*"j",74*/
{0x20,0x40,0x3F,0xC0,0x01,0x40,0x07,0x00,0x04,0xC0,0x04,0x40},/*"k",75*/
{0x20,0x40,0x20,0x40,0x3F,0xC0,0x00,0x40,0x00,0x40,0x00,0x00},/*"l",76*/
{0x07,0xC0,0x04,0x00,0x07,0xC0,0x04,0x00,0x03,0xC0,0x00,0x00},/*"m",77*/
{0x04,0x40,0x07,0xC0,0x04,0x40,0x04,0x00,0x03,0xC0,0x00,0x40},/*"n",78*/
{0x00,0x00,0x03,0x80,0x04,0x40,0x04,0x40,0x03,0x80,0x00,0x00},/*"o",79*/
{0x04,0x10,0x07,0xF0,0x04,0x50,0x04,0x40,0x03,0x80,0x00,0x00},/*"p",80*/
{0x00,0x00,0x03,0x80,0x04,0x40,0x04,0x50,0x07,0xF0,0x00,0x10},/*"q",81*/
{0x04,0x40,0x07,0xC0,0x02,0x40,0x04,0x00,0x04,0x00,0x00,0x00},/*"r",82*/
{0x00,0x00,0x06,0x40,0x05,0x40,0x05,0x40,0x04,0xC0,0x00,0x00},/*"s",83*/
{0x00,0x00,0x04,0x00,0x1F,0x80,0x04,0x40,0x00,0x40,0x00,0x00},/*"t",84*/
{0x04,0x00,0x07,0x80,0x00,0x40,0x04,0x40,0x07,0xC0,0x00,0x40},/*"u",85*/
{0x04,0x00,0x07,0x00,0x04,0xC0,0x01,0x80,0x06,0x00,0x04,0x00},/*"v",86*/
{0x06,0x00,0x01,0xC0,0x07,0x00,0x01,0xC0,0x06,0x00,0x00,0x00},/*"w",87*/
{0x04,0x40,0x06,0xC0,0x01,0x00,0x06,0xC0,0x04,0x40,0x00,0x00},/*"x",88*/
{0x04,0x10,0x07,0x10,0x04,0xE0,0x01,0x80,0x06,0x00,0x04,0x00},/*"y",89*/
{0x00,0x00,0x04,0x40,0x05,0xC0,0x06,0x40,0x04,0x40,0x00,0x00},/*"z",90*/
{0x00,0x00,0x00,0x00,0x04,0x00,0x7B,0xE0,0x40,0x20,0x00,0x00},/*"{",91*/
{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00},/*"|",92*/
{0x00,0x00,0x40,0x20,0x7B,0xE0,0x04,0x00,0x00,0x00,0x00,0x00},/*"}",93*/
{0x40,0x00,0x80,0x00,0x40,0x00,0x20,0x00,0x20,0x00,0x40,0x00},/*"~",94*/
};
//���ֵ��� 12*12(����)
uint8_t font_1212[35][24]={
{0x70,0x20,0x10,0x40,0x11,0x90,0x1E,0x10,0xF3,0x20,0x12,0xA0,0x12,0x40,0x92,0xA0,0x53,0x20,0x10,0x10,0x10,0x10,0x00,0x00},/*"��",0*/
{0x01,0x20,0x7F,0x40,0xD5,0x80,0x55,0x10,0x7F,0xF0,0x00,0x00,0x12,0x00,0x11,0x90,0x10,0x10,0xFF,0xF0,0x10,0x00,0x00,0x00},/*"��",1*/
{0x11,0x00,0x11,0x10,0xFF,0xF0,0x12,0x00,0x25,0x10,0x35,0x50,0xAD,0xD0,0x67,0x20,0x2D,0x20,0x35,0xD0,0x25,0x10,0x00,0x00},/*"��",2*/
{0x7F,0xC0,0x00,0x80,0x01,0x00,0xFF,0xF0,0x04,0x10,0x08,0x20,0xF7,0x40,0x10,0x80,0x11,0x40,0x1E,0x20,0x10,0x10,0x00,0x00},/*"��",3*/
{0x08,0x90,0x7B,0x10,0x08,0x20,0xFF,0x40,0x48,0x80,0x49,0x00,0x9F,0x90,0xB0,0x20,0xD7,0xC0,0x90,0x20,0x9F,0x90,0x00,0x00},/*"Ƶ",4*/
{0x40,0x40,0x51,0x40,0x4A,0x40,0x59,0x40,0x6B,0x40,0xCD,0xF0,0x4B,0x40,0x51,0x40,0x4A,0x40,0x51,0x40,0x40,0x40,0x00,0x00},/*"��",5*/
{0x08,0x00,0x3F,0xF0,0xC0,0x00,0x20,0x00,0x2A,0xF0,0x2A,0xA0,0xAA,0xA0,0x6A,0xA0,0x2A,0xA0,0x2A,0xF0,0x20,0x00,0x00,0x00},/*"��",6*/
{0x08,0x10,0x88,0x20,0x4F,0xC0,0x00,0x20,0x5F,0xD0,0xD5,0x50,0x75,0x50,0x55,0x50,0x55,0x50,0xD5,0x50,0x5F,0xD0,0x00,0x00},/*"��",7*/
{0x4C,0x00,0x49,0xE0,0xE9,0x00,0x49,0x00,0x49,0x00,0xEB,0xF0,0x49,0x00,0x49,0x00,0xE9,0x20,0x49,0xE0,0x4C,0x00,0x00,0x00},/*"��",8*/
{0x60,0x10,0x57,0x90,0x54,0x20,0x7C,0x20,0x54,0x40,0xD5,0x80,0x54,0x60,0x7C,0x10,0x54,0x10,0x57,0x90,0x60,0x30,0x00,0x00},/*"��",9*/
{0x11,0x00,0x16,0x00,0xFF,0xF0,0x12,0x00,0x40,0x50,0x5F,0x50,0xF5,0x60,0x55,0xC0,0xF5,0x60,0x5F,0x50,0x40,0x50,0x00,0x00},/*"ģ",10*/
{0x11,0x10,0xFF,0xF0,0x12,0x00,0x00,0x00,0x7F,0xC0,0x00,0x90,0x41,0x20,0x30,0xC0,0x07,0x00,0xF8,0xC0,0x00,0x30,0x00,0x00},/*"��",11*/
{0x12,0x90,0x54,0xD0,0x19,0xA0,0xFE,0xA0,0x14,0xD0,0x52,0x00,0x08,0x10,0xF7,0xA0,0x10,0x40,0x1F,0xA0,0x10,0x10,0x00,0x00},/*"��",12*/
{0x30,0x80,0x20,0x80,0x24,0x80,0x24,0x90,0xA4,0x90,0x64,0xF0,0x25,0x80,0x26,0x80,0x24,0x80,0x20,0x80,0x30,0x80,0x00,0x00},/*"��",13*/
{0x3F,0xC0,0x20,0x80,0x3F,0xC0,0x44,0x10,0x42,0x10,0x7F,0xF0,0x40,0x10,0x40,0x10,0x7F,0xF0,0x42,0x10,0x44,0x10,0x00,0x00},/*"��",14*/
{0x08,0x00,0x4B,0xF0,0x6A,0xA0,0x5A,0xA0,0x4A,0xA0,0xCA,0xA0,0x4A,0xA0,0x5A,0xA0,0x6A,0xA0,0x4B,0xF0,0x08,0x00,0x00,0x00},/*"��",15*/
{0x44,0x00,0x57,0xF0,0xFD,0x40,0x57,0xF0,0x54,0x00,0x2A,0x80,0xCA,0x90,0x5F,0xF0,0x6A,0x80,0x0F,0xC0,0x02,0x00,0x00,0x00},/*"��",16*/
{0x7F,0xC0,0x40,0x80,0x7F,0xC0,0x00,0x00,0x0E,0x90,0xEA,0xA0,0xAE,0xC0,0xA1,0xF0,0xAE,0xC0,0xEA,0xA0,0x0E,0x90,0x00,0x00},/*"��",17*/
{0x10,0x10,0xFF,0x50,0x95,0x50,0x95,0x50,0x95,0x50,0xDF,0xF0,0xB5,0x50,0x95,0x50,0x95,0x50,0xFF,0x50,0x10,0x10,0x00,0x00},/*"��",18*/
{0x10,0x10,0x5F,0x50,0x55,0x50,0x55,0x50,0x55,0x50,0x7F,0xF0,0x95,0x50,0x95,0x50,0x95,0x50,0x9F,0x50,0x10,0x10,0x00,0x00},/*"��",19*/
{0x08,0x10,0xE8,0x10,0xAB,0xF0,0xAA,0x10,0xEA,0x10,0xBE,0x70,0xEA,0x10,0xAA,0x10,0xAB,0xF0,0xE8,0x10,0x08,0x10,0x00,0x00},/*"��",20*/
{0x08,0x10,0x88,0x20,0x4F,0xC0,0x00,0x20,0xFF,0xD0,0xA8,0x90,0xAD,0x10,0xAA,0x10,0xA9,0x10,0xFA,0xD0,0x04,0x10,0x00,0x00},/*"��",21*/
{0x01,0xE0,0x78,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0xFF,0xE0,0x08,0x20,0x08,0x20,0x08,0x20,0x78,0x20,0x01,0xF0,0x00,0x00},/*"��",22*/
{0x19,0x20,0x2B,0x20,0xCD,0x40,0x11,0x50,0x40,0x60,0x7F,0x80,0x41,0x10,0x40,0xA0,0x4C,0x40,0x74,0xA0,0x07,0x10,0x00,0x00},/*"��",23*/
{0x08,0x00,0x88,0x00,0x4F,0xE0,0x00,0x40,0x0A,0x10,0xF3,0x10,0x82,0xA0,0x82,0x40,0xF2,0xA0,0x0B,0x10,0x08,0x10,0x00,0x00},/*"��",24*/
{0x42,0x00,0x4F,0xE0,0x74,0x40,0x47,0xE0,0x00,0x10,0x2F,0xE0,0xCA,0x80,0x4F,0xE0,0x5A,0x80,0x6A,0x90,0x0F,0xF0,0x00,0x00},/*"ȷ",0*/
{0x34,0x10,0x24,0x20,0x25,0xC0,0x24,0x20,0xA4,0x10,0x67,0xF0,0x24,0x90,0x24,0x90,0x24,0x90,0x24,0x90,0x34,0x10,0x00,0x00},/*"��",1*/
{0x1E,0x00,0x00,0x00,0xFF,0xF0,0x10,0x20,0x23,0xC0,0xFC,0x10,0x23,0x20,0x20,0x40,0x2F,0x80,0x22,0x60,0x24,0x10,0x00,0x00},/*"��",2*/
{0x20,0x00,0x40,0x50,0xBE,0x90,0xAB,0xD0,0xAA,0xA0,0xAA,0xA0,0xAA,0xA0,0xAA,0xA0,0xAA,0xD0,0xBE,0x90,0x80,0x10,0x00,0x00},/*"��",3*/
{0x00,0x10,0x10,0x20,0x50,0x40,0x30,0x80,0x13,0x00,0x1C,0x00,0xF2,0x00,0x11,0x90,0x10,0x10,0x10,0x10,0x1F,0xE0,0x00,0x00},/*"Ϊ",4*/
{0xFA,0x50,0xAA,0x60,0x8A,0x50,0xFF,0xA0,0xAA,0x90,0xFA,0xA0,0x00,0x10,0x08,0xE0,0xFF,0x00,0x48,0xE0,0x28,0x10,0x00,0x00},/*"Ĭ",5*/
{0x08,0x00,0x88,0x00,0x4F,0xE0,0x00,0x40,0x00,0x90,0x00,0x60,0x03,0x80,0xFC,0x00,0x03,0x80,0x00,0x60,0x00,0x10,0x00,0x00},/*"��",6*/
{0x40,0x40,0x7F,0xC0,0x4A,0x40,0x4A,0x40,0x7F,0xF0,0x40,0x80,0x20,0x10,0x3F,0x20,0x20,0xC0,0x3F,0x20,0x00,0x10,0x00,0x00},/*"ȡ",7*/
{0x08,0x20,0x44,0x40,0x20,0x80,0x00,0x00,0x4F,0xF0,0x2A,0x80,0x0A,0x80,0xFA,0x80,0x0A,0x80,0x2A,0x90,0x4F,0xF0,0x00,0x00},/*"��",8*/
{0x00,0x00,0x30,0x00,0x70,0x00,0x87,0x60,0x8F,0x60,0x78,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"��",9*/
};
char fonttest_table[] = {
"�������Ƶ���ŵ�����ģ���������������������˳�����ȷ���ָ�ΪĬ��ȡ����"
};
struct tg_font font_test={
	.height=12,
	.width=12,
	.hz_bitmap=&font_1212[0][0],
	.asc_bitmap=&fonttest_0612[0][0],
	.index=fonttest_table,
};