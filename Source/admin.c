/**********************************************
FileName: admin.c
Author:   ������
Date��    2020/10/29
Description: ���ļ���Ҫ���ڹ���Ա��¼ע�Ṧ�� 
Function List: 
        login_user()   //�û���¼���� 
***********************************************/
#include "admin.h"
#include "common.h"
#include "lgstate.h"

/*********************************
Function: login_admin()
Description: ����Ա��¼���� 
Called by: main()
Return:	8 -> �������Ա������
        0 ��> ���ػ�ӭ����
********************************/
int login_admin(void)
{
    int flag = 0, key = 0; //flag ��귴�� key  �ж������Ƿ���ȷ
    char code[20] = "";     //�������벢���бȶ�

    Bar1(0, 0, 1024, 768, 0x9eef); //��ʼ������

    //�����˳����ؼ�
    Bar1(900, 5, 1024, 55, 0x7bef);
    Bar1(895, 0, 1019, 50, 59004);
    prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
    Bar1(5, 5, 127, 53, 0x7bef);
    Bar1(0, 0, 124, 50, 59004);
    prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24h");

    //����
    prt_hz16_size(285, 150, 5, 5, "���͹�״����", 0xffe0, "HZK\\Hzk16s");
    prt_hz16_size(285, 250, 5, 5, "����ͨ��ϵͳ", 0xffe0, "HZK\\Hzk16s");
    prt_hz16_size(404, 450, 2, 2, "�������Ա����", 0x5091, "HZK\\Hzk16s");

    //�����
    Bar1(382, 500, 682, 530, 0);
    Bar1(384, 502, 680, 528, 0xffff);

    //ȷ�Ͽ�
    Bar1(477, 585, 577, 635, 0);
    Bar1(472, 580, 572, 630, 0xffff);
    prt_hz24d(320, 500, "���룺", 0, "HZK\\Hzk24h");
    prt_hz24d(497, 592, "ȷ��", 0, "HZK\\Hzk24h");

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (flag == 0 && MouseIn(895, 0, 1019, 50)) //�˳�����
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 56603);
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        if (flag == 0 && MouseIn(0, 0, 124, 50)) //���ؿ���
        {
            MouseOff(&mouse);
            Bar1(0, 0, 124, 50, 56603);
            prt_hz24d(38, 13, "����", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        if (flag == 0 && MouseIn(472, 580, 572, 630)) //ȷ�ϼ�����
        {
            MouseOff(&mouse);
            Bar1(472, 580, 572, 630, 57083);
            prt_hz24d(497, 592, "ȷ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }

        else if (flag == 1 && !(MouseIn(0, 0, 124, 50)) 
                            && !(MouseIn(895, 0, 1019, 50)) 
                            && !(MouseIn(472, 580, 572, 630)))
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 59004);
            Bar1(0, 0, 124, 50, 59004);
            Bar1(472, 580, 572, 630, 0xffff);

            prt_hz24d(497, 592, "ȷ��", 0, "HZK\\Hzk24h");
            prt_hz24d(38, 13, "����", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");

            MouseOn(mouse);
            flag = 0;
        }
        else if (MousePress(384, 502, 680, 528)) //������������
        {
            MouseOff(&mouse);
            Getcode(384, 502, code, 10);
            MouseOn(mouse);
        }
        if (MousePress(472, 580, 572, 630)) //���ȷ�ϼ�
        {
            if (code[0] == '\0')
            {
                prt_hz24d(450, 664, "���������룡", 0, "HZK\\Hzk24h");
                delay(1000);
                Bar1(450, 664, 660, 688, 0x9eef);
            }
            else
            {
                key = admin_password(code);
                if (key == 1)
                {
                    prt_hz24d(480, 664, "��¼�ɹ���", 0, "HZK\\Hzk24h");
                    delay(1000);
                    return 8; //�������Ա���˵�����
                }
                if (key != 1)
                {
                    prt_hz24d(450, 664, "�������", 0, "HZK\\Hzk24h");
                    delay(1000);
                    Bar1(450, 664, 560, 688, 0x9eef);
                }
            }
        }
        if (MousePress(0, 0, 150, 55)) //�������
        {
            return 0;
        }
        else if (MousePress(874, 0, 1024, 55)) //����˳�
        {
            CloseSVGA();
            delay(1000);
            exit(1);
        }
    }
}