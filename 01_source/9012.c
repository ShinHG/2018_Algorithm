#include <stdio.h>

int N;
char str[51];
int sp = 0;

int isVPS() {
	for (int j = 0; str[j] != '\0'; j++) {
		if (str[j] == '(') sp++;
		else {
			if (sp == 0) return 0;
			else sp--;
		}
	}
	if (sp == 0) return 1;
	else return 0;
}

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", &str);
		sp = 0;

		if (isVPS() == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}