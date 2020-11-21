/*******************************************
FileName: admod.c
Author:   ������
Date��    2020/10/29
Description: �ó����ļ����ڹ���Ա�������޸�
Function List: 
        admin_modify()  //�����޸������ƺ���
        pop_window1     //�ص���ʱ�䵯��
        pop_window2     //�����޸����ݵ���
        click_Data_Block//������ݿ����
        Unhighlight     //ȡ������
        modify_MainPage //��ҳ�����
        mouse_feedback_main //��귴��
Others:
�������������:
	M��1
		�γ���2		
			�Ż�����3
				����С��4
				����С��5
			��Ӫ����6
				����С��7
				��԰С��8
		������9
			�ϳ�����10
				�ϳ�С��11
				����С��12
            ��������13
				���Ϻɶ�14
				�������15
*******************************************/
#include "admod.h"
#include "choice.h"
#include "common.h"
#include "gettime.h"

/*********************************
Function: admin_modify()
Description: �����޸������ƺ��� 
Calls:  pop_window1 //�ص���ʱ�䵯��
        modify_MainPage //��ҳ�����
Called by: main()
Return:	8 ���ع���Ա������
********************************/
int admin_modify(void)
{ //�����޸�������

    int key;
    char area;

    //ѡ�����򵯴�
    Bar1(0, 0, 1024, 768, 0xa794);
    if (pop_window1(&key, &area))//���õ���1
    {
        return 8;   //���ȡ���򷵻ع���Ա������
    }   

    Bar1(0, 0, 1024, 768, 0xa794);

    //��ʾ��ҳ��
    modify_MainPage(&key, &area);

    return 8;
}

/*********************************
Function: pop_window1()
Description: ����ѡ�������ʱ�����������
Calls:  choose_district //�ص�ѡ��˵�
        choose_date     //ʱ��ѡ��
Called by: admin_modify()
Return:	0 ����admin_modify
        1 ���ع���Ա������
********************************/
int pop_window1(int *key, char *area)
{ //ѡ�������ʱ�����������

	int year,month,day,today;
	gett(&year, &month, &day);
	today = findday(year, month, day);
    Bar1(248, 168, 752, 482, 0);
    Bar1(250, 170, 750, 480, 0x8edf); //������ɫ

    prt_hz24d(380, 200, "��ѡ����Ҫ�޸ĵĵ���", 0, "HZK\\Hzk24h");

    Bar1(348, 413, 452, 457, 0x4b32);
    Bar1(350, 415, 450, 455, 0x8ff2);
    prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
    Bar1(548, 413, 652, 457, 0x4b32);
    Bar1(550, 415, 650, 455, 0x8ff2);
    prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ����

    //������ѡ�񵯴�
    if (choose_district(265, 255, area)) //���ȷ����������һ����
    {
        Bar1(248, 168, 752, 482, 0);
        Bar1(250, 170, 750, 480, 0x8edf); //������ɫ
        prt_hz24d(380, 200, "��ѡ����Ҫ�޸ĵ�����", 0, "HZK\\Hzk24h");
        Bar1(348, 413, 452, 457, 0x4b32);
        Bar1(350, 415, 450, 455, 0x8ff2);
        prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
        Bar1(548, 413, 652, 457, 0x4b32);
        Bar1(550, 415, 650, 455, 0x8ff2);
        prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ����

        //��ʱ��ѡ�񴰿�
        if (choose_date(345, 255, key))
        {
        	if (*key > today) //�ж������Ƿ�Ϸ�
    		{
        		Bar1(0, 0, 1024, 768, 0x9efc);
        		prt_hz16_size(420, 300, 2, 2, "������������", 0, "HZK\\Hzk16s");
        		delay(2000);
        		return 8;
    		}
    		else
    		return 0;
		}
            
        else    //ȡ��ѡ��ʱ�䣬���صص�ѡ�񵯴�
            pop_window1(key, area);
    }
    else
        return 1; //�ص�����Ա������
}

/*********************************
Function: modify_MainPage()
Description: �޸����ݹ�����ҳ��
Calls:  pop_window2     //�����޸����ݵ���
        click_Data_Block  //������ݿ����
Called by: admin_modify()
Table Accessed: i.DAT   (ѡ�е����������ļ�)
********************************/
void modify_MainPage(int *key, char *area)
{ //�޸����ݹ�����ҳ��

    int flg = 0, datKey = -1;
    int block_flg = 1;
    char filename[8];
    const char t[4] = {".DAT"};
    SAVEDAY *d = NULL;
    FILE *fp;

    filename[0] = *area;
    filename[1] = '\0';
    strcat(filename, t);
    filename[6] = '\0';
    
    if ((d = (SAVEDAY *)malloc(sizeof(SAVEDAY))) == NULL)
    {//Ϊ�ṹ������ڴ�

        delay(3000);
        exit(1); //����ռ䲻�㣬�˳�����
    }
    if ((fp = fopen(filename, "rb+")) == NULL)
    {//���ļ�
        put_asc16_size(185 + 150 + 80 + 80, 600, 2, 2, filename, 0x0000);
        delay(3000);
        exit(1); //��ʧ�ܣ��˳�����
    }
    
    //����ѡ�е�����
    fseek(fp, (*key) * sizeof(SAVEDAY), SEEK_SET);
    
    //�����ݶ����ṹ��
    fread(d, sizeof(SAVEDAY), 1, fp);
    
    //���
    Line3(0, 98, 1024, 98, 2, 0);
    Line3(0, 198, 1024, 198, 2, 0);
    Line3(0, 298, 1024, 298, 2, 0);
    Line3(0, 398, 1024, 398, 2, 0);
    Line3(0, 498, 1024, 498, 2, 0);
    Line3(0, 598, 1024, 598, 2, 0);
    Line3(512, 0, 512, 598, 2, 0); //����
    Bar1(0, 666, 100, 768, 0x5b4f);
    Bar1(0, 668, 98, 768, 0x37dc);
    prt_hz24d(25, 706, "����", 0, "HZK\\Hzk24h");
    Bar1(924, 666, 1024, 768, 0x5b4f);
    Bar1(926, 668, 1024, 768, 0x37dc);
    prt_hz24d(951, 706, "�˳�", 0, "HZK\\Hzk24h");
    Bar1(410, 666, 614, 768, 0x5b4f);
    Bar1(412, 668, 612, 768, 65523);
    prt_hz24d(462, 706, "�޸�����", 0, "HZK\\Hzk24h");

    prt_hz24d(160, 50, "����ȷ��", 0, "HZK\\Hzk24h");
    put_asc16_size(160, 50 + 100, 2, 2, d->infestor, 0x0000);
    prt_hz24d(160, 250, "��������", 0, "HZK\\Hzk24h");
    put_asc16_size(160, 250 + 100, 2, 2, d->heal, 0x0000);
    prt_hz24d(160, 450, "��������", 0, "HZK\\Hzk24h");
    put_asc16_size(160, 450 + 100, 2, 2, d->death, 0x0000);
    prt_hz24d(512 + 160, 50, "�ۼ�ȷ��", 0, "HZK\\Hzk24h");
    put_asc16_size(512 + 160, 50 + 100, 2, 2, d->allinf, 0x0000);
    prt_hz24d(512 + 160, 250, "�ۼ�����", 0, "HZK\\Hzk24h");
    put_asc16_size(512 + 160, 250 + 100, 2, 2, d->allhea, 0x0000);
    prt_hz24d(512 + 160, 450, "�ۼ�����", 0, "HZK\\Hzk24h");
    put_asc16_size(512 + 160, 450 + 100, 2, 2, d->alldea, 0x0000);
    
    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);
        if (flg == 0 && MouseIn(926, 668, 1024, 768)) //�˳�����
        {
            MouseOff(&mouse);
            Bar1(926, 668, 1024, 768, 14137);
            prt_hz24d(951, 706, "�˳�", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(0, 668, 98, 768)) //���ؿ���
        {
            MouseOff(&mouse);
            Bar1(0, 668, 98, 768, 14137);
            prt_hz24d(25, 706, "����", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        if (flg == 0 && MouseIn(412, 668, 612, 768)) //�޸����ݼ�����
        {
            MouseOff(&mouse);
            Bar1(412, 668, 612, 768, 65184);
            prt_hz24d(462, 706, "�޸�����", 0, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 1;
        }
        else if (flg == 1 && !(MouseIn(926, 668, 1024, 768)) 
                           && !(MouseIn(0, 668, 98, 768)) 
                           && !(MouseIn(412, 668, 612, 768)))
        {
            MouseOff(&mouse);
            Bar1(926, 668, 1024, 768, 0x37dc);
            Bar1(0, 668, 98, 768, 0x37dc);
            Bar1(412, 668, 612, 768, 65523);
            prt_hz24d(462, 706, "�޸�����", 0, "HZK\\Hzk24h");
            prt_hz24d(951, 706, "�˳�", 0x0000, "HZK\\Hzk24h");
            prt_hz24d(25, 706, "����", 0x0000, "HZK\\Hzk24h");
            MouseOn(mouse);
            flg = 0;
        }
        
        //���"�޸�����"
        else if (MousePress(412, 668, 612, 768) && datKey != -1)
        {
            block_flg = 0;
            MouseOff(&mouse);
            pop_window2(datKey, d, area);
            
            Bar1(0, 0, 1024, 768, 0xa794);
            modify_MainPage(key, area); //���´򿪽���
            MouseOn(mouse);

            block_flg = 1;
        }

        else if (MousePress(926, 668, 1024, 768)) //����˳�
        {
            CloseSVGA();
            delay(1000);
            exit(1);
        }

        else if (MousePress(0, 668, 98, 768)) //�������
        {
            if (fclose(fp) != 0) //�ر��ļ�
            {
                printf("\nError in closing file .");
                delay(3000);
                exit(1);
            }
            free(d);
            return;
        }
        if (block_flg) //������ݿ鷴��
            click_Data_Block(&datKey);
    }
}

/*********************************
Function: pop_window2()
Description: �����޸����ݵ���
Calls:  modify_database //�޸�����
Called by: modify_MainPage()
********************************/
void pop_window2(int datKey, SAVEDAY *d, char *area)
{ //�������ݵ���
    char modify_number[5 + 1] = "\0";
    int flg = 0;

    Bar1(248, 168, 752, 482, 0);
    Bar1(250, 170, 750, 480, 0x8edf); //������ɫ

    prt_hz24d(390, 200, "�������޸ĺ�����", 0, "HZK\\Hzk24h");
    Bar1(348, 413, 452, 457, 0x4b32);
    Bar1(350, 415, 450, 455, 0x8ff2);
    prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
    Bar1(548, 413, 652, 457, 0x4b32);
    Bar1(550, 415, 650, 455, 0x8ff2);
    prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ����

    Bar1(424, 258, 559, 292, 0);
    Bar1(426, 260, 557, 290, 0xffff); //�����

    Mouse_Init();
    while (1)
    {
        MouseShow(&mouse);

        if (flg == 0 && MouseIn(350, 415, 450, 455)) //ȷ�Ͽ���
        {
            MouseOff(&mouse);
            Bar2(350, 415, 450, 455, 800);
            prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
            MouseOn(mouse);
            flg = 1;
        }

        else if (flg == 0 && MouseIn(550, 415, 650, 455)) //ȡ������
        {
            MouseOff(&mouse);
            Bar2(550, 415, 650, 455, 800);
            prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ��
            MouseOn(mouse);
            flg = 1;
        }

        else if (flg == 1 && !(MouseIn(350, 415, 450, 455)) && !(MouseIn(550, 415, 650, 455)))
        {
            MouseOff(&mouse);
            Bar1(350, 415, 450, 455, 0x8ff2);
            prt_hz24d(376, 423, "ȷ��", 0, "HZK\\Hzk24h"); //ȷ�ϼ�
            Bar1(550, 415, 650, 455, 0x8ff2);
            prt_hz24d(576, 423, "ȡ��", 0, "HZK\\Hzk24h"); //ȡ����
            MouseOn(mouse);
            
            flg = 0;
        }

        else if (MousePress(550, 415, 650, 455)) //���ȡ����
        {
            return;
        }

        else if (MousePress(350, 415, 450, 455)) //���ȷ����
        {
            modify_database(d, area);//���ṹ�������д���ļ�
            return;
        }

        if (MousePress(426, 260, 557, 290)) //��������
        {
            Bar1(426, 260, 557, 290, 0xffff);
            MouseOff(&mouse);
            Getinfo(430, 260, modify_number, 5); //�õ�����
            if (datKey == 1)
                strcpy(d->infestor, modify_number);
            if (datKey == 2)
                strcpy(d->heal, modify_number);
            if (datKey == 3)
                strcpy(d->death, modify_number);
            MouseOn(mouse);
        }
    }
}

/*********************************
Function: click_Data_Block()
Description: �������ѡ�������
********************************/
void click_Data_Block(int *datKey)
{                                   //�������ѡ�������
                                    //������ݿ�
    if (MousePress(0, 0, 510, 196)) //���������ȷ�
    {
        Unhighlight();
        Bar2(0, 0, 510, 196, 7327);
        *datKey = 1;
    }

    else if (MousePress(0, 200, 510, 396)) //���������������
    {
        Unhighlight();
        Bar2(0, 200, 510, 396, 7327);
        *datKey = 2;
    }

    else if (MousePress(0, 400, 510, 596)) //���������������
    {
        Unhighlight();
        Bar2(0, 400, 510, 596, 7327);
        *datKey = 3;
    }
}

/*********************************
Function: Unhighlight()
Description: ȡ�����ݿ����
********************************/
void Unhighlight(void)
{ //ȡ�����ݿ����

    Bar2(0, 0, 510, 196, 0xa794);
    Bar2(0, 200, 510, 396, 0xa794);
    Bar2(0, 400, 510, 596, 0xa794);
    Bar2(514, 2, 1024, 196, 0xa794);
    Bar2(514, 200, 1024, 396, 0xa794);
    Bar2(514, 400, 1024, 596, 0xa794);
}

/*********************************
Function: mouse_feedback_main()
Description: ��귴��
********************************/
void mouse_feedback_main(void)
{ //��귴��
    int flg = 0;

    if (flg == 0 && MouseIn(926, 668, 1024, 768)) //�˳�����
    {
        MouseOff(&mouse);
        Bar1(926, 668, 1024, 768, 14137);
        prt_hz24d(951, 706, "�˳�", 0x0000, "HZK\\Hzk24h");
        MouseOn(mouse);
        flg = 1;
    }
    if (flg == 0 && MouseIn(0, 668, 98, 768)) //���ؿ���
    {
        MouseOff(&mouse);
        Bar1(0, 668, 98, 768, 14137);
        prt_hz24d(25, 706, "����", 0x0000, "HZK\\Hzk24h");
        MouseOn(mouse);
        flg = 1;
    }
    if (flg == 0 && MouseIn(412, 668, 612, 768)) //�޸����ݼ�����
    {
        MouseOff(&mouse);
        Bar1(412, 668, 612, 768, 65184);
        prt_hz24d(462, 706, "�޸�����", 0, "HZK\\Hzk24h");
        MouseOn(mouse);
        flg = 1;
    }
    else if (flg == 1 && !(MouseIn(926, 668, 1024, 768)) 
                    && !(MouseIn(0, 668, 98, 768)) 
                    && !(MouseIn(412, 668, 612, 768)))
    {
        MouseOff(&mouse);
        Bar1(926, 668, 1024, 768, 0x37dc);
        Bar1(0, 668, 98, 768, 0x37dc);
        Bar1(412, 668, 612, 768, 65523);
        prt_hz24d(462, 706, "�޸�����", 0, "HZK\\Hzk24h");
        prt_hz24d(951, 706, "�˳�", 0x0000, "HZK\\Hzk24h");
        prt_hz24d(25, 706, "����", 0x0000, "HZK\\Hzk24h");
        MouseOn(mouse);
        flg = 0;
    }
}
