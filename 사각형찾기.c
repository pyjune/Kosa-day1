#include <stdio.h>

int main(void)
{
	int tcase, T;
	int i, j, N;
	int row, col, r, c;
	int max;
	int m[100][100];

	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%d", &N);
		max = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf("%d", &m[i][j]);
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (m[i][j])
				{
					r = 0;
					
					while (m[i+r][j] != 0)
					{
						c = 0;
						while (m[i+r][j + c] != 0)
						{
							m[i + r][j + c] = 0;
							c++;
						}
						r++;
					}
					
					if (max < r*c)
						max = r*c;
					
				}
			}
		}
		printf("#%d %d\n", tcase, max);
	}
}
