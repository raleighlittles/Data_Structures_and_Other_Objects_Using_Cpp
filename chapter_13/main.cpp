#include <iostream>
#include "radix_sorter.hpp"

using namespace std;

// Get maximum value from array.
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Count sort of arr[].
void countSort(int arr[], int n, int exp)
{
    cout << "Entering countSort function" << endl;
    // Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
    int output[n], i, count[10] = {0};

    // Count the number of times each digit occurred at (exp)th place in every input.
    for (i = 0; i < n; i++) {
        // this starts off as the rightmost character (last) of every string in the array, then moves to the left as the exp variable goes up by a factor of 10
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Calculating their cumulative count.
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
    for (i = n - 1; i >= 0; i--)
    {
        int index = (arr[i] / exp) % 10;
        int second_index = count[index] - 1;
        output[second_index] = arr[i];
        count[index]--;

    }

    // Assigning the result to the arr pointer of main().
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Sort arr[] of size n using Radix Sort.
void radixsort(int arr[], int n)
{
    int exp, m;
    m = getMax(arr, n);

    // Calling countSort() for digit at (exp)th place in every input.
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


int main()
{
    int n = 10;
    int arr[] = {886,542,12,3,96,125,54,129,3125};

    radixsort(arr, n);

    cout << " sorted data " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }

    cout << endl << "doing the same thing again vector approach" << endl;

    vector<std::string> v = {"bbb", "aaa", "ccc"};

    Sorter::radix_sort(v);

    cout << v.size() << endl;

    for (std::string word : v)
    {
        cout << " " << word;
    }

}
