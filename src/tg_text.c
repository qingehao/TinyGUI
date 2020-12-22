#include "tgui.h"
#include "string.h"
static uint8_t letter_space=0;
static uint8_t line_space=0;
//��ʾһ���ַ�
static void show_char(uint8_t x,uint8_t y,tg_font_t font,char *ch,uint8_t mode)
{
		const char* font_table;
		uint16_t fontSeq;
		uint8_t temp,t,t1;
		uint16_t y0= y; 
	  uint8_t bHz=0;
		uint8_t csize=(font->height/8+((font->height%8)?1:0))*font->width;//�õ����ɷֱ��ַ���ռ���ֽ��� 

		if( (uint8_t)*ch>0x80 ) //����
		{
			bHz=1;
			font_table=font->index;
			for(fontSeq=0; fontSeq<strlen(font_table)/2; fontSeq++) //���������±�
			{
				if(font_table[2*fontSeq]==ch[0] && font_table[2*fontSeq+1]==ch[1])
					break;
			}
			if(fontSeq >= strlen(font_table)/2) return;//û�и���ģ
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
  uint8_t  bHz=0;     //�ַ���������  	
  uint8_t last_ch;	
  while(*str!=0)//����δ����
  { 
		rt_kprintf("0X%x,",*str);
    if(!bHz) 
    {
	     if( (uint8_t)*str>0x80 )
			 {
					bHz=1;//����  
			 }
	     else     //�ַ�
	     {      
					if(x>(x0+SCR_WIDTH -font->width/2))//����
					{				   
						y+=font->height+line_space;
						x=x0;	   
					}							    
		      if(y>(y0+SCR_HIGH-font->height))break;//Խ�緵��      
		      if(*str==0X0D || *str==0X0A)//���з���
		      {         
		        y+=font->height+line_space;
						x=x0;
		        str++; 
		      }  
		      else 
					{
						show_char(x,y,font,str,mode);
						str++;
						x+=font->width/2+letter_space; //�ַ�,Ϊȫ�ֵ�һ�� 
						last_ch=1; //��ǰ����ַ�ΪӢ���ַ�
					}
	      }
     }
		 else//���� 
     {     
        bHz=0;//�к��ֿ�    
        if(x>(x0+SCR_WIDTH -font->width))//����
				{	    
					y+=font->height+line_space;//2Ϊ�м��
					x=x0;		  
				}
	      if(y>(y0+SCR_HIGH-font->height))break;//Խ�緵��  
				if(last_ch==1) //��һ��ΪӢ���ַ��Ļ�
				{
					x+=0;
				}
				show_char(x,y,font,str,mode);	
        last_ch=2;				
	      str+=2; 
	      x+=font->width+letter_space;//��һ������ƫ��	    
			}						 
  }
}
void tg_text_set_spacing(uint8_t letter,uint8_t line)
{
	letter_space=letter;
	line_space=line;
}
			 		 
//��ָ����ȵ��м���ʾ�ַ���
//����ַ����ȳ�����len,����Show_Str��ʾ
//len:ָ��Ҫ��ʾ�Ŀ��			  
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
//�õ��ַ���ռ�õ�ˮƽ���ص���
uint8_t tg_text_get_strHPixel(tg_font_t font,char *str)
{
	uint16_t HPixel=0;
	uint16_t i=0;
	uint8_t last_ch=0;
	while(*str!=0)
	{
		if( (uint8_t)*str >0x80 ) //����
		{
			str+=2;
			HPixel+=font->width;
			if(last_ch==1) //�ϸ��ַ���Ӣ��
			{
				HPixel+=(1+letter_space);//�����м���ټ���1
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
			if(last_ch==1) //�ϸ��ַ���Ӣ��
			{
				HPixel+=(letter_space);//�����м���ټ���1
			}
			else if(last_ch==2)//�ϸ��ַ�������
			{
				HPixel+=(letter_space);
			}
			last_ch=1; 
		}
	}
	return HPixel;
}


