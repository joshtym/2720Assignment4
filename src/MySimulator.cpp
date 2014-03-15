// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #4
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: MySimulator.cpp
 * Software Used: Geany
*/
#include "MySimulator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"

/// Class Implementation
/**
 * Impelmentation which defines all methods prototyped in the class
 * interface
**/

MySimulator::MySimulator(const Display& disp, int frames, 
						 ShapeContainer& givenShapes) : 
						 Simulator(disp, frames), shapes(givenShapes)
{
	// Determine the width and height of the shape
	displayWidth = disp.getW();
	displayHeight = disp.getH();
	
	// Define animations for all the shapes within the container
	Shape* shape;
	std::list<Shape*>::iterator it;
	
	for (it = shapes.shList.begin(); it != shapes.shList.end(); ++it)
	{
		shape = *it;
		shape->getAnimation(disp.getW(), disp.getH());
	}
	
}

void MySimulator::updateModel(double dt)
{
	Shape* shape;
	std::list<Shape*>::iterator it;
	
	// Iterate through the container and update each shape
	for (it = shapes.shList.begin(); it != shapes.shList.end(); ++it)
	{
		shape = *it;
		shape->updatePosition(dt);	
	}
}

void MySimulator::drawModel()
{
	// Clear and then redraw
	al_clear_to_color(al_map_rgb(0,0,0));
	shapes.draw();
	al_flip_display();
}

void MySimulator::simulate()
{
	run();
}
