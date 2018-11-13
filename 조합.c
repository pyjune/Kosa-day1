#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[] = {1,2,3};
int c[2];

void ncr(int n, int k, int m); // n개에서 k개를 고르는 단계, 조합의 크기 m

int main(int argc, char *argv[]) 
{
	ncr(3, 2, 2);
	return 0;
}

void ncr(int n, int k, int m)
{
	if( k == 0)
	{
		for(int i= 0; i<m; i++)
		{
			printf("%d", c[i]);
		}
		printf("\n");
	}
	else if( n < k)
	{
		return;
	}
	else
	{
		c[k-1] = a[n-1];
		ncr(n - 1, k - 1, m);
		ncr(n - 1, k, m);
	}
}
