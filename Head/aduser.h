/*******************************************
FileName: aduser.h
Author:   ���Ӻ� 
Date��    2020/10/26
Description: ���ļ���Ҫ�����û������� 
Others: ��
Function List: 
        aduser();       �û����������� 
        aduser_menu();  �û����������� 
        aduserdraw();   ���淭ҳ���� 
 		aduserbutton(); ���ư�ť 
 		user_ice();		�����û� 
 		no_iced();      �ⶳ�û� 
 		button1();	    ��ť���� 
 		button3();	    ��ť���� 
 		put_User();	    ��ӡ�û����� 
 		put_run();      ��ӡ�û��Ƿ��ͨ�� 
********************************************/
#ifndef ADUSER.H
#define ADUSER.H

int aduser(void);
int aduser_menu(int *choose1);
void aduserdraw(int *choose1);
void aduserbutton(int *flag,int *choose1,int n);
int user_ice(void);
int no_iced(void);
void button1(int *flag);
void button3(int *flag);
int put_User(int *choose1);
void put_run(char s,int i);

#endif
