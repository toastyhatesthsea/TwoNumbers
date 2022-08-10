#include <vector>

using namespace std;
class Insert
{
    vector<int> &someNums;

public:
    Insert(vector<int> &nums) : someNums(nums)
    {
    }

    /**
     * @brief Narrows the array down to where the target might be
     *
     * @param min int&
     * @param max int&
     */
    void reduceArray(int &min, int &max, int &indexOfMiddle, int target)
    {
        int current = someNums[indexOfMiddle];
        if (target < current)
        {
            max = indexOfMiddle;
        }
        else
        {
            min = indexOfMiddle;
            // min = min + total;
        }
        int difference = max - min;
        if (difference % 2 == 0)
        {
        }
        indexOfMiddle = difference / 2 + min;
    }

    int searchInsert(int target)
    {
        int middleIndex;
        if (someNums.size() % 2 == 0)
        {
            middleIndex = someNums.size() / 2 - 1;
        }
        else
        {
            middleIndex = someNums.size() / 2;
        }
        // int middleIndex = someNums.size() / 2;
        int minIndex = 0;
        int maxIndex = someNums.size() - 1;
        int answer = 0;

        bool found = false;

        while (!found)
        {
            int value = someNums[middleIndex];
            if (value == target)
            {
                found = true;
                answer = middleIndex;
            }
            else if (minIndex + 1 == middleIndex && maxIndex - 1 == middleIndex)
            {
                int minValue = someNums[minIndex];
                int maxValue = someNums[maxIndex];
                int middleValue = someNums[middleIndex];
                // In the middle Value
                if (target <= minValue)
                {
                    answer = minIndex;
                }
                else if(target <= middleValue)
                {
                    answer = middleIndex;
                }
                else if (target <= maxValue)
                {
                    answer = maxIndex;
                }
                else
                {
                    answer = maxIndex + 1;
                }
                found = true;
            }
            else if (minIndex == maxIndex)
            {
                found = true;
                int value = someNums[minIndex];
                if (target <= value)
                {
                    answer = minIndex;
                }
                else
                {

                    answer = maxIndex + 1;
                }
            }
            else if (middleIndex == maxIndex)
            {
                found = true;
                answer = middleIndex;
            }
            else if (maxIndex - minIndex == 1)
            {
                int maxValue = someNums[maxIndex];
                int minValue = someNums[minValue];

                if (target <= minValue)
                {
                    answer = minIndex;
                }
                else if(target <= maxValue)
                {
                    answer = maxIndex;
                }
                else
                {
                    answer = maxIndex + 1;
                }

                found = true;
            }
            else
            {
                reduceArray(minIndex, maxIndex, middleIndex, target);
            }
        }
        return answer;
    }
};

int main(int argc, char **argcs)
{
    vector<int> someArray = {-8, -6, -5, -4, -2, -1, 0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 13, 15};
    vector<int> testOne = {1, 2, 3};
    vector<int> single = {1};
    vector<int> evenOne = {1, 2, 3, 5};
    vector<int> testTwo = {1, 3, 5, 6};
    vector<int> two = {1, 3};
    vector<int> simple = {1, 3, 5};

    int middleTestOne = testOne.size() / 2;
    int size = someArray.size();
    int middle = size / 2;
    Insert someInsert = Insert(simple);
    int answer = someInsert.searchInsert(7);
    // TODO Need to look into values that are in the middle of Min/Max

    return 0;
}