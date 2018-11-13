#include <stdio.h>

int h[101];
int last;
void enq(int n);

int main(void) 
{
	int T;
	int N;
	int s;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		last = 0;
		s = 0;
		for(int i = 0; i < N; i++)
		{
			int data;
			scanf("%d", &data);
			enq(data);
		}
		// 마지막 노드의 조상 노드...
		last /= 2; // 마지막 노드의 부모 노드 부터.. 
		while( last > 0) 
		{
			s += h[last];
			last /= 2;
		}
		printf("#%d %d\n", tc, s);
	}
	return 0;
}

void enq(int n)
{
	int p, c;
	++last;
	h[last] = n; // 완전이진트리 유지 
	c = last;
	p = c / 2;
	while(( p > 0) && (h[p] > h[c])) // 부모가 있고, 자식이 더 작으면 
	{
		int t = h[c]; // 부모와 자식 데이터 교환 
		h[c] = h[p];
		h[p] = t;
		c = p;
		p = c / 2;	
	}
}
