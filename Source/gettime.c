/*��ȡ����ʱ��*/
#include "common.h"

void gett(int *year, int *month, int *day)
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    if ((p->tm_hour) < 8) /*�������׼ʱ��ת��Ϊ�й�ʱ��*/
        *day = p->tm_mday - 1;
    else
        *day = p->tm_mday;     /*��ȡ��ǰ�·�����,��Χ��1-31*/
    *month = 1 + p->tm_mon;    /*��ȡ��ǰ�·�,��Χ��0-11,����Ҫ��1*/
    *year = 1900 + p->tm_year; /*��ȡ��ǰ���,��1900��ʼ������Ҫ��1900*/
}
