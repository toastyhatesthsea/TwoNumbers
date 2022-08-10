#include <string>
#include <iostream>

using namespace std;
class Palimdrone
{
public:
    string &someString;

    Palimdrone(string &aString) : someString(aString)
    {
    }

    string isPalimdrone(int startingIndex, int middle, bool isEven)
    {
        int cursorFront = startingIndex;
        int cursorBack;
        if (startingIndex == middle && startingIndex < someString.size() && isEven)
        {
            cursorBack = startingIndex + 1;
        }
        else
        {
            cursorBack = startingIndex;
        }

        //At the end of the string
        if(someString.size() > 2 && startingIndex == someString.size() - 1 )
        {
            cursorFront = someString.size() - 2;
            cursorBack = someString.size() - 1;
        }
        string answer = "";
        bool thisIsAPalimdrone = true;

        while (cursorFront >= 0 && cursorBack < someString.size() && thisIsAPalimdrone)
        {
            char firstChar = someString.at(cursorFront);
            char secondChar = someString.at(cursorBack);

            if (firstChar == secondChar)
            {
                if (cursorFront == cursorBack)
                {
                    string meow(1, firstChar);
                    answer = meow + answer;
                }
                else
                {
                    string meow(1, firstChar);
                    answer = meow.append(answer);
                    answer.push_back(secondChar);
                }
            }
            else
            {
                thisIsAPalimdrone = false;
            }
            cursorFront--;
            cursorBack++;
        }
        return answer;
    }

    string longestPalimdroneSubstring()
    {
        string answer = "";
        int largestPalimdrone = 1;
        int middleValue = someString.size() / 2;
        bool isEven = false;
        if (someString.size() % 2 == 0)
        {
            isEven = true;
            middleValue -= 1;
        }
        int potentialMax = 1;
        // int potentialMax = 1;
        int minimum = 0;

        for (int i = 0; i < someString.size(); i++)
        {
            string foundString = isPalimdrone(i, middleValue, isEven);
            minimum = i * 2 + 1;

            if (foundString.size() > answer.size())
            {
                answer = foundString;
            }
        }
        return answer;
    }

    /**
     * @brief Finds the max potential size of a Palimdrone based on the current string
     *
     * @param index int
     * @return int Returns max
     */
    int findMaxSize(int index, int middle, bool isEven)
    {
        int answer = 0;

        if (index <= middle)
        {
        }

        return answer;
    }


};

int main(int argc, char **someargs)
{
    string aString = "babad";
    string bigger = "abababacc";
    string maxPalimdrone = "babab";
    string harhar = "bad";
    string evens = "babbab";
    string single = "a";
    string cbbd = "cbbd";
    string abb = "abb";
    Palimdrone aDrone = Palimdrone(abb);
    string answer = aDrone.longestPalimdroneSubstring();
    return 0;
}