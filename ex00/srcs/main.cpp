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

int main(int ac, char **av)
{
    std::string str(av[ac - 1]);
    std::vector<bitcoinValue> referenceTab;
    fill_prices(&referenceTab);

    std::vector<bitcoinValue>::iterator it = referenceTab.begin();
    std::vector<bitcoinValue>::iterator itend = referenceTab.end();

    while (it != itend)
    {
        std::cout << it->getDate() + " - " << it->getValue() << std::endl;
        it++;
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
        std::cout << tmp << std::endl;
        newElem.setDate(tmp.substr(0, 10));
        newElem.setValue(atof((tmp.substr(11, tmp.size())).c_str()));
        referenceTab->push_back(newElem);
    }
}