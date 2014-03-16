// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: CircularAnimationStrategy.cpp
 * Software Used: Geany
*/

#include "CircularAnimationStrategy.h"
#include <cmath>

CircularAnimationStrategy::CircularAnimationStrategy(Point origin)
{
	const double PI = 3.14159265358979323846;
	
	// Assign the various points
	centerPoint = origin;
	assignRotationPoint();
	
	// Vector that determines the x and y value lengths from the 
	// center point to the starting point
	Vector length(abs(startingPoint.getX() - centerPoint.getX()), 
				  abs(startingPoint.getY() - centerPoint.getY()));

	// Double value that determines the length of the above vector
	radiusOfRotation = sqrt(pow(length.getX(), 2) + 
							pow(length.getY(), 2));
	
	// Determines the starting degree of the shape in accordance to
	// the unit circle
	degree = acos((startingPoint.getX() - centerPoint.getX())/radiusOfRotation)*180/PI;	
}

Point CircularAnimationStrategy::nextPosition(Point crt, double dt)
{
	// Update the degree value dependant on the time
	degree += speedOfRotation*dt;
	
	// Rotate the point
	crt.rotate(centerPoint, crt, radiusOfRotation, degree);
	
	return crt;
}

void CircularAnimationStrategy::randomSpeedVector()
{
	speedOfRotation = rand() % 76 + 25;
}

void CircularAnimationStrategy::assignRotationPoint()
{
	startingPoint.setX(centerPoint.getX() + (rand() % 51 + 25));
	startingPoint.setY(centerPoint.getY() + (rand() % 51 + 25));
}
	
