# The Cave of Shards Developer Guide

---

# Contents
- 1 - [Introduction](#1-introduction)
- 2 - [Building](#2-building)
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


##2. Building
Building is entirely handled by tha make tool and is very simple to run.
```bash
make -j4
```
The -j4 arg is just there to speed up the build time and gives make 4 threads instead of 1 to do the build. If the build
fails, first try running make without the -j4 arg as sometimes the multithreaded build can build and link out of order,
and cause error. 

At this time, warnings are still thrown, specifically around some switch cases. This is ok and know behavior.
##3. Adding to Build Chain
There are a few ways to add to the build chain. The first option is the simplest case where you want to add a new file 
to an already existing source directory. Source directory are listed as "SRCDIRS" in the makefile in the top level project 
directory. Any files that are added inside one of those directories will be automagicly be built into .o files and places
in the  





##4. Design Concepts