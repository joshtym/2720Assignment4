// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Implmenetation
 * Professor: Robert  Benkoczi
 * Program Name: Shape.cpp
 * Software Used: Geany
*/
#include "Vector.h"

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/
double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

void Vector::setX(double userX)
{
	x = userX;
}

void Vector::setY(double userY)
{
	y = userY;
}
