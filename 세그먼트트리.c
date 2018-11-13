#include <stdio.h>

int a[5] = { 1, 2, 3, 4, 5};
int tree[1000000];

int makeT(int n, int s, int e);

int main(void) 
{
	makeT(1, 0, 4);

	return 0;
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
