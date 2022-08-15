#include "parantheses.h"

using namespace std;

bool Parantheses::isValidParantheses()
{
    bool answer = true;
    for (int i = 0; i < aString.size() && answer; i++)
    {
        char someChar = aString.at(i);

        if (isValidLeftParantheses(someChar))
        {
            paranStack.push(someChar);
        }
        else if (isValidRightParantheses(someChar))
        {
            if (paranStack.empty())
            {
                answer = false;
            }
            else
            {
                char poppedParan = paranStack.top();
                paranStack.pop();
                if (poppedParan == '{' && someChar != '}')
                {
                    answer = false;
                }
                else if (poppedParan == '[' && someChar != ']')
                {
                    answer = false;
                }
                else if (poppedParan == '(' && someChar != ')')
                {
                    answer = false;
                }
            }
        }
    }
    if(!paranStack.empty())
    {
        answer = false;
    }
    return answer;
}

Parantheses::Parantheses(string &someString) : aString(someString)
{
    stack<char> someStack;
}

bool Parantheses::isValidRightParantheses(char aChar)
{
    bool answer = false;
    if (aChar == '}')
    {
        answer = true;
    }
    else if (aChar == ')')
    {
        answer = true;
    }
    else if (aChar == ']')
    {
        answer = true;
    }
    return answer;
}

bool Parantheses::isValidLeftParantheses(char aChar)
{
    bool answer = false;
    if (aChar == '{')
    {
        answer = true;
    }
    else if (aChar == '(')
    {
        answer = true;
    }
    else if (aChar == '[')
    {
        answer = true;
    }
    return answer;
}

int main(int argc, char **someArgs)
{
    string meow = "{}";

    Parantheses someParan = Parantheses(meow);
    bool answer = someParan.isValidParantheses();

    return 0;
}