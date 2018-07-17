DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS =-g -std=c++11 -c
else
    CFLAGS= -std=c++11 -c
endif




CPP = g++
LINK = g++
LFLAGS= -std=c++11
PROJNAME = Gen.app
SRCDIRS = factories products
OBJDIR=objects
TEMP = main.o\
mapFactory.o mapProduct.o tileProduct.o\
trapFactory.o trapProduct.o\
lootFactory.o lootProduct.o\
itemFactory.o itemProduct.o\
monsterFactory.o monsterProduct.o\
characterFactory.o character.o\
jsoncpp.o\
populate.o
OBJS=$(addprefix $(OBJDIR)/,$(TEMP))
all: jsoncpp $(SRCDIRS) $(PROJNAME)

$(SRCDIRS):
	$(MAKE) -C $@ DEBUG=$(DEBUG)

$(PROJNAME): $(SRCDIRS) main.o
	$(LINK) $(OBJS) $(LFLAGS) -o $(PROJNAME)

main.o: main.cpp
	$(CPP) $(CFLAGS) $^ -o $(OBJDIR)/$@

jsoncpp:
	cd ./jsoncpp;python amalgamate.py;cd ./dist; $(CPP) $(CFLAGS) jsoncpp.cpp -I../include/; cp *.o ../../objects

clean:
	find . -name '*.o' -delete -type f
	rm -f *.app
	rm -f $(OBJSDIR)/*.o

.PHONY: $(SRCDIRS)
.PHONY: jsoncpp
