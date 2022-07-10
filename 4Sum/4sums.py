from typing import Dict, List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        someTables = self.createTables(nums)
        answer = self.getBiggestSum(someTables, target)

        return answer
    def createTables(self, nums: List[int]):

        lengthOfArray = len(nums)
        aTable = {}

        for i in range(lengthOfArray):
            for j in range(i+1, lengthOfArray):
                total = nums[i] + nums[j]
                aTable[i, j] = nums[i], nums[j]
        
        return aTable

    def checkSum(self, nums: List[int], answers: List[List[int]]):
        '''
        Only checks if one List is in the current large list of answers
        '''
        answer = False

        for aList in answers:
            if aList == nums:
                answer = True
                break
        
        return answer

    def checkForDuplicate(self, firstKey:List[int], secondKey:List[int]) -> bool:

        duplicate = False
        for aNum in firstKey:
            for secondNum in secondKey:
                if aNum == secondNum:
                    duplicate = True
                    break
        
        return duplicate

    def biggestSumTwo(self, dictOfNums: Dict, target: int) -> List[List[int]]:

        lengthOfDict = len(dictOfNums)
        row = 0
        column = 1

        while row < lengthOfDict - 1:
            firstValuePair = dictOfNums.get((row, column))
            secondRow = row
            while column < lengthOfDict:



        pass

    def getBiggestSum(self, dictOfNums: Dict, target: int) ->List[List[int]]:
        '''
        Uses a Temporary array of Lists of numbers to check for Duplicates
        '''
        lengthOfDict = len(dictOfNums)
        tempers = []
        answer = []
        endLoop = 4

        for firstKey, firstValue in dictOfNums.items():
            #tempers.append(firstKey)
            for secondKey, aValue in dictOfNums.items():
                if secondKey[0] > firstKey[0]:

                    aValueTotal = aValue[0] + aValue[1]
                    firstValueTotal = firstValue[0] + firstValue[1]
                    grandTotal = aValueTotal + firstValueTotal
                    if aValueTotal + firstValueTotal == target and self.checkForDuplicate(firstKey, secondKey) is False:
                        '''Only Proceed if all numbers are UNIQUE'''
                        '''aList = []
                        for i in range(len(aKey)):
                            aList.append(firstKey[i])
                            aList.append(aKey[i])'''
                        #aList.append(firstKey)
                        #aList.append(aKey)
                        aValueList = []
                        for j in range(len(aValue)):
                            aValueList.append(aValue[j])
                            aValueList.append(firstValue[j])

                        #aValueList.sort()
                        checkSumAnswer = self.checkSum(aValueList, answer)
                        #checkSumAnswer = False
                        if checkSumAnswer is False:
                            #tempers.append(aList)
                            answer.append(aValueList)

                        #answer.append(aList)
            #endLoop -= 1

            #if endLoop < 1:
                #break
        return answer


def main():
    nums = [3,5,9,8,7]
    tester2 = [1,0,-1,0,-2,2]
    largeTest = [10, 2, 3, 4, 5, 9, 7, 8]
    anotherTest = [1,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5
    ,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5]

    lengthOfArray = len(nums)
    target = -11
    meow = Solution()
    #TODO Create a Dictionary with Keys of the Total
    aDictOfNums = meow.createTables(anotherTest)
    aValuePair = aDictOfNums.get((1, 2), 1)
    answer = meow.getBiggestSum(aDictOfNums, target)
    blah = 12

if __name__ == "__main__":
    main()