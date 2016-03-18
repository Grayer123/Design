OBJS = main.o 
CXX = g++
CXXFLAGS = -Wall -Werror #-O -g

solution: $(OBJS)
	$(CXX) $(OBJS) -o solution

main.o: main.cpp solution.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


.PHONY: clean
clean:
	rm *.o solution
	
