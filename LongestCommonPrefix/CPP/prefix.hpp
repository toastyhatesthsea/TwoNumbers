#include <string>
#include <vector>

using namespace std;
class Prefix
{
public:
    Prefix(vector<string> &someVectorOfStrings);
    string longestCommonPrefix();

private:
    vector<string> &someStrings;
};