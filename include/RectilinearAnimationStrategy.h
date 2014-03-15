// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: RectilinearAnimationStrategy.h
 * Software Used: Geany
*/
#ifndef RECTILINEARANIMATIONSTRATEGY_H
#define RECTILINEARANIMATIONSTRATEGY_H

#include "AnimationStrategyInterface.h"
#include "Vector.h"

/// Child class of AnimationStrategyInterface that utilizes it's
/// interface to create a concrete strategy
/**
 * This is a defined animation strategy which, will run the animation
 * logic of a shape that simulates a shape, moving at random speeds, 
 * bouncing off of the walls of the display.
**/
class RectilinearAnimationStrategy : public AnimationStrategyInterface
{
	public:
		///Main Constructor
		/**
		 * Takes in two values to that define the width and the height
		 * of the display being currently used
		**/
		RectilinearAnimationStrategy(int, int);
		
		/// Determines the next position of the shape in the animation
		/**
		 * \param crt is the current position of the shape
		 * \param dt is the time interval measured in seconds from
		 * the present to which the new position of the shape must
		 * be calculated
		**/
		Point nextPosition(Point crt, double dt);
		
		/// Ensures that the Shape stays within bound
		/**
		 * Given the origin, maximum, and minimum values of the shape,
		 * this function uses helper functions to ensure that the
		 * maximum and minimum points are within bounds of the display
		 * window. If not, the origin is updated to ensure that these
		 * points are within bounds
		**/
		void checkValidityOfCurrentShape(Point&, Point, Point);
		
		/// Assigns a random speed vector for the animation
		void randomSpeedVector();
		
	private:
		/// Private Helper Functions to ensure the point is in bounds
		
		/// Check to see if minimum x value falls below 0
		void checkLessThanXAxis(Point&, Point);
		
		/// Check to see if maximum x value falls above displayWidth
		void checkGreaterThanXAxis(Point&, Point);
		
		/// Check to see if the minimum y value falls below 0
		void checkLessThanYAxis(Point&, Point);
		
		/// Check to see if the maximum y value falls above displayHeight
		void checkGreaterThanYAxis(Point&, Point);
		
		// Private data members
		int displayWidth, displayHeight;
		Vector speedVector;
};
#endif
