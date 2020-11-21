/*******************************************
FileName:dayinfo.h
Author:   ���Ӻ� 
Date��    2020/10/24
Description: ���ļ���Ҫ����������Ϣ���� 
Others: ��
Function List: 
         wr_day_inf();  	��ÿ��������Ϣд���ļ�
 		countcases();		���㵥���ļ��и�������
 		countallcases();	���������ļ��и�������
 		judge_date();		�ж�����������Ƿ�Ϸ�
 		judge_cases();		�ж������������Ϣ�Ƿ�Ϸ�
 		countareacases();	��ȡĳ�����������
 		wr_area();			����Ҫͨ�����ļ���д���ļ�
 		re_area();			����Ҫͨ�����ļ������� 
		 wr_database();		������д�����ݿ�
 		modify_database();	�޸����ݿ��е�����
 		getoneday();		��ȡĳ�������ݿ��е�λ��
********************************************/
#ifndef _DAYINFO_H_
#define _DAYINFO_H_

void wr_day_inf(char area[],char Ye[],char Mo[],char Da[],char In[],char De[],char He[],char User[]);
/*�������ܣ���ÿ��������Ϣд���ļ�*/

void countcases(char *filename,int *suminf,int *sumdea,int *sumheal,int *nowinf);
/*�������ܣ����㵥���ļ��и������� */

void countallcases(int filenumbers,int *alsuminf,int *alsumdea,int *alsumheal,int *alnowinf);
/*�������ܣ����������ļ��и������� */

int judge_date(char year[],char month[],char day[]);
/*�������ܣ��ж�����������Ƿ�Ϸ� */

int judge_cases(char inf[],char dea[],char hea[]);
/*�������ܣ��ж������������Ϣ�Ƿ�Ϸ� */

void countareacases(int areakey,int *suminf,int *sumdea,int *sumheal,int *nowinf);
/*�������ܣ���ȡĳ�����������*/

void wr_area(int areakey);
/*�������ܣ�����Ҫͨ�����ļ���д���ļ�*/

void re_area(int *areakey);
/*�������ܣ�����Ҫͨ�����ļ�������*/

void wr_database(DAY *a);
/*�������ܣ�������д�����ݿ�*/

void modify_database(SAVEDAY *a,char *area);
/*�������ܣ��޸����ݿ��е�����*/

void getoneday(SAVEDAY *a,int areakey,int daykey);
/*�������ܣ���ȡĳ���ڵ�����*/

#endif
