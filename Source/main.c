/***********************

����������
 
**********************/
#include "common.h"
#include "main.h"
void main(void)
{

    int page = 12; //ҳ���л�����

    SetSVGA64k();
    Mouse_Init();

    while (1)
    {
        switch (page)
        {
        case 0: //��ӭҳ��
            page = welcome();
            break;
        case 1: //��¼ҳ��
            page = login_user();
            break;

        case 2: //����Ա��¼ҳ��
            page = login_admin();
            break;
        case 3: //ע��ҳ��
            page = register_user();
            break;

        case 4: //��������ҳ��
            page = refound_user();
            break;

        case 5: //���ӻ�����
            page = visual_page();
            break;

        case 6: //ͨ������
            page = report();
            break;

        case 7: //���ݲ�ѯ����
            page = inquiry();
            break;

        case 8: //����Ա����
            page = admin_menu();
            break;

        case 9: //�����û�����
            page = aduser();
            break;

        case 10: //�������ҳ��
            page = admin_review();
            break;

        case 11: //�����޸�ҳ��
            page = admin_modify();
            break;

        case 12: //����չʾҳ�棨��״ͼ��
            page = showinfo_main();
            break;

        case -1:         //�˳�����
            CloseSVGA(); //�ر�ͼ�ν���
            exit(0);
        }
    }
}
