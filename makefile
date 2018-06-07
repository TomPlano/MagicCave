CPP = g++
LINK = g++
PROJNAME = Gen.app
OBJS = main.o factories/mapFactory.o products/mapProduct.o products/tileProduct.o
all: $(OBJS)
	$(LINK) $(OBJS) -o $(PROJNAME)

debug: $(OBJS)
	$(LINK) $(OBJS) -o $(PROJNAME) -g


factories/%.o:%.c
	$(CPP) -c $(input) -o $(output) -g

products/%.o:%.c
	$(CPP) -c $(input) -o $(output) -g

./%.o:%.c
	$(CPP) -c $(input) -o $(output) -g

clean:
	find . -name '*.o' -delete -type f
	rm *.app
