#include "tgui.h"

//上按钮
const unsigned char scroll_btn_up[8]={
0x02,0x0E,0x3E,0x7E,0x7E,0x3E,0x0E,0x02,
};

//下按钮
const unsigned char scroll_btn_down[8]={
0x40,0x70,0x7C,0x7E,0x7E,0x7C,0x70,0x40,
};

//设置滚动条的位置
void tg_scrollbar_setPos(tg_scrollbar_t scbx)
{	
	uint16_t scbpos;  //滚动条偏移
	uint16_t scblen;  //滚动条可以滚动的长度
	uint16_t x,y,xlen,ylen;

	scblen=scbx->height-2*TG_SCROLL_BTN_HEIGHT-scbx->scbbarlen;//得到滚动条滚动空间的长度
	x=scbx->x+1;                  //滚动条起始坐标x
	y=scbx->y+TG_SCROLL_BTN_HEIGHT;  //滚动条起始坐标y
	xlen=scbx->width-2-1;         //滚动条宽度 -1
	ylen=scblen+scbx->scbbarlen-1;//滚动条长度 -1
	
	//清除滚动条
	tg_draw_rect_fill(x ,y,x+xlen,y+ylen, 0);
	if(scbx->totalitems <= scbx->itemsperpage)//总条目不够一页显示的
	{
		scbpos=0; //偏移0
	}
	else //不止一页
	{
		scbpos=(scbx->topitem*scblen)/(scbx->totalitems-1);//计算当前滚动条偏移的位置
	}
	
	//画出滚动条
	tg_draw_rect_fill(x ,y+scbpos,x+xlen,y+scbpos+scbx->scbbarlen, 1);
}



//创建一个滚动条
void tg_scrollbar_draw(tg_scrollbar_t scbx)
{
	uint32_t scbactlen=0;//滚动条可以滚动的空间长度
	if(scbx==NULL) return;
	if(scbx->width<TG_SCROLL_BTN_WIDTH) return;
	if(scbx->height<2*TG_SCROLL_BTN_HEIGHT) return;
	
	//画外边框
	tg_draw_rect(scbx->x, scbx->y, scbx->x+scbx->width-1, scbx->y+scbx->height-1, 1);
	//画上下两个按钮
	tg_draw_picture(scbx->x+(scbx->width-8)/2, scbx->y+1, (uint8_t *)scroll_btn_up, 8, 8);
	tg_draw_picture(scbx->x+(scbx->width-8)/2, scbx->y+scbx->height-9, (uint8_t *)scroll_btn_down, 8, 8);	
	//画按钮边框
	tg_draw_line(scbx->x, scbx->y+9, scbx->x+scbx->width-1, scbx->y+9,1);
	tg_draw_line(scbx->x, scbx->y+scbx->height-10, scbx->x+scbx->width-1, scbx->y+scbx->height-10,1);
	
	
	//可供滚动条滚动的空间范围
	scbactlen=scbx->height -2*TG_SCROLL_BTN_HEIGHT;
	
	//每页滚动条目大于总条目数 滚动条目等于最大可滚动的控件
	if(scbx->itemsperpage >= scbx->totalitems)scbx->scbbarlen=scbactlen;
	//每页滚动条目小于总条目数 
	else scbx->scbbarlen=(scbactlen*scbx->itemsperpage)/scbx->totalitems;//得到滚动条的长度
	//设置滚动条的位置
	tg_scrollbar_setPos(scbx);
}


//删除一个滚动条
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

////测试滚动条函数
//void test_scrollbar(void)
//{

//	tg_scrollbar_draw(&Scrollbar);
//	tg_refresh();								//刷新屏幕
//	rt_thread_mdelay(2000);
//	Scrollbar.topitem = 1;
//	tg_scrollbar_setPos(&Scrollbar);
//	tg_refresh();								//刷新屏幕
//	rt_thread_mdelay(2000);
//		Scrollbar.topitem = 2;
//	tg_scrollbar_setPos(&Scrollbar);
//	tg_refresh();
////	tg_scrollbar_draw(&Scrollbar);
//}




