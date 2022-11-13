#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<assert.h>

#define N 10


//					数 据 结 构
//	(Data Structure)是计算机存储、组织数据的方式，指相互之间存在一种或多种特定关系的数据元素的集合。

//	时间复杂度 - 是一个函数表达式，代码跑了多少次
////	空间复杂度 - 代码存储占用的空间大小
// 
// 推断大O阶方法：
// 1.用常数1取代运行时间中所有加法常数
// 2.再修改后的运行次数函数中，只保留最高阶项
// 3.如果最高阶项存在且不为1，则去除与这个项目相乘的常数(系数)，得到的即为大O阶
//
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;			// 共 N*N次
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k) 
//	{
//		++count;				// 共 2*N次
//	}
//	int M = 10; while (M--) 
//	{
//		++count;				// 共 10次
//	}
//	printf("%d\n", count);		//  一共N*N+2*N+10次，时间复杂度F(N)=N*N+2*N+10
//	//					N=10,F=130,N=1000,F=1002010,N*N的影响慢慢大过后两项，因此
//	//					计算时间复杂度时不一定要精确计算执行次数，只需要大概执行次数
//	//					即 大O的渐进表示法 - 估算
//			//	因此上面代码时间复杂度 - O(N^2)		法2
//}

// 计算Func2的时间复杂度?
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;	// 2*N 次
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;	// 10 次
//	}						//时间复杂度 0(N)  不是2*N，法3
//	printf("%d\n", count);
//}

//计算Func3的时间复杂度?
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k) 
//	{
//		++count;	//	M 次
//	}
//	for (int k = 0; k < N; ++k) 
//	{
//		++count;	//	N 次
//	}
//							//	时间复杂度 O(M+N) - 未说明
//	//						1.若 M >> N ,则O(M)
//	//						1.若 N >> M ,则O(N)
//	//						1.若 M == N ,则O(M)/O(N)都行
//	printf("%d \n", count);
//}

//计算Func4的时间复杂度?
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k) 
//	{
//		++count;	//	100 次		O(1)	并不是只能运算 1 次，而是常数次
//	}
//	printf("%d\n", count);
//}

//					 hello world
//	 假设查找 h - 1 次，  最好情况：任意输入规模的最小运行次数(下界)
//	 假设查找 w - N/2 次，平均情况：任意输入规模的期望运行次数	  - 一般不看平均情况，意义不大
//	 假设查找 d - N 次，  最坏情况：任意输入规模的最大运行次数(上界)

//	而 ：当一个算法随着输入的不同，时间复杂度也不同，时间复杂度做悲观预期，看最坏情况
//const char* strchr(const char* str, int character)
//{
//	while (*str)
//	{
//		if (*str == character)	// 时间复杂度 O(N)	看最坏情况
//			return str;
//		else
//			++str;
//	}
//	}

// 计算Bubb1eSort的时间复杂度 ? 	冒泡排序
//void Bubb1esort(int* a,int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)	//  n 次
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)	
//			//	n-1趟 -> n-2趟 -> n-3趟 -> n-4趟 -> ... -> 1趟
//		{
//			if (a[i - 1] > a[i]) 
//			{								//  前n-1项合
//	//										(1+(n-1))(n-1)/2 = n(n-1)/2
//				Swap(&a[i - 1], & a[i]);	//	O(n^2)
//				exchange = 1;				
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}

// 计算BinarySearch的时间复杂度？	二分查找
int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;		//	最好情况：中间一次
		else if (a[mid] > x)		//  最坏情况：找到最后/找不到
			end = mid;
		else						//	假设最坏找了X次找到那个数
			return mid;				//	N -> N/2 -> N/2/2 -> N/2/2/2 ->... -> 1
	}								//	N/2/2/2/2/2=1  即 N = 1*2*2*2*2*...*2
									//	N=2*X (乘了X个2，共X次)
									//  X=log N (以2为底)	时间复杂度O(log N)
	return -1;
}

//	对于二分查找:		
//	1000 个数里找1个数：10次
//	100万个数里找1个数：20次
//	10亿 个数里找1个数：30次
//		如果是有序的，效率非常高，不过排序非常耗能