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
    float                       tmpamount;

    fill_prices(&referenceTab);
    std::vector<bitcoinValue>::iterator it = referenceTab.begin();
    std::vector<bitcoinValue>::iterator itend = referenceTab.end();

    while (std::getline(fd, tmp))
    {
        tmpamount = 0;
        it = referenceTab.begin();
        tmpdate = tmp.substr(0, 10);
        if (tmp.size() < 13)
            it = itend;
        else 
            tmpamount = atof(tmp.substr(13, tmp.size()).c_str());
        if (tmpamount < 0)
        {
            std::cout << "Error: not a positive number" << std::endl;
            continue ;
        }
        while (it != itend)
        {
            if (datecmp(it->getDate(), tmpdate) >= 0 
            && datecmp((it + 1)->getDate(), tmpdate) < 0)
            {
                std::cout << tmpdate + " => " << tmpamount << " = "<< it->getTotalValue(tmpamount) << std::endl;
                break ;
            }
            it++;
        }
        if (it == itend) {
            std::cout << "Error: bad input => " + tmp << std::endl;
        }
    }
    return (0);
}

void fill_prices(std::vector<bitcoinValue> *referenceTab)
{
    std::ifstream data("data.csv");
    std::string tmp;
    bitcoinValue newElem;

    std::getline(data, tmp);
    while (std::getline(data, tmp))
    {
        newElem.setDate(tmp.substr(0, 10));
        newElem.setValue(atof((tmp.substr(11, tmp.size())).c_str()));
        referenceTab->push_back(newElem);
    }
}

typedef struct s_date {
    int year;
    int month;
    int day;
}              t_date;

int datecmp(std::string const datecsv, std::string const datefile)
{
    t_date csv;
    t_date inputfile;
    

    csv.year = atoi(datecsv.substr(0, 4).c_str());
    csv.month = atoi(datecsv.substr(5, 7).c_str());
    csv.day = atoi(datecsv.substr(8, 10).c_str());
    inputfile.year = atoi(datefile.substr(0, 4).c_str());
    inputfile.month = atoi(datefile.substr(5, 7).c_str());
    inputfile.day = atoi(datefile.substr(8, 10).c_str());
    if (csv.year == inputfile.year)
    {
        if (csv.month == inputfile.month)
            return (inputfile.day - csv.day);
        return (inputfile.month - csv.month);
    }
    return (inputfile.year - csv.year);
}