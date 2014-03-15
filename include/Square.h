// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Square.h
 * Software Used: Geany
*/
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

/// Class that initializes a Square object and allows for 
/// drawing
/**
 * Class utilizes the idea of inheritance and takes form the
 * template of the Shape class. Defines it's own seperate draw
 * function and has one data member, the length of the side of
 * a square
**/
class Square : public Shape
{
	private:
		// Main data member
		double sideLength;

	public:
		/// Constructor
		/**
		 * Constructor takes in the x and y coordinates of the origin
		 * as well as the side length of the square and assigns them
		 * all to the appropiate values
		**/
		Square(double, double, double);
		
		/// Defined draw function from the purely virtual one
		/// in the shape class
		/**
		 * Defined to allow for the drawing of a square given
		 * it's x and y coordinates of the origin as well as the
		 * length of a side
		**/
		void draw(double, double);
		
		/// Defines the minimum and maximum x and y values
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