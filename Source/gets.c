/**********************************************
���ļ���Ҫ������Ϣ���� 
Function list :    show_gb  ����� 
                   Getinfo  ��Ϣ���� 
                   Getcode  �������� 
***********************************************/
#include"GETS.h"
#include"common.h"

/***����꺯��***/
void show_gb(int x,int y)
{
	Line1(x,y,x,y+16,0);
}

/***��Ϣ����ʱ��������ͬ����***/
void Getinfo(int x1,int y1,char *name,int num)
{
	char showtemp[2]= {0,0};
	int key;    			//����ֵ
	int i=0,k,temp;
	int border=x1+4;	    //border��ʾ��ʾͼƬ����߽�
		x1=x1+4;
	y1=y1+5;
	for(i=strlen(name)-1;i>=0;i--)
	{
		*showtemp=name[i];
		prt_asc16_ch(x1+i*8,y1-2,showtemp[0],0);
	}
	i=strlen(name);
	while(bioskey(1))					//������뻺����
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//�����»س���ʱ��ʾ������ϣ��س���ֵΪ13��
    {
	    show_gb(border,y1);//�����˸ 
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
		if(bioskey(1))
		{
			temp=bioskey(0)&0x00ff;
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				if(('0'<=temp&&temp<='9'||('a'<=temp&&temp<='z')||temp=='_')&&i<num)	//���Ϊ���ֻ���ĸ���»��ߣ����¼
				{
					Bar1(border,y1,border+8, y1+16, 0xffff);
					name[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;
					prt_asc16(border,y1-2,showtemp,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;
					name[i]='\0';		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//�����ļ��������ִ�Сд����������ļ�����Ҫ���û������ļ��� 
				{							//����ע��ʱ�Ͳ����ִ�Сд�� 
					Bar1(border,y1,border+8, y1+16, 0xffff);
					temp+=32;
					name[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;       //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					prt_asc16(border,y1-2,showtemp,0);
					i++;
					name[i]='\0';		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					border-=8;
					Bar1(border,y1,border+8, y1+16, 0xffff);
					i--;
					name[i]='\0';
					Bar1(border,y1,border+8, y1+16, 0xffff);
					show_gb(border,y1);
				}
			}
			else
			{
				break;
			}
		}
		if(!MouseIn(378,296,724,322)&&MouseGet(&mouse))		//���������������Ĳ��֣��˳�
		{
			break;
		}
		Bar1(border,y1,border+8, y1+16, 0xffff);
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
	}
	Bar1(border,y1,border+8, y1+16, 0xffff);
}




/***��������ʱ��������ͬ����***/
void Getcode(int x1,int y1,char *code,int num)
{
	char showtemp[2]= {0,0};
	int key;    			//����ֵ
	int i=0,k,temp;
	int border=x1+4;	    //border��ʾ��ʾͼƬ����߽�
		x1=x1+4;
	y1=y1+5;
	for(i=strlen(code)-1;i>=0;i--)
	{
		*showtemp=code[i];
		prt_asc16_ch(x1+i*8,y1-2,'*',0);
	}
	i=strlen(code);
	while(bioskey(1))					//������뻺����
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//�����»س���ʱ��ʾ������ϣ��س���ֵΪ13��
   {
	   show_gb(border,y1);
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
		if(bioskey(1))
		{
			temp=bioskey(0)&0x00ff;
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				//if('0'<=temp&&temp<='9'||'a'<=temp&&temp<='z'||'A'<=temp&&temp<='Z')	//���Ϊ���ֻ���ĸ�����¼
				if(('0'<=temp&&temp<='9'||'a'<=temp&&temp<='z'||temp=='_')&&i<num)	//���Ϊ���ֻ���ĸ���»��ߣ����¼
				{
					Bar1(border,y1,border+8, y1+16, 0xffff);
					code[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;
					prt_asc16(border,y1-2,showtemp,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					delay(150);
					Bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"_",0);
					delay(50);
					Bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"*",0);
					i++;
					code[i]=0;		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//�����ļ��������ִ�Сд����������ļ�����Ҫ���û������ļ��� 
				{							//����ע��ʱ�Ͳ����ִ�Сд�� 
					Bar1(border,y1,border+8, y1+16, 0xffff);
					temp+=32;
					code[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;       //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					prt_asc16(border,y1-2,showtemp,0);
					delay(300);
					Bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"_",0);
					delay(100);
					Bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"*",0);
					i++;
					code[i]=0;		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					border-=8;
					Bar1(border,y1,border+8, y1+16, 0xffff);
					i--;
					code[i]=0;
					Bar1(border,y1,border+8, y1+16, 0xffff);
					show_gb(border,y1);
				}
			}
			else
			{
				break;
			}
		}
		if(!MouseIn(378,296,724,322)&&MouseGet(&mouse))		//���������������Ĳ��֣��˳�
		{
			break;
		}
		Bar1(border,y1,border+8, y1+16, 0xffff);
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
	}
	Bar1(border,y1,border+8, y1+16, 0xffff);
}


