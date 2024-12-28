#pragma once//��ֹͷ�ļ��ظ�����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//��׼�������������
#include<string.h>//�ַ�����ͷ�ļ�
#include<stdlib.h>
#include<stdbool.h>//����bool��ͷ�ļ�

//����������
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

//ѧУ��ѧ��
struct Student
{
    int age_;//ѧ��������
    char gender_[100];//ѧ�����Ա�
    char name_[100];//ѧ��������
    char xuehao_[100];//ѧ����ѧ��
    char Math[100];
    char Chinese[100];
    char English[100];
    char sum[100];
    struct Student* st;
};

//����һ�������ͷ�ڵ�
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

//�ж��Ƿ��д���ѧ����Ϣ���ļ�
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
        struct Student* s1 = (struct Student*)malloc(sizeof(struct Student));//�ڶ��Ͻ��д���ѧ����ʵ����
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

//����ѧ�������ڴ���ͷ�
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

//�ļ�����ѧ����Ϣ�ĺ���
void Save(struct Student* s,int ge)
{
    FILE* fp = fopen("Student_information.txt", "r");
    if (fp == NULL)
    {
        perror("�ļ���ʧ�ܣ�");
        fp = fopen("Student_information.txt", "w");
        fprintf(fp, "���\t\t����\t\t�Ա�\t\t����\t\tѧ��\t\t\t��ѧ�ɼ�\t\t���ĳɼ�\t\tӢ��ɼ�\t\t�ܳɼ�\n");
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

//���Ļ���ɾ��ѧ����Ϣʱ���ļ��Ĵ���
void Changefile()
{
    FILE* f = fopen("Student_information.txt", "w");
    if (f == NULL)
    {
        perror("file open failed:");
        return;
    }
    fprintf(f, "���\t\t����\t\t�Ա�\t\t����\t\tѧ��\t\t\t��ѧ�ɼ�\t\t���ĳɼ�\t\tӢ��ɼ�\t\t�ܳɼ�\n");
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

//ѧУ��У��
struct Headmaster
{
    char* name;
};

//У���ĳ�ʼ������
static void HeadmasterInit()  
{
    printf("���������Ȩ����Կ��");
    char secure[100];
    scanf(" %s", secure);
    secure[strlen(secure)] = '\0';
    system("cls");
    int n = strlen(secure);
    Secure(secure, n);
    //���ÿ������ܽ��б任
    FILE* ff = fopen("Secure.txt", "r");
    char GET[100];//���ļ��ж�ȡ���룬�ж������Ƿ���ȷ
    fscanf(ff,"%s", GET);
    GET[strlen(GET)] = '\0';
    fclose(ff);
    if (strcmp(secure, GET) == 0)
    {
        printf("�������������ȷ����ϲ\n");
        Administration();
    }
    else
    {
        printf("�������\nϵͳ�Ѿ��˳�\n");
        return;
    }
}

//��ʦ�ĳ�ʼ������
static void TeacherInit()
{
    printf("���������Ȩ����Կ��");
    char secure[100];
    scanf(" %s", secure);
    secure[strlen(secure)] = '\0';
    system("cls");
    int n = strlen(secure);
    Secure(secure, n);
    //���ÿ������ܽ��б任
    FILE* fm = fopen("Secure_Teacher.txt", "r");
    char GET[100];//���ļ��ж�ȡ���룬�ж������Ƿ���ȷ
    fscanf(fm, "%s", GET);
    GET[strlen(GET)] = '\0';
    fclose(fm);
    if (strcmp(secure, GET) == 0)
    {
        printf("�������������ȷ����ϲ\n");
        TeAd();
    }
    else
    {
        printf("�������\nϵͳ�Ѿ��˳�\n");
        return;
    }
}

//��ʦ�������ܺ���
void TeAd()
{
    while (1)
    {
        printf("\033[1;33;5m");
        printf("\n\
                          _ooOoo_                          \n\
                         o8888888o                         \n\
                         88�� . ��88                         \n\
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
                  ���᱾����    �������̨                 \n\
                  ������BUG     �αس��޸�                 \n\
                                                           \n\n");
        printf("\033[0m");
        printf("\n������%d��ѧ������Ϣ\nѧ����ѧ����Ψһ��Ŷ\n\n", geshu);
        printf("*****��ʦȨ�޲˵�****\n");
        printf("** 1��¼��ѧ���ɼ� **\n");
        printf("** 2������ѧ���ɼ� **\n");
        printf("** 3����ѯѧ����Ϣ **\n");
        printf("*4����ʾ����ѧ����Ϣ*\n");
        printf("** 5��ѧ���ɼ����� **\n");
        printf("6�����Ľ�ʦ�Ľ�����Կ\n");
        printf("** 7���˳�����ϵͳ **\n");
        int value;
        printf("\n������������ѡ��Ĳ�����ţ�");
        int n = scanf("%d", &value);
        system("cls");
        if (!n)
        {
            printf("����������ַ��������Ǹ���ɵ�ӣ��ټ�\n\n");
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

//��ʦ���й����ĺ���
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

//��ʦ¼��͸���ѧ���ɼ��ĺ���
void Tpush(int val)
{
    struct Student* p = head_;
    printf("��������Ҫ¼��ѧ����ѧ�ţ�");
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
                printf("�������ѧ������ѧ�ɼ���");
                scanf("%s", p->Math);
                p->Math[strlen(p->Math)] = '\0';
                m = atoi(p->Math);
                printf("�������ѧ�������ĳɼ���");
                scanf("%s", p->Chinese);
                p->Chinese[strlen(p->Chinese)] = '\0';
                c = atoi(p->Chinese);
                printf("�������ѧ����Ӣ��ɼ���");
                scanf("%s", p->English);
                p->English[strlen(p->English)] = '\0';
                e = atoi(p->English);
                _itoa((m + c + e), p->sum, 10);
            }
            if (val == 2)
            {
                printf("�����������ѧ������ѧ�ɼ���");
                scanf("%s", p->Math);
                p->Math[strlen(p->Math)] = '\0';
                m = atoi(p->Math);
                printf("�����������ѧ�������ĳɼ���");
                scanf("%s", p->Chinese);
                p->Chinese[strlen(p->Chinese)] = '\0';
                c = atoi(p->Chinese);
                printf("�����������ѧ����Ӣ��ɼ���");
                scanf("%s", p->English);
                p->English[strlen(p->English)] = '\0';
                e = atoi(p->English);
                int sum = (m + c + e);
                _itoa(sum, p->sum, 10);
            }
            Changefile();
            printf("\n¼��ɹ���\n");
            system("pause");
            system("cls");
            return;
        }
    }
    printf("������˼��û����ϵͳ���ҵ���ѧ�Ŷ�Ӧ��ѧ����\n");
    system("pause");
    system("cls");
    return;
}

struct Student* merge(struct Student* left, struct Student* right) 
{
    struct Student* dummy = (struct Student*)malloc(sizeof(struct Student));
    if (dummy == NULL) 
    {
        printf("�ڴ����ʧ�ܣ��ϲ������޷�����\n");
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

// �鲢����ĵݹ黮�ֺ������ӵڶ����ڵ㿪ʼ�������򣬺���ͷ�ڵ�
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

// ���Ⱪ¶�����������������ù鲢�������������򣬺���ͷ�ڵ�(ѧ���ɼ��洢��Grade_ranking.txt.txt��)
void sortList() 
{
    //�������������
    if (head_ == NULL || head_->st == NULL) {
        return;
    }
    head_->st = mergeSort(head_->st);
    PrintGrade(head_);
    PushGrade(head_);

    //��������֮ǰ��ģ��
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

//��ӡѧ���ɼ������ĺ���
void PrintGrade(struct Student* m)
{
    if (m->st == NULL)
    {
        system("cls");
        printf("��ϵͳû���κ�ѧ����\n");
        system("pause");
        system("cls");
        return;
    }
    int i = 1;
    system("cls");
    printf("����\t����\t\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\t�ܳɼ�\n");
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

//���ļ���¼��ѧ���ɼ������ĺ���
void PushGrade(struct Student* m)
{
    FILE* f = fopen("Grade_ranking.txt.txt", "w");
    if (f == NULL)
    {
        perror("file open failed:");
        return;
    }
    fprintf(f, "����\t\t����\t\t�Ա�\t\t����\t\tѧ��\t\t\t��ѧ�ɼ�\t\t���ĳɼ�\t\tӢ��ɼ�\t\t�ܳɼ�\n");
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

//У�����������ܺ���
void Administration()
{
    while(1)
    {
        printf("\033[1;33;5m");
        printf("\n\
                          _ooOoo_                          \n\
                         o8888888o                         \n\
                         88�� . ��88                         \n\
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
                  ���᱾����    �������̨                 \n\
                  ������BUG     �αس��޸�                 \n\
                                                           \n\n");
        printf("\033[0m");
        printf("\n������%d��ѧ������Ϣ\nѧ����ѧ����Ψһ��Ŷ\n\n", geshu);
        printf("*****У��Ȩ�޲˵�****\n");
        printf("**** 1��¼����Ϣ ****\n");
        printf("**** 2��ɾ����Ϣ ****\n");
        printf("**** 3��������Ϣ ****\n");
        printf("*****4����ѯ��Ϣ ****\n");
        printf("*5����ʾ����ѧ����Ϣ*\n");
        printf("*6��ɾ������ѧ����Ϣ*\n");
        printf("7������У���Ľ�����Կ\n");
        printf("** 8���˳�����ϵͳ **\n");
        int value;
        printf("\n������������ѡ��Ĳ�����ţ�");
        int n = scanf("%d", &value);
        system("cls");
        if (!n)
        {
            printf("����������ַ��������Ǹ���ɵ�ӣ��ټ�\n\n");
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

//У�����й����ĺ���
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

//У��������Ϣ�ĺ���
void hpush(int* ge)
{
    struct Student* s1 = (struct Student*)malloc(sizeof(struct Student));
    if (s1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("������ѧ����������");
    scanf("%s", s1->name_);
    s1->name_[strlen(s1->name_)] = '\0';
    printf("������ѧ�����Ա�");
    scanf("%s", s1->gender_);
    s1->gender_[strlen(s1->gender_)] = '\0';
    printf("������ѧ�������䣺");
    scanf("%d", &(s1->age_));
    printf("������ѧ����ѧ�ţ�");
    scanf("%s", s1->xuehao_);
    s1->xuehao_[strlen(s1->xuehao_)] = '\0';
    strcpy(s1->Math, "����");
    strcpy(s1->Chinese, "����");
    strcpy(s1->English, "����");
    strcpy(s1->sum, "����");
    system("cls");
    struct Student* p1 = head_->st;
    struct Student* p2 = head_;
    while (p2->st != NULL)//��������ı����������Ƿ��������ͬ��ѧ��
    {
        if (strcmp(p1->xuehao_, s1->xuehao_) == 0)
        {
            printf("ϵͳ���Ѿ��и�ѧ�ţ�ѧ�Ŵ���\n���˳�\n");
            system("pause");
            system("cls");
            return;
            if (strcmp(p1->gender_, s1->gender_) == 0)
            {
                if (s1->age_ == p1->age_)
                {
                    if (strcmp(p1->name_, s1->name_) == 0)//���ܳ���ͬ������������Ҫ��ѧ�����Ա���
                    {
                        printf("�Ѿ��и�ѧ��������������ӣ�\n");
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
    //�������������Ϣ�������ļ���
    struct Student* p = head_;
    while (p->st != NULL)//���б��������������ѧ�����������ĩβ
    {
        p = p->st;
    }
    *ge = *ge + 1;
    p->st = s1;
    s1->st = NULL;
    Save(s1, *ge);
}

//У��ɾ����Ϣ�ĺ���
void hdelete(int* ge)
{ 
    system("cls");
    if (*ge==0)
    {
        printf("�Ѿ�û��ѧ����\n����ɾ��\n");
        system("pause");
        system("cls");
        return;
    }
    int age;
    char gender[100];
    char name[100];
    char xuehao[100];
    printf("����������Ҫɾ����ѧ����������");
    scanf("%s", name);
    name[strlen(name)] = '\0';
    printf("����������Ҫɾ����ѧ�����Ա�");
    scanf("%s", gender);
    gender[strlen(gender)] = '\0';
    printf("����������Ҫɾ����ѧ�������䣺");
    scanf("%d", &age);
    printf("����������Ҫɾ����ѧ����ѧ�ţ�");
    scanf("%s", xuehao);
    xuehao[strlen(xuehao)] = '\0';
    struct Student* p1 = head_->st;
    struct Student* p2 = head_;
    while (p2->st != NULL)//��������ı����������Ƿ��������ͬ��ѧ��
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
                        printf("ɾ���ɹ���\n");
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
    printf("δ�ҵ���ѧ������Ϣ��\n���������Ƿ���ȷ\n");
    system("pause");
    system("cls");
}

//У����ʾѧ��������Ϣ�ĺ���
void hshow()
{
    struct Student* p = head_;
    if (p->st == NULL)
    {
        system("cls");
        printf("��ϵͳû���κ�ѧ����\n");
        system("pause");
        system("cls");
        return;
    }
    int i = 1;
    system("cls");
    printf("���\t����\t�Ա�\t����\tѧ��\t\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\t�ܳɼ�\n");
    while (p->st != NULL)
    {
        p = p->st;
        int len = strlen(p->name_);
        if (len == 8)
        {
            printf("%d��\t%s %s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", i, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
            continue;
        }
        printf("%d��\t%s\t%s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", i, p->name_, p->gender_, p->age_, p->xuehao_, p->Math, p->Chinese, p->English, p->sum);
        i++;
    }
    system("pause");
    system("cls");
}

//У��ɾ������ѧ����Ϣ�ĺ���
void DeleteAll(int *ge)
{
    if (*ge == 0)
    {
        printf("��ɾ����ë��ϵͳ��û��ѧ����\n");
        system("pause");
        system("cls");
        return;
    }
    char ch;
    system("cls");
    printf("��ȷ���Ƿ�Ҫɾ������ѧ����Ϣ��\nȷ��������#����������@\n");
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
        printf("ɾ���ɹ���\n");
        system("pause");
        system("cls");
    }
    else if (ch == '@')
    {
        printf("ԭ�����ǲ���ʧ�󰡣�\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("�������\n���Ǽ�ð�İɣ�\n");
        system("pause");
        system("cls");
        return;
    }
    *ge = 0;
}

//У����ѯѧ����Ϣ�ĺ���
void hFind()
{
    struct Student* f = head_;
    if (f->st == NULL)
    {
        printf("ɵ�������ģ�ϵͳ����û��ѧ��������ʲô�ң�����\n");
        system("pause");
        system("cls");
        return;
    }
    char xuehao[100];
    printf("����������Ҫ��ѯ��ѧ����ѧ�ţ�");
    scanf("%s", xuehao);
    xuehao[strlen(xuehao)] = '\0';
    while (f->st != NULL)
    {
        f = f->st;
        if (strcmp(f->xuehao_, xuehao) == 0)
        {
            printf("����\t�Ա�\t����\tѧ��\t\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\t�ܳɼ�\n");
            printf("%s\t%s\t%d\t%s\t%s\t\t%s\t\t%s\t\t%s\n", f->name_, f->gender_, f->age_, f->xuehao_, f->Math, f->Chinese, f->English, f->sum);
            system("pause");
            system("cls");
            return;
        }
    }
    printf("δ�ҵ���ѧ�����������������Ϣ�Ƿ���ȷ\n");
    system("pause");
    system("cls");
}

//У������ѧ����Ϣ�ĺ���
void hChange()
{
    struct Student* p = head_;
    if (p->st == NULL)
    {
        printf("��ϵͳû��ѧ�����޷����ģ�\n");
        system("pause");
        system("cls");
        return;
    }
    char ch[100];
    printf("����������Ҫ���ĵ����ݣ�\n1������\n2���Ա�\n3������\n4��ѧ��\n");
    scanf("%s", ch);
    if (Alter(ch))
    {
        printf("����Ϊ��ϵͳ����ѧ������Ϣ\n");
        hshow();
        char xuehao[100];
        printf("�������㽫Ҫ�޸ĵ�ѧ����ѧ�ţ�");
        scanf("%s", xuehao);
        xuehao[strlen(xuehao)] = '\0';
        while (p->st != NULL)
        {
            p = p->st;
            if (strcmp(xuehao, p->xuehao_)==0)
            {
                if (strcmp("����", ch)==0)
                {
                    printf("������Ҫ��%s��%d����Ϊ��", ch, p->age_);
                    scanf("%d", &p->age_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
                else if (strcmp("����", ch) == 0)
                {
                    printf("������Ҫ��%s��%s����Ϊ��", ch, p->name_);
                    scanf("%s", p->name_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
                else if (strcmp("�Ա�", ch) == 0)
                {
                    printf("������Ҫ��%s��%s����Ϊ��", ch, p->gender_);
                    scanf("%s", p->gender_);
                    Changefile();
                    system("pause");
                    system("cls");
                    return;
                }
                else if (strcmp("ѧ��", ch) == 0)
                {
                    printf("������Ҫ��%s��%s����Ϊ��", ch, p->xuehao_);
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
        printf("\nɵ�������ģ��ⶼ���벻�ԣ��װ������ϣ�\n");
        system("pause");
        system("cls");
        return;
    }
    printf("û���ҵ���ͬѧ����\n");
    system("pause");
    system("cls");
}
bool Alter(char* c)
{
    if (strcmp(c, "����") == 0 || strcmp(c, "�Ա�") == 0 || strcmp(c, "ѧ��") == 0 || strcmp(c, "����") == 0)
    {
        return true;
    }
    else
        return false;
}

//У���ͽ�ʦ����������ĵĺ���
void ChangeSecure(char p[])
{
    FILE* fp = fopen(p, "w");
    if (fp == NULL)
    {
        perror("file open failed��");
        return;
    }
    printf("�������µ����룺");
    char ch[100];
    scanf("%s", ch);
    ch[strlen(ch)] = '\0';
    fprintf(fp, "%s\n", ch);
    Secure2(ch, strlen(ch));
    fprintf(fp, "%s\n", ch);
    printf("��������:\n�´����룺%s����\n�����λ�����뱣����һ����԰�ȫ�ĵط�\n", ch);
    fclose(fp);
    system("pause");
    system("cls");
}

//���ÿ���������м򵥵Ľ���
static void Secure(char p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] - 1;
    }
}

//���ÿ���������м򵥼���
static void Secure2(char p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] + 1;
    }
}