// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: RectilinearAnimationStrategy.cpp
 * Software Used: Geany
*/
#include "RectilinearAnimationStrategy.h"
#include <cstdlib>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/
RectilinearAnimationStrategy::RectilinearAnimationStrategy(int width, int height)
{
	displayWidth = width;
	displayHeight = height;
}

Point RectilinearAnimationStrategy::nextPosition(Point crt, double dt)
{
	// Change current point to reflect the time and speed
	crt.setX(crt.getX() + dt * speedVector.getX());
	crt.setY(crt.getY() + dt * speedVector.getY());
	return crt;
}

void RectilinearAnimationStrategy::checkValidityOfCurrentShape(Point& origin,  Point minimum,  Point maximum)
{
	// Call helper functions to make sure the shape is in bounds
	checkLessThanXAxis(origin, minimum);
	checkGreaterThanXAxis(origin, maximum);
	checkLessThanYAxis(origin, minimum);
	checkGreaterThanYAxis(origin, maximum);
}

void RectilinearAnimationStrategy::checkLessThanXAxis(Point& origin, Point minimum)
{
	if (minimum.getX() <= 0)
	{
		origin.setX(origin.getX() + (0 - minimum.getX()));
								 
		speedVector.setX((speedVector.getX())*-1);
	}
}

void RectilinearAnimationStrategy::checkGreaterThanXAxis(Point& origin, Point maximum)
{
	if (maximum.getX() >= displayWidth)
	{
		origin.setX(origin.getX() - (maximum.getX() - displayWidth));
								 
		speedVector.setX((speedVector.getX())*-1);
	}
}

void RectilinearAnimationStrategy::checkLessThanYAxis(Point& origin, Point minimum)
{
	if (minimum.getY() <= 0)
	{
		origin.setY(origin.getY() + (0 - minimum.getY()));
								
		speedVector.setY((speedVector.getY())*-1);
	}
}

void RectilinearAnimationStrategy::checkGreaterThanYAxis(Point& origin, Point maximum)
{
	if (maximum.getY() >= displayHeight)
	{
		origin.setY(origin.getY() - (maximum.getY() - displayHeight));
				
		speedVector.setY((speedVector.getY())*-1);
	}
}
	
void RectilinearAnimationStrategy::randomSpeedVector()
{
	speedVector.setX(0);
	speedVector.setY(0);
	
	// Ensures that we don't get a zero vector
	while (speedVector.getX() == 0 || speedVector.getY() == 0)
	{
		speedVector.setX(rand() % 200 - 100);
		speedVector.setY(rand() % 200 - 100);
	}
}
