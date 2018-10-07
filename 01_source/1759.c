#include <stdio.h>

int L, C;
char alpha[16];
int stack[16];
int sp;

void DFS(int pos, int s) {
	//printf("pos: %d\n", pos);
	if (pos == L) {
		int ja = 0, mo = 0;
		for (int i = 0; i < L; i++) {
			if (alpha[stack[i]] == 'a' || alpha[stack[i]] == 'e' ||
				alpha[stack[i]] == 'i' || alpha[stack[i]] == 'o' || alpha[stack[i]] == 'u')
				mo++;
			else ja++;
		}

		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < L; i++)
				printf("%c", alpha[stack[i]]);
			printf("\n");
		}
		return;
	}
	for (int i = s; i < C; i++) {	
		stack[pos] = i;
		DFS(pos + 1, stack[pos]+1);
	}
}

int main() {
	scanf("%d%d", &L, &C);

	for (int i = 0; i < C;) {
		char tmp;
		scanf("%c", &tmp);
		if (tmp != ' ' && tmp!= '\n') {
			alpha[i] = tmp;
			i++;
		}
	}
	
	for (int i = 0; i < C; i++) {
		for (int j = i + 1; j < C; j++) {
			if (alpha[i] > alpha[j]) {
				int tmp = alpha[j];
				alpha[j] = alpha[i];
				alpha[i] = tmp;
			 }
		}
	}
	DFS(0,0);

	return 0;
}