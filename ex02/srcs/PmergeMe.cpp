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
    _sortedSequenceVector = tabToVector(sequence);
    _initialSequenceDeque = tabToDeque(sequence);
    _sortedSequenceDeque = tabToDeque(sequence);
    sortVector(_sortedSequenceVector);
    sortDeque(_sortedSequenceDeque);
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
    _initialSequenceVector = obj._initialSequenceVector;
    _initialSequenceDeque = obj._initialSequenceDeque;
    _sortedSequenceVector = obj._sortedSequenceVector;
    _sortedSequenceDeque = obj._sortedSequenceDeque;
    _timeToSortWithVector = obj._timeToSortWithVector;
    _timeToSortWithDeque = obj._timeToSortWithDeque;
    return (*this);
}

// methods

// vector

std::vector<int>     PmergeMe::tabToVector(char **sequence)
{
    std::vector<int> ret;
    int         i = 1;

    while (sequence[i])
    {
        ret.push_back(atoi(sequence[i]));
        i++;
    }
    return (ret);
}

void            PmergeMe::sortVector(std::vector<int> &array)
{
    int length = array.size();
    if (length <= 1)
        return ;
    
    int middle = length / 2;
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    int i = 0;

    while (array[i])
    {
        if (i < middle)
            leftArray.push_back(array[i]);
        else
            rightArray.push_back(array[i]);
        i++;
    }
    sortVector(leftArray);
    sortVector(rightArray);
    mergeInsertVector(leftArray, rightArray, array);
}

void            PmergeMe::mergeInsertVector(std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &mainArray)
{
    int leftSize = mainArray.size() / 2;
    int rightSize = mainArray.size() - leftSize;
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

// deque

std::deque<int>     PmergeMe::tabToDeque(char **sequence)
{
    std::deque<int> ret;
    int         i = 1;

    while (sequence[i])
    {
        ret.push_back(atoi(sequence[i]));
        i++;
    }
    return (ret);
}

void            PmergeMe::sortDeque(std::deque<int> &array)
{
    int length = array.size();
    if (length <= 1)
        return ;
    
    int middle = length / 2;
    std::deque<int> leftArray;
    std::deque<int> rightArray;

    int i = 0;

    while (array[i])
    {
        if (i < middle)
            leftArray.push_back(array[i]);
        else
            rightArray.push_back(array[i]);
        i++;
    }
    sortDeque(leftArray);
    sortDeque(rightArray);
    mergeInsertDeque(leftArray, rightArray, array);
}

void            PmergeMe::mergeInsertDeque(std::deque<int> &leftArray, std::deque<int> &rightArray, std::deque<int> &mainArray)
{
    int leftSize = mainArray.size() / 2;
    int rightSize = mainArray.size() - leftSize;
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

// accessor

float       PmergeMe::getTTSVector(void) { return (_timeToSortWithVector); }
float       PmergeMe::getTTSDeque(void) { return (_timeToSortWithDeque); }
std::vector<int> PmergeMe::getInitialSequenceVector(void) { return (_initialSequenceVector); }
std::deque<int>   PmergeMe::getInitialSequenceDeque(void) { return (_initialSequenceDeque); }
std::vector<int> PmergeMe::getSortedSequenceVector(void) { return (_sortedSequenceVector); }
std::deque<int>   PmergeMe::getSortedSequenceDeque(void) { return (_sortedSequenceDeque); }


// utils