// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: MySimulator.h
 * Software Used: Geany
*/
#ifndef MYSIMULATOR_H
#define MYSIMULATOR_H

#include "Simulator.h"
#include "ShapeContainer.h"

/// Class that inherits the functions from the Simulator class and
/// defines the virtual functions so it works with the ShapeContainer
/**
 * Class utilizes the idea of inheritance and takes form the
 * template of the Simulator class. Defines it's own seperate drawModel
 * as well as it's updateModel function so that when the Simulation
 * begins, the Simulator correctly renders the shapes moving around in 
 * the boundaries of the Display. If the shape hits the side of the
 * Display, then the shape bounces off and the speedVector of the
 * shape is correctly altered to correlate with the bounce. Contains a
 * local shapes container to store the given shapes.
**/
class MySimulator : public Simulator
{
	private:
		// Main data members required
		ShapeContainer shapes;
		int displayWidth, displayHeight;
		
	public:
		/// Main Constructor
		/**
		 * Takes the display and the fps and starts up a simulation.
		 * Takes the shapecontainer and creates one that it can work with
		**/
		MySimulator(const Display&, int, ShapeContainer&);
		
		/// Start the simulation
		void simulate();
		
		/// Updates the model depending on the amount of time passed
		/// as well as the speedVector
		/**
		 * Iterates through the ShapeContainer and updates each
		 * value accordingly. It then calls a check to all the "check"
		 * functions to ensure validity is perserved
		**/
		void updateModel(double dt);
		
		/// Standard draw function
		/**
		 * Clears the screen and redraws the shape. Note that this is
		 * faster than the eye can see, hence why we don't notice
		**/
		void drawModel();
};
#endif