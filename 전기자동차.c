#include <stdio.h>

int bat[10];
int minV;
void f(int n, int k, int e, int c); // n 정류장, k 종점, e 남은에너지, c 교환횟수 

int main(void) 
{
	int T;
	int N;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N); // 종점 번호 
		minV = 10;
		for(int i = 1; i <= N - 1; i++)
		{
			scanf("%d", &bat[i]); // 정류장 별 배터리 용량 
		}
		//f( 1, N, 0, 0); // 1번부터 교환횟수를 고려하는 경우... 
		f( 2, N, bat[1] - 1, 0);
		printf("#%d %d\n", tc, minV);
	}

	return 0;
}

void f(int n, int k, int e, int c)
{
	if( n == k) // 종점에 도착한 경우 
	{
		if( minV > c )
		{
			minV = c;
		}
	}
	else
	{
		if( e > 0 ) // 남은 에너지가 있는 경우에만 
			f( n + 1, k, e - 1, c ); // 통과
		f( n + 1, k, bat[n] - 1, c + 1 ); // 교환 : 현재 정류장 배터리 - 1, 교환횟수 증가 
	}
