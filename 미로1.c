#include <stdio.h>

int maze[100][100];
int N;
int find(int r, int c);

int main(void) 
{
	int T;
	freopen("input.txt","r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int data;
		int sr, sc;
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
		printf("#%d %d\n", tc, find(sr, sc));
	}
	return 0;
}

int find(int r, int c)
{
	int dr[] = { 0, 1, 0, -1};
	int dc[] = { 1, 0, -1, 0};
	int nr, nc;
	
	if( maze[r][c] == 3)
	{
		return 1;
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
				if( find(nr, nc) == 1)
				{
					return 1;
				}
			} 
		}
		return 0;	
	}
}


