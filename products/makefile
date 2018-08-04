DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS =-g -std=c++11 -c
else
    CFLAGS= -std=c++11 -c
endif

CPP = g++
OBJDIR=../objects
SRC=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRC))
all: $(OBJS)

$(OBJS):%.o:%.cpp
	$(CPP) $(CFLAGS) $^ -o $(OBJDIR)/$@

clean:
	rm -f *.o
