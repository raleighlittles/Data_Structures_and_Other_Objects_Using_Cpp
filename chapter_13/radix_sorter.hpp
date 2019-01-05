//
// Created by raleigh on 12/31/18.
//

#ifndef CHAPTER_13_RADIX_SORTER_H
#define CHAPTER_13_RADIX_SORTER_H

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <array>

namespace Sorter
{
    const std::size_t ASCII_LENGTH = 256;

/*
 *  Returns the length of the longest word in the array.
 */
    size_t max_word_length(std::vector<std::string> unsorted_list_of_words)
    {
        std::sort(unsorted_list_of_words.begin(), unsorted_list_of_words.end(),
                [](const std::string &s1, const std::string  &s2) -> bool
                {
                    return s1.size() > s2.size();
                });


        return unsorted_list_of_words.front().size();
    }

    void counting_radix_sort(std::vector<std::string>& unsorted_list, std::size_t string_position)
    {
        std::array<std::size_t, ASCII_LENGTH> counts = {0};
        std::vector<std::string> output;
        // Learn the difference between resize and reserve!
        output.resize(unsorted_list.size());

        for (auto word : unsorted_list)
        {
           std::string letter_at_string_position = std::string(1, word.at(word.length() -1 - string_position));
           // C++ has a bug that doesn't let you convert a one-length string into an integer, but since each element of a string
           // is a character, and character -> int static casts work, you have to manually select an index from the string
           int ascii_value_of_letter = static_cast<int>(letter_at_string_position[0]);
           counts[ascii_value_of_letter]++;
        }

        for (int i = 1; i < ASCII_LENGTH; i++)
        {
            counts[i] += counts[i-1];
        }

        for (int i = unsorted_list.size() - 1; i >= 0; i--)
        {
            std::string current_element = unsorted_list[i];
            std::string letter_at_string_position = std::string(1, current_element.at(current_element.length() - 1 - string_position));
            int ascii_value_of_letter = static_cast<int>(letter_at_string_position[0]);

            size_t second_index = counts[ascii_value_of_letter] - 1;
            output.at(second_index) = current_element;
            counts[ascii_value_of_letter]--;
        }


        for (std::size_t i = 0; i < unsorted_list.size(); i++)
        {
            unsorted_list[i] = output[i];
        }

    }


    void radix_sort(std::vector<std::string>& initial_array_to_sort)
    {
        std::size_t longest_word_length = max_word_length(initial_array_to_sort);

        for (int position = 0; position < longest_word_length; position++)
        {
            counting_radix_sort(initial_array_to_sort, position);
        }

    }
}

#endif //CHAPTER_13_RADIX_SORTER_H
