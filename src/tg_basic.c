#include "tgui.h"
#include <math.h>
/****************************************************************************
* ���ƣ�tg_draw_rect()
* ���ܣ������Ρ�
* ��ڲ����� x0		�������Ͻǵ�x����ֵ
*           y0		�������Ͻǵ�y����ֵ
*           x1      �������½ǵ�x����ֵ
*           y1      �������½ǵ�y����ֵ
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_rect(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color)
{  
	tg_draw_HLine(x0, y0, x1, color);
	tg_draw_HLine(x0, y1, x1, color);
	tg_draw_VLine(x0, y0, y1, color);
	tg_draw_VLine(x1, y0, y1, color);
}
/****************************************************************************
* ���ƣ�tg_draw_rect_fill()
* ���ܣ������Ρ���һ�����ľ��Σ����ɫ��߿�ɫһ����
* ��ڲ����� x0		�������Ͻǵ�x����ֵ
*           y0		�������Ͻǵ�y����ֵ
*           x1      �������½ǵ�x����ֵ
*           y1      �������½ǵ�y����ֵ
*           color	�����ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_rect_fill(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color)
{  
	uint32_t  i;

	/* ���ҳ��������Ͻ������½ǵ������㣬������(x0,y0)��(x1,y1) */
	if(x0>x1) 						// ��x0>x1����x0��x1����
	{  
		i = x0;
		x0 = x1;
		x1 = i;
	}
	if(y0>y1)						// ��y0>y1����y0��y1����
	{  
		i = y0;
		y0 = y1;
		y1 = i;
	}

	/* �ж��Ƿ�ֻ��ֱ�� */
	if(y0==y1) 
	{  
		tg_draw_HLine(x0, y0, x1, color);
		return;
	}
	if(x0==x1) 
	{ 
		tg_draw_VLine(x0, y0, y1, color);
		return;
	}

	while(y0<=y1)						
	{  
		tg_draw_HLine(x0, y0, x1, color);	// ��ǰ��ˮƽ��
		y0++;							// ��һ��
	}
}
/****************************************************************************
* ���ƣ�tg_draw_square()
* ���ܣ��������Ρ�
* ��ڲ����� x0		���������Ͻǵ�x����ֵ
*           y0		���������Ͻǵ�y����ֵ
*           with    �����εı߳�
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_square(uint32_t x0, uint32_t y0, uint32_t  with, TCOLOR  color)
{   
	if(with==0) return;
	if( (x0+with) > SCR_WIDTH ) return;
	if( (y0+with) > SCR_HIGH ) return;
	tg_draw_rect(x0, y0, x0+with, y0+with, color);
}
/****************************************************************************
* ���ƣ�tg_draw_line()
* ���ܣ�����������֮���ֱ�ߡ�
* ��ڲ����� x0		ֱ������x����ֵ
*           y0		ֱ������y����ֵ
*           x1      ֱ���յ��x����ֵ
*           y1      ֱ���յ��y����ֵ
*           color	��ʾ��ɫ(���ںڰ�ɫLCM��Ϊ0ʱ��Ϊ1ʱ��ʾ)
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color)
{  
	int32_t   dx;					// ֱ��x���ֵ����
	int32_t   dy;          			// ֱ��y���ֵ����
	int8_t    dx_sym;				// x����������Ϊ-1ʱ��ֵ����Ϊ1ʱ��ֵ����
	int8_t    dy_sym;				// y����������Ϊ-1ʱ��ֵ����Ϊ1ʱ��ֵ����
	int32_t   dx_x2;				// dx*2ֵ���������ڼӿ������ٶ�
	int32_t   dy_x2;				// dy*2ֵ���������ڼӿ������ٶ�
	int32_t   di;					// ���߱���

	dx = x1-x0;						// ��ȡ����֮��Ĳ�ֵ
	dy = y1-y0;
	/* �ж��������򣬻��Ƿ�Ϊˮƽ�ߡ���ֱ�ߡ��� */
	if(dx>0)						// �ж�x�᷽��
	{  
		dx_sym = 1;					// dx>0������dx_sym=1
	}
	else
	{  
		if(dx<0)
			dx_sym = -1;			// dx<0������dx_sym=-1
		else
		{  							// dx==0������ֱ�ߣ���һ��
			tg_draw_VLine(x0, y0, y1, color);
			return;
		}
	}
	if(dy>0)						// �ж�y�᷽��
	{  
		dy_sym = 1;					// dy>0������dy_sym=1
	}
	else
	{  
		if(dy<0)
			dy_sym = -1;			// dy<0������dy_sym=-1
		else
		{ 							// dy==0����ˮƽ�ߣ���һ��
			tg_draw_HLine(x0, y0, x1, color);
			return;
		}
	}
	/* ��dx��dyȡ����ֵ */
	dx = dx_sym * dx;
	dy = dy_sym * dy;

	/* ����2����dx��dyֵ */
	dx_x2 = dx*2;
	dy_x2 = dy*2;

	/* ʹ��Bresenham�����л�ֱ�� */
	if(dx>=dy)						// ����dx>=dy����ʹ��x��Ϊ��׼
	{  
		di = dy_x2 - dx;
		while(x0!=x1)
		{  
			tg_draw_point(x0, y0, color);
			x0 += dx_sym;
			if(di<0)
				di += dy_x2;		// �������һ���ľ���ֵ
			else
			{  
				di += dy_x2 - dx_x2;
				y0 += dy_sym;
			}
		}
		tg_draw_point(x0, y0, color);	// ��ʾ���һ��
	}
	else							// ����dx<dy����ʹ��y��Ϊ��׼
	{  
		di = dx_x2 - dy;
		while(y0!=y1)
		{  
			tg_draw_point(x0, y0, color);
			y0 += dy_sym;
			if(di<0)
				di += dx_x2;
			else
			{  
				di += dx_x2 - dy_x2;
				x0 += dx_sym;
			}
		}
		tg_draw_point(x0, y0, color);		// ��ʾ���һ��
	} 
}
void tg_draw_picture(uint8_t x,uint8_t y,const uint8_t *p,uint8_t p_w,uint8_t p_h)
{
	uint8_t temp,i,col,row;
	uint8_t y0=y;
	uint8_t width=p_w;
	if(x+p_w>SCR_WIDTH)width=SCR_WIDTH-p_w;//ʵ����ʾ���
	uint8_t high=p_h;
	if(y+p_h>SCR_HIGH)high=SCR_HIGH-p_h;//ʵ����ʾ�߶�
	uint8_t exp_col_bytes=(p_h/8+((p_h%8)?1:0));//��ʾһ�е��ֽ���
	uint8_t act_col_bytes=(high/8+((high%8)?1:0));//ʵ����ʾһ�е��ֽ���
	
	for(row=0;row<width;row++)//��++
	{
		for(col=0;col<act_col_bytes;col++)//��ʾһ��
		{   
			temp = p[col+row*exp_col_bytes];
			for(i=0;i<8;i++)
			{
				if(temp&0x80)tg_draw_point(x,y,1);
				else tg_draw_point(x,y,0);
				temp<<=1;
				y++;
				if((y-y0)==high)
				{
					y=y0;
					x++;
					break;
				}		
			} 
		}
	}	
}

#if	TG_DRAW_LINE_With_EN==1
/****************************************************************************
* ���ƣ�tg_draw_lineWith()
* ���ܣ�����������֮���ֱ�ߣ����ҿ������ߵĿ�ȡ�
* ��ڲ����� x0		ֱ������x����ֵ
*           y0		ֱ������y����ֵ
*           x1      ֱ���յ��x����ֵ
*           y1      ֱ���յ��y����ֵ
*           with    �߿�(0-50)
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void  tg_draw_lineWith(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t with, TCOLOR color)
{  
	int32_t   dx;						// ֱ��x���ֵ����
	int32_t   dy;          				// ֱ��y���ֵ����
	int8_t    dx_sym;					// x����������Ϊ-1ʱ��ֵ����Ϊ1ʱ��ֵ����
	int8_t    dy_sym;					// y����������Ϊ-1ʱ��ֵ����Ϊ1ʱ��ֵ����
	int32_t   dx_x2;					// dx*2ֵ���������ڼӿ������ٶ�
	int32_t   dy_x2;					// dy*2ֵ���������ڼӿ������ٶ�
	int32_t   di;						// ���߱���
	int32_t   wx, wy;					// �߿����
	int32_t   draw_a, draw_b;

	/* �������� */
	if(with==0) return;
	if(with>50) with = 50;

	dx = x1-x0;							// ��ȡ����֮��Ĳ�ֵ
	dy = y1-y0;
	wx = with/2;
	wy = with-wx-1;

	/* �ж��������򣬻��Ƿ�Ϊˮƽ�ߡ���ֱ�ߡ��� */
	if(dx>0)							// �ж�x�᷽��
	{  
		dx_sym = 1;						// dx>0������dx_sym=1
	}
	else
	{  
		if(dx<0) 
			dx_sym = -1;				// dx<0������dx_sym=-1
		else/* dx==0������ֱ�ߣ���һ�� */
		{  						
			wx = x0-wx;
			if(wx<0) wx = 0;
			wy = x0+wy;
			while(1)
			{  
				x0 = wx;
				tg_draw_VLine(x0, y0, y1, color);
				if(wx>=wy) break;
				wx++;
			}
			return;
		}
	}

	if(dy>0)							// �ж�y�᷽��
		dy_sym = 1;						// dy>0������dy_sym=1
	else
	{  
		if(dy<0)
			dy_sym = -1;				// dy<0������dy_sym=-1	
		else /* dy==0����ˮƽ�ߣ���һ�� */
		{ 
			wx = y0-wx;
			if(wx<0) wx = 0;
			wy = y0+wy;
			while(1)
			{  
				y0 = wx;
				tg_draw_HLine(x0, y0, x1, color);
				if(wx>=wy) break;
				wx++;
			}
			return;
		}
	}

	/* ��dx��dyȡ����ֵ */
	dx = dx_sym * dx;
	dy = dy_sym * dy;

	/* ����2����dx��dyֵ */
	dx_x2 = dx*2;
	dy_x2 = dy*2;

	/* ʹ��Bresenham�����л�ֱ�� */
	if(dx>=dy)						// ����dx>=dy����ʹ��x��Ϊ��׼
	{  
		di = dy_x2 - dx;
		while(x0!=x1)/* x����������������y���򣬼�����ֱ�� */
		{  
			draw_a = y0-wx;
			if(draw_a<0) draw_a = 0;
			draw_b = y0+wy;
			tg_draw_VLine(x0, draw_a, draw_b, color);

			x0 += dx_sym;				
			if(di<0)
				di += dy_x2;			// �������һ���ľ���ֵ
			else
			{  
				di += dy_x2 - dx_x2;
				y0 += dy_sym;
			}
		}
		draw_a = y0-wx;
		if(draw_a<0) draw_a = 0;
		draw_b = y0+wy;
		tg_draw_VLine(x0, draw_a, draw_b, color);
	}
	else								// ����dx<dy����ʹ��y��Ϊ��׼
	{  
		di = dx_x2 - dy;
		while(y0!=y1) /* y����������������x���򣬼���ˮƽ�� */
		{ 
			draw_a = x0-wx;
			if(draw_a<0) draw_a = 0;
			draw_b = x0+wy;
			tg_draw_HLine(draw_a, y0, draw_b, color);
			y0 += dy_sym;
			if(di<0)
				di += dx_x2;
			else
			{  
				di += dx_x2 - dy_x2;
				x0 += dx_sym;
			}
		}
		draw_a = x0-wx;
		if(draw_a<0) draw_a = 0;
		draw_b = x0+wy;
		tg_draw_HLine(draw_a, y0, draw_b, color);
	} 
}
#endif



/****************************************************************************
* ���ƣ�tg_draw_lineS()
* ���ܣ������֮����������ߡ��ӵ�һ�������ڶ��㣬������������...
* ��ڲ����� points  ������������ݵ�ָ�룬��������Ϊ(x0,y0)��(x1,y1)��(x2,y2)...
*           no      ����Ŀ������Ҫ����1
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_lineS(uint32_t const *points, uint8_t no, TCOLOR color)
//void  tg_draw_lineS(uint32_t const *points, uint8_t no, TCOLOR color)
{  
	uint32_t  x0, y0;
	uint32_t  x1, y1;
	uint8_t  i;

	/* ��ڲ������� */
	if(0==no) return;
	if(1==no)						// ����
	{  
		x0 = *points++;
		y0 = *points;
		tg_draw_point(x0, y0, color);
	}
	/* ���������� */
	x0 = *points++;					// ȡ����һ������ֵ����Ϊԭ�������ֵ
	y0 = *points++;
	for(i=1; i<no; i++)
	{  
		x1 = *points++;				// ȡ����һ������ֵ
		y1 = *points++;
		tg_draw_line(x0, y0, x1, y1, color);
		x0 = x1;						// ����ԭ�������
		y0 = y1;
	}
}



#if  TG_DRAW_CIRCLEX_EN==1
/****************************************************************************
* ���ƣ�tg_draw_circle()
* ���ܣ�ָ��Բ��λ�ü��뾶����Բ��
* ��ڲ����� x0		Բ�ĵ�x����ֵ
*           y0		Բ�ĵ�y����ֵ
*           r       Բ�İ뾶
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_circle(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color)
//void  tg_draw_circle(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color)
{  
	int32_t  draw_x0, draw_y0;			// ��ͼ���������
	int32_t  draw_x1, draw_y1;	
	int32_t  draw_x2, draw_y2;	
	int32_t  draw_x3, draw_y3;	
	int32_t  draw_x4, draw_y4;	
	int32_t  draw_x5, draw_y5;	
	int32_t  draw_x6, draw_y6;	
	int32_t  draw_x7, draw_y7;	
	int32_t  xx, yy;					// ��Բ���Ʊ���
	int32_t  di;						// ���߱���

	/* �������� */
	if(0==r) return;

	/* �����8�������(0��45��90��135��180��225��270��)��������ʾ */
	draw_x0 = draw_x1 = x0;
	draw_y0 = draw_y1 = y0 + r;
	if(draw_y0<SCR_HIGH) tg_draw_point(draw_x0, draw_y0, color);	// 90��

	draw_x2 = draw_x3 = x0;
	draw_y2 = draw_y3 = y0 - r;
	if(draw_y2>=0) tg_draw_point(draw_x2, draw_y2, color);			// 270��


	draw_x4 = draw_x6 = x0 + r;
	draw_y4 = draw_y6 = y0;
	if(draw_x4<SCR_WIDTH) tg_draw_point(draw_x4, draw_y4, color);	// 0��

	draw_x5 = draw_x7 = x0 - r;
	draw_y5 = draw_y7 = y0;
	if(draw_x5>=0) tg_draw_point(draw_x5, draw_y5, color);			// 180��   
	if(1==r) return;					// ���뾶Ϊ1������Բ����
   
   
	/* ʹ��Bresenham�����л�Բ */
	di = 3 - 2*r;					// ��ʼ�����߱���

	xx = 0;
	yy = r;	
	while(xx<yy)
	{  
		if(di<0)
			di += 4*xx + 6;	      
		else
		{  
			di += 4*(xx - yy) + 10;
			yy--;	  
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;
			draw_x4--;
			draw_x5++;
			draw_x6--;
			draw_x7++;	 	
		}
		xx++;   
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		draw_y4++;
		draw_y5++;
		draw_y6--;
		draw_y7--;

		/* Ҫ�жϵ�ǰ���Ƿ�����Ч��Χ�� */
		if( (draw_x0<=SCR_WIDTH)&&(draw_y0>=0) )	
			tg_draw_point(draw_x0, draw_y0, color);

		if( (draw_x1>=0)&&(draw_y1>=0) )	
			tg_draw_point(draw_x1, draw_y1, color);

		if( (draw_x2<=SCR_WIDTH)&&(draw_y2<=SCR_HIGH) )	
			tg_draw_point(draw_x2, draw_y2, color);   

		if( (draw_x3>=0)&&(draw_y3<=SCR_HIGH) )	
			tg_draw_point(draw_x3, draw_y3, color);

		if( (draw_x4<=SCR_WIDTH)&&(draw_y4>=0) )	
			tg_draw_point(draw_x4, draw_y4, color);

		if( (draw_x5>=0)&&(draw_y5>=0) )	
			tg_draw_point(draw_x5, draw_y5, color);

		if( (draw_x6<=SCR_WIDTH)&&(draw_y6<=SCR_HIGH) )	
			tg_draw_point(draw_x6, draw_y6, color);

		if( (draw_x7>=0)&&(draw_y7<=SCR_HIGH) )	
			tg_draw_point(draw_x7, draw_y7, color);
	}
}


/****************************************************************************
* ���ƣ�tg_draw_circle_fill()
* ���ܣ�ָ��Բ��λ�ü��뾶����Բ����䣬���ɫ��߿�ɫһ����
* ��ڲ����� x0		Բ�ĵ�x����ֵ
*           y0		Բ�ĵ�y����ֵ
*           r       Բ�İ뾶
*           color	�����ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_circle_fill(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color)
//void  tg_draw_circle_fill(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color)
{  
	int32_t  draw_x0, draw_y0;			// ��ͼ���������
	int32_t  draw_x1, draw_y1;	
	int32_t  draw_x2, draw_y2;	
	int32_t  draw_x3, draw_y3;	
	int32_t  draw_x4, draw_y4;	
	int32_t  draw_x5, draw_y5;	
	int32_t  draw_x6, draw_y6;	
	int32_t  draw_x7, draw_y7;	
	int32_t  fill_x0, fill_y0;			// �������ı�����ʹ�ô�ֱ�����
	int32_t  fill_x1;
	int32_t  xx, yy;					// ��Բ���Ʊ���
	int32_t  di;						// ���߱���

	/* �������� */
	if(0==r) return;

	/* �����4�������(0��90��180��270��)��������ʾ */
	draw_x0 = draw_x1 = x0;
	draw_y0 = draw_y1 = y0 + r;
	if(draw_y0<SCR_HIGH)
		tg_draw_point(draw_x0, draw_y0, color);	// 90��

	draw_x2 = draw_x3 = x0;
	draw_y2 = draw_y3 = y0 - r;
	if(draw_y2>=0)
		tg_draw_point(draw_x2, draw_y2, color);	// 270��

	draw_x4 = draw_x6 = x0 + r;
	draw_y4 = draw_y6 = y0;
	if(draw_x4<SCR_WIDTH) 
	{  
		tg_draw_point(draw_x4, draw_y4, color);	// 0��
		fill_x1 = draw_x4;
	}
	else
		fill_x1 = SCR_WIDTH;
	
	fill_y0 = y0;							// �������������ʼ��fill_x0
	fill_x0 = x0 - r;						// �����������������fill_y1
	if(fill_x0<0) fill_x0 = 0;
	tg_draw_HLine(fill_x0, fill_y0, fill_x1, color);

	draw_x5 = draw_x7 = x0 - r;
	draw_y5 = draw_y7 = y0;
	if(draw_x5>=0) 
		tg_draw_point(draw_x5, draw_y5, color);	// 180��
	if(1==r) return;


	/* ʹ��Bresenham�����л�Բ */
	di = 3 - 2*r;							// ��ʼ�����߱���

	xx = 0;
	yy = r;
	while(xx<yy)
	{  
		if(di<0)
			di += 4*xx + 6;
		else
		{  
			di += 4*(xx - yy) + 10;
			yy--;	  
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;
			draw_x4--;
			draw_x5++;
			draw_x6--;
			draw_x7++;		 
		}
		xx++;   
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;
		draw_y4++;
		draw_y5++;
		draw_y6--;
		draw_y7--;
		
		/* Ҫ�жϵ�ǰ���Ƿ�����Ч��Χ�� */
		if( (draw_x0<=SCR_WIDTH)&&(draw_y0>=0) )	
			tg_draw_point(draw_x0, draw_y0, color);

		if( (draw_x1>=0)&&(draw_y1>=0) )	
			tg_draw_point(draw_x1, draw_y1, color);
	  
		/* �ڶ���ˮֱ�����(�°�Բ�ĵ�) */
		if(draw_x1>=0)
		{  /* �������������ʼ��fill_x0 */
			fill_x0 = draw_x1;
			/* �������������ʼ��fill_y0 */
			fill_y0 = draw_y1;
			if(fill_y0>SCR_HIGH) fill_y0 = SCR_HIGH;
			if(fill_y0<0) fill_y0 = 0; 
			/* �����������������fill_x1 */									
			fill_x1 = x0*2 - draw_x1;				
			if(fill_x1>SCR_WIDTH) fill_x1 = SCR_WIDTH;
			tg_draw_HLine(fill_x0, fill_y0, fill_x1, color);
		}
	  
		if( (draw_x2<=SCR_WIDTH)&&(draw_y2<=SCR_HIGH) )	
			tg_draw_point(draw_x2, draw_y2, color);   
		  
		if( (draw_x3>=0)&&(draw_y3<=SCR_HIGH) )	
			tg_draw_point(draw_x3, draw_y3, color);
	  
		/* ���ĵ㴹ֱ�����(�ϰ�Բ�ĵ�) */
		if(draw_x3>=0)
		{  /* �������������ʼ��fill_x0 */
			fill_x0 = draw_x3;
			/* �������������ʼ��fill_y0 */
			fill_y0 = draw_y3;
			if(fill_y0>SCR_HIGH) fill_y0 = SCR_HIGH;
			if(fill_y0<0) fill_y0 = 0;
			/* �����������������fill_x1 */									
			fill_x1 = x0*2 - draw_x3;				
			if(fill_x1>SCR_WIDTH) fill_x1 = SCR_WIDTH;
			tg_draw_HLine(fill_x0, fill_y0, fill_x1, color);
		}	 
		if( (draw_x4<=SCR_WIDTH)&&(draw_y4>=0) )	
			tg_draw_point(draw_x4, draw_y4, color);

		if( (draw_x5>=0)&&(draw_y5>=0) )	
			tg_draw_point(draw_x5, draw_y5, color);
	  
		/* �����㴹ֱ�����(�ϰ�Բ�ĵ�) */
		if(draw_x5>=0)
		{  /* �������������ʼ��fill_x0 */
			fill_x0 = draw_x5;
			/* �������������ʼ��fill_y0 */
			fill_y0 = draw_y5;
			if(fill_y0>SCR_HIGH) fill_y0 = SCR_HIGH;
			if(fill_y0<0) fill_y0 = 0;
			/* �����������������fill_x1 */									
			fill_x1 = x0*2 - draw_x5;				
			if(fill_x1>SCR_WIDTH) fill_x1 = SCR_WIDTH;
			tg_draw_HLine(fill_x0, fill_y0, fill_x1, color);
		}

		if( (draw_x6<=SCR_WIDTH)&&(draw_y6<=SCR_HIGH) )	
			tg_draw_point(draw_x6, draw_y6, color);
		if( (draw_x7>=0)&&(draw_y7<=SCR_HIGH) )	
			tg_draw_point(draw_x7, draw_y7, color);

		/* �ڰ˵㴹ֱ�����(�ϰ�Բ�ĵ�) */
		if(draw_x7>=0)
		{  /* �������������ʼ��fill_x0 */
			fill_x0 = draw_x7;
			/* �������������ʼ��fill_y0 */
			fill_y0 = draw_y7;
			if(fill_y0>SCR_HIGH) fill_y0 = SCR_HIGH;
			if(fill_y0<0) fill_y0 = 0;
			/* �����������������fill_x1 */									
			fill_x1 = x0*2 - draw_x7;				
			if(fill_x1>SCR_WIDTH) fill_x1 = SCR_WIDTH;
			tg_draw_HLine(fill_x0, fill_y0, fill_x1, color);
		}
	}
}
#endif

#if	 TG_DRAW_EllipseX_EN==1
/****************************************************************************
* ���ƣ�GUI_Ellipse()
* ���ܣ�������Բ��������Բ���ĸ���Ĳ������������ҵ��x������ֵΪx0��x1�����ϡ����µ�
*      ��y������Ϊy0��y1��
* ��ڲ����� x0		������x����ֵ
*           x1		���ҵ��x����ֵ
*           y0		���ϵ��y����ֵ
*           y1      ���µ��y����ֵ
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void  GUI_Ellipse(uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1, TCOLOR color)
{  
	int32_t  draw_x0, draw_y0;			// ��ͼ���������
	int32_t  draw_x1, draw_y1;
	int32_t  draw_x2, draw_y2;
	int32_t  draw_x3, draw_y3;
	int32_t  xx, yy;					// ��ͼ���Ʊ���

	int32_t  center_x, center_y;		// ��Բ���ĵ��������
	int32_t  radius_x, radius_y;		// ��Բ�İ뾶��x��뾶��y��뾶
	int32_t  radius_xx, radius_yy;		// �뾶��ƽ��ֵ
	int32_t  radius_xx2, radius_yy2;	// �뾶��ƽ��ֵ������
	int32_t  di;						// ������߱���
	
	/* �������� */
	if( (x0==x1) || (y0==y1) ) return;

	/* �������Բ���ĵ����� */
	center_x = (x0 + x1) >> 1;			
	center_y = (y0 + y1) >> 1;

	/* �������Բ�İ뾶��x��뾶��y��뾶 */
	if(x0 > x1)
		radius_x = (x0 - x1) >> 1;
	else
		radius_x = (x1 - x0) >> 1;
	if(y0 > y1)
		radius_y = (y0 - y1) >> 1;
	else
		radius_y = (y1 - y0) >> 1;
   
	/* ����뾶ƽ��ֵ */
	radius_xx = radius_x * radius_x;
	radius_yy = radius_y * radius_y;

	/* ����뾶ƽ��ֵ��2ֵ */
	radius_xx2 = radius_xx<<1;
	radius_yy2 = radius_yy<<1;

	/* ��ʼ����ͼ���� */
	xx = 0;
	yy = radius_y;
	di = radius_yy2 + radius_xx - radius_xx2*radius_y ;	// ��ʼ�����߱��� 

	/* �������Բy���ϵ������˵����꣬��Ϊ��ͼ��� */
	draw_x0 = draw_x1 = draw_x2 = draw_x3 = center_x;
	draw_y0 = draw_y1 = center_y + radius_y;
	draw_y2 = draw_y3 = center_y - radius_y;

	tg_draw_point(draw_x0, draw_y0, color);					// ��y���ϵ������˵� 
	tg_draw_point(draw_x2, draw_y2, color);

	while( (radius_yy*xx) < (radius_xx*yy) ) 
	{  	
		if(di<0)
	 		di+= radius_yy2*(2*xx+3);
		else
		{  
			di += radius_yy2*(2*xx+3) + 4*radius_xx - 4*radius_xx*yy;
			yy--;
			draw_y0--;
			draw_y1--;
			draw_y2++;
			draw_y3++;				 
		}
		xx ++;						// x���1
		draw_x0++;
		draw_x1--;
		draw_x2++;
		draw_x3--;

		tg_draw_point(draw_x0, draw_y0, color);
		tg_draw_point(draw_x1, draw_y1, color);
		tg_draw_point(draw_x2, draw_y2, color);
		tg_draw_point(draw_x3, draw_y3, color);
	}
  
	di = radius_xx2*(yy-1)*(yy-1) + radius_yy2*xx*xx + radius_yy + radius_yy2*xx - radius_xx2*radius_yy;
	while(yy>=0) 
	{  
		if(di<0)
		{  
			di+= radius_xx2*3 + 4*radius_yy*xx + 4*radius_yy - 2*radius_xx2*yy;

			xx ++;						// x���1	 		
			draw_x0++;
			draw_x1--;
			draw_x2++;
			draw_x3--;  
		}
		else
			di += radius_xx2*3 - 2*radius_xx2*yy;	 	 		     			 
		yy--;
		draw_y0--;
		draw_y1--;
		draw_y2++;
		draw_y3++;	

		tg_draw_point(draw_x0, draw_y0, color);
		tg_draw_point(draw_x1, draw_y1, color);
		tg_draw_point(draw_x2, draw_y2, color);
		tg_draw_point(draw_x3, draw_y3, color);
	}     
}
/****************************************************************************
* ���ƣ�GUI_EllipseFill()
* ���ܣ�������Բ������䡣������Բ���ĸ���Ĳ������������ҵ��x������ֵΪx0��x1�����ϡ����µ�
*      ��y������Ϊy0��y1��
* ��ڲ����� x0		������x����ֵ
*           x1		���ҵ��x����ֵ
*           y0		���ϵ��y����ֵ
*           y1      ���µ��y����ֵ
*           color	�����ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void  GUI_EllipseFill(uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1, TCOLOR color)
{  int32_t  draw_x0, draw_y0;			// ��ͼ���������
   int32_t  draw_x1, draw_y1;
   int32_t  draw_x2, draw_y2;
   int32_t  draw_x3, draw_y3;
   int32_t  xx, yy;					// ��ͼ���Ʊ���
    
   int32_t  center_x, center_y;		// ��Բ���ĵ��������
   int32_t  radius_x, radius_y;		// ��Բ�İ뾶��x��뾶��y��뾶
   int32_t  radius_xx, radius_yy;		// �뾶��ƽ��ֵ
   int32_t  radius_xx2, radius_yy2;	// �뾶��ƽ��ֵ������
   int32_t  di;						// ������߱���
	
   /* �������� */
   if( (x0==x1) || (y0==y1) ) return;
   
   /* �������Բ���ĵ����� */
   center_x = (x0 + x1) >> 1;			
   center_y = (y0 + y1) >> 1;
   
   /* �������Բ�İ뾶��x��뾶��y��뾶 */
   if(x0 > x1)
   {  radius_x = (x0 - x1) >> 1;
   }
   else
   {  radius_x = (x1 - x0) >> 1;
   }
   if(y0 > y1)
   {  radius_y = (y0 - y1) >> 1;
   }
   else
   {  radius_y = (y1 - y0) >> 1;
   }
		
   /* ����뾶��ƽ��ֵ */
   radius_xx = radius_x * radius_x;
   radius_yy = radius_y * radius_y;
	
   /* ����뾶��4ֵ */
   radius_xx2 = radius_xx<<1;
   radius_yy2 = radius_yy<<1;
   
    /* ��ʼ����ͼ���� */
   xx = 0;
   yy = radius_y;
  
   di = radius_yy2 + radius_xx - radius_xx2*radius_y ;	// ��ʼ�����߱��� 
	
   /* �������Բy���ϵ������˵����꣬��Ϊ��ͼ��� */
   draw_x0 = draw_x1 = draw_x2 = draw_x3 = center_x;
   draw_y0 = draw_y1 = center_y + radius_y;
   draw_y2 = draw_y3 = center_y - radius_y;
  
	 
   tg_draw_point(draw_x0, draw_y0, color);					// ��y���ϵ������˵�
   tg_draw_point(draw_x2, draw_y2, color);
	
   while( (radius_yy*xx) < (radius_xx*yy) ) 
   {  if(di<0)
	  {  di+= radius_yy2*(2*xx+3);
	  }
	  else
	  {  di += radius_yy2*(2*xx+3) + 4*radius_xx - 4*radius_xx*yy;
	 	  
	     yy--;
		 draw_y0--;
		 draw_y1--;
		 draw_y2++;
		 draw_y3++;				 
	  }
	  
	  xx ++;						// x���1
	 		
	  draw_x0++;
	  draw_x1--;
	  draw_x2++;
	  draw_x3--;
		
	  tg_draw_point(draw_x0, draw_y0, color);
	  tg_draw_point(draw_x1, draw_y1, color);
	  tg_draw_point(draw_x2, draw_y2, color);
	  tg_draw_point(draw_x3, draw_y3, color);
	  
	  /* ��y���ѱ仯��������� */
	  if(di>=0)
	  {  tg_draw_HLine(draw_x0, draw_y0, draw_x1, color);
	     tg_draw_HLine(draw_x2, draw_y2, draw_x3, color);
	  }
   }
  
   di = radius_xx2*(yy-1)*(yy-1) + radius_yy2*xx*xx + radius_yy + radius_yy2*xx - radius_xx2*radius_yy;
   while(yy>=0) 
   {  if(di<0)
	  {  di+= radius_xx2*3 + 4*radius_yy*xx + 4*radius_yy - 2*radius_xx2*yy;
	 	  
	     xx ++;						// x���1	 		
	     draw_x0++;
	     draw_x1--;
	     draw_x2++;
	     draw_x3--;  
	  }
	  else
	  {  di += radius_xx2*3 - 2*radius_xx2*yy;	 	 		     			 
	  }
	  
	  yy--;
 	  draw_y0--;
	  draw_y1--;
	  draw_y2++;
	  draw_y3++;	
		
	  tg_draw_point(draw_x0, draw_y0, color);
	  tg_draw_point(draw_x1, draw_y1, color);
	  tg_draw_point(draw_x2, draw_y2, color);
	  tg_draw_point(draw_x3, draw_y3, color);
	  
	  /* y���ѱ仯��������� */
	  tg_draw_HLine(draw_x0, draw_y0, draw_x1, color);
	  tg_draw_HLine(draw_x2, draw_y2, draw_x3, color); 
   }     
}
#endif




#if  TG_DRAW_FLOOD_FILL_EN==1
/****************************************************************************
* ���ƣ�tg_read_leftPoint()
* ���ܣ��ҳ�ָ�����������ķ�color�㡣
* ��ڲ����� x0		ָ�����x����ֵ
*           y0		ָ�����y����ֵ
*           color	ָ����ɫֵ
* ���ڲ��������ظõ��x������ֵ��
* ˵������û���ҳ����򷵻������x����0��
****************************************************************************/
uint32_t tg_read_leftPoint(uint32_t x0, uint32_t y0, TCOLOR color)
//uint32_t  tg_read_leftPoint(uint32_t x0, uint32_t y0, TCOLOR color)
{  uint32_t  i;
   TCOLOR  bakc;
   
   for(i=x0-1; i>0; i--)
   {  tg_read_point(i, y0, &bakc);
      if( GUI_CmpColor(bakc,color)==0 ) return(i+1);	// ���ҵ����򷵻�
   }
   tg_read_point(i, y0, &bakc);
   if( GUI_CmpColor(bakc,color)==0 ) return(1);		// ���ҵ����򷵻�
   
   return(0);
}


/****************************************************************************
* ���ƣ�tg_read_rightPoint()
* ���ܣ��ҳ�ָ�����ұ�����ķ�color�㡣
* ��ڲ����� x0		ָ�����x������ֵ
*           y0		ָ�����y������ֵ
*           color	ָ����ɫֵ
* ���ڲ��������ظõ��x������ֵ��
* ˵������û���ҳ����򷵻����ҵ�x����SCR_WIDTH��
****************************************************************************/
uint32_t tg_read_rightPoint(uint32_t x0, uint32_t y0, TCOLOR color)
//uint32_t  tg_read_rightPoint(uint32_t x0, uint32_t y0, TCOLOR color)
{  uint32_t  i;
   TCOLOR  bakc;
   
   for(i=x0+1; i<SCR_WIDTH; i++)
   {  tg_read_point(i, y0, &bakc);
      if( GUI_CmpColor(bakc,color)==0 ) return(i-1);	// ���ҵ����򷵻�
   }
   return(SCR_WIDTH);
}


/****************************************************************************
* ���ƣ�tg_cmp_pointColor()
* ���ܣ��ж�ָ�����ϵ���ɫ�Ƿ�Ϊĳ����ɫ��
* ��ڲ�����x			ָ�����x������ֵ
*		   y		ָ�����y������ֵ
*          color	��ɫֵ
* ���ڲ���������1��ʾ��ͬ������0��ʾ����ͬ��
* ˵����
****************************************************************************/
int tg_cmp_pointColor(uint32_t x, uint32_t y, TCOLOR color)
//int  tg_cmp_pointColor(uint32_t x, uint32_t y, TCOLOR color)
{  TCOLOR  bakc;
   
   tg_read_point(x, y, &bakc);
   return( GUI_CmpColor(bakc,color) );	
}


/* �����۵���� */
#ifndef  DOWNP_N
#define  DOWNP_N		20
#endif
#ifndef	 UPP_N
#define  UPP_N			20
#endif
/****************************************************************************
* ���ƣ�tg_draw_flood_fill()
* ���ܣ�ͼ����䣬��ָ�����ڵķ��ͼ�ν�����䡣��ָ�������ɫ���������䣬�����Ǹ���ɫ
*      ������Ϊ�߽�(�磬ָ�����ϵ���ɫΪ��ɫ����������ɫ���ؾ�Ϊ�߽�)��
* ��ڲ����� x0		ָ�����x����ֵ
*           y0		ָ�����y����ֵ
*           color	�����ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��ָ���㲻�ڷ��ͼ���ڡ�
****************************************************************************/
void tg_draw_flood_fill(uint32_t x0, uint32_t y0, TCOLOR color)
{  
	 PointXY  down_point[DOWNP_N];	// �����������ת�۵㻺����
   uint8_t    down_no;				// �����۵����
   PointXY  up_point[UPP_N];		// �����������ת�۵㻺����
   uint8_t    up_no;					// �����۵����
   TCOLOR   fcolor;					// �����ϵ���ɫ
   
   uint32_t  xx, yy;					// �����ʱx��y���� (��ǰ����е��е�)
   uint32_t  xx0;						// ��ǰ����е���xֵ����
   uint32_t  xx1;						// ��ǰ����е���yֵ����
   uint32_t  i;
   
   uint32_t  x0_bak, y0_bak;
   uint32_t  x1_bak;
   
   /* �������� */
   if(x0>=SCR_WIDTH) return;
   if(y0>=SCR_HIGH) return;
   
   /* �ж�ָ�����Ƿ�Ϊ�����ɫ��������ֱ�ӷ��� */
   tg_read_point(x0, y0, &fcolor);						// ȡ���������ɫ
   if( GUI_CmpColor(fcolor,color)!=0 ) return;
   
   y0_bak = y0;
   x0_bak = xx0 = tg_read_leftPoint(x0, y0, fcolor);		// �ҳ���ǰy�����ϵ�����ߵĵ�
   x1_bak = xx1 = tg_read_rightPoint(x0, y0, fcolor);		// �ҳ���ǰy�����ϵ����ұߵĵ�
   down_point[0].x = up_point[0].x = (xx1 + xx0)/2;
   down_point[0].y = up_point[0].y = y0;
   down_no = 1;
   up_no = 1;
   					
   /* ��ʼ������� */
FILL_UP:  
   if(0==up_no) goto FILL_DOWN;							// ������ɨ������ɣ����˳�
   xx = up_point[up_no-1].x;							// ����ȡ����һ�۵�
   yy = up_point[up_no-1].y;
   up_no--; 
   xx0 = tg_read_leftPoint(xx, yy, fcolor);
   xx1 = tg_read_rightPoint(xx, yy, fcolor);
   while(1) 
   {  yy += 1;											// ���ĵ�����һ��
       
      if( tg_cmp_pointColor(xx, yy, fcolor)==0 )					
      {  /* �жϴ˵��Ƿ�Ϊ�յ㣬�������˳��˴�ѭ�� */
         for(i=xx0; i<=xx1; i++)     					// ���Ҵ����Ƿ���������
         {  if( tg_cmp_pointColor(i, yy, fcolor)!=0 ) break;
         }
         if(i>xx1) goto FILL_UP; 
         
         /* �ҳ���һ�������ұߵĵ� */
         xx = i;										// ����xx��Ҫ������Ч������
         xx1 = tg_read_rightPoint(xx, yy, fcolor);
      }
      else
      {  /* �ҳ���һ�������ұߵĵ� */
         xx1 = tg_read_rightPoint(xx, yy, fcolor);
      }
      xx0 = tg_read_leftPoint(xx, yy, fcolor);
      
      /* �����۵㡣ʹ��y0��Ϊ�۵������x0��Ϊ��һ�۵���� */
      if(down_no<DOWNP_N)
      {  y0 = xx0;
         x0 = y0-1;
         for(i=y0; i<=xx1; i++)
         {  if( tg_cmp_pointColor(i, yy-1, fcolor)==0 )	// �����۵�
            {  y0 = i;										
            }
            else
            {  if(x0!=y0)								// �ҵ��µ��۵�
               {  x0 = y0;
                  down_point[down_no].x = i;
                  down_point[down_no].y = yy;
                  down_no++;
               }
            }
            if(down_no>=DOWNP_N) break;					// ���������ѱ����������˳�
         } // end  of for(i=y0+1; i<xx1; i++)
      } // end of if(down_no<DOWNP_N)
      
      xx = (xx1 + xx0)/2;								// �������ĵ�
      tg_draw_HLine(xx0, yy, xx1, color);					// ���һ��
      
      /* �����۵㡣ʹ��y0��Ϊ�۵������x0��Ϊ��һ�۵���� */
      if(up_no<UPP_N)
      {  y0 = xx0;
         x0 = y0-1;
         for(i=y0; i<=xx1; i++)
         {  if( tg_cmp_pointColor(i, yy+1, fcolor)==0 )	// �����۵�
            {  y0 = i;										
            }
            else
            {  if(x0!=y0)								// �ҵ��µ��۵�
               {  x0 = y0;
                  up_point[up_no].x = i;
                  up_point[up_no].y = yy;
                  up_no++;
               }
            }
            if(up_no>=UPP_N) break;						// ���������ѱ����������˳�
         }
      } // end of if(up_no<UPP_N)
      
   } // end of while(1) 

   /* ������� */
FILL_DOWN: 
   if(0==down_no) 
   {  if(0==up_no) 
      {  tg_draw_HLine(x0_bak, y0_bak, x1_bak, color);
         return;								// ������ɨ������ɣ���û�з����µ������۵㣬���˳�
      }
      else
      {  goto FILL_UP;
      }
   }
   xx = down_point[down_no-1].x;						// ����ȡ����һ�۵�
   yy = down_point[down_no-1].y;
   down_no--;
   xx0 = tg_read_leftPoint(xx, yy, fcolor);
   xx1 = tg_read_rightPoint(xx, yy, fcolor);
   
   while(1) 
   {  yy -= 1;											// ���ĵ�����һ�� 
      if( tg_cmp_pointColor(xx, yy, fcolor)==0 )					
      {  /* �жϴ˵��Ƿ�Ϊ�յ㣬�������˳��˴�ѭ�� */
         for(i=xx0; i<=xx1; i++)     					// ������һ���Ƿ���������
         {  if( tg_cmp_pointColor(i, yy, fcolor)!=0 ) break;
         }
         if(i>xx1) goto FILL_DOWN; 
         
         /* �ҳ���һ�������ұߵĵ� */
         xx = i;
         xx1 = tg_read_rightPoint(xx, yy, fcolor);
      }
      else
      {  /* �ҳ���һ�������ұߵĵ� */
         xx1 = tg_read_rightPoint(xx, yy, fcolor);
      }
      xx0 = tg_read_leftPoint(xx, yy, fcolor);
            
      /* �����۵㡣ʹ��y0��Ϊ�۵������x0��Ϊ��һ�۵���� */
      if(up_no<UPP_N)
      {  y0 = xx0;
         x0 = y0-1;
         for(i=y0; i<=xx1; i++)
         {  if( tg_cmp_pointColor(i, yy+1, fcolor)==0 )	// �����۵�
            {  y0 = i;										
            }
            else
            {  if(x0!=y0)								// �ҵ��µ��۵�
               {  x0 = y0;
                  up_point[up_no].x = i;
                  up_point[up_no].y = yy;
                  up_no++;
               }
            }
            if(up_no>=UPP_N) break;						// ���������ѱ����������˳�
         }
      }
            
      xx = (xx1 + xx0)/2; 
      tg_draw_HLine(xx0, yy, xx1, color);					// ���һ��
      
      /* �����۵㡣ʹ��y0��Ϊ�۵������x0��Ϊ��һ�۵���� */
      if(down_no<DOWNP_N)
      {  y0 = xx0;
         x0 = y0-1;
         for(i=y0; i<=xx1; i++)
         {  if( tg_cmp_pointColor(i, yy-1, fcolor)==0 )	// �����۵�
            {  y0 = i;										
            }
            else
            {  if(x0!=y0)								// �ҵ��µ��۵�
               {  x0 = y0;
                  down_point[down_no].x = i;
                  down_point[down_no].y = yy;
                  down_no++;
               }
            }
            if(down_no>=DOWNP_N) break;					// ���������ѱ����������˳�
         }
      } // end of if(down_no<DOWNP_N)
      
   } // end of while(1) 
   
//   tg_draw_HLine(x0_bak, y0_bak, x1_bak, color);
	 
}

#endif

#if  TG_DRAW_ARCX_EN==1
/****************************************************************************
* ���ƣ�tg_draw_arc4()
* ���ܣ���������㼰�յ�ֻ��Ϊ0��-90�ȡ�90��-180�ȡ�180��-270�ȡ�270��-0�ȵȡ����ֱ�
*      Ϊ��1-4���޵�90�Ȼ���
* ��ڲ����� x0		Բ�ĵ�x����ֵ
*           y0		Բ�ĵ�y����ֵ
*           r       Բ���İ뾶
*           angle	����������(1-4)
*           color	��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_arc4(uint32_t x, uint32_t y, uint32_t r, uint8_t angle, TCOLOR color)
//void  tg_draw_arc4(uint32_t x, uint32_t y, uint32_t r, uint8_t angle, TCOLOR color)
{  int32_t  draw_x, draw_y;

   int32_t  op_x, op_y;
   int32_t  op_2rr;
   
   if(r==0) return;
   
   op_2rr = 2*r*r;										// ����rƽ������2
   
   switch(angle)
   {  case  1:
            draw_x = x+r;
            draw_y = y;
            
            op_x = r;
            op_y = 0;
 
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_y++;
               draw_y++;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_x--;
                  draw_x--;
               }
               if(op_y>=op_x) break;
            }
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_x--;
               draw_x--;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_y++;
                  draw_y++;
               }
               if(op_x<=0)
               {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                  break;
               }
            }
   
            break;      
   				
      case  2:
            draw_x = x-r;
            draw_y = y;
            
            op_x = r;
            op_y = 0;
 
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_y++;
               draw_y++;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_x--;
                  draw_x++;
               }
               if(op_y>=op_x) break;
            }
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_x--;
               draw_x++;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_y++;
                  draw_y++;
               }
               if(op_x<=0)
               {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                  break;
               }
            }
  
            break;
            
      case  3:
            draw_x = x-r;
            draw_y = y;
            
            op_x = r;
            op_y = 0;
 
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_y++;
               draw_y--;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_x--;
                  draw_x++;
               }
               if(op_y>=op_x) break;
            }
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_x--;
               draw_x++;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_y++;
                  draw_y--;
               }
               if(op_x<=0)
               {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                  break;
               }
            }
      
            break;
            
      case  4:
            draw_x = x+r;
            draw_y = y;
            
            op_x = r;
            op_y = 0;
 
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_y++;
               draw_y--;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_x--;
                  draw_x--;
               }
               if(op_y>=op_x) break;
            }
            while(1)
            {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                 
               /* ������һ�� */
               op_x--;
               draw_x--;
               if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
               {  op_y++;
                  draw_y--;
               }
               if(op_x<=0)
               {  tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
                  break;
               }
            }
            break;
            
      default:
            break;
      
   }

}

/****************************************************************************
* ���ƣ�tg_draw_arc()
* ���ܣ�ָ����㡢�յ㼰�뾶����(���ܻ�Բ)��ʹ�õ���˳ʱ�뷽��ͼ��
* ��ڲ����� x			Բ�ĵ�x������ֵ
*           y			Բ�ĵ�y������ֵ
*           stangle 	��ʼ�Ƕ�(0-359��)
*           endangle	��ֹ�Ƕ�(0-359��)
*           r  			Բ�İ뾶�յ�
*           color		��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void tg_draw_arc(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color)
//void  tg_draw_arc(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color)
{  int32_t  draw_x, draw_y;					// ��ͼ�������
   int32_t  op_x, op_y;						// ��������
   int32_t  op_2rr;							// 2*r*rֵ����
   
   int32_t  pno_angle;						// �Ƚǵ�ĸ���
   uint8_t  draw_on;							// ���㿪�أ�Ϊ1ʱ���㣬Ϊ0ʱ����
   
   
   /* �������� */
   if(r==0) return;							// �뾶Ϊ0��ֱ���˳�
   if(stangle==endangle) return;			// ��ʼ�Ƕ�����ֹ�Ƕ���ͬ���˳�
   if( (stangle>=360) || (endangle>=360) ) return;

   op_2rr = 2*r*r;							// ����rƽ������2
   pno_angle = 0;
   /* �ȼ�����ڴ˰뾶�µ�45�ȵ�Բ���ĵ��� */       
   op_x = r;
   op_y = 0;
   while(1)
   {  pno_angle++; 							// �������         
      /* ������һ�� */
      op_y++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x--;
      }
      if(op_y>=op_x) break;
   }
   
   draw_on = 0;								// �ʼ�ػ��㿪��
   /* ������ʼ�㼰�յ� */
   if(endangle>stangle) draw_on = 1;		// ���յ������㣬���һ��ʼ������(359)
   stangle = (360-stangle)*pno_angle/45;
   endangle = (360-endangle)*pno_angle/45;
   if(stangle==0) stangle=1;
   if(endangle==0) endangle=1;
   
   /* ��ʼ˳ʱ�뻭������359�ȿ�ʼ(��4����) */
   pno_angle = 0;
   
   draw_x = x+r;
   draw_y = y;         
   op_x = r;
   op_y = 0;
   while(1)
   {  /* ������һ�� */
      op_y++;
      draw_y--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x--;
         draw_x--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      if(op_y>=op_x)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_x--;
      draw_x--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y++;
         draw_y--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      
      if(op_x<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
    
    
   /* ��ʼ˳ʱ�뻭������269�ȿ�ʼ(��3����) */
   draw_y = y-r;
   draw_x = x;         
   op_y = r;
   op_x = 0;
   while(1)
   {  /* ������һ�� */
      op_x++;
      draw_x--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y--;
         draw_y++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      
      if(op_x>=op_y)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_y--;
      draw_y++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x++;
         draw_x--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      if(op_y<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
   
   /* ��ʼ˳ʱ�뻭������179�ȿ�ʼ(��2����) */
   draw_x = x-r;
   draw_y = y;         
   op_x = r;
   op_y = 0;
   while(1)
   {  /* ������һ�� */
      op_y++;
      draw_y++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x--;
         draw_x++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      if(op_y>=op_x)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_x--;
      draw_x++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y++;
         draw_y++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      
      if(op_x<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
  
  
   /* ��ʼ˳ʱ�뻭������89�ȿ�ʼ(��1����) */
   draw_y = y+r;
   draw_x = x;         
   op_y = r;
   op_x = 0;
   while(1)
   {  /* ������һ�� */
      op_x++;
      draw_x++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y--;
         draw_y--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      
      if(op_x>=op_y)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_y--;
      draw_y--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x++;
         draw_x++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
      } 
      if(op_y<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
}
#endif




#if  TG_DRAW_Pieslice_EN==1
/****************************************************************************
* ���ƣ�GUI_Pieslice()
* ���ܣ�ָ����㡢�յ㼰�뾶����(���ܻ�Բ)��ʹ�õ���˳ʱ�뷽��ͼ��
* ��ڲ����� x			Բ�ĵ�x������ֵ
*           y			Բ�ĵ�y������ֵ
*           stangle 	��ʼ�Ƕ�(0-359��)
*           endangle	��ֹ�Ƕ�(0-359��)
*           r  			Բ�İ뾶�յ�
*           color		��ʾ��ɫ
* ���ڲ�������
* ˵��������ʧ��ԭ����ָ����ַ������Ч��Χ��
****************************************************************************/
void  GUI_Pieslice(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color)
{  int32_t  draw_x, draw_y;					// ��ͼ�������
   int32_t  op_x, op_y;						// ��������
   int32_t  op_2rr;							// 2*r*rֵ����
   
   int32_t  pno_angle;						// �Ƚǵ�ĸ���
   uint8_t  draw_on;							// ���㿪�أ�Ϊ1ʱ���㣬Ϊ0ʱ����
   
   
   /* �������� */
   if(r==0) return;							// �뾶Ϊ0��ֱ���˳�
   if(stangle==endangle) return;			// ��ʼ�Ƕ�����ֹ�Ƕ���ͬ���˳�
   if( (stangle>=360) || (endangle>=360) ) return;

   op_2rr = 2*r*r;							// ����rƽ������2
   pno_angle = 0;
   /* �ȼ�����ڴ˰뾶�µ�45�ȵ�Բ���ĵ��� */       
   op_x = r;
   op_y = 0;
   while(1)
   {  pno_angle++; 							// �������         
      /* ������һ�� */
      op_y++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x--;
      }
      if(op_y>=op_x) break;
   }
   
   draw_on = 0;								// �ʼ�ػ��㿪��
   /* ������ʼ�㼰�յ� */
   if(endangle>stangle) draw_on = 1;		// ���յ������㣬���һ��ʼ������(359)
   stangle = (360-stangle)*pno_angle/45;
   endangle = (360-endangle)*pno_angle/45;
   if(stangle==0) stangle=1;
   if(endangle==0) endangle=1;
   
   /* ��ʼ˳ʱ�뻭������359�ȿ�ʼ(��4����) */
   pno_angle = 0;
   
   draw_x = x+r;
   draw_y = y;         
   op_x = r;
   op_y = 0;
   while(1)
   {  /* ������һ�� */
      op_y++;
      draw_y--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x--;
         draw_x--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      if(op_y>=op_x)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_x--;
      draw_x--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y++;
         draw_y--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      
      if(op_x<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
    
    
   /* ��ʼ˳ʱ�뻭������269�ȿ�ʼ(��3����) */
   draw_y = y-r;
   draw_x = x;         
   op_y = r;
   op_x = 0;
   while(1)
   {  /* ������һ�� */
      op_x++;
      draw_x--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y--;
         draw_y++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      
      if(op_x>=op_y)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_y--;
      draw_y++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x++;
         draw_x--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      if(op_y<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
   
   /* ��ʼ˳ʱ�뻭������179�ȿ�ʼ(��2����) */
   draw_x = x-r;
   draw_y = y;         
   op_x = r;
   op_y = 0;
   while(1)
   {  /* ������һ�� */
      op_y++;
      draw_y++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_x +1)>0 ) 	// ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x--;
         draw_x++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      if(op_y>=op_x)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_x--;
      draw_x++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_y +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y++;
         draw_y++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      
      if(op_x<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
  
  
   /* ��ʼ˳ʱ�뻭������89�ȿ�ʼ(��1����) */
   draw_y = y+r;
   draw_x = x;         
   op_y = r;
   op_x = 0;
   while(1)
   {  /* ������һ�� */
      op_x++;
      draw_x++;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr - 2*op_y +1)>0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_y--;
         draw_y--;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      
      if(op_x>=op_y)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);		// ��ʼ��ͼ
         break;
      }
   }
   
   while(1)
   {  /* ������һ�� */
      op_y--;
      draw_y--;
      if( (2*op_x*op_x + 2*op_y*op_y - op_2rr + 2*op_x +1)<=0 ) // ʹ�����ȽϷ�ʵ�ֻ�Բ��
      {  op_x++;
         draw_x++;
      }
      if(draw_on==1) tg_draw_point(draw_x, draw_y, color);			// ��ʼ��ͼ
      pno_angle++;
      if( (pno_angle==stangle)||(pno_angle==endangle) )			// �����������յ㣬���㿪��ȡ��
      {  draw_on = 1-draw_on;
         if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         tg_draw_line(x, y, draw_x, draw_y, color);
      } 
      if(op_y<=0)
      {  if(draw_on==1) tg_draw_point(draw_x, draw_y, color);
         break;
      }
   }
}
#endif
