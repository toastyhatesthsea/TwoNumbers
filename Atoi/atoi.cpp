#include <string>
#include <string.h>

using namespace std;

class Atoi
{
public:
    // string someString = "";

    string eliminateWhiteSpace(string someString)
    {
        bool hasWhiteSpace = true;
        string answer = someString;
        for (int i = 1; i + 1 < someString.length() && hasWhiteSpace; i++)
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

    int convertStringToInt(string someString)
    {
        char prevChar;
        char currentChar;
        int answer = 0;
        bool isNum = false;
        bool isNeg = false;
        bool leadingWhiteSpace = false;
        string stringWithoutWhiteSpace= someString;

        //Checks if leading character is a white space and then eliminates white space
        if(someString.at(0) == 32)
        {
            stringWithoutWhiteSpace = eliminateWhiteSpace(someString);
        }

        for (int i = 0; i < someString.length(); i++)
        {
            currentChar = someString.at(i);

            if (i == 0 && currentChar == 32)
            {
                leadingWhiteSpace = true;
            }

            if (currentChar >= 48 && currentChar <= 57)
            {
                isNum = true;
                int value = currentChar - 48;
                answer = answer * 10 + value;
                if (prevChar == 45)
                {
                    isNeg = true;
                }
            }
            prevChar = currentChar;
        }
        if (isNeg == true)
        {
            answer = answer * -1;
        }
        return answer;
    }
};

int main(int argc, char **someChars)
{
    Atoi someAtoi;
    string test1 = "     word 123";
    string negString = "   -42";
    string whiteSpaceAnswer = someAtoi.eliminateWhiteSpace(test1);
    // int answer = someAtoi.convertStringToInt(negString);
}