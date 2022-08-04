#include <vector>
#define NULL 0

using namespace std;

class RemoveDup
{

public:
    RemoveDup(vector<int> &nums) : someVector(nums)
    {
    }

    int removeDuplicates()
    {
        int answer = 0;
        int currentNum = someVector[0];
        int nextNum = 0;
        int j = 1;
        bool done = false;

        for (int i = 1; i < someVector.size(); i++)
        {
            // currentNum = someVector.at(i);
            nextNum = someVector.at(i);
            if (currentNum != nextNum)
            {
                answer++;
                someVector[answer] = nextNum;
                currentNum = nextNum;
            }
        }
        return answer + 1;
    }

    vector<int> &someVector;
};

int main(int argc, char **meowMew)
{
    vector<int> someVector;
    vector<int> someVec{1, 1, 2};
    vector<int> bigVec{0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    RemoveDup meow = RemoveDup(someVec);
    int answer = meow.removeDuplicates();
}