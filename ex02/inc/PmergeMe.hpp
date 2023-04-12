#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <string.h>
# include <string>
# include <iostream>
# include <cctype>
# include <deque>
# include <vector>
# include <cstdlib>

class PmergeMe {

private :

    std::vector<int>     _initialSequenceVector;
    std::deque<int>       _initialSequenceDeque;
    std::vector<int>     _sortedSequenceVector;
    std::deque<int>       _sortedSequenceDeque;
    float           _timeToSortWithVector;
    float           _timeToSortWithDeque;

public :

    //constructor - destructor

    PmergeMe(void);
    PmergeMe(char **sequence);
    PmergeMe(const PmergeMe &obj);
    ~PmergeMe(void);
    PmergeMe   &operator=(const PmergeMe &obj);

    //methods

    std::vector<int>    tabToVector(char **input);
    void                sortVector(std::vector<int> &array);
    void                mergeInsertVector(std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &mainArray);

    std::deque<int>      tabToDeque(char **input);
    void                sortDeque(std::deque<int> &array);
    void                mergeInsertDeque(std::deque<int> &leftArray, std::deque<int> &rightArray, std::deque<int> &mainArray);



    //accessor
    float               getTTSVector(void);
    std::vector<int>    getInitialSequenceVector(void);
    std::vector<int>    getSortedSequenceVector(void);

    float               getTTSDeque(void);
    std::deque<int>      getInitialSequenceDeque(void);
    std::deque<int>      getSortedSequenceDeque(void);
};

#endif