#include <stdio.h>

int T, n;
int dp[12];

int main() {
	scanf("%d", &T);
	dp[1] = 1;
	dp[2] = dp[1] + 1;
	dp[3] = dp[2] + dp[1] + 1;

	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}