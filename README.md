# student-management-project
## 大一上学期用C语言编写的学生成绩管理系统
### 1、系统名称 
  Student Score Management System
 
### 2、系统实现的功能
  1.	展示菜单并提供功能选择，包含录入、打印、保存、排序、统计、查询、修改、删除学生信息以及退出系统等选项。也可以实现学生成绩信息的插入。
  2.	录入学生信息，可输入学生个数，依次录入学生姓名、学号及语文、数学、英语成绩，会判断学号是否重复。
  3.	打印学生信息，输出学生的姓名、学号、各科成绩及总分。
  4.	修改学生信息，按学号查找并修改相应学生的各项信息。
  5.	查询学生信息，支持按学号或姓名两种方式进行查询并输出详细信息。
  6.	统计学生人数，通过遍历得出学生总数。
  7.	删除学生信息，可按学号或姓名两种方式删除相应学生信息。
  8.	对学生信息进行排序，提供学号、总分、语文成绩、数学成绩、英语成绩这几种排序方式。
  9.	保存学生信息，将学生相关信息按格式写入指定文本文件。
### 3、系统特色
  1.	功能丰富，涵盖学生信息录入、打印、修改、查询、统计、删除、排序、保存等多方面功能。
  2.	交互友好，菜单界面清晰，功能选项明确，操作提示合理。
  3.	整合学生基本信息与学科成绩，便于整体查看与处理。
  4.	实现数据持久化，可将信息保存至本地文本文件。
  5.	支持灵活的查询与排序，能按不同维度、依据操作。
  6.	具备错误处理与防错机制，避免数据录入冲突，应对不合理输入。
  7.	页面不会持续刷新，可以实现暂停。
     
## 系统展示
1. 主界面
系统的主界面如下图1所示。

![image](https://github.com/user-attachments/assets/85ed9b58-5ffc-481d-842d-73c48cbc2ddf)

图1 系统主界面

2.主要功能模块界面

 ![image](https://github.com/user-attachments/assets/13530a0d-ed1d-448a-be50-7b46b3a41011)

图2 录入学生成绩

 ![image](https://github.com/user-attachments/assets/319ef54c-64a7-4443-a71e-e3dbf11c713f)

图3 打印学生信息
 
 ![image](https://github.com/user-attachments/assets/ab8742f7-fa11-47e3-b978-b0cffb6fdd07)
![image](https://github.com/user-attachments/assets/c9620e75-972d-4c58-90f3-e0e793a9b64a)

图4-5 保存学生信息
 
![image](https://github.com/user-attachments/assets/aeff6f5d-a751-49d4-a183-4092ef73db39)
 ![image](https://github.com/user-attachments/assets/800dcbb1-3f3e-4c08-b6b5-f83ca411f8b8)
![image](https://github.com/user-attachments/assets/dc0cb665-e3b3-4b6e-8498-d092190e72f8)
![image](https://github.com/user-attachments/assets/946d7cd3-d294-4890-9f15-d6cc7440d021)
![image](https://github.com/user-attachments/assets/29052a74-b9f8-473d-b064-e89627be64df)

图6-10 排序并打印

 ![image](https://github.com/user-attachments/assets/1ce39229-8fec-427e-af8b-87533e6495c0)

图11 统计学生人数

 ![image](https://github.com/user-attachments/assets/8a292d19-fd9f-4d2f-94e1-55385548e131)
![image](https://github.com/user-attachments/assets/df192d2b-d2b1-46fa-bf4d-353ec880a4f3)
 
图11-12 查询学生信息

 ![image](https://github.com/user-attachments/assets/141447b4-2c94-4a61-86a9-4f387e4d0965)

图13 修改学生成绩

 ![image](https://github.com/user-attachments/assets/d0e67a0f-4b02-4d6f-aff4-0fba9fc30a9e)
 ![image](https://github.com/user-attachments/assets/52f3b8d9-939e-4be1-81e9-bc163510e0a6)

图14-15 删除学生成绩

 ![image](https://github.com/user-attachments/assets/aa3108f8-0306-4888-9aa6-292b0d71b4fb)

图16 退出系统

3.实现的特色界面

  1.可以提供多种方式进行选择/排序（以排序为例）
 
 ![image](https://github.com/user-attachments/assets/9d8029f7-a6ce-42d2-9df1-fd84e3740a18)

  图17 排序并打印
 
  2. 具备错误处理与防错机制，避免数据录入冲突，应对不合理输入。（以主页面和录入学生信息为例）
  
 ![image](https://github.com/user-attachments/assets/b09d672f-283e-488a-abc5-7228baefc2fa)
![image](https://github.com/user-attachments/assets/3a22c8c1-e26f-4389-9b80-68d69dc6ff4f)

图18-19 防错机制
	
 3.页面暂停，防止持续刷新
 
 ![image](https://github.com/user-attachments/assets/5dac8410-90c5-4ded-ad8a-69372d92a9c3)

图20 页面悬停

### 实验总结
  一、系统开发收获
    - 深入理解链表：熟练掌握其操作，体会到在动态数据管理中的优势，如信息录入、修改等环节的高效运用。相比与数组而言，其学生数据的插入和删除更加简单方便，并且其可以储存更多的信息
    - 锻炼编程逻辑与算法：通过排序、查询、统计等功能开发，熟悉多种算法原理与应用，提升构建复杂逻辑的能力。
    - 积累文件操作经验：学会文件保存流程，为数据持久化处理奠定基础。
    - 培养问题解决能力：在调试各类错误中，掌握排查问题与寻求解决方案的技巧，增强应对编程难题的信心。并且磨练了自己的耐心，让自己可以直面自己的错误从而提升自己。
   二、代码行数统计
    本系统代码约500行。
  三、可添加功能展望
    - 成绩分析功能：计算课程平均分、最高分、最低分及分数段分布，生成统计图表，助力教学策略制定。
  四、个人发展期待
    - 短期：巩固 C 语言，期末考出好的成绩。 
    - 中期：学习 Python 等语言，参与项目或者比赛积累经验，提升竞争力。
    - 长期：成为资深软件工程师或架构师，引领大型项目开发，为行业献力，持续学习追求卓越。

附：源代码通过链表实现录入学生信息
