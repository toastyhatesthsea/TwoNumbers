#include <string>
#include <stack>

class Parantheses
{
public:
    std::string &aString;
    std::stack<char> paranStack;

    Parantheses(std::string &someString);
    bool isAParanthesesChar(char someChar);
    bool isValidParantheses();
    bool isValidLeftParantheses(char someChar);
    bool isValidRightParantheses(char someChar);
};
