/**********************************************
FileName: welcome.c
Author:   ������
Date:     2020/10/28
Description: ���ƻ�ӭ����
Function list: 
        int welcome() //��ӭ�����ͼ�λ���
***********************************************/
#include "common.h"
#include "welcome.h"
/**********************
Function: int welcome()
Description: ��ӭ�����ͼ�λ���
Calls:  ��
Called by: main()
Input:  ��
Output: �� 
Return: 1   -> �û���¼
        2   -> ����Ա��¼
       -1   -> �˳�
**********************/
int welcome(void)
{
    int flg = 0;

    Bar1(0, 0, 1024, 768, 0x9eef); //0x9eef

    /*������ť��Ӱ*/
    Bar1(403, 450, 590, 525, 0x7bef); //�û���
    Bar1(403, 560, 590, 635, 0x7bef); //����Ա��

    /*������ť*/
    Bar1(400, 445, 585, 520, 0xde5d); //�û���
    Bar1(400, 555, 585, 630, 0xde5d); //����Ա��

    Circlefill(420, 482, 10, 0xffff); //�û���¼Բ�α�־
    Circlefill(420, 592, 10, 0xffff); //����Ա��¼Բ�α�־
    Bar2(400, 445, 585, 520, 0xffff); //�û���¼��
    Bar2(400, 555, 585, 630, 0xffff); //����Ա��

    /*�������Ϣ*/
    prt_hz16_size(285, 150, 5, 5, "���͹�״����", 0xffe0, "HZK\\Hzk16s");
    prt_hz16_size(285, 250, 5, 5, "����ͨ��ϵͳ", 0xffe0, "HZK\\Hzk16s"); //0xffe0 ����ɫ
    prt_hz24(455, 472, "�û���¼", 0x0000, "HZK\\Hzk24s");
    prt_hz24(455, 582, "����Ա", 0x0000, "HZK\\Hzk24s");

    /*�����˳���*/
    Bar1(900, 5, 1024, 55, 0x7bef); //�˳�����Ӱ
    Bar1(895, 0, 1019, 50, 59004);  //�˳���ʵ��
    prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");

    /*�������*/
    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (MousePress(400, 445, 585, 520)) //����û���
        {
            return 1; //�����û���¼����
        }
        if (MousePress(400, 555, 585, 630)) //�������Ա
        {
            return 2; //�������Ա����
        }
        if (MousePress(895, 0, 1019, 50)) //����˳�
        {
            return -1;
        }
        if (flg == 0 && MouseIn(895, 0, 1019, 50)) //�˳�������
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 56603);
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(400, 445, 585, 520)) //�û�������
        {
            MouseOff(&mouse);
            Bar2(400, 445, 585, 520, 0x429a);
            Circlefill(420, 482, 10, 0x429a);
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(400, 555, 585, 630)) //����Ա����
        {
            MouseOff(&mouse);
            Circlefill(420, 592, 10, 0x429a);
            Bar2(400, 555, 585, 630, 0x429a);
            MouseOn(mouse);
            flg = 1;
        }
        else if (flg == 1 && !(MouseIn(400, 445, 585, 520)) && !(MouseIn(400, 555, 585, 630)) && !(MouseIn(900, 0, 1024, 50)))
        {
            MouseOff(&mouse);
            Circlefill(420, 482, 10, 0xffff); //�û���¼Բ�α�־
            Circlefill(420, 592, 10, 0xffff); //����Ա��¼Բ�α�־
            Bar2(400, 445, 585, 520, 0xffff); //�û���¼��
            Bar2(400, 555, 585, 630, 0xffff); //����Ա��
            Bar1(895, 0, 1019, 50, 59004);
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 0;
        }
    }
}