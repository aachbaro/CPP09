#ifndef BITCOINVALUE_HPP
# define BITCOINVALUE_HPP
# include <string.h>
# include <string>
# include <iostream>

class bitcoinValue {

private :

    std::string _date;
    float       _value;

public :

    //constructor - destructor

    bitcoinValue(void);
    bitcoinValue(std::string const date, float const value);
    bitcoinValue(const bitcoinValue &obj);
    ~bitcoinValue(void);
    bitcoinValue   &operator=(const bitcoinValue &obj);

    //methods

    float       getTotalValue(float const amount);

    //accessor
    float       getValue();
    std::string getDate();
    void        setValue(float const value);
    void        setDate(std::string const date);
    
};

#endif