/*******************************************
FileName: adop.c
Author:   ���Ӻ� 
Date��    2020/10/27
Description: ���ļ���Ҫ���ڹ���Աѡ��������� 
Others: ��
Function List: 
        admin_menu() ѡ������˵����� 
		admindraw()  ��ͼ���� 
		admindraw2() ��ͼ���� 
		adminbutton()��ť�������� 
********************************************/
#include "adop.h"
#include "common.h"

/*****************************
Function: int admin_menu(void)
Description: ѡ������˵�
Calls:     admindraw()
           admindraw2()
           adminbutton()
Called by: main()
Table Accessed: ��
Table Updated:  ��
Input:  ��
Output: �� 
Return: -1  -> �˳� 
        0   -> ��ӭ���溯��
		9   -> �û���Ϣ������ 
		10	-> ����û�ͨ������ 
		11	-> �����������ݺ��� 
******************************/
int admin_menu(void)
{
    int flag = 0;
    admindraw(); //��ͼ����
    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        admin_button(&flag);                //��������
        if (MousePress(400, 450, 650, 500)) //����û�ͨ��
            return 10;
        else if (MousePress(400, 550, 650, 600)) //������������
            return 11;
        else if (MousePress(400, 650, 650, 700)) //�û���Ϣ����
            return 9;
        else if (MousePress(0, 0, 150, 55)) //����
            return 0;
        else if (MousePress(874, 0, 1024, 55)) //�˳�
            return -1;
    }
}
/*****************************
Function: admindraw(void)
Description: ��ͼ���� 
Calls:     �� 
Called by: admin_menu() 
Table Accessed: ��
Table Updated:  ��
Input:  ��
Output: �� 
Return: �� 
******************************/
void admindraw(void)
{
    Bar1(0, 0, 1024, 768, 1658);

    Bar1(5, 5, 155, 60, 0x5b4f);
    Bar1(0, 0, 150, 55, 59004);
    prt_hz24(45, 12, "����", 0, "HZK\\Hzk24h");
    Bar1(869, 5, 1029, 60, 0x5b4f);
    Bar1(874, 0, 1024, 55, 59004);
    prt_hz24(919, 12, "�˳�", 0, "HZK\\Hzk24h");
    admindraw2();

    Bar1(406, 456, 656, 506, 0x7bef);
    Bar1(400, 450, 650, 500, 44925);
    Circlefill(420, 475, 10, 0xffff); //�ص����

    Bar1(406, 556, 656, 606, 0x7bef);
    Bar1(400, 550, 650, 600, 44925);
    Circlefill(420, 575, 10, 0xffff); //˾����Ϣ����

    Bar1(406, 656, 656, 706, 0x7bef);
    Bar1(400, 650, 650, 700, 44925);
    Circlefill(420, 675, 10, 0xffff); //�û���Ϣ��ѯ

    prt_hz24(453, 462, "����û�ͨ��", 0, "HZK//HzK24h");
    prt_hz24(453, 562, "������������", 0, "HZK//HzK24h");
    prt_hz24(453, 662, "�û���Ϣ����", 0, "HZK//HzK24h");
    Line3(426, 250, 426, 400, 3, 0);
    Line3(426, 250, 626, 250, 3, 0);
    Line3(626, 250, 626, 400, 3, 0);
    Circlefill(526, 190, 60, 0);
    Circlefill(526, 190, 55, 1658); //����Աͼ��
}
/*****************************
Function: admindraw2(void)
Description: ��ͼ���� 
Calls:     �� 
Called by: admin_menu() 
Table Accessed: ��
Table Updated:  ��
Input:  ��
Output: �� 
Return: �� 
******************************/
void admindraw2(void)
{
    prt_hz16_size(100, 100, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(100, 150, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(100, 200, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(100, 250, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(100, 300, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(100, 350, 2, 2, "Ա", 0, "HZK\\Hzk16s");
    prt_hz16_size(140, 100, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(140, 150, 2, 2, "ӭ", 0, "HZK\\Hzk16s");
    prt_hz16_size(140, 200, 2, 2, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 100, 3, 3, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 160, 3, 3, "ѡ", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 220, 3, 3, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 280, 3, 3, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 340, 3, 3, "Ҫ", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 400, 3, 3, "ִ", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 460, 3, 3, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 520, 3, 3, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 580, 3, 3, "��", 0, "HZK\\Hzk16s");
    prt_hz16_size(230, 640, 3, 3, "��", 0, "HZK\\Hzk16s");
}
/*****************************
Function: admin_button(int *flag)
Description: ��ť�������� 
Calls:     �� 
Called by: admin_menu() 
Table Accessed: ��
Table Updated:  ��
Input:  &flag 
Output: �� 
Return: �� 
******************************/
void admin_button(int *flag)
{
    if (*flag == 0 && MouseIn(0, 0, 150, 55)) //���ؿ���
    {
        MouseOff(&mouse);
        Bar1(0, 0, 150, 55, 56603);
        prt_hz24d(45, 12, "����", 0, "HZK\\Hzk24h");
        MouseOn(mouse);
        *flag = 1;
    }
    if (*flag == 0 && MouseIn(874, 0, 1024, 55))
    {
        MouseOff(&mouse);
        Bar1(874, 0, 1024, 55, 56603);
        prt_hz24d(919, 12, "�˳�", 0, "HZK\\Hzk24h");
        MouseOn(mouse);
        *flag = 2;
    }
    if (*flag == 0 && MouseIn(400, 450, 650, 500))
    {
        MouseOff(&mouse);
        Bar1(400, 450, 650, 500, 46876);
        Circlefill(420, 475, 10, 0x429a);
        prt_hz24d(453, 462, "����û�ͨ��", 0, "HZK//HzK24h");
        MouseOn(mouse);
        *flag = 3;
    }
    if (*flag == 0 && MouseIn(400, 550, 650, 600))
    {
        MouseOff(&mouse);
        Bar1(400, 550, 650, 600, 46876);
        Circlefill(420, 575, 10, 0x429a);
        prt_hz24d(453, 562, "������������", 0, "HZK//HzK24h");
        MouseOn(mouse);
        *flag = 4;
    }
    if (*flag == 0 && MouseIn(400, 650, 650, 700))
    {
        MouseOff(&mouse);
        Bar1(400, 650, 650, 700, 46876);
        Circlefill(420, 675, 10, 0x429a);
        prt_hz24d(453, 662, "�û���Ϣ����", 0, "HZK//HzK24h");
        MouseOn(mouse);
        *flag = 5;
    }
    else if (*flag == 1 && !(MouseIn(0, 0, 150, 55)))
    {
        MouseOff(&mouse);
        Bar1(0, 0, 150, 55, 59004);
        prt_hz24d(45, 12, "����", 0, "HZK\\Hzk24h");
        MouseOn(mouse);
        *flag = 0;
    }
    else if (*flag == 2 && !(MouseIn(874, 0, 1024, 55)))
    {
        MouseOff(&mouse);
        Bar1(874, 0, 1024, 55, 59004);
        prt_hz24d(919, 12, "�˳�", 0, "HZK\\Hzk24h");
        MouseOn(mouse);
        *flag = 0;
    }
    else if (*flag == 3 && !(MouseIn(400, 450, 650, 500)))
    {
        MouseOff(&mouse);
        Bar1(400, 450, 650, 500, 44925);
        Circlefill(420, 475, 10, 0xffff);
        prt_hz24d(453, 462, "����û�ͨ��", 0, "HZK//HzK24h");
        MouseOn(mouse);
        *flag = 0;
    }
    else if (*flag == 4 && !(MouseIn(400, 550, 650, 600)))
    {
        MouseOff(&mouse);
        Bar1(400, 550, 650, 600, 44925);
        Circlefill(420, 575, 10, 0xffff);
        prt_hz24d(453, 562, "������������", 0, "HZK//HzK24h");
        MouseOn(mouse);
        *flag = 0;
    }
    else if (*flag == 5 && !(MouseIn(400, 650, 650, 700)))
    {
        MouseOff(&mouse);
        Bar1(400, 650, 650, 700, 44925);
        Circlefill(420, 675, 10, 0xffff);
        prt_hz24d(453, 662, "�û���Ϣ����", 0, "HZK//HzK24h");
        MouseOn(mouse);
        *flag = 0;
    }
}
