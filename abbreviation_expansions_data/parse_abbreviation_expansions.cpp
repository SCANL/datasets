#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <cctype>

const unsigned int ORIGINAL_IDENTIFIER_COLUMN = 1;
const unsigned int ABBREV_EXPANSION_COLUMN = 2;
const unsigned int SPLIT_IDENTIFIER_COLUMN = 3;

void ParseGoldSet(std::string filename){
    std::set<std::string> count_unique_abbreviations;
    std::ifstream filestream(filename);
    char currentChar;
    int column = 1;
    std::string token;
    while(filestream.get(currentChar)){
        switch(currentChar){
            case ',':{
                switch(column){
                    case ORIGINAL_IDENTIFIER_COLUMN:{   
                        std::cout<<"Original Identifier: "<<token<<std::endl;
                        break;
                    }
                    case ABBREV_EXPANSION_COLUMN:{
                        std::string expansion,abbrev;
                        bool seencolon = false;
                        for(char c : token){
                            if(c == ':'){
                                seencolon = true;
                            }
                            if(c == '-'){
                                count_unique_abbreviations.insert(abbrev +":"+expansion);
                                std::cout<<"Abbrev and Expansion: "<<abbrev +":"+expansion<<std::endl;
                                abbrev.clear();
                                expansion.clear();
                                seencolon = false;
                            }
                            if(c == ')'){
                                count_unique_abbreviations.insert(abbrev +":"+expansion);
                                std::cout<<"Abbrev and Expansion: "<<abbrev +":"+expansion<<std::endl;
                                abbrev.clear();
                                expansion.clear();
                                seencolon = false;
                            }
                            if(c != ':' && c != ')' && c != '(' && c != '-'){
                                if((std::isalpha(c) || std::isdigit(c) || ' ') && seencolon){
                                    expansion+=std::tolower(c);
                                }
                                if((std::isalpha(c) || std::isdigit(c) || ' ') && !seencolon){
                                    abbrev+=std::tolower(c);
                                }
                            }
                        }
                        break;
                    }
                    case SPLIT_IDENTIFIER_COLUMN:{
                        std::cout<<"Split Identifier: "<< token<<std::endl;;
                        break;
                    }
                }
                ++column;
                token.clear();
                break;
            }
            case '\n':{
                column = 1;
                token.clear();
                break;
            }
            default:{
                token+=currentChar;
            }
        }

    }
    std::cerr<<count_unique_abbreviations.size()<<std::endl;
}

int main(int argc, char** argv){
  if(argc < 2){ 
    std::cerr<<"Syntax: ./executable [.csv file name]"<<std::endl;
    exit(1);
  }
  ParseGoldSet(argv[1]);
}