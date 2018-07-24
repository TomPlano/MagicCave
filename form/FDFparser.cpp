//
// Created by Tom on 7/24/18.
//

#include "FDFparser.h"
void FDFparser::parse_file(std::string file_str){
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


void FDFparser::prep_char_sheets(Character* characters, int pc_count){
    for(int i=0; i<pc_count;i++) {
        //copy key_val for each char sheet
        std::map<std::string, std::string> temp(key_val);
        //populate with data from char

        temp["Race "]=characters[i].char_race;
        temp["ClassLevel"]=characters[i].char_class+" "+std::to_string(characters[i].level);

        temp["DEX"]=std::to_string(characters[i].dex);
        temp["STR"]=std::to_string(characters[i].str);
        temp["CHA"]=std::to_string(characters[i].cha);
        temp["CON"]=std::to_string(characters[i].con);
        temp["INT"]=std::to_string(characters[i].intel);
        temp["WIS"]=std::to_string(characters[i].wis);

        temp["STRmod"]=std::to_string(characters[i].str_mod);
        temp["CHamod"]=std::to_string(characters[i].cha_mod);
        temp["DEXmod "]=std::to_string(characters[i].dex_mod);
        temp["CONmod"]=std::to_string(characters[i].con_mod);
        temp["INTmod"]=std::to_string(characters[i].intel_mod);
        temp["WISmod"]=std::to_string(characters[i].wis_mod);

        temp["ProfBonus"]=std::to_string(characters[i].prof_bonus);
        temp["HPMax"]=std::to_string(characters[i].hp);
        temp["HD"]=characters[i].hit_die;

        //create string to dump to file
        std::string file_contents = build_fdf_contents(temp);

        //dump to file

        std::ofstream output("pdf/player"+std::to_string(i)+".fdf");
        output << file_contents;
        output.close();

        //print_keys(temp);

    }
}


std::string FDFparser::build_fdf_contents(std::map <std::string,std::string> set){
    std::string body = "%FDF-1.2\n"
                       "%����\n"
                       "1 0 obj \n"
                       "<<\n"
                       "/FDF \n"
                       "<<\n"
                       "/Fields [\n";
    std::string footer ="]\n"
                        ">>\n"
                        ">>\n"
                        "endobj \n"
                        "trailer\n"
                        "\n"
                        "<<\n"
                        "/Root 1 0 R\n"
                        ">>\n"
                        "%%EOF";
    for(std::map<std::string,std::string>::const_iterator it = set.begin(); it != set.end(); it++)
    {
        body.append("<<\n/V ("+it->second+")\n/T ("+it->first+")\n>>");
    }
    body.append(footer);
    return body;

}


void FDFparser::print_keys(std::map <std::string,std::string> set){
    for(std::map<std::string,std::string>::const_iterator it = set.begin(); it != set.end(); it++)
    {
        std::cout<<it->first<<":"<< it->second<<"\n";
    }
}
