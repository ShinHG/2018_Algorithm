#include <stdio.h>

int N, M, V;
int stack[10001], que[10001], visit[10001], visit2[10001];
int sp, qp1, qp2;
int map[1001][1001];
int node1, node2;

void DFS() {
	stack[sp] = V;
	visit[V] = 1;
	printf("%d ", V);
	while (1) {
		if (sp == -1)break;
		for (int i = 1; i <= N; i++) {
			if (map[stack[sp]][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				sp++;
				stack[sp] = i;
				printf("%d ", i);
				i = 0;
				continue;
			}
		}
		sp--;
	}
}

void BFS() {
	que[qp2] = V;
	qp2++;
	visit2[V] = 1;
	printf("%d ", V);
	while (1) {
		if (qp1 == qp2)break;
		for (int i = 1; i <= N; i++) {
			if (map[que[qp1]][i] == 1 && visit2[i] == 0) {
				que[qp2] = i;
				printf("%d ", i);
				qp2++;
				visit2[i] = 1;
			}
		}
		qp1++;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &node1, &node2);
		map[node1][node2] = 1;
		map[node2][node1] = 1;
	}

	DFS();
	printf("\n");
	BFS();

	return 0;
}