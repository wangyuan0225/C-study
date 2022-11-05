#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


//创建结构体
struct studentsFile {
	char id[15];
	char name[20];
	char sex[9];
	int age;
	char class[100];
};

int main() {
	struct studentsFile students[400];//定义一个400学生的结构体
	FILE* fp = fopen("students.txt", "r");//打开students文件，只读
	int pd = 0;//判定学生是否存在
	for (int i = 0; i < 400; i++) {
		fscanf(fp, "%[^,],%[^,],%[^,],%d,%s\n", &students[i].id, &students[i].name, &students[i].sex, &students[i].age,
			&students[i].class);//参考了CSDN上如何讲文件内容复制到结构体中
	}
	while (1) {//循环
		printf("i.查询模式1：根据姓名或学号查询学生信息\nii.查询模式2：根据年龄范围查询学生信息\niii.查询模式3：根据班级查询学生信息\n其他:退出查询\n");
		printf("请输入查询模式:>");//提示语
		int mod;
		scanf("%d", &mod);//输入查询模式
		switch (mod) {
		case 1://进入模式1
			pd = 0;//初始化判定
			printf("样例1： 输入： 张三\n输出： 张三, 2017002871, 男, 17, 大数据1702\n张三, 2015009321, 男, 22, 信计1502\n");
			printf("样例2： 输入： 2017009876\n输出： 小路, 2016009876, 男, 20, 大数据1701\n");
			printf("请输入姓名或学号:>");//提示语
			char pf[99];
			scanf("%s", pf);//输入姓名或者学号
			for (int i = 0; i < 401; i++) {//遍历结构体数组
				if ((strcmp(students[i].name, pf) == 0)
					|| (strcmp(students[i].id, pf) == 0)) {//判定所输入的学号或者姓名在文件中是否存在
					printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age,
						students[i].class);//打印对应的学生
					pd = 1;//改变判定值，说明学生信息存在
				}
			}
			if (pd == 0)//判定值未改变，学生信息不存在
				printf("查无此人\n");
			printf("------------------------------------------\n");
			break;//回到查询模式
		case 2://进入模式2
			pd = 0;//初始化判定
			printf("样例1： 输入： 18 20 \n输出： 李四, 2017001765, 女, 18, 软件工程1712\n小路, 2016009876, 男, 20, 大数据1701\n大张伟, 2014002715, 男, 19, 计算机1402\n");
			printf("请输入两个数确定年龄范围，要求第一个数小于等于第二个数:>");//提示语
			int age[2];
			scanf("%d%d", &age[0], &age[1]);//输入两个数字确定奈年龄范围
			if (age[0] > age[1]) {//规定第一个数小于等于第二个数
				printf("输入错误");
				break;
			}
			else {
				for (int i = 0; i < 401; i++) {//遍历结构体数组
					if (students[i].age >= age[0] && students[i].age <= age[1]) {
						printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
						pd = 1;//改变学生信息存在判定
					}
				}
				if (pd == 0)//学生信息不存在
					printf("查无此人\n");
			}
			printf("------------------------------------------\n");
			break;
		case 3:
			pd = 0;
			printf("样例1： 输入： 大数据1702\n输出： 张三, 2017002871, 男, 17, 大数据1702\n王璐丹, 2017009479, 女, 22, 大数据1702\n");
			printf("请输入专业班级:>");
			char class[99];
			scanf("%s", class);//输入班级
			for (int i = 0; i < 401; i++) {//作用同Case1和2
				if ((strcmp(students[i].class, class) == 0) || (strcmp(students[i].class, class) == 0)) {
					printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
					pd = 1;
				}
			}
			if (pd == 0)//作用同case1&2
				printf("查无此人\n");
			printf("------------------------------------------\n");
			break;
		default://输入其他数，退出查询
			printf("退出查询\n");
			return 0;
		}
	}
	fclose(fp);//关闭文件
	return 0;
}



//struct record {
//	char id;
//	int score;
//	int time;
//};
//
//int  main()
//{
//	srand((unsigned int)time(NULL));
//	while (1)
//	{
//		struct record nRecord[400];
//		printf("请输入ID号:>");
//		char id[99];
//		char sign[5] = { '+','-','*','/','+' };
//		char* test;
//		char yunsuan[10] = { '0' };
//		int choice;
//		int first[10];
//		int second[10];
//		int answer[10];
//		int idAnswer[10];
//		int true = 0;
//		int pd = 1;
//		int t1, t2;
//		char* pid = id;
//		FILE* fp = fopen("record.txt", "a");
//		scanf("%s", id);
//		if ((*pid >= 'A' && *pid <= 'Z') && (*(pid + 1) >= 'A' && *(pid + 1) <= 'Z') && (*(pid + 2) >= '0' && *(pid + 2) <= '9') && (*(pid + 3) >= '0' && *(pid + 3) <= '9') && (*(pid + 4) >= '0' && *(pid + 4) <= '9') && (*(pid + 5) >= '0' && *(pid + 5) <= '9'))
//		{
//			printf("请选择:\n(1)开始测试\n(2)检查分数\n(3)退出\n");
//			scanf("%d", &choice);
//			switch (choice)
//			{
//			case 1:
//				t1 = time(NULL);
//				for (int i = 0; i < 10; )
//				{
//					test = sign + rand() % 4;
//					if (i > 0 && *test == yunsuan[i - 1])
//					{
//						yunsuan[i] = *(test + 1);
//					}
//					else
//					{
//						yunsuan[i] = *(test);
//					}
//					if (yunsuan[i] == '+')
//					{
//						do {
//							first[i] = rand() % 100 + 1;
//							second[i] = rand() % 100 + 1;
//							answer[i] = first[i] + second[i];
//						} while (first[i] + second[i] > 100);
//						printf("%d%c%d=", first[i], yunsuan[i], second[i]);
//						scanf("%d", &idAnswer[i]);
//					}
//					if (yunsuan[i] == '-')
//					{
//						do {
//							first[i] = rand() % 100 + 1;
//							second[i] = rand() % 100 + 1;
//							answer[i] = first[i] - second[i];
//						} while (answer[i] >= 100 || answer[i] < 0);
//						printf("%d%c%d=", first[i], yunsuan[i], second[i]);
//						scanf("%d", &idAnswer[i]);
//					}
//					if (yunsuan[i] == '*')
//					{
//						do {
//							first[i] = rand() % 100 + 1;
//							second[i] = rand() % 100 + 1;
//							answer[i] = first[i] * second[i];
//						} while (answer[i] > 100);
//						printf("%d%c%d=", first[i], yunsuan[i], second[i]);
//						scanf("%d", &idAnswer[i]);
//					}
//					if (yunsuan[i] == '/')
//					{
//						do 
//						{
//							first[i] = rand() % 100 + 1;
//							second[i] = rand() % 100 + 1;
//							answer[i] = first[i] / second[i];
//						} while (first[i] % second[i] != 0);
//						printf("%d%c%d=", first[i], yunsuan[i], second[i]);
//						scanf("%d", &idAnswer[i]);
//					}
//					if (answer[i] == idAnswer[i])
//					{
//						true++;
//					}
//					i++;
//				}
//				t2 = time(NULL);
//				printf("问题 | 正确答案 | 你的答案\n");
//				for (int i = 0; i < 10; i++)
//				{
//					printf("%d%c%d=|   %d    |     %d     \n", first[i], yunsuan[i], second[i], answer[i], idAnswer[i]);
//				}
//				
//				printf("成绩:%d0分\n用时:%ds\n", true, t2 - t1);
//				fprintf(fp, "%s %d %d\n", id, true, t2 - t1);
//				fclose(fp);
//				break;
//			case 2:
//				for (int i = 0; i < 400; i++) 
//				{
//					fscanf(fp, "%[^ ] %[^ ] %d\n", &nRecord[i].id, &nRecord[i].score, &nRecord[i].time);
//				}
//				for (int i = 0; i < 400; i++)
//				{
//					if (strcmp(nRecord[i].id, id) == 0)
//					{
//						printf("%s %d0 %ds\n", nRecord[i].id, nRecord[i].score, nRecord[i].time);
//					}
//				}
//				break;
//			case 3:
//				return 0;
//			default:
//				break;
//			}
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//		}
//	}
//	return 0;
//}



//struct studentsFile
//{
//	char id[15];
//	char name[20];
//	char sex[9];
//	int age;
//	char class[100];
//};
//
//int main()
//{
//	struct studentsFile students[400];
//	FILE* fp = fopen("C:\\students.txt", "r");
//	char students1[999];
//	int pd = 0;
//	for (int i = 0; i < 400; i++)
//	{
//		fscanf(fp, "%[^,],%[^,],%[^,],%d,%s\n", &students[i].id, &students[i].name, &students[i].sex, &students[i].age, &students[i].class);
//	}
//	while (1)
//	{
//		printf("i.查询模式1：根据姓名或学号查询学生信息\nii.查询模式2：根据年龄范围查询学生信息\niii.查询模式3：根据班级查询学生信息\n其他:退出查询\n");
//		printf("请输入查询模式:>");
//		int mod;
//		scanf("%d", &mod);
//		switch (mod)
//		{
//		case 1:
//			printf("样例1： 输入： 张三\n输出： 张三, 2017002871, 男, 17, 大数据1702\n张三, 2015009321, 男, 22, 信计1502\n");
//			printf("样例2： 输入： 2017009876\n输出： 小路, 2016009876, 男, 20, 大数据1701\n");
//			printf("请输入姓名或学号:>");
//			char pf[99];
//			scanf("%s", pf);
//			for (int i = 0; i < 401; i++)
//			{
//				if ((strcmp(students[i].name, pf) == 0) || (strcmp(students[i].id, pf) == 0))
//				{
//					printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
//					pd = 1;
//				}
//			}
//			if (pd == 0)
//				printf("查无此人");
//			printf("------------------------------------------\n");
//			break;
//		case 2:
//			printf("样例1： 输入： 18 20 \n输出： 李四, 2017001765, 女, 18, 软件工程1712\n小路, 2016009876, 男, 20, 大数据1701\n大张伟, 2014002715, 男, 19, 计算机1402\n");
//			printf("请输入两个数确定年龄范围，要求第一个数小于等于第二个数:>");
//			int age[2];
//			scanf("%d%d", &age[0], &age[1]);
//			if (age[0] > age[1])
//			{
//				printf("输入错误");
//				break;
//			}
//			//printf("%d %d", age[0],age[1]);
//			else
//			{
//				for (int i = 0; i < 401; i++)
//				{
//					if (students[i].age >= age[0] && students[i].age <= age[1])
//					{
//						printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
//						pd = 1;
//					}
//				}
//				if (pd == 0)
//					printf("查无此人\n");
//			}
//			printf("------------------------------------------\n");
//			break;
//		case 3:
//			printf("样例1： 输入： 大数据1702\n输出： 张三, 2017002871, 男, 17, 大数据1702\n王璐丹, 2017009479, 女, 22, 大数据1702\n");
//			printf("请输入专业班级:>");
//			char class[99];
//			scanf("%s", class);
//			for (int i = 0; i < 401; i++)
//			{
//				if ((strcmp(students[i].class, class) == 0) || (strcmp(students[i].class, class) == 0))
//				{
//					printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
//					pd = 1;
//				}
//
//			}
//			if (pd == 0)
//				printf("查无此人");
//			printf("------------------------------------------\n");
//			break;
//		default:
//			printf("退出查询");
//			return 0;
//		}
//	}
//	fclose(fp);
//	return 0;
//}


//int  main()
//{
//	int	red = 3, white = 3, black = 6;
//	for (int i = 2; i <= black; i++)
//	{
//
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	for (int a = 1;; a++)
//	{
//		if (a % 2 == 1 && a % 3 == 2 && a % 5 == 4 && a % 6 == 5 && a % 7 == 0)
//		{
//			printf("%d\n", a);
//			break;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n, a;
//	int result = 0;
//	printf("计算a + aa + aaa + … + aa…a（n 个 a）\n");
//	printf("请输入n值>>");
//	scanf("%d", &n);
//	printf("请输入a值>>");
//	scanf("%d", &a);
//	for (int j = 1; j <= n; j++)
//	{
//		int all = 0;
//		for (int i = 0; i < j; i++)
//		{
//			all += a * pow(10, i);
//		}
//		result += all;
//	}
//	printf("%d", result);
//	return 0;
//}


//int jiecheng(int n);
//
//int main()
//{
//	float x;
//	while (1)
//	{
//		printf("sin(x)请输入x>>");
//		scanf("%f", &x);
//		float all = 0;
//		int n = 1;
//		int fuhao = 1;
//		for (int i = 1; ; i += 2, fuhao *= (-1), n++)
//		{
//			all += fuhao * pow(x, i) / jiecheng(i);
//			if (x / jiecheng(i) < 0.00001)
//			{
//				break;
//			}
//		}
//		printf("%f %d\n", all, n);
//	}
//	return 0;
//}
//
//int jiecheng(int n)
//{
//	int result = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		result *= i;
//	}
//	return result;
//}


//int main()
//{
//	float e = 2.325465;
//	printf("%f\n", fabs(e));
//	printf("%f\n", e);
//	return 0;
//}


//int jiecheng(int n);
//
//int main()
//{
//	int n;
//	float e = 1;
//	for (n = 1;; n++)
//	{
//		e += 1.0 / jiecheng(n);
//		if (fabs(1.0 / jiecheng(n)) < 0.00001)
//		{
//			break;
//		}
//	}
//	printf("e的近似值为>>%f\n", e);
//	printf("共累加了%d项\n", n + 1);
//	return 0;
//}
//
//int jiecheng(int n)
//{
//	int result = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		result *= i;
//	}
//	return result;
//}




//int i, n, s, gen;
//char mchuan[99];
//char zchuan[99];
//int main()
//{
//	gets(mchuan);
//	gets(zchuan);
//	int zlen = strlen(zchuan);
//	int mlen = strlen(mchuan);
//	for (i = 0; (i<zlen) && (((i + strlen(zchuan)) <= mlen));i++, zlen++)
//	{
//		for (n = 0; n < strlen(zchuan); n++,i++)
//		{
//			if (*(mchuan + i) == *(zchuan + n))
//			{
//				s++;
//			}
//		}
//		if (s == strlen(zchuan))
//		{
//			gen++;
//		}
//		s = 0;
//		i -= strlen(zchuan);
//	}
//	printf("%d\n", gen);
//	return 0;
//}




//int main()
//{
//	int n, a;
//	int result = 0;
//	printf("计算a + aa + aaa + … + aa…a（n 个 a）\n");
//	printf("请输入n值>>");
//	scanf("%d", &n);
//	printf("请输入a值>>");
//	scanf("%d", &a);
//	for (int i = 0; i < n; i++)
//	{
//		result += pow(a, i + 1);
//	}
//	printf("=%d\n", result);
//	return 0;
//}


//int main()
//{
//	int result = 0;
//	for (int i = 1; i < 100; i+=2)
//	{
//		result += i * (i + 1) * (i + 2);
//	}
//	printf("%d", result);
//	return 0;
//}


//int main()
//{
//	int x, y;
//	char op;
//	scanf("%d%c%d", &x, &op, &y);
//	switch (op)
//	{
//	case '+':printf("%d %c %d = %d", x, op, y, x + y); break;
//	case '-':printf("%d %c %d = %d", x, op, y, x - y); break;
//	case '*':printf("%d %c %d = %d", x, op, y, x * y); break;
//	case '/':printf("%d %c %d = %d", x, op, y, x / y); break;
//	default:
//		break;
//	}
//	return 0;
//}


//int main()
//{
//	int grade, shi;
//	scanf("%d", &grade);
//	shi = grade / 10;
//	switch (shi)
//	{
//	case 0:
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:printf("不合格"); break;
//	case 6:printf("合格"); break;
//	case 7:printf("中等"); break;
//	case 8:printf("良好"); break;
//	case 9:
//	case 10:printf("优秀"); break;
//	default:
//		break;
//	}
//	return 0;
//}



//int main()
//{
//	int grade;
//	scanf("%d", &grade);
//	if (grade >= 0 && grade <= 100)
//		if (grade < 60)
//			printf("不合格");
//		else if (grade < 70)
//			printf("合格");
//			else if (grade < 80)
//				printf("中等");
//				else if (grade < 90)
//					printf("良好");
//					else printf("优秀");
//	else 
//		printf("输入数据不符合要求");
//	return 0;
//}


//int main()
//{
//	int m = 0, n = 0;
//	char c;
//	while (c=getchar()!= '\n')
//	{
//		if (c >= 'A' && c <= 'Z') m++;
//		if (c >= 'a' && c <= 'z') n++;
//	}
//	//int a = 1, b = 2, c = 3, t;
//	//while (a < b < c)
//	//{
//	//	t = a;
//	//	a = b;
//	//	b = t;
//	//	c--;
//	//}
//	//printf("%d,%d,%d", a, b, c);
//	//int i = 100;
//	//while (1)
//	//{
//	//	i = i % 100 + 1;
//	//	if (i >= 100)
//	//		break;
//	//}
//	//for (;;);
//	return 0;
//	//int k = 2;
//	//while (k = 1)
//	//{
//	//	printf("%d", k);
//	//	k--;
//	//}
//}


//int main()
//{
//	char str[99];
//	int* p = str;
//	char son[99];
//	int* q = son;
//	int num = 0;
//	int i = 0, all = 0;
//	int j = 0;
//	printf("请输入一个字符串\n");
//	gets(str);
//	printf("请输入一个子串\n");
//	gets(son);
//	int lenson = strlen(son);
//	for (i = 0; (i < lenson) && ((i + strlen(son)) <= strlen(str)); i++, num = 0, lenson++)
//	{
//		for (j = 0; j < strlen(son); i++, j++)
//		{
//			if (*(str+i) == *(son+j))
//			
//			{
//				num++;
//			}
//		}
//		if (num == strlen(son))
//		{
//			all++;
//		}
//		i -= strlen(son);
//		j = 0;
//	}
//	printf("该子串共出现了%d次\n", all);
//	return 0;
//}


//int main()
//{
//	char c = ' ';
//	
//	printf("%d\n", c);
//
//	return 0;
//}


//int main()
//{
//	int i, j;
//	char str[99];
//	char* p = str;
//	gets(str);
//	int st = strlen(str);
//	for (i = 0; i < st; i++)
//	{
//		if ((int)*(p + i) == 32)
//		{
//			for (j = st; j > i; j--)
//			{
//				*(p + j + 2) = *(p + j);
//			}
//			st += 2;
//			i += 2;
//			*(p + j) = '%';
//			*(p + j + 1) = '2';
//			*(p + j + 2) = '0';
//		}
//	}
//	printf("%s\n", p);
//	//printf("%d\n", strlen(str));
//	//printf("%d\n", (int)*(p + 1));
//	return 0;
//}


//void hello();
//void change(int *a,int *b);
//
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	hello();
//	change(&x, &y);
//	printf("%d %d\n", x, y);
//	return 0;
//}
//
//void hello()
//{
//	printf("Hello world!\n");
//}
//
//void change(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//
//}


//int main()
//{
//	char* skr = "all";
//	printf("%s", skr);
//	return 0;
//}


//int main()
//{
//	int a = 8, b = 9;
//	char* p = 'a';
//	int* q = p + 1;
//	printf("%d\n", *p);
//	printf("%d\n", *q);
//	printf("%s\n%x\n", p, &b);
//	return 0;
//}


//int main()
//{
//	int a = 8, *p, *q;
//	p = &a;
//	printf("p=%x\n", p);
//	printf("*p=%d\n", *p);
//	q = p;
//	printf("q=%x\n", q);
//	printf("q=%d\n", *q);
//	return 0;
//}


//void change(int *a, int *b);
//
//int main()
//{
//	int a, b;
//	a = 10;
//	b = 20;
//	printf("%d %d\n", a, b);
//	printf("%p %p\n", &a, &b);
//	change(&a, &b);
//	printf("%d %d\n", a, b);
//	printf("%p %p\n", &a, &b);
//	return 0;
//}
//
//void change(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}


//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; (y = 123) && (x < 4); x++)
//	{
//		printf("1");
//	}
//	return 0;
// }


//int main()
//{
//	int a;
//	for (a = 1; a < 5; a++)
//	{
//		a = 2 * a;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//int main()
//{
//	int i, sum, n;
//	while (1)
//	{
//		i = 1;
//		sum = 0;
//		printf("请输入一个数:>");
//		scanf("%d", &n);
//		while (i <= n)
//		{
//			sum += i;
//			i++;
//		}
//		printf("sum = %d\n", sum);
//	}	
//	return 0;
//}


//#define NOT_EXIST -1
//#define INIT_SIZE 50
//#define MAX_SIZE 100
//
//int dirty[MAX_SIZE] = {0};
//int e = 0;
//int size = INIT_SIZE - 1;
//char word[20];
//char words[MAX_SIZE][20] = { "just","see","him","your","come","persistent","now","than","like","other","how","then","its","our","two","more","these","want","way","look","first","also","new","because","day","use","no","man","find","here","thing","give","many","well","only","those","tell","very","even","back","any","good","woman","through","us","life","child","work","down","may" };
//char chinese[MAX_SIZE][300] = { "adj. 公正的,公平的,恰当的 adv. 正好,恰好","vt. 看见,经历,明白,确保,视为,拜访,陪同 vi. 注意,想象,了解,调查 n. 主教教区,主角权限","pron. 他(宾格)","pron. 你的, 你们的","vt. 接近，扮演 vi. 来，发生，达到，进入","adj.执着的；不屈不挠的；坚持不懈的；连绵的","n. 现在,此刻 adj. 现存的, 目前的 adv. 现在,立刻 conj. 既然 abbr. =National Organization of Women 全国妇女组织","conj.比（用于比较级）； 宁愿…而不愿； 除…以外； 一…就 prep.超过； 比","adj. 相似的,同样的 vt. &vi. 喜欢,愿意,想 prep. 像,如同 n. 爱好,类似的人（或物） adv. 大概,和…一样 conj. 如同","adj. 别的,其他的 pron. 另一个人(或事) n. 其他人(或事)"," 	adv. 如何,怎样,多么,多少 conj. 如何,怎样,以...方式 n. 方式","adv. 那么, 当时，然后，于是 adj. 当时的","pron.（it的所有格)它的","pron. 我们的","num. 二，两个","adv.更，更多； 达到或处于更大的范围或程度； 此外，更加 adj.更多的； (many)的比较级； 附加的，额外的 pron.更多的或附加的人或事物 n.更多； 附加，添加","adj.&pron. 这些","n. 缺乏, 贫困, 欲望, 需要, 不足 vi. 要, 希望, 必须 vt. 缺少, 渴望, 喜欢, 应该","	 	n. 方法,道路,方向,作风,(某)方面,程度,状态 adv. 非常,很多,很远 adj. 与路线的中间点相关的,路线的中间点","n. 看, 神色, 样子, 脸色 vi. 看, 注意, 朝着, 好象, 显得 vt. 打量, 注视, 用眼神或脸色表示, 期待","adv. 首先,第一,优先 adj. 第一的, 最早的, 一流的 n. (序数词)第一, 第一个人或事物, (大学学位的)最优等, (汽车, 自行车等的)最低挡","adv. 也, 同样地, 而且","adj. 新的,附加的 adv. 新的","conj. 因为","n. 白天,一天","n. 运用,用法,使用权,适用 vt. 使用,利用,对待 vi. 吸毒","n. 不, 拒绝, 否决票 adj. 没有, 不是, 绝非 adv. 不","n. 男人,人类,人 vt. 为...配备人手,使...振奋","vt. &vi. 发现,感觉到,认为 n. 发现物","adv.在这里； 这时； 在这一点上； （给某人东西或指出某物时说） n.这里 int.喂； 嗨","n. 东西, 事情","vt.& vi.给予； 赠送； 作出 vt.供给； 产生； 举办； （为购买某物或做某事而）支付 vi.（物体）塌下； 让步 n.伸展性，弹性","n. 许多人,许多 adj. 许多的 pron. 许多人或物","n. 井,源泉,楼梯井 adj. 健康的,良好的,适宜的 adv. 很好地,适当地 vi. 涌出 interj. 好吧,啊","adj. 最好的,唯一的,出众的 adv. 仅仅,只有,专门地,唯一地,刚才 conj. 除非, 但是, 然而, 毕竟","pron.&amp;adj. 那些","vt. 告诉,说,知道,认出,计数 vi. 讲述,告发,作证,产生效果","adj. 真正的,完全的,自己的,仅仅的,同一个,特别的 adv. 真的,非常"," 	adj. 平坦的, 偶数的, 相等的 adv. 甚至, 恰好, 正当 v. 使平坦, 相等","adj. 后面的，偏远的, 过时的, 积欠的, 向后的 adv. 向后地 n. 后背, 背脊，后面, 靠背 vt. 后退，支持 vi. 后退","adj. 任何的 adv. 稍 det. 一些 prep. 无论哪个 pron. 任何","n. 善行,好处 adj. 好的,优良的,上等的 [pl.]商品","n. 妇女, 女人","adv. 穿越, 完全 prep. 经过, 穿过, 凭借 adj. 完成的, 完结的; 贯穿的, 直通的","pron. 我们(we的宾格)"," 	n. 生活, 生命, 人生, 生物, 寿命,灵魂, 无期(徒刑) adj. 活的,终身的,生动的","n.小孩，孩子； 幼稚的人； 产物； 弟子","n. 工作,作用,成果,作品,善行,工艺,奏效,建筑工程,工厂,(机械)活动部件 adj. 工作的 vi. 创造, 实现, 有工作, 起作用, 操作, 正常运转, 成功, 产生影响, 逐渐进行, 处理 vt. 造成, 产生, 使运转, 锻造, 奋力达到, 利用","adj. 向下的,降低的,情绪低落,停止运行 adv. 向下的,下跌,在南方 n. 绒毛,汗毛,轻视 prep. 沿着...而下","n. 五月, 青春 v. aux.可能,可以,祝愿" };
//
//int isExist(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void search(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void insert(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void change(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void logicDelete(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void menu();
//
////了解使用的三个新的函数：strcmp strcpy和memset
//int main() {
//	int choice = 0;
//	printf("Welcome!\n");
//	while (1) {
//		menu();
//		printf("Please input your choice\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			search(words, chinese, size, word);
//			break;
//		case 2:
//			insert(words, chinese, size, word);
//			size++;
//			break;
//		case 3:
//			change(words, chinese, size, word);
//			break;
//		case 4:
//			logicDelete(words, chinese, size, word);
//			break;
//		case 5:
//			return 0;
//		default:
//			printf("Wrong input!\n");
//			continue;
//		}
//	}
//}
//
//void menu() {
//	printf("------------------\n");
//	printf("\t1.Search words\n");
//	printf("\t2.Add vocabulary\n");
//	printf("\t3.Change meaning\n");
//	printf("\t4.Delete\n");
//	printf("\t5.Exit\n");
//}
//
//int isExist(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word) {
//	for (int i = 0; i < MAX_SIZE; i++) {
//		if (strcmp(words[i], word) == 0 && dirty[i] != 1) {
//			printf("Word:\t%s\nChinese:\t%s\n", word, chinese[i]);
//			return i;
//		}
//	}
//	return NOT_EXIST;
//}
//
//void search(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word) {
//	printf("Please input the word\n");
//	scanf("%s", word);
//	if (isExist(words, chinese, size, word) == NOT_EXIST)
//		printf("The word isn't in dictionary!\n");
//	memset(word, 0, 20);
//}
//
//void insert(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word) {
//	printf("Please input the word\n");
//	scanf("%s", word);
//	if (isExist(words, chinese, size, word) == NOT_EXIST) {
//		strcpy(words[size + 1], word);
//		printf("Please input translation:\n");
//		scanf("%s", chinese[size + 1]);
//		printf("Add success!\n");
//	}
//	else {
//		printf("The word is already exist!\n");
//	}
//	memset(word, 0, 20);
//}
//
//void change(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word) {
//	printf("Please input the word for change:\n");
//	scanf("%s", word);
//	e = isExist(words, chinese, size, word);
//	if (e == NOT_EXIST)
//		printf("The word not exists,you can add it again!\n");
//	else {
//		strcpy(words[e], word);
//		printf("Please input translation:\n");
//		scanf("%s", chinese[e]);
//		printf("Change success!\n");
//	}
//	memset(word, 0, 20);
//}
//
//void logicDelete(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word) {
//	printf("Please input the word for delete:\n");
//	scanf("%s", word);
//	e = isExist(words, chinese, size, word);
//	if (e == NOT_EXIST)
//		printf("The word not exists,you can not delete it!\n");
//	else {
//		dirty[e] = 1;
//		printf("Delete success!\n");
//	}
//	memset(word, 0, 20);
//}


////8 6 4 2 10 9 7 5 3 1
//int odd_count = 0;
//void classify(int* arr, int size);
//void sortArr(int* arr, int size);
//void sort(int* arr, int start, int end);
//void printArr(int* arr, int size);
//
//int main()
//{
//	int arr[100] = { 0 };
//	printf("Input 10 numbers for sorting...\n");
//	int size = 0;
//	int choice = 0;
//	for (int i = 0; i < 10; ++i) {
//		scanf("%d", &arr[i]);
//		size++;
//	}
//	classify(arr, 10);
//	sortArr(arr, size);
//	printArr(arr, size);
//
//	while (1) {
//		printf("choose 1 for continue,0 for exit\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("Add new number:\n");
//			scanf("%d", &arr[size++]);
//			classify(arr, size);
//			sortArr(arr, size);
//			printArr(arr, size);
//			break;
//		case 0:
//			return 0;
//		}
//	}
//}
//
//void classify(int* arr, int size) {
//	int begin = 0, end = size;
//	int temp = 0;
//	while (begin < end) {
//		while (arr[begin] % 2 == 1) {
//			begin++;
//			odd_count++;
//		}
//		while (arr[end] % 2 == 0) {
//			end--;
//		}
//		if (begin < end) {
//			temp = arr[begin];
//			arr[begin] = arr[end];
//			arr[end] = temp;
//		}
//	}
//}
//
//void sort(int* arr, int start, int end) {
//	int temp = 0;
//	for (int i = start; i < end; ++i) {
//		for (int j = start; j < end - 1; ++j) {
//			if (arr[j] > arr[j + 1]) {
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void printArr(int* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void sortArr(int* arr, int size) {
//	sort(arr, 0, odd_count);
//	sort(arr, odd_count, size);
//	odd_count = 0;
//}


//int main() {
//	int i, num, m = 0, seize = 1, pd = 0, p = 10;//定义一些整形变量
//	float all = 0;//定义总和
//	char pFood[256];//定义要输入食品名称字符串
//	char food[50][999] = { "牛奶", "面包", "方便面", "矿泉水", "火腿肠", "溜溜梅", "薄荷糖", "豆腐干", "辣条", "纸巾", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
//	float price[] = { 3, 2, 5, 1, 1.5, 5, 10, 1, 0.5, 1 };
//	//定义食品清单
//	char* book[256] = { "" };//定义购买的字符串数组
//	int num1[256] = { 0 };//定义重复购买数量数组
//	float price1[256] = { 0 };//定义重复购买单价数组
//BEGIN://开始
//	printf("****菜单****\n食品名称   单价（元）\n");
//	for (i = 0; i < p; i++)
//		printf("  %s·······%.2f\n", food[i], price[i]);//菜单遍历
//	printf("输入格式:食品名称 数量\n(结算按1 1)\n");
//	do {
//		pd = 0;//初始化判定
//		scanf("%s %d", &pFood, &num);//输入要买的食品和数量
//		if (strcmp(pFood, "1") == 0 && num == 1)
//			goto COUNT;//如果输入1 1则进入小票结算系统
//		for (i = 0; i < p; i++) {
//			if (strcmp(pFood, food[i]) == 0) {
//				pd = 1;//如果输入的食品在菜单中则判定为真
//				break;
//			}
//		}
//		if (pd != 1) {//输入食品在菜单中不存在
//			strcpy(food[p], pFood);//拷贝输入的食品到菜单中
//			printf("这是一个新事物,说出价格让我死心:>\n(输入完价格后请重新输入一遍需要购买的新食品和数量)\n");
//			scanf("%f", &price[p]);//输入价钱
//			p++;//下标右移
//			goto BEGIN;//回到梦开始的地方
//
//		}
//		for (i = 0; i < m; i++) {//遍历
//			if (strcmp(pFood, food[i]) == 0) {//如果新输入的食品和前面输入的有重复
//				num1[i] += num;//在前一次基础上加上这次数量
//				all += price[i] * num;//总价也加上
//				goto PT;//进入单次结算
//			}
//		}
//		if (strcmp(pFood, "1") == 0 && num == 1) {//进入小票结算
//		COUNT:
//			printf("小票如下:\n商品名   单价    数量\n");
//			for (m = 0; m < seize - 1; m++) {//遍历
//				printf("%s     %.2f      %d\n", book[m], price1[m], num1[m]);
//			}
//			printf("-----------------------\n总价:    %.2f", all);//输出总价
//			break;
//		}
//		else {//输入的食品为菜单上现有的
//			for (i = 0; i < p; i++) {//遍历
//				if (strcmp(pFood, food[i]) == 0) {//找到价钱对应食品下标
//					book[m] = food[i];//替换进入购买食品数组
//					num1[m] = num;//替换进入购买数量数组
//					price1[m] = price[i];//替换进入购买单价数组
//					m++;//下标加
//					seize++;//种类加
//					all += price[i] * num;//求总和
//					break;
//				}
//			}
//		PT:
//			printf("总价:%.2f\n", all);
//			printf("你还要啥\n");
//			goto BEGIN;//回到梦开始的地方
//		}
//	} while (1);//无限循环
//	return 0;
//}



//int main() {
//	int i, n = 0, j = 50;//定义j=50，使新单词加到词典数组后面
//	int pd, pd2;//判定是否进入程序
//	char nword[256], nmean[256];//定义输入的单词和意思
//	char word[][256] = { "just", "see", "him", "your", "come", "persistent", "now", "than", "like", "other", "how", "then", "its", "our", "two", "more", "these", "want", "way", "look", "first", "also", "new", "because", "day", "use", "no", "man", "find", "here", "thing", "give", "many", "well", "only", "those", "tell", "very", "even", "back", "any", "good", "woman", "through", "us", "life", "child", "work", "down", "may", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
//	//参考了CSDN字符串数组如何定义，一开始用的指针，后来舍弃改用二维数组
//	char mean[][256] = { "adj. 公正的,公平的,恰当的 adv. 正好,恰好", "vt. 看见,经历,明白,确保,视为,拜访,陪同 vi. 注意,想象,了解,调查 n. 主教教区,主角权限", "pron. 他(宾格)", "pron. 你的, 你们的", "vt. 接近，扮演 vi. 来，发生，达到，进入", "adj.执着的；不屈不挠的；坚持不懈的；连绵的", "n. 现在,此刻 adj. 现存的, 目前的 adv. 现在,立刻 conj. 既然 abbr. =National Organization of Women 全国妇女组织", "conj.比（用于比较级）； 宁愿…而不愿； 除…以外； 一…就 prep.超过； 比", "adj. 相似的,同样的 vt. &vi. 喜欢,愿意,想 prep. 像,如同 n. 爱好,类似的人（或物） adv. 大概,和…一样 conj. 如同", "adj. 别的,其他的 pron. 另一个人(或事) n. 其他人(或事)", " 	adv. 如何,怎样,多么,多少 conj. 如何,怎样,以...方式 n. 方式", "adv. 那么, 当时，然后，于是 adj. 当时的", "pron.（it的所有格)它的", "pron. 我们的", "num. 二，两个", "adv.更，更多； 达到或处于更大的范围或程度； 此外，更加 adj.更多的； (many)的比较级； 附加的，额外的 pron.更多的或附加的人或事物 n.更多； 附加，添加", "adj.&pron. 这些", "n. 缺乏, 贫困, 欲望, 需要, 不足 vi. 要, 希望, 必须 vt. 缺少, 渴望, 喜欢, 应该", "	 	n. 方法,道路,方向,作风,(某)方面,程度,状态 adv. 非常,很多,很远 adj. 与路线的中间点相关的,路线的中间点", "n. 看, 神色, 样子, 脸色 vi. 看, 注意, 朝着, 好象, 显得 vt. 打量, 注视, 用眼神或脸色表示, 期待", "adv. 首先,第一,优先 adj. 第一的, 最早的, 一流的 n. (序数词)第一, 第一个人或事物, (大学学位的)最优等, (汽车, 自行车等的)最低挡", "adv. 也, 同样地, 而且", "adj. 新的,附加的 adv. 新的", "conj. 因为", "n. 白天,一天", "n. 运用,用法,使用权,适用 vt. 使用,利用,对待 vi. 吸毒", "n. 不, 拒绝, 否决票 adj. 没有, 不是, 绝非 adv. 不", "n. 男人,人类,人 vt. 为...配备人手,使...振奋", "vt. &vi. 发现,感觉到,认为 n. 发现物", "adv.在这里； 这时； 在这一点上； （给某人东西或指出某物时说） n.这里 int.喂； 嗨", "n. 东西, 事情", "vt.& vi.给予； 赠送； 作出 vt.供给； 产生； 举办； （为购买某物或做某事而）支付 vi.（物体）塌下； 让步 n.伸展性，弹性", "n. 许多人,许多 adj. 许多的 pron. 许多人或物", "n. 井,源泉,楼梯井 adj. 健康的,良好的,适宜的 adv. 很好地,适当地 vi. 涌出 interj. 好吧,啊", "adj. 最好的,唯一的,出众的 adv. 仅仅,只有,专门地,唯一地,刚才 conj. 除非, 但是, 然而, 毕竟", "pron.&amp;adj. 那些", "vt. 告诉,说,知道,认出,计数 vi. 讲述,告发,作证,产生效果", "adj. 真正的,完全的,自己的,仅仅的,同一个,特别的 adv. 真的,非常", " 	adj. 平坦的, 偶数的, 相等的 adv. 甚至, 恰好, 正当 v. 使平坦, 相等", "adj. 后面的，偏远的, 过时的, 积欠的, 向后的 adv. 向后地 n. 后背, 背脊，后面, 靠背 vt. 后退，支持 vi. 后退", "adj. 任何的 adv. 稍 det. 一些 prep. 无论哪个 pron. 任何", "n. 善行,好处 adj. 好的,优良的,上等的 [pl.]商品", "n. 妇女, 女人", "adv. 穿越, 完全 prep. 经过, 穿过, 凭借 adj. 完成的, 完结的; 贯穿的, 直通的", "pron. 我们(we的宾格)", " 	n. 生活, 生命, 人生, 生物, 寿命,灵魂, 无期(徒刑) adj. 活的,终身的,生动的", "n.小孩，孩子； 幼稚的人； 产物； 弟子", "n. 工作,作用,成果,作品,善行,工艺,奏效,建筑工程,工厂,(机械)活动部件 adj. 工作的 vi. 创造, 实现, 有工作, 起作用, 操作, 正常运转, 成功, 产生影响, 逐渐进行, 处理 vt. 造成, 产生, 使运转, 锻造, 奋力达到, 利用", "adj. 向下的,降低的,情绪低落,停止运行 adv. 向下的,下跌,在南方 n. 绒毛,汗毛,轻视 prep. 沿着...而下", "n. 五月, 青春 v. aux.可能,可以,祝愿", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
//	printf("扣1开卷，扣0摆烂\n");
//	scanf("%d", &pd);//输入1或者0
//	if (pd == 1) {//开卷
//		do {
//		START:n = 0;//初始化n
//			printf("请输入英文单词(按0摆烂):>");
//			scanf("%s", &nword);//输入单词
//			if (strcmp(nword, "0") == 0) {//摆烂
//				printf("恭喜你度过摆烂的一生\n");
//				break;//跳到return 0（应该）
//			}
//			for (i = 0; i < j; i++) {//遍历
//				if (strcmp(nword, word[i]) == 0) {//在词典中找到了
//					printf("该单词意思为:>");
//					printf("%s\n", mean[i]);//下标对应
//					n = 1;//改变n值以便跳过新单词判定
//					break;//跳到do(应该)
//				}
//			}
//			if (n != 1) {//进入新单词判定
//			RESTART://又是一个新单词
//				printf("这是一个新单词，是否想添加到词典中呢，想加扣666,不想加扣1,想摆扣0\n");
//				scanf("%d", &pd2);//判定2
//				if (pd2 == 666)//想加新单词了
//				{
//					strcpy(word[j], nword);//将新单词加到原词典后面
//					printf("请告诉我它的意思\n");
//					scanf("%s", &nmean);//输入新单词的意思
//					strcpy(mean[j], nmean);//将意思加到原词典对应意思数组后面，且下标对应
//					printf("请输入英文单词:>");
//					scanf("%s", &nword);//再次输入新的英文单词
//					for (i = 0; i < j + 1; i++) {//遍历更新的词典，这个j+1是试出来的，原理不是很懂
//						if (strcmp(nword, word[i]) == 0) {
//							printf("该单词意思为:>");
//							printf("%s\n", mean[i]);
//							n = 1;//改变n值，防止输入的单词仍然是新单词从而判定
//							j++;//找到后使下一个要加入进来的单词和意思在词典下标右移
//							break;
//						}
//					}
//					if (n != 1) {
//						j++;//找到后使下一个要加入进来的单词和意思在词典下标右移
//						goto RESTART;//从新词语判定后开始
//					}
//				}
//				if (pd2 == 1)//单词太简单了，不是很想加
//					goto START;
//				if (pd2 == 0)//开摆
//					goto END;
//			}
//		} while (1);//无限循环
//	}
//	else if (pd == 0) {//开始摆烂
//	END:printf("恭喜你度过摆烂的一生\n");
//	}
//	return 0;
//}


//int main()
//{
//	int a, b;
//	int x;
//	float y;
//	double c;
//	y = 1.123456789f;
//	c = 1.123456789l;
//	char z;
//	/*scanf("%d,%d", &a, &b);*/
//	//scanf("%2d%*2d%2d", &a, &b);//%*2d可以不存放,但在输入时仍然要输入三个数字
//	//printf("%d %d\n", a, b);
//	printf("%f %lf\n", y, c);
//	x = -7;
//	y = 56.66;
//	z = 'A';
//	//printf("Value is:%-10.4f", 32.6784728);
//	//printf("%d %f %c", x, y, z);
//	return 0;
//}


//int main()
//{
//	int math[11] = { 0 };
//	int i, j;
//	int pd1, pd2;
//	int newNum;
//	printf("用户输入样例:>(输完一个数记得按回车)");
//	for (i = 0; i < 10; i++)
//		printf("%d\n", i);
//	do
//	{
//		printf("\n\n想玩按1,不想玩按0\n");
//		scanf("%d", &pd1);
//		if (pd1 == 1)
//		{
//			printf("请自行输入:>\n");
//			for (i = 0; i < 10; i++)
//			{
//				scanf("%d", &math[i]);
//			}
//			for (i = 9; i >= 0; i--)
//			{
//				for (j = 0; j < i; j++)
//				{
//					int tmp;
//					if (math[j] > math[j + 1])
//					{
//						tmp = math[j + 1];
//						math[j + 1] = math[j];
//						math[j] = tmp;
//					}
//				}
//			}
//			printf("输出:>");
//			for (j = 0; j < 10; j++)
//			{
//				if (math[j] % 2 != 0)
//					printf("%d ", math[j]);
//			}
//			for (j = 0; j < 10; j++)
//			{
//				if (math[j] % 2 == 0)
//					printf("%d ", math[j]);
//			}
//			printf("\n想玩新花样吗，加一个数吧，想加按666，不想加按1，退出按0\n");
//			scanf("%d", &pd2);
//			if (pd2 == 666)
//			{
//				printf("请输入一个新数:>");
//				scanf("%d", &math[10]);
//				for (i = 10; i >= 0; i--)
//				{
//					for (j = 0; j < i; j++)
//					{
//						int tmp;
//						if (math[j] > math[j + 1])
//						{
//							tmp = math[j + 1];
//							math[j + 1] = math[j];
//							math[j] = tmp;
//						}
//					}
//				}
//				printf("输出:>");
//				for (j = 0; j < 11; j++)
//				{
//					if (math[j] % 2 != 0)
//						printf("%d ", math[j]);
//				}
//				for (j = 0; j < 11; j++)
//				{
//					if (math[j] % 2 == 0)
//						printf("%d ", math[j]);
//				}
//
//			}
//			else if (pd2 == 0)
//			{
//				break;
//			}
//		}
//		else if (pd1 == 0)
//		{
//			break;
//		}
//	} while (1);
//	return 0;
//}


//int main()
//{
//	int grade[4][3] = { 82,77,76,90,59,56,87,48,75,86,86,66 };
//	int i, j;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			if (grade[i][j] < 60)
//			{
//				printf("第%d个同学不及格\n", i + 1);
//				continue;
//			}
//		}
//	}
//	return 0;
//}


////优化方法参考  https://zhidao.baidu.com/question/372052575.html
////经此方法复杂度大约少了一个数量级！！！
////原理大概是我之前直接用遍历的数字和1后面好几个0取余浪费时间，这种算法将位数逐渐缩小，减少了计算时间 
////amazing!
//int main() {
//	long long start, end;
//	printf("请输入数字范围(1-100)：");
//	scanf("%lld-%lld", &start, &end);
//	printf("请输入特征数和个数(8 3)：");
//	int feature, target_count;
//	scanf("%d %d", &feature, &target_count);
//	long long i, count = 0;
//	//遍历从start到end所有数
//	for (i = start; i <= end; i++) {
//		long long  tmp = i;
//		//定义内部计数器
//		long long inner_count = 0;
//		//第几位
//		int j = 0;
//		//遍历每一位
//		int n;
//		n = tmp % 10;
//		//n>0的条件是错误的，会提前结束循环 
//		while (tmp > 0)
//		{
//			if (n == feature) inner_count++;
//			tmp = (tmp - n) / 10;
//			n = tmp % 10;
//		}
//		if (inner_count == target_count) {
//			printf("%lld ", i);
//			count++;
//		}
//	}
//	printf("\n总计%lld个\n", count);
//	return 0;
//}


////优化方法灵感来自题目《大数字的竖式运算》！ 
////此方法的效率不必多说！ 
////原理是数组！计算机不喜欢十进制，so总是%10、/10的他会很难受 
////但是速度只比不带plus的版本快了一倍 
////amazing!
//
////329:  {9,2,3,-1}
////329+1=330: {0,3,3,-1}
////999: {9,9,9,-1}
////999+1=1000: {0,0,0,1,-1} 
//int list_add_one(int num_arr[]) {
//	int i;
//	for (i = 0; num_arr[i] != -1; i++) {
//		int tmp;
//		if (i == 0) {
//			num_arr[i]++;
//		}
//		if (num_arr[i] == 10) {
//			num_arr[i] = 0;
//			//判断是否为结束标识符 
//			if (num_arr[i + 1] == -1) {
//				num_arr[i + 2] = -1;
//				num_arr[i + 1] = 1;
//			}
//			else {
//				num_arr[i + 1]++;
//			}
//		}
//	}
//	return 0;
//}
//
//int main() {
//	//数组num_arr其实就是倒序数字
//	int num_arr[256] = { 0,-1 };
//	long long start, end;
//	printf("请输入数字范围(1-100)：");
//	scanf("%lld-%lld", &start, &end);
//	printf("请输入特征数和个数(8 3)：");
//	int feature, target_count;
//	scanf("%d %d", &feature, &target_count);
//	long long i, count = 0;
//	//使数组自增到start 
//	int* a = &num_arr[0];
//	for (i = 0; i < start; i++) {
//		list_add_one(a);
//	}
//	//遍历从start到end所有数
//	for (i = start; i <= end; i++) {
//		int j;
//		int inner_count = 0;
//		//从个位开始，遍历数组每一位 
//		for (j = 0; num_arr[j] != -1; j++) {
//			if (num_arr[j] == feature) {
//				inner_count++;
//			}
//		}
//		//判断count条件，然后输出 
//		if (inner_count == target_count) {
//			count++;
//			for (j--; j >= 0; j--) {
//				printf("%d", num_arr[j]);
//			}
//			printf(" ");
//		}
//		//数组自增 
//		int* p = &num_arr[0];
//		list_add_one(p);
//	}
//	printf("\n总计%lld个\n", count);
//	return 0;
//}



////三个版本中的初始版本，也是最慢的版本 
//int main() {
//	long long start, end;
//	printf("请输入数字范围(1-100)：");
//	scanf("%lld-%lld", &start, &end);
//	printf("请输入特征数和个数(8 3)：");
//	int feature, target_count;
//	scanf("%d %d", &feature, &target_count);
//	long long i, count = 0;
//	//遍历从start到end所有数
//	for (i = start; i <= end; i++) {
//		int tmp;
//		//遍历每一位
//		long long j, inner_count = 0;
//		for (j = 1; i / j > 0; j *= 10) {
//			if (i / j % 10 == feature) inner_count++;
//		}
//		if (inner_count == target_count) {
//			printf("%lld ", i);
//			count++;
//		}
//	}
//	printf("\n总计%lld个\n", count);
//	return 0;
//}



//int main()
//{
//	double arr[] = { 1.78, 1.77, 1.82, 1.79, 1.85, 1.75, 1.86, 1.77, 1.81, 1.80 };
//	int i, j;
//	printf("\n************排队前*************\n");
//	for (i = 0; i < 10; i++)
//	{
//		if (i != 9)
//			printf("%.2f, ", arr[i]);  //%.2f表示小数点后精确到两位
//		else
//			printf("%.2f", arr[i]);    //%.2f表示小数点后精确到两位
//	}
//	for (i = 8; i >= 0; i--)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (arr[j] > arr[j + 1])      //当前面的数比后面的数大时
//			{
//				double temp;    //定义临时变量temp
//				temp = arr[j];   //将前面的数赋值给temp
//				arr[j] = arr[j + 1];     //前后之数颠倒位置
//				arr[j + 1] = temp; //将较大的数放在后面    
//			}
//		}
//	}
//	printf("\n************排队后*************\n");
//	for (i = 0; i < 10; i++)
//	{
//		if (i != 9)
//			printf("%.2f, ", arr[i]);  //%.2f表示小数点后精确到两位     
//		else
//			printf("%.2f", arr[i]);    //%.2f表示小数点后精确到两位
//	}
//	return 0;
//}

//int d()
//{
//	int score[10] = { 67,98,75,63,82,79,81,91,66,84 };
//	int x, y, z;
//	for (x = 0; x < 9; x++)
//	{
//		for (y = 0; y < 9 - x; y++)
//			if (score[y] > score[y + 1])
//			{
//				z = score[y];
//				score[y] = score[y + 1];
//				score[y + 1] = z;
//			}
//	}
//	printf("考试成绩降序如下:\n");
//	for (y = 0; y < 10; y++)
//	{
//		printf("%d ", score[y]);
//	}
//	printf("\n\n");
//	return 0;
//
//}
//
//int main()
//{
//	int i, sum = 0, max, min, m, x, y, z;
//	int score[10] = { 67,98,75,63,82,79,81,91,66,84 };
//	for (i = 0; i < 10; i++)
//	{
//		sum += score[i];
//		if (score[i] > score[i + 1])
//		{
//			max = score[i];
//		}
//		if (score[i] < score[i + 1])
//		{
//			min = score[i];
//		}
//	}
//	for (m = 9; m >= 0; m--)
//	{
//		for (i = 0; i < 9; i++)
//		{
//			if (score[i] > score[i + 1])
//			{
//				int temp;
//				temp = score[i];
//				score[i] = score[i + 1];
//				score[i + 1] = temp;
//			}
//		}
//	}
//	/*for (x = 0; x < 9; x++)
//	{
//		for (y = 0; y < 9 - x; y++)
//			if (score[y] > score[y + 1])
//			{
//				z = score[y];
//				score[y] = score[y + 1];
//				score[y + 1] = z;
//			}
//	}*/
//	printf("总分:%d\n", sum);
//	printf("最高分:%d\n", max);
//	printf("最低分:%d\n", min);
//	printf("平均分:%.1f\n", sum / 10.0);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", score[i]);
//	}
//	d();
//
//	return 0;
//}


/* 定义say函数 */
//void say(char string[])       //数组参数应该怎么写呢？
//{
//	printf("%s\n", string);    //打印字符串
//}
//
//int main()
//{
//	//定义字符串数组
//	char string[] = "我在慕课网上学习IT技能！";
//	say(string);                 //调用say函数输出字符串
//	return 0;
//}

//

//
//int getIndex(int arr[5], int value)
//{
//	int i;
//	int index;
//	for (i = 0; i < 5; i++)
//	{
//		/* 请完善数组查询功能 */
//		if (arr[i] == value)
//		{
//			index = i;
//			break;
//		}
//	}
//	if (index != i)
//		index = -1;
//	
//	return index;
//}
//
//int main()
//{
//	int arr[5] = { 3,12,9,8,6 };
//	int value = 8;
//	int index = getIndex(arr, 8);      //这里应该传什么参数呢？
//	if (index != -1)
//	{
//		printf("%d在数组中存在，下标为：%d\n", value, index);
//	}
//	else
//	{
//		printf("%d在数组中不存在。\n", value);
//	}
//	return 0;
//}


//int main()
//{
//	int a[8] = { 80,90,85,84,70,76,75,83 };
//	int i, max = 0, min = 100;
//	for (i = 0; i < 8; i++)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//		else if (a[i] < min)
//		{
//			min = a[i];
//		}
//	}
//	printf("最高分为:%d 最低分为:%d", max, min);
//	return 0;
//}


//void replaceMax(int arr[], int value)
//{
//	int max = arr[0];
//	int index = 0;
//	int i;
//	for (i = 1; i < 5; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];//将数组中较大的数赋值给max
//			index = i;//记录当前索引
//		}
//	}
//	arr[index] = value;
//}
//
//int main()
//{
//	int arr1[] = { 10,41,3,12,22 };
//	int arr2[] = { 1,2,3,4,5 };
//	int i;
//	replaceMax(arr1, arr2[0]); //将数组arr1和数组arr2的第一个元素传入函数中
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}


//int main()
//{
//	printf("%f",13 + 2.3 * 9 + 1);
//	return 0;
//}


////读入一个年份和月份，打印出该月有多少天（考虑闰年），用switch语句编程实现。
//int main()
//{
//	int year, month, day = 0;
//	scanf("%d %d", &year, &month);
//	switch (month)
//	{
//	case 12:
//		day += 31;
//		break;
//	case 11:
//		day += 30;
//		break;
//	case 10:
//		day += 31;
//		break;
//	case 9:
//		day += 30;
//		break;
//	case 8:
//		day += 31;
//		break;
//	case 7:
//		day += 31;
//		break;
//	case 6:
//		day += 30;
//		break;
//	case 5:
//		day += 31;
//		break;
//	case 4:
//		day += 30;
//		break;
//	case 3:
//		day += 31;
//		break;
//	case 2:
//		if (year % 4 == 0 && year % 100 != 0)
//		{
//			day += 29;
//		}
//		else if (year % 400 == 0)
//		{
//			day += 29;
//		}
//		else
//		{
//			day += 28;
//		}
//		break;
//	case 1:
//		day += 31;
//		break;
//	}
//	printf("%d", day);
//	return 0;
//}


//5、在屏幕上显示一张如下所示的时间表：
//* ****Time * ****
//1  morning
//2  afternoon
//3  night
//Please enter your choice :
//操作人员根据提示进行选择，程序根据输入的时间序号显示相应的问候信息，选择1时显示"Good morning"， 选择2时显示"Good afternoon"， 选择3时显示"Good night"，对于其他选择显示"Selection error!"，用switch语句编程实现。

//int main()
//{
//	int a;
//	printf("****Time****\n");
//	scanf("%d", &a);
//	switch (a)
//	{
//	case 1:
//		printf("Good morning\n");
//		break;
//	case 2:
//		printf("Good afternoon");
//		break;
//	case 3:
//		printf("Good night");
//		break;
//	default:
//		printf("Selection error!");
//
//	}
//	return 0;
//}


//4、输入三角形的三条边a，b，c，判断它们能否构成三角形。若能构成三角形，指出是何种三角形（等腰三角形、直角三角形、一般三角形）。
//int main()
//{
//	int a, b, c;
//	scanf("%d,%d,%d", &a, &b, &c);
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		if (a == b || a == c || b == c)
//			printf("等腰");
//		if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
//			printf("直角");
//		else
//			printf("一般");
//	}
//	else
//		printf("不构成");
//	printf("三角形\n");
//	return 0;
//}


//int main()
//{
//	int x;
//	scanf("%d", &x);
//	if (x > 0)
//		printf("e^(-%d)", x);
//	else if (x == 0)
//		printf("1");
//	else if (x < 0)
//		printf("-e^(%d)", x);
//	return 0;
//}


//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (a % 2 == 0)
//		printf("偶数且为");
//	else if (a % 2 != 0)
//		printf("奇数且为");
//	if (a > 0)
//		printf("正数\n");
//	else if (a < 0)
//		printf("负数\n");
//}


////通过键盘输入一个字符，判断该字符是数字字符、大写字母、小写字母、空格还是其他字符。
//int main()
//{
//	char pt;
//	pt = getchar();
//	//printf("%d\n", pt);
//	if (pt >= 48 && pt <= 57)
//	{
//		printf("数字字符\n");
//	}
//	else if (pt >= 41 && pt <= 90)
//	{
//		printf("大写字母\n");
//	}
//	else if (pt >= 97 && pt <= 122)
//	{
//		printf("小写字母\n");
//	}
//	else if (pt == 32)
//	{
//		printf("空格\n");
//	}
//	else
//	{
//		printf("其他字符\n");
//	}
//	return 0;
//}


//从键盘任意输入一个年号，判断它是否是闰年。若是闰年，输出“Yes”，否则输出“No”。已知符合下列条件之一者是闰年：
//■能被4整除，但不能被100整除。
//■能被400整除。
//int main()
//{
//	int year;
//	printf("请输入年号:>");
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0)
//	{
//		printf("该年是闰年\n");
//	}
//	else if (year % 400 == 0)
//	{
//		printf("该年是闰年\n");
//	}
//	else
//	{
//		printf("该年不是闰年\n");
//	}
//	return 0;
//}


/*
 * 请使用递归函数完成本题
 * 小编已将正确代码放在左侧任务的“不知道怎么办”里
 * 小编希望各位童鞋独立完成哦~
 */
 //int count(int age)
 //{
 //	int sum;
 //	if (age == 5)
 //	{
 //		sum = 10;
 //	}
 //	else
 //	{
 //		sum = count(age + 1) + 2;
 //		age++;
 //	}
 //	return sum;
 //}
 //int main()
 //{
 //	int sum= count(1);
 //	
 //	printf("第5个人的年龄是%d岁", sum);
 //	return 0;
 //}


 //int main()
 //{
 //	int x, y;
 //	scanf(" % d, % d", &x, &y);
 //	if (x > y)
 //	{
 //		x = y; y = x;
 //	}
 //	else
 //	{
 //		x++; y++;
 //	}
 //	printf(" % d, % d", x, y);
 //}


 //int main() 
 //{
 //	float b;
 //	int d;
 //	scanf_s("%f %d", &b,&d);
 //	printf("%f %d", b,d);
 //	return 0;
 //}


 //int main() {
 //	srand((unsigned int)time(NULL));
 //	float m = 0 + rand() % 60;
 //	float n = 9 + rand() % 3;
 //	float a = n + m / 100;
 //	float b;
 //	int a1, b1, c, d, end, sum, sam;
 //	printf("公交车始发于%.2f\n", a);
 //	printf("请输入小明开始的时刻与站台 ");
 //	printf("用户输入:");
 //	scanf("%.2f", &b);
 //	scanf("%d", &d);
 //	a1 = a;
 //	b1 = b;
 //	if (b <= a) {
 //		c = a1 - b1;
 //		end = 60 * c + 100 * (a - b - c) + 20 * d;
 //	}
 //	else if (b > a) {
 //		c = b1 - a1;
 //		sum = 60 * c + 100 * (b - a - c);
 //		if (sum <= 20 * d)
 //			end = 20 * d - sum;
 //		else if (sum > 20 * d) {
 //			if (sum <= 70)
 //				end = 70 - sum + 20 * d;
 //			else if (sum > 70) {
 //				sam = sum - (sum / 70) * 70;
 //				if (sam <= 20 * d)
 //					end = 20 * d - sam;
 //				else
 //					end = 70 - sam + 20 * d;
 //			}
 //		}
 //	}
 //	printf("等待时间是%dmin\n", end);
 //	return 0;
 //}



 //int main()
 //{
 //	//srand((unsigned int)time(NULL));
 //	//int a = rand();
 //	int a;
 //	printf("%d", a);
 //	int random(int 10);
 //	return 0;
 //}


 //int main()
 //{
 //	srand((unsigned int)time(NULL));
 //	int a = rand() % 4 + 9;
 //	int b = rand() % 60;
 //	//int a = 10;
 //	//int b = 55;
 //	int h, m, n;
 //	int t;
 //	printf("公交车始发于%d:", a);
 //	if (a == 12)
 //	{
 //		printf("00\n");
 //	}
 //	else if (b < 10)
 //		printf("0%d\n", b);
 //	else if (b >= 10)
 //		printf("%d\n", b);
 //	
 //	printf("发车时间段为9:00-12:00,请不要输错哦\n");
 //	printf("请输入小明开始的时刻与站台\n");
 //	printf("样例输入:10.00 2\n");
 //	printf("用户输入:");
 //	scanf_s("%d.%d %d", &h, &m, &n);
 //	
 //	if (n == 1)
 //	{
 //		if ((a * 60 + b) >= 650 && ((h * 60 + m) - (a * 60 + b) > 20))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 580 && ((h * 60 + m) - (a * 60 + b) > 90))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 510 && ((h * 60 + m) - (a * 60 + b) > 160))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 440 && ((h * 60 + m) - (a * 60 + b) > 230))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 370 && ((h * 60 + m) - (a * 60 + b) > 300))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 300 && ((h * 60 + m) - (a * 60 + b) > 370))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if (h == a)
 //		{
 //			b += 20;
 //			if (m > b)
 //			{
 //				t = 70 - (m - b);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //			else
 //			{
 //				t = b - m;
 //				printf("等待时间是%dmin\n", t);
 //			}
 //		}
 //		else if (h == a + 1)
 //		{
 //			if ((h * 60 + m) - (a * 60 + b) < 20)
 //			{
 //				t = (h * 60 + m) - (a * 60 + b);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //			else
 //			{
 //				t = -((h * 60 + m) - (a * 60 + b)) + 90;
 //				printf("等待时间是%dmin\n", t);
 //			}
 //		}
 //		else if (h == a + 2)
 //		{
 //			if ((h * 60 + m) - (a * 60 + b) < 90)
 //			{
 //				t = (a * 60 + b) + 90 - (h * 60 + m);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //			else
 //			{
 //				t = (a * 60 + b) + 160 - (h * 60 + m);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //		}
 //		else if (h < a && a != 12)
 //		{
 //			t = -((h * 60 + m) - (a * 60 + b)) + 20;
 //			printf("等待时间是%dmin\n", t);
 //		}
 //		else if (h < a && a == 12)
 //		{
 //			t = 740 - (h * 60 + m);
 //			printf("等待时间是%dmin\n", t);
 //		}
 //	}
 //	else if (n == 2)
 //	{
 //		if ((a * 60 + b) >= 650 && ((h * 60 + m) - (a * 60 + b) > 40))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 580 && ((h * 60 + m) - (a * 60 + b) > 110))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 510 && ((h * 60 + m) - (a * 60 + b) > 180))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 440 && ((h * 60 + m) - (a * 60 + b) > 250))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 370 && ((h * 60 + m) - (a * 60 + b) > 320))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((a * 60 + b) >= 300 && ((h * 60 + m) - (a * 60 + b) > 390))
 //		{
 //			printf("坐不到车车\n");
 //		}
 //		else if ((h * 60 + m) <= (a * 60 + b) && a != 12)
 //		{
 //			t = -((h * 60 + m) - (a * 60 + b)) + 40;
 //			printf("等待时间是%dmin\n", t);
 //		}
 //		else if ((h * 60 + m) <= (a * 60 + b) && a == 12)
 //		{
 //			t = 760 - (h * 60 + m);
 //			printf("等待时间是%dmin\n", t);
 //		}
 //		else if ((h * 60 + m) > (a * 60 + b))
 //		{
 //			if ((h * 60 + m) - (a * 60 + b) <= 40)
 //			{
 //				t = (a * 60 + b) + 40 - (h * 60 + m);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //			else if ((h * 60 + m) - (a * 60 + b) <= 110)
 //			{
 //				t = (a * 60 + b) + 110 - (h * 60 + m);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //			else if ((h * 60 + m) - (a * 60 + b) <= 180)
 //			{
 //				t = (a * 60 + b) + 180 - (h * 60 + m);
 //				printf("等待时间是%dmin\n", t);
 //			}
 //		}
 //	}
 //	return 0;
 //}


 //int main()
 //{
 //	int a, b, sum;
 //	a = 123;
 //	b = 456;
 //	/*a = 1;
 //	b = 2;*/
 //	sum = a + b;
 //	printf("sum is %d\n", sum);
 //	return 0;
 //}


 //int main()
 //{
 //	printf("This is a C program.\n");
 //	return 0;
 //}


 //int  i, sum;
 //int main()
 //{
 //	
 //	ABC: srand((unsigned int)time(NULL));
 //	int a = rand() % 10 ;
 //	int b = rand() % 10 / 2;
 //	if (b > 4 || b < 1)
 //	{
 //		//printf("错误\n");
 //		goto ABC;
 //	}
 //	//printf("特征数为:");
 //	//scanf_s("%d", &a);
 //	//printf("特征数个数为:");
 //	//scanf_s("%d", &b);
 //	printf("特征数为:%d\n特征数个数为:%d\n", a, b);
 //	if (b > 4 || b < 1)
 //		printf("错误\n");
 //	else if (b == 4)
 //	{
 //		printf("%d%d%d%d,", a, a, a, a);
 //		sum++;
 //	}
 //	else if (b == 3)
 //	{
 //		for(i=1000;i<10000;i++)
 //		if (i / 1000 == a && i % 1000 / 100 == a && i % 100 / 10 == a && i % 10 != a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if(i / 1000 == a && i % 1000 / 100 == a && i % 100 / 10 != a && i % 10 == a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 == a && i % 1000 / 100 != a && i % 100 / 10 == a && i % 10 == a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 != a && i % 1000 / 100 == a && i % 100 / 10 == a && i % 10 == a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //	}
 //	else if (b == 2)
 //	{
 //		for (i = 1000; i < 10000; i++)
 //		if (i / 1000 == a && i % 1000 / 100 == a && i % 100 / 10 != a && i % 10 != a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 == a && i % 1000 / 100 != a && i % 100 / 10 == a && i % 10 != a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 != a && i % 1000 / 100 == a && i % 100 / 10 == a && i % 10 != a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 == a && i % 1000 / 100 != a && i % 100 / 10 != a && i % 10 == a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 != a && i % 1000 / 100 == a && i % 100 / 10 != a && i % 10 == a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //		else if (i / 1000 != a && i % 1000 / 100 != a && i % 100 / 10 == a && i % 10 == a)
 //		{
 //			printf("%d, ", i);
 //			sum++;
 //		}
 //	
 //	}
 //	else if (b == 1)
 //	{
 //		for (i = 1000; i < 10000; i++)
 //			if (i / 1000 == a && i % 1000 / 100 != a && i % 100 / 10 != a && i % 10 != a)
 //			{
 //				printf("%d, ", i);
 //				sum++;
 //			}
 //			else if (i / 1000 != a && i % 1000 / 100 == a && i % 100 / 10 != a && i % 10 != a)
 //			{
 //				printf("%d, ", i);
 //				sum++;
 //			}
 //			else if (i / 1000 != a && i % 1000 / 100 != a && i % 100 / 10 == a && i % 10 != a)
 //			{
 //				printf("%d, ", i);
 //				sum++;
 //			}
 //			else if (i / 1000 != a && i % 1000 / 100 != a && i % 100 / 10 != a && i % 10 == a)
 //			{
 //				printf("%d, ", i);
 //				sum++;
 //			}
 //	}
 //	printf("中奖个数为%d", sum);
 //	return 0;
 //}


 //int main()
 //{
 //	float a;
 //	do 
 //	{
 //		scanf_s("%f", &a);
 //		float b = a / 100;
 //		float c = b * 106.5;
 //		printf("%f", c);
 //	} while (a=100);
 //	return 0;
 //}


 //int getPeachNumber(n)
 //{
 //	int num;    //定义所剩桃子数
 //	if (n == 10)
 //	{
 //		num = 1;       //递归结束条件
 //	}
 //	else
 //	{
 //		num = getPeachNumber(n+1) * 2 + 2;  //这里是不应该用递归呢？
 //		printf("第%d天所剩桃子%d个\n", n, num); //天数，所剩桃子个数
 //		n++;
 //	}
 //	return num;
 //}
 //int main()
 //{
 //	int num = getPeachNumber(1);
 //	printf("猴子第一天摘了:%d个桃子。\n", num);
 //	return 0;
 //}


 ///* Jone算出结果应该怎么写函数？ */
 //int  joneResult(int x, int y, int z)
 //{
 //	int sum = x + y + z;
 //	return sum;//这里是不是应该将sum返回呢？
 //}
 ///* Jack没有算出结果只说了一句话是不是应该用无返回值函数？ */
 //void jackResult(int x, int y, int z)
 //{
 //	printf("我算不出来\n");
 //}
 //
 //int main()
 //{
 //	int a, b, c;
 //	a = 10;
 //	b = 20;
 //	c = 30;
 //	//Jone的返回值类型是什么？
 //	int jR = joneResult(a, b, c);
 //	printf("Jone运算结果是：%d\n", jR);
 //	printf("Jack运算结果是：");
 //	//Jack没有算出结果只说了句话，是不是直接调用函数就可以了？
 //	jackResult(a, b, c);
 //	return 0;
 //}


 //int xuexi()
 //{
 //	printf("小明在慕课网上学习\n");
 //}
 //
 //int clas(int i)
 //{
 //	printf("小明在慕课网上已经参与学习了%d门课程",i);
 //}
 //
 //int main()
 //{
 //	xuexi();
 //	clas(1);
 //	return 0;
 //}

 //int main()
 //{
 //    /* 定义需要计算的日期 */
 //    int year = 2008;
 //    int month = 8;
 //    int day = 8;
 //    /*
 //     * 请使用switch语句，if...else语句完成本题
 //     * 如有想看小编思路的，可以点击左侧任务中的“不会了怎么办”
 //     * 小编还是希望大家独立完成哦~
 //     */
 //    int days = 0;
 //    switch(month)
 //    {
 //    case 12:
 //        days += 31;
 //    case 11:
 //        days += 30;
 //    case 10:
 //        days += 31;
 //    case 9:
 //        days += 30;
 //    case 8:
 //        days += 31;
 //    case 7:
 //        days += 31;
 //    case 6:
 //        days += 30;
 //    case 5:
 //        days += 31;
 //    case 4:
 //        days += 30;
 //    case 3:
 //        days += 31;
 //    case 2:
 //        if (year % 4 == 0)
 //        {
 //            days += 29;
 //        }
 //        else
 //        {
 //            days += 28;
 //        }
 //    case 1:
 //        days += 31;
 //    }
 //    printf("%d", days + day);
 //    return 0;
 //}


 //int main()
 //{
 //	int i, j;
 //	for (i = 9; i >= 1; i--)
 //	{
 //		for (j = 1; j <= i; j++)
 //		{
 //			printf("%d*%d=%d ", i, j, j * i);
 //		}
 //		printf("\n");
 //	}
 //	return 0;
 //}


 //打印正三角形
 //int main()
 //{
 //	int i, j, k;
 //	for (i = 1; i < 5; i++)
 //		{
 //			/* 观察每行的空格数量，补全循环条件 */
 //			for (j = i; j < 5; j++)
 //			{
 //				printf(" ");    //输出空格
 //			}
 //			/* 观察每行*号的数量，补全循环条件 */
 //			for (k = 0; k < i * 2 - 1; k++)
 //			{
 //				printf("*");   //每行输出的*号
 //			}
 //			printf("\n");     //每次循环换行
 //		}
 //	return 0;
 //}


 //int main()
 //{
 //    /* 小伙伴们：
 //           选择你们认为最合理的循环结构完成功能吧 */
 //    int sum = 0;  //定义计算结果变量sum
 //    int i = 1;    //定义循环数字变量i
 //    int flag = 1; //定义符号状态变量flag
 //
 //    //使用while循环
 //  //  while (i <= 100)
 //  //  {
 //  //      i++;
 //		//flag = -flag;
 //  //      sum += flag * i;
 //  //  }
 //
 //    i = 1;  //重新初始化变量i
 //
 //    //do-while循环
 //  //  do {
 //  //      i++;
 //  //      flag = -flag;
 //		//sum += flag * i;
 //  //  } while (i <= 100);
 //
 //    i = 1;  //重新初始化变量i
 //
 //    //使用for循环
 //    for (i = 1; i <= 100; i++)
 //    {
 //		flag = -flag;
 //		sum += flag * i;
 //        
 //    }
 //    printf("sum=%d\n", -sum);
 //
 //    return 0;
 //}


 //int main()
 //{
 //	char c = 'a';
 //	int n = c;        //将c赋值给n
 //	float f = c;      //将c赋值给f
 //	double d = c;    //将c赋值给d
 //	printf("%d\n", n);
 //	printf("%f\n", f);
 //	printf("%lf\n", d);
 //	return 0;
 //}
