#include <stdio.h>
#define MAX(a,b) a>b?a:b

int N, buffer;
long long dp[101];

int main() {
	scanf("%d", &N);

	for (int i = 0; i <= 3; i++) {
		dp[i] = i;
	}
	for (int i = 4; i <= N; i++) {
		if (dp[i] < dp[i - 1] + 1) dp[i] = dp[i - 1] + 1;
		for (int j = 1; i-j >= 3; j++) {
			if (dp[i] < dp[i - j - 2] * (j+1))
				dp[i] = dp[i - j - 2] * (j+1);
		}
	}

	printf("%lld\n", dp[N]);
	return 0;
}