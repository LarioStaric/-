/*******************************************
FileName: admod.h
Author:   ������
Date��    2020/10/29
Description: �ó����ļ����ڹ���Ա�������޸�
Function List: 
        login_user()   //�û���¼���� 
*******************************************/
#ifndef _ADMOD_H
#define _ADMOD_H

#include "data.h"

int admin_modify(void);
void modify_page(void);
void Unhighlight(void);
int pop_window1(int *key,char *area);

void click_Data_Block(int *datakey);
void mouse_feedback_main(void);
void modify_MainPage(int *key,char *area);
void pop_window2(int datakey,SAVEDAY *d,char *area);

#endif
