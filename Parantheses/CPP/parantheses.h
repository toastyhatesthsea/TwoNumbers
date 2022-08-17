#include <string>
#include <stack>

class Parantheses
{
public:
    std::string &aString;
    std::stack<char> paranStack;
    std::string current;

    Parantheses(std::string &someString);
    bool isAParanthesesChar(char someChar);
    bool isValidParantheses();
    /**
     * @brief Get and return the longest valid parantheses before it is no longer valid
     * 
     * @param index (int)The index of where to start looking for the valid Parantheses
     * @return int The index where the Parantheses are no longer valid
     */
    std::string getParantheses(int index);

    bool isValidLeftParantheses(char someChar);
    bool isValidRightParantheses(char someChar);
    int longestValidParantheses();
};
