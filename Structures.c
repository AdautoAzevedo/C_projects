#include <stdio.h>
#include <stdlib.h>


// A structure is a user-defined data type that allows grouping different types of variables under a single name.
typedef struct {
	int x;
	int y;
} Point;
	
// The typedef keyword allow us to give a alias 'Point' for the structure type
typedef struct {
	int x;
	int y;
} Coordinate;

typedef struct {
	Coordinate topLeft;
	Coordinate rightBottom;
} Rectangle;


int main() {
	Point p1;
	p1.x = 10;
	p1.y = 20;
		
	printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);
	
	Rectangle rect;
	rect.topLeft.x = 0;
	rect.topLeft.y = 10;
	rect.rightBottom.x = 20;
	rect.rightBottom.y = 0;

	printf("Rectangle top left: (%d, %d)\n", rect.topLeft.x, rect.topLeft.y);
	printf("Rectangle bottom right: (%d, %d)\n", rect.rightBottom.x, rect.rightBottom.y);


	//We can also create arrays of structures
	Point points[3];
	
	points[0].x = 1; points[0].y = 2;
	points[1].x = 3; points[1].y = 4;
	points[2].x = 5; points[2].y = 6;
	
	int i;
	for ( i = 0; i < 3; i++) {
		printf("Point %d coordinates: (%d, %d)\n", i+1, points[i].x, points[i].y);
	}
	
	return 0;
}
