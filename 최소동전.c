#include <stdio.h>

int q[100];
int front = -1;
int rear = -1;

int V;
int E;
int adj[101][101];
int coin[101];
int ind[101];
int find(void);

int main(void) {
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E); // 사람수, 비교횟수
		for(int i = 0; i < E; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
			ind[n2]++; // 진입차수 
		} 
		printf("#%d %d\n", tc, find());
		
		front = -1;
		rear = -1;
		for(int i = 1; i <= V; i++)
		{
			ind[i] = 0;
			coin[i] = 0;
			for(int j = 1; j <= V; j++)
			{
				adj[i][j] = 0;	
			}
		}
	}
	
	return 0;
}

int find(void)
{
	int n;
	int maxV;
	for(int i = 1; i <= V; i++ )
	{
		if( ind[i] == 0 ) // 진입차수가 0이면
		{
			q[++rear] = i;
			coin[i] = 1; // 최소한의 동전을 가진 사람 
		} 
	}
	while( front != rear )
	{
		n = q[++front];
		for(int i = 1; i <= V; i++)
		{
			if( adj[n][i] != 0 )
			{
				ind[i]--; // n에 인접인 노드의 진입차수 감소..
				if( ind[i] == 0 )
				{
					q[++rear] = i;
					coin[i] = coin[n] + 1;
					maxV = coin[i];
				} 
			}
		}
		
	}
	return maxV; // 마지막에 결정된 동전의 개수가 최대개수... 
}
