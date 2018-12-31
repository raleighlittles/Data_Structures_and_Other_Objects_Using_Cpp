//
// Created by raleigh on 12/31/18.
//

#ifndef CHAPTER_13_RADIX_SORTER_H
#define CHAPTER_13_RADIX_SORTER_H

#include <vector>
#include <algorithm>
#include <string>

namespace Sorter
{
    // use this: https://www.sanfoundry.com/cpp-program-implement-radix-sort/
    // but you'll need 256 buckets (ASCII), and insert values in the list according to their ASCII character chart

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
}

#endif //CHAPTER_13_RADIX_SORTER_H
