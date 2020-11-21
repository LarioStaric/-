/*******************************************
FileName: inquiry.c
Author:   ���Ӻ� 
Date��    2020/10/24
Description: ���ļ���Ҫ�����û�ͨ�����ݹ��� 
Others: ��
Function List: 
        inquiry  �û���ѯ������  
        drawarea ���������Ϣ  
********************************************/
#include "choice.h"
#include "common.h"
#include "dayinfo.h"
#include "drawc.h"
#include "gettime.h"
#include "inquiry.h"
// �û���ѯ������
int inquiry(void)
{
    //��ʼ��
    int flag = 0, areakey, datekey, judge;
    char area[6];
    char alinf[6] = {'\0'};
    char aldea[6] = {'\0'};
    char alhea[6] = {'\0'};
    char alnow[6] = {'\0'};
    //char filename[5+1]={'\0'};
    char cyear[5] = {'\0'};
    char cmonth[3] = {'\0'};
    char cday[3] = {'\0'};
    CHARTDATA data[135];
    SAVEDAY *dd = NULL;
    int alsuminf, alsumdea, alsumheal, alnowinf;
    int suminf, sumdea, sumheal, nowinf;
    int year, month, day, count = 0, today;
    re_area(&areakey);
    countareacases(14, &alsuminf, &alsumdea, &alsumheal, &alnowinf);
    itoa(alsuminf, alinf, 10);
    itoa(alsumdea, aldea, 10);
    itoa(alsumheal, alhea, 10);
    itoa(alnowinf, alnow, 10);
    Bar1(0, 0, 1024, 768, 0x9efc);

    if ((dd = (SAVEDAY *)malloc(sizeof(SAVEDAY))) == NULL)
    {
        printf("memory error CountCase");
        delay(3000);
        exit(1); //����ռ䲻�㣬�˳�����
    }

    gett(&year, &month, &day);         //�õ�����ʱ��
    today = findday(year, month, day); //�ҵ���Ӧ���������ݿ��е�λ��

    Bar1(248, 168, 752, 482, 0);
    Bar1(250, 170, 750, 480, 0x8edf); //������ɫ

    prt_hz24d(380, 200, "��ѡ����Ҫ��ѯ������", 0, "HZK\\Hzk24h");

    Bar1(348, 413, 452, 457, 0x4b32);
    Bar1(350, 415, 450, 455, 0x8ff2);
    prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
    Bar1(548, 413, 652, 457, 0x4b32);
    Bar1(550, 415, 650, 455, 0x8ff2);
    prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ����

    judge = choose_date(345, 255, &datekey);
    if (judge == 0)
    {
        return 5;
    }
    if (datekey > today) //�ж������Ƿ�Ϸ�
    {
        Bar1(0, 0, 1024, 768, 0x9efc);
        prt_hz16_size(420, 300, 2, 2, "������������", 0, "HZK\\Hzk16s");
        delay(2000);
        return 5;
    }
    getoneday(dd, areakey, datekey); //��ȡ��Ӧ������Ϣ

    Bar1(0, 0, 1024, 768, 0x9efc);

	Bar1(600-1, 720-1, 650+1, 750+1, 0x0000);
    Bar1(500-1, 720-1, 550+1, 750+1, 0x0000);
    Bar1(600, 720, 650, 750, 0xffff);
    Bar1(500, 720, 550, 750, 0xffff);
    
    //�����˳���
    Bar1(900, 5, 1024, 55, 0x7bef); //�˳�����Ӱ
    Bar1(895, 0, 1019, 50, 0xccff); //�˳���ʵ��
    prt_hz24(935, 12, "�˳�", 0xfc00, "HZK\\Hzk24h");

    //���ؼ�
    Bar1(5, 5, 127, 53, 0x7bef); //0x7bef��ɫ
    Bar1(0, 0, 124, 50, 0xccff);
    prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24h");

    //����
    prt_hz16_size(300, 20, 5, 5, "������Ϣ��ѯ", 0xffe0, "HZK\\Hzk16s"); //0xffe0 ����ɫ
    
    prt_hz24(500, 720, "��ǰ", 0x0000, "HZK\\Hzk24k");
    prt_hz24(600, 720, "���", 0x0000, "HZK\\Hzk24k");

    put_asc16_size(185, 200 + 50, 2, 2, alinf, 0x0000);
    prt_hz24(100, 200 + 50, "��ȷ��", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(185 + 150, 200 + 50, 2, 2, aldea, 0x0000);
    prt_hz24(100 + 150, 200 + 50, "������", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(185 + 150 + 150, 200 + 50, 2, 2, alhea, 0x0000);
    prt_hz24(100 + 150 + 150, 200 + 50, "������", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(185 + 150 + 150 + 150 + 20, 200 + 50, 2, 2, alnow, 0x0000);
    prt_hz24(100 + 150 + 150 + 150, 200 + 50, "�ִ�", 0x0000, "HZK\\Hzk24k");

    drawarea(areakey); //�����Ӧ������Ϣ

    countareacases(areakey, &suminf, &sumdea, &sumheal, &nowinf); //�����Ӧ������Ϣ

    gett(&year, &month, &day);

    put_asc16_size(285 + 80, 600, 2, 2, cyear, 0x0000);
    put_asc16_size(485 + 80, 600, 2, 2, cmonth, 0x0000);
    put_asc16_size(685 + 80, 600, 2, 2, cday, 0x0000);

    itoa(suminf, alinf, 10);
    itoa(sumdea, aldea, 10);
    itoa(sumheal, alhea, 10);
    itoa(nowinf, alnow, 10);
    put_asc16_size(185 + 80, 200, 2, 2, alinf, 0x0000);
    prt_hz24(100, 200, "ѡ����ȷ��", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(185 + 150 + 80 + 80, 200, 2, 2, aldea, 0x0000);
    prt_hz24(100 + 150 + 80, 200, "ѡ��������", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(185 + 150 + 150 + 80 + 80 + 80, 200, 2, 2, alhea, 0x0000);
    prt_hz24(100 + 150 + 150 + 80 + 80, 200, "ѡ��������", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(185 + 150 + 150 + 150 + 80 + 80 + 80 + 80, 200, 2, 2, alnow, 0x0000);
    prt_hz24(100 + 150 + 150 + 150 + 80 + 80 + 80, 200,
							 "ѡ���ִ�ȷ��", 0x0000, "HZK\\Hzk24k");

    put_asc16_size(120-60, 100, 2, 2, dd->year, 0x0000);
    prt_hz24(140, 100, "��", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(165, 100, 2, 2, dd->month, 0x0000);
    prt_hz24(140+ 60, 100, "��", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(165 + 60, 100, 2, 2, dd->day, 0x0000);
    prt_hz24(140+ 2 * 60, 100, "��", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(165 + 60 , 160, 2, 2, dd->infestor, 0x0000);
    prt_hz24(100, 160, "����ȷ��", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(165 + 60 * 3, 160, 2, 2, dd->heal, 0x0000);
    prt_hz24(100 + 140, 160, "��������", 0x0000, "HZK\\Hzk24k");
    put_asc16_size(180 + 60 * 5, 160, 2, 2, dd->death, 0x0000);
    prt_hz24(100 + 140 * 2, 160, "��������", 0x0000, "HZK\\Hzk24k");
//    put_asc16_size(165 + 60 * 6, 160, 2, 2, dd->allinf, 0x0000);
//    prt_hz24(100 + 140 * 3, 160 , "������ȷ��", 0x0000, "HZK\\Hzk24k");
//    put_asc16_size(165 + 60 * 7, 160, 2, 2, dd->allhea, 0x0000);
//    prt_hz24(100 + 140 * 4, 160, "����������", 0x0000, "HZK\\Hzk24k");
//    put_asc16_size(165 + 60 * 8, 160, 2, 2, dd->alldea, 0x0000);
//	prt_hz24(100 + 140 * 5, 160, "����������", 0x0000, "HZK\\Hzk24k");
//	
    drawchart(data, areakey, count); //������ͼ

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);

        if (flag == 0 && MouseIn(895, 0, 1019, 50)) //�˳�����
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 0x9ea0);
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }
        if (flag == 0 && MouseIn(0, 0, 124, 50)) //���ؿ���
        {
            MouseOff(&mouse);
            Bar1(0, 0, 124, 50, 0x9ea0);
            prt_hz24d(38, 13, "����", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flag = 1;
        }

        else if (flag == 1 && !(MouseIn(895, 0, 1019, 50)) && !(MouseIn(0, 0, 124, 50)))
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 0xccff);
            Bar1(0, 0, 124, 50, 0xccff);

            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(38, 13, "����", 0x0000, "HZK\\Hzk24h");

            MouseOn(mouse);
            flag = 0;
        }
        if (MousePress(600, 720, 650, 750) && count > 0)
        {
            count--;
            Bar1(228, 280, 1024, 710, 0x9efc);
            drawchart(data, areakey, count); //������ͼ
        }
        if (MousePress(500, 720, 550, 750) && count < 2)
        {
            count++;
            Bar1(228, 280, 1024, 710, 0x9efc);
            drawchart(data, areakey, count); //������ͼ
        }

        if (MousePress(895, 0, 1019, 50)) //����˳�
        {
            return -1;
        }
        else if (MousePress(0, 0, 124, 50)) //�������
        {
            free(dd);
            return 5;
        }
    }
}
// ���������Ϣ
void drawarea(int areakey)
{
    if (areakey == 0)
    {
        prt_hz24(790, 90, "��ѡ������С��", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 1)
    {
        prt_hz24(790, 90, "��ѡ�б���С��", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 2)
    {
        prt_hz24(790, 90, "��ѡ�й���С��", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 3)
    {
        prt_hz24(790, 90, "��ѡ�й�԰С��", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 4)
    {
        prt_hz24(790, 90, "��ѡ���ϳ�С��", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 5)
    {
        prt_hz24(790, 90, "��ѡ������С��", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 6)
    {
        prt_hz24(790, 90, "��ѡ�з��Ϻɶ�", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 7)
    {
        prt_hz24(790, 90, "��ѡ�к������", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 8)
    {
        prt_hz24(790, 90, "��ѡ�йŻ�����", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 9)
    {
        prt_hz24(790, 90, "��ѡ����Ӫ����", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 10)
    {
        prt_hz24(790, 90, "��ѡ���ϳ�����", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 11)
    {
        prt_hz24(790, 90, "��ѡ�б�������", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 12)
    {
        prt_hz24(790, 90, "��ѡ���γ���", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 13)
    {
        prt_hz24(790, 90, "��ѡ�и�����", 0x0000, "HZK\\Hzk24k");
    }
    if (areakey == 14)
    {
        prt_hz24(790, 90, "��ѡ����", 0x0000, "HZK\\Hzk24k");
    }
}
