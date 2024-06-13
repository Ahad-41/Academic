#include<stdio.h>
#include<string.h>

#define N 1000
int dp[N][N];
char s1[N];
char s2[N];

int LCS(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int ans = 0;
    int firstWay = LCS(i-1, j);
    if (firstWay > ans) ans = firstWay;
    
    int secondWay = LCS(i, j-1);
    if (secondWay > ans) ans = secondWay;

    int thirdWay = LCS(i-1, j-1) + (s1[i] == s2[j]);
    if (thirdWay > ans) ans = thirdWay;

    return dp[i][j] = ans;
}

int main()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    gets(s1);
    gets(s2);

    int n = strlen(s1);
    int m = strlen(s2);

    int length = LCS(n-1, m-1);
    printf("%d\n",length);
}

