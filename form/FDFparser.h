//
// Created by Tom on 7/24/18.
//

#ifndef MAGICCAVE_FDFPARSER_H
#define MAGICCAVE_FDFPARSER_H

#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include "../products/character.h"


class FDFparser {
public:
    FDFparser(){}
    void parse_file(std::string file_str);
    void prep_char_sheets(Character* characters, int pc_count);
    void prep_npc_sheets(Character* characters, int npc_count);
    std::string build_fdf_contents(std::map <std::string,std::string> set);
    void print_keys(std::map <std::string,std::string> set);
    std::map <std::string,std::string> key_val;
    std::string format_proficiency(std::string prof);
};


#endif //MAGICCAVE_FDFPARSER_H
