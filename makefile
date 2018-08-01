
# Debug flag system
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

# directories where source files are, each of these dirs has there own make file as well
SRCDIRS = factories products form

#object output folder
OBJDIR=objects

#list of objects that are needed for linking
TEMP = main.o\
mapFactory.o mapProduct.o tileProduct.o\
trapFactory.o trapProduct.o\
lootFactory.o lootProduct.o\
itemFactory.o itemProduct.o\
monsterFactory.o monsterProduct.o\
characterFactory.o character.o\
jsoncpp.o\
populate.o\
FDFparser.o
OBJS=$(addprefix $(OBJDIR)/,$(TEMP))
all: jsoncpp $(SRCDIRS) $(PROJNAME)

#go to source directories and call their make files
$(SRCDIRS):
	$(MAKE) -C $@ DEBUG=$(DEBUG)

#link all .o's into the final project
$(PROJNAME): $(SRCDIRS) main.o
	$(LINK) $(OBJS) $(LFLAGS) -o $(PROJNAME)

#build main.o into object/
main.o: main.cpp
	$(CPP) $(CFLAGS) $^ -o $(OBJDIR)/$@

#build the jsoncpp dependency
jsoncpp:
	cd ./jsoncpp;python amalgamate.py;cd ./dist; $(CPP) $(CFLAGS) jsoncpp.cpp -I../include/; cp *.o ../../objects

clean:
	find . -name '*.o' -delete -type f
	rm -f *.app
	rm -f $(OBJSDIR)/*.o

.PHONY: $(SRCDIRS)
.PHONY: jsoncpp
