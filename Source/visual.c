/*******************************************
FileName: visual.c
Author:   ������
Date��    2020/10/28
Description: �ó����ļ�����ʵ��������յȼ����ӻ�
Others: ��
Function List: 
        int visual page()   //�ײ�������
        void visual_basic() //���ӻ�������ձ�ʾ
        int risk_level()    //�жϷ��յȼ�
********************************************/
#include "common.h"
#include "dayinfo.h"
#include "draw.h"
#include "visual.h"

/*****************************
Function: int visual_page(void)
Description: ���ӻ������������
Calls:     void visual_basic()
Called by: main()
Table Accessed: areanow.DAT
Table Updated:  areanow.DAT
Input:  ��
Output: �� 
Return: 1   -> ����
        6   -> ͨ������
        7   -> ��ѯ����
       12   -> ע��
******************************/
int visual_page(void)
{
    int flg = 0;
    int choose = -1;
    Bar1(0, 0, 1024, 768, 0x9eef); //������

    //�˳���
    Bar1(900, 5, 1024, 55, 0x7bef); //�˳�����Ӱ
    Bar1(895, 0, 1019, 50, 59004);  //�˳���ʵ��
    prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24k");

    //���ؼ�
    Bar1(5, 5, 129, 55, 0x7bef); //0x7bef��ɫ
    Bar1(0, 0, 124, 50, 59004);
    prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24k");

    //��תѡ�����̨
    Bar1(282, 5, 766, 55, 0x7bef); //��ɫ��Ӱ
    Bar1(277, 0, 761, 50, 0x0000); //��ɫ��ɫ
    Bar1(280, 3, 438, 47, 63422);  //ע��
    Bar1(441, 3, 600, 47, 63422);  //ͨ��
    Bar1(603, 3, 758, 47, 63422);  //��ѯ

    //����
    prt_hz24(335, 13, "����", 0x0000, "HZK\\Hzk24k");
    prt_hz24(470, 13, "����ͨ��", 0x0000, "HZK\\Hzk24k");
    prt_hz24(630, 13, "���ݲ�ѯ", 0x0000, "HZK\\Hzk24k");
    prt_hz16_size(280, 100, 5, 5, "���յȼ���ͼ", 0xffe0, "HZK\\Hzk16s");

    visual_basic(); //��������������

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (flg == 0 && MouseIn(895, 0, 1019, 50)) //�˳�����
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 56603);
            prt_hz24d(935, 12, "�˳�", 0, "HZK\\Hzk24k");
            MouseOn(mouse);
            flg = 1;
        }
        else if (flg == 0 && MouseIn(0, 0, 124, 50)) //���ؿ���
        {
            MouseOff(&mouse);
            Bar1(0, 0, 124, 50, 56603);
            prt_hz24d(38, 13, "����", 0, "HZK\\Hzk24k");
            MouseOn(mouse);
            flg = 1;
        }
        else if (flg == 0 && MouseIn(280, 3, 438, 47)) //ע������
        {
            MouseOff(&mouse);
            Bar2(280, 3, 438, 47, 7327);
            MouseOn(mouse);
            flg = 1;
        }
        else if (flg == 0 && MouseIn(441, 3, 600, 47)) //ͨ������
        {
            MouseOff(&mouse);
            Bar2(441, 3, 600, 47, 7327);
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(603, 3, 758, 47)) //��ѯ����
        {
            MouseOff(&mouse);
            Bar2(603, 3, 758, 47, 7327);
            MouseOn(mouse);
            flg = 1;
        }
        else if (flg == 1 && MouseIn(277, 0, 761, 50) 
                            && !(MouseIn(280, 3, 438, 47)) 
                            && !(MouseIn(441, 3, 600, 47)) 
                            && !(MouseIn(603, 3, 758, 47)) 
                            && !(MouseIn(805, 140, 865, 180)))
        {
            MouseOff(&mouse);
            Bar2(280, 3, 438, 47, 63422); //ע��
            Bar2(441, 3, 600, 47, 63422); //ͨ��
            Bar2(603, 3, 758, 47, 63422); //��ѯ
            MouseOn(mouse);
            flg = 0;
        }
        else if (flg == 1 && !(MouseIn(277, 0, 761, 50)) 
                           && !(MouseIn(805, 140, 865, 180)) 
                           && !(MouseIn(0, 0, 124, 50)) 
                           && !(MouseIn(895, 0, 1019, 50)))
        {
            //��ԭ����
            MouseOff(&mouse);
            Bar2(280, 3, 438, 47, 63422);     //ע��
            Bar2(441, 3, 600, 47, 63422);     //ͨ��
            Bar2(603, 3, 758, 47, 63422);     //��ѯ
            Bar1(895, 0, 1019, 50, 59004);    //�˳�
            Bar1(0, 0, 124, 50, 59004);       //����
            prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24k");
            prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24k");
            MouseOn(mouse);
            flg = 0;
        }
        if (MousePress(895, 0, 1019, 50)) //����˳�
        {
            CloseSVGA();
            delay(1000);
            exit(1);
        }
        else if (MousePress(0, 0, 124, 50)) //�������
        {
            return 1;
        }
        else if (MousePress(280, 3, 438, 47)) //���ע��
        {
            return 12;
        }
        else if (MousePress(603, 3, 758, 47)) //�����ѯ
        {
            if (choose == -1)
            {
                prt_hz24(810, 150, "��δѡ������", 0x0000, "HZK\\Hzk24k");
                delay(1000);
                Bar1(810, 150, 1000, 200, 0x9eef);
            }
            else
            {
                return 7;
            }
        }
        else if (MousePress(441, 3, 600, 47)) //���ͨ��
        {
            if (choose == 0)
            {
                return 6;
            }
            else if (choose == 1)
            {
                Bar1(810, 150, 1000, 200, 0x9eef);
                prt_hz24(810, 150, "�������޷�ͨ��", 0x0000, "HZK\\Hzk24k");
                delay(1000);
                Bar1(810, 150, 1000, 200, 0x9eef);
            }
            else if (choose == -1)
            {
                prt_hz24(810, 150, "��δѡ������", 0x0000, "HZK\\Hzk24k");
                delay(1000);
                Bar1(810, 150, 1000, 200, 0x9eef);
            }
        }
        /******************
        �ж�������С��->����->��->��
        ���ȼ��ɸߵ���
        �ɱ����ص����ֵĴ���
        ******************/
        if (MousePress(105, 320, 245, 480)) //����С��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ������С��", 0x0000, "HZK\\Hzk24k");
            wr_area(0);
            choose = 0;
            continue;
        }
        else if (MousePress(280, 320, 410, 475)) //����С��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�б���С��", 0x0000, "HZK\\Hzk24k");
            wr_area(1);
            choose = 0;
            continue;
        }
        else if (MousePress(105, 560, 245, 710)) //����С��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�й���С��", 0x0000, "HZK\\Hzk24k");
            wr_area(2);
            choose = 0;
            continue;
        }
        else if (MousePress(280, 560, 410, 710)) //��԰С��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�й�԰С��", 0x0000, "HZK\\Hzk24k");
            wr_area(3);
            choose = 0;
            continue;
        }
        else if (MousePress(555, 320, 695, 480)) //�ϳ�С��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ���ϳ�С��", 0x0000, "HZK\\Hzk24k");
            wr_area(4);
            choose = 0;
            continue;
        }
        else if (MousePress(740, 320, 920, 480)) //����С��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ������С��", 0x0000, "HZK\\Hzk24k");
            wr_area(5);
            choose = 0;
            continue;
        }
        else if (MousePress(555, 560, 695, 710)) //���Ϻɶ�
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�з��Ϻɶ�", 0x0000, "HZK\\Hzk24k");
            wr_area(6);
            choose = 0;
            continue;
        }
        else if (MousePress(740, 560, 900, 710)) //�������
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�к������", 0x0000, "HZK\\Hzk24k");
            wr_area(7);
            choose = 0;
            continue;
        }
        else if (MousePress(90, 290, 420, 500) 
                    && !MousePress(105, 320, 245, 480) 
                    && !MousePress(280, 320, 410, 475)) //�Ż�����
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�йŻ�����", 0x0000, "HZK\\Hzk24k");
            wr_area(8);
            choose = 1;
            continue;
        }
        else if (MousePress(90, 530, 420, 720) 
                    && !MousePress(105, 560, 245, 710) 
                    && !MousePress(280, 560, 410, 710)) //��Ӫ����
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ����Ӫ����", 0x0000, "HZK\\Hzk24k");
            wr_area(9);
            choose = 1;
            continue;
        }
        else if (MousePress(540, 290, 930, 500) 
                    && !MousePress(555, 320, 695, 480) 
                    && !MousePress(740, 320, 920, 480)) //�ϳ�����
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ���ϳ�����", 0x0000, "HZK\\Hzk24k");
            wr_area(10);
            choose = 1;
            continue;
        }
        else if (MousePress(540, 530, 930, 720) 
                    && !MousePress(555, 560, 695, 710) 
                    && !MousePress(740, 560, 900, 710)) //��������
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�б�������", 0x0000, "HZK\\Hzk24k");
            wr_area(11);
            choose = 1;
            continue;
        }
        else if (MousePress(50, 260, 460, 740) 
                    && !MousePress(90, 290, 420, 500) 
                    && !MousePress(90, 530, 420, 720)) //�γ���
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ���γ���", 0x0000, "HZK\\Hzk24k");
            wr_area(12);
            choose = 1;
            continue;
        }
        else if (MousePress(495, 260, 960, 740) 
                    && !MousePress(540, 290, 930, 500) 
                    && !MousePress(540, 530, 930, 720)) //������
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ�и�����", 0x0000, "HZK\\Hzk24k");
            wr_area(13);
            choose = 1;
            continue;
        }
        else if (MousePress(2, 240, 1022, 766) 
                    && !MousePress(495, 260, 960, 740) 
                    && !MousePress(50, 260, 460, 740)) //��
        {
            Bar1(805, 140, 805 + 200, 140 + 45, 0x9eef);
            prt_hz24(810, 150, "��ѡ����", 0x0000, "HZK\\Hzk24k");
            wr_area(14);
            choose = 1;
            continue;
        }
    }
}
/*****************************
Function: void visual_basic(void)
Description: ���ӻ������������
Calls:     risk_level()
           draw_floor1()
Called by: visual_page()
Input:  ��
Output: �� 
Return: 1   -> ����
        6   -> ͨ������
        7   -> ��ѯ����
       12   -> ע��
******************************/
void visual_basic(void)
{
    //��ÿ�����������ݴ���������
    int data[15] = {0};
    int temp1, temp2, temp3, temp4 = 10;
    int i = 0;
    for (i = 14; i >= 0; i--)
    {
        countareacases(i, &temp4, &temp1, &temp3, &temp2);
        data[14 - i] = temp2;
    }

    Bar1(0, 237, 1024, 768, 0x0000);              //�ڱ߿����巶Χ
    Bar1(2, 240, 1022, 766, risk_level(data[0])); //����Χ(�м�)(2,240,1022,766)

    Bar1(47, 257, 463, 743, 0x0000);
    Bar1(50, 260, 460, 740, risk_level(data[2])); //����γ��� 50,260,460,740

    //��������֮�����·
    Bar1(465, 240, 485, 768, 0);
    for (i = 0; i < 20; i++)
    {
        Line3(475, 242 + 25 * i, 475, 242 + 25 * i + 10, 2, 65184);
    }

    Bar1(492, 257, 963, 743, 0x0000);
    Bar1(495, 260, 960, 740, risk_level(data[1])); //�Ҳ������ 495,260,960,740

    Bar1(87, 287, 423, 503, 0x0000);
    Bar1(90, 290, 420, 500, risk_level(data[6])); //���Ż����� 90,290,420,500

    Bar1(87, 527, 423, 723, 0x0000);
    Bar1(90, 530, 420, 720, risk_level(data[5])); //�����Ӫ���� 90,530,420,720

    //����������֮�����·
    Bar1(0, 505, 1024, 525, 0);
    for (i = 0; i < 46; i++)
    {
        Line3(3 + 25 * i, 515, 3 + 25 * i + 10, 515, 2, 65184);
    }

    Bar1(537, 287, 933, 503, 0x0000);
    Bar1(540, 290, 930, 500, risk_level(data[4]));  //�Ҳ��ϳ����� 540,290,930,500

    Bar1(537, 527, 933, 723, 0x0000);
    Bar1(540, 530, 930, 720, risk_level(data[3]));  //�Ҳ౱������ 540,530,930,720

    Bar1(102, 317, 248, 483, 0x0000);
    Bar1(105, 320, 245, 480, risk_level(data[14])); //�������С�� 105,320,245,480
    draw_floor1(120, 360);

    Bar1(277, 317, 413, 478, 0x0000);
    Bar1(280, 320, 410, 475, risk_level(data[13])); //��౱��С�� 280,320,410,475
    draw_floor2(310, 360);

    //�����С��֮�����·
    Bar1(250, 240, 270, 766, 0);
    for (i = 0; i < 46; i++)
    {
        Line3(260, 245 + 25 * i, 260, 245 + 25 * i + 10, 2, 65184);
    }

    Bar1(102, 557, 248, 713, 0x0000);
    Bar1(105, 560, 245, 710, risk_level(data[12])); //������С�� 105,560,245,710
    draw_floor3(140, 600);

    Bar1(277, 557, 413, 713, 0x0000);
    Bar1(280, 560, 410, 710, risk_level(data[11])); //����԰С�� 280,560,410,710
    draw_floor1(285, 600);

    Bar1(552, 317, 698, 483, 0x0000);
    Bar1(555, 320, 695, 480, risk_level(data[10])); //�Ҳ��ϳ�С�� 555,320,695,480
    draw_floor3(590, 360);

    Bar1(737, 317, 903, 483, 0x0000);
    Bar1(740, 320, 900, 480, risk_level(data[9])); //�Ҳ�����С�� 740,320,920,480
    draw_floor1(760, 360);

    //���Ҳ�С��֮�����·
    Bar1(710, 240, 730, 766, 0);
    for (i = 0; i < 46; i++)
    {
        Line3(720, 245 + 25 * i, 720, 245 + 25 * i + 10, 2, 65184);
    }

    Bar1(552, 557, 698, 713, 0x0000);
    Bar1(555, 560, 695, 710, risk_level(data[8])); //�Ҳ���Ϻɶ� 555,560,695,710
    draw_floor2(590, 600);

    Bar1(737, 557, 903, 713, 0x0000);
    Bar1(740, 560, 900, 710, risk_level(data[7])); //�Ҳ������� 740,560,900,710
    draw_floor3(780, 600);
}
/********************
Function: int risk_level(int cases)
Description: �жϷ��յȼ�����
Calls:  ��
Called by: visual_basic()
Input:  int cases Ϊ��Ӧ����ȷ������
Output: �� 
Return: ��ͬ���ն�Ӧ����ɫRGBֵ
Others:
    *�߷���*�����ķּ���׼Ϊ�ۼ�ȷ�ﲡ��    *����2��*
    *�и߷���*�����ķּ���׼Ϊ�ۼ�ȷ�ﲡ��  *2��*
    *�з���*�����ķּ���׼Ϊ�ۼ�ȷ�ﲡ��    *1��*
    *�ͷ���*�����ķּ���׼Ϊ�ۼ�ȷ�ﲡ��    *�޲���*
**********************/
int risk_level(int cases)
{
    if (cases == 0)
    {
        return 32736; //�ͷ�����ɫ
    }
    else if (cases == 1)
    {
        return 65184; //�з��ջ�ɫ
    }
    else if (cases == 2)
    {
        return 64800; //�и߷��ճ�ɫ
    }
    else if (cases > 2)
    {
        return 64526; //�߷��պ�ɫ
    }
    return 0;
}
