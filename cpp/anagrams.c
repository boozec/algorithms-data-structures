#include <stdio.h>
#include <string.h>
void swap(char* a, char* b) {
	char t = *a;
	*a = *b;
	*b = t;
}

void anagrams(char* str, int l, int r) {
	if(l == r)
		printf("%s\n", str);
	else
		for(int i = l; i < r; i++) {
			swap(&str[l], &str[i]);
			anagrams(str, l+1, r);
			//swap(&str[l], &str[i]);
		}
}

int main() {
	char str[30];
	scanf("%s", str);
	anagrams(str, 0, strlen(str));
	return 0;
}
