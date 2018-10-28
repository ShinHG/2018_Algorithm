#include <stdio.h>

int N;
int T[15], P[15], pay[16];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &T[i], &P[i]);
	}

	pay[1] = P[1];

	for (int i = 2; i <= N; i++) {
		int tmp1 = 0, tmp2 = 0;
		for (int j = 1; j <= 4; j++) {
			if (i - j >= 0 && j >= T[i - j]) {

			}
		}

	}

	return 0;
}