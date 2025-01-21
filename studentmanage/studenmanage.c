
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


struct Student {
    char name[20];
    int id;
    float grade[4];
};
//链表
struct StudentList {
    struct Student student;
    struct StudentList *next;
};
//头指针
struct StudentList head;
//菜单
int menu() {
    printf("***********************************\n");
    printf("***    学生成绩管理系统(C语言版)    ***\n");
    printf("***          请选择功能           ***\n");
    printf("***********************************\n");
    printf("***  1.录入学生信息 2.打印学生信息  ***\n");
    printf("***  3.保存学生信息 4.排序并且打印  ***\n");
    printf("***  5.统计学生人数 6.查询学生信息  ***\n");
    printf("***  7.修改学生信息 8.删除学生信息  ***\n");
    printf("***          0.退出系统          ***\n");
    printf("***********************************\n");
    printf("您的选择—>");
    int select=-1;
    scanf("%d",&select);
    return select;
}
//录入
void input() {
    int n;
    printf("请输入您要录入的学生个数：");
    scanf("%d",&n);
    int i;
    for(int i=1;i<=n;i++) {
        struct StudentList *inputStudent;//新的学生
        struct StudentList *p;//中间指针
        inputStudent=(struct StudentList*)malloc(sizeof(struct StudentList));//为新学生开辟空间
        printf("请输入第%d位学生的信息：",i);
        printf("\n姓名：");
        scanf("%s",inputStudent->student.name);
        printf("学号：");
        scanf("%d",&inputStudent->student.id);
        //判断是否重复
        p=head.next;
        while(p!=NULL) {
            if(p->student.id==inputStudent->student.id) {
                printf("学号重复，请重新输入：");
                scanf("%d",&inputStudent->student.id);
                p=head.next;
            }else {
                p=p->next;
            }
        }
        printf("语文成绩：");
        scanf("%f",&inputStudent->student.grade[0]);
        printf("数学成绩：");
        scanf("%f",&inputStudent->student.grade[1]);
        printf("英语成绩：");
        scanf("%f",&inputStudent->student.grade[2]);
        //链接链表
        inputStudent->next=head.next;
        head.next=inputStudent;
        printf("录入成功！\n");
    }
    printf("按回车键继续...");
    getchar();
}
//打印
void output() {
    struct StudentList *p;
    p=head.next;
    printf("姓名*****学号******语文******数学******英语*****总分\n");
    while(p!=NULL) {
        printf("%-9s",p->student.name);
        printf("%-9d",p->student.id);
        printf("%-9.1f",p->student.grade[0]);
        printf("%-9.1f",p->student.grade[1]);
        printf("%-9.1f",p->student.grade[2]);
        printf("%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
        p=p->next;
    }
    printf("按回车键继续...");
    getchar();
}
//修改
void amend() {
    printf("请输入要更改的学生的学号：");
    int id;
    scanf("%d",&id);
    struct StudentList *p;
    p=head.next;
    while(p!=NULL) {
        if(p->student.id==id) {
            printf("请输入学生姓名：");
            scanf("%s",p->student.name);
            getchar();
            printf("请输入学生学号：");
            scanf("%d",&p->student.id);
            getchar();
            printf("请输入学生成绩：\n");
            printf("语文：");
            scanf("%f",&p->student.grade[0]);
            getchar();
            printf("数学：");
            scanf("%f",&p->student.grade[1]);
            getchar();
            printf("英语：");
            scanf("%f",&p->student.grade[2]);
            getchar();
            printf("学生成绩修改成功！\n");
            printf("按回车键继续...");
            getchar();
            return;
        }else {
            p=p->next;
        }
    }
    printf("未查找到相应学号！！！\n");
    printf("按回车键继续...");
    getchar();
}
//查找
void search() {
    label1:
    printf("请选择查询方式：学号查询（1）/姓名查询（2）->");
    int n;
    struct StudentList *p;
    p=head.next;
    scanf("%d",&n);
    if(n==1) {
        int id;
        printf("请输入学号：");
        scanf("%d",&id);
        while(p!=NULL) {
            if(id==p->student.id) {
                printf("姓名*****学号******语文******数学******英语*****总分\n");
                printf("%-9s",p->student.name);
                printf("%-9d",p->student.id);
                printf("%-9.1f",p->student.grade[0]);
                printf("%-9.1f",p->student.grade[1]);
                printf("%-9.1f",p->student.grade[2]);
                printf("%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
                printf("按回车键继续...");
                getchar();
                return;
            }else{
                p=p->next;
            }
        }printf("未查询到相应学号！！\n");
        printf("按回车键继续...");
        getchar();
    }else if(n==2) {
        char name[30];
        printf("请输入姓名：");
        scanf("%s",name);
        while(p!=NULL) {
            if(strcmp(name,p->student.name)==0) {
                printf("姓名*****学号******语文******数学******英语*****总分\n");
                printf("%-9s",p->student.name);
                printf("%-9d",p->student.id);
                printf("%-9.1f",p->student.grade[0]);
                printf("%-9.1f",p->student.grade[1]);
                printf("%-9.1f",p->student.grade[2]);
                printf("%-9.1f\n",p->student.grade[0]+p->student.grade[1]+p->student.grade[2]);
                printf("按回车键继续...");
                getchar();
                return;
            }else {
                p=p->next;
            }
        }printf("未查询到相应姓名！！！\n");
        printf("按回车键继续...");
        getchar();
    }else {
        printf("输入有误！！！\n");
        goto label1;
    }
}
//统计
void sumup() {
    int sum=0;
    struct StudentList *p;
    p=head.next;
    while(p!=NULL) {
        sum++;
        p=p->next;
    }
    printf("共%d名学生\n",sum);
    printf("按回车键继续...");
    getchar();
}
//删除
void Remove() {
    label1:
    printf("请选择删除方式：学号删除（1）/姓名删除（2）->");
    int n;
    struct StudentList *p;
    p=head.next;
    scanf("%d",&n);
    if(n==1) {
        int id;
        struct StudentList *p1=&head;//滞后
        printf("请输入学号：");
        scanf("%d",&id);
        while(p!=NULL) {
            if(id==p->student.id) {
                p1->next=p->next;
                printf("学生数据删除成功！\n");
                printf("按回车键继续...");
                getchar();
                return;
            }else{
                    p=p->next;
                    p1=p1->next;
            }
        }printf("未查询到相应学号！！\n");
        printf("按回车键继续...");
        getchar();
    }else if(n==2) {
        char name[30];
        struct StudentList *p1=&head;//滞后
        printf("请输入姓名：");
        scanf("%s",name);
        while(p!=NULL) {
            if(strcmp(name,p->student.name)==0) {
                p1->next=p->next;
                printf("学生数据删除成功！\n");
                printf("按回车键继续...");
                getchar();
                return;
            }else {
                p=p->next;
                p1=p1->next;
            }
        }printf("未查询到相应姓名！！！\n");
        printf("按回车键继续...");
        getchar();
    }else {
        printf("输入有误！！！\n");
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

//排序
void Rank() {
    int num=0;
    struct StudentList *k;
    k=head.next;
    while(k!=NULL) {
        num++;
        k=k->next;
    }

    printf("请选择排序方式"
           "1.学号排序 2.总分排序"
           " 3.语文成绩排序"
           " 4.数学成绩排序"
           " 5.英语成绩排序\n");
    printf("您的选择->");
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
            printf("输入有误！！！");
        printf("按回车键继续...");
        getchar();
    }
    printf("排序成功！\n");
    printf("姓名*****学号******语文******数学******英语*****总分\n");
    for(int i=0;i<num;i++){
        printf("%-9s",list[i]->student.name);
        printf("%-9d",list[i]->student.id);
        printf("%-9.1f",list[i]->student.grade[0]);
        printf("%-9.1f",list[i]->student.grade[1]);
        printf("%-9.1f",list[i]->student.grade[2]);
        printf("%-9.1f\n",list[i]->student.grade[0]+list[i]->student.grade[1]+list[i]->student.grade[2]);
}
    printf("按回车键继续...");
    }
//保存
void Save() {
    struct StudentList *p;
    p=head.next;
    FILE* fp;
    fp = fopen("E:\\code\\save.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp,"姓名*****学号******语文******数学******英语*****总分\n");
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
        printf("保存成功！\n");
        printf("按回车键继续...");
        getchar();
        return ;
    }
}