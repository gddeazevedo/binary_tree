all: src/*/*.h src/*/*.c main.c
	cc src/*/*.h src/*/*.c main.c -lm -o run.out