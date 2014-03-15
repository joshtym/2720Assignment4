// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Implmenetation
 * Professor: Robert  Benkoczi
 * Program Name: Point.cpp
 * Software Used: Geany
*/
#include "Point.h"
#include <cmath>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/
double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

void Point::setX(double userX)
{
	x = userX;
}

void Point::setY(double userY)
{
	y = userY;
}

void Point::rotate(const Point& p1, Point& p2, double length, 
                   double degree)
{
	// Math to allow for the rotation around one point
	const double PI = 3.14159265358979323846;
	p2.setX(p1.getX() + length*cos(PI*degree/180));
	p2.setY(p1.getY() + length*sin(PI*degree/180));
}
