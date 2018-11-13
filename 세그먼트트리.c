#include <stdio.h>

int a[5] = { 1, 2, 3, 4, 5};
int tree[1000000];

int makeT(int n, int s, int e);

int main(void) 
{
	makeT(1, 0, 4);
	printf("%d\n", findT(1, 0, 4, 1, 3));
	return 0;
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
