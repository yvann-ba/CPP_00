#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseArguments(int argc, char **argv);
    void sortAndPrintResults();

private:
    std::vector<int> _numbersVector;
    std::deque<int>  _numbersDeque;

    void fordJohnsonSortVector(std::vector<int> &arr);
    void fordJohnsonSortDeque(std::deque<int>  &arr);

    void createPairsAndSort(std::vector<std::pair<int,int> > &pairs, const std::vector<int> &input);
    void createPairsAndSort(std::deque< std::pair<int,int> > &pairs, const std::deque<int> &input);

    void insertIntoSortedVector(std::vector<int> &sortedVec, int value);
    void insertIntoSortedDeque(std::deque<int> &sortedDq, int value);

    bool isPositiveInteger(const std::string &str) const;
};

#endif
