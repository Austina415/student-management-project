#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(void)
{
    while(1) {
        switch(menu()) {
            //�˳��˵�
            case  0:
                return 0;
            //¼��ѧ����Ϣ
            case  1:
                input();
                break;
            //��ӡѧ����Ϣ
            case  2:
                output();
                break;
            //����ѧ����Ϣ
            case  3:
                Save();
                break;
            case  4:
                Rank();
                break;
            //ͳ��ѧ������
            case  5:
                sumup();
                break;
            //����ѧ���ɼ�
            case  6:
                search();
                break;
            //�޸�ѧ���ɼ�
            case  7:
                amend();
                break;
            //ɾ��
            case  8:
                Remove();
                break;
            default:
                printf("\n�Բ���!������������,û�иù���!\n");
        }
        //���ջ���
        getchar();
        // //������ͣ
        // system("pause");
        // //����
        // system("cls");
    }

    return 0;
}
