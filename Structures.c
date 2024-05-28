#include <stdio.h>
#include <stdlib.h>


// A structure is a user-defined data type that allows grouping different types of variables under a single name.
struct Point {
		int x;
		int y;
	};
	

int main() {
	struct Point p1;
	p1.x = 10;
	p1.y = 20;
	
	printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);
	
	return 0;
}
