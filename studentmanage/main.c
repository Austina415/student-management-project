#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(void)
{
    while(1) {
        switch(menu()) {
            //退出菜单
            case  0:
                return 0;
            //录入学生信息
            case  1:
                input();
                break;
            //打印学生信息
            case  2:
                output();
                break;
            //保存学生信息
            case  3:
                Save();
                break;
            case  4:
                Rank();
                break;
            //统计学生个数
            case  5:
                sumup();
                break;
            //查找学生成绩
            case  6:
                search();
                break;
            //修改学生成绩
            case  7:
                amend();
                break;
            //删除
            case  8:
                Remove();
                break;
            default:
                printf("\n对不起!您的输入有误,没有该功能!\n");
        }
        //接收换行
        getchar();
        // //程序暂停
        // system("pause");
        // //清屏
        // system("cls");
    }

    return 0;
}
