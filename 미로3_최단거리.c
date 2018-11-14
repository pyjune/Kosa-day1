#include <stdio.h>

int maze[100][100];
int N;
void find(int r, int c, int e);
int cnt;
int minV;
int main(void) 
{
	int T;
	freopen("input.txt","r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int data;
		int sr, sc;
		minV = 10000;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%1d", &data);
				maze[i][j] = data;
				if( data == 2 )
				{
					sr = i;
					sc = j;
				}
			}
		}
		find(sr, sc, 0);
		if ( minV == 10000)
		{
			minV = 1; // 도착못하는 경우 0을 출력하기 위해.. 
		}
		printf("#%d %d\n", tc, minV - 1); // 지나온 칸에서 출발점 제외 
	}
	return 0;
}

void find(int r, int c, int e)
{
	int dr[] = { 0, 1, 0, -1};
	int dc[] = { 1, 0, -1, 0};
	int nr, nc;
	
	if( maze[r][c] == 3)
	{
		if( minV > e)
		{
			minV = e;
		}
	}
	else
	{
		maze[r][c] = 1; // 지나간 칸은 벽으로 변경 
		for(int i = 0 ; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if( maze[nr][nc] != 1) // 벽이 아니면 인접...
			{
				find(nr, nc, e + 1);
			} 
		}
		maze[r][c] = 0;
	}
}
