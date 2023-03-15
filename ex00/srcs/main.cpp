#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "../inc/bitcoinValue.hpp"
#include <fstream>
#include <cstdlib>

void fill_prices(std::vector<bitcoinValue> *referenceTab);
int datecmp(std::string const date1, std::string const date2);

int main(int ac, char **av)
{

    std::vector<bitcoinValue>   referenceTab;
    std::ifstream               fd(av[ac-1]);
    std::string                 tmp;
    std::string                 tmpdate;

    fill_prices(&referenceTab);
    std::vector<bitcoinValue>::iterator it;
    std::vector<bitcoinValue>::iterator itend = referenceTab.end();
    while (std::getline(fd, tmp))
    {
        it = referenceTab.begin() + 1;
        tmpdate = tmp.substr(0, 10);
        while (it != itend)
        {
            if (datecmp(tmpdate, it->getDate()) <= 1 && datecmp(tmpdate, (it + 1)->getDate()) == 2)
            {
                std::cout << tmp << std::endl;
                break ;
            }
            it++;
        }
        if (it == itend) { std::cout << "nop" << std::endl;}
    }
    return (0);
}

void fill_prices(std::vector<bitcoinValue> *referenceTab)
{
    std::ifstream data("data.csv");
    std::string tmp;
    bitcoinValue newElem;

    while (std::getline(data, tmp))
    {
        newElem.setDate(tmp.substr(0, 10));
        newElem.setValue(atof((tmp.substr(11, tmp.size())).c_str()));
        referenceTab->push_back(newElem);
    }
}

int datecmp(std::string const date1, std::string const date2)
{
    if (date1.substr(0, 4) == date2.substr(0, 4))
    {
        if (date1.substr(5, 7) == date2.substr(5, 7))
        {
            if (date1.substr(8, 10) == date2.substr(8, 10))
                return (0);
            else if (atoi(date1.substr(8, 10).c_str()) < atoi(date2.substr(8, 10).c_str()))
                return (2);
            else
                return (1);
        }
        else if (atoi(date1.substr(5, 7).c_str()) < atoi(date2.substr(5, 7).c_str()))
            return (2);
        else
            return (1);
    }
    else if (atoi(date1.substr(0, 4).c_str()) < atoi(date2.substr(0, 4).c_str()))
        return (2);
    else
        return (1);
}