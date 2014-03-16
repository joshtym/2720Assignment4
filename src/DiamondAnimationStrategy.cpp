#include "DiamondAnimationStrategy.h"

DiamondAnimationStrategy::DiamondAnimationStrategy(Point origin)
{
	startingPoint = origin;
	height = 100;
	width = 100;
}

Point DiamondAnimationStrategy::nextPosition(Point crt, double dt)
{
	crt.setX(crt.getX() + speedVector.getX()*dt);
	crt.setY(crt.getY() + speedVector.getY()*dt);
	
	if (crt.getX() <= startingPoint.getX())
	{
		crt.setX(crt.getX() + (startingPoint.getX() - crt.getX()));
								 
		speedVector.setX((speedVector.getX())*-1);
	}
	
	if (crt.getX() >= (startingPoint.getX() + width))
	{
		crt.setX(crt.getX() - (crt.getX() - (startingPoint.getX() + width)));
								 
		speedVector.setX((speedVector.getX())*-1);
	}
	
	if (crt.getY() <= (startingPoint.getY() - height/2))
	{
		crt.setY(crt.getY() + ((startingPoint.getY() - height/2) - crt.getY()));
								 
		speedVector.setY((speedVector.getY())*-1);
	}
	
	if (crt.getY() >= startingPoint.getY() + height/2)
	{
		crt.setY(crt.getY() + (crt.getY() - (startingPoint.getY() + height / 2)));
								 
		speedVector.setX((speedVector.getX())*-1);
	}
	return crt;
}
void DiamondAnimationStrategy::randomSpeedVector()
{
	speedVector.setX(75);
	speedVector.setY(75);
}
