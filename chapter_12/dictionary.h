//
// Created by raleigh on 12/28/18.
//

#ifndef CHAPTER_12_DICTIONARY_H

#define CHAPTER_12_DICTIONARY_H

// Problem statement
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include "rapid_csv.h"
#include <regex>
#include <iostream>
#include <algorithm>

/* Implement a dictionary program using a
table. The user inputs a word, and the word’s
definition is displayed. You will need to re-
vise one of the table implementations to use a string
as the search key. Use a hash function similar to the
one you implemented for Self-Test Exercise 28.
 */

class WordDictionary {
private:
    std::map<std::size_t, std::string> dictionary_table;
    std::size_t dictionary_size = dictionary_table.size();
    std::hash<std::string> hasher;


public:
    explicit WordDictionary(
            std::string dictionary_filename) {

        rapidcsv::Document document(dictionary_filename);

        std::vector column_names = document.GetColumnNames();

        std::vector<std::string> definitions = document.GetColumn<std::string>("definition");

        std::vector<std::string> words = document.GetColumn<std::string>("word");

        for (auto word = words.begin(); word != words.end(); ++word) {
            long index = std::distance(words.begin(), word);

            std::regex pattern("\"");

            std::string word_without_quotes = std::regex_replace(*word, pattern, "");

            std::size_t hash_result = hasher(word_without_quotes);

            dictionary_table.insert(std::make_pair(hash_result, definitions[index]));
        }

    }

    std::string lookup(std::string word_to_search) {
        std::size_t desired_hash = hasher(word_to_search);

        auto result = dictionary_table.find(desired_hash);

        if (result != dictionary_table.end()) {
            return result->second;
        } else {
            return "";
        }
    }
};

#endif //CHAPTER_12_DICTIONARY_H
