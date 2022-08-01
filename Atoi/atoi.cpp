#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class Atoi
{
public:
    // string someString = "";

    string eliminateWhiteSpace(string someString)
    {
        bool hasWhiteSpace = true;
        string answer = someString;
        for (int i = 0; i + 1 < someString.length() && hasWhiteSpace; i++)
        {
            char someChar = someString.at(i);

            if (someChar == 32)
            {
                answer = someString.substr(i + 1);
            }
            else
            {
                hasWhiteSpace = false;
            }
        }
        return answer;
    }

    /**
     * @brief Checks if the char is correct. Only digits and - or +
     *
     * @param aChar char
     * @return true If correct char
     * @return false If not the correct char
     */
    bool checkCorrectChar(char aChar)
    {
        bool answer = false;

        if (aChar >= 48 && aChar <= 57)
        {
            answer = true;
        }
        else if (aChar == 45)
        {
            answer = true;
        }
        else if (aChar == 43)
        {
            answer = true;
        }
        return answer;
    }

    bool isDigit(char aChar)
    {
        int answer = aChar - 48;

        if (answer >= 48 && answer <= 57)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int convertStringToInt(string someString)
    {
        char prevChar = 0;
        char currentChar;
        long answer = 0;
        // bool isNum = false;
        bool isNeg = false;
        int signMultiplier = 1;
        bool leadingWhiteSpace = false;
        string stringWithoutWhiteSpace = someString;
        if(someString.length() == 0)
        {
            return 0;
        }

        // Checks if leading character is a white space and then eliminates white space
        if (someString.at(0) == 32)
        {
            stringWithoutWhiteSpace = eliminateWhiteSpace(someString);
        }
        // First Character must be a valid character '-+ or digit"
        if (!checkCorrectChar(stringWithoutWhiteSpace.at(0)))
        {
            return 0;
        }
        // Second Character MUST be a digit
        else if (stringWithoutWhiteSpace.length() > 1 && !isdigit(stringWithoutWhiteSpace.at(1)))
        {

            char someChar = stringWithoutWhiteSpace.at(0);
            if (someChar >= 48 && someChar <= 57)
            {
                return someChar - 48;
            }
            else
            {
                return 0;
            }
        }
        // If First char is negative, change sign multiplier and eliminate first Char
        if (stringWithoutWhiteSpace.at(0) == 45)
        {
            signMultiplier = -1;
            stringWithoutWhiteSpace = stringWithoutWhiteSpace.substr(1);
        }
        // If First char is positive, eliminate first Char
        else if (stringWithoutWhiteSpace.at(0) == 43)
        {
            stringWithoutWhiteSpace = stringWithoutWhiteSpace.substr(1);
        }

        for (int i = 0; i < stringWithoutWhiteSpace.length(); i++)
        {
            currentChar = stringWithoutWhiteSpace.at(i);

            /*if (prevChar == 45 || prevChar == 43)
            {
                if (currentChar < 48 || currentChar > 57)
                {
                    return 0;
                }
                else
                {
                    if (prevChar == 45)
                    {
                        signMultiplier = -1;currentChar - 48;
                    }
                }
            }*/
            if (currentChar >= 48 && currentChar <= 57)
            {
                int value = currentChar - 48;

                answer = answer * 10 + value * signMultiplier;

                if (answer > INT32_MAX)
                {
                    return INT32_MAX;
                }
                else if (answer < INT32_MIN)
                {
                    return INT32_MIN;
                }
            }
            else
            {
                return answer;
            }

            // prevChar = currentChar;
        }
        /*if (isNeg == true)
        {
            answer = answer * -1;
        }*/
        return answer;
    }
};

int main(int argc, char **someChars)
{
    Atoi someAtoi;
    string test1 = "     word 123";
    string negString = "   -42";
    string smallWhite = " 1";
    string bigNegNum = "  -w91283472332";
    string decimal = "   3.212";
    string someDecimal = "3.14159";
    string hiddenPlus = "  3323+34";
    string negTwelve = "+-12";
    string single = "1";
    string negative = "-";
    int answer = someAtoi.convertStringToInt(negative);
    // int answer = someAtoi.convertStringToInt(negString);
}