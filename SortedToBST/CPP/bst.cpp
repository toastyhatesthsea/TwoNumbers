#include <vector>
#include <iostream>

using namespace std;
class BST
{

public:
    BST(vector<int> &aNum) : someNums(aNum)
    {
    }
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode createTree(int currentIndex)
    {
        if (currentIndex == 0)
        {
            int someValue = someNums[currentIndex];
            TreeNode endNode = TreeNode(someValue);
            return endNode;
        }
        else if (currentIndex == someNums.size() - 1)
        {
            int someValue = someNums[currentIndex];
            TreeNode endNode = TreeNode(someValue);
            return endNode;
        }
        else
        {
            int currentValue = someNums[currentIndex];
            int leftShiftIndex = currentIndex - 1;
            int rightShiftIndex = currentIndex + 1;

            TreeNode leftSide = createTree(leftShiftIndex);
            TreeNode rightSide = createTree(rightShiftIndex);

            TreeNode root = TreeNode(currentValue, &leftSide, &rightSide);
            return root;
        }
    }

    TreeNode createTreeFromSortedArray(int min, int max)
    {
        if (min > max)
        {
            // EndNode
            // int aValue = someNums[min];
            return NULL;
        }
        /*else if (max - min == 1)
        {
            int aValue = someNums[min];
            TreeNode someTree = TreeNode(aValue);
            return someTree;
        }*/
        /*else if (max - min == 2)
        {
            int middleIndex = (max - min) / 2 + min;
            int middleValue = someNums[middleIndex];
            int minValue = someNums[min];
            int maxValue = someNums[max];

            TreeNode rightSide = TreeNode(maxValue);
            TreeNode leftSide = TreeNode(minValue);
            TreeNode someRoot = TreeNode(middleValue, &leftSide, &rightSide);
            return someRoot;
        }*/
        else
        {
            int middleIndex = (min + max) / 2;
            int leftMax = middleIndex - 1;
            int rightMin = middleIndex + 1;
            int rootValue = someNums[middleIndex];
            

            TreeNode leftSide = createTreeFromSortedArray(min, leftMax);
            TreeNode rightSide = createTreeFromSortedArray(rightMin, max);

            TreeNode root = TreeNode(rootValue);
            root.left = &leftSide;
            root.right = &rightSide;
//            root->

            return root;
        }
    }

    TreeNode getTreeNode()
    {
        return someTree;
    }

private:
    TreeNode someTree;
    vector<int> &someNums;
};

int main(int argc, char **someArgs)
{
    vector<int> testOne = {-10, -3, 0, 5, 9};
    vector<int> testTwo = {1, 2, 3};

    BST someTree = BST(testOne);
    BST::TreeNode someRoot = someTree.createTreeFromSortedArray(0, testOne.size() - 1);
    //BST::TreeNode someRoot = someTree.createTree(testOne.size() /2);

    return 0;
}
