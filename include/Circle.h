// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Circle Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Circle.h
 * Software Used: Geany
*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

/// Class that initializes a Circle object and allows for 
/// drawing
/**
 * Class utilizes the idea of inheritance and takes form the
 * template of the Shape class. Defines it's own seperate draw
 * function and has one data member, the radius
**/
class Circle : public Shape
{
	private:
		// Main data member
		double radius;

	public:
		/// Constructor
		/**
		 * Constructor takes in the x and y coordinates of the origin
		 * as well as the radius of the circle and assigns them
		 * all to the appropiate values
		**/
		Circle(double, double, double);
		
		/// Defined draw function from the purely virtual one
		/// in the shape class
		/**
		 * Defined to allow for the drawing of a circle given
		 * it's x and y coordinates of the origin as well as the
		 * radius
		**/
		void draw(double, double);
		
		/// Updates max and min values based on new origin
		/**
		 * Using the new coordinates of the origin, this defines
		 * where the maximum and minimum x and y values are in
		 * correlation to said origin
		**/
		void updateMaxAndMin();
		
		/// Updates the Position of the Shape
		/**
		 * Given the time that is has run, this function will
		 * use the animationstrategy to update it's current position
		 * ensuring that it stays in the boundries in accordance
		 * to how/where it's moving
		**/
		void updatePosition(double);
};
#endif
