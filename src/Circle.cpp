// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: Circle.cpp
 * Software Used: Geany
*/
#include "Circle.h"
#include <allegro5/allegro_primitives.h>

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

Circle::Circle(double givenRadius, double originX, double originY)
{
	// Assign all the given values to their appropiate values
	radius = givenRadius;
	origin.setX(originX);
	origin.setY(originY);
	
	// Update the max and min based on assigned values
	updateMaxAndMin();
}

void Circle::draw(double originx, double originy)
{
	// Uses the allegro_primitives addon to draw a circle
	al_draw_circle(originx, originy, radius, al_map_rgb(49,94,199), 4);
}

void Circle::updateMaxAndMin()
{
	minimum.setX(origin.getX() - radius);
	minimum.setY(origin.getY() - radius);
	maximum.setX(origin.getX() + radius);
	maximum.setY(origin.getY() + radius);
}

void Circle::updatePosition(double dt)
{
	// Redefine the origin dependant on time and animation
	// strategy
	origin = chosenAnimation->nextPosition(origin, dt);
	
	// Update max and min values and check shape validity
	updateMaxAndMin();
	chosenAnimation->checkValidityOfCurrentShape(origin, minimum, maximum);
}
