/*	FileName: report.h
	Author:   ���Ӻ� 
	Date��    2020/9/7
	function��char judge_password(char mima[]) ;�����ʽ
			char judge_IDnumber(char id[]); ���֤�Ÿ�ʽ
			char compare_password(char key1[],char key2[]); ȷ�������Ƿ���ͬ
			char right_id(char account[],char id[]);ȷ�����֤�����Ƿ���ͬ
			char judge_same_name(char account[]); �Ƿ�ע��
			char right_password(char account[],char key[]); ������ȷ
			char judge_userfrozen(char account[]); �ж��û��Ƿ񱻶��� 
			char user_freeze(char account[]) ; �����˻� 
			char user_unfreeze(char account[]);�������ܣ����ʻ��ⶳ
			char complete_register(char account,char key1,char key2,char id); ���ע������
			char complete_login(char account,char key); ��ɵ�¼����
			char complete_admin(char key);��ɹ���Ա��¼����
			void wr_user_inf(char account[],char key[],char id[]);��ע����Ϣд���ļ�
			void wr_user(char account[]);�����ε�¼���˺�д���ļ�
			char admin_password(char key[]);�жϹ���Ա��¼ʱ�����Ƿ����*/
			
/*�������ܣ��ж������Ƿ�Ϻ�Ҫ��
  ����ֵ��0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ�Ϻ�Ҫ��*/
#ifndef _LGSTATE_H_
#define _LGSTATE_H_

/*�������ܣ��ж������Ƿ�Ϻ�Ҫ��
  ����ֵ��0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ�Ϻ�Ҫ��*/
char judge_password(char mima[]);

/*�������ܣ��ж����֤���Ƿ�Ϻ�Ҫ��
  ����ֵ��0��ʾ���Ȳ��Ϻ�Ҫ��1��ʾ���ݲ��Ϻ�Ҫ��2��ʾ�Ϻ�Ҫ��*/
char judge_IDnumber(char id[]);

 /*�������ܣ��ж���������������Ƿ���ͬ
   ����ֵ��0��ʾ����ͬ��1��ʾ��ͬ*/
char compare_password(char key1[],char key2[]);

/*�������ܣ��ж�ע����˺��Ƿ��������˺�����
  ����ֵ��0��ʾ������1��ʾ������
  �������ܣ��жϵ�¼�˺��Ƿ��Ѿ�ע��
  ����ֵ��0��ʾ��ע�ᣬ1��ʾ��δע��*/
char judge_same_name(char account[]);

/*�������ܣ��ж��˺����֤���Ƿ�ƥ��
  ����ֵ��0��ʾ����ȷ��1��ʾ��ȷ*/  
char right_id(char account[],char id[]);

/*�������ܣ��ж��˺������Ƿ�ƥ��
  ����ֵ��0��ʾδ����1��ʾ��ȷ*/
char right_password(char account[],char key[]);

/*�������ܣ��ж��û��Ƿ񱻶��� 
  ����ֵ��0��ʾδ�����ᣬ1��ʾ������*/
char judge_userfrozen(char account[]);

/* �������ܣ������˻�*/
int user_freeze(char account[]);
	
/*�������ܣ����ʻ��ⶳ*/
char user_unfreeze(char account[]);

/*�������ܣ��ж��Ƿ��������� �������˻�ע�ᣩ
  ����ֵ��1��ʾȫ�����룬2��ʾ�˺�δ���룬3��ʾ����δ���룬4��ʾδȷ�����룬5��ʾ���֤��δ����*/
char complete_register(char account,char key1,char key2,char id);

/*�������ܣ��ж��Ƿ��������� �������˻���¼��
  ����ֵ��1��ʾȫ�����룬2��ʾ�˺�δ���룬3��ʾ����δ����*/
char complete_login(char account,char key);

/*�������ܣ��ж��Ƿ��������� �����ڹ���Ա��¼��
  ����ֵ��1��ʾȫ�����룬2��ʾ����δ����*/
char complete_admin(char key);

/*�������ܣ���ע����Ϣд���ļ�*/
void wr_user_inf(char account[],char key[],char id[]);

/*�������ܣ���������д���ļ�*/ 
void user_change_password(char account[],char key[]);

/*�������ܣ������ε�¼���˺�д���ļ�*/
void wr_user(char account[]);

/*�������ܣ������ε�¼���˺Ŷ���*/
void re_user(char account[]);

/*�������ܣ��жϹ���Ա��¼ʱ�����Ƿ����
  ����ֵ��0��ʾ����ȷ��1��ʾ��ȷ*/
char admin_password(char key[]);

/*�������ܣ��ж�id�Ƿ����
  ����ֵ��0��ʾ���ڣ�1��ʾ������*/
char judge_same_id(char idnumber[],char account[]);


#endif


