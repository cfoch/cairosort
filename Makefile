cairosort:
	gcc `pkg-config --cflags gtk+-3.0` \
	-include \
		csort.h \
		sortableshape.h \
		sortableshapesimplebar.h \
		sortableshapearrayobject.h \
	-o main \
	sortableshape.c \
	sortableshapesimplebar.c \
	sortableshapearrayobject.c \
	csort.c \
	main.c \
	`pkg-config --libs gtk+-3.0`
