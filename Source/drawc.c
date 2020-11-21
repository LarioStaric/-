/*******************************************
FileName: drawc.c
Author:   ���Ӻ� 
Date��    2020/10/16
Description: ���ļ���Ҫ���ڻ�������ͼ 
Others: ��
Function List: 
        drawchart(); ��������ͼ���� 
 		readata();	 ��ȡ���ݺ��� 
 		areafunc();	 �������ת������ 
 		giveweight();�ı�Ȩ�غ��� 
 		findday();	 Ѱ�Ҷ�Ӧ�������ݺ��� 
********************************************/
#include "common.h"
#include "drawc.h"
#include "gettime.h"

/*�������ܣ�������ͼ*/

void drawchart(CHARTDATA *data, int areakey, int count)
{
    int i, j;
    float x = 1.0;
    int inf, hea, dea, alinf, alhea, aldea;
    giveweight(&areakey, &x);      //�ɲ�ͬ������벻ͬȨ�ط�ֹ����ͼ����
    readata(data, areakey, count); //��ȡ����
    Line3(221, 706, 221, 300, 3, 0x0000);
    Line3(221, 706, 920, 706, 3, 0x0000);
    for (i = 0; i < 10; i++) //���Ƽ�ͷ
    {
        Line3(221 - i, 300 + 2 * i, 221 + i, 300 + 2 * i, 1, 0x0000);
    }
    for (i = 0; i < 10; i++) //���Ƽ�ͷ
    {
        Line3(920 - 2 * i, 706 + i, 920 - 2 * i, 706 - i, 1, 0x0000);
    }
    
    for (i = 0; i < 135 - 1; i++) //��������ͼ
    {
        Line2(224 + (5 * i), 700 - x * data[i].allinf, 224 + 5 * (i + 1), 700 - x * data[i + 1].allinf, 0x1111);
        Line2(224 + (5 * i), 700 - x * data[i].alldea, 224 + 5 * (i + 1), 700 - x * data[i + 1].alldea, 0x2222);
        Line2(224 + (5 * i), 700 - x * data[i].allhea, 224 + 5 * (i + 1), 700 - x * data[i + 1].allhea, 0xffff);
        Line2(224 + (5 * i), 700 - x * data[i].heal, 224 + 5 * (i + 1), 700 - x * data[i + 1].heal, 0x4444);
        Line2(224 + (5 * i), 700 - x * data[i].death, 224 + 5 * (i + 1), 700 - x * data[i + 1].death, 0x5555);
        Line2(224 + (5 * i), 700 - x * data[i].infestor, 224 + 5 * (i + 1), 700 - x * data[i + 1].infestor, 0x6666);
    }
}
/*�������ܣ���ȡ����*/
void readata(CHARTDATA *data, int areakey, int count)
{
    char area[8 + 1] = "";
    const char t[4] = {".DAT"};
    int i, j, dnum, year, month, day;
    FILE *fp;
    char filename[10] = "start";
    SAVEDAY *d = NULL;
    memset(data, '\0', sizeof(CHARTDATA) * 135);
    areafunc(areakey, area); //�õ�������Ŷ�Ӧ����

    if ((d = (SAVEDAY *)malloc(sizeof(SAVEDAY))) == NULL)
    {

        delay(3000);
        exit(1); //����ռ䲻�㣬�˳�����
    }
    gett(&year, &month, &day);                            //�ҵ���������
    dnum = findday(year, month, day) - 135 * (count + 1); //�ӵ��տ�ʼ��ͼ
    if (dnum < 0)
        dnum = 0; //��ֹԽ��

    while (area[i] != '\0')
    {
        filename[0] = area[i];
        filename[1] = '\0';
        strcat(filename, t);
        filename[5] = '\0';
        i++;

        if ((fp = fopen(filename, "rb+")) == NULL)
        {
            put_asc16_size(185 + 150 + 80 + 80, 600, 2, 2, filename, 0x0000);
            delay(3000);
            exit(1); //��ʧ�ܣ��˳�����
        }
        for (j = 0; j < 135; j++)
        {
            fseek(fp, (dnum + j) * sizeof(SAVEDAY), SEEK_SET);
            fread(d, sizeof(SAVEDAY), 1, fp);
            data[j].infestor = data[j].infestor + atoi(d->infestor); //����������Ⱦ
            data[j].death = data[j].death + atoi(d->death);          //������������
            data[j].heal = data[j].heal + atoi(d->heal);             //��������
            data[j].allinf = data[j].allinf + atoi(d->allinf);       //������Ϊֹ �ܸ�Ⱦ��
            data[j].alldea = data[j].alldea + atoi(d->alldea);       //������Ϊֹ ��������
            data[j].allhea = data[j].allhea + atoi(d->allhea);       //������Ϊֹ ��������
        }
        if (fclose(fp) != 0) //�ر��ļ�
        {
            printf("\nError in closing file .");
            delay(3000);
            exit(1);
        }
    }
    free(d);
}
/*�������ܣ��������ת��*/
void areafunc(int areakey, char area[])
{
    switch (areakey)
    {
    case 0:
        strcpy(area, "0");
        break;
    case 1:
        strcpy(area, "1");
        break;
    case 2:
        strcpy(area, "2");
        break;
    case 3:
        strcpy(area, "3");
        break;
    case 4:
        strcpy(area, "4");
        break;
    case 5:
        strcpy(area, "5");
        break;
    case 6:
        strcpy(area, "6");
        break;
    case 7:
        strcpy(area, "7");
        break;
    case 8:
        strcpy(area, "01");
        break;
    case 9:
        strcpy(area, "23");
        break;
    case 10:
        strcpy(area, "45");
        break;
    case 11:
        strcpy(area, "67");
        break;
    case 12:
        strcpy(area, "0123");
        break;
    case 13:
        strcpy(area, "4567");
        break;
    case 14:
        strcpy(area, "01234567");
        break;
    }
}
/*�������ܣ�����Ȩ��*/
void giveweight(int *areakey, float *x)
{

    if (*areakey < 8)
    {
        *x = 3;
    }
    if (*areakey < 12 && *areakey > 7)
    {
        *x = 2;
    }
    if (*areakey > 11 && *areakey < 14)
    {
        *x = 1;
    }
    if (*areakey == 14)
    {
        *x = 0.5;
    }
}
/*�������ܣ�Ѱ��ĳ���Ӧ���*/
int findday(int year, int month, int day)
{
    FILE *fp;
    SAVEDAY *d = NULL;
    int length, i, count;
    if ((fp = fopen("0.DAT", "rb+")) == NULL)
    {
        put_asc16_size(185 + 150 + 80 + 80, 600, 2, 2, "file error", 0x0000);
        delay(3000);
        exit(1); //��ʧ�ܣ��˳�����
    }
    if ((d = (SAVEDAY *)malloc(sizeof(SAVEDAY))) == NULL)
    {

        delay(3000);
        exit(1); //����ռ䲻�㣬�˳�����
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp) / sizeof(SAVEDAY);
    for (i = 0; i < length; i++)
    {
        fseek(fp, i * sizeof(SAVEDAY), SEEK_SET);
        fread(d, sizeof(SAVEDAY), 1, fp);
        if (year == atoi(d->year) && month == atoi(d->month) && day == atoi(d->day))
        {
            //�ҵ���Ӧ���ں�ֹͣ
            break;
        }
    }
    free(d);
    if (fclose(fp) != 0) //�ر��ļ�
    {
        printf("\nError in closing file .");
        delay(3000);
        exit(1);
    }
    return i;
}
