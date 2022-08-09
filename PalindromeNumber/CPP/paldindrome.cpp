#include <math.h>

class Palindrome
{
public:
    int &theNumber;

    bool isPalindrome()
    {
        // Positive single digit
        if (theNumber < 10 && theNumber >= 0)
        {
            return true;
        }
        else if (theNumber < 0)
        {
            return false;
        }
        int copyOfNum = theNumber;
        int digits = numberOfDigits(copyOfNum) - 1;
        int tenMultiplier = pow(10, digits);
        int count = (digits + 1) / 2;
        // bool answer = true;

        while (count >= 0)
        {
            int lastDigit = copyOfNum % 10;
            int firstDigit = copyOfNum / tenMultiplier;

            if (lastDigit != firstDigit)
            {
                return false;
            }
            count--;
            if (count <= 0)
            {
                return true;
            }

            // Reduction of Number
            int substractionOfHighestDigit = firstDigit * tenMultiplier;
            copyOfNum = copyOfNum - substractionOfHighestDigit;
            copyOfNum = copyOfNum / 10;
            tenMultiplier /= 100;
        }
        return true;
    }

    /**
     * @brief Returns the number of digits in a number
     *
     * @param someNum int
     * @return int Returns the number of digits
     */
    static int numberOfDigits(int someNum)
    {
        int digits = 0;

        // Make positive
        if (someNum < 0)
        {
            someNum *= -1;
        }

        while (someNum > 0)
        {
            someNum = someNum / 10;
            digits++;
        }
        return digits;
    }

    Palindrome(int &someNumber) : theNumber(someNumber)
    {
    }
};

int main(int argc, char **someargs)
{
    int someNum = -20;
    Palindrome meow = Palindrome(someNum);
    bool answer = meow.isPalindrome();

    return 0;
}