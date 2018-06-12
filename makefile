CPP = g++
LINK = g++
PROJNAME = Gen.app
OBJS = main.o factories/mapFactory.o factories/trapFactory.o products/mapProduct.o products/tileProduct.o products/trapProduct.o
all: $(OBJS)
	$(LINK) $(OBJS) -o $(PROJNAME) -std=c++11

factories/%.o:%.c
	$(CPP) -c $(input) -o $(output) -std=c++11

products/%.o:%.c
	$(CPP) -c $(input) -o $(output) -std=c++11

./%.o:%.c
	$(CPP) -c $(input) -o $(output) -std=c++11

clean:
	find . -name '*.o' -delete -type f
	rm *.app
