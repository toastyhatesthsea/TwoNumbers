#include "prefix.hpp"

Prefix::Prefix(vector<string> &someString) : someStrings(someString)
{
}

string Prefix::longestCommonPrefix()
{
    string answer = "";
    bool isValid = true;

    for (int charIndex = 0; isValid; charIndex++)
    {
        string firstString = someStrings.at(0);
        char prevChar;

        if (charIndex < firstString.size())
        {
            prevChar = firstString.at(charIndex);
        }
        else
        {
            isValid = false;
            return answer;
        }
        char someChar;
        for (int stringIndex = 0; stringIndex < someStrings.size() && isValid; stringIndex++)
        {
            string currentString = someStrings.at(stringIndex);

            if (charIndex >= currentString.size()) // Once you're past the size of a string, you're done
            {
                isValid = false;
                return answer;
            }
            else
            {
                someChar = currentString.at(charIndex);
            }

            if (someChar != prevChar)
            {
                isValid = false;
                return answer;
            }
            prevChar = someChar;
        }

        if (isValid)
        {
            string nextStringToAddToAnswer(1, prevChar);
            answer = answer + nextStringToAddToAnswer;
        }
    }
    return answer;
}

int main(int argc, char **someArgs)
{
    vector<string> testOne = {"flower", "flow", "flight"};
    vector<string> testTwo = {"dog", "racecar", "car"};
    vector<string> testThree = {"ab", "a"};


    Prefix meowPre = Prefix(testThree);
    string answer = meowPre.longestCommonPrefix();

    return 0;
}