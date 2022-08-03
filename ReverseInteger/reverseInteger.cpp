#include <limits>
#include <iostream>

using namespace std;
class ReverseInts
{
public:
    int reverseTheInt()
    {
        int answer = 0;
        int digits = 0;
        int positiveCopyOfInt = theNumber;
        if (isNeg)
        {
            positiveCopyOfInt *= -1;
        }
        while (theNumber != 0)
        {
            int lastNumber = theNumber % 10;
            int overFlowCheck = answer * 10;
            if (overFlowCheck / 10 != answer)
            {
                if (isNeg)
                {
                    return __INT32_MAX__ * -1;
                }
                else
                {
                    return __INT32_MAX__;
                }
            }
            try
            {
                /* code */
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }

            answer = answer * 10;

            answer += lastNumber;
            theNumber /= 10;
            if (answer != 0)
            {
                bool validNum = checkValidNum(answer);
                if (!validNum)
                {
                    if (isNeg)
                    {
                        return __INT32_MAX__ * -1;
                    }
                    else
                    {
                        return __INT32_MAX__;
                    }
                }
                digits++;
            }
        }
        return answer;
    }

    bool checkValidDigitSize(int someInt)
    {
        int maxer = INT32_MAX;
        int divider = 100000000;
        bool answer = true;

        for (int i = 0; someInt != 0 && answer; i++)
        {
            int firstDigit = someInt / divider;
            int firstDigitOfMax = maxer / divider;

            if (firstDigit > firstDigitOfMax)
            {
                answer = false;
            }
            divider /= 10;
        }
        return answer;
    }

    int getDefault()
    {
        if (isNeg)
        {
            return INT32_MIN;
        }
        else
        {
            return INT32_MAX;
        }
    }

    int reverseIntShift()
    {
        int digits = 1;
        int answer = 0;
        if (isNeg)
        {
            theNumber *= -1;
        }
        for (int i = 0; theNumber != 0; i++)
        {
            int lastDigit = theNumber % 10;
            theNumber = theNumber / 10;
            int savedAnswerBeforeThreeShift = answer;
            if (digits == 9)
            {
                bool validAnswer = checkValidDigitSize(answer);
                if (!validAnswer)
                {
                    return getDefault();
                }
            }
            answer = answer << 3;
            int oneShiftAnswer = savedAnswerBeforeThreeShift << 1;
            answer = answer + oneShiftAnswer;

            int newAnswer = answer / 10;
            if (newAnswer != savedAnswerBeforeThreeShift)
            {
                getDefault();
            }
            int answerBeforeAdd = answer;
            answer = answer + lastDigit;

            if (answerBeforeAdd != answer - lastDigit)
            {
                return getDefault();
            }
            digits++;
        }

        if (isNeg)
        {
            answer *= -1;
        }
        return answer;
    }

    bool checkValidNum(int aNum)
    {
        if (isNeg == true)
        {
            return aNum < 0;
        }
        else
        {
            return aNum >= 0;
        }
    }

    bool isNeg = false;
    bool isPos = false;
    int theNumber;

    ReverseInts(int someInt)
    {
        if (someInt < 0)
        {
            isNeg = true;
        }
        else
        {
            isPos = true;
        }
        theNumber = someInt;
    }
};

int main(int argc, char **someArgs)
{
    int smallNeg = -10;
    int biggerNeg = -239;
    int bigNum = 1534236469;
    int oneTwoThree = 123;
    int one = -1;
    int result = one << 3;
    one = one << 1;
    result = result & one;
    int max = INT32_MAX;

    ReverseInts someReverse(bigNum);
    int someAnswer = someReverse.reverseIntShift();
    // int overFlowInt = 964632435 * 10;
}