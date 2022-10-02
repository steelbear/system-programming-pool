#include <stdio.h>

int main() {
	int a = 3;
	char b = 'x';

	printf("%d %c\n", a, b);
	printf("%d %d\n", sizeof(a), sizeof(b));
	
	int* ap = &a;
	char* bp = &b;

	printf("%d %c %p %p\n", a, b, ap, bp);
	printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(ap), sizeof(bp));
	printf("%d %c\n", *ap, *bp);
	
	*ap = 4;
	printf("%d %p\n", *ap, ap);

	return 0;
}
