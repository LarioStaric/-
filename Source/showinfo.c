/************************************************
FileName: showinfo.h
Author:   ������
Date��    2020/10/28
Description: �ó����ļ�����ʵ��������������ͼ
Others: ��
Function List: 
        int showinfo_main(void); //������ʼ��, ��������������ͼ
        void drawbar(int key); //����ѡ���
        void bubble_Sort(int arr[], int eq_loc[], int len); //ð������
        void swap(int *a, int *b); //��������
*************************************************/
#include "common.h"
#include "dayinfo.h"
#include "draw.h"
#include "showinfo.h"
/***************************************************
Function: int showinfo_main(void)
Description: ������ʼ��, ��������������ͼ
Calls:     void drawbar(int key); //����ѡ���
           void bubble_Sort(int arr[], int eq_loc[], int len); //ð������
           void swap(int *a, int *b); //��������
           countareacases(i, &tmp1, &tmp2, &tmp3, &tmp4) //��ȡ������
           
Called by: main()
Table Accessed: i.DAT(��ͬ������Ӧ�������ļ�)
Table Updated:  ��
Input:  ��
Output: �� 
Return: 5   -> ���ӻ�����
       -1   -> �˳�
****************************************************/
int showinfo_main(void)
{
    //������ʼ��
    int flg = 0, key = 0;
    int data[15] = {0};
    int tmp1, tmp2, tmp3, tmp4 = 10;
    int i, k;
    
    //��ʼ������������ƥ������
    int eq_loc[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    char loc[15][20] = {"\0"};
    char loc_name[15][20] = 
    {"ĳ��", "������", "�γ���", "��������", "�ϳ�����", 
    "��Ӫ����", "�Ż�����", "�������", "���Ϻɶ�", "����С��", 
    "�ϳ�С��", "��԰С��", "����С��", "����С��", "����С��"};

    //����ѡ���
    drawbar(key);
    
    //����
    prt_hz16_size(315, 60, 4, 4, "ȷ�ﲡ������", 0xffe0, "HZK\\Hzk16s");

    //����ȷ������
    for (i = 14; i >= 0; i--)
    {
        countareacases(i, &tmp1, &tmp2, &tmp3, &tmp4);
        data[14 - i] = tmp1;
    }

    //��ȷ�����ݽ���ð������
    bubble_Sort(data, eq_loc, 15);

    //����ƥ��
    for (i = 0, k = 0; i < 15; i++)
    {
        stpcpy(loc[i], loc_name[eq_loc[k++]]);
    }

    //�������������ͼ
    for (i = 0; i < 15; i++)
    {
        prt_hz24(75, 240 + 32 * i, loc[i], 0x0000, "HZK\\Hzk24k");
        draw_column(185, 240 + 32 * i, data[i]);
    }

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        
        //ÿ��ѭ��Ϊ eq_loc ��������ֵ
        for (i = 0; i < 15; i++)
        {
            eq_loc[i] = i;
        }

        if (MousePress(895, 0, 1019, 50)) //����˳�
        {
            return -1;
        }
        if (MousePress(0, 0, 124, 50)) //�������
        {
            return 5; //���ؿ��ӻ�����
        }
        if (MousePress(255, 160, 355, 200) && key != 0) //�����ȷ��
        {
            for (i = 14; i >= 0; i--)
            {
                countareacases(i, &tmp1, &tmp2, &tmp3, &tmp4);
                data[14 - i] = tmp1;
            }
            key = 0;
            drawbar(key);
            prt_hz16_size(315, 60, 4, 4, "ȷ�ﲡ������", 0xffe0, "HZK\\Hzk16s");

            //��ȷ�����ݽ���ð������
            bubble_Sort(data, eq_loc, 15);

            //����ƥ��
            for (i = 0, k = 0; i < 15; i++)
            {
                stpcpy(loc[i], loc_name[eq_loc[k++]]);
            }
               
            //��������ͼ
            for (i = 0; i < 15; i++)
            {
                prt_hz24(70, 240 + 32 * i, loc[i], 0x0000, "HZK\\Hzk24k");
                draw_column(180, 240 + 32 * i, data[i]);
            }
        }
        if (MousePress(255 + 200, 160, 355 + 200, 200) && key != 1) //���������
        {
            for (i = 14; i >= 0; i--)
            {
                countareacases(i, &tmp1, &tmp2, &tmp3, &tmp4);
                data[14 - i] = tmp3;
            }
            key = 1;
            drawbar(key);
            prt_hz16_size(315, 60, 4, 4, "������������", 0xffe0, "HZK\\Hzk16s");
            
            //���������ݽ���ð������
            bubble_Sort(data, eq_loc, 15);

            //����ƥ��
            for (i = 0, k = 0; i < 15; i++)
            {
                stpcpy(loc[i], loc_name[eq_loc[k++]]);
            }
                
            //��������ͼ
            for (i = 0; i < 15; i++)
            {
                prt_hz24(70, 240 + 32 * i, loc[i], 0x0000, "HZK\\Hzk24k");
                draw_column(180, 240 + 32 * i, data[i]);
            }
        }
        if (MousePress(255 + 200 + 200, 160, 355 + 200 + 200, 200) && key != 2) //���������
        {
            for (i = 14; i >= 0; i--)
            {
                countareacases(i, &tmp1, &tmp2, &tmp3, &tmp4);
                data[14 - i] = tmp2;
            }
            key = 2;
            drawbar(key);
            prt_hz16_size(315, 60, 4, 4, "������������", 0xffe0, "HZK\\Hzk16s");
            bubble_Sort(data, eq_loc, 15);

            //����ƥ��
            for (i = 0, k = 0; i < 15; i++)
            {
                stpcpy(loc[i], loc_name[eq_loc[k++]]);
            }

            for (i = 0; i < 15; i++)
            {
                prt_hz24(70, 240 + 32 * i, loc[i], 0x0000, "HZK\\Hzk24k");
                draw_column(180, 240 + 32 * i, data[i] * 10);
            }
        }

        if (flg == 0 && MouseIn(895, 0, 1019, 50)) //�˳�����
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 56603);
            prt_hz24d(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(0, 0, 124, 50)) //���ؿ���
        {
            MouseOff(&mouse);
            Bar1(0, 0, 124, 50, 56603);
            prt_hz24d(38, 13, "����", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }

        else if (flg == 1 && !(MouseIn(0, 0, 124, 50)) && !(MouseIn(900, 0, 1024, 50)))
        {
            MouseOff(&mouse);
            Bar1(895, 0, 1019, 50, 59004); //�˳���ʵ��
            prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");

            Bar1(0, 0, 124, 50, 59004);
            prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24h");

            MouseOn(mouse);
            flg = 0;
        }
    }
}

/***************************************************
Function: void drawbar(int key)
Description: ����ѡ���         
Called by: showinfo_main(void)
Input:  int key ѡ�����Ͳ���
        0 -> ��ȷ��
        1 -> ������
        2 -> ������
****************************************************/
void drawbar(int key)
{
    Bar1(0, 0, 1024, 768, 0x9efc);

    //�����˳���
    Bar1(900, 5, 1024, 55, 0x7bef); //�˳�����Ӱ
    Bar1(895, 0, 1019, 50, 59004);  //�˳���ʵ��
    prt_hz24(935, 12, "�˳�", 0x0000, "HZK\\Hzk24h");

    //���ؼ�
    Bar1(5, 5, 127, 53, 0x7bef); //0x7bef��ɫ
    Bar1(0, 0, 124, 50, 59004);
    prt_hz24(38, 13, "����", 0x0000, "HZK\\Hzk24h");

    Bar1(258, 163, 358, 203, 0x7bef);
    Bar1(255, 160, 355, 200, 0xffff);
    prt_hz24(270, 168, "��ȷ��", 0x0000, "HZK\\Hzk24h");

    Bar1(255 + 203, 163, 355 + 203, 203, 0x7bef);
    Bar1(255 + 200, 160, 355 + 200, 200, 0xffff);
    prt_hz24(270 + 200, 168, "������", 0x0000, "HZK\\Hzk24h");

    Bar1(255 + 200 + 203, 163, 355 + 200 + 203, 203, 0x7bef);
    Bar1(255 + 200 + 200, 160, 355 + 200 + 200, 200, 0xffff);
    prt_hz24(270 + 200 + 200, 168, "������", 0x0000, "HZK\\Hzk24h");

    if (key == 0)
    {
        Bar2(255, 160, 355, 200, 56612);
    }
    if (key == 1)
    {
        Bar2(255 + 200, 160, 355 + 200, 200, 56612);
    }
    if (key == 2)
    {
        Bar2(255 + 200 + 200, 160, 355 + 200 + 200, 200, 56612);
    }
}

//��������
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//ð������
void bubble_Sort(int arr[], int eq_loc[], int len)
{
    int i, j;
    for (i = 1; i < len; i++)
        for (j = 1; j < len - i; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swap(&eq_loc[j], &eq_loc[j + 1]);
            }
    return;
}
