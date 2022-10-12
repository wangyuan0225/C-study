#include <stdio.h>

int getPeachNumber(n)
{
	int num;    //定义所剩桃子数
	if (n == 10)
	{
		num = 1;       //递归结束条件
	}
	else
	{
		num = getPeachNumber(num)*2+1;   //这里是不应该用递归呢？
		printf("第%d天所剩桃子%d个\n", 10-n, getPeachNumber(num)); //天数，所剩桃子个数
		n++;
	}
	return num;
}
int main()
{
	int num = getPeachNumber(1);
	printf("猴子第一天摘了:%d个桃子。\n", num);
	return 0;
}

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
