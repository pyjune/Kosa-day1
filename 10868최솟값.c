#include <stdio.h>

int a[100001];
int tree[1000000];

int makeT(int n, int s, int e);
int findT(int n, int s, int e, int l, int r);

int main(void) 
{
	int N, M;
	
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}
	makeT(1, 1, N);
	for(int i = 0; i < M; i++)
	{
		int l, r;
		int v;
		scanf("%d %d", &l, &r);
		v = findT(1, 1, N, l, r);
		printf("%d\n", v);
	}

	return 0;
}

int findT(int n, int s, int e, int l, int r)
{
	if(( r < s)||( e < l)) // 노드의 구간이 검색 구간을 벗어나면 
	{
		return 0x7fffffff;
	}
	else if((l <= s) && (e <= r)) // 노드 구간이 검색 구간에 포함
	{
		return tree[n];	
	}
	else
	{
		int r1 = findT(n * 2, s, (s + e) / 2, l, r);
		int r2 = findT(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
		return ((r1 < r2)? r1: r2);
	}
}

int makeT(int n, int s, int e)
{
	if( s == e ) // leaf
	{
		tree[n] = a[s];
		return tree[n];
	}
	else
	{
		int r1 = makeT( n * 2, s, (s + e) / 2);
		int r2 = makeT( n * 2 + 1, (s + e) / 2 + 1, e);
		tree[n] = (r1 < r2)? r1: r2;
		return tree[n];
	}
}
