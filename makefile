CPP = g++
LINK = g++
PROJNAME = Gen.app
SRCDIRS = factories products
OBJDIR=objects
TEMP = main.o mapFactory.o trapFactory.o mapProduct.o tileProduct.o trapProduct.o lootFactory.o lootProduct.o itemFactory.o itemProduct.o
OBJS=$(addprefix $(OBJDIR)/,$(TEMP))
all: $(SRCDIRS) $(PROJNAME) rapidjson

$(SRCDIRS):
	$(MAKE) -C $@

$(PROJNAME): $(SRCDIRS) main.o
	$(LINK) $(OBJS) -o $(PROJNAME) -std=c++11

main.o: main.cpp
	$(CPP) -std=c++11 -c $^ -o $(OBJDIR)/$@

.PHONY: rapidjson

rapidjson:
	mkdir -p ./rapidjson/build
	cd ./rapidjson/build; cmake ..; make

clean:
	find . -name '*.o' -delete -type f
	rm -f *.app
	rm -f $(OBJSDIR)/*.o

.PHONY: $(SRCDIRS)
