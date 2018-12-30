#include <iostream>
#include "dictionary.h"
int main()
{

    WordDictionary dictionary = WordDictionary("/home/raleigh/Programming/Github_Projects/Data_Structures_and_Other_Objects_Using_Cpp/chapter_12/dictionary.csv");

    std::string definition;

    definition = dictionary.lookup("Vent");

    std::cout << "Definition: " << definition << std::endl;
}
