/*************************
���ļ��������û�ע��
**************************/
#include "common.h"
#include "lgstate.h"
#include "register.h"

int register_user(void) //ע�����
{
    int flag = 0; //������־����
    char state = 1;
    char username[12 + 1] = {'\0'}; //username
    char key1[12 + 1] = {'\0'};     //password
    char key2[12 + 1] = {'\0'};     //ensure password
    char id[18 + 1] = {'\0'};       //IDnumber
    Bar1(0, 0, 1024, 768, 0x9eef);  //�������

    //����
    prt_hz16_size(285, 150, 5, 5, "���͹�״����", 0xffe0, "HZK\\Hzk16s");
    prt_hz16_size(285, 250, 5, 5, "����ͨ��ϵͳ", 0xffe0, "HZK\\Hzk16s");

    /*��������*/
    //�˳���
    Bar1(900, 5, 1024, 55, 0x7bef); //�˳�����Ӱ
    Bar1(895, 0, 1019, 50, 59004);  //�˳���ʵ��
    prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");

    //���ؼ�
    Bar1(5, 5, 127, 53, 0x7bef); //0x7bef��ɫ
    Bar1(0, 0, 124, 50, 59004);
    prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24h");

    Bar1(374, 423, 661, 451, 0);
    Bar1(376, 425, 659, 449, 0xffff); //�˺ſ�

    Bar1(374, 487, 661, 515, 0);
    Bar1(376, 489, 659, 513, 0xffff); //�����

    Bar1(374, 551, 661, 579, 0);
    Bar1(376, 553, 659, 577, 0xffff); //ȷ�������

    Bar1(374, 551 + 64, 661, 579 + 64, 0);
    Bar1(376, 553 + 64, 659, 577 + 64, 0xffff); //���֤��

    Bar1(361, 614 + 100, 429, 648 + 100, 0x7bef);
    Bar1(356, 609 + 100, 424, 643 + 100, 0xffff); //ȷ�Ͽ�

    Bar1(561, 614 + 100, 629, 648 + 100, 0x7bef);
    Bar1(556, 609 + 100, 624, 643 + 100, 0xffff); //ȡ����

    prt_hz24(307, 425, "�˺ţ�", 0, "HZK\\Hzk24h");
    prt_hz24(307, 489, "���룺", 0, "HZK\\Hzk24h");
    prt_hz24(259, 553, "ȷ�����룺", 0, "HZK\\Hzk24h");
    prt_hz24(259, 553 + 64, "���֤��", 0, "HZK\\Hzk24h");
    prt_hz24(366, 614 + 100, "ȷ��", 0, "HZK\\Hzk24h");
    prt_hz24(566, 614 + 100, "ȡ��", 0, "HZK\\Hzk24h");

    Mouse_Init(); //����ʼ��
    while (1)
    {
        char key_0 = 0;           //����ע������״̬���ɹ�1���˺�δ����2������δ����3������δȷ��4�����֤δ����5
        char key_1 = 0;           //����ע������״̬���˺ţ�����0��δ����1
        char key_2 = 0;           //����ע������״̬�������ʽ��0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ�Ϻ�Ҫ��
        char key_3 = 0;           //����ע������״̬���������룬0��ʾ����ͬ��1��ʾ��ͬ
        char key_4 = 0;           //����ע������״̬�����֤�����ʽ
                                  //0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ���ݲ��Ϻ�Ҫ��2��ʾ�Ϻ�Ҫ��
        
        MouseShow(&mouse);        //���ѭ��
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
        if (flag == 0 && MouseIn(366, 614 + 100, 414, 638 + 100)) //ȷ�Ͽ���
        {
            MouseOff(&mouse);
            Bar1(356, 609 + 100, 424, 643 + 100, 0xeeee);
            prt_hz24d(366, 614 + 100, "ȷ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        if (flag == 0 && MouseIn(566, 614 + 100, 614, 638 + 100)) //ȡ������
        {
            MouseOff(&mouse);
            Bar1(556, 609 + 100, 624, 643 + 100, 0xeeee);
            prt_hz24d(566, 614 + 100, "ȡ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }

        else if (flag == 1 && !(MouseIn(900, 0, 1024, 50)) && !(MouseIn(0, 0, 124, 50)) && !(MouseIn(366, 614 + 100, 414, 638 + 100)) && !(MouseIn(566, 614 + 100, 614, 638 + 100)))
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 59004);
            Bar1(356, 609 + 100, 424, 643 + 100, 0xffff);
            Bar1(556, 609 + 100, 624, 643 + 100, 0xffff);
            Bar1(0, 0, 124, 50, 59004);
            prt_hz24d(38, 13, "����", 0, "HZK\\Hzk24h");
            prt_hz24d(935, 12, "�˳�", 0, "HZK\\Hzk24h");
            prt_hz24d(366, 614 + 100, "ȷ��", 0, "HZK\\Hzk24h");
            prt_hz24d(566, 614 + 100, "ȡ��", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 0;
        }
        else if (MousePress(378, 425, 659, 449)) //�����˺�
        {
            prt_hz24d(700, 454, "���س����������룩", 0, "HZK\\Hzk24h");
            MouseOff(&mouse);
            Bar1(378, 425, 659, 449, 0xffff);
            Getinfo(380, 427, username, 12); //gets.h
            MouseOn(mouse);
            Bar1(670, 425, 670 + 200, 425 + 28, 0x9eef);
        }
        else if (MousePress(378, 489, 659, 513)) //��������
        {
            MouseOff(&mouse);
            Bar1(378, 489, 659, 513, 0xffff);
            Getcode(380, 491, key1, 12);
            MouseOn(mouse);
            Bar1(670, 425 + 64, 670 + 200, 425 + 28 + 64, 0x9eef);
        }
        else if (MousePress(378, 553, 659, 577)) //������������
        {
            MouseOff(&mouse);
            Bar1(378, 553, 659, 577, 0xffff);
            Getcode(380, 555, key2, 12);
            MouseOn(mouse);
            Bar1(670, 425 + 64 * 2, 670 + 200, 425 + 28 + 64 * 2, 0x9eef);
        }
        else if (MousePress(378, 553 + 64, 659, 577 + 64)) //�������֤
        {
            MouseOff(&mouse);
            Bar1(378, 553 + 64, 659, 577 + 64, 0xffff);
            Getinfo(380, 555 + 64, id, 18);
            MouseOn(mouse);
            Bar1(670, 425 + 64 * 3, 670 + 200, 425 + 28 + 64 * 3, 0x9eef);
        }
        if (MousePress(366, 614 + 100, 414, 638 + 100)) //���ȷ�ϼ�
        {
            state = 1;
            /*�ж��Ƿ�������ȫ*/
            key_0 = complete_register(username[0], key1[0], key2[0], id[0]); //�ɹ�1���˺�δ����2������δ����3������δȷ��4�����֤δ����5
            switch (key_0)
            {
            case 1:
                break;
            case 2:
                prt_hz24(670, 425, "�˺�δ����", 0, "HZK\\Hzk24h");
                state = 0;
                break;
            case 3:
                prt_hz24(670, 489, "����δ����", 0, "HZK\\Hzk24h");
                state = 0;
                break;
            case 4:
                prt_hz24(670, 553, "��ȷ������", 0, "HZK\\Hzk24h");
                state = 0;
                break;
            case 5:
                prt_hz24(670, 553 + 64, "���֤����δ����", 0, "HZK\\Hzk24h");
                state = 0;
                break;
            default:
                prt_hz24(670, 553, "����", 0, "HZK\\Hzk24h");
                break;
            }
            /*�ж��Ƿ�����*/
            if (key_0 == 1)
            {
                key_1 = judge_same_name(username); //0��ʾ������1��ʾ������
                if (key_1 == 0)
                {
                    prt_hz24(670, 553, "�û����ѱ�ʹ��", 0, "HZK\\Hzk24h");
                    state = 0;
                }
            }
            /*�ж������ʽ*/
            if (key_1 == 1)
            {
                key_2 = judge_password(key1); //0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ�Ϻ�Ҫ��
                if (key_2 == 0)
                {
                    prt_hz24(670, 553, "�������", 0, "HZK\\Hzk24h");
                    state = 0;
                }
            }
            /*�ж����������Ƿ���ͬ*/
            if (key_2 == 1)
            {
                key_3 = compare_password(key1, key2); //0��ʾ����ͬ��1��ʾ��ͬ
                if (key_3 == 0)
                {
                    prt_hz24(670, 553, "���벻һ��", 0, "HZK\\Hzk24h");
                    state = 0;
                }
            }
            /*�ж����֤�����ʽ*/
            if (key_3 == 1)
            {
                key_4 = judge_IDnumber(id); //0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ���ݲ��Ϻ�Ҫ��2��ʾ�Ϻ�Ҫ��
                if (key_4 == 0)
                {
                    prt_hz24(670, 553 + 64, "��������", 0, "HZK\\Hzk24h");
                    state = 0;
                }
                else if (key_4 == 1)
                {
                    prt_hz24(670, 553 + 64, "��������", 0, "HZK\\Hzk24h");
                    state = 0;
                }
            }

            if (state == 1)
            {
                wr_user_inf(username, key1, id);
                prt_hz24(670, 553, "ע��ɹ�", 0, "HZK\\Hzk24h");
                delay(1000);
                return 1;
            }
        }

        if (MousePress(566, 614, 614, 638)) //���ȡ����
        {
            return 1;
        }
        if (MousePress(900, 0, 1024, 50)) //����˳�
        {
            return -1;
        }
        if (MousePress(0, 0, 124, 50)) //�������
        {
            return 1;
        }
    }
}
