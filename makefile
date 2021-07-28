CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o tree.o obj.o 

main: $(OBJS)

main.o: tree.h obj.h

tree.o: tree.h obj.h

clean:
	echo "cleaning repository"
	rm *.o main
