// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: AnimationStrategyInterface.h
 * Software Used: Geany
*/
#ifndef ANIMATIONSTRATEGYINTERFACE_H
#define ANIMATIONSTRATEGYINTERFACE_H

#include "Point.h"
#include "Vector.h"
#include <cstdlib>

/// Class that defines an Interface for all Animated related movements
/// of the shapes
/**
 * Using a few virtual functions, this is the base for all animated
 * related strategies.
**/
class AnimationStrategyInterface
{
	public:
		/// Determines the next position of the shape in the animation
		/**
		 * \param crt is the current position of the shape
		 * \param dt is the time interval measured in seconds from
		 * the present to which the new position of the shape must
		 * be calculated
		**/
		virtual Point nextPosition(Point crt, double dt) = 0;
		
		/// Determines the current validity of the given shape
		/**
		 * \param origin is the point that we'll be editing depending
		 * on the location of the other two points
		 * \param minimum is the minimum x and y values of the shape
		 * that we are checking
		 * \param maximum is the maximum x and y values of the shape
		 * that we are checking.
		 * This is mainly a border checking function to simulate the
		 * 'bounce' effect when it collides with the edges of the window
		**/
		virtual void checkValidityOfCurrentShape(Point& origin, 
								Point mininmum, Point maximum) {};
		
		/// Assigns a speed to the animation strategy
		/**
		 * Using a private member within the children class, this will
		 * define the private member to a speed as to which the
		 * animation will be initiated on the object
		**/
		virtual void randomSpeedVector() {};
		
		virtual ~AnimationStrategyInterface() {};
};
#endif
