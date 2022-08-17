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
    if (!paranStack.empty())
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

string Parantheses::getParantheses(int index)
{
    bool valid = true;
    string totalString = aString;
    int correctCount = 0; // Keeps track of the amount of correct Parantheses
    stack<int> someStack;

    while (valid && index < aString.size())
    {
        char someChar = aString.at(index);

        if (isValidLeftParantheses(someChar))
        {
            someStack.push(index);
        }
        else if (isValidRightParantheses(someChar) && !someStack.empty())
        {
            bool isCorrectParan = false;
            int poppedParanIndex = someStack.top();
            char poppedParan = aString.at(poppedParanIndex);
            someStack.pop();
            if (poppedParan == '{' && someChar == '}')
            {
                isCorrectParan = true;
            }
            else if (poppedParan == '[' && someChar == ']')
            {
                isCorrectParan = true;
            }
            else if (poppedParan == '(' && someChar == ')')
            {
                isCorrectParan = true;
            }

            if (isCorrectParan == true)
            {
                totalString.replace(index, 1, " ");
                totalString.replace(poppedParanIndex, 1, " ");
                correctCount++;
            }
        }
        index++;
    }
    return totalString;
}

int Parantheses::longestValidParantheses()
{
    int answer = 0;
    int current = 0;
    string returnedString = getParantheses(0);
    bool foundWellFormedParantheses = false;

    for (int i = 0; i < returnedString.size(); i++)
    {

        char someChar = returnedString.at(i);

        if (someChar == ' ')
        {
            current++;

            if (current > answer)
            {
                answer = current;
            }
        }
        else
        {
            current = 0;
        }
    }
    return answer;
}

int main(int argc, char **someArgs)
{
    string meow = "{{}}()";
    string testOne = "{{{(){";
    string testTwo = "(((()(()";

    string testThree = "{{{(){()()";

    string testFour = "}}}()}";

    string testFive = "{{()}}";
    string testSix = "{((((((}";
    string testSeven = "(((((()";

    testFive.replace(0, 1, " ");

    Parantheses someParan = Parantheses(testThree);
    int answer = someParan.longestValidParantheses();

    // TODO Can push parantheses index values into an array
    // TODO Or you can simply erase properly formed parantheses from the original string
    // TODO and then count how large the uninterrupted 'spaces' are and return the largest one

    return 0;
}