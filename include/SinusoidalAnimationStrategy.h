// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: SinusoidalAnimationStrategy.h
 * Software Used: Geany
*/
#ifndef SINUSOIDALANIMATIONSTRATEGY_H
#define SINUSOIDALANIMATIONSTRATEGY_H

#include "AnimationStrategyInterface.h"

/// Concrete implementation of animation strategy for sinusoidal movement
/**
 * This is a defined animation strategy which, will run the animation
 * logic of a shape that simulates a shape, moving at random speeds, 
 * simulating a sinusoidal function (AKA, a squiggly line).
**/
class SinusoidalAnimationStrategy : public AnimationStrategyInterface
{
	public:
		SinusoidalAnimationStrategy(int);
		
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
		
		/// Assigns a random value for the period of the Sinusoidal Function
		double randomPeriodValue();
		
		private:
			// Height of the sinusoidal function
			double height;
			
			// Amplitude of the sinusoidal function
			double amplitude;
			
			// Period of the sinusoidal function
			double period;
			
			// Speed of the movement along the sinusoidal function
			double speed;
			
			// Width of display
			int displayWidth;
};
#endif
