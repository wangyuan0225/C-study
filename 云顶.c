#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand((unsigned int)time(NULL));
	int a = rand() % 4 + 9;
	int b = rand() % 60;
	//int a = 10;
	//int b = 55;
	int h, m, n;
	int t;
	printf("������ʼ����%d:", a);
	if (a == 12)
	{
		printf("00\n");
	}
	else if (b < 10)
		printf("0%d\n", b);
	else if (b >= 10)
		printf("%d\n", b);
	
	printf("����ʱ���Ϊ9:00-12:00,�벻Ҫ���Ŷ\n");
	printf("������С����ʼ��ʱ����վ̨\n");
	printf("��������:10.00 2\n");
	printf("�û�����:");
	scanf_s("%d.%d %d", &h, &m, &n);
	
	if (n == 1)
	{
		if ((a * 60 + b) >= 650 && ((h * 60 + m) - (a * 60 + b) > 20))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 580 && ((h * 60 + m) - (a * 60 + b) > 90))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 510 && ((h * 60 + m) - (a * 60 + b) > 160))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 440 && ((h * 60 + m) - (a * 60 + b) > 230))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 370 && ((h * 60 + m) - (a * 60 + b) > 300))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 300 && ((h * 60 + m) - (a * 60 + b) > 370))
		{
			printf("����������\n");
		}
		else if (h == a)
		{
			b += 20;
			if (m > b)
			{
				t = 70 - (m - b);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
			else
			{
				t = b - m;
				printf("�ȴ�ʱ����%dmin\n", t);
			}
		}
		else if (h == a + 1)
		{
			if ((h * 60 + m) - (a * 60 + b) < 20)
			{
				t = (h * 60 + m) - (a * 60 + b);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
			else
			{
				t = -((h * 60 + m) - (a * 60 + b)) + 90;
				printf("�ȴ�ʱ����%dmin\n", t);
			}
		}
		else if (h == a + 2)
		{
			if ((h * 60 + m) - (a * 60 + b) < 90)
			{
				t = (a * 60 + b) + 90 - (h * 60 + m);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
			else
			{
				t = (a * 60 + b) + 160 - (h * 60 + m);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
		}
		else if (h < a && a != 12)
		{
			t = -((h * 60 + m) - (a * 60 + b)) + 20;
			printf("�ȴ�ʱ����%dmin\n", t);
		}
		else if (h < a && a == 12)
		{
			t = 740 - (h * 60 + m);
			printf("�ȴ�ʱ����%dmin\n", t);
		}
	}
	else if (n == 2)
	{
		if ((a * 60 + b) >= 650 && ((h * 60 + m) - (a * 60 + b) > 40))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 580 && ((h * 60 + m) - (a * 60 + b) > 110))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 510 && ((h * 60 + m) - (a * 60 + b) > 180))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 440 && ((h * 60 + m) - (a * 60 + b) > 250))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 370 && ((h * 60 + m) - (a * 60 + b) > 320))
		{
			printf("����������\n");
		}
		else if ((a * 60 + b) >= 300 && ((h * 60 + m) - (a * 60 + b) > 390))
		{
			printf("����������\n");
		}
		else if ((h * 60 + m) <= (a * 60 + b) && a != 12)
		{
			t = -((h * 60 + m) - (a * 60 + b)) + 40;
			printf("�ȴ�ʱ����%dmin\n", t);
		}
		else if ((h * 60 + m) <= (a * 60 + b) && a == 12)
		{
			t = 760 - (h * 60 + m);
			printf("�ȴ�ʱ����%dmin\n", t);
		}
		else if ((h * 60 + m) > (a * 60 + b))
		{
			if ((h * 60 + m) - (a * 60 + b) <= 40)
			{
				t = (a * 60 + b) + 40 - (h * 60 + m);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
			else if ((h * 60 + m) - (a * 60 + b) <= 110)
			{
				t = (a * 60 + b) + 110 - (h * 60 + m);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
			else if ((h * 60 + m) - (a * 60 + b) <= 180)
			{
				t = (a * 60 + b) + 180 - (h * 60 + m);
				printf("�ȴ�ʱ����%dmin\n", t);
			}
		}
	}
	return 0;
}


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


//int mian()
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
//		num = getPeachNumber(num)*2+1;   //�����ǲ�Ӧ���õݹ��أ�
//		printf("��%d����ʣ����%d��\n", 10-n, getPeachNumber(num)); //��������ʣ���Ӹ���
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
