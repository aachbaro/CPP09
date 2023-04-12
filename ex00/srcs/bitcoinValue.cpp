#include "../inc/bitcoinvalue.hpp"

// constructor - destructor

bitcoinvalue::bitcoinvalue(void)
{
    //std::cout << "bitcoinvalue default constructor called" << std::endl;
    this->_value = 0;
    this->_date = "";
    return ;
}

bitcoinvalue::bitcoinvalue(std::string const date, float const value)
{
    //std::cout << "bitCoin constructor called" << std::endl;
    this->_value = value;
    this->_date = date;
}

bitcoinvalue::bitcoinvalue(const bitcoinvalue &obj)
{
    //std::cout << "bitcoinvalue copy constructor called" << std::endl;
    *this = obj;
    return ;
}

bitcoinvalue::~bitcoinvalue(void)
{
    //std::cout << "bitcoinvalue destructor called" << std::endl;
    return ;
}

bitcoinvalue   &bitcoinvalue::operator=(const bitcoinvalue &obj)
{
    //std::cout << "bitcoinvalue copy assignement coperator called" << std::endl;
    this->_value = obj._value;
    this->_date = obj._date;
    return (*this);
}

// methods

float       bitcoinvalue::getTotalValue(float const amount)
{
    return (this->_value * amount);
}

// accessor

float       bitcoinvalue::getValue(void) { return (_value); }
std::string bitcoinvalue::getDate(void) { return (_date); }
void        bitcoinvalue::setValue(float const value) { _value = value; }
void        bitcoinvalue::setDate(std::string const date) { _date = date; }