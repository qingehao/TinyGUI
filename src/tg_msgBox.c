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


//����Ϣ��
uint8_t tg_msgBox_draw(tg_msgBox_t  msgBox)
//uint8_t tg_msgBox_draw(tg_msgBox_t  msgBox)
{
	/* �������ˣ������������Χ���򷵻�0 */
	if( ( (msgBox->with)<20 ) || ( (msgBox->hight)<20 ) ) return(0);// ��ȡ��߶ȼ�飬������С����
	if( (msgBox->x + msgBox->with ) > SCR_WIDTH ) return(0);		// ���ڿ���Ƿ����
	if( (msgBox->y + msgBox->hight ) > SCR_HIGH ) return(0);	// ���ڸ߶��Ƿ����

	/* ��ʼ������ */
	tg_draw_rect_fill(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + msgBox->hight - 1, 0);//����
	tg_draw_rect(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + msgBox->hight - 1, 1);// ������(�߿�)
	tg_draw_HLine(msgBox->x, msgBox->y + 14, msgBox->x + msgBox->with - 1, disp_color);		// �������±߿�	 

	//��������
	tg_draw_rect_fill(msgBox->x, msgBox->y, msgBox->x + msgBox->with - 1, msgBox->y + 14-1, 1);
	if(tg_text_get_strHPixel(default_font,msgBox->title)>(msgBox->with-2))
	{  	
		return 0;//��ʾ�ı��ⳬ���˴���Ŀ��
	} 
	//��ʾ����
	//show_str_mid(msgBox->x, msgBox->y+1,msgBox->title,12,12,0,msgBox->with);


	//ȷ����ť
	btn_ok_msgBox.state = 0;
	btn_ok_msgBox.title = msgBox->ok;
	btn_ok_msgBox.x = msgBox->x+5;
	btn_ok_msgBox.y = msgBox->y+msgBox->hight-1 -btn_ok_msgBox.height -3;
	tg_button_draw(&btn_ok_msgBox);

	//ȡ����ť	  
	btn_cancel_msgBox.state = 1;
	btn_cancel_msgBox.title = msgBox->cancel;
	btn_cancel_msgBox.x = msgBox->x+ msgBox->with -btn_cancel_msgBox.width-1-5;
	btn_cancel_msgBox.y = msgBox->y+msgBox->hight-1 -btn_cancel_msgBox.height-3;	 
	tg_button_draw(&btn_cancel_msgBox); 

	//��ʾ��Ϣ
	//show_str(msgBox->x+6, msgBox->y+1+16,msgBox->msg, 12,12,1);
	return(1);
}

//���ð�ť״̬
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
	//ȷ����ť
	tg_button_selected(&btn_ok_msgBox,ok_status);

	//ȡ����ť	  
	tg_button_selected(&btn_cancel_msgBox,cancel_status);

}
//�õ���ǰѡ����
uint8_t tg_msgBox_get_result(tg_msgBox_t  msgBox)
//uint8_t tg_msgBox_get_result(tg_msgBox_t  msgBox)
{
	return btn_ok_msgBox.state;	
}

//ɾ����Ϣ��
uint8_t tg_msgBox_delete(tg_msgBox_t  msgBox)
//uint8_t tg_msgBox_delete(tg_msgBox_t  msgBox)
{	
   if( ( (msgBox->with)<20 ) || ( (msgBox->hight)<20 ) ) return(0);		// ��ȡ��߶ȼ�飬������С����
   if( (msgBox->x + msgBox->with ) > SCR_WIDTH ) return(0);			// ���ڿ���Ƿ����
   if( (msgBox->y + msgBox->hight ) > SCR_HIGH ) return(0);			// ���ڸ߶��Ƿ����
    
   /* �������� */
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


////������Ϣ��
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




