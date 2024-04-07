#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

using namespace std;

class commandInvalidExeption
{
public:
    const char *what()
    {
        return "Command is invalid! Please enter a valid command.";
    };
};

class wrongFoodException
{
public:
    const char *what()
    {
        return "Jangan kasih makan itu dong, gabisa!";
    };
};

#endif