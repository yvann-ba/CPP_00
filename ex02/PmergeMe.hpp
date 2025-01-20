#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    // Main interface to parse arguments, store them, and run the sorts
    bool parseArguments(int argc, char **argv);
    void sortAndPrintResults();

private:
    // Containers
    std::vector<int> _numbersVector;
    std::deque<int>  _numbersDeque;

    // ========== FORD-JOHNSON (MERGE-INSERT) SORT IMPLEMENTATIONS ==========
    void fordJohnsonSortVector(std::vector<int> &arr);
    void fordJohnsonSortDeque(std::deque<int>  &arr);

    // Steps for the algorithm:
    void createPairsAndSort(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &input);
    void createPairsAndSort(std::deque< std::pair<int,int> > &pairs, const std::deque<int> &input);

    // Helpers:
    void insertIntoSortedVector(std::vector<int> &sortedVec, int value);
    void insertIntoSortedDeque(std::deque<int> &sortedDq, int value);

    // Utility to check if a string is a valid positive integer
    bool isPositiveInteger(const std::string &str) const;
};

#endif
