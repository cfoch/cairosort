cairosort:
	gcc `pkg-config --cflags gtk+-3.0` \
	-include sortableshape.h sortableshapesimplebar.h \
	-o main \
	main.c \
	sortableshape.c \
	sortableshapesimplebar.c \
	`pkg-config --libs gtk+-3.0`
