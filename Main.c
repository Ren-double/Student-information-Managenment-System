#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"school.h"
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Student.h"

//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  ������¥                  BUG����
//          ��Ի:
//                  д��¥��д�ּ䣬д�ּ������Ա��
//                  ������Աд�������ó��򻻾�Ǯ��
//                  ����ֻ���������������������ߣ�
//                  ��������ո��գ����������긴�ꡣ
//                  ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
//                  ���۱������Ȥ���������г���Ա��
//                  ����Ц��߯��񲣬��Ц�Լ���̫����
//                  ��������Ư���ã��ĸ���ó���Ա��

//�ж��Ƿ��һ�ν���ϵͳ��ΪУ��������ʦ����ʦ�������洢��Secure_Teacher.txt�У�У�������洢��Secure.txt�У�
bool FIRST(char p[])
{
	FILE* fp = fopen(p, "r");
	if (fp == NULL)
	{
		perror("file open failed:");
		fp = fopen(p, "w");
		if (strcmp(p, "Secure.txt") == 0)
			printf("��ӭ����һ����ϵͳ��\n��������Ҫ���õ�У�����룺");
		else if (strcmp(p, "Secure_Teacher.txt") == 0)
			printf("��ӭ����һ����ϵͳ��\n��������Ҫ���õĽ�ʦ���룺");
		char ch[100];
		scanf("%s", ch);
		ch[strlen(ch)] = '\0';
		fprintf(fp, "%s\n", ch);//����������ļ���
		int chang = strlen(ch);
		Secure2(ch, chang);
		fprintf(fp, "%s\n", ch);
		printf("��������:\n�´����룺%s����\n�����λ�����뱣����һ����԰�ȫ�ĵط�\n", ch);
		fclose(fp);
		system("pause");
		system("cls");
		return false;
	}
	else
	{
		fclose(fp);
		return true;
	}
}

//��ϵͳ����ע���ĺ���
void Destory()
{
	FILE* f1 = fopen("Student_information.txt", "r");
	FILE* f2 = fopen("Secure.txt", "r");
	if (f1 == NULL || f2 == NULL)
	{
		printf("��ע���ë�ߣ��㶼û���ļ���ע��ɶ������\n");
		return;
	}
	fclose(f1);
	fclose(f2);
	printf("���������ȷ��ע������ϵͳ��������Ϣ��\nȷ���밴#���˳��밴@\n");
	char ch;
	scanf(" %c", &ch);
	if (ch == '#')
	{
		printf("����������У��Ȩ����Կ��");
		char secure[100];
		scanf(" %s", secure);
		secure[strlen(secure)] = '\0';
		int n = strlen(secure);
		Secure(secure, n);
		FILE* ff = fopen("Secure.txt", "r");
		char GET[100];//���ļ��ж�ȡ���룬�ж������Ƿ���ȷ
		fscanf(ff, "%s", GET);
		GET[strlen(GET)] = '\0';
		fclose(ff);
		if (strcmp(secure, GET) != 0)
		{
			printf("���ð�ƻ����ټ�\n");
			StudentEnd();
			return;
		}
		StudentEnd();
		remove("Secure.txt");
		remove("Student_information.txt");
		remove("Secure_Teacher.txt");
		remove("Grade_ranking.txt.txt");
		printf("��ϲ��ע���ɹ�\nף��������죡\n");
		return;
	}
	else if(ch=='@')
	{
		printf("��֪�����ǵ����\nϵͳ�Ѿ��˳�\n");
		StudentEnd();
		return;
	}
	else
	{
		printf("�������\n���Ǽ�ð�İɣ�\nǿ���˳�ϵͳ\n");
		system("pause");
		StudentEnd();
		return;
	}
}

int main()
{
	StudentInit();
	File(&geshu);
	while (1)
	{
	sign:
		printf("\033[1;96m    ------------------------------\033[0m \n");
		printf("\033[1;96;5m");	//5����˸Ч��
		printf("              /\\_____/\\\n");
		printf("             /  o   o  \\\n");
		printf("            ( ==  ^  == )\n");
		printf("             )----O----(\n");
		printf("            (           )\n");
		printf("           ( (  )   (  ) )\n");
		printf("          (__(__)___(__)__) \n");
		printf("\033[0m");  // ������ʽ
		printf("\033[1;96m    ------------------------------\033[0m \n");
		printf("\033[1;97m    ��ӭ�������ѧ������ϵͳ\033[0m\n\n");
		printf("****��ϵͳΪѧУ����ϵͳ****\n");
		printf("��ΪУ������ʦ��ѧ������ģ��\n");
		printf("��ѡ�������ݣ�\n");
		printf("1��У��\n2����ʦ\n3��ѧ��\n4���˳�ϵͳ\n5��ע������ϵͳ\n");
		system("pause");
		int number;
		printf("\n��������ѡ�����ţ�");
		scanf("%d", &number);
		system("cls");
		switch (number)
		{
		case 1:
		{
			FIRST("Secure.txt");
			HeadmasterInit();
			break;
		}
		case 2:
		{
			FIRST("Secure_Teacher.txt");
			TeacherInit();
			break;
		}
		case 3:
			Student_Oper();
			break;
		case 4:
			printf("ϵͳ�ɹ��˳�\n��������ȥStudent_information���ļ��в鿴�����ѧ����ϢŶ\n");
			return 0;
		case 5:
			Destory();
			return 0;
		default:
			printf("�����ٴ�ȷ�����Ƿ�������ȷ��");
			if (!scanf("%d", &number))
			{
				printf("\n����������ַ��������Ǹ���ɵ�ӣ��ټ�\n");
				StudentEnd();
				return 0;
			}
			printf("\n��Ŵ�������������\n");
			goto sign;
		}
	}
	StudentEnd();
	return 0;
}