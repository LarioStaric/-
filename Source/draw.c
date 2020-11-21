/*******************************************
FileName: draw.h
Author:   ������
Date��    2020/10/28
Description: �ó����ļ����ڻ��ƿ��ӻ�����Ľ���
             �������е�����ͼ
Function List: 
        void draw_floor1(int x, int y); //���� visual_basic �еĽ���
        void draw_floor2(int x, int y);
        void draw_floor3(int x, int y);
        void draw_axis(int x, int y); //������
        void draw_column(int x, int y, int len); //����ͼ
********************************************/
#include "draw.h"

/***********************
Function: draw_floor1
Description: ���ƽ���
Called by: visual_basic()
Input: (x, y)Ϊͼ�����Ͻ�λ��
*************************/
void draw_floor1(int x, int y)
{
	int i;
	Line3(x,y,x+60,y,2,0);
	Line3(x,y,x,y+100,2,0);
	Line3(x+60,y+3,x+60,y+97,4,0);
	Line3(x,y+100,x+60,y+100,2,0);
	for(i = 8; i<80; i+=8){
		Line3(x,y+i,x+60,y+i,1,0);
	}
	for(i = 8; i<60; i+=8){
		Line3(x+i,y,x+i,y+72,1,0);
	}
	Line3(x+20,y+80,x+30,y+80,1,0);
	Line3(x+20,y+80,x+20,y+100,1,0);
	Line3(x+30,y+80,x+30,y+100,1,0);
	
	Line3(x+30,y+80,x+40,y+80,1,0);
	Line3(x+30,y+80,x+30,y+100,1,0);
	Line3(x+40,y+80,x+40,y+100,1,0);
	
	Line3(x+60,y+50,x+120,y+50,2,0);
	Line3(x+60,y+100,x+120,y+100,2,0);
	Line3(x+120,y+50,x+120,y+100,2,0);
	
	for(i = 68; i<120; i+=8){
		Line3(x+i,y+50,x+i,y+82,1,0);
	}
	for(i = 58; i<90; i+=8){
		Line3(x+60,y+i,x+120,y+i,1,0);
	}
	
	Line3(x+80,y+86,x+90,y+86,1,0);
	Line3(x+80,y+86,x+80,y+100,1,0);
	Line3(x+90,y+86,x+90,y+100,1,0);
	
	Line3(x+90,y+86,x+100,y+86,1,0);
	Line3(x+90,y+86,x+90,y+100,1,0);
	Line3(x+100,y+86,x+100,y+100,1,0);
}

/***********************
Function: draw_floor2
Description: ���ƽ���
Called by: visual_basic()
Input: (x, y)Ϊͼ�����Ͻ�λ��
*************************/
void draw_floor2(int x, int y){
	
	Line3(x-2,y-2,x+72,y,4,0);
	Line3(x,y,x,y+100,2,0);
	Line3(x+70,y,x+70,y+97,4,0);
	Line3(x,y+100,x+70,y+100,4,0);
	
	Line3(x+2,y-5,x+68,y-5,3,0);
	
	Line3(x-2,y+50,x+74,y+50,2,0);
	
	Line3(x+10,y+10,x+10,y+30,1,0);
	Line3(x+25,y+10,x+25,y+30,1,0);
	Line3(x+10,y+10,x+25,y+10,1,0);
	Line3(x+10,y+30,x+25,y+30,1,0);
	
	Line3(x+42,y+10,x+42,y+30,1,0);
	Line3(x+57,y+10,x+57,y+30,1,0);
	Line3(x+42,y+10,x+57,y+10,1,0);
	Line3(x+42,y+30,x+57,y+30,1,0);
	
	Line3(x+10,y+60,x+10,y+80,1,0);
	Line3(x+25,y+60,x+25,y+80,1,0);
	Line3(x+10,y+60,x+25,y+60,1,0);
	Line3(x+10,y+80,x+25,y+80,1,0);
	
	Line3(x+40,y+70,x+40,y+100,1,0);
	Line3(x+57,y+70,x+57,y+100,1,0);
	Line3(x+40,y+70,x+57,y+70,1,0);
	Line3(x+48,y+70,x+48,y+100,1,0);
}

/***********************
Function: draw_floor3
Description: ���ƽ���
Called by: visual_basic()
Input: (x, y)Ϊͼ�����Ͻ�λ��
*************************/
void draw_floor3(int x, int y)
{
	int i;
	Line3(x, y, x+80, y, 2, 0);
	Line3(x, y, x, y+100, 2, 0);
	Line3(x+80, y, x+80, y+100, 2, 0);
	Line3(x, y+100, x+80, y+100, 2, 0);
	
	for(i = 0; i < 4; i++)
	{
		Line2(x-i,y,x+41-i,y-32,0);
	}
	
	for(i = 0; i < 6; i++)
	{
		Line2(x+38+i,y-32,x+78+i,y,0);
	}
	
	Line3(x+10,y+10,x+10,y+30,1,0);
	Line3(x+30,y+10,x+30,y+30,1,0);
	Line3(x+10,y+10,x+30,y+10,1,0);
	Line3(x+10,y+30,x+30,y+30,1,0);
	
	Line3(x+50,y+10,x+50,y+30,1,0);
	Line3(x+70,y+10,x+70,y+30,1,0);
	Line3(x+50,y+10,x+70,y+10,1,0);
	Line3(x+50,y+30,x+70,y+30,1,0);
	
	Line3(x-3, y+50,x+83, y+50, 3, 0);
	
	Line3(x+10,y+60,x+10,y+80,1,0);
	Line3(x+30,y+60,x+30,y+80,1,0);
	Line3(x+10,y+60,x+30,y+60,1,0);
	Line3(x+10,y+80,x+30,y+80,1,0);
	
	Line3(x+35+10,y+65,x+35+10,y+100,1,0);
	Line3(x+58+10,y+65,x+58+10,y+100,1,0);
	Line3(x+35+10,y+65,x+58+10,y+65,1,0);
	Line3(x+63,y+77,x+63,y+80,1,0);
}

/***********************
Function: draw_axis
Description: ����������
Input: (x, y)Ϊͼ��ԭ��λ��
*************************/
void draw_axis(int x, int y){
	Line3(x, y-330, x, y, 2, 0);
	Line3(x, y, x+675, y, 2, 0);
	
	Line2(x-15, y-310, x, y-332,0);
	Line2(x-15, y-309, x, y-331,0);
	Line2(x-15, y-308, x, y-330,0);
	
	Line2(x, y-332, x+15, y-310,0);
	Line2(x, y-331, x+15, y-309,0);
	Line2(x, y-330, x+15, y-308,0);
	
	Line2(x+655, y-15, x+675, y, 0);
	Line2(x+656, y-15, x+676, y, 0);
	Line2(x+657, y-15, x+677, y, 0);
	
	Line2(x+655, y+15, x+675, y, 0);
	Line2(x+656, y+15, x+676, y, 0);
	Line2(x+657, y+15, x+677, y, 0);
}

/***********************
Function: draw_column
Description: ��������ͼ
Called by: showinfo_main()
Input: (x, y)Ϊͼ�����Ͻ�λ��
*************************/
void draw_column(int x, int y, int len)
{
	Bar1(x-2, y-2, x+len+2,y+20+2, 0xffff);
	Bar1(x, y, x+len,y+20, 64518);	
}




