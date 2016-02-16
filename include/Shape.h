// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Shape.h
 * Software Used: Geany
*/
#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Vector.h"
#include "AnimationStrategyInterface.h"
#include "RectilinearAnimationStrategy.h"
#include "CircularAnimationStrategy.h"
#include "SinusoidalAnimationStrategy.h"

/// Main Parent Class of all Shapes
/**
 * This class acts as a "template" for all other derived shapes
 * to follow. Contains the similarities between all shapes and
 * contains an overridable draw function. The draw function must be
 * overrided to be used
**/
class Shape
{
	public:
		/// Virtual Functions
		/**
		 * Two functions provided. The translate function is based on
		 * the fact that all shapes have a central "origin" that
		 * is based on how they move. The draw function is what is
		 * classified as "purely virtual" which means that is must
		 * be overriden by it's children to be used
		**/
		virtual void translate(Vector&);
		virtual void draw(double, double) = 0;
		virtual void updateMaxAndMin() = 0;
		
		/// Get Animation Function
		virtual void getAnimation(int, int);
		
		/// Update the Position based on the Animation
		virtual void updatePosition(double) = 0;
		
		virtual ~Shape();
		
		/// Getter Functions
		/**
		 * Allows for querying the maximum and minimum x and y
		 * coordinates in each shape at the current moment
		**/
		/// Gets the minimum X value of the shape
		double getMinX();
		
		/// Gets the minimum Y value of the shape
		double getMinY();
		
		/// Gets the maximum X value of the shape
		double getMaxX();
		
		/// Gets the maximum Y value of the shape
		double getMaxY();
		
		// Central point for each shape
		Point origin;
		
		// Speed Vector for each shape
		
		// Maximum Point for each shape
		Point minimum;
		
		// Minimum Point for each shape
		Point maximum;
		
		// Animation Strategy to be used
		AnimationStrategyInterface* chosenAnimation;
};
#endif
