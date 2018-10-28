#include <stdio.h>

int T, N;
int cnt0[41], cnt1[41];

int main(){
	scanf("%d", &T);

	cnt0[0] = 1;
	cnt0[1] = 0;
	cnt1[0] = 0;
	cnt1[1] = 1;

	for (int i = 2; i <= 40; i++) {
		cnt0[i] = cnt0[i - 1] + cnt0[i - 2];
		cnt1[i] = cnt1[i - 1] + cnt1[i - 2];
	}

	while (T--) {
		scanf("%d", &N);
		printf("%d %d\n", cnt0[N], cnt1[N]);
	}

	return 0;
}