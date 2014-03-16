// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: CircularAnimationStrategy.h
 * Software Used: Geany
*/
#ifndef CIRCULARANIMATIONSTRATEGY_H
#define CIRCULARANIMATIONSTRATEGY_H

#include "AnimationStrategyInterface.h"

/// Concrete implementation of animation strategy for circular movement
/**
 * This is a defined animation strategy which, will run the animation
 * logic of a shape that simulates a shape, moving at random speeds, 
 * rotating around a fixed point within the plane of the display
**/
class CircularAnimationStrategy : public AnimationStrategyInterface
{
	public:
		CircularAnimationStrategy(Point);
		
		/// Determines the next position of the shape in the animation
		/**
		 * \param crt is the current position of the shape
		 * \param dt is the time interval measured in seconds from
		 * the present to which the new position of the shape must
		 * be calculated
		**/
		 Point nextPosition(Point crt, double dt);
		 
		 /// Assigns a speed to the animation strategy
		/**
		 * Using a private member within the children class, this will
		 * define the private member to a speed as to which the
		 * animation will be initiated on the object
		**/
		void randomSpeedVector();
		 
	private:
		/// Length of radius from center point to origin of shape
		double radiusOfRotation;
		
		/// Speed of rotation around the center point
		double speedOfRotation;
		
		// Center point
		Point centerPoint;
		
		// Starting point of shape
		Point startingPoint;
		
		// Degree that the rotation starts at. Is updated each time the
		// shape moves
		double degree;
		
		// Helper function to assign the rotational point
		void assignRotationPoint();
};
#endif
