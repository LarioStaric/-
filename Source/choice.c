/*******************************************
FileName: choice.c
Author:   ������
Date��    2020/10/28
Description: �ó����ļ�����ʵ�ֵ������������˵�
             ������ʱ�书��
Function List: 
        choose_district //�������ƺ���
        choose_date     //����Ҫ��ѯ������
        dis_bar         //�����˵���ѡ���
********************************************/
#include "choice.h"
#include "common.h"
#include "drawc.h" //ʹ��findday����

/***********************************
Function: choose_district
Description: �������ƺ���
             ����areaΪ������Ӧ���
Called by: pop_window1()
*************************************/
int choose_district(int x, int y, char *area) //(x,y)Ϊ���Ͻ�����
{
    int flg = 0;
    int choice = 0;     //ѡ����
    int pre_flg = 0;    //�������Ʋ���
    int quit_flg = 0;   //�˳�����
    int choose_flg = 0; //�ж��Ƿ���ѡ������

    //�ĸ������Ӧ��ѡ���
    Bar1(x - 3, y - 3, x + 73, y + 33, 0);
    Bar1(x, y, x + 70, y + 30, 0xffff);
    prt_hz24d(x + 20, y + 5, "��", 0, "HZK\\Hzk24h");

    Bar1(x + 92, y - 3, x + 188, y + 33, 0);
    Bar1(x + 95, y, x + 185, y + 30, 0xffff);
    prt_hz24d(x + 125, y + 5, "��", 0, "HZK\\Hzk24h");

    Bar1(x + 207, y - 3, x + 323, y + 33, 0);
    Bar1(x + 210, y, x + 320, y + 30, 0xffff);
    prt_hz24d(x + 240, y + 5, "����", 0, "HZK\\Hzk24h");

    Bar1(x + 342, y - 3, x + 458, y + 33, 0);
    Bar1(x + 345, y, x + 455, y + 30, 0xffff);
    prt_hz24d(x + 375, y + 5, "С��", 0, "HZK\\Hzk24h");

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (flg == 0 && MouseIn(350, 415, 450, 455)) //ȷ�Ͽ���
        {
            MouseOff(&mouse);
            Bar2(350, 415, 450, 455, 800);
            prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
            MouseOn(mouse);
            flg = 1;
        }

        if (flg == 0 && MouseIn(550, 415, 650, 455)) //ȡ������
        {
            MouseOff(&mouse);
            Bar2(550, 415, 650, 455, 800);
            prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ��
            MouseOn(mouse);
            flg = 1;
        }

        else if (flg == 1 && !(MouseIn(350, 415, 450, 455)) 
                           && !(MouseIn(550, 415, 650, 455)))
        {
            MouseOff(&mouse);
            Bar1(350, 415, 450, 455, 0x8ff2);
            prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
            Bar1(550, 415, 650, 455, 0x8ff2);
            prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ����
            MouseOn(mouse);
            flg = 0;
        }

        else if (MousePress(350, 415, 450, 455) && choose_flg) //���ȷ����
        {
            return 1;
        }

        else if (MousePress(550, 415, 650, 455)) //���ȡ����
        {
            Bar1(x, y, x + 70, y + 30, 0xffff);
            prt_hz24d(x + 20, y + 5, "��", 0, "HZK\\Hzk24h");
            Bar1(x + 95, y, x + 185, y + 30, 0xffff);
            prt_hz24d(x + 125, y + 5, "��", 0, "HZK\\Hzk24h");
            Bar1(x + 210, y, x + 320, y + 30, 0xffff);
            prt_hz24d(x + 240, y + 5, "����", 0, "HZK\\Hzk24h");
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 375, y + 5, "С��", 0, "HZK\\Hzk24h");
            
            choose_flg = 0;
            if (quit_flg)
            {
                return 0;
            }
            quit_flg = 1; //�������Ա������
        }

        /*********************
		������ѡ���ж����
		***********************/

        else if (MousePress(x, y, x + 70, y + 30) && choice == 0) 
        {//����У�����������
            MouseOff(&mouse);
            dis_bar(x, y + 30, 70, 1);
            prt_hz24d(x + 12, y + 35, "ĳ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            
            pre_flg = 1;
            quit_flg = 0;
        }

        else if (MousePress(x, y + 30, x + 70, y + 60) && pre_flg == 1) 
        {//ѡ��"ĳ��"
            MouseOff(&mouse);
            Bar1(x, y, x + 70, y + 30, 0xffff);
            prt_hz24d(x + 12, y + 5, "ĳ��", 0, "HZK\\Hzk24h");
            Bar1(x - 3, y + 33, x + 73, y + 63, 0x8edf);
            
            choice = 1;
            pre_flg = 0;
            choose_flg = 1;
            MouseOn(mouse);
        }

        else if (MousePress(x + 95, y, x + 185, y + 30) && choice == 1) 
        {//�����������������
            MouseOff(&mouse);
            dis_bar(x + 95, y + 30, 90, 2);
            prt_hz24d(x + 105, y + 35, "�γ���", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 105, y + 68, "������", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            pre_flg = 2;
        }

        else if (MousePress(x + 95, y + 30, x + 185, y + 60) && pre_flg == 2) 
        {//ѡ��"�γ���"
            MouseOff(&mouse);
            Bar1(x + 95, y, x + 185, y + 30, 0xffff);
            prt_hz24d(x + 105, y + 5, "�γ���", 0, "HZK\\Hzk24h");
            Bar1(x + 92, y + 33, x + 188, y + 100, 0x8edf);
            choice = 2;
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 210, y, x + 320, y + 30) && choice == 2) 
        {//�������������������
            MouseOff(&mouse);
            dis_bar(x + 210, y + 30, 110, 2);
            prt_hz24d(x + 220, y + 35, "�Ż�����", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 220, y + 68, "��Ӫ����", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            pre_flg = 3;
        }

        else if (MousePress(x + 210, y + 30, x + 320, y + 60) && pre_flg == 3) 
        {//ѡ��"�Ż�����"
            MouseOff(&mouse);
            Bar1(x + 210, y, x + 320, y + 30, 0xffff);
            prt_hz24d(x + 220, y + 5, "�Ż�����", 0, "HZK\\Hzk24h");
            Bar1(x + 207, y + 33, x + 323, y + 93, 0x8edf);
            choice = 3;
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y, x + 455, y + 30) && choice == 3) 
        {//���С��������������
            MouseOff(&mouse);
            dis_bar(x + 345, y + 30, 110, 2);
            prt_hz24d(x + 355, y + 35, "����С��", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 355, y + 68, "����С��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            pre_flg = 4;
        }

        else if (MousePress(x + 345, y + 30, x + 455, y + 60) && pre_flg == 4) 
        {//ѡ��"����С��"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "����С��", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 4;
            *area = '0';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y + 60, x + 455, y + 90) && pre_flg == 4) 
        {//ѡ��"����С��"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "����С��", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 5;
            *area = '1';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 210, y + 60, x + 320, y + 90) && pre_flg == 3) 
        {//ѡ��"��Ӫ����"
            MouseOff(&mouse);
            Bar1(x + 210, y, x + 320, y + 30, 0xffff);
            prt_hz24d(x + 220, y + 5, "��Ӫ����", 0, "HZK\\Hzk24h");
            Bar1(x + 207, y + 33, x + 323, y + 93, 0x8edf);
            choice = 6;
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y, x + 455, y + 30) && choice == 6) 
        {//���С��������������
            MouseOff(&mouse);
            dis_bar(x + 345, y + 30, 110, 2);
            prt_hz24d(x + 355, y + 35, "����С��", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 355, y + 68, "��԰С��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);

            pre_flg = 4;
        }

        else if (MousePress(x + 345, y + 30, x + 455, y + 60) && pre_flg == 4) 
        {//ѡ��"����С��"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "����С��", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 7;
            *area = '2';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y + 60, x + 455, y + 90) && pre_flg == 4) 
        {//ѡ��"��԰С��"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "��԰С��", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 8;
            *area = '3';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 95, y + 60, x + 185, y + 90) && pre_flg == 2) 
        {//ѡ��"������"
            MouseOff(&mouse);
            Bar1(x + 95, y, x + 185, y + 30, 0xffff);
            prt_hz24d(x + 105, y + 5, "������", 0, "HZK\\Hzk24h");
            Bar1(x + 92, y + 33, x + 188, y + 100, 0x8edf);
            choice = 9;
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 210, y, x + 320, y + 30) && choice == 9) 
        {//�������������������
            MouseOff(&mouse);
            dis_bar(x + 210, y + 30, 110, 2);
            prt_hz24d(x + 220, y + 35, "�ϳ�����", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 220, y + 68, "��������", 0, "HZK\\Hzk24h");
            pre_flg = 5;
            MouseOn(mouse);
        }

        else if (MousePress(x + 210, y + 30, x + 320, y + 60) && pre_flg == 5) 
        {//ѡ��"�ϳ�����"
            MouseOff(&mouse);
            Bar1(x + 210, y, x + 320, y + 30, 0xffff);
            prt_hz24d(x + 220, y + 5, "�ϳ�����", 0, "HZK\\Hzk24h");
            Bar1(x + 207, y + 33, x + 323, y + 93, 0x8edf);
            choice = 10;
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y, x + 455, y + 30) && choice == 10) 
        {//���С��������������
            MouseOff(&mouse);
            dis_bar(x + 345, y + 30, 110, 2);
            prt_hz24d(x + 355, y + 35, "�ϳ�С��", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 355, y + 68, "����С��", 0, "HZK\\Hzk24h");
            pre_flg = 7;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y + 30, x + 455, y + 60) && pre_flg == 7) 
        {//ѡ��"�ϳ�С��"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "�ϳ�С��", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 11;
            *area = '4';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y + 60, x + 455, y + 90) && pre_flg == 7) 
        {//ѡ��"����С��"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "����С��", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 12;
            *area = '5';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 210, y + 60, x + 320, y + 90) && pre_flg == 5) 
        {//ѡ��"��������"
            MouseOff(&mouse);
            Bar1(x + 210, y, x + 320, y + 30, 0xffff);
            prt_hz24d(x + 220, y + 5, "��������", 0, "HZK\\Hzk24h");
            Bar1(x + 207, y + 33, x + 323, y + 93, 0x8edf);
            choice = 13;
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y, x + 455, y + 30) && choice == 13) 
        {//���С��������������
            MouseOff(&mouse);
            dis_bar(x + 345, y + 30, 110, 2);
            prt_hz24d(x + 355, y + 35, "���Ϻɶ�", 0, "HZK\\Hzk24h");
            prt_hz24d(x + 355, y + 68, "�������", 0, "HZK\\Hzk24h");
            pre_flg = 8;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y + 30, x + 455, y + 60) && pre_flg == 8) 
        {//ѡ��"���Ϻɶ�"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "���Ϻɶ�", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 14;
            *area = '6';
            pre_flg = 0;
            MouseOn(mouse);
        }

        else if (MousePress(x + 345, y + 60, x + 455, y + 90) && pre_flg == 8) 
        {//ѡ��"�������"
            MouseOff(&mouse);
            Bar1(x + 345, y, x + 455, y + 30, 0xffff);
            prt_hz24d(x + 355, y + 5, "�������", 0, "HZK\\Hzk24h");
            Bar1(x + 342, y + 33, x + 458, y + 93, 0x8edf);
            choice = 15;
            *area = '7';
            pre_flg = 0;
            MouseOn(mouse);
        }
    }
}

/***********************************
Function: choose_district
Description: ����Ҫ��ѯ������
Calls:  findday   //�ҵ�ĳ��
Called by: pop_window1()
*************************************/
int choose_date(int x, int y, int *key) //keyΪ����ʱ���Ӧ������Ϣ���ļ�����Ӧ��λ��
{

    char year[4 + 1] = "\0";
    char month[2 + 1] = "\0";
    char day[2 + 1] = "\0";

    int quit_flg = 0;
    int flg = 0;
    int choose_flg = 0;

    Bar1(x - 3, y - 3, x + 83, y + 33, 0);
    Bar1(x, y, x + 80, y + 30, 0xffff);
    prt_hz24d(x + 25, y + 5, "��", 0, "HZK\\Hzk24h");
    Bar1(x + 107, y - 3, x + 183, y + 33, 0);
    Bar1(x + 110, y, x + 180, y + 30, 0xffff);
    prt_hz24d(x + 130, y + 5, "��", 0, "HZK\\Hzk24h");
    Bar1(x + 207, y - 3, x + 293, y + 33, 0);
    Bar1(x + 210, y, x + 290, y + 30, 0xffff);
    prt_hz24d(x + 235, y + 5, "��", 0, "HZK\\Hzk24h");

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (flg == 0 && MouseIn(350, 415, 450, 455)) 
        {//ȷ�Ͽ���
            MouseOff(&mouse);
            Bar2(350, 415, 450, 455, 800);
            prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }

        if (flg == 0 && MouseIn(550, 415, 650, 455))
        { //ȡ������
            MouseOff(&mouse);
            Bar2(550, 415, 650, 455, 800);
            prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }

        else if (flg == 1 && !(MouseIn(350, 415, 450, 455)) 
                           && !(MouseIn(550, 415, 650, 455)))
        {
            MouseOff(&mouse);
            Bar1(350, 415, 450, 455, 0x8ff2);
            prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h");
            Bar1(550, 415, 650, 455, 0x8ff2);
            prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 0;
        }

        else if (MousePress(350, 415, 450, 455) && choose_flg)
        {//���ȷ����
            return 1;
        }

        else if (MousePress(550, 415, 650, 455))
        {//���ȡ����
            Bar1(x - 3, y - 3, x + 83, y + 33, 0);
            Bar1(x, y, x + 80, y + 30, 0xffff);
            prt_hz24d(x + 25, y + 5, "��", 0, "HZK\\Hzk24h");
            Bar1(x + 107, y - 3, x + 183, y + 33, 0);
            Bar1(x + 110, y, x + 180, y + 30, 0xffff);
            prt_hz24d(x + 130, y + 5, "��", 0, "HZK\\Hzk24h");
            Bar1(x + 207, y - 3, x + 293, y + 33, 0);
            Bar1(x + 210, y, x + 290, y + 30, 0xffff);
            prt_hz24d(x + 235, y + 5, "��", 0, "HZK\\Hzk24h");

            if (quit_flg)
            { 
                return 0;
            }
            quit_flg = 1;
        }

        if (MousePress(x, y, x + 80, y + 30)) //���*��*
        {
            MouseOff(&mouse);
            Bar1(x, y, x + 80, y + 30, 0xffff);
            Getinfo(x + 10, y + 5, year, 4); //�õ�����
            MouseOn(mouse);
        }
        else if (MousePress(x + 110, y, x + 180, y + 30)) //���*��*
        {
            MouseOff(&mouse);
            Bar1(x + 110, y, x + 180, y + 30, 0xffff);
            Getinfo(x + 120, y + 5, month, 2); //�õ�����
            MouseOn(mouse);
        }
        else if (MousePress(x + 210, y, x + 290, y + 30)) //���*��*
        {
            MouseOff(&mouse);
            Bar1(x + 210, y, x + 290, y + 30, 0xffff);
            Getinfo(x + 220, y + 5, day, 2); //�õ�����
            MouseOn(mouse);
            if (*key = findday(atoi(year), atoi(month), atoi(day)))
            {
                choose_flg = 1;
            }
            else
            {
				prt_hz24d(x+100,y+80,"�Ҳ�������",0,"HZK\\Hzk24h");
				delay(1000);
				Bar1(x+98, y+78, x+350, y+120, 0x8edf);
			}
        }
    }
}

/***********************************
Function: dis_bar
Description: ������������
Called by: choose_district()
*************************************/
void dis_bar(int x, int y, int wid, int n)
{
    int i;
    Bar1(x - 3, y, x + wid + 3, y + 30 * n + 3, 0);
    for (i = 0; i < n; i++)
    {
        Bar1(x, y + i * 30 + 3, x + wid, y + i * 30 + 30, 0xffff);
    }
}
