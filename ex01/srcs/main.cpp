#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "../inc/RPN.hpp"
#include <fstream>
#include <cstdlib>


int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Error" <<std:: endl;
    rpn expression(av[ac - 1]);
    if (expression.getRes() != -1)
        std::cout << expression.getRes() << std::endl;
    return (0);
}