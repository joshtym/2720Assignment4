// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Shape Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Simulator.h
 * Software Used: Geany
*/
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Display.h"
#include <allegro5/allegro.h>


/// Class responsible for setting up the Allegro library for 
/// some basic animation.
/**
 * Initializes the Allegro timer that controls rendering, set up a
 * common Allegro event queue, and provides a rendering loop function
 * for the animation
**/
class Simulator
{
	private:
		/// Rendering Frequency
		int framesPerSec;
		
		/// Event Storage
		ALLEGRO_EVENT_QUEUE *eventQueue;
		
		/// Generates Events for Simulation
		ALLEGRO_TIMER *timer;
		
	public:
		/// The constructor initializes the Allegro library
		/**
		 * \param d - the display object. Needed so that the Simulator
		 * object recognizes when the "close window" button is pressed
		 * and the simulation needs to stop
		 * \param fps - the number of frames per second. This is the
		 * rate at which both the simulation and the rendering are
		 * performed.
		**/
		Simulator(const Display& d, int fps);
		
		/// The destructor frees all the Allegro resources allocated by the
		/// constructor 
		~Simulator();
		
		/// Rendering Loop
		/**
		 * Must be invoked to start the simulation. The function exists
		 * when the user closes the display window
		**/
		void run();
		
		/// Updates the state of the object
		/**
		 * Subclass and provide an implemention for this function that
		 * specifies how the model used in the simulation is updated.
		 * It is called by run().
		 * \param dt is the time in seconds since the most recent model
		 * update. The model needs to be changed to a state that
		 * reflects the passing of dt seconds after the current state.
		 * It is possible that dt is zero and/or negative
		**/
		virtual void updateModel(double dt) = 0;
		
		/// Displays the updated model
		/**
		 * Subclass and provide an implementation for this function that
		 * contains the drawing code
		**/
		virtual void drawModel() = 0;
};
#endif
