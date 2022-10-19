#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int i, n = 0;
	char nword[256], nmean[256];
	char* word[] = { "just","see","him","your","come","persistent","now","than","like","other","how","then","its","our","two","more","these","want","way","look","first","also","new","because","day","use","no","man","find","here","thing","give","many","well","only","those","tell","very","even","back","any","good","woman","through","us","life","child","work","down","may" };
	char* mean[] = { "adj. ������,��ƽ��,ǡ���� adv. ����,ǡ��","vt. ����,����,����,ȷ��,��Ϊ,�ݷ�,��ͬ vi. ע��,����,�˽�,���� n. ���̽���,����Ȩ��","pron. ��(����)","pron. ���, ���ǵ�","vt. �ӽ������� vi. �����������ﵽ������","adj.ִ�ŵģ��������ӵģ���ֲ�и�ģ������","n. ����,�˿� adj. �ִ��, Ŀǰ�� adv. ����,���� conj. ��Ȼ abbr. =National Organization of Women ȫ����Ů��֯","conj.�ȣ����ڱȽϼ����� ��Ը������Ը�� �������⣻ һ���� prep.������ ��","adj. ���Ƶ�,ͬ���� vt. &vi. ϲ��,Ը��,�� prep. ��,��ͬ n. ����,���Ƶ��ˣ���� adv. ���,�͡�һ�� conj. ��ͬ","adj. ���,������ pron. ��һ����(����) n. ������(����)"," 	adv. ���,����,��ô,���� conj. ���,����,��...��ʽ n. ��ʽ","adv. ��ô, ��ʱ��Ȼ������ adj. ��ʱ��","pron.��it�����и�)����","pron. ���ǵ�","num. ��������","adv.�������ࣻ �ﵽ���ڸ���ķ�Χ��̶ȣ� ���⣬���� adj.����ģ� (many)�ıȽϼ��� ���ӵģ������ pron.����Ļ򸽼ӵ��˻����� n.���ࣻ ���ӣ����","adj.&pron. ��Щ","n. ȱ��, ƶ��, ����, ��Ҫ, ���� vi. Ҫ, ϣ��, ���� vt. ȱ��, ����, ϲ��, Ӧ��","	 	n. ����,��·,����,����,(ĳ)����,�̶�,״̬ adv. �ǳ�,�ܶ�,��Զ adj. ��·�ߵ��м����ص�,·�ߵ��м��","n. ��, ��ɫ, ����, ��ɫ vi. ��, ע��, ����, ����, �Ե� vt. ����, ע��, ���������ɫ��ʾ, �ڴ�","adv. ����,��һ,���� adj. ��һ��, �����, һ���� n. (������)��һ, ��һ���˻�����, (��ѧѧλ��)���ŵ�, (����, ���г��ȵ�)��͵�","adv. Ҳ, ͬ����, ����","adj. �µ�,���ӵ� adv. �µ�","conj. ��Ϊ","n. ����,һ��","n. ����,�÷�,ʹ��Ȩ,���� vt. ʹ��,����,�Դ� vi. ����","n. ��, �ܾ�, ���Ʊ adj. û��, ����, ���� adv. ��","n. ����,����,�� vt. Ϊ...�䱸����,ʹ...���","vt. &vi. ����,�о���,��Ϊ n. ������","adv.����� ��ʱ�� ����һ���ϣ� ����ĳ�˶�����ָ��ĳ��ʱ˵�� n.���� int.ι�� ��","n. ����, ����","vt.& vi.���裻 ���ͣ� ���� vt.������ ������ �ٰ죻 ��Ϊ����ĳ�����ĳ�¶���֧�� vi.�����壩���£� �ò� n.��չ�ԣ�����","n. �����,��� adj. ���� pron. ����˻���","n. ��,ԴȪ,¥�ݾ� adj. ������,���õ�,���˵� adv. �ܺõ�,�ʵ��� vi. ӿ�� interj. �ð�,��","adj. ��õ�,Ψһ��,���ڵ� adv. ����,ֻ��,ר�ŵ�,Ψһ��,�ղ� conj. ����, ����, Ȼ��, �Ͼ�","pron.&amp;adj. ��Щ","vt. ����,˵,֪��,�ϳ�,���� vi. ����,�淢,��֤,����Ч��","adj. ������,��ȫ��,�Լ���,������,ͬһ��,�ر�� adv. ���,�ǳ�"," 	adj. ƽ̹��, ż����, ��ȵ� adv. ����, ǡ��, ���� v. ʹƽ̹, ���","adj. ����ģ�ƫԶ��, ��ʱ��, ��Ƿ��, ���� adv. ���� n. ��, ����������, ���� vt. ���ˣ�֧�� vi. ����","adj. �κε� adv. �� det. һЩ prep. �����ĸ� pron. �κ�","n. ����,�ô� adj. �õ�,������,�ϵȵ� [pl.]��Ʒ","n. ��Ů, Ů��","adv. ��Խ, ��ȫ prep. ����, ����, ƾ�� adj. ��ɵ�, ����; �ᴩ��, ֱͨ��","pron. ����(we�ı���)"," 	n. ����, ����, ����, ����, ����,���, ����(ͽ��) adj. ���,�����,������","n.С�������ӣ� ���ɵ��ˣ� ��� ����","n. ����,����,�ɹ�,��Ʒ,����,����,��Ч,��������,����,(��е)����� adj. ������ vi. ����, ʵ��, �й���, ������, ����, ������ת, �ɹ�, ����Ӱ��, �𽥽���, ���� vt. ���, ����, ʹ��ת, ����, �����ﵽ, ����","adj. ���µ�,���͵�,��������,ֹͣ���� adv. ���µ�,�µ�,���Ϸ� n. ��ë,��ë,���� prep. ����...����","n. ����, �ഺ v. aux.����,����,ףԸ" };
	do
	{
		printf("������Ӣ�ĵ���:>");
		scanf("%s", &nword);
		for (i = 0; i < 50; i++)
		{
			if (strcmp(nword, word[i]) == 0)
			{
				printf("�õ�����˼Ϊ:>");
				printf("%s\n", mean[i]);
				n = 1;
			}
		}
		if (n != 1)
		{
			printf("����һ���µ��ʣ���������˼:>");
			scanf("%s", &nmean);
			printf("������Ӣ�ĵ���:>");
			scanf("%s", &nword);
			for (i = 0; i < 50; i++)
			{
				if (strcmp(nword, word[i]) == 0)
				{
					printf("�õ�����˼Ϊ:>");
					printf("%s\n", mean[i]);
					n = 1;
				}
			}
			if (n != 1)
			{
				printf("�õ�����˼Ϊ:>");
				printf("%s\n", nmean);
			}
		}

	} while (n = 1000);
	return 0;
}


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
