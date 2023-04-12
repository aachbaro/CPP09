#ifndef BITCOINVALUE_HPP
# define BITCOINVALUE_HPP
# include <string.h>
# include <string>
# include <iostream>

class bitcoinvalue {

private :

    std::string _date;
    float       _value;

public :

    //constructor - destructor

    bitcoinvalue(void);
    bitcoinvalue(std::string const date, float const value);
    bitcoinvalue(const bitcoinvalue &obj);
    ~bitcoinvalue(void);
    bitcoinvalue   &operator=(const bitcoinvalue &obj);

    //methods

    float       getTotalValue(float const amount);

    //accessor
    float       getValue();
    std::string getDate();
    void        setValue(float const value);
    void        setDate(std::string const date);
    
};

#endif