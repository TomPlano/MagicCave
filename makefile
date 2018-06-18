CPP = g++
LINK = g++
PROJNAME = Gen.app
OBJS = main.o factories/mapFactory.o factories/trapFactory.o products/mapProduct.o products/tileProduct.o products/trapProduct.o
all: $(OBJS)
	$(LINK) $(OBJS) -o $(PROJNAME) -std=c++11

factories/%.o:%.cpp
	cd factories
	make
products/%.o:%.cpp
	cd products
	make

clean:
	find . -name '*.o' -delete -type f
	rm *.app
