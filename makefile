CPP = g++
LINK = g++
PROJNAME = Gen.app
OBJS = main.o factories/mapFactory.o
all: $(OBJS)
	$(LINK) $(OBJS) -o $(PROJNAME)

factories/%.o:%.c
	$(CPP) -c $(input) -o $(output)

products/%.o:%.c
	$(CPP) -c $(input) -o $(output)

./%.o:%.c
	$(CPP) -c $(input) -o $(output)

clean:
	find . -name '*.o' -delete -type f
	rm *.app
