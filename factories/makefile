CPP = g++
OBJDIR=../objects
SRC=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRC))
all: $(OBJS)

$(OBJS):%.o:%.cpp
	$(CPP) -c $^ -std=c++11 -o $(OBJDIR)/$@

clean:
	rm -f *.o
