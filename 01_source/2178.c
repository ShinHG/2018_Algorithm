#include <stdio.h>

int main() {
	int N, M;
	int map[101][101];
	int visit[101][101];
	int queX[10001];
	int queY[10001];
	int q_start = 0, q_end = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			visit[i][j] = 0;
		}
	queX[q_end] = 0;
	queY[q_end] = 0;

	visit[queY[q_end]][queX[q_end]]++;

	for (;; q_start++) {
		if (queX[q_start] == M - 1 && queY[q_start] == N - 1) {
			printf("%d\n", visit[queY[q_start]][queX[q_start]]);
			break;
		}

		if (queX[q_start] + 1 < M && map[queY[q_start]][queX[q_start] + 1] == 1
			&& visit[queY[q_start]][queX[q_start] + 1] == 0) {
			//오른쪽으로 길 있을 때
			visit[queY[q_start]][queX[q_start] + 1] = visit[queY[q_start]][queX[q_start]] + 1;
			q_end++;
			queX[q_end] = queX[q_start] + 1;
			queY[q_end] = queY[q_start];
		}

		if (queY[q_start] + 1 < N && map[queY[q_start] + 1][queX[q_start]] == 1
			&& visit[queY[q_start] + 1][queX[q_start]] == 0) {
			//밑으로 길 있을 때
			visit[queY[q_start] + 1][queX[q_start]] = visit[queY[q_start]][queX[q_start]] + 1;
			q_end++;
			queX[q_end] = queX[q_start];
			queY[q_end] = queY[q_start] + 1;
		}

		if (queX[q_start] - 1 >= 0 && map[queY[q_start]][queX[q_start] - 1] == 1
			&& visit[queY[q_start]][queX[q_start] - 1] == 0) {
			//왼쪽으로 길 있을 때
			visit[queY[q_start]][queX[q_start] - 1] = visit[queY[q_start]][queX[q_start]] + 1;
			q_end++;
			queX[q_end] = queX[q_start] - 1;
			queY[q_end] = queY[q_start];
		}

		if (queY[q_start] - 1 >= 0 && map[queY[q_start] - 1][queX[q_start]] == 1
			&& visit[queY[q_start] - 1][queX[q_start]] == 0) {
			//위로 길 있을 때
			visit[queY[q_start] - 1][queX[q_start]] = visit[queY[q_start]][queX[q_start]] + 1;
			q_end++;
			queX[q_end] = queX[q_start];
			queY[q_end] = queY[q_start] - 1;
		}

	}

	return 0;
}