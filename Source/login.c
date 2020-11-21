/*******************************************
FileName: login.c
Author:   ������
Date��    2020/10/28
Description: �ó����ļ������û���¼ 
Others: ��
Function List: 
        login_user()   //�û���¼���� 
********************************************/
#include "common.h"
#include "lgstate.h"
#include "login.h"

/*********************************
Function: login_user()
Description: �û���¼���� 
Calls:  wr_user        //����¼���˺�д���ļ�
        judge_userfrozen //�ж��û��Ƿ񶳽�
        right_password  //�ж������Ƿ���ȷ
Called by: main()
Table Accessed: userinfo.DAT
Table Updated:  usernow.DAT
Return:	3 -> ����ע�����
		5 -> ��¼�ɹ�
        4 -> ��������
       -1 -> �˳�
        0 ��> ����
********************************/
int login_user(void)
{
    //��ʼ��
    int flag = 0;
    int state = 1;
    char username[12 + 1] = "\0";
    char key[12 + 1] = "\0";

    Bar1(0, 0, 1024, 768, 0x9eef);

    //�˳����ؼ�
    Bar1(900, 5, 1024, 55, 0x7bef); //�˳�����Ӱ
    Bar1(895, 0, 1019, 50, 59004);  //�˳���ʵ��
    prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
    Bar1(5, 5, 127, 53, 0x7bef);
    Bar1(0, 0, 124, 50, 59004); //���ؼ�
    prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24h");

    //����
    prt_hz16_size(285, 150, 5, 5, "���͹�״����", 0xffe0, "HZK\\Hzk16s");
    prt_hz16_size(285, 250, 5, 5, "����ͨ��ϵͳ", 0xffe0, "HZK\\Hzk16s");

    //�˺������
    Bar1(374, 420, 659, 449, 0);
    Bar1(376, 422, 657, 447, 0xffff);
    Bar1(374, 484, 659, 513, 0);
    Bar1(376, 486, 657, 511, 0xffff);
    
    //��¼ע���
    Bar1(405, 560, 473, 594, 0x7bef); //��Ӱ
    Bar1(400, 555, 468, 589, 0xffff); //ʵ��
    Bar1(545, 560, 613, 594, 0x7bef); //��Ӱ
    Bar1(540, 555, 608, 589, 0xffff); //ʵ��
    
    //���������
    Bar1(700, 484 + 76, 815, 513 + 76, 0x7bef); //��Ӱ
    Bar1(695, 479 + 76, 810, 508 + 76, 0xffff); //ʵ��

    prt_hz24d(307, 423, "�˺�", 0, "HZK\\Hzk24h");
    prt_hz24d(307, 487, "����", 0, "HZK\\Hzk24h");
    prt_hz24d(410, 560, "��¼", 0, "HZK\\Hzk24h");
    prt_hz24d(550, 560, "ע��", 0, "HZK\\Hzk24h");
    prt_hz24d(705, 484 + 76, "��������", 0, "HZK\\Hzk24h");
    
    Mouse_Init();
    while (1)
    {
        char key_0 = 0; //���µ�¼�����״̬
                        //1��ʾȫ�����룬2��ʾ�˺�δ���룬3��ʾ����δ����
                        
        char key_1 = 2; //���µ�¼�����״̬
                        //0��ʾ��ע�ᣬ1��ʾ��δע��
                        
        char key_2 = 0; //���µ�¼�����״̬���˻�����ƥ��
        char key_3 = 0; //0��ʾ����ȷ��1��ʾ��ȷ
        
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
        if (flag == 0 && MouseIn(400, 555, 468, 589)) //��¼������
        {
            MouseOff(&mouse);
            Bar1(405, 560, 473, 594, 0x7bef);
            Bar1(400, 555, 468, 589, 57083);
            prt_hz24d(410, 560, "��¼", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        if (flag == 0 && MouseIn(540, 555, 608, 589)) //ע�������
        {
            MouseOff(&mouse);
            Bar1(545, 560, 613, 594, 0x7bef);
            Bar1(540, 555, 608, 589, 57083); //ע���
            prt_hz24d(550, 560, "ע��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        if (flag == 0 && MouseIn(695, 479 + 76, 810, 508 + 76)) //�������������
        {
            MouseOff(&mouse);
            Bar1(700, 484 + 76, 815, 513 + 76, 0x7bef);
            Bar1(695, 479 + 76, 810, 508 + 76, 57083); //���������
            prt_hz24d(705, 484 + 76, "��������", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        else if (flag == 1 && !(MouseIn(895, 0, 1019, 50)) 
                            && !(MouseIn(540, 555, 608, 589)) 
                            && !(MouseIn(400, 555, 468, 589)) 
                            && !(MouseIn(0, 0, 124, 50)) 
                            && !(MouseIn(695, 479 + 76, 810, 508 + 76)))
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 59004);
            Bar1(0, 0, 124, 50, 59004);
            Bar1(400, 555, 468, 589, 0xffff);
            Bar1(540, 555, 608, 589, 0xffff);
            Bar1(695, 479 + 76, 810, 508 + 76, 0xffff);
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(38, 13, "����", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(410, 560, "��¼", 0, "HZK\\Hzk24h");
            prt_hz24d(550, 560, "ע��", 0, "HZK\\Hzk24h");
            prt_hz24d(705, 484 + 76, "��������", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 0;
        }
        else if (MousePress(376, 422, 657, 447)) //����˺ſ�
        {
            prt_hz24d(700, 454, "���س����������룩", 0, "HZK\\Hzk24h");
            MouseOff(&mouse);
            Bar1(376, 422, 657, 447, 0xffff);
            Getinfo(380, 424, username, 9); //�õ��˺�
            MouseOn(mouse);
            Bar1(700, 454, 910, 454 + 24, 0x9eef);
        }
        else if (MousePress(376, 486, 657, 511)) //��������
        {
            MouseOff(&mouse);
            Bar1(376, 486, 657, 511, 0xffff);
            Getcode(380, 488, key, 9); //�õ�����
            MouseOn(mouse);
            Bar1(700, 486, 900, 486 + 28, 0x9eef);
        }
        else if (MousePress(540, 555, 608, 589)) //���ע��
        {
            return 3;
        }
        if (MousePress(400, 555, 468, 589)) //��¼ȷ�ϼ�
        {
            /*�ж��Ƿ�������ȫ*/
            state = 1;
            key_0 = complete_login(username[0], key[0]);   //1��ʾȫ������
                                                            //2��ʾ�˺�δ����
                                                            //3��ʾ����δ����
            {
                if (key_0 == 2)
                {
                    prt_hz24d(700, 410, "�ʻ�δ����", 0, "HZK\\Hzk24h");
                    state = 0;
                }
                else if (key_0 == 3)
                {
                    prt_hz24d(700, 490, "����δ����", 0, "HZK\\Hzk24h");
                    state = 0;
                }
            }
            
            /*�жϵ�¼�˺��Ƿ��Ѿ�ע��*/
            if (key_0 == 1)
            {
                key_1 = judge_same_name(username); //0��ʾ��ע�ᣬ1��ʾ��δע��
                if (key_1 == 1)
                {
                    prt_hz24d(650, 660, "�ʻ�δע��", 0, "HZK\\Hzk24h");
                    delay(1000);
                    Bar1(650, 660, 850, 660 + 35, 0x9eef);
                    state = 0;
                }
            }
            
            /*�ж��˺������Ƿ�ƥ��*/
            if (key_1 == 0) //���Ѿ�ע�ᣬ���˻������Ƿ�ƥ��
            {
                key_2 = right_password(username, key); //0��ʾ����ȷ��1��ʾ��ȷ
                if (key_2 == 0)
                {
                    prt_hz24d(650, 660, "���벻��ȷ", 0, "HZK\\Hzk24h");
                    delay(1000);
                    Bar1(650, 660, 850, 660 + 35, 0x9eef);
                    state = 0;
                }
            }
            if (key_2 == 1)
            {
                key_3 = judge_userfrozen(username);
                if (key_3 == 1)
                {
                    prt_hz24d(650, 660, "�ʻ��Ѷ���", 0, "HZK\\Hzk24h");
                    delay(500);
                    Bar1(650, 660, 850, 660 + 35, 0x9eef);
                    state = 0;
                }
            }
            if (state == 1) //����¼���˺�д���ļ�
            {
                wr_user(username);
                return 5; //����ϵͳ
            }
        }
        if (MousePress(695, 479 + 76, 810, 508 + 76)) //�����������
        {
            return 4;
        }
        if (MousePress(895, 0, 1019, 50)) //����˳�
        {
            return -1;
        }
        else if (MousePress(0, 0, 124, 50)) //�������
        {
            return 0;
        }
    }
}