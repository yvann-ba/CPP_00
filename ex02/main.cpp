#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    PmergeMe sorter;

    if (!sorter.parseArguments(argc, argv))
        return 1; // Error already printed in parseArguments

    sorter.sortAndPrintResults();

    return 0;
}
