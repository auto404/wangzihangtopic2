#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

int num[1000000];

void quickSort(int, int, int);
int partition(int, int);

int main()
{
	int n, k, i;
	srand(unsigned(time(NULL)));		// 随机函数种子
	SetConsoleOutputCP(CP_UTF8);
	printf("请输入n（数组的个数),k（第k小）,请输入具体数组？\n");
	while (~scanf("%d%d", &n, &k))//scanf的返回值是输入值的个数,如果没有输入值就是返回-1- 1按位取反结果是0,退出循环
	{
		for (i = 0; i < n; i++)
			scanf("%d", &num[i]);

		quickSort(0, n - 1, k- 1);

		printf("%d\n", num[k - 1]);
	}
	return 0;
}
// 快速排序
void quickSort(int left, int right, int min)
{
	if (left < right)
	{
		int p = partition(left, right);		// 分为左右

		if (p == min)						// 如果p就是要找的输出
			return;
		if (p < min)
			quickSort(p + 1, right, min);	// p比min小就在[p + 1, right]区间找
		if (p > min)
			quickSort(left, p - 1, min);	// p比min大就在[left, p - 1]区间找
	}
}
// 从小到大排
int partition(int left, int right)
{
	int r = rand() % (right - left + 1) + left;		// 随机一个
	int key = num[r];
	std::swap(num[r], num[left]);					// 交换到数组首位
	while (left < right)
	{// 从数组后面开始, 找比随机选择的数小的, 然后从前找比随机选择的数大的
		while (left < right && num[right] >= key)
			right--;
		if (left < right)
			num[left] = num[right];

		while (left < right && num[left] <= key)
			left++;
		if (left < right)
			num[right] = num[left];
	}
	num[left] = key;		// 将随机选择的数存回
	return left;			// 返回随机选择的数分割数组的下标, 左小右大
}
