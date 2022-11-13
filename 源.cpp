#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 10
//					数 据 结 构
//	(Data Structure)是计算机存储、组织数据的方式，指相互之间存在一种或多种特定关系的数据元素的集合。

//	时间复杂度 - 是一个函数表达式，代码跑了多少次
//	空间复杂度 - 代码存储占用的空间大小

void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j)
		{
			++count;			// 共 N*N次
		}
	}
	for (int k = 0; k < 2 * N; ++k) 
	{
		++count;				// 共 2*N次
	}
	int M = 10; while (M--) 
	{
		++count;				// 共 10次
	}
	printf("%d\n", count);		//  一共N*N+2*N+10次，时间复杂度F(N)=N*N+2*N+10
	//					N=10,F=130,N=1000,F=1002010,N*N的影响慢慢大过后两项，因此
	//					计算时间复杂度时不一定要精确计算执行次数，只需要大概执行次数
	//					即 大O的渐进表示法 - 估算
			//	因此上面代码时间复杂度 - O(N^2)
}