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


class FDFparser {
public:
    FDFparser(){}
    void parse_file(std::string file_str){
        std::string line;
        std::ifstream fdf_file(file_str);
        if (fdf_file.is_open()) {
            while (getline(fdf_file, line)) {
                std::string tag_str ("/T (");
                std::size_t found = line.find(tag_str);
                if (found!=std::string::npos){
                    line.erase(0,4);
                    line.erase(line.end()-1);
                    key_val.insert(std::pair<std::string,std::string>(line,""));
                }

            }
            fdf_file.close();
        }
    }
    void get_keys(){}
    void print_keys(){
        for(std::map<std::string,std::string>::const_iterator it = key_val.begin(); it != key_val.end(); it++)
        {
            std::cout<<it->first<<"\n";
        }
    }
    std::map <std::string,std::string> key_val;
};


#endif //MAGICCAVE_FDFPARSER_H
