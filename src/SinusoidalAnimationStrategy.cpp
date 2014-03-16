// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: SinusoidalAnimationStrategy.cpp
 * Software Used: Geany
*/
#include "SinusoidalAnimationStrategy.h"
#include <cmath>

SinusoidalAnimationStrategy::SinusoidalAnimationStrategy(int width)
{
	// Assign a random height to the sinusoidal function between y
	// values 200 and 400.
	height = rand() % 201 + 200;
	
	// Assign a random amplitude to the sinusoidal function between
	// values 50 and 200
	amplitude = rand() % 151 + 50;
	
	// Assign a random period value to the function
	period = randomPeriodValue();
	
	displayWidth = width;
}

Point SinusoidalAnimationStrategy::nextPosition(Point crt, double dt)
{
	// Constant value for pi
	const double PI = 3.14159265358979323846;
	
	// Set the new x value dependant on the time and speed
	crt.setX(dt*speed + crt.getX());
	
	// Set the new y value as a sinusoidal function of the x value
	crt.setY(amplitude*sin(PI*(crt.getX()/period)/180) + height);
	
	// If the origin of the shape is out of bounds, return to beginning
	// of screen and repeat
	if (crt.getX() >= displayWidth)
		crt.setX(0);
		
	return crt;
}

double SinusoidalAnimationStrategy::randomPeriodValue()
{
	// Given the available options, choose a period for the sinusoidal
	// function
	double availableOptions[] = {0.5, 1, 1.5, 2};
	
	return availableOptions[rand() % 4];
}

void SinusoidalAnimationStrategy::randomSpeedVector()
{
	// Assign a random speed
	speed = rand() % 51 + 25;
}
