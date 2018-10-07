#include <stdio.h>
#define MAX 100000

int N, K;
int qp1, qp2;
int que[MAX + 1];
int time[MAX + 1];

void BFS() {
	while (1) {
		if (que[qp1] == K) return;
		if (que[qp1] - 1 >= 0 && time[que[qp1]-1] == 0) {
			que[qp2] = que[qp1] - 1;
			time[que[qp2]] = time[que[qp1]] + 1;
			qp2++;
		}
		if (que[qp1] + 1 <= MAX && time[que[qp1] + 1] == 0) {
			que[qp2] = que[qp1] + 1;
			time[que[qp2]] = time[que[qp1]] + 1;
			qp2++;
		}
		if (que[qp1] * 2 <= MAX && time[que[qp1] * 2] == 0) {
			que[qp2] = que[qp1] * 2;
			time[que[qp2]] = time[que[qp1]] + 1;
			qp2++;
		}
		qp1++;
	}
}

int main() {
	scanf("%d %d", &N, &K);

	que[qp2] = N;
	time[N] = 1;
	qp2++;
	BFS();
	printf("%d\n", time[K]-1);

	return 0;
}