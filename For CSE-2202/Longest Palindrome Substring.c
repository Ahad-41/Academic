#include<stdio.h>
#include<string.h>

#define N 1000
int dp[N][N];
char s[N];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int LPS(int i, int j, int count) {
	if (i > j) return count;
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) return dp[i][j] = count + 1;

	if (s[i] == s[j]) {
		int ans = 0;
		int firstWay = LPS(i + 1, j - 1, count + 2);
		if (firstWay > ans) ans = firstWay;

		int secondWay = LPS(i + 1, j, 0);
		if (secondWay > ans) ans = secondWay;

		int thirdWay = LPS(i, j - 1, 0);
		if (thirdWay > ans) ans = thirdWay;
		return dp[i][j] = ans;
	}
	
	return dp[i][j] = max(LPS(i + 1, j, 0), LPS(i, j - 1, 0));
}

int main()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    gets(s);
    int n = strlen(s);

    int length = LPS(0, n-1, 0);
    printf("%d\n",length);
}