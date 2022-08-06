#include <vector>

using namespace std;
class MedianOfInts
{
public:
    vector<int> &arrayOne;
    vector<int> &arrayTwo;

    MedianOfInts(vector<int> &one, vector<int> &two) : arrayOne(one), arrayTwo(two)
    {
    }

    /**
     * @brief Finds the median of two sorted arrays. The median is the value in the middle.
     * In the event of an EVEN number of values. The median will be two values in the middle / 2
     *
     * @return double The Median Value
     */
    double findMedian()
    {
        int answer = 0;

        int arrayOneSize = arrayOne.size();
        int arrayTwoSize = arrayTwo.size();
        int totalSize = arrayOneSize + arrayTwoSize;
        int medianIndex = totalSize / 2;
        vector<int> combinedArray;
        int arrayOneIndex = 0;
        int arrayTwoIndex = 0;
        int combinedArrayIndex = 0;

        while (combinedArrayIndex <= medianIndex)
        {
            int arrayOneValue;
            int arrayTwoValue;

            if (arrayOneIndex >= arrayOneSize)
            {
                arrayTwoValue = arrayTwo[arrayTwoIndex];
                combinedArray.push_back(arrayTwoValue);
                arrayTwoIndex++;
            }
            else if (arrayTwoIndex >= arrayTwoSize)
            {
                arrayOneValue = arrayOne[arrayOneIndex];
                combinedArray.push_back(arrayOneValue);
                arrayOneIndex++;
            }
            else
            {
                arrayOneValue = arrayOne[arrayOneIndex];
                arrayTwoValue = arrayTwo[arrayTwoIndex];
                if (arrayOneValue <= arrayTwoValue)
                {
                    combinedArray.push_back(arrayOneValue);
                    arrayOneIndex++;
                }
                else
                {
                    combinedArray.push_back(arrayTwoValue);
                    arrayTwoIndex++;
                }
            }

            combinedArrayIndex++;
        }

        // Even values
        if (totalSize % 2 == 0)
        {
            int valueOne = combinedArray[combinedArrayIndex - 2];
            int valueTwo = combinedArray[combinedArrayIndex - 1];
            double total = valueOne + valueTwo;

            return total / 2;
        } // Odd Values
        else
        {
            return combinedArray[combinedArrayIndex - 1];
        }
    }
};

int main(int args, char **someArgs)
{
    vector<int> testVecOne = {1, 2};
    vector<int> testVecTwo = {3, 4};

    vector<int> testVecThree = {1, 3};
    vector<int> testVecFour = {2};

    vector<int> single = {2};
    vector<int> singleTwo = {9};

    vector<int> zero;
    MedianOfInts meow = MedianOfInts(single, zero);
    double answer = meow.findMedian();

    return 0;
}