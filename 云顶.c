#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


//�����ṹ��
struct studentsFile {
	char id[15];
	char name[20];
	char sex[9];
	int age;
	char class[100];
};

int main() {
	struct studentsFile students[400];//����һ��400ѧ���Ľṹ��
	FILE* fp = fopen("students.txt", "r");//��students�ļ���ֻ��
	int pd = 0;//�ж�ѧ���Ƿ����
	for (int i = 0; i < 400; i++) {
		fscanf(fp, "%[^,],%[^,],%[^,],%d,%s\n", &students[i].id, &students[i].name, &students[i].sex, &students[i].age,
			&students[i].class);//�ο���CSDN����ν��ļ����ݸ��Ƶ��ṹ����
	}
	while (1) {//ѭ��
		printf("i.��ѯģʽ1������������ѧ�Ų�ѯѧ����Ϣ\nii.��ѯģʽ2���������䷶Χ��ѯѧ����Ϣ\niii.��ѯģʽ3�����ݰ༶��ѯѧ����Ϣ\n����:�˳���ѯ\n");
		printf("�������ѯģʽ:>");//��ʾ��
		int mod;
		scanf("%d", &mod);//�����ѯģʽ
		switch (mod) {
		case 1://����ģʽ1
			pd = 0;//��ʼ���ж�
			printf("����1�� ���룺 ����\n����� ����, 2017002871, ��, 17, ������1702\n����, 2015009321, ��, 22, �ż�1502\n");
			printf("����2�� ���룺 2017009876\n����� С·, 2016009876, ��, 20, ������1701\n");
			printf("������������ѧ��:>");//��ʾ��
			char pf[99];
			scanf("%s", pf);//������������ѧ��
			for (int i = 0; i < 401; i++) {//�����ṹ������
				if ((strcmp(students[i].name, pf) == 0)
					|| (strcmp(students[i].id, pf) == 0)) {//�ж��������ѧ�Ż����������ļ����Ƿ����
					printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age,
						students[i].class);//��ӡ��Ӧ��ѧ��
					pd = 1;//�ı��ж�ֵ��˵��ѧ����Ϣ����
				}
			}
			if (pd == 0)//�ж�ֵδ�ı䣬ѧ����Ϣ������
				printf("���޴���\n");
			printf("------------------------------------------\n");
			break;//�ص���ѯģʽ
		case 2://����ģʽ2
			pd = 0;//��ʼ���ж�
			printf("����1�� ���룺 18 20 \n����� ����, 2017001765, Ů, 18, �������1712\nС·, 2016009876, ��, 20, ������1701\n����ΰ, 2014002715, ��, 19, �����1402\n");
			printf("������������ȷ�����䷶Χ��Ҫ���һ����С�ڵ��ڵڶ�����:>");//��ʾ��
			int age[2];
			scanf("%d%d", &age[0], &age[1]);//������������ȷ�������䷶Χ
			if (age[0] > age[1]) {//�涨��һ����С�ڵ��ڵڶ�����
				printf("�������");
				break;
			}
			else {
				for (int i = 0; i < 401; i++) {//�����ṹ������
					if (students[i].age >= age[0] && students[i].age <= age[1]) {
						printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
						pd = 1;//�ı�ѧ����Ϣ�����ж�
					}
				}
				if (pd == 0)//ѧ����Ϣ������
					printf("���޴���\n");
			}
			printf("------------------------------------------\n");
			break;
		case 3:
			pd = 0;
			printf("����1�� ���룺 ������1702\n����� ����, 2017002871, ��, 17, ������1702\n��贵�, 2017009479, Ů, 22, ������1702\n");
			printf("������רҵ�༶:>");
			char class[99];
			scanf("%s", class);//����༶
			for (int i = 0; i < 401; i++) {//����ͬCase1��2
				if ((strcmp(students[i].class, class) == 0) || (strcmp(students[i].class, class) == 0)) {
					printf("%s %s %s %d %s\n", students[i].id, students[i].name, students[i].sex, students[i].age, students[i].class);
					pd = 1;
				}
			}
			if (pd == 0)//����ͬcase1&2
				printf("���޴���\n");
			printf("------------------------------------------\n");
			break;
		default://�������������˳���ѯ
			printf("�˳���ѯ\n");
			return 0;
		}
	}
	fclose(fp);//�ر��ļ�
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
//		printf("������ID��:>");
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
//			printf("��ѡ��:\n(1)��ʼ����\n(2)������\n(3)�˳�\n");
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
//				printf("���� | ��ȷ�� | ��Ĵ�\n");
//				for (int i = 0; i < 10; i++)
//				{
//					printf("%d%c%d=|   %d    |     %d     \n", first[i], yunsuan[i], second[i], answer[i], idAnswer[i]);
//				}
//				
//				printf("�ɼ�:%d0��\n��ʱ:%ds\n", true, t2 - t1);
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
//			printf("�����������������\n");
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
//		printf("i.��ѯģʽ1������������ѧ�Ų�ѯѧ����Ϣ\nii.��ѯģʽ2���������䷶Χ��ѯѧ����Ϣ\niii.��ѯģʽ3�����ݰ༶��ѯѧ����Ϣ\n����:�˳���ѯ\n");
//		printf("�������ѯģʽ:>");
//		int mod;
//		scanf("%d", &mod);
//		switch (mod)
//		{
//		case 1:
//			printf("����1�� ���룺 ����\n����� ����, 2017002871, ��, 17, ������1702\n����, 2015009321, ��, 22, �ż�1502\n");
//			printf("����2�� ���룺 2017009876\n����� С·, 2016009876, ��, 20, ������1701\n");
//			printf("������������ѧ��:>");
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
//				printf("���޴���");
//			printf("------------------------------------------\n");
//			break;
//		case 2:
//			printf("����1�� ���룺 18 20 \n����� ����, 2017001765, Ů, 18, �������1712\nС·, 2016009876, ��, 20, ������1701\n����ΰ, 2014002715, ��, 19, �����1402\n");
//			printf("������������ȷ�����䷶Χ��Ҫ���һ����С�ڵ��ڵڶ�����:>");
//			int age[2];
//			scanf("%d%d", &age[0], &age[1]);
//			if (age[0] > age[1])
//			{
//				printf("�������");
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
//					printf("���޴���\n");
//			}
//			printf("------------------------------------------\n");
//			break;
//		case 3:
//			printf("����1�� ���룺 ������1702\n����� ����, 2017002871, ��, 17, ������1702\n��贵�, 2017009479, Ů, 22, ������1702\n");
//			printf("������רҵ�༶:>");
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
//				printf("���޴���");
//			printf("------------------------------------------\n");
//			break;
//		default:
//			printf("�˳���ѯ");
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
//	printf("����a + aa + aaa + �� + aa��a��n �� a��\n");
//	printf("������nֵ>>");
//	scanf("%d", &n);
//	printf("������aֵ>>");
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
//		printf("sin(x)������x>>");
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
//	printf("e�Ľ���ֵΪ>>%f\n", e);
//	printf("���ۼ���%d��\n", n + 1);
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
//	printf("����a + aa + aaa + �� + aa��a��n �� a��\n");
//	printf("������nֵ>>");
//	scanf("%d", &n);
//	printf("������aֵ>>");
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
//	case 5:printf("���ϸ�"); break;
//	case 6:printf("�ϸ�"); break;
//	case 7:printf("�е�"); break;
//	case 8:printf("����"); break;
//	case 9:
//	case 10:printf("����"); break;
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
//			printf("���ϸ�");
//		else if (grade < 70)
//			printf("�ϸ�");
//			else if (grade < 80)
//				printf("�е�");
//				else if (grade < 90)
//					printf("����");
//					else printf("����");
//	else 
//		printf("�������ݲ�����Ҫ��");
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
//	printf("������һ���ַ���\n");
//	gets(str);
//	printf("������һ���Ӵ�\n");
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
//	printf("���Ӵ���������%d��\n", all);
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
//		printf("������һ����:>");
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
//char chinese[MAX_SIZE][300] = { "adj. ������,��ƽ��,ǡ���� adv. ����,ǡ��","vt. ����,����,����,ȷ��,��Ϊ,�ݷ�,��ͬ vi. ע��,����,�˽�,���� n. ���̽���,����Ȩ��","pron. ��(����)","pron. ���, ���ǵ�","vt. �ӽ������� vi. �����������ﵽ������","adj.ִ�ŵģ��������ӵģ���ֲ�и�ģ������","n. ����,�˿� adj. �ִ��, Ŀǰ�� adv. ����,���� conj. ��Ȼ abbr. =National Organization of Women ȫ����Ů��֯","conj.�ȣ����ڱȽϼ����� ��Ը������Ը�� �������⣻ һ���� prep.������ ��","adj. ���Ƶ�,ͬ���� vt. &vi. ϲ��,Ը��,�� prep. ��,��ͬ n. ����,���Ƶ��ˣ���� adv. ���,�͡�һ�� conj. ��ͬ","adj. ���,������ pron. ��һ����(����) n. ������(����)"," 	adv. ���,����,��ô,���� conj. ���,����,��...��ʽ n. ��ʽ","adv. ��ô, ��ʱ��Ȼ������ adj. ��ʱ��","pron.��it�����и�)����","pron. ���ǵ�","num. ��������","adv.�������ࣻ �ﵽ���ڸ���ķ�Χ��̶ȣ� ���⣬���� adj.����ģ� (many)�ıȽϼ��� ���ӵģ������ pron.����Ļ򸽼ӵ��˻����� n.���ࣻ ���ӣ����","adj.&pron. ��Щ","n. ȱ��, ƶ��, ����, ��Ҫ, ���� vi. Ҫ, ϣ��, ���� vt. ȱ��, ����, ϲ��, Ӧ��","	 	n. ����,��·,����,����,(ĳ)����,�̶�,״̬ adv. �ǳ�,�ܶ�,��Զ adj. ��·�ߵ��м����ص�,·�ߵ��м��","n. ��, ��ɫ, ����, ��ɫ vi. ��, ע��, ����, ����, �Ե� vt. ����, ע��, ���������ɫ��ʾ, �ڴ�","adv. ����,��һ,���� adj. ��һ��, �����, һ���� n. (������)��һ, ��һ���˻�����, (��ѧѧλ��)���ŵ�, (����, ���г��ȵ�)��͵�","adv. Ҳ, ͬ����, ����","adj. �µ�,���ӵ� adv. �µ�","conj. ��Ϊ","n. ����,һ��","n. ����,�÷�,ʹ��Ȩ,���� vt. ʹ��,����,�Դ� vi. ����","n. ��, �ܾ�, ���Ʊ adj. û��, ����, ���� adv. ��","n. ����,����,�� vt. Ϊ...�䱸����,ʹ...���","vt. &vi. ����,�о���,��Ϊ n. ������","adv.����� ��ʱ�� ����һ���ϣ� ����ĳ�˶�����ָ��ĳ��ʱ˵�� n.���� int.ι�� ��","n. ����, ����","vt.& vi.���裻 ���ͣ� ���� vt.������ ������ �ٰ죻 ��Ϊ����ĳ�����ĳ�¶���֧�� vi.�����壩���£� �ò� n.��չ�ԣ�����","n. �����,��� adj. ���� pron. ����˻���","n. ��,ԴȪ,¥�ݾ� adj. ������,���õ�,���˵� adv. �ܺõ�,�ʵ��� vi. ӿ�� interj. �ð�,��","adj. ��õ�,Ψһ��,���ڵ� adv. ����,ֻ��,ר�ŵ�,Ψһ��,�ղ� conj. ����, ����, Ȼ��, �Ͼ�","pron.&amp;adj. ��Щ","vt. ����,˵,֪��,�ϳ�,���� vi. ����,�淢,��֤,����Ч��","adj. ������,��ȫ��,�Լ���,������,ͬһ��,�ر�� adv. ���,�ǳ�"," 	adj. ƽ̹��, ż����, ��ȵ� adv. ����, ǡ��, ���� v. ʹƽ̹, ���","adj. ����ģ�ƫԶ��, ��ʱ��, ��Ƿ��, ���� adv. ���� n. ��, ����������, ���� vt. ���ˣ�֧�� vi. ����","adj. �κε� adv. �� det. һЩ prep. �����ĸ� pron. �κ�","n. ����,�ô� adj. �õ�,������,�ϵȵ� [pl.]��Ʒ","n. ��Ů, Ů��","adv. ��Խ, ��ȫ prep. ����, ����, ƾ�� adj. ��ɵ�, ����; �ᴩ��, ֱͨ��","pron. ����(we�ı���)"," 	n. ����, ����, ����, ����, ����,���, ����(ͽ��) adj. ���,�����,������","n.С�������ӣ� ���ɵ��ˣ� ��� ����","n. ����,����,�ɹ�,��Ʒ,����,����,��Ч,��������,����,(��е)����� adj. ������ vi. ����, ʵ��, �й���, ������, ����, ������ת, �ɹ�, ����Ӱ��, �𽥽���, ���� vt. ���, ����, ʹ��ת, ����, �����ﵽ, ����","adj. ���µ�,���͵�,��������,ֹͣ���� adv. ���µ�,�µ�,���Ϸ� n. ��ë,��ë,���� prep. ����...����","n. ����, �ഺ v. aux.����,����,ףԸ" };
//
//int isExist(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void search(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void insert(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void change(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void logicDelete(char words[MAX_SIZE][20], char chinese[MAX_SIZE][300], int size, char* word);
//void menu();
//
////�˽�ʹ�õ������µĺ�����strcmp strcpy��memset
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
//	int i, num, m = 0, seize = 1, pd = 0, p = 10;//����һЩ���α���
//	float all = 0;//�����ܺ�
//	char pFood[256];//����Ҫ����ʳƷ�����ַ���
//	char food[50][999] = { "ţ��", "���", "������", "��Ȫˮ", "���ȳ�", "����÷", "������", "������", "����", "ֽ��", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
//	float price[] = { 3, 2, 5, 1, 1.5, 5, 10, 1, 0.5, 1 };
//	//����ʳƷ�嵥
//	char* book[256] = { "" };//���幺����ַ�������
//	int num1[256] = { 0 };//�����ظ�������������
//	float price1[256] = { 0 };//�����ظ����򵥼�����
//BEGIN://��ʼ
//	printf("****�˵�****\nʳƷ����   ���ۣ�Ԫ��\n");
//	for (i = 0; i < p; i++)
//		printf("  %s��������������%.2f\n", food[i], price[i]);//�˵�����
//	printf("�����ʽ:ʳƷ���� ����\n(���㰴1 1)\n");
//	do {
//		pd = 0;//��ʼ���ж�
//		scanf("%s %d", &pFood, &num);//����Ҫ���ʳƷ������
//		if (strcmp(pFood, "1") == 0 && num == 1)
//			goto COUNT;//�������1 1�����СƱ����ϵͳ
//		for (i = 0; i < p; i++) {
//			if (strcmp(pFood, food[i]) == 0) {
//				pd = 1;//��������ʳƷ�ڲ˵������ж�Ϊ��
//				break;
//			}
//		}
//		if (pd != 1) {//����ʳƷ�ڲ˵��в�����
//			strcpy(food[p], pFood);//���������ʳƷ���˵���
//			printf("����һ��������,˵���۸���������:>\n(������۸������������һ����Ҫ�������ʳƷ������)\n");
//			scanf("%f", &price[p]);//�����Ǯ
//			p++;//�±�����
//			goto BEGIN;//�ص��ο�ʼ�ĵط�
//
//		}
//		for (i = 0; i < m; i++) {//����
//			if (strcmp(pFood, food[i]) == 0) {//����������ʳƷ��ǰ����������ظ�
//				num1[i] += num;//��ǰһ�λ����ϼ����������
//				all += price[i] * num;//�ܼ�Ҳ����
//				goto PT;//���뵥�ν���
//			}
//		}
//		if (strcmp(pFood, "1") == 0 && num == 1) {//����СƱ����
//		COUNT:
//			printf("СƱ����:\n��Ʒ��   ����    ����\n");
//			for (m = 0; m < seize - 1; m++) {//����
//				printf("%s     %.2f      %d\n", book[m], price1[m], num1[m]);
//			}
//			printf("-----------------------\n�ܼ�:    %.2f", all);//����ܼ�
//			break;
//		}
//		else {//�����ʳƷΪ�˵������е�
//			for (i = 0; i < p; i++) {//����
//				if (strcmp(pFood, food[i]) == 0) {//�ҵ���Ǯ��ӦʳƷ�±�
//					book[m] = food[i];//�滻���빺��ʳƷ����
//					num1[m] = num;//�滻���빺����������
//					price1[m] = price[i];//�滻���빺�򵥼�����
//					m++;//�±��
//					seize++;//�����
//					all += price[i] * num;//���ܺ�
//					break;
//				}
//			}
//		PT:
//			printf("�ܼ�:%.2f\n", all);
//			printf("�㻹Ҫɶ\n");
//			goto BEGIN;//�ص��ο�ʼ�ĵط�
//		}
//	} while (1);//����ѭ��
//	return 0;
//}



//int main() {
//	int i, n = 0, j = 50;//����j=50��ʹ�µ��ʼӵ��ʵ��������
//	int pd, pd2;//�ж��Ƿ�������
//	char nword[256], nmean[256];//��������ĵ��ʺ���˼
//	char word[][256] = { "just", "see", "him", "your", "come", "persistent", "now", "than", "like", "other", "how", "then", "its", "our", "two", "more", "these", "want", "way", "look", "first", "also", "new", "because", "day", "use", "no", "man", "find", "here", "thing", "give", "many", "well", "only", "those", "tell", "very", "even", "back", "any", "good", "woman", "through", "us", "life", "child", "work", "down", "may", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
//	//�ο���CSDN�ַ���������ζ��壬һ��ʼ�õ�ָ�룬�����������ö�ά����
//	char mean[][256] = { "adj. ������,��ƽ��,ǡ���� adv. ����,ǡ��", "vt. ����,����,����,ȷ��,��Ϊ,�ݷ�,��ͬ vi. ע��,����,�˽�,���� n. ���̽���,����Ȩ��", "pron. ��(����)", "pron. ���, ���ǵ�", "vt. �ӽ������� vi. �����������ﵽ������", "adj.ִ�ŵģ��������ӵģ���ֲ�и�ģ������", "n. ����,�˿� adj. �ִ��, Ŀǰ�� adv. ����,���� conj. ��Ȼ abbr. =National Organization of Women ȫ����Ů��֯", "conj.�ȣ����ڱȽϼ����� ��Ը������Ը�� �������⣻ һ���� prep.������ ��", "adj. ���Ƶ�,ͬ���� vt. &vi. ϲ��,Ը��,�� prep. ��,��ͬ n. ����,���Ƶ��ˣ���� adv. ���,�͡�һ�� conj. ��ͬ", "adj. ���,������ pron. ��һ����(����) n. ������(����)", " 	adv. ���,����,��ô,���� conj. ���,����,��...��ʽ n. ��ʽ", "adv. ��ô, ��ʱ��Ȼ������ adj. ��ʱ��", "pron.��it�����и�)����", "pron. ���ǵ�", "num. ��������", "adv.�������ࣻ �ﵽ���ڸ���ķ�Χ��̶ȣ� ���⣬���� adj.����ģ� (many)�ıȽϼ��� ���ӵģ������ pron.����Ļ򸽼ӵ��˻����� n.���ࣻ ���ӣ����", "adj.&pron. ��Щ", "n. ȱ��, ƶ��, ����, ��Ҫ, ���� vi. Ҫ, ϣ��, ���� vt. ȱ��, ����, ϲ��, Ӧ��", "	 	n. ����,��·,����,����,(ĳ)����,�̶�,״̬ adv. �ǳ�,�ܶ�,��Զ adj. ��·�ߵ��м����ص�,·�ߵ��м��", "n. ��, ��ɫ, ����, ��ɫ vi. ��, ע��, ����, ����, �Ե� vt. ����, ע��, ���������ɫ��ʾ, �ڴ�", "adv. ����,��һ,���� adj. ��һ��, �����, һ���� n. (������)��һ, ��һ���˻�����, (��ѧѧλ��)���ŵ�, (����, ���г��ȵ�)��͵�", "adv. Ҳ, ͬ����, ����", "adj. �µ�,���ӵ� adv. �µ�", "conj. ��Ϊ", "n. ����,һ��", "n. ����,�÷�,ʹ��Ȩ,���� vt. ʹ��,����,�Դ� vi. ����", "n. ��, �ܾ�, ���Ʊ adj. û��, ����, ���� adv. ��", "n. ����,����,�� vt. Ϊ...�䱸����,ʹ...���", "vt. &vi. ����,�о���,��Ϊ n. ������", "adv.����� ��ʱ�� ����һ���ϣ� ����ĳ�˶�����ָ��ĳ��ʱ˵�� n.���� int.ι�� ��", "n. ����, ����", "vt.& vi.���裻 ���ͣ� ���� vt.������ ������ �ٰ죻 ��Ϊ����ĳ�����ĳ�¶���֧�� vi.�����壩���£� �ò� n.��չ�ԣ�����", "n. �����,��� adj. ���� pron. ����˻���", "n. ��,ԴȪ,¥�ݾ� adj. ������,���õ�,���˵� adv. �ܺõ�,�ʵ��� vi. ӿ�� interj. �ð�,��", "adj. ��õ�,Ψһ��,���ڵ� adv. ����,ֻ��,ר�ŵ�,Ψһ��,�ղ� conj. ����, ����, Ȼ��, �Ͼ�", "pron.&amp;adj. ��Щ", "vt. ����,˵,֪��,�ϳ�,���� vi. ����,�淢,��֤,����Ч��", "adj. ������,��ȫ��,�Լ���,������,ͬһ��,�ر�� adv. ���,�ǳ�", " 	adj. ƽ̹��, ż����, ��ȵ� adv. ����, ǡ��, ���� v. ʹƽ̹, ���", "adj. ����ģ�ƫԶ��, ��ʱ��, ��Ƿ��, ���� adv. ���� n. ��, ����������, ���� vt. ���ˣ�֧�� vi. ����", "adj. �κε� adv. �� det. һЩ prep. �����ĸ� pron. �κ�", "n. ����,�ô� adj. �õ�,������,�ϵȵ� [pl.]��Ʒ", "n. ��Ů, Ů��", "adv. ��Խ, ��ȫ prep. ����, ����, ƾ�� adj. ��ɵ�, ����; �ᴩ��, ֱͨ��", "pron. ����(we�ı���)", " 	n. ����, ����, ����, ����, ����,���, ����(ͽ��) adj. ���,�����,������", "n.С�������ӣ� ���ɵ��ˣ� ��� ����", "n. ����,����,�ɹ�,��Ʒ,����,����,��Ч,��������,����,(��е)����� adj. ������ vi. ����, ʵ��, �й���, ������, ����, ������ת, �ɹ�, ����Ӱ��, �𽥽���, ���� vt. ���, ����, ʹ��ת, ����, �����ﵽ, ����", "adj. ���µ�,���͵�,��������,ֹͣ���� adv. ���µ�,�µ�,���Ϸ� n. ��ë,��ë,���� prep. ����...����", "n. ����, �ഺ v. aux.����,����,ףԸ", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
//	printf("��1������0����\n");
//	scanf("%d", &pd);//����1����0
//	if (pd == 1) {//����
//		do {
//		START:n = 0;//��ʼ��n
//			printf("������Ӣ�ĵ���(��0����):>");
//			scanf("%s", &nword);//���뵥��
//			if (strcmp(nword, "0") == 0) {//����
//				printf("��ϲ��ȹ����õ�һ��\n");
//				break;//����return 0��Ӧ�ã�
//			}
//			for (i = 0; i < j; i++) {//����
//				if (strcmp(nword, word[i]) == 0) {//�ڴʵ����ҵ���
//					printf("�õ�����˼Ϊ:>");
//					printf("%s\n", mean[i]);//�±��Ӧ
//					n = 1;//�ı�nֵ�Ա������µ����ж�
//					break;//����do(Ӧ��)
//				}
//			}
//			if (n != 1) {//�����µ����ж�
//			RESTART://����һ���µ���
//				printf("����һ���µ��ʣ��Ƿ�����ӵ��ʵ����أ���ӿ�666,����ӿ�1,��ڿ�0\n");
//				scanf("%d", &pd2);//�ж�2
//				if (pd2 == 666)//����µ�����
//				{
//					strcpy(word[j], nword);//���µ��ʼӵ�ԭ�ʵ����
//					printf("�������������˼\n");
//					scanf("%s", &nmean);//�����µ��ʵ���˼
//					strcpy(mean[j], nmean);//����˼�ӵ�ԭ�ʵ��Ӧ��˼������棬���±��Ӧ
//					printf("������Ӣ�ĵ���:>");
//					scanf("%s", &nword);//�ٴ������µ�Ӣ�ĵ���
//					for (i = 0; i < j + 1; i++) {//�������µĴʵ䣬���j+1���Գ����ģ�ԭ���Ǻܶ�
//						if (strcmp(nword, word[i]) == 0) {
//							printf("�õ�����˼Ϊ:>");
//							printf("%s\n", mean[i]);
//							n = 1;//�ı�nֵ����ֹ����ĵ�����Ȼ���µ��ʴӶ��ж�
//							j++;//�ҵ���ʹ��һ��Ҫ��������ĵ��ʺ���˼�ڴʵ��±�����
//							break;
//						}
//					}
//					if (n != 1) {
//						j++;//�ҵ���ʹ��һ��Ҫ��������ĵ��ʺ���˼�ڴʵ��±�����
//						goto RESTART;//���´����ж���ʼ
//					}
//				}
//				if (pd2 == 1)//����̫���ˣ����Ǻ����
//					goto START;
//				if (pd2 == 0)//����
//					goto END;
//			}
//		} while (1);//����ѭ��
//	}
//	else if (pd == 0) {//��ʼ����
//	END:printf("��ϲ��ȹ����õ�һ��\n");
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
//	//scanf("%2d%*2d%2d", &a, &b);//%*2d���Բ����,��������ʱ��ȻҪ������������
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
//	printf("�û���������:>(����һ�����ǵð��س�)");
//	for (i = 0; i < 10; i++)
//		printf("%d\n", i);
//	do
//	{
//		printf("\n\n���水1,�����水0\n");
//		scanf("%d", &pd1);
//		if (pd1 == 1)
//		{
//			printf("����������:>\n");
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
//			printf("���:>");
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
//			printf("\n�����»����𣬼�һ�����ɣ���Ӱ�666������Ӱ�1���˳���0\n");
//			scanf("%d", &pd2);
//			if (pd2 == 666)
//			{
//				printf("������һ������:>");
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
//				printf("���:>");
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
//				printf("��%d��ͬѧ������\n", i + 1);
//				continue;
//			}
//		}
//	}
//	return 0;
//}


////�Ż������ο�  https://zhidao.baidu.com/question/372052575.html
////���˷������Ӷȴ�Լ����һ��������������
////ԭ��������֮ǰֱ���ñ��������ֺ�1����ü���0ȡ���˷�ʱ�䣬�����㷨��λ������С�������˼���ʱ�� 
////amazing!
//int main() {
//	long long start, end;
//	printf("���������ַ�Χ(1-100)��");
//	scanf("%lld-%lld", &start, &end);
//	printf("�������������͸���(8 3)��");
//	int feature, target_count;
//	scanf("%d %d", &feature, &target_count);
//	long long i, count = 0;
//	//������start��end������
//	for (i = start; i <= end; i++) {
//		long long  tmp = i;
//		//�����ڲ�������
//		long long inner_count = 0;
//		//�ڼ�λ
//		int j = 0;
//		//����ÿһλ
//		int n;
//		n = tmp % 10;
//		//n>0�������Ǵ���ģ�����ǰ����ѭ�� 
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
//	printf("\n�ܼ�%lld��\n", count);
//	return 0;
//}


////�Ż��������������Ŀ�������ֵ���ʽ���㡷�� 
////�˷�����Ч�ʲ��ض�˵�� 
////ԭ�������飡�������ϲ��ʮ���ƣ�so����%10��/10����������� 
////�����ٶ�ֻ�Ȳ���plus�İ汾����һ�� 
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
//			//�ж��Ƿ�Ϊ������ʶ�� 
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
//	//����num_arr��ʵ���ǵ�������
//	int num_arr[256] = { 0,-1 };
//	long long start, end;
//	printf("���������ַ�Χ(1-100)��");
//	scanf("%lld-%lld", &start, &end);
//	printf("�������������͸���(8 3)��");
//	int feature, target_count;
//	scanf("%d %d", &feature, &target_count);
//	long long i, count = 0;
//	//ʹ����������start 
//	int* a = &num_arr[0];
//	for (i = 0; i < start; i++) {
//		list_add_one(a);
//	}
//	//������start��end������
//	for (i = start; i <= end; i++) {
//		int j;
//		int inner_count = 0;
//		//�Ӹ�λ��ʼ����������ÿһλ 
//		for (j = 0; num_arr[j] != -1; j++) {
//			if (num_arr[j] == feature) {
//				inner_count++;
//			}
//		}
//		//�ж�count������Ȼ����� 
//		if (inner_count == target_count) {
//			count++;
//			for (j--; j >= 0; j--) {
//				printf("%d", num_arr[j]);
//			}
//			printf(" ");
//		}
//		//�������� 
//		int* p = &num_arr[0];
//		list_add_one(p);
//	}
//	printf("\n�ܼ�%lld��\n", count);
//	return 0;
//}



////�����汾�еĳ�ʼ�汾��Ҳ�������İ汾 
//int main() {
//	long long start, end;
//	printf("���������ַ�Χ(1-100)��");
//	scanf("%lld-%lld", &start, &end);
//	printf("�������������͸���(8 3)��");
//	int feature, target_count;
//	scanf("%d %d", &feature, &target_count);
//	long long i, count = 0;
//	//������start��end������
//	for (i = start; i <= end; i++) {
//		int tmp;
//		//����ÿһλ
//		long long j, inner_count = 0;
//		for (j = 1; i / j > 0; j *= 10) {
//			if (i / j % 10 == feature) inner_count++;
//		}
//		if (inner_count == target_count) {
//			printf("%lld ", i);
//			count++;
//		}
//	}
//	printf("\n�ܼ�%lld��\n", count);
//	return 0;
//}



//int main()
//{
//	double arr[] = { 1.78, 1.77, 1.82, 1.79, 1.85, 1.75, 1.86, 1.77, 1.81, 1.80 };
//	int i, j;
//	printf("\n************�Ŷ�ǰ*************\n");
//	for (i = 0; i < 10; i++)
//	{
//		if (i != 9)
//			printf("%.2f, ", arr[i]);  //%.2f��ʾС�����ȷ����λ
//		else
//			printf("%.2f", arr[i]);    //%.2f��ʾС�����ȷ����λ
//	}
//	for (i = 8; i >= 0; i--)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (arr[j] > arr[j + 1])      //��ǰ������Ⱥ��������ʱ
//			{
//				double temp;    //������ʱ����temp
//				temp = arr[j];   //��ǰ�������ֵ��temp
//				arr[j] = arr[j + 1];     //ǰ��֮���ߵ�λ��
//				arr[j + 1] = temp; //���ϴ�������ں���    
//			}
//		}
//	}
//	printf("\n************�ŶӺ�*************\n");
//	for (i = 0; i < 10; i++)
//	{
//		if (i != 9)
//			printf("%.2f, ", arr[i]);  //%.2f��ʾС�����ȷ����λ     
//		else
//			printf("%.2f", arr[i]);    //%.2f��ʾС�����ȷ����λ
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
//	printf("���Գɼ���������:\n");
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
//	printf("�ܷ�:%d\n", sum);
//	printf("��߷�:%d\n", max);
//	printf("��ͷ�:%d\n", min);
//	printf("ƽ����:%.1f\n", sum / 10.0);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", score[i]);
//	}
//	d();
//
//	return 0;
//}


/* ����say���� */
//void say(char string[])       //�������Ӧ����ôд�أ�
//{
//	printf("%s\n", string);    //��ӡ�ַ���
//}
//
//int main()
//{
//	//�����ַ�������
//	char string[] = "����Ľ������ѧϰIT���ܣ�";
//	say(string);                 //����say��������ַ���
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
//		/* �����������ѯ���� */
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
//	int index = getIndex(arr, 8);      //����Ӧ�ô�ʲô�����أ�
//	if (index != -1)
//	{
//		printf("%d�������д��ڣ��±�Ϊ��%d\n", value, index);
//	}
//	else
//	{
//		printf("%d�������в����ڡ�\n", value);
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
//	printf("��߷�Ϊ:%d ��ͷ�Ϊ:%d", max, min);
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
//			max = arr[i];//�������нϴ������ֵ��max
//			index = i;//��¼��ǰ����
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
//	replaceMax(arr1, arr2[0]); //������arr1������arr2�ĵ�һ��Ԫ�ش��뺯����
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


////����һ����ݺ��·ݣ���ӡ�������ж����죨�������꣩����switch�����ʵ�֡�
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


//5������Ļ����ʾһ��������ʾ��ʱ���
//* ****Time * ****
//1  morning
//2  afternoon
//3  night
//Please enter your choice :
//������Ա������ʾ����ѡ�񣬳�����������ʱ�������ʾ��Ӧ���ʺ���Ϣ��ѡ��1ʱ��ʾ"Good morning"�� ѡ��2ʱ��ʾ"Good afternoon"�� ѡ��3ʱ��ʾ"Good night"����������ѡ����ʾ"Selection error!"����switch�����ʵ�֡�

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


//4�����������ε�������a��b��c���ж������ܷ񹹳������Ρ����ܹ��������Σ�ָ���Ǻ��������Σ����������Ρ�ֱ�������Ρ�һ�������Σ���
//int main()
//{
//	int a, b, c;
//	scanf("%d,%d,%d", &a, &b, &c);
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		if (a == b || a == c || b == c)
//			printf("����");
//		if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
//			printf("ֱ��");
//		else
//			printf("һ��");
//	}
//	else
//		printf("������");
//	printf("������\n");
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
//		printf("ż����Ϊ");
//	else if (a % 2 != 0)
//		printf("������Ϊ");
//	if (a > 0)
//		printf("����\n");
//	else if (a < 0)
//		printf("����\n");
//}


////ͨ����������һ���ַ����жϸ��ַ��������ַ�����д��ĸ��Сд��ĸ���ո��������ַ���
//int main()
//{
//	char pt;
//	pt = getchar();
//	//printf("%d\n", pt);
//	if (pt >= 48 && pt <= 57)
//	{
//		printf("�����ַ�\n");
//	}
//	else if (pt >= 41 && pt <= 90)
//	{
//		printf("��д��ĸ\n");
//	}
//	else if (pt >= 97 && pt <= 122)
//	{
//		printf("Сд��ĸ\n");
//	}
//	else if (pt == 32)
//	{
//		printf("�ո�\n");
//	}
//	else
//	{
//		printf("�����ַ�\n");
//	}
//	return 0;
//}


//�Ӽ�����������һ����ţ��ж����Ƿ������ꡣ�������꣬�����Yes�������������No������֪������������֮һ�������꣺
//���ܱ�4�����������ܱ�100������
//���ܱ�400������
//int main()
//{
//	int year;
//	printf("���������:>");
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0)
//	{
//		printf("����������\n");
//	}
//	else if (year % 400 == 0)
//	{
//		printf("����������\n");
//	}
//	else
//	{
//		printf("���겻������\n");
//	}
//	return 0;
//}


/*
 * ��ʹ�õݹ麯����ɱ���
 * С���ѽ���ȷ��������������ġ���֪����ô�족��
 * С��ϣ����λͯЬ�������Ŷ~
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
 //	printf("��5���˵�������%d��", sum);
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
 //	printf("������ʼ����%.2f\n", a);
 //	printf("������С����ʼ��ʱ����վ̨ ");
 //	printf("�û�����:");
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
 //	printf("�ȴ�ʱ����%dmin\n", end);
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
 //	printf("������ʼ����%d:", a);
 //	if (a == 12)
 //	{
 //		printf("00\n");
 //	}
 //	else if (b < 10)
 //		printf("0%d\n", b);
 //	else if (b >= 10)
 //		printf("%d\n", b);
 //	
 //	printf("����ʱ���Ϊ9:00-12:00,�벻Ҫ���Ŷ\n");
 //	printf("������С����ʼ��ʱ����վ̨\n");
 //	printf("��������:10.00 2\n");
 //	printf("�û�����:");
 //	scanf_s("%d.%d %d", &h, &m, &n);
 //	
 //	if (n == 1)
 //	{
 //		if ((a * 60 + b) >= 650 && ((h * 60 + m) - (a * 60 + b) > 20))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 580 && ((h * 60 + m) - (a * 60 + b) > 90))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 510 && ((h * 60 + m) - (a * 60 + b) > 160))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 440 && ((h * 60 + m) - (a * 60 + b) > 230))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 370 && ((h * 60 + m) - (a * 60 + b) > 300))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 300 && ((h * 60 + m) - (a * 60 + b) > 370))
 //		{
 //			printf("����������\n");
 //		}
 //		else if (h == a)
 //		{
 //			b += 20;
 //			if (m > b)
 //			{
 //				t = 70 - (m - b);
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //			else
 //			{
 //				t = b - m;
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //		}
 //		else if (h == a + 1)
 //		{
 //			if ((h * 60 + m) - (a * 60 + b) < 20)
 //			{
 //				t = (h * 60 + m) - (a * 60 + b);
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //			else
 //			{
 //				t = -((h * 60 + m) - (a * 60 + b)) + 90;
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //		}
 //		else if (h == a + 2)
 //		{
 //			if ((h * 60 + m) - (a * 60 + b) < 90)
 //			{
 //				t = (a * 60 + b) + 90 - (h * 60 + m);
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //			else
 //			{
 //				t = (a * 60 + b) + 160 - (h * 60 + m);
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //		}
 //		else if (h < a && a != 12)
 //		{
 //			t = -((h * 60 + m) - (a * 60 + b)) + 20;
 //			printf("�ȴ�ʱ����%dmin\n", t);
 //		}
 //		else if (h < a && a == 12)
 //		{
 //			t = 740 - (h * 60 + m);
 //			printf("�ȴ�ʱ����%dmin\n", t);
 //		}
 //	}
 //	else if (n == 2)
 //	{
 //		if ((a * 60 + b) >= 650 && ((h * 60 + m) - (a * 60 + b) > 40))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 580 && ((h * 60 + m) - (a * 60 + b) > 110))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 510 && ((h * 60 + m) - (a * 60 + b) > 180))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 440 && ((h * 60 + m) - (a * 60 + b) > 250))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 370 && ((h * 60 + m) - (a * 60 + b) > 320))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((a * 60 + b) >= 300 && ((h * 60 + m) - (a * 60 + b) > 390))
 //		{
 //			printf("����������\n");
 //		}
 //		else if ((h * 60 + m) <= (a * 60 + b) && a != 12)
 //		{
 //			t = -((h * 60 + m) - (a * 60 + b)) + 40;
 //			printf("�ȴ�ʱ����%dmin\n", t);
 //		}
 //		else if ((h * 60 + m) <= (a * 60 + b) && a == 12)
 //		{
 //			t = 760 - (h * 60 + m);
 //			printf("�ȴ�ʱ����%dmin\n", t);
 //		}
 //		else if ((h * 60 + m) > (a * 60 + b))
 //		{
 //			if ((h * 60 + m) - (a * 60 + b) <= 40)
 //			{
 //				t = (a * 60 + b) + 40 - (h * 60 + m);
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //			else if ((h * 60 + m) - (a * 60 + b) <= 110)
 //			{
 //				t = (a * 60 + b) + 110 - (h * 60 + m);
 //				printf("�ȴ�ʱ����%dmin\n", t);
 //			}
 //			else if ((h * 60 + m) - (a * 60 + b) <= 180)
 //			{
 //				t = (a * 60 + b) + 180 - (h * 60 + m);
 //				printf("�ȴ�ʱ����%dmin\n", t);
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
 //		//printf("����\n");
 //		goto ABC;
 //	}
 //	//printf("������Ϊ:");
 //	//scanf_s("%d", &a);
 //	//printf("����������Ϊ:");
 //	//scanf_s("%d", &b);
 //	printf("������Ϊ:%d\n����������Ϊ:%d\n", a, b);
 //	if (b > 4 || b < 1)
 //		printf("����\n");
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
 //	printf("�н�����Ϊ%d", sum);
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
 //	int num;    //������ʣ������
 //	if (n == 10)
 //	{
 //		num = 1;       //�ݹ��������
 //	}
 //	else
 //	{
 //		num = getPeachNumber(n+1) * 2 + 2;  //�����ǲ�Ӧ���õݹ��أ�
 //		printf("��%d����ʣ����%d��\n", n, num); //��������ʣ���Ӹ���
 //		n++;
 //	}
 //	return num;
 //}
 //int main()
 //{
 //	int num = getPeachNumber(1);
 //	printf("���ӵ�һ��ժ��:%d�����ӡ�\n", num);
 //	return 0;
 //}


 ///* Jone������Ӧ����ôд������ */
 //int  joneResult(int x, int y, int z)
 //{
 //	int sum = x + y + z;
 //	return sum;//�����ǲ���Ӧ�ý�sum�����أ�
 //}
 ///* Jackû��������ֻ˵��һ�仰�ǲ���Ӧ�����޷���ֵ������ */
 //void jackResult(int x, int y, int z)
 //{
 //	printf("���㲻����\n");
 //}
 //
 //int main()
 //{
 //	int a, b, c;
 //	a = 10;
 //	b = 20;
 //	c = 30;
 //	//Jone�ķ���ֵ������ʲô��
 //	int jR = joneResult(a, b, c);
 //	printf("Jone�������ǣ�%d\n", jR);
 //	printf("Jack�������ǣ�");
 //	//Jackû��������ֻ˵�˾仰���ǲ���ֱ�ӵ��ú����Ϳ����ˣ�
 //	jackResult(a, b, c);
 //	return 0;
 //}


 //int xuexi()
 //{
 //	printf("С����Ľ������ѧϰ\n");
 //}
 //
 //int clas(int i)
 //{
 //	printf("С����Ľ�������Ѿ�����ѧϰ��%d�ſγ�",i);
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
 //    /* ������Ҫ��������� */
 //    int year = 2008;
 //    int month = 8;
 //    int day = 8;
 //    /*
 //     * ��ʹ��switch��䣬if...else�����ɱ���
 //     * �����뿴С��˼·�ģ����Ե����������еġ���������ô�족
 //     * С�໹��ϣ����Ҷ������Ŷ~
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


 //��ӡ��������
 //int main()
 //{
 //	int i, j, k;
 //	for (i = 1; i < 5; i++)
 //		{
 //			/* �۲�ÿ�еĿո���������ȫѭ������ */
 //			for (j = i; j < 5; j++)
 //			{
 //				printf(" ");    //����ո�
 //			}
 //			/* �۲�ÿ��*�ŵ���������ȫѭ������ */
 //			for (k = 0; k < i * 2 - 1; k++)
 //			{
 //				printf("*");   //ÿ�������*��
 //			}
 //			printf("\n");     //ÿ��ѭ������
 //		}
 //	return 0;
 //}


 //int main()
 //{
 //    /* С����ǣ�
 //           ѡ��������Ϊ������ѭ���ṹ��ɹ��ܰ� */
 //    int sum = 0;  //�������������sum
 //    int i = 1;    //����ѭ�����ֱ���i
 //    int flag = 1; //�������״̬����flag
 //
 //    //ʹ��whileѭ��
 //  //  while (i <= 100)
 //  //  {
 //  //      i++;
 //		//flag = -flag;
 //  //      sum += flag * i;
 //  //  }
 //
 //    i = 1;  //���³�ʼ������i
 //
 //    //do-whileѭ��
 //  //  do {
 //  //      i++;
 //  //      flag = -flag;
 //		//sum += flag * i;
 //  //  } while (i <= 100);
 //
 //    i = 1;  //���³�ʼ������i
 //
 //    //ʹ��forѭ��
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
 //	int n = c;        //��c��ֵ��n
 //	float f = c;      //��c��ֵ��f
 //	double d = c;    //��c��ֵ��d
 //	printf("%d\n", n);
 //	printf("%f\n", f);
 //	printf("%lf\n", d);
 //	return 0;
 //}
