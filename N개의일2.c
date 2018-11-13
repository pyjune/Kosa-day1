#include <stdio.h>

int t[10][10]; // [사람][일] 
int used[10];
int p[10];
int minV;
int cnt; // 재귀호출 횟수 비교를 위한 변수

void find(int n, int k);
void find2(int n, int k, int s); // 이미 결정된 일을 하는데 걸리는 시간s 

int main(void)
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N; // 사람과 일의 수
		minV = 100;
		cnt = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		find(0, N);
		//find2(0, N, 0);
		printf("#%d %d\n", tc, minV);
		printf("%d\n", cnt);
	}
	
	return 0;
}
void find2(int n, int k, int s)
{
	cnt++;
	if( n == k) // 모든 일을 맡은 사람이 결정되면 
	{
		if( minV > s)
		{
			minV = s;
		}
	}
	else if( s >= minV ) // 남은 일이 있어도, 최소 시간을 초과하면 
	{
		return;
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				p[n] = i; // n번일을 하는 사람 결정 
				find2( n + 1, k, s + t[p[n]][n]); // n번일을 하는데 걸리는 시간 추가 
				used[i] = 0;
			}
		}
	}
}

void find(int n, int k)
{
	cnt++;
	if( n == k)
	{
		int s = 0;
		for(int i = 0; i < k; i++)
		{
			s += t[p[i]][i];
		}
		if( minV > s)
		{
			minV = s;
		}	
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				find( n + 1, k );
				used[i] = 0;
			}
		}
	}
}
