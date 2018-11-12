#include <stdio.h>

int main(void)
{
	
	int tcase, T;
	int sr, sc, pr, pc, color;
	int i, N;
	int r, c;
	int v;

	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		int m[10][10] = { 0 };
		v = 0;
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d %d %d %d %d", &sr, &sc, &pr, &pc, &color);
			for (r = sr; r <= pr; r++)
			{
				for (c = sc; c <= pc; c++)
				{
					m[r][c] += color;
				}
			}
		}
		for (r = 0; r < 10; r++)
		{
			for (c = 0; c < 10; c++)
			{
				if (m[r][c] == 3)
				{
					v++;
				}
			}
		}
		printf("#%d %d\n", tcase, v);
	}
	return 0;
}
