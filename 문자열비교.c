#include <stdio.h>

int strLen(char s[]);

int main(void)
{
	int tcase, T;
	int i, j;
	int N, M;

	char p[101];
	char t[1001];

	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%s", p);
		scanf("%s", t);
		N = strLen(p);
		M = strLen(t);

		printf("#%d", tcase);
		for (i = 0; i <= M - N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (p[j] != t[i + j])
					break; // 패턴과 글자가 다른 경우 중단. 다음 구간으로.
			}
			if (j == N) // 패턴과 일치하는 경우.
				break; // 다음 구간 비교가 불필요..
		}
		if (j == N)
		{
			printf(" 1\n");
		}
		else
		{
			printf(" 0\n");
		}
	}

}

int strLen(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
