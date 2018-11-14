#include <stdio.h>

int q[5];
int front = -1;
int rear = -1;

int V;
int E;
int adj[6][6];
int visited[6];

void bfs(int n);
int bfs2(int n, int k); // n에서 k까지 가는 최단거리를 리턴 
 
int main(void) 
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 무향그래프인 경우 
	}
	
	bfs(1);
	
	return 0;
}

void bfs(int n)
{
	// 초기화
	q[++rear] = n; // 시작노드 인큐
	visited[n] = 1; // 방문표시 
	// 반복 
	while( front != rear ) // 큐가 비어있지 않으면 반복 
	{
		n = q[++front]; // 디큐
		printf("%d ", n);
		for(int i = 1; i <= V; i++)
		{
			if(( adj[n][i] != 0 ) && (visited[i] == 0))
			{
				q[++rear] = i;
				visited[i] = visited[n] + 1; // 거리가 같은 노드는 같은 값 
			}
		} 
	}
}

int bfs2(int n, int k)
{
	// 초기화
	q[++rear] = n; // 시작노드 인큐
	visited[n] = 1; // 방문표시 
	// 반복 
	while( front != rear ) // 큐가 비어있지 않으면 반복 
	{
		n = q[++front]; // 디큐
		if( n == k ) // 
		{
			return (visited[n] - 1);
		}
		for(int i = 1; i <= V; i++)
		{
			if(( adj[n][i] != 0 ) && (visited[i] == 0))
			{
				q[++rear] = i;
				visited[i] = visited[n] + 1; // 거리가 같은 노드는 같은 값 
			}
		} 
	}
	return 0; // k에 도착할 수 없는 경우 
}
