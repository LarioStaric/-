/*******************************************
FileName: drawc.h
Author:   ���Ӻ� 
Date��    2020/10/16
Description: ���ļ���Ҫ���ڻ�������ͼ 
Others: ��
Function List: 
        drawchart(); ��������ͼ���� 
 		readata();	 ��ȡ���ݺ��� 
 		areafunc();	 �������ת������ 
 		giveweight();�ı�Ȩ�غ��� 
 		findday();	 Ѱ�Ҷ�Ӧ�������ݺ��� 
********************************************/
#ifndef _DRAWC_H_
#define _DRAWC_H_

void drawchart(CHARTDATA *data,int areakey,int count);

void readata(CHARTDATA *data,int areakey,int count);

void areafunc(int areakey,char area[]);

void giveweight(int *areakey,float *x);

int findday(int year,int month,int day);

#endif


