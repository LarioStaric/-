#ifndef _DATA_H_
#define _DATA_H_

typedef struct UseInfo
{
	char UserName[12+1];//�û���
	char password[12+1];//����
	char IDnumber[18+1];//���֤��
	char UserState;  //�û��Ƿ񱻶���  0��δ�����ᣬ1�������� 
	char n[2];//�洢'\n\r' ʹ�����ݴ洢ʱ���� 

}USER;

typedef struct DayInfo//���ڴ����û�ͨ�����ݣ��ȴ�����Ա��� 
{	
	char area[5+1];//ͨ������ 
	char year[4+1];//�� 
	char month[2+1];//�� 
	char day[2+1];//�� 
	char infestor[6];//����������Ⱦ 
	char death[6];//������������ 
	char heal[6];//�������� 
	char username[13];//�ϱ��� 
	char infostate;//����״̬ 0 Ϊδ��ˣ�1Ϊ���ͨ����2Ϊ��˲�ͨ�� 
	char n[2];//�洢'\n\r' ʹ�����ݴ洢ʱ���� 
}DAY;

typedef struct Save_Dayinfo//������Ϣ 
{
	char year[4+1];//�� 
	char month[2+1];//�� 
	char day[2+1];//�� 
	char infestor[6];//����������Ⱦ 
	char death[6];//������������ 
	char heal[6];//�������� 
	char allinf[7];//������Ϊֹ �ܸ�Ⱦ�� 
	char alldea[7];//������Ϊֹ �������� 
	char allhea[7];//������Ϊֹ �������� 
	char n[2];//�洢'\n\r' ʹ�����ݴ洢ʱ���� 
}SAVEDAY; 

typedef struct Chartinfo//������Ϣ 
{
	int infestor;//����������Ⱦ 
	int death;//������������ 
	int heal;//�������� 
	int allinf;//������Ϊֹ �ܸ�Ⱦ�� 
	int alldea;//������Ϊֹ �������� 
	int allhea;//������Ϊֹ �������� 

}CHARTDATA; 


#endif


