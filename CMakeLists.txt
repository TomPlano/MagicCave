cmake_minimum_required(VERSION 3.10)
project(MagicCave)

set(CMAKE_CXX_STANDARD 11)

include_directories(factories)
include_directories(jsoncpp/dist/json)
include_directories(jsoncpp/include)
include_directories(jsoncpp/include/json)
include_directories(jsoncpp/src/lib_json)
include_directories(jsoncpp/src/test_lib_json)
include_directories(products)

add_executable(MagicCave
        factories/characterFactory.cpp
        factories/characterFactory.h
        factories/itemFactory.cpp
        factories/itemFactory.h
        factories/lootFactory.cpp
        factories/lootFactory.h
        factories/mapFactory.cpp
        factories/mapFactory.h
        factories/monsterFactory.cpp
        factories/monsterFactory.h
        factories/trapFactory.cpp
        factories/trapFactory.h
        jsoncpp/dist/jsoncpp.cpp
        products/character.cpp
        products/character.h
        products/itemProduct.cpp
        products/itemProduct.h
        products/lootProduct.cpp
        products/lootProduct.h
        products/mapProduct.cpp
        products/mapProduct.h
        products/monsterProduct.cpp
        products/monsterProduct.h
        products/tileProduct.cpp
        products/tileProduct.h
        products/trapProduct.cpp
        products/trapProduct.h
        main.cpp)
