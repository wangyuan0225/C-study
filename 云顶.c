#include <stdio.h>

int main()
{
    /* ������Ҫ��������� */
    int year = 2008;
    int month = 8;
    int day = 8;
    /*
     * ��ʹ��switch��䣬if...else�����ɱ���
     * �����뿴С��˼·�ģ����Ե����������еġ���������ô�족
     * С�໹��ϣ����Ҷ������Ŷ~
     */
    int days = 0;
    switch(month)
    {
    case 12:
        days += 31;
    case 11:
        days += 30;
    case 10:
        days += 31;
    case 9:
        days += 30;
    case 8:
        days += 31;
    case 7:
        days += 31;
    case 6:
        days += 30;
    case 5:
        days += 31;
    case 4:
        days += 30;
    case 3:
        days += 31;
    case 2:
        if (year % 4 == 0)
        {
            days += 29;
        }
        else
        {
            days += 28;
        }
    case 1:
        days += 31;
    }
    printf("%d", days + day);
    return 0;
}


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
