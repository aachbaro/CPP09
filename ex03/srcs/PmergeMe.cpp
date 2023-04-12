#include "../inc/PmergeMe.hpp"

// constructor - destructor

PmergeMe::PmergeMe(void)
{
    //std::cout << "PmergeMe default constructor called" << std::endl;
    return ;
}

PmergeMe::PmergeMe(char **sequence)
{
    //std::cout << "PmergeMe constructor called" << std::endl;
    _initialSequenceVector = tabToVector(sequence);
    sortVector(_initialSequenceVector);
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    //std::cout << "PmergeMe copy constructor called" << std::endl;
    *this = obj;
    return ;
}

PmergeMe::~PmergeMe(void)
{
    //std::cout << "PmergeMe destructor called" << std::endl;
    return ;
}

PmergeMe   &PmergeMe::operator=(const PmergeMe &obj)
{
    //std::cout << "PmergeMe copy assignement coperator called" << std::endl;
    _initialSequenceVector = obj->_initialSequenceVector;
    _initialSequenceListt = obj->_initialSequenceList;
    _sortedSequenceVector = obj->_sortedSequenceVector;
    _sortedSequenceList = obj->_sortedSequenceList;
    _timeToSortWithVector = obj->_timeToSortWithVector;
    _timeToSortWithList = obj->_timeToSortWithList;
    return (*this);
}

// methods

std::vector     PmergeMe::tabToVector(char **sequence)
{
    std::vector<int> ret;
    int         i = 1;

    while (sequence[i])
    {
        ret.pushback(atoi(av[i]));
        i++;
    }
    return (ret);
}

std::list       PmergeMe::tabToList(std::string const input);

void            PmergeMe::sortVector(std::vector<int> const array);
{
    int length = array.size();
    if (size <= 1)
        return (array);
    
    int middle = length / 2;
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    int i = 0;

    while (array[i])
    {
        if (i < middle)
            leftArray.pushback(array[i]);
        else
            rightArray.pushback(array[i]);
        i++;
    }
    sortVector(leftArray);
    sortVector(rightArray);
    mergeInsertVector(leftArray, rightArray, array);
    _sortedSequenceVector = array;
}

void            PmergeMe::sortList(void);

void            PmergeMe::mergeInsertVector(std::vector<int> leftArray, std::vector<int> rightArray, std::vector<int> mainArray)
{
    int leftSize = mainArray.length() / 2;
    int rightSize = mainArray.length() - leftSize;
    int i = 0;
    int l = 0;
    int r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] < rightArray[r])
            mainArray[i] = leftArray[l++];
        else
            mainArray[i] = rightArray[r++];
        i++;
    }
    while (l < leftSize)
        mainArray[i++] = leftArray[l++];
    while (r < rightSize)
        mainArray[i++] = rightArray[r++];
}

void            PmergeMe::mergeInsertList(std::list<int> leftArray, std::list<int> rightArray, std::list<int> mainArray);



// accessor

float       PmergeMe::getTTSVector(void) { return (_timeToSortWithVector); }
float       PmergeMe::getTTSList(void) { return (_timeToSortWithList); }
std::vector<int> PmergeMe::getInitialSequenceVector(void) { return (_initialSequenceVector); }
std::list<int>   PmergeMe::getInitialSequenceList(void) { return (_initialSequenceList); }
std::vector<int> PmergeMe::getSortedSequenceVector(void) { return (_SortedSequenceVector); }
std::list<int>   PmergeMe::getSortedSequenceList(void) { return (_SortedSequenceList); }


// utils