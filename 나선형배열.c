#include <stdio.h>

int main(void)
{
	int a[100][100];
	int tcase, T;
	int i, N;
	int R, C, r, c;
	int k;

	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%d %d %d", &N, &R, &C);
		k = 1;
		for (i = 0; i <= N / 2; i++)
		{
			r = i;
			for (c = i; c < N - i - 1; c++) //  윗변 → 
				a[r][c] = k++;
			for (r = i; r < N - i - 1; r++) // 오른쪽 변↓
				a[r][c] = k++;
			for (c = N - i - 1; c > i; c--) // 아랫변 ←
				a[r][c] = k++;
			for (r = N - i - 1; r > i; r--) // 왼쪽 변↑
				a[r][c] = k++;

		}
		a[r][c] = k; // 중심부는 따로 처리합니다.
		printf("#%d %d\n", tcase, a[R][C]);
	}
}
