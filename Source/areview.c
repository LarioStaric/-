/*******************************************
FileName: areview.c
Author:   ������
Date��    2020/10/29
Description: �ó����ļ�����ͨ���������
Function List: 
        admin_review(void); //ͨ��������˺���
        judge_redata(void); //�ж��Ƿ��д����ͨ��
********************************************/
#include "areview.h"
#include "common.h"

/*********************************
Function: admin_review()
Description: ͨ��������˺��� 
Calls:  judge_redata
        wr_database
Called by: main()
Table Accessed: userepo.DAT
Table Updated:  userepo.DAT
********************************/
int admin_review(void)
{
    int flg = 0;
    FILE *fp;
    DAY *d = NULL;
    int i, j;
    int length;
    char key = 0;

    Bar1(0, 0, 1024, 768, 0xa794);

    if ((fp = fopen("userepo.dat", "rb+")) == NULL)
    { //��userepo.dat

        printf("\nUserInfo.dat error file");
        delay(3000);
        exit(1); //��ʧ�ܣ��˳�����
    }

    if ((d = (DAY *)malloc(sizeof(DAY))) == NULL)
    { //��ʼ��������Ϣ�ṹ��

        printf("memory error JudgeSameName");
        delay(3000);
        exit(1); //����ռ䲻�㣬�˳�����
    }

    fseek(fp, 0, SEEK_END); //�����ļ�ĩβ
    length = ftell(fp) / sizeof(DAY); //����ͨ������

    for (i = 0; i < length; i++)
    {
        memset(d, '\0', sizeof(DAY));   //��ʼ���ṹ��
        fseek(fp, i * sizeof(DAY), SEEK_SET);   //������ǰͨ������
        fread(d, sizeof(DAY), 1, fp);   //������д���ṹ��
        if (d->infostate == '0')        //���δ���������
        {
            break;
        }
    }

    if (fclose(fp) != 0) //�ر��ļ�
    {
        printf("\nError in closing file .");
        delay(3000);
        exit(1);
    }
    
    key = judge_redata();   //�ж��Ƿ��д����ͨ��
    
    if (key == '1')
    {
        prt_hz16_size(420, 300, 2, 2, "�����ݴ����", 0, "HZK\\Hzk16s");
        prt_hz16_size(375, 350, 2, 2, "���Զ�������һ����", 0, "HZK\\Hzk16s");
        delay(2000);
        if (d != NULL)
        {
            free(d);
            d = NULL;
        }
        return 8;
    }

    //����
    prt_hz24d(40, 50, "�û���", 0, "HZK\\Hzk24h");
    prt_hz24d(250, 50, "��", 0, "HZK\\Hzk24h");
    prt_hz24d(320, 50, "��", 0, "HZK\\Hzk24h");
    prt_hz24d(400, 50, "��", 0, "HZK\\Hzk24h");
    prt_hz24d(500, 50, "����ȷ��", 0, "HZK\\Hzk24h");
    prt_hz24d(650, 50, "��������", 0, "HZK\\Hzk24h");
    prt_hz24d(800, 50, "��������", 0, "HZK\\Hzk24h");
    prt_hz24d(920, 50, "��������", 0, "HZK\\Hzk24h");

    Line3(0, 98, 1024, 98, 2, 0);
    Bar1(0, 100, 1024, 198, 14137); //ͻ����һ��

    Line3(0, 198, 1024, 198, 2, 0);
    Line3(0, 298, 1024, 298, 2, 0);
    Line3(0, 398, 1024, 398, 2, 0);
    Line3(0, 498, 1024, 498, 2, 0);
    
    Bar1(0, 666, 100, 768, 0x5b4f);
    Bar1(0, 668, 98, 768, 0x37dc);
    prt_hz24d(25, 706, "����", 0, "HZK\\Hzk24h");
    Bar1(924, 666, 1024, 768, 0x5b4f);
    Bar1(926, 668, 1024, 768, 0x37dc);
    prt_hz24d(951, 706, "�˳�", 0, "HZK\\Hzk24h");
    Bar1(204, 666, 408, 768, 0x5b4f);
    Bar1(206, 668, 406, 768, 0xfd84);
    prt_hz24d(258, 706, "��������", 0, "HZK\\Hzk24h");
    Bar1(616, 666, 820, 768, 0x5b4f);
    Bar1(618, 668, 818, 768, 0xfd84);
    prt_hz24d(670, 706, "ɾ������", 0, "HZK\\Hzk24h");

    prt_hz16_asc16_size(20, 20 + 100, 2, 2, d->username, 0, "HZK\\Hzk16k");
    prt_hz16_asc16_size(40 + 200, 20 + 100, 2, 2, d->year, 0, "HZK\\Hzk16k");
    prt_hz16_asc16_size(40 + 200 + 100, 20 + 100, 2, 2, d->month, 0, "HZK\\Hzk16k");
    prt_hz16_asc16_size(40 + 200 + 100 + 60, 20 + 100, 2, 2, d->day, 0, "HZK\\Hzk16k");
    prt_hz16_asc16_size(520, 20 + 100, 2, 2, d->infestor, 0, "HZK\\Hzk16k");
    prt_hz16_asc16_size(670, 20 + 100, 2, 2, d->death, 0, "HZK\\Hzk16k");
    prt_hz16_asc16_size(820, 20 + 100, 2, 2, d->heal, 0, "HZK\\Hzk16k");
    if (d->area[0] == '0')
    {
        prt_hz24(920, 20 + 100, "����С��", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '1')
    {
        prt_hz24(920, 20 + 100, "����С��", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '2')
    {
        prt_hz24(920, 20 + 100, "����С��", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '3')
    {
        prt_hz24(920, 20 + 100, "��԰С��", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '4')
    {
        prt_hz24(920, 20 + 100, "�ϳ�С��", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '5')
    {
        prt_hz24(920, 20 + 100, "����С��", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '6')
    {
        prt_hz24(920, 20 + 100, "���Ϻɶ�", 0x0000, "HZK\\Hzk24k");
    }
    if (d->area[0] == '7')
    {
        prt_hz24(920, 20 + 100, "�������", 0x0000, "HZK\\Hzk24k");
    }

    if (d != NULL)
    {
        free(d);
        d = NULL;
    }

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (flg == 0 && MouseIn(926, 668, 1024, 768)) //�˳�����
        {
            MouseOff(&mouse);
            Bar1(926, 668, 1024, 768, 0x9ea0);
            prt_hz24d(951, 706, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(0, 668, 98, 768)) //���ؿ���
        {
            MouseOff(&mouse);
            Bar1(0, 668, 98, 768, 0x9ea0);
            prt_hz24d(25, 706, "����", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(206, 668, 406, 768)) //�������ݼ�����
        {
            MouseOff(&mouse);
            Bar1(206, 668, 406, 768, 0x2f44);
            prt_hz24d(258, 706, "��������", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(618, 668, 818, 768)) //ɾ��������
        {
            MouseOff(&mouse);
            Bar1(618, 668, 818, 768, 0x2f44);
            prt_hz24d(670, 706, "ɾ������", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }

        else if (flg == 1 && !(MouseIn(926, 668, 1024, 768)) 
                           && !(MouseIn(0, 668, 98, 768)) 
                           && !(MouseIn(206, 668, 406, 768)) 
                           && !(MouseIn(618, 668, 818, 768)))
        {
            MouseOff(&mouse);
            Bar1(926, 668, 1024, 768, 0xccff);
            Bar1(0, 668, 98, 768, 0xccff);
            Bar1(206, 668, 406, 768, 0xffff);
            Bar1(618, 668, 818, 768, 0xffff);
            prt_hz24d(951, 706, "�˳�", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(25, 706, "����", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(258, 706, "��������", 0, "HZK\\Hzk24h");
            prt_hz24d(670, 706, "ɾ������", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 0;
        }
        else if (MousePress(206, 668, 406, 768)) //�����������
        {
            if ((fp = fopen("userepo.dat", "rb+")) == NULL)
            {
                printf("\nUserInfo.dat error file");
                delay(3000);
                exit(1); //��ʧ�ܣ��˳�����
            }

            if ((d = (DAY *)malloc(sizeof(DAY))) == NULL)
            {
                printf("memory error JudgeSameName");
                delay(3000);
                exit(1); //����ռ䲻�㣬�˳�����
            }
            
            fseek(fp, 0, SEEK_END);
            length = ftell(fp) / sizeof(DAY);
            
            for (i = 0; i < length; i++)
            {
                memset(d, '\0', sizeof(DAY));
                fseek(fp, i * sizeof(DAY), SEEK_SET);
                fread(d, sizeof(DAY), 1, fp);
                if (d->infostate == '0')    
                {
                    d->infostate = '1'; //���ͨ����������Ϊ1
                    break;
                }
            }

            fseek(fp, i * sizeof(DAY), SEEK_SET);
            
            fwrite(d, sizeof(DAY), 1, fp);  //���ļ��������û�ͨ��״̬

            wr_database(d); //��ͨ��������д���ļ�
            
            prt_hz24d(458, 706, "���ͨ��", 0, "HZK\\Hzk24h");
            delay(1000);
            
            if (d != NULL)
            {
                free(d);
                d = NULL;
            }
            if (fclose(fp) != 0) //�ر��ļ�
            {
                printf("\nError in closing file .");
                delay(3000);
                exit(1);
            }
            return 10;
        }
        else if (MousePress(618, 668, 818, 768)) //���ɾ������
        {
            if ((fp = fopen("userepo.dat", "rb+")) == NULL)
            {
                printf("\nUserInfo.dat error file");
                delay(3000);
                exit(1); //��ʧ�ܣ��˳�����
            }
            if ((d = (DAY *)malloc(sizeof(DAY))) == NULL)
            {
                printf("memory error JudgeSameName");
                delay(3000);
                exit(1); //����ռ䲻�㣬�˳�����
            }
            
            fseek(fp, 0, SEEK_END);
            length = ftell(fp) / sizeof(DAY);
            
            for (i = 0; i < length; i++)
            {
                memset(d, '\0', sizeof(DAY));
                fseek(fp, i * sizeof(DAY), SEEK_SET);
                fread(d, sizeof(DAY), 1, fp);
                if (d->infostate == '0')
                {
                    d->infostate = '2';
                    break;
                }
            }

            fseek(fp, i * sizeof(DAY), SEEK_SET);
            fwrite(d, sizeof(DAY), 1, fp); //���ļ��������û�ͨ��״̬
            
            prt_hz24d(458, 706, "��������", 0, "HZK\\Hzk24h");
            delay(1000);
            
            if (d != NULL)
            {
                free(d);
                d = NULL;
            }
            if (fclose(fp) != 0) //�ر��ļ�
            {
                printf("\nError in closing file .");
                delay(3000);
                exit(1);
            }
            return 10;
        }

        if (MousePress(926, 668, 1024, 768)) //����˳�
        {
            CloseSVGA();
            delay(1000);
            exit(1);
        }
        else if (MousePress(0, 668, 98, 768)) //�������
        {
            if (d != NULL)
            {
                free(d);
                d = NULL;
            }
            return 8;
        }
    }
}

/*********************************
Function: judge_redata()
Description: ͨ��������˺��� 
Called by: admin_review()
Table Accessed: userepo.DAT
********************************/
char judge_redata(void)
{
    char flg = '1';
    FILE *fp;
    DAY *d = NULL; //�ǵ�free
    int i;
    int length;
    
    if ((fp = fopen("userepo.dat", "rb+")) == NULL)
    {
        printf("\nUserInfo.dat error file");
        delay(3000);
        exit(1); //��ʧ�ܣ��˳�����
    }
    
    if ((d = (DAY *)malloc(sizeof(DAY))) == NULL)
    {
        printf("memory error JudgeSameName");
        delay(3000);
        exit(1); //����ռ䲻�㣬�˳�����
    }
    
    memset(d, '\0', sizeof(DAY));   //��ʼ���ṹ��
    fseek(fp, 0, SEEK_END); //�����ļ�ĩβ
    length = ftell(fp) / sizeof(DAY);   //����ͨ������
    
    for (i = 0; i < length; i++)
    {
        fseek(fp, i * sizeof(DAY), SEEK_SET);
        fread(d, sizeof(DAY), 1, fp);
        if (d->infostate == '0')    //�����δ���ͨ��
        {
            flg = '0';
            break;  //�˳�ѭ��
        }
    }

    if (d != NULL)
    {
        free(d);
        d = NULL;
    }

    if (fclose(fp) != 0) //�ر��ļ�
    {
        printf("\nError in closing file .");
        delay(3000);
        exit(1);
    }
    return flg;
}
