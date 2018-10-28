#include <stdio.h>
#define MOD 1000000000

int N;
int dp[10][101];
int dap;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= 9; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= 100; i++) {
		dp[0][i] += dp[1][i - 1];
		dp[0][i] %= MOD;
		dp[9][i] += dp[8][i - 1];
		dp[9][i] %= MOD;
		for (int j = 1; j <= 8; j++) {
			dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
			dp[j][i] %= MOD;
		}
	}

	for (int i = 0; i <= 9; i++) {
		dap += dp[i][N];
		dap %= MOD;
	}
	printf("%d\n", dap % MOD);

	return 0;
}