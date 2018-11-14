#include <stdio.h>
/*
5 6
1 2 1 3 3 2 2 5 5 4 3 4
*/
int V;
int E;
int adj[6][6]; // 1~5번 노드인 경우 
int visited[6]; // 노드의 방문 여부를 기록 

int top = -1;
int stack[5];
void dfs(int n);
void dfs2(int n);
 
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
	//dfs(1);
	dfs2(1);
	return 0;
}

void dfs(int n)
{
	visited[n] = 1; // 방문 기록
	printf("%d", n);
	for( int i = 1; i <= V; i++)
	{
		// n에 인접하고, 아직 미방문인 노드 i 검색... 
		if(( adj[n][i] != 0 ) && ( visited[i] == 0))
		{
			dfs(i);
		}
	}
}

void dfs2(int n)
{
	stack[++top] = n; // push(n) 시작노드 push
	visited[n] = 1;
	while( top != -1 ) // 스택이 비어있지 않으면 반복
	{
		n = stack[top--]; // n = pop()
		printf("%d ", n);
		for(int i = 1; i <= V; i++)
		{
			if((adj[n][i] != 0) && ( visited[i] == 0)) // i가 n에 인접하고 방문하지 않은 노드면 
			{
				stack[++top] = i;
				visited[i] = 1;
			}
		} 
	} 
	
}
