#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
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

bool PmergeMe::parseArguments(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No numbers provided." << std::endl;
        return false;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        if (!isPositiveInteger(str))
        {
            std::cerr << "Error: Invalid positive integer => " << str << std::endl;
            return false;
        }
        long val = std::atol(str.c_str());
        if (val < 0)
        {
            std::cerr << "Error: Negative number => " << val << std::endl;
            return false;
        }

        _numbersVector.push_back(static_cast<int>(val));
        _numbersDeque.push_back(static_cast<int>(val));
    }
    return true;
}
void PmergeMe::sortAndPrintResults()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _numbersVector.size(); i++)
        std::cout << _numbersVector[i] << (i + 1 < _numbersVector.size() ? " " : "");
    std::cout << std::endl;

    std::vector<int> tempVector = _numbersVector;
    clock_t startVec = clock();
    fordJohnsonSortVector(tempVector);
    clock_t endVec   = clock();

    std::deque<int> tempDeque = _numbersDeque;
    clock_t startDeq = clock();
    fordJohnsonSortDeque(tempDeque);
    clock_t endDeq   = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < tempVector.size(); i++)
        std::cout << tempVector[i] << (i + 1 < tempVector.size() ? " " : "");
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << _numbersVector.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _numbersDeque.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
void PmergeMe::fordJohnsonSortVector(std::vector<int> &arr)
{
    if (arr.size() < 2) return;

    std::vector< std::pair<int,int> > pairs;
    createPairsAndSort(pairs, arr);

    std::vector<int> smallChain;
    smallChain.reserve(pairs.size());
    
    for (size_t i = 0; i < pairs.size(); i++)
        smallChain.push_back(pairs[i].first);

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

    for (size_t i = 0; i < pairs.size(); i++)
    {
        int larger = pairs[i].second;
        insertIntoSortedVector(smallChain, larger);
    }

    if (arr.size() % 2 == 1)
    {
        int leftover = arr[arr.size() - 1];
        insertIntoSortedVector(smallChain, leftover);
    }

    arr = smallChain;
}
void PmergeMe::fordJohnsonSortDeque(std::deque<int> &arr)
{
    if (arr.size() < 2) return;

    std::deque< std::pair<int,int> > pairs;
    createPairsAndSort(pairs, arr);

    std::deque<int> smallChain;
    smallChain.resize(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++)
        smallChain[i] = pairs[i].first;

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

    for (size_t i = 0; i < pairs.size(); i++)
    {
        int larger = pairs[i].second;
        insertIntoSortedDeque(smallChain, larger);
    }

    if (arr.size() % 2 == 1)
    {
        int leftover = arr[arr.size() - 1];
        insertIntoSortedDeque(smallChain, leftover);
    }

    arr = smallChain;
}
void PmergeMe::createPairsAndSort(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &input)
{
    size_t limit = input.size() - (input.size() % 2);
    pairs.reserve(limit / 2);

    for (size_t i = 0; i < limit; i += 2)
    {
        int first  = input[i];
        int second = input[i+1];
        if (first > second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }
}
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
void PmergeMe::insertIntoSortedVector(std::vector<int> &sortedVec, int value)
{
    std::vector<int>::iterator it = sortedVec.begin();
    while (it != sortedVec.end() && *it < value)
        ++it;
    sortedVec.insert(it, value);
}
void PmergeMe::insertIntoSortedDeque(std::deque<int> &sortedDq, int value)
{
    std::deque<int>::iterator it = sortedDq.begin();
    while (it != sortedDq.end() && *it < value)
        ++it;
    sortedDq.insert(it, value);
}
bool PmergeMe::isPositiveInteger(const std::string &str) const
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    if (str.size() > 10)        return false;
    return true;
}
