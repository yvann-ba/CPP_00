#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    PmergeMe sorter;

    if (!sorter.parseArguments(argc, argv))
        return 1;
    sorter.sortAndPrintResults();

    return 0;
}
