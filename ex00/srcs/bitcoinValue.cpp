#include "../inc/bitcoinValue.hpp"

// constructor - destructor

bitcoinValue::bitcoinValue(void)
{
    //std::cout << "bitcoinValue default constructor called" << std::endl;
    this->_value = 0;
    this->_date = "";
    return ;
}

bitcoinValue::bitcoinValue(std::string const date, float const value)
{
    //std::cout << "bitCoin constructor called" << std::endl;
    this->_value = value;
    this->_date = date;
}

bitcoinValue::bitcoinValue(const bitcoinValue &obj)
{
    //std::cout << "bitcoinValue copy constructor called" << std::endl;
    *this = obj;
    return ;
}

bitcoinValue::~bitcoinValue(void)
{
    //std::cout << "bitcoinValue destructor called" << std::endl;
    return ;
}

bitcoinValue   &bitcoinValue::operator=(const bitcoinValue &obj)
{
    //std::cout << "bitcoinValue copy assignement coperator called" << std::endl;
    this->_value = obj._value;
    this->_date = obj._date;
    return (*this);
}

// accessor

float       bitcoinValue::getValue(void) { return (_value); }
std::string bitcoinValue::getDate(void) { return (_date); }
void        bitcoinValue::setValue(float const value) { _value = value; }
void        bitcoinValue::setDate(std::string const date) { _date = date; }