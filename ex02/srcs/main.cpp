#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "../inc/PmergeMe.hpp"
#include <fstream>
#include <cstdlib>


int main(int ac, char **av)
{
    if (ac > 1) {
        PmergeMe sequence(av);

       int i = 0;
        while (sequence.getSortedSequenceVector()[i])
        {
            std::cout << sequence.getSortedSequenceVector()[i] << std::endl;
            i++;
        }
    }

    return (0);
}

