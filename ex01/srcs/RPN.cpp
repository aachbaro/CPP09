#include "../inc/RPN.hpp"

// constructor - destructor

rpn::rpn(void)
{
    //std::cout << "rpn default constructor called" << std::endl;
    _res = -1;
    return ;
}

rpn::rpn(std::string const expr)
{
    //std::cout << "rpn constructor called" << std::endl;
    int i = 0;
    std::string operators = "+-/*";

    while (expr[i])
    {
        if (isalnum(expr[i]))
            _stack.push_back(expr[i] - '0');
        else if (operators.find(expr[i]) != std::string::npos)
            handleOperatorToken(expr[i]);
        else if (isspace(expr[i])) {}
        else {
            std::cout << "Error" << std::endl;
            _res = -1;
            return ;
        }
        i++;
    }
    if (_stack.size() == 1){
        _res = _stack.back();
    }
    else {
        _res = -1;
        std::cout << "Error" << std::endl;
    }
}

rpn::rpn(const rpn &obj)
{
    //std::cout << "rpn copy constructor called" << std::endl;
    *this = obj;
    return ;
}

rpn::~rpn(void)
{
    //std::cout << "rpn destructor called" << std::endl;
    return ;
}

rpn   &rpn::operator=(const rpn &obj)
{
    //std::cout << "rpn copy assignement coperator called" << std::endl;
    _res = obj._res;
    _stack = obj._stack;
    return (*this);
}

// methods

void        rpn::handleOperatorToken(char const tkn)
{
    int tmp = _stack.back();

    _stack.pop_back();
    switch (tkn)
    {
    case '+':
        _stack.back() += tmp;
        break;
    case '-':
        _stack.back() -= tmp;
        break;
    case '/':
        _stack.back() /= tmp;
        break;
    case '*':
        _stack.back() *= tmp;
        break;
    
    default:
        break;
    }
}

// accessor

int       rpn::getRes(void) { return (_res); }