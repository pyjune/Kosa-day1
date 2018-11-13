#include <stdio.h>

int a[] = {1,2,3,4,5};
int p[3];
int used[5];

void npr(int n, int k);
void npr2(int n, int k, int m);

int main(void) 
{
	//npr(0, 3);
	npr2(0, 3, 5);

	return 0;
}

void npr2(int n, int k, int m)
{
	if(n == k)
	{
		for(int i = 0; i < k; i++)
		{
			printf("%d", p[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			if(used[i] == 0) // 아직 사용하지 않은	숫자면
			{
				used[i] = 1; // 사용함으로 표시
				p[n] = a[i]; // 사용하지 않은 숫자를 순열에 추가 
				npr2( n + 1, k, m ); // 다음자리 결정
				used[i] = 0; // 다른 자리에서 사용할 수 있도록 함 
			} 
		}	
	}	
}

void npr(int n, int k)
{
	if(n == k)
	{
		for(int i = 0; i < k; i++)
		{
			printf("%d", p[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			if(used[i] == 0) // 아직 사용하지 않은	숫자면
			{
				used[i] = 1; // 사용함으로 표시
				p[n] = a[i]; // 사용하지 않은 숫자를 순열에 추가 
				npr( n + 1, k ); // 다음자리 결정
				used[i] = 0; // 다른 자리에서 사용할 수 있도록 함 
			} 
		}	
	}	
}
