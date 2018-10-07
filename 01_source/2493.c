#include <stdio.h>

int N;
int stack[500001][2] = { 100000001, -1 };
int sp = 1;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		
		while (1) {
			if (stack[sp-1][0] >= tmp) {
				printf("%d ", stack[sp-1][1]+1);
				stack[sp][0] = tmp;
				stack[sp][1] = i;
				sp++;
				break;
			}
			else {
				if (sp == 1) {
					printf("0 ");
					break;
				}
				sp--;
			}
		}
	}
	return 0;
}