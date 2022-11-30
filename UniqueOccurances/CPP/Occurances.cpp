#include <vector>
#include <iostream>
#include "Occurances.h"
#include <map>

using namespace std;
Occurances::Occurances(std::vector<int> &anArray) : arr(anArray){

                                                    };

bool checkMapHelper(map<int, int> &aMap)
{
    map<int, int> occurancesMap;
    bool answer = true;
    for (auto &x : aMap)
    {
        int numOfOccurances = x.second;

        pair<map<int, int>::iterator, bool> somePair;
        somePair = occurancesMap.insert(pair<int, int>(numOfOccurances, x.first));

        if (somePair.second == false) // Already has value
        {
            answer = false;
            break;
        }
    }
    return answer;
}

bool Occurances::uniqueOccurances()
{
    map<int, int> someMap;
    bool answer = false;

    for (int i = 0; i < arr.size(); i++)
    {
        int valueFromArray = arr[i];
        pair<map<int, int>::iterator, bool> somePair;
        somePair = someMap.insert(pair<int, int>(valueFromArray, 1));
        if (somePair.second == false) // Already has value
        {
            int value = somePair.first->second;
            // pair<map<int, int>::iterator, bool> anotherPair;
            someMap[valueFromArray] = value + 1;
        }
    }
    answer = checkMapHelper(someMap);

    return answer;
};

int main(int argc, char **someArgsssss)
{
    vector<int> arrayOne = {1, 2, 2, 3, 4, 4, 5, 5, -1};
    vector<int> arraySmall = {1, 2};
    vector<int> arrayTwo = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    Occurances someOccurant = Occurances(arraySmall);
    bool answer = someOccurant.uniqueOccurances();
    return 0;
};