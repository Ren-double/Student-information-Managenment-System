#pragma once//防止头文件重复包含
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//标准输入输出流函数
#include<string.h>//字符串的头文件
#include<stdlib.h>
#include<stdbool.h>//包含bool的头文件

//函数的声明
void hpush(int* ge);
void hdelete(int* ge);
static void Secure(char p[], int n);
static void HeadmasterInit();
void Administration();
void oper(int value, int* ge);
void Toper(int val);
void hshow();
void DeleteAll(int* ge);
void hFind();
void hChange();
bool Alter(char* c);
void ChangeSecure(char p[]);
static void Secure2(char p[], int n);
void TeAd();
void Tpush(int val);
void PushGrade(struct Student* m);
void PrintGrade(struct Student* m);
void sortList();
struct Student* merge(struct Student* left, struct Student* right);
struct Student* mergeSort(struct Student* head);

//学校有学生
struct Student
{
    int age_;//学生的年龄
    char gender_[100];//学生的性别
    char name_[100];//学生的名字
    char xuehao_[100];//学生的学号
    char Math[100];
    char Chinese[100];
    char English[100];
    char sum[100];
    struct Student* st;
};

//定义一个链表的头节点
struct Student* head_;
static int geshu = 0;
static void StudentInit()
{

    head_ = (struct Student*)malloc(sizeof(struct Student));
    if (head_ == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    head_->st = NULL;
    head_->age_ = 0;
    strcpy(head_->gender_, "This is nothing!");
    strcpy(head_->name_, "This is nothing!");
    strcpy(head_->xuehao_, "This is nothing!");
    strcpy(head_->Math, "This is nothing!");
    strcpy(head_->Chinese, "This is nothing!");
    strcpy(head_->English, "This is nothing!");
    strcpy(head_->sum, "This is nothing!");
}

//判断是否有储存学生信息的文件
static void File(int* ge)
{
    FILE* f = fopen("Student_information.txt", "r");
    if (f == NULL)
    {
        *ge = 0;
        return;
    }
    int xuhao = 0;
    char ch[10];
    fscanf(f, "%s %s %s %s %s %s %s %s %s", ch, ch, ch, ch, ch, ch, ch, ch, ch);
    while (1)
    {
        struct Student* s1 = (struct Student*)malloc(sizeof(struct Student));//在堆上进行创建学生的实例化
        if (fscanf(f, "%d %s %s %d %s %s %s %s %s", &xuhao, s1->name_, s1->gender_, &s1->age_, s1->xuehao_, s1->Math, s1->Chinese, s1->English, s1->sum) != 9)
        {
            break;
        }
        struct Student* p = head_;
        while (p->st != NULL)
        {
            p = p->st;
        }
        *ge = *ge + 1;
        p->st = s1;
        s1->st = NULL;
    }
    fclose(f);
}

//进行学生链表内存的释放
static void StudentEnd()
{
    struct Student* p = head_;
    while (p != NULL)
    {
        head_ = p->st;
        free(p);
        p = head_;
    }
    p = NULL;
    head_ = NULL;
}

//文件保存学生信息的函数
void Save(struct Student* s,int ge)
{
    FILE* fp = fopen("Student_information.txt", "r");
    if (fp == NULL)
    {
        perror("文件打开失败：");
        fp = fopen("Student_information.txt", "w");
        fprintf(fp, "序号\t\t姓名\t\t性别\t\t年龄\t\t学号\t\t\t数学成绩\t\t语文成绩\t\t英语成绩\t\t总成绩\n");
    }
    fclose(fp);
    fp = fopen("Student_information.txt", "a");
    int len = strlen(s->name_);
    if (len == 4)
    {
        fprintf(fp, "%d\t\t%s\t\t%s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, s->name_, s->gender_, s->age_, s->xuehao_, s->Math, s->Chinese, s->English, s->sum);
    }
    else if (len == 8)
    {
        fprintf(fp, "%d\t\t%s   %s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, s->name_, s->gender_, s->age_, s->xuehao_, s->Math, s->Chinese, s->English, s->sum);
    }
    else
    {
        fprintf(fp, "%d\t\t%s\t%s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, s->name_, s->gender_, s->age_, s->xuehao_, s->Math, s->Chinese, s->English, s->sum);
    }
    fclose(fp);
}

//更改或者删除学生信息时对文件的处理
void Changefile()
{
    FILE* f = fopen("Student_information.txt", "w");
    if (f == NULL)
    {
        perror("file open failed:");
        return;
    }
    fprintf(f, "序号\t\t姓名\t\t性别\t\t年龄\t\t学号\t\t\t数学成绩\t\t语文成绩\t\t英语成绩\t\t总成绩\n");
    struct Student* p = head_;
    int ge = 1;
    while (p->st != NULL)
    {
        p = p->st;
        int len = strlen(p->name_);
        if (len == 4)
        {
            fprintf(f, "%d\t\t%s\t\t%s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        }
        else if (len == 8)
        {
            fprintf(f, "%d\t\t%s   %s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        }
        else
        {
            fprintf(f, "%d\t\t%s\t%s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        }
        ge++;
    }
    fclose(f);
}

//学校有校长
struct Headmaster
{
    char* name;
};

//校长的初始化函数
static void HeadmasterInit()  
{
    printf("请输入你的权限密钥：");
    char secure[100];
    scanf(" %s", secure);
    secure[strlen(secure)] = '\0';
    system("cls");
    int n = strlen(secure);
    Secure(secure, n);
    //运用凯撒加密进行变换
    FILE* ff = fopen("Secure.txt", "r");
    char GET[100];//从文件中读取密码，判断输入是否正确
    fscanf(ff,"%s", GET);
    GET[strlen(GET)] = '\0';
    fclose(ff);
    if (strcmp(secure, GET) == 0)
    {
        printf("您输入的密码正确，恭喜\n");
        Administration();
    }
    else
    {
        printf("密码错误\n系统已经退出\n");
        return;
    }
}

//教师的初始化函数
static void TeacherInit()
{
    printf("请输入你的权限密钥：");
    char secure[100];
    scanf(" %s", secure);
    secure[strlen(secure)] = '\0';
    system("cls");
    int n = strlen(secure);
    Secure(secure, n);
    //运用凯撒加密进行变换
    FILE* fm = fopen("Secure_Teacher.txt", "r");
    char GET[100];//从文件中读取密码，判断输入是否正确
    fscanf(fm, "%s", GET);
    GET[strlen(GET)] = '\0';
    fclose(fm);
    if (strcmp(secure, GET) == 0)
    {
        printf("您输入的密码正确，恭喜\n");
        TeAd();
    }
    else
    {
        printf("密码错误\n系统已经退出\n");
        return;
    }
}

//教师行政功能函数
void TeAd()
{
    while (1)
    {
        printf("\033[1;33;5m");
        printf("\n\
                          _ooOoo_                          \n\
                         o8888888o                         \n\
                         88· . ·88                         \n\
                         (| ^_^ |)                         \n\
                         O\\  =  /O                         \n\
                      ____/`---'\\____                      \n\
                    .'  \\\\|     |//  `.                    \n\
                   /  \\\\|||  :  |||//  \\                   \n\
                  /  _||||| -:- |||||-  \\                  \n\
                  |   | \\\\\\  -  /// |   |                  \n\
                  | \\_|  ''\\---/''  |   |                  \n\
                  \\  .-\\__  `-`  ___/-. /                  \n\
                ___`. .'  /--.--\\  `. . ___                \n\
               ."" '<  `.___\\_<|>_/___.'  >'"".                \n\
            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |            \n\
            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /            \n\
     ========`-.____`-.___\\_____/___.-`____.-'========     \n\
                          '=---='                          \n\
     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     \n\
                  菩提本无树    明镜亦非台                 \n\
                  本来无BUG     何必常修改                 \n\
                                                           \n\n");
        printf("\033[0m");
        printf("\n现在有%d名学生的信息\n学生的学号是唯一的哦\n\n", geshu);
        printf("*****教师权限菜单****\n");
        printf("** 1、录入学生成绩 **\n");
        printf("** 2、更改学生成绩 **\n");
        printf("** 3、查询学生信息 **\n");
        printf("*4、显示所有学生信息*\n");
        printf("** 5、学生成绩排名 **\n");
        printf("6、更改教师的进入密钥\n");
        printf("** 7、退出操作系统 **\n");
        int value;
        printf("\n请输入你所想选择的操作序号；");
        int n = scanf("%d", &value);
        system("cls");
        if (!n)
        {
            printf("你输入的是字符串，你是个大傻子，再见\n\n");
            return;
        }
        if (value == 7)
        {
            system("cls");
            return;
        }
        else if (value == 6)
        {
            ChangeSecure("Secure_Teacher.txt");
            return;
        }
        else
        {
            Toper(value);
        }
    }
}

//教师进行工作的函数
void Toper(int val)
{
    switch (val)
    {
    case 1:
        Tpush(val);
        break;
    case 2:
        Tpush(val);
        break;
    case 3:
        hFind();
        break;
    case 4:
        hshow();
        break;
    case 5:
        sortList();
        break;
    }
}

//教师录入和更改学生成绩的函数
void Tpush(int val)
{
    struct Student* p = head_;
    printf("请输入您要录入学生的学号：");
    char xu[100];
    scanf("%s",xu);
    xu[strlen(xu)] = '\0';
    while (p->st != NULL)
    {
        int m, c, e;
        p = p->st;
        if (strcmp(p->xuehao_, xu)==0)
        {
            if (val == 1)
            {
                printf("请输入该学生的数学成绩：");
                scanf("%s", p->Math);
                p->Math[strlen(p->Math)] = '\0';
                m = atoi(p->Math);
                printf("请输入该学生的语文成绩：");
                scanf("%s", p->Chinese);
                p->Chinese[strlen(p->Chinese)] = '\0';
                c = atoi(p->Chinese);
                printf("请输入该学生的英语成绩：");
                scanf("%s", p->English);
                p->English[strlen(p->English)] = '\0';
                e = atoi(p->English);
                _itoa((m + c + e), p->sum, 10);
            }
            if (val == 2)
            {
                printf("请重新输入该学生的数学成绩：");
                scanf("%s", p->Math);
                p->Math[strlen(p->Math)] = '\0';
                m = atoi(p->Math);
                printf("请重新输入该学生的语文成绩：");
                scanf("%s", p->Chinese);
                p->Chinese[strlen(p->Chinese)] = '\0';
                c = atoi(p->Chinese);
                printf("请重新输入该学生的英语成绩：");
                scanf("%s", p->English);
                p->English[strlen(p->English)] = '\0';
                e = atoi(p->English);
                int sum = (m + c + e);
                _itoa(sum, p->sum, 10);
            }
            Changefile();
            printf("\n录入成功！\n");
            system("pause");
            system("cls");
            return;
        }
    }
    printf("不好意思，没有在系统中找到该学号对应的学生！\n");
    system("pause");
    system("cls");
    return;
}

struct Student* merge(struct Student* left, struct Student* right) 
{
    struct Student* dummy = (struct Student*)malloc(sizeof(struct Student));
    if (dummy == NULL) 
    {
        printf("内存分配失败，合并操作无法进行\n");
        exit(1);
    }
    struct Student* cur = dummy;

    while (left != NULL && right != NULL) 
    {
        if (strcmp(left->sum, right->sum) > 0) 
        {
            cur->st = left;
            left = left->st;
        }
        else {
            cur->st = right;
            right = right->st;
        }
        cur = cur->st;
    }

    if (left != NULL) 
    {
        cur->st = left;
    }
    else 
    {
        cur->st = right;
    }

    struct Student* result = dummy->st;
    free(dummy);
    return result;
}

// 归并排序的递归划分函数，从第二个节点开始处理排序，忽略头节点
struct Student* mergeSort(struct Student* head) {
    if (head == NULL || head->st == NULL) {
        return head;
    }

    struct Student* slow = head;
    struct Student* fast = head->st;
    while (fast != NULL && fast->st != NULL && fast->st->st != NULL) {
        slow = slow->st;
        fast = fast->st->st;
    }

    struct Student* right = slow->st;
    slow->st = NULL;

    struct Student* left = mergeSort(head);
    right = mergeSort(right);

    struct Student* merged = merge(left, right);
    return merged;
}

// 对外暴露的链表排序函数，调用归并排序函数进行排序，忽略头节点(学生成绩存储在Grade_ranking.txt.txt中)
void sortList() 
{
    //对链表进行排序
    if (head_ == NULL || head_->st == NULL) {
        return;
    }
    head_->st = mergeSort(head_->st);
    PrintGrade(head_);
    PushGrade(head_);

    //将链表变成之前的模样
    struct Student* p = head_->st;
    struct Student* p1 = head_->st;
    while (p != NULL)
    {
        p1 = p->st;
        free(p);
        p = p1;
    }
    p = NULL;
    p1 = NULL;
    head_->st = NULL;
    geshu = 0;
    File(&geshu);
}

//打印学生成绩排名的函数
void PrintGrade(struct Student* m)
{
    if (m->st == NULL)
    {
        system("cls");
        printf("该系统没有任何学生！\n");
        system("pause");
        system("cls");
        return;
    }
    int i = 1;
    system("cls");
    printf("排名\t姓名\t\t数学成绩\t语文成绩\t英语成绩\t总成绩\n");
    while (m->st != NULL)
    {
        m = m->st;
        int len = strlen(m->name_);
        if (len == 8)
        {
            printf("%d\t%s %s\t\t%s\t\t%s\t\t%s\n", i, m->name_, m->Math, m->Chinese, m->English, m->sum);
            continue;
        }
        printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", i, m->name_, m->Math, m->Chinese, m->English, m->sum);
        i++;
    }
    system("pause");
    system("cls");
}

//向文件中录入学生成绩排名的函数
void PushGrade(struct Student* m)
{
    FILE* f = fopen("Grade_ranking.txt.txt", "w");
    if (f == NULL)
    {
        perror("file open failed:");
        return;
    }
    fprintf(f, "排名\t\t姓名\t\t性别\t\t年龄\t\t学号\t\t\t数学成绩\t\t语文成绩\t\t英语成绩\t\t总成绩\n");
    struct Student* p = m;
    int ge = 1;
    while (p->st != NULL)
    {
        p = p->st;
        int len = strlen(p->name_);
        if (len == 4)
        {
            fprintf(f, "%d\t\t%s\t\t%s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        }
        else if (len == 8)
        {
            fprintf(f, "%d\t\t%s   %s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        }
        else
        {
            fprintf(f, "%d\t\t%s\t%s\t\t%d\t\t%s\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n", ge, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        }
        ge++;
    }
    fclose(f);
}

//校长的行政功能函数
void Administration()
{
    while(1)
    {
        printf("\033[1;33;5m");
        printf("\n\
                          _ooOoo_                          \n\
                         o8888888o                         \n\
                         88· . ·88                         \n\
                         (| ^_^ |)                         \n\
                         O\\  =  /O                         \n\
                      ____/`---'\\____                      \n\
                    .'  \\\\|     |//  `.                    \n\
                   /  \\\\|||  :  |||//  \\                   \n\
                  /  _||||| -:- |||||-  \\                  \n\
                  |   | \\\\\\  -  /// |   |                  \n\
                  | \\_|  ''\\---/''  |   |                  \n\
                  \\  .-\\__  `-`  ___/-. /                  \n\
                ___`. .'  /--.--\\  `. . ___                \n\
               ."" '<  `.___\\_<|>_/___.'  >'"".                \n\
            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |            \n\
            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /            \n\
     ========`-.____`-.___\\_____/___.-`____.-'========     \n\
                          '=---='                          \n\
     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     \n\
                  菩提本无树    明镜亦非台                 \n\
                  本来无BUG     何必常修改                 \n\
                                                           \n\n");
        printf("\033[0m");
        printf("\n现在有%d名学生的信息\n学生的学号是唯一的哦\n\n", geshu);
        printf("*****校长权限菜单****\n");
        printf("**** 1、录入信息 ****\n");
        printf("**** 2、删除信息 ****\n");
        printf("**** 3、更改信息 ****\n");
        printf("*****4、查询信息 ****\n");
        printf("*5、显示所有学生信息*\n");
        printf("*6、删除所有学生信息*\n");
        printf("7、更改校长的进入密钥\n");
        printf("** 8、退出操作系统 **\n");
        int value;
        printf("\n请输入你所想选择的操作序号；");
        int n = scanf("%d", &value);
        system("cls");
        if (!n)
        {
            printf("你输入的是字符串，你是个大傻子，再见\n\n");
            return;
        }
        if (value == 8)
        {
            system("cls");
            return;
        }
        else if (value == 7)
        {
            ChangeSecure("Secure.txt");
            return;
        }
        else
        {
            oper(value,&geshu);
        }
    }
}

//校长进行工作的函数
void oper(int value,int* ge)
{
    switch (value)
    {
    case 1:
        hpush(ge);
        break;
    case 2:
        hdelete(ge);
        break;
    case 3:
        hChange();
        break;
    case 4:
        hFind();
        break;
    case 5:
        hshow();
        break;
    case 6:
        DeleteAll(ge);
        break;
    }
}

//校长输入信息的函数
void hpush(int* ge)
{
    struct Student* s1 = (struct Student*)malloc(sizeof(struct Student));
    if (s1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("请输入学生的姓名：");
    scanf("%s", s1->name_);
    s1->name_[strlen(s1->name_)] = '\0';
    printf("请输入学生的性别：");
    scanf("%s", s1->gender_);
    s1->gender_[strlen(s1->gender_)] = '\0';
    printf("请输入学生的年龄：");
    scanf("%d", &(s1->age_));
    printf("请输入学生的学号：");
    scanf("%s", s1->xuehao_);
    s1->xuehao_[strlen(s1->xuehao_)] = '\0';
    strcpy(s1->Math, "暂无");
    strcpy(s1->Chinese, "暂无");
    strcpy(s1->English, "暂无");
    strcpy(s1->sum, "暂无");
    system("cls");
    struct Student* p1 = head_->st;
    struct Student* p2 = head_;
    while (p2->st != NULL)//进行链表的遍历，搜索是否有四项都相同的学生
    {
        if (strcmp(p1->xuehao_, s1->xuehao_) == 0)
        {
            printf("系统内已经有该学号，学号错误\n已退出\n");
            system("pause");
            system("cls");
            return;
            if (strcmp(p1->gender_, s1->gender_) == 0)
            {
                if (s1->age_ == p1->age_)
                {
                    if (strcmp(p1->name_, s1->name_) == 0)//可能出现同名现象，所以需要将学号属性遍历
                    {
                        printf("已经有该学生，请勿重新添加！\n");
                        free(s1);
                        system("pause");
                        system("cls");
                        return;
                    }
                }
            }
        }
        p2 = p1;
        p1 = p1->st;
    }
    //将输入的所有信息保存至文件中
    struct Student* p = head_;
    while (p->st != NULL)//进行遍历，将新输入的学生插在链表的末尾
    {
        p = p->st;
    }
    *ge = *ge + 1;
    p->st = s1;
    s1->st = NULL;
    Save(s1, *ge);
}

//校长删除信息的函数
void hdelete(int* ge)
{ 
    system("cls");
    if (*ge==0)
    {
        printf("已经没有学生了\n别再删了\n");
        system("pause");
        system("cls");
        return;
    }
    int age;
    char gender[100];
    char name[100];
    char xuehao[100];
    printf("请输入你所要删除的学生的姓名：");
    scanf("%s", name);
    name[strlen(name)] = '\0';
    printf("请输入你所要删除的学生的性别：");
    scanf("%s", gender);
    gender[strlen(gender)] = '\0';
    printf("请输入你所要删除的学生的年龄：");
    scanf("%d", &age);
    printf("请输入你所要删除的学生的学号：");
    scanf("%s", xuehao);
    xuehao[strlen(xuehao)] = '\0';
    struct Student* p1 = head_->st;
    struct Student* p2 = head_;
    while (p2->st != NULL)//进行链表的遍历，搜索是否有四项都相同的学生
    {
        if (strcmp(p1->name_, name)==0)
        {
            if (strcmp(p1->gender_, gender)==0)
            {
                if (age == p1->age_)
                {
                    if (strcmp(p1->xuehao_, xuehao)==0)
                    {
                        p2->st = p1->st;
                        free(p1);
                        *ge = *ge - 1;
                        printf("删除成功！\n");
                        Changefile();
                        system("pause");
                        system("cls");
                        return;
                    }
                }
            }
        }
        p2 = p1;
        p1 = p1->st;
    }
    printf("未找到该学生的信息！\n请检查输入是否正确\n");
    system("pause");
    system("cls");
}

//校长显示学生所有信息的函数
void hshow()
{
    struct Student* p = head_;
    if (p->st == NULL)
    {
        system("cls");
        printf("该系统没有任何学生！\n");
        system("pause");
        system("cls");
        return;
    }
    int i = 1;
    system("cls");
    printf("序号\t姓名\t性别\t年龄\t学号\t\t数学成绩\t语文成绩\t英语成绩\t总成绩\n");
    while (p->st != NULL)
    {
        p = p->st;
        int len = strlen(p->name_);
        if (len == 8)
        {
            printf("%d号\t%s %s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", i, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
            continue;
        }
        printf("%d号\t%s\t%s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", i, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        i++;
    }
    system("pause");
    system("cls");
}

//校长删除所有学生信息的函数
void DeleteAll(int *ge)
{
    if (*ge == 0)
    {
        printf("你删个鸡毛，系统里没有学生！\n");
        system("pause");
        system("cls");
        return;
    }
    char ch;
    system("cls");
    printf("请确认是否要删除所有学生信息吗？\n确认请输入#，否则输入@\n");
    scanf(" %c", &ch);
    if (ch == '#')
    {
        struct Student* p = head_->st;
        struct Student* p1 = head_->st;
        while (p != NULL)
        {
            p1 = p->st;
            free(p);
            p = p1;
        }
        p = NULL;
        p1 = NULL;
        head_->st = NULL;
        remove("Student_information.txt");
        printf("删除成功！\n");
        system("pause");
        system("cls");
    }
    else if (ch == '@')
    {
        printf("原来你是操作失误啊！\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("输入错误！\n你是假冒的吧！\n");
        system("pause");
        system("cls");
        return;
    }
    *ge = 0;
}

//校长查询学生信息的函数
void hFind()
{
    struct Student* f = head_;
    if (f->st == NULL)
    {
        printf("傻不拉几的，系统内又没有学生，你找什么找！！！\n");
        system("pause");
        system("cls");
        return;
    }
    char xuehao[100];
    printf("请输入你所要查询的学生的学号：");
    scanf("%s", xuehao);
    xuehao[strlen(xuehao)] = '\0';
    while (f->st != NULL)
    {
        f = f->st;
        if (strcmp(f->xuehao_, xuehao) == 0)
        {
            printf("姓名\t性别\t年龄\t学号\t\t数学成绩\t语文成绩\t英语成绩\t总成绩\n");
            printf("%s\t%s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", f->name_, f->gender_, f->age_, f->xuehao_, f->Math, f->Chinese, f->English, f->sum);
            system("pause");
            system("cls");
            return;
        }
    }
    printf("未找到该学生，请检查您输入的信息是否正确\n");
    system("pause");
    system("cls");
}

//校长更改学生信息的函数
void hChange()
{
    struct Student* p = head_;
    if (p->st == NULL)
    {
        printf("该系统没有学生，无法更改！\n");
        system("pause");
        system("cls");
        return;
    }
    char ch[100];
    printf("请输入你所要更改的内容：\n1、姓名\n2、性别\n3、年龄\n4、学号\n");
    scanf("%s", ch);
    if (Alter(ch))
    {
        printf("以下为该系统所有学生的信息\n");
        hshow();
        char xuehao[100];
        printf("请输入你将要修改的学生的学号：");
        scanf("%s", xuehao);
        xuehao[strlen(xuehao)] = '\0';
        while (p->st != NULL)
        {
            p = p->st;
            if (strcmp(xuehao, p->xuehao_)==0)
            {
                if (strcmp("年龄", ch)==0)
                {
                    printf("请问您要将%s：%d更改为：", ch, p->age_);
                    scanf("%d", &p->age_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
                else if (strcmp("姓名", ch) == 0)
                {
                    printf("请问您要将%s：%s更改为：", ch, p->name_);
                    scanf("%s", p->name_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
                else if (strcmp("性别", ch) == 0)
                {
                    printf("请问您要将%s：%s更改为：", ch, p->gender_);
                    scanf("%s", p->gender_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
                else if (strcmp("学号", ch) == 0)
                {
                    printf("请问您要将%s：%s更改为：", ch, p->xuehao_);
                    scanf("%s", p->xuehao_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
            }
        }
    }
    else
    {
        printf("\n傻不拉几的，这都输入不对，白白了您嘞！\n");
        system("pause");
        system("cls");
        return;
    }
    printf("没有找到该同学呢亲\n");
    system("pause");
    system("cls");
}
bool Alter(char* c)
{
    if (strcmp(c, "姓名") == 0 || strcmp(c, "性别") == 0 || strcmp(c, "学号") == 0 || strcmp(c, "年龄") == 0)
    {
        return true;
    }
    else
        return false;
}

//校长和教师进行密码更改的函数
void ChangeSecure(char p[])
{
    FILE* fp = fopen(p, "w");
    if (fp == NULL)
    {
        perror("file open failed：");
        return;
    }
    printf("请输入新的密码：");
    char ch[100];
    scanf("%s", ch);
    ch[strlen(ch)] = '\0';
    fprintf(fp, "%s\n", ch);
    Secure2(ch, strlen(ch));
    fprintf(fp, "%s\n", ch);
    printf("经过加密:\n下次输入：%s即可\n建议各位将密码保存在一个相对安全的地方\n", ch);
    fclose(fp);
    system("pause");
    system("cls");
}

//运用凯撒密码进行简单的解密
static void Secure(char p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] - 1;
    }
}

//运用凯撒密码进行简单加密
static void Secure2(char p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] + 1;
    }
}