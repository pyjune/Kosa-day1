#include <stdio.h>

int maze[100][100];
int N;
int bfs(int sr, int sc);
int visited[100][100]; // 출발로 부터의 거리를 기록하기 위한 배열.. 
int q[10000];
int front;
int rear;

int main(void) 
{
	int T;
	freopen("input.txt","r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int data;
		int sr, sc;
		front = -1;
		rear = -1;
		
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
		printf("#%d %d\n", tc, bfs(sr, sc)); // 지나온 칸에서 출발점 제외 
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				visited[i][j] = 0;
			}
		}
	}
	return 0;
}

int bfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1};
	int dc[] = { 1, 0, -1, 0};
	int nr, nc;
	// 시작점 인큐, 방문표시..
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1;
	while( front != rear) // 큐가 비어있지 않으면 반복
	{
		r = q[++front];
		c = q[++front];
		if(maze[r][c] == 3) // 목적지인지 확인...
		{
			return (visited[r][c] - 2);
		}
		// r, c칸의 인접하고 미방분인 칸을 인큐... 
		for(int i = 0 ; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if((maze[nr][nc] != 1) && ( visited[nr][nc] == 0))
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;
			}
		}
	} 
	return 0;
}
