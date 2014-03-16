CCFLAGS = -I ../libs/allegro5/include/ -I /usr/include $(INCLUDEDIRS)
LIBDIR = -L ../libs/allegro5/lib -L /usr/lib
INCLUDEDIRS = -I ../include/
OBJDIR = ../obj/
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS = Simulator.o Triangle.o Square.o Circle.o ShapeContainer.o Shape.o main.o MySimulator.o Display.o Point.o Vector.o RectilinearAnimationStrategy.o CircularAnimationStrategy.o SinusoidalAnimationStrategy.o
OBJS = $(addprefix $(OBJDIR), $(OBJECTS))
EXECUTALBE = ../animatedShapes

$(EXECUTALBE): $(OBJS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
$(OBJDIR)%.o : %.cpp
	g++ -c -o $@ $< $(CCFLAGS)

clean:
	rm -f ./include/*~ ./include/*% ./include/*# ./include/.#*
	rm -f ./src/*~ ./src/*% ./src/*# ./src/.#*
	rm -f ../obj/*.o

clean-all: clean
	rm -f $(EXECUTALBE)
