#include <stdio.h>
#define print(r) printf("%d\n", r)

#define MAX_STUDENTS 2




int main() {
	int count = 4;
	while (--count) print(count);
	do(print(count));
	while(count > 0);
}