// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #2
 * Shape Class Implmenetation
 * Professor: Robert  Benkoczi
 * Program Name: Shape.cpp
 * Software Used: Geany
*/
#include "Shape.h"

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

void Shape::translate(Vector& v)
{
	// Translate function used by all children
	origin.setX(origin.getX() + v.getX());
	origin.setY(origin.getY() + v.getY());
}

void Shape::getAnimation(int width, int height)
{
	chosenAnimation = new RectilinearAnimationStrategy(width, height);
	chosenAnimation->randomSpeedVector();
}

double Shape::getMinX()
{
	return minimum.getX();
}

double Shape::getMinY()
{
	return minimum.getY();
}

double Shape::getMaxX()
{
	return maximum.getX();
}

double Shape::getMaxY()
{
	return maximum.getY();
}
