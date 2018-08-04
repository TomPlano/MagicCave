# The Cave of Shards Developer Guide

---

# Contents
- 1 - [Introduction](#1-introduction)
- 2 - [Building/Running](#2-building/running)
- 3 - [Adding to Build Chain](#3-adding-to-build-chain)
- 4 - [Design Concepts](#4-design-concepts)

---

##1. Introduction
###1.1 Submodules
This project contains submodule repos. Submodules must be collected before the project can be built. To collect this 
repo after cloning the MagicCave repo run th the following from inside the MagicCave top level directory

```bash
git submodule init  
git submodule sync 
git submodule update
```
At this point you will have collected the required versions of the MagicCave dependencies in their unbuilt form. 
They will be built along with the rest of the application.


##2. Building/Running
###2.1 Building
Building is entirely handled by tha make tool and is very simple to run.
```bash
make -j4
```
The -j4 arg is just there to speed up the build time and gives make 4 threads instead of 1 to do the build. If the build
fails, first try running make without the -j4 arg as sometimes the multithreaded build can build and link out of order,
and cause error. 

At this time, warnings are still thrown, specifically around some switch cases. This is ok and known behavior.
###2.2 Running 
After building, you will have the "Gen.app" binary in the toplevel directory. The quick usage rundown is 
```bash
./Gen.app <x_size> <y_size> <avg player lvl> <player count>
```
For more detailed usage, see the USER_GUIDE file.
That tool on its own will not create player and npc character sheets. For that you will need to install PDFtk on the machine
that you want to run on. Then you can run 
```bash
./MagicCave.sh <x_size> <y_size> <avg player lvl> <player count>
```
This small script will call "Gen.app" and then invoke PDFtk to zip up the pdf template and formdata from the gen.app.

PDFtk can be found [here](https://www.pdflabs.com/tools/pdftk-server/ "PDFtk Server page"). Simply install for your system
and the MagicCave should work. If it just hangs, check out [this](https://stackoverflow.com/questions/39750883/pdftk-hanging-on-macos-sierra "PDFtk Server Uptodate")
link. The PDFtk site is often out of date, so make sure to check that stackoverflow page to see if there's a new version for your system.

 
##3. Adding to Build Chain
There are a few ways to add to the build chain. 
### 3.1 Adding to an Existing Source Directory 
The first option is the simplest case where you want to add a new file 
to an already existing source directory. Source directory are listed as "SRCDIRS" in the makefile in the top level project 
directory. Any files that are added inside one of those directories will be automagicly be built into .o files and places
in the objects directory. After that, simply add the object file to the "TEMP" list in the top level makefile. This is essentially
a list of files that need to be linked in with main.o.  
### 3.2 Creating a New Source Directory
The second option is slightly more complex but far more useful. When a new feature of significant size, or some functionality that
doesnt fall into the established design principles is required, a new source dir is in order.
Luckily, there are examples to look to to set that up. When ever a new source dir is created, the following 2 steps must be done.
1. Edit "SRCDIRS" list in the top level makefile to include the new directory that you just created.
2. Copy MagicCave/factories/makefile into the new source directory. This makefile builds all *.cpp files in that dir and moves them to the MagicCave/objecs dir

Once those 2 steps are done, follow the instructions in 3.1 to add files as you create them.

##4. Design Concepts

The primary goals of this project were to begin a generator that would produce game ready scenarios for D&D 5e. To that end we 
knew that we would be generating lots of objects to place around the the map and that there would be a relatively few number of
types of objects compared to the the number of objects actually created. To that end we decided to build this project with a
factory method pattern. The essential design decision is that factories should do all the work for creating objects, and objects should be simple
data structures without the knowledge to create populate themselves. This is doubly important because of the fact that we are 
loading in external data to populate objects. By using the factory model, json data only need be loaded once, into the factory
and then all objects that come out of the factory will be correctly populated. 



