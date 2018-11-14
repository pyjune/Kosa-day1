#include <stdio.h>

int arr[10][10];
int used[10][10];
int p[10];
int N;
int M;
int find(void);
int dfs(int i, int j, int n);

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &p[i]);
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		printf("#%d %d\n", tc, find());
	}
	
	return 0;
}

int find(void)
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if( arr[i][j] == p[0])
			{
				if( dfs(i, j, 0) == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int dfs(int i, int j, int n)
{
	int di[] = {0, 1, 0, -1};
	int dj[] = {1, 0, -1, 0};
	int ni, nj;
	if( n == N )
	{
		return 1;
	}
	else
	{
		used[i][j] = 1;
		for(int k = 0; k < 4; k++)
		{
			ni = i + di[k];
			nj = j + dj[k];
			if( 0<=ni && ni<M && 0<=nj && nj<M)
			{
				if((arr[ni][nj] == p[n+1]) && (used[ni][nj] == 0))
				{
					if(dfs(ni, nj, n + 1) == 1)
					{
						used[i][j] = 0;
						return 1;
					}
				}
			}
		}
		used[i][j] = 0;
		return 0;
	}
}

