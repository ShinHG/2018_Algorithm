#include<stdio.h>

int T, M, N, K;
int map[51][51];
int visit[51][51];
int bug;

void DFS(int x, int y) {
	if (x + 1 <= N && visit[x + 1][y] == 0 && map[x + 1][y] == 1) {
		visit[x + 1][y] = bug;
		DFS(x + 1, y);
	}
	if (x - 1 >= 0 && visit[x - 1][y] == 0 && map[x - 1][y] == 1) {
		visit[x - 1][y] = bug;
		DFS(x - 1, y);
	}
	if (y + 1 <= M && visit[x][y + 1] == 0 && map[x][y + 1] == 1) {
		visit[x][y + 1] = bug;
		DFS(x, y + 1);
	}
	if (y - 1 >= 0 && visit[x][y - 1] == 0 && map[x][y - 1] == 1) {
		visit[x][y - 1] = bug;
		DFS(x, y - 1);
	}
	return;
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		bug = 0;
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					bug++;
					visit[i][j] = bug;
					DFS(i, j);
				}
			}
		}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d", visit[i][j]);
			}
			printf("\n");
		}
*/
		printf("%d\n", bug);
	}
	return 0;
}