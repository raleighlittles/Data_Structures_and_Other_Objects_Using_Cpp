//
// Created by raleigh on 12/31/18.
//

#ifndef CHAPTER_13_RADIX_SORTER_H
#define CHAPTER_13_RADIX_SORTER_H

#include <vector>
#include <algorithm>
#include <string>
#include <array>

namespace Sorter
{
    const std::size_t ASCII_LENGTH = 256;

    // use this: https://www.sanfoundry.com/cpp-program-implement-radix-sort/
    // but you'll need 256 buckets (ASCII), and insert values in thhttps://www.sanfoundry.com/cpp-program-implement-radix-sort/e list according to their ASCII character chart

    size_t max_word_length(std::vector<std::string> unsorted_list_of_words)
    {
        // The
        std::sort(unsorted_list_of_words.begin(), unsorted_list_of_words.end(),
                [](const std::string &s1, const std::string  &s2) -> bool
                {
                    return s1.size() > s2.size();
                });


        return unsorted_list_of_words.front().size();
    }

    void counting_radix_sort(std::vector<std::string> unsorted_list, std::size_t string_position)
    {
        // count the number of strings that have the current character at that same position
        std::array<std::size_t, ASCII_LENGTH> counts = {0};
        std::vector<std::string> output;
        output.reserve(unsorted_list.size());

        for (auto word : unsorted_list)
        { // the string position is similar to the whole modulo trick used in the integer radix version to figure out what "place" of the number you're in (tens, hundreds, etc)
            counts[static_cast<int>(word[string_position])]++;
        }

        for (int i = 1; i < ASCII_LENGTH; i++)
        {
            counts[i] += counts[i-1];
        }

        for (std::size_t i = unsorted_list.size() - 1; i >= 0; i++)
        {
            output[counts[static_cast<int>(unsorted_list[i][string_position])] - 1] = unsorted_list[i];

            counts[static_cast<int>(unsorted_list[i][string_position])]--;

        }

        for (std::size_t i = 0; i < unsorted_list.size(); i++)
        {
            unsorted_list[i] = output[i];
        }
    }


    void radix_sort(std::vector<std::string> initial_array_to_sort)
    {
        std::size_t longest_word_length = max_word_length(initial_array_to_sort);

        for (int position = 0; position < longest_word_length; position++)
        {
            counting_radix_sort(initial_array_to_sort, position);
        }
    }
}

#endif //CHAPTER_13_RADIX_SORTER_H
