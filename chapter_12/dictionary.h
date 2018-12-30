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
            std::string dictionary_filename) { // see: https://waterprogramming.wordpress.com/2017/08/20/reading-csv-files-in-c/
        // as an example of how to parse CSV files


        // iterate through the dictionary CSV file

        // create a map, out of it, with an integer (the hash) of the string, and the definition as the value

        // store the value from above with dictionary_table

        rapidcsv::Document document(dictionary_filename);

        std::vector<std::string> words = document.GetColumn<std::string>("Word");

        std::vector<std::string> definitions = document.GetColumn<std::string>("Definition");

        for (auto word = words.begin(); word != words.end(); ++word) {
            long index = std::distance(words.begin(), word);

            std::regex pattern("\"");

            std::string word_without_quotes = std::regex_replace(*word, pattern, "");

            std::size_t hash_result = hasher(word_without_quotes);
            // add this to map
            dictionary_table.insert(std::make_pair(hash_result, definitions[index]));
        }

    }

    std::string lookup(std::string word_to_search) {
        // compute the hash of the word, and see if its in the map
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
