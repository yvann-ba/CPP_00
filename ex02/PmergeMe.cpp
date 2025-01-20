#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>   // for std::istringstream
#include <cstdlib>   // for std::atoi
#include <ctime>     // for clock(), CLOCKS_PER_SEC

// ================================
//  ORTHODOX CANONICAL FORM
// ================================
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_numbersVector = other._numbersVector;
        this->_numbersDeque  = other._numbersDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ================================
//  PARSE ARGUMENTS
// ================================
bool PmergeMe::parseArguments(int argc, char **argv)
{
    // If no arguments besides program name
    if (argc < 2)
    {
        std::cerr << "Error: No numbers provided." << std::endl;
        return false;
    }
    // Starting from argv[1], parse each argument
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        if (!isPositiveInteger(str))
        {
            std::cerr << "Error: Invalid positive integer => " << str << std::endl;
            return false;
        }
        // Convert string to int
        long val = std::atol(str.c_str());
        if (val < 0)
        {
            std::cerr << "Error: Negative number => " << val << std::endl;
            return false;
        }
        // We can also check the upper limit if we want. Subject says up to 3000 different integers, 
        // but doesn't specify maximum value. Let's just assume within normal int range.

        // Store in both containers
        _numbersVector.push_back(static_cast<int>(val));
        _numbersDeque.push_back(static_cast<int>(val));
    }
    return true;
}

// ================================
//  SORT AND PRINT RESULTS
// ================================
void PmergeMe::sortAndPrintResults()
{
    // 1) Print "Before" (the unsorted sequence):
    std::cout << "Before: ";
    for (size_t i = 0; i < _numbersVector.size(); i++)
        std::cout << _numbersVector[i] << (i + 1 < _numbersVector.size() ? " " : "");
    std::cout << std::endl;

    // 2) Sort with Vector
    std::vector<int> tempVector = _numbersVector; // We'll sort a copy
    clock_t startVec = clock(); // Start timing
    fordJohnsonSortVector(tempVector);
    clock_t endVec   = clock(); // End timing

    // 3) Sort with Deque
    std::deque<int> tempDeque = _numbersDeque;
    clock_t startDeq = clock(); // Start timing
    fordJohnsonSortDeque(tempDeque);
    clock_t endDeq   = clock(); // End timing

    // 4) Print "After" (the sorted sequence from vector or deque—they should match)
    std::cout << "After:  ";
    for (size_t i = 0; i < tempVector.size(); i++)
        std::cout << tempVector[i] << (i + 1 < tempVector.size() ? " " : "");
    std::cout << std::endl;

    // 5) Print the times
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0; // microseconds
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0; // microseconds

    std::cout << "Time to process a range of " << _numbersVector.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _numbersDeque.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}

// ================================
//  FORD-JOHNSON SORT (VECTOR)
// ================================

void PmergeMe::fordJohnsonSortVector(std::vector<int> &arr)
{
    if (arr.size() < 2) return;

    // 1) Create pairs of elements, sorting each pair so smaller is first
    std::vector< std::pair<int,int> > pairs;
    createPairsAndSort(pairs, arr);

    // 2) Build the "small chain" from the smaller elements, and sort it
    std::vector<int> smallChain;
    smallChain.reserve(pairs.size()); // reserve space
    for (size_t i = 0; i < pairs.size(); i++)
        smallChain.push_back(pairs[i].first);

    // Sort the smallChain with your choice (insertion sort or just std::sort).
    // The subject does not forbid std::sort. We can do a simple insertion sort if we want:
    // But let's keep it consistent with c++98 (std::sort is allowed, though).
    for (size_t i = 1; i < smallChain.size(); i++)
    {
        int key = smallChain[i];
        size_t j = i;
        while (j > 0 && smallChain[j - 1] > key)
        {
            smallChain[j] = smallChain[j - 1];
            j--;
        }
        smallChain[j] = key;
    }

    // 3) For each pair's "larger element," insert it into the smallChain
    for (size_t i = 0; i < pairs.size(); i++)
    {
        int larger = pairs[i].second;
        insertIntoSortedVector(smallChain, larger);
    }

    // 4) If the original array had an odd size, the last element is leftover:
    if (arr.size() % 2 == 1)
    {
        int leftover = arr[arr.size() - 1];
        insertIntoSortedVector(smallChain, leftover);
    }

    // 5) Now smallChain is fully sorted
    arr = smallChain;
}

// ================================
//  FORD-JOHNSON SORT (DEQUE)
// ================================

void PmergeMe::fordJohnsonSortDeque(std::deque<int> &arr)
{
    if (arr.size() < 2) return;

    // 1) Create pairs
    std::deque< std::pair<int,int> > pairs;
    createPairsAndSort(pairs, arr);

    // 2) Build the "small chain" of smaller elements, then insertion-sort it
    std::deque<int> smallChain;
    smallChain.resize(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++)
        smallChain[i] = pairs[i].first;

    // Perform an insertion sort on the smallChain (could use std::sort if we prefer)
    for (size_t i = 1; i < smallChain.size(); i++)
    {
        int key = smallChain[i];
        size_t j = i;
        while (j > 0 && smallChain[j - 1] > key)
        {
            smallChain[j] = smallChain[j - 1];
            j--;
        }
        smallChain[j] = key;
    }

    // 3) Insert each “larger” element
    for (size_t i = 0; i < pairs.size(); i++)
    {
        int larger = pairs[i].second;
        insertIntoSortedDeque(smallChain, larger);
    }

    // 4) Odd leftover
    if (arr.size() % 2 == 1)
    {
        int leftover = arr[arr.size() - 1];
        insertIntoSortedDeque(smallChain, leftover);
    }

    // 5) smallChain is sorted
    arr = smallChain;
}

// ================================
//  CREATE & SORT PAIRS (VECTOR/DEQUE)
// ================================

// For vector
void PmergeMe::createPairsAndSort(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &input)
{
    // number of pairs = input.size() / 2 if even
    // if odd => last element is leftover
    size_t limit = input.size() - (input.size() % 2);
    pairs.reserve(limit / 2);

    for (size_t i = 0; i < limit; i += 2)
    {
        int first  = input[i];
        int second = input[i+1];
        // ensure the smaller is in .first
        if (first > second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }
}

// For deque
void PmergeMe::createPairsAndSort(std::deque< std::pair<int,int> > &pairs, const std::deque<int> &input)
{
    size_t limit = input.size() - (input.size() % 2);
    pairs.resize(limit / 2);

    size_t index = 0;
    for (size_t i = 0; i < limit; i += 2)
    {
        int first  = input[i];
        int second = input[i+1];
        if (first > second)
            pairs[index++] = std::make_pair(second, first);
        else
            pairs[index++] = std::make_pair(first, second);
    }
}

// ================================
//  INSERT INTO SORTED (VECTOR/DEQUE)
// ================================

// Insert 'value' into sortedVec, preserving sorted order
void PmergeMe::insertIntoSortedVector(std::vector<int> &sortedVec, int value)
{
    // Binary search approach or linear insertion.
    // For simplicity (and c++98 compliance), let's do a linear approach.
    // If the data set is large, a binary search might be more optimal. 
    // Implementation for demonstration:
    std::vector<int>::iterator it = sortedVec.begin();
    while (it != sortedVec.end() && *it < value)
        ++it;
    sortedVec.insert(it, value);
}

// Insert 'value' into sortedDq, preserving sorted order
void PmergeMe::insertIntoSortedDeque(std::deque<int> &sortedDq, int value)
{
    std::deque<int>::iterator it = sortedDq.begin();
    while (it != sortedDq.end() && *it < value)
        ++it;
    sortedDq.insert(it, value);
}

// ================================
//  HELPERS
// ================================

bool PmergeMe::isPositiveInteger(const std::string &str) const
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    // Also check that it doesn't exceed the range of int, but that’s optional here.
    // We'll do a quick check that length not crazy large
    if (str.size() > 10) // bigger than the length of 32-bit INT max (2147483647)
        return false;
    return true;
}
