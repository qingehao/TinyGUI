#include "tgui.h"
#include "string.h"
static uint8_t letter_space=0;
static uint8_t line_space=0;
//显示一个字符
static void show_char(uint8_t x,uint8_t y,tg_font_t font,char *ch,uint8_t mode)
{
		const char* font_table;
		uint16_t fontSeq;
		uint8_t temp,t,t1;
		uint16_t y0= y; 
	  uint8_t bHz=0;
		uint8_t csize=(font->height/8+((font->height%8)?1:0))*font->width;//得到自由分辨字符所占的字节数 

		if( (uint8_t)*ch>0x80 ) //汉字
		{
			bHz=1;
			font_table=font->index;
			for(fontSeq=0; fontSeq<strlen(font_table)/2; fontSeq++) //计算数组下标
			{
				if(font_table[2*fontSeq]==ch[0] && font_table[2*fontSeq+1]==ch[1])
					break;
			}
			if(fontSeq >= strlen(font_table)/2) return;//没有该字模
		}
		else
		{
			fontSeq=*ch-' ';
			csize=csize/2;
		}
		for(t=0;t<csize;t++)
		{   		
			if(bHz)
			{
				temp=font->hz_bitmap[fontSeq*csize+t];
			}
			else
			{
				temp=font->asc_bitmap[fontSeq*csize+t];
			}
			for(t1=0;t1<8;t1++)
			{
				if(temp&0x80) tg_draw_point(x,y,mode);
				else tg_draw_point(x,y,!mode);
				temp<<=1;
				y++;
				if((y-y0)==font->height)
				{
					y=y0;
					x++;
					break;
				}
			}  	 
		} 
}
void tg_text_show_string(uint8_t x,uint8_t y,tg_font_t font,char *str,uint8_t mode)
{
	uint16_t x0=x;
	uint16_t y0=y;							  	  
  uint8_t  bHz=0;     //字符或者中文  	
  uint8_t last_ch;	
  while(*str!=0)//数据未结束
  { 
		rt_kprintf("0X%x,",*str);
    if(!bHz) 
    {
	     if( (uint8_t)*str>0x80 )
			 {
					bHz=1;//中文  
			 }
	     else     //字符
	     {      
					if(x>(x0+SCR_WIDTH -font->width/2))//换行
					{				   
						y+=font->height+line_space;
						x=x0;	   
					}							    
		      if(y>(y0+SCR_HIGH-font->height))break;//越界返回      
		      if(*str==0X0D || *str==0X0A)//换行符号
		      {         
		        y+=font->height+line_space;
						x=x0;
		        str++; 
		      }  
		      else 
					{
						show_char(x,y,font,str,mode);
						str++;
						x+=font->width/2+letter_space; //字符,为全字的一半 
						last_ch=1; //当前输出字符为英文字符
					}
	      }
     }
		 else//中文 
     {     
        bHz=0;//有汉字库    
        if(x>(x0+SCR_WIDTH -font->width))//换行
				{	    
					y+=font->height+line_space;//2为行间距
					x=x0;		  
				}
	      if(y>(y0+SCR_HIGH-font->height))break;//越界返回  
				if(last_ch==1) //上一个为英文字符的话
				{
					x+=0;
				}
				show_char(x,y,font,str,mode);	
        last_ch=2;				
	      str+=2; 
	      x+=font->width+letter_space;//下一个汉字偏移	    
			}						 
  }
}
void tg_text_set_spacing(uint8_t letter,uint8_t line)
{
	letter_space=letter;
	line_space=line;
}
			 		 
//在指定宽度的中间显示字符串
//如果字符长度超过了len,则用Show_Str显示
//len:指定要显示的宽度			  
void tg_text_show_string_mid(uint16_t x,uint16_t y,tg_font_t font,char*str,uint8_t mode,uint16_t len)
{
	uint16_t str_len=0;
	str_len=tg_text_get_strHPixel(font,str);
	if(str_len>len)
	{
		tg_text_show_string(x,y,font,str,mode);
	}
	else
	{
		str_len=(len-str_len)/2;
	  tg_text_show_string(str_len+x,y,font,str,mode);
	}
}   
//得到字符串占用的水平像素点数
uint8_t tg_text_get_strHPixel(tg_font_t font,char *str)
{
	uint16_t HPixel=0;
	uint16_t i=0;
	uint8_t last_ch=0;
	while(*str!=0)
	{
		if( (uint8_t)*str >0x80 ) //中文
		{
			str+=2;
			HPixel+=font->width;
			if(last_ch==1) //上个字符是英文
			{
				HPixel+=(1+letter_space);//加上行间距再加上1
			}
			else if(last_ch==2)
			{
				HPixel+=(letter_space);
			}
			last_ch=2;
		}
		else
		{
			str+=1;
			HPixel+=(font->width/2);
			if(last_ch==1) //上个字符是英文
			{
				HPixel+=(letter_space);//加上行间距再加上1
			}
			else if(last_ch==2)//上个字符是中文
			{
				HPixel+=(letter_space);
			}
			last_ch=1; 
		}
	}
	return HPixel;
}


