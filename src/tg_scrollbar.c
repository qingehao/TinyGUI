#include "tgui.h"

//�ϰ�ť
const unsigned char scroll_btn_up[8]={
0x02,0x0E,0x3E,0x7E,0x7E,0x3E,0x0E,0x02,
};

//�°�ť
const unsigned char scroll_btn_down[8]={
0x40,0x70,0x7C,0x7E,0x7E,0x7C,0x70,0x40,
};

//���ù�������λ��
void tg_scrollbar_setPos(tg_scrollbar_t scbx)
{	
	uint16_t scbpos;  //������ƫ��
	uint16_t scblen;  //���������Թ����ĳ���
	uint16_t x,y,xlen,ylen;

	scblen=scbx->height-2*TG_SCROLL_BTN_HEIGHT-scbx->scbbarlen;//�õ������������ռ�ĳ���
	x=scbx->x+1;                  //��������ʼ����x
	y=scbx->y+TG_SCROLL_BTN_HEIGHT;  //��������ʼ����y
	xlen=scbx->width-2-1;         //��������� -1
	ylen=scblen+scbx->scbbarlen-1;//���������� -1
	
	//���������
	tg_draw_rect_fill(x ,y,x+xlen,y+ylen, 0);
	if(scbx->totalitems <= scbx->itemsperpage)//����Ŀ����һҳ��ʾ��
	{
		scbpos=0; //ƫ��0
	}
	else //��ֹһҳ
	{
		scbpos=(scbx->topitem*scblen)/(scbx->totalitems-1);//���㵱ǰ������ƫ�Ƶ�λ��
	}
	
	//����������
	tg_draw_rect_fill(x ,y+scbpos,x+xlen,y+scbpos+scbx->scbbarlen, 1);
}



//����һ��������
void tg_scrollbar_draw(tg_scrollbar_t scbx)
{
	uint32_t scbactlen=0;//���������Թ����Ŀռ䳤��
	if(scbx==NULL) return;
	if(scbx->width<TG_SCROLL_BTN_WIDTH) return;
	if(scbx->height<2*TG_SCROLL_BTN_HEIGHT) return;
	
	//����߿�
	tg_draw_rect(scbx->x, scbx->y, scbx->x+scbx->width-1, scbx->y+scbx->height-1, 1);
	//������������ť
	tg_draw_picture(scbx->x+(scbx->width-8)/2, scbx->y+1, (uint8_t *)scroll_btn_up, 8, 8);
	tg_draw_picture(scbx->x+(scbx->width-8)/2, scbx->y+scbx->height-9, (uint8_t *)scroll_btn_down, 8, 8);	
	//����ť�߿�
	tg_draw_line(scbx->x, scbx->y+9, scbx->x+scbx->width-1, scbx->y+9,1);
	tg_draw_line(scbx->x, scbx->y+scbx->height-10, scbx->x+scbx->width-1, scbx->y+scbx->height-10,1);
	
	
	//�ɹ������������Ŀռ䷶Χ
	scbactlen=scbx->height -2*TG_SCROLL_BTN_HEIGHT;
	
	//ÿҳ������Ŀ��������Ŀ�� ������Ŀ�������ɹ����Ŀؼ�
	if(scbx->itemsperpage >= scbx->totalitems)scbx->scbbarlen=scbactlen;
	//ÿҳ������ĿС������Ŀ�� 
	else scbx->scbbarlen=(scbactlen*scbx->itemsperpage)/scbx->totalitems;//�õ��������ĳ���
	//���ù�������λ��
	tg_scrollbar_setPos(scbx);
}


//ɾ��һ��������
void tg_scrollbar_delete(tg_scrollbar_t scbx)
{
  tg_draw_rect_fill(scbx->x, scbx->y, scbx->x+scbx->width-1, scbx->y+scbx->height-1, 0);

}

//struct tg_scrollbar  Scrollbar=
//{
//118,
//14,
//10,
//50,
//	
//9,
//3,
//9,
//0
//};

////���Թ���������
//void test_scrollbar(void)
//{

//	tg_scrollbar_draw(&Scrollbar);
//	tg_refresh();								//ˢ����Ļ
//	rt_thread_mdelay(2000);
//	Scrollbar.topitem = 1;
//	tg_scrollbar_setPos(&Scrollbar);
//	tg_refresh();								//ˢ����Ļ
//	rt_thread_mdelay(2000);
//		Scrollbar.topitem = 2;
//	tg_scrollbar_setPos(&Scrollbar);
//	tg_refresh();
////	tg_scrollbar_draw(&Scrollbar);
//}




