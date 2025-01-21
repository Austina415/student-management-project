
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


struct Student {
    char name[20];
    int id;
    float grade[4];
};
//����
struct StudentList {
    struct Student student;
    struct StudentList *next;
};
//ͷָ��
struct StudentList head;
//�˵�
int menu() {
    printf("***********************************\n");
    printf("***    ѧ���ɼ�����ϵͳ(C���԰�)    ***\n");
    printf("***          ��ѡ����           ***\n");
    printf("***********************************\n");
    printf("***  1.¼��ѧ����Ϣ 2.��ӡѧ����Ϣ  ***\n");
    printf("***  3.����ѧ����Ϣ 4.�����Ҵ�ӡ  ***\n");
    printf("***  5.ͳ��ѧ������ 6.��ѯѧ����Ϣ  ***\n");
    printf("***  7.�޸�ѧ����Ϣ 8.ɾ��ѧ����Ϣ  ***\n");
    printf("***          0.�˳�ϵͳ          ***\n");
    printf("***********************************\n");
    printf("����ѡ��>");
    int select=-1;
    scanf("%d",&select);
    return select;
}
//¼��
void input() {
    int n;
    printf("��������Ҫ¼���ѧ��������");
    scanf("%d",&n);
    int i;
    for(int i=1;i<=n;i++) {
        struct StudentList *inputStudent;//�µ�ѧ��
        struct StudentList *p;//�м�ָ��
        inputStudent=(struct StudentList*)malloc(sizeof(struct StudentList));//Ϊ��ѧ�����ٿռ�
        printf("�������%dλѧ������Ϣ��",i);
        printf("\n������");
        scanf("%s",inputStudent->student.name);
        printf("ѧ�ţ�");
        scanf("%d",&inputStudent->student.id);
        //�ж��Ƿ��ظ�
        p=head.next;
        while(p!=NULL) {
            if(p->student.id==inputStudent->student.id) {
                printf("ѧ���ظ������������룺");
                scanf("%d",&inputStudent->student.id);
                p=head.next;
            }else {
                p=p->next;
            }
        }
        printf("���ĳɼ���");
        scanf("%f",&inputStudent->student.grade[0]);
        printf("��ѧ�ɼ���");
        scanf("%f",&inputStudent->student.grade[1]);
        printf("Ӣ��ɼ���");
        scanf("%f",&inputStudent->student.grade[2]);
        //��������
        inputStudent->next=head.next;
        head.next=inputStudent;
        printf("¼��ɹ���\n");
    }
    printf("���س�������...");
    getchar();
}
//��ӡ
void output() {
    struct StudentList *p;
    p=head.next;
    printf("����*****ѧ��******����******��ѧ******Ӣ��*****�ܷ�\n");
    while(p!=NULL) {
        printf("%-9s",p->student.name);
        printf("%-9d",p->student.id);
        printf("%-9.1f",p->student.grade[0]);
        printf("%-9.1f",p->student.grade[1]);
        printf("%-9.1f",p->student.grade[2]);
        printf("%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
        p=p->next;
    }
    printf("���س�������...");
    getchar();
}
//�޸�
void amend() {
    printf("������Ҫ���ĵ�ѧ����ѧ�ţ�");
    int id;
    scanf("%d",&id);
    struct StudentList *p;
    p=head.next;
    while(p!=NULL) {
        if(p->student.id==id) {
            printf("������ѧ��������");
            scanf("%s",p->student.name);
            getchar();
            printf("������ѧ��ѧ�ţ�");
            scanf("%d",&p->student.id);
            getchar();
            printf("������ѧ���ɼ���\n");
            printf("���ģ�");
            scanf("%f",&p->student.grade[0]);
            getchar();
            printf("��ѧ��");
            scanf("%f",&p->student.grade[1]);
            getchar();
            printf("Ӣ�");
            scanf("%f",&p->student.grade[2]);
            getchar();
            printf("ѧ���ɼ��޸ĳɹ���\n");
            printf("���س�������...");
            getchar();
            return;
        }else {
            p=p->next;
        }
    }
    printf("δ���ҵ���Ӧѧ�ţ�����\n");
    printf("���س�������...");
    getchar();
}
//����
void search() {
    label1:
    printf("��ѡ���ѯ��ʽ��ѧ�Ų�ѯ��1��/������ѯ��2��->");
    int n;
    struct StudentList *p;
    p=head.next;
    scanf("%d",&n);
    if(n==1) {
        int id;
        printf("������ѧ�ţ�");
        scanf("%d",&id);
        while(p!=NULL) {
            if(id==p->student.id) {
                printf("����*****ѧ��******����******��ѧ******Ӣ��*****�ܷ�\n");
                printf("%-9s",p->student.name);
                printf("%-9d",p->student.id);
                printf("%-9.1f",p->student.grade[0]);
                printf("%-9.1f",p->student.grade[1]);
                printf("%-9.1f",p->student.grade[2]);
                printf("%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
                printf("���س�������...");
                getchar();
                return;
            }else{
                p=p->next;
            }
        }printf("δ��ѯ����Ӧѧ�ţ���\n");
        printf("���س�������...");
        getchar();
    }else if(n==2) {
        char name[30];
        printf("������������");
        scanf("%s",name);
        while(p!=NULL) {
            if(strcmp(name,p->student.name)==0) {
                printf("����*****ѧ��******����******��ѧ******Ӣ��*****�ܷ�\n");
                printf("%-9s",p->student.name);
                printf("%-9d",p->student.id);
                printf("%-9.1f",p->student.grade[0]);
                printf("%-9.1f",p->student.grade[1]);
                printf("%-9.1f",p->student.grade[2]);
                printf("%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
                printf("���س�������...");
                getchar();
                return;
            }else {
                p=p->next;
            }
        }printf("δ��ѯ����Ӧ����������\n");
        printf("���س�������...");
        getchar();
    }else {
        printf("�������󣡣���\n");
        goto label1;
    }
}
//ͳ��
void sumup() {
    int sum=0;
    struct StudentList *p;
    p=head.next;
    while(p!=NULL) {
        sum++;
        p=p->next;
    }
    printf("��%d��ѧ��\n",sum);
    printf("���س�������...");
    getchar();
}
//ɾ��
void Remove() {
    label1:
    printf("��ѡ��ɾ����ʽ��ѧ��ɾ����1��/����ɾ����2��->");
    int n;
    struct StudentList *p;
    p=head.next;
    scanf("%d",&n);
    if(n==1) {
        int id;
        struct StudentList *p1=&head;//�ͺ�
        printf("������ѧ�ţ�");
        scanf("%d",&id);
        while(p!=NULL) {
            if(id==p->student.id) {
                p1->next=p->next;
                printf("ѧ������ɾ���ɹ���\n");
                printf("���س�������...");
                getchar();
                return;
            }else{
                    p=p->next;
                    p1=p1->next;
            }
        }printf("δ��ѯ����Ӧѧ�ţ���\n");
        printf("���س�������...");
        getchar();
    }else if(n==2) {
        char name[30];
        struct StudentList *p1=&head;//�ͺ�
        printf("������������");
        scanf("%s",name);
        while(p!=NULL) {
            if(strcmp(name,p->student.name)==0) {
                p1->next=p->next;
                printf("ѧ������ɾ���ɹ���\n");
                printf("���س�������...");
                getchar();
                return;
            }else {
                p=p->next;
                p1=p1->next;
            }
        }printf("δ��ѯ����Ӧ����������\n");
        printf("���س�������...");
        getchar();
    }else {
        printf("�������󣡣���\n");
        goto label1;
    }
}

int cmp_id(const void *a, const void *b)
{
    struct StudentList *p1 = *(struct StudentList **)a;
    struct StudentList *p2 = *(struct StudentList **)b;
    if(p1->student.id < p2->student.id)
        return -1;
    else if(p1->student.id == p2->student.id)
        return 0;
    else
        return 1;
}

int cmp_score(const void *a, const void *b)
{
    struct StudentList *p1 = *(struct StudentList **)a;
    struct StudentList *p2 = *(struct StudentList **)b;
    if(p1->student.grade[0]+p1->student.grade[1]+p1->student.grade[2] < p2->student.grade[0]+p2->student.grade[1]+p2->student.grade[2])
        return -1;
    else if(p1->student.grade[0]+p1->student.grade[1]+p1->student.grade[2] == p2->student.grade[0]+p2->student.grade[1]+p2->student.grade[2])
        return 0;
    else
        return 1;
}

int cmp_ch(const void *a, const void *b)
{
    struct StudentList *p1 = *(struct StudentList **)a;
    struct StudentList *p2 = *(struct StudentList **)b;
    if(p1->student.grade[0]< p2->student.grade[0])
        return -1;
    else if(p1->student.grade[0]== p2->student.grade[0])
        return 0;
    else
        return 1;
}

int cmp_math(const void *a, const void *b)
{
    struct StudentList *p1 = *(struct StudentList **)a;
    struct StudentList *p2 = *(struct StudentList **)b;
    if(p1->student.grade[1]< p2->student.grade[1])
        return -1;
    else if(p1->student.grade[1]== p2->student.grade[1])
        return 0;
    else
        return 1;
}

int cmp_en(const void *a, const void *b)
{
    struct StudentList *p1 = *(struct StudentList **)a;
    struct StudentList *p2 = *(struct StudentList **)b;
    if(p1->student.grade[2]< p2->student.grade[2])
        return -1;
    else if(p1->student.grade[2]== p2->student.grade[2])
        return 0;
    else
        return 1;
}

//����
void Rank() {
    int num=0;
    struct StudentList *k;
    k=head.next;
    while(k!=NULL) {
        num++;
        k=k->next;
    }

    printf("��ѡ������ʽ"
           "1.ѧ������ 2.�ܷ�����"
           " 3.���ĳɼ�����"
           " 4.��ѧ�ɼ�����"
           " 5.Ӣ��ɼ�����\n");
    printf("����ѡ��->");
    int c;
    scanf("%d",&c);
    getchar();

    struct StudentList **list=(struct StudentList **)malloc(num * sizeof(struct StudentList*));
    struct StudentList *p;
    p=head.next;

    for(int i=0;i<num;i++) {
        list[i]=p;
        p=p->next;
    }

    switch(c) {
        case 1: {
            qsort(list, num, sizeof(struct StudentList *), cmp_id);
            break;
        }
        case 2:
            qsort(list, num, sizeof(struct StudentList *), cmp_score);
            break;
        case 3:
            qsort(list, num, sizeof(struct StudentList *), cmp_ch);
            break;
        case 4:
            qsort(list, num, sizeof(struct StudentList *), cmp_math);
            break;
        case 5:
            qsort(list, num, sizeof(struct StudentList *), cmp_en);
            break;
        default:
            printf("�������󣡣���");
        printf("���س�������...");
        getchar();
    }
    printf("����ɹ���\n");
    printf("����*****ѧ��******����******��ѧ******Ӣ��*****�ܷ�\n");
    for(int i=0;i<num;i++){
        printf("%-9s",list[i]->student.name);
        printf("%-9d",list[i]->student.id);
        printf("%-9.1f",list[i]->student.grade[0]);
        printf("%-9.1f",list[i]->student.grade[1]);
        printf("%-9.1f",list[i]->student.grade[2]);
        printf("%-9.1f\n",list[i]->student.grade[0]+list[i]->student.grade[1]+list[i]->student.grade[2]);
}
    printf("���س�������...");
    }
//����
void Save() {
    struct StudentList *p;
    p=head.next;
    FILE* fp;
    fp = fopen("E:\\code\\save.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp,"����*****ѧ��******����******��ѧ******Ӣ��*****�ܷ�\n");
        while(p!=NULL) {

            fprintf(fp,"%-9s",p->student.name);
            fprintf(fp,"%-9d",p->student.id);
            fprintf(fp,"%-9.1f",p->student.grade[0]);
            fprintf(fp,"%-9.1f",p->student.grade[1]);
            fprintf(fp,"%-9.1f",p->student.grade[2]);
            fprintf(fp,"%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
            p=p->next;
        }
        fprintf(fp,"\n");
        fclose(fp);
        printf("����ɹ���\n");
        printf("���س�������...");
        getchar();
        return ;
    }
}