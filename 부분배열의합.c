#include <stdio.h>

int arr[100][100]; 

int main(void) 
{
	
	int tc, T;
	int N, n, m;
	int i, j;
	int k,l;
	int sum;
	int max;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d %d %d", &N, &n, &m);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}	
		max = 0;
		for(i=0;i<=N-n;i++)
		{
			for(j=0;j<=N-m;j++) // 배열의 i, j부터.. 
			{
				sum=0;
				for(k=0;k<n;k++)// 아래로 k번빼줄 ..
				{
					for(l=0;l<m;l++)// 오른쪽으로 l번째 칸.. 
					{
						sum+= arr[i+k][j+l];
					}
				}
				if(max<sum)
					max=sum; 
			}
		}
		// 모든 nxm 영역을 계산하고 나면..
		printf("#%d %d\n", tc, max); 
		
	}	
	
	return 0;
}
