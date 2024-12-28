#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"school.h"
#define _CRT_SECURE_NO_WARNINGS

void StudentMemu();
void Opertor(int val, char ch[]);
void FindInformation(char ch[]);
void bool_ChangeInformation(char hao[]);
void Change_Information(char xuehao[]);

//学生进入系统前输入学号的函数
static void Student_Oper()
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
    printf("请输入您的学号：");
    scanf("%s", xuehao);
    xuehao[strlen(xuehao)] = '\0';
    while (f->st != NULL)
    {
        f = f->st;
        if (strcmp(f->xuehao_, xuehao) == 0)
        {
            while (1)
            {
                StudentMemu();
                int value;
                printf("\n请输入你所想选择的操作序号：");
                int n = scanf("%d", &value);
                system("cls");
                if (!n)
                {
                    printf("你输入的是字符串，你是个大傻子，再见\n\n");
                    return;
                }
                if (value == 3)
                {
                    system("cls");
                    return;
                }
                else if (value == 1 || value == 2)
                {
                    Opertor(value, xuehao);
                }
                else
                {
                    printf("真服了，序号都输不对\n");
                    system("pause");
                    system("cls");
                }
            }
        }
    }
    printf("抱歉，该系统没有您的信息!\n");
    system("pause");
    system("cls");
    return;
}

//学生功能展示的函数
void StudentMemu()
{
    system("cls");
    // 开启闪烁及指定颜色，用于输出主体的有趣图案部分，这里颜色代码96表示一种偏亮的青色，数字5表示闪烁效果（不一定所有终端都支持闪烁呈现哦）
    printf("\033[1;33;5m");
    printf("                            _ooOoo_\n");
    printf("                           o8888888o\n");
    printf("                           88\".  \"88\n");
    printf("                           (| -_- |)\n");
    printf("                            O\\ = /O\n");
    printf("                        ____/`---'\\____\n");
    printf("                    .   ' \\\\| |// `. \n");
    printf("                       / \\\\||| : |||// \\\n");
    printf("                     / _||||| -:- |||||- \\\n");
    printf("                       | | \\\\ - /// | |\n");
    printf("                     | \\_| ''\\---/'' | |\n");
    printf("                      \\\\.-\\__ `-` ___/-. /\n");
    printf("                   ___`..' /--.--\\ `.. __\n");
    printf("              .\"\" '< `.___\\_<|>_/___.' >'\"\".\n");
    printf("               | | : `- \\\\`.;`\\ _ /`;.`/ - ` : | |\n");
    printf("                 \\\\ \\\\ `-. \\_ __\\ /__ _/.-` / /\n");
    printf("         ======`-.____`-.___\\_____/___.-`____.-'======\n");
    printf("                            `=---='\n");
    printf("         .............................................\n");
    printf("                  佛祖镇楼                  BUG辟易\n");
    printf("          佛曰:\n");
    // 重置样式，关闭闪烁及颜色等样式设置
    printf("\033[0m");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("■■■  学生权限菜单  \t■■■\n");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    printf("■■■  1、查看信息  \t■■■\n");
    printf("■■■  2、更改信息  \t■■■\n");
    printf("■■■  3、退出操作系统  \t■■■\n");
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
}

//学生进行操作的函数
void Opertor(int val,char ch[])
{
    switch (val)
    {
    case 1:
        FindInformation(ch);
        break;
    case 2:
        bool_ChangeInformation(ch);
        break;
    }
}

//学生查找信息的函数
void FindInformation(char ch[])
{
    struct Student* f = head_;
    while (f->st != NULL)
    {
        f = f->st;
        if (strcmp(f->xuehao_, ch) == 0)
        {
            printf("姓名\t性别\t年龄\t学号\t\t数学成绩\t语文成绩\t英语成绩\t总成绩\n");
            printf("%s\t%s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", f->name_, f->gender_, f->age_, f->xuehao_, f->Math, f->Chinese, f->English, f->sum);
            system("pause");
            system("cls");
            return;
        }
    }
}

//判断学生是否可以更改信息的函数
void bool_ChangeInformation(char hao[])
{
    //学生只能修改自身的个人信息，不能修改成绩，而且需要输入老师的权限密码
    printf("请输入教师给你的权限密钥：");
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
        printf("您输入的密码正确，请修改您的信息\n");
        Change_Information(hao);
    }
    else
    {
        printf("密码错误\n系统已经退出\n");
        system("pause");
        system("cls");
        return;
    }
}

//学生修改信息的函数
void Change_Information(char xuehao[])
{
    struct Student* p = head_;
    char ch[100];
    //学生只能修改姓名，性别，年龄
    printf("请输入你所要更改的内容：\n1、姓名\n2、性别\n3、年龄\n");
    scanf("%s", ch);
    if (Alter(ch))
    {
        while (p->st != NULL)
        {
            p = p->st;
            if (strcmp(xuehao, p->xuehao_) == 0)
            {
                if (strcmp("年龄", ch) == 0)
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
}