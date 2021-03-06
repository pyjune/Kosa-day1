#include <stdio.h>

int a[10000];
int tree[1000000];

int makeT(int n, int s, int e);
int findT(int n, int s, int e, int l, int r);
void changeT(int n, int s, int e, int i, int data);

int main(void) 
{
	int T;
	int N, M;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int maxV = 0;
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);
		}
		makeT(1, 0, N-1);
		for(int i = 0; i < M; i++)
		{
			int l, r;
			int v;
			scanf("%d %d", &l, &r);
			v = findT(1, 0, N-1, l, r);
			if( maxV < v)
			{
				maxV = v;
			}
		}
		printf("#%d %d\n", tc, maxV);
	}
	return 0;
}

void changeT(int n, int s, int e, int i, int data)
{
	int diff = data - a[i];
	while( s != e )
	{
		tree[n] += diff;
		if (i <= ((s + e) / 2)) // 왼쪽 자식노드 구간이 i를 포함하면 
		{
			n = n * 2;
			e = (s + e) / 2;
		}
		else
		{
			n = n * 2 + 1;
			s = (s + e) / 2 + 1;
		}	
	}
	tree[n] += diff; // leaf 노드에 적용... 
}

int findT(int n, int s, int e, int l, int r)
{
	if(( r < s)||( e < l)) // 노드의 구간이 검색 구간을 벗어나면 
	{
		return 0;
	}
	else if((l <= s) && (e <= r)) // 노드 구간이 검색 구간에 포함
	{
		return tree[n];	
	}
	else
	{
		int r1 = findT(n * 2, s, (s + e) / 2, l, r);
		int r2 = findT(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
		return (r1 + r2);
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
		tree[n] = r1 + r2;
		return tree[n];
	}
}
