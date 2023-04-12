#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <string.h>
# include <string>
# include <iostream>
# include <cctype>
# include <list>
# include <vector>

class PmergeMe {

private :

    std::vector<int>     _initialSequenceVector;
    std::list<int>       _initialSequenceList;
    std::vector<int>     _sortedSequenceVector;
    std::list<int>       _sortedSequenceList;
    float           _timeToSortWithVector;
    float           _timeToSortWithList;

public :

    //constructor - destructor

    PmergeMe(void);
    PmergeMe(char **sequence);
    PmergeMe(const PmergeMe &obj);
    ~PmergeMe(void);
    PmergeMe   &operator=(const PmergeMe &obj);

    //methods

    std::vector<int>     tabToVector(char **input);
    std::list<int>       tabToList(char **input);
    void            sortVector(std::vector<int> const array);
    void            sortList(void);
    void            mergeInsertVector(std::vector<int> leftArray, std::vector<int> rightArray, std::vector<int> mainArray);
    void            mergeInsertList(std::list<int> leftArray, std::list<int> rightArray, std::list<int> mainArray);




    //accessor
    float           getTTSVector(void);
    float           getTTSList(void);
    std::vector<int>     getInitialSequenceVector(void);
    std::list<int>       getInitialSequenceList(void);
    std::vector<int>     getSortedSequenceVector(void);
    std::list<int>       getSortedSequenceList(void);
};

#endif