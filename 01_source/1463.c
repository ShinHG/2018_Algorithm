//#include <stdio.h>
//#define MIN(a,b) a>b?b:a
//int dp[1000001];
//int N;
//int main() {
//	scanf("%d", &N);
//	dp[1] = 0;
//
//	for (int i = 2; i <= N; i++) {
//		if (i % 3 == 0) {
//			if (i % 2 == 0) {
//				dp[i] = MIN(MIN(dp[i / 3] + 1, dp[i / 2] + 1), dp[i - 1] - 1);
//			}
//			dp[i] = dp[i / 3] + 1;
//		}
//		else if (i % 2 == 0) {
//			dp[i] = MIN(dp[i / 2] + 1, dp[i - 1] + 1);
//		
//		}
//		else dp[i] = dp[i - 1] + 1;
//	}
//
//	printf("%d\n", dp[N]);
//return 0;
//}


#include <stdio.h>
#include <malloc.h>
#define MIN(x,y) x>y?y:x
int dp[1000001];
int main() {
	int N;
	
	scanf("%d", &N);
	dp[1] = 0;
	dp[2] = dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		if (i % 3 == 0) dp[i] = dp[i / 3] + 1;
		if (i % 2 == 0) {
			if (dp[i] != 0)
				dp[i] = MIN(dp[i], dp[i / 2] + 1);
			else dp[i] = dp[i / 2] + 1;
		}
		if (dp[i] != 0)
			dp[i] = MIN(dp[i], dp[i - 1] + 1);
		else dp[i] = dp[i - 1] + 1;
	}

	printf("%d\n", dp[N]);

	return 0;
}