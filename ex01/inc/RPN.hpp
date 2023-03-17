#ifndef RPN_HPP
# define RPN_HPP
# include <string.h>
# include <string>
# include <iostream>
# include <cctype>
# include <list>

class rpn {

private :

    std::list<int>  _stack;
    int             _res;

public :

    //constructor - destructor

    rpn(void);
    rpn(std::string input);
    rpn(const rpn &obj);
    ~rpn(void);
    rpn   &operator=(const rpn &obj);

    //methods

    void    handleNumericToken(char tkn);
    void    handleOperatorToken(char const tkn);

    //accessor
    int         getRes(void);
};

#endif