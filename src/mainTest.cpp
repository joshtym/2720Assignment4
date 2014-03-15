#include "ShapeContainer.h"

int main()
{
	
	ShapeContainer shapes();
	
	shapes.insert("triangle", 100, 0, 0, 60);
	shapes.insert("square", 100, 0, 0, 0);
	shapes.insert("circle", 100, 0, 0, 0);
	
	return 0;
}
