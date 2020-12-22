#include "tgui.h"


#if  TG_WINDOW_EN==1

/****************************************************************************
* ���ƣ�tg_windows_draw()
* ���ܣ���ʾ���ڡ������ṩ�Ĵ��ڲ������л����ڡ�
* ��ڲ�����win		���ھ��
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
uint8_t tg_windows_draw(tg_window_t win)
{  
	/* �������ˣ������������Χ���򷵻�0 */
	if( ( (win->width)<20 ) || ( (win->height)<20 ) ) return(0);	// ��ȡ��߶ȼ�飬������С����
	if( (win->x + win->width ) > SCR_WIDTH ) return(0);			// ���ڿ���Ƿ����
	if( (win->y + win->height ) > SCR_HIGH ) return(0);			// ���ڸ߶��Ƿ����

	/* ��ʼ������ */
	tg_draw_rect_fill(win->x, win->y, win->x + win->width - 1, win->y + win->height - 1, 0);// �����겻������ô���ڣ�
	tg_draw_rect(win->x, win->y, win->x + win->width - 1, win->y + win->height - 1, 1);	// �����ڱ߿�
	tg_draw_HLine(win->x, win->y + 14, win->x + win->width - 1, disp_color);					// ������Ŀ���±߿�	 

	//��������
	tg_draw_rect_fill(win->x, win->y, win->x + win->width - 1, win->y + 14-1, 1);
	if(tg_text_get_strHPixel(default_font,win->title)>(win->width-2))
	{  
		return 0;//��ʾ�ı��ⳬ���˴���Ŀ��
	}	
	tg_text_show_string_mid(win->x, win->y+1, default_font,win->title,0,win->width);//��ʾ����
	return(1);
}


/****************************************************************************
* ���ƣ�GUI_WindowsHide()
* ���ܣ��������ڡ�
* ��ڲ�����win		���ھ��
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
uint8_t tg_windows_delete(tg_window_t win)
{  
	/* �������ˣ������������Χ���򷵻�0 */
	if( ( (win->width)<20 ) || ( (win->height)<20 ) ) return(0);	// ��ȡ��߶ȼ�飬������С����
	if( (win->x + win->width ) > SCR_WIDTH ) return(0);			// ���ڿ���Ƿ����
	if( (win->y + win->height ) > SCR_HIGH ) return(0);			// ���ڸ߶��Ƿ����

	/* �������� */
	tg_draw_rect_fill(win->x, win->y, win->x + win->width - 1, win->y + win->height - 1, back_color);
	return(1);
}



/****************************************************************************
* ���ƣ�tg_windows_clr()
* ���ܣ��������ڡ�
* ��ڲ�����win		���ھ��
* ���ڲ�������
* ˵����ʹ�ô˺���ǰҪ��ʹ��tg_windows_draw()�����ڻ�����
****************************************************************************/
void tg_windows_clr(tg_window_t win)
{ 
	uint8_t  x0, y0;
	uint8_t  x1, y1;

	/* ����Ҫ���������� */
	x0 = win->x + 1;
	x1 = win->x + win->width - 2;
	y0 = win->y + 14;
	y1 = win->y + win->height - 2;

	/* ʹ��������ʵ������ */
	tg_draw_rect_fill(x0, y0, x1, y1, back_color);
}

#endif












