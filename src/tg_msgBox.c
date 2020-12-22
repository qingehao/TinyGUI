#include "tgui.h"
struct tg_button  btn_ok_msgBox={
20,
20,
48,
15,
"OK",
1
};

struct tg_button  btn_cancel_msgBox={
20,
20,
48,
15,
"cancel",
1
};


//画消息框
uint8_t tg_msgBox_draw(tg_msgBox_t  msgBox)
//uint8_t tg_msgBox_draw(tg_msgBox_t  msgBox)
{
	/* 参数过滤，若窗口起出范围，则返回0 */
	if( ( (msgBox->with)<20 ) || ( (msgBox->hight)<20 ) ) return(0);// 宽度、高度检查，限制最小窗口
	if( (msgBox->x + msgBox->with ) > SCR_WIDTH ) return(0);		// 窗口宽度是否溢出
	if( (msgBox->y + msgBox->hight ) > SCR_HIGH ) return(0);	// 窗口高度是否溢出

	/* 开始画窗口 */
	tg_draw_rect_fill(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + msgBox->hight - 1, 0);//清屏
	tg_draw_rect(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + msgBox->hight - 1, 1);// 画窗口(边框)
	tg_draw_HLine(msgBox->x, msgBox->y + 14, msgBox->x + msgBox->with - 1, disp_color);		// 画标题下边框	 

	//填充标题栏
	tg_draw_rect_fill(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + 14-1, 1);
	if(tg_text_get_strHPixel(default_font,msgBox->title)>(msgBox->with-2))
	{  	
		return 0;//显示的标题超过了窗体的宽度
	} 
	//显示标题
	//show_str_mid(msgBox->x, msgBox->y+1,msgBox->title,12,12,0,msgBox->with);


	//确定按钮
	btn_ok_msgBox.state = 0;
	btn_ok_msgBox.title = msgBox->ok;
	btn_ok_msgBox.x = msgBox->x+5;
	btn_ok_msgBox.y = msgBox->y+msgBox->hight-1 -btn_ok_msgBox.height -3;
	tg_button_draw(&btn_ok_msgBox);

	//取消按钮	  
	btn_cancel_msgBox.state = 1;
	btn_cancel_msgBox.title = msgBox->cancel;
	btn_cancel_msgBox.x = msgBox->x+ msgBox->with -btn_cancel_msgBox.width-1-5;
	btn_cancel_msgBox.y = msgBox->y+msgBox->hight-1 -btn_cancel_msgBox.height-3;	 
	tg_button_draw(&btn_cancel_msgBox); 

	//显示消息
	//show_str(msgBox->x+6, msgBox->y+1+16,msgBox->msg, 12,12,1);
	return(1);
}

//设置按钮状态
void tg_msgBox_set_buttonSta(tg_msgBox_t  msgBox, uint8_t status)
//void tg_msgBox_set_buttonSta(tg_msgBox_t  msgBox, uint8_t status)
{	
	uint8_t ok_status;
	uint8_t cancel_status;

	if(status)
	{
		ok_status =1;
		cancel_status  =0;			
	}else
	{
		ok_status =0;
		cancel_status  =1;	
	}
	//确定按钮
	tg_button_selected(&btn_ok_msgBox,ok_status);

	//取消按钮	  
	tg_button_selected(&btn_cancel_msgBox,cancel_status);

}
//得到当前选择结果
uint8_t tg_msgBox_get_result(tg_msgBox_t  msgBox)
//uint8_t tg_msgBox_get_result(tg_msgBox_t  msgBox)
{
	return btn_ok_msgBox.state;	
}

//删除消息框
uint8_t tg_msgBox_delete(tg_msgBox_t  msgBox)
//uint8_t tg_msgBox_delete(tg_msgBox_t  msgBox)
{	
   if( ( (msgBox->with)<20 ) || ( (msgBox->hight)<20 ) ) return(0);		// 宽度、高度检查，限制最小窗口
   if( (msgBox->x + msgBox->with ) > SCR_WIDTH ) return(0);			// 窗口宽度是否溢出
   if( (msgBox->y + msgBox->hight ) > SCR_HIGH ) return(0);			// 窗口高度是否溢出
    
   /* 消隐窗口 */
   tg_draw_rect_fill(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + msgBox->hight - 1, back_color);
   return(1);
}

//struct tg_messageBox  msgBox={
//0,
//0,	
//128,
//64,
//"reset",	
//"system will be resetni hao a1234?",
//"OK",
//"Cancel"
//};


////测试消息框
//void test_MessageBox(void)
//{
// tg_msgBox_draw(&msgBox);
// tg_refresh();
// delay_ms(2000);
// tg_msgBox_set_buttonSta(&msgBox, 1);	
// tg_refresh();
// delay_ms(2000);
// tg_msgBox_set_buttonSta(&msgBox, 0);		
// tg_refresh();
// delay_ms(2000);	
//tg_msgBox_delete(&msgBox);	
//	
//	
//}




