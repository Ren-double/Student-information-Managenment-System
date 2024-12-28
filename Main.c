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
//                  佛祖镇楼                  BUG辟易
//          佛曰:
//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？

//判断是否第一次进入系统成为校长或者老师（教师的密码会存储在Secure_Teacher.txt中，校长密码会存储在Secure.txt中）
bool FIRST(char p[])
{
	FILE* fp = fopen(p, "r");
	if (fp == NULL)
	{
		perror("file open failed:");
		fp = fopen(p, "w");
		if (strcmp(p, "Secure.txt") == 0)
			printf("欢迎您第一进入系统：\n请输入您要设置的校长密码：");
		else if (strcmp(p, "Secure_Teacher.txt") == 0)
			printf("欢迎您第一进入系统：\n请输入您要设置的教师密码：");
		char ch[100];
		scanf("%s", ch);
		ch[strlen(ch)] = '\0';
		fprintf(fp, "%s\n", ch);//将密码存入文件中
		int chang = strlen(ch);
		Secure2(ch, chang);
		fprintf(fp, "%s\n", ch);
		printf("经过加密:\n下次输入：%s即可\n建议各位将密码保存在一个相对安全的地方\n", ch);
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

//对系统进行注销的函数
void Destory()
{
	FILE* f1 = fopen("Student_information.txt", "r");
	FILE* f2 = fopen("Secure.txt", "r");
	if (f1 == NULL || f2 == NULL)
	{
		printf("你注册个毛线，你都没有文件你注销啥！！！\n");
		return;
	}
	fclose(f1);
	fclose(f2);
	printf("请问您真的确认注销整个系统的所有信息吗？\n确认请按#，退出请按@\n");
	char ch;
	scanf(" %c", &ch);
	if (ch == '#')
	{
		printf("请输入您的校长权限密钥：");
		char secure[100];
		scanf(" %s", secure);
		secure[strlen(secure)] = '\0';
		int n = strlen(secure);
		Secure(secure, n);
		FILE* ff = fopen("Secure.txt", "r");
		char GET[100];//从文件中读取密码，判断输入是否正确
		fscanf(ff, "%s", GET);
		GET[strlen(GET)] = '\0';
		fclose(ff);
		if (strcmp(secure, GET) != 0)
		{
			printf("你个冒牌货，再见\n");
			StudentEnd();
			return;
		}
		StudentEnd();
		remove("Secure.txt");
		remove("Student_information.txt");
		remove("Secure_Teacher.txt");
		remove("Grade_ranking.txt.txt");
		printf("恭喜您注销成功\n祝您生活愉快！\n");
		return;
	}
	else if(ch=='@')
	{
		printf("就知道你是点错了\n系统已经退出\n");
		StudentEnd();
		return;
	}
	else
	{
		printf("输入错误！\n你是假冒的吧！\n强制退出系统\n");
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
		printf("\033[1;96;5m");	//5是闪烁效果
		printf("              /\\_____/\\\n");
		printf("             /  o   o  \\\n");
		printf("            ( ==  ^  == )\n");
		printf("             )----O----(\n");
		printf("            (           )\n");
		printf("           ( (  )   (  ) )\n");
		printf("          (__(__)___(__)__) \n");
		printf("\033[0m");  // 重置样式
		printf("\033[1;96m    ------------------------------\033[0m \n");
		printf("\033[1;97m    欢迎大家来到学生管理系统\033[0m\n\n");
		printf("****该系统为学校管理系统****\n");
		printf("分为校长，教师，学生三大模块\n");
		printf("请选择你的身份：\n");
		printf("1、校长\n2、教师\n3、学生\n4、退出系统\n5、注销整个系统\n");
		system("pause");
		int number;
		printf("\n请输入你选择的序号：");
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
			printf("系统成功退出\n亲您可以去Student_information的文件中查看储存的学生信息哦\n");
			return 0;
		case 5:
			Destory();
			return 0;
		default:
			printf("请您再次确认您是否输入正确：");
			if (!scanf("%d", &number))
			{
				printf("\n你输入的是字符串，你是个大傻子，再见\n");
				StudentEnd();
				return 0;
			}
			printf("\n序号错误，请重新输入\n");
			goto sign;
		}
	}
	StudentEnd();
	return 0;
}