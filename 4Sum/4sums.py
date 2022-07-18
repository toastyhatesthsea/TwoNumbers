from typing import Dict, List
from xmlrpc.client import Boolean

from numpy import numarray


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
    
    def createTablesTwo(self, nums: List[int]) -> Dict:
        lengthOfArray = len(nums)
        aTable = {}

        for i in range(lengthOfArray):
            for j in range(i+1, lengthOfArray):
                total = nums[i] + nums[j]

                returnedValue = aTable.get(total, None)

                if returnedValue != None:
                    someList = [list(returnedValue)]
                    anotherList = [i, j]

                    returnedValue.extend(anotherList)
                    #someList.append(j)
                    #returnedValue.extend(i, j)
                    #aTable.update(total, someList)
                    aTable.pop(total)
                    aTable[total] = returnedValue
                else:
                    aList = [i, j]
                    aTable[total] = aList

                #aTable[total] = i, j
        
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
                    return True
        
        return duplicate

    def biggestSumTwo(self, dictOfNums: Dict, nums: List[int], target: int) -> List[List[int]]:

        lengthOfArray = len(nums)
        answer = []
        tempers = []
        nums.sort()

        for i in range(lengthOfArray):
            for j in range(i+1, lengthOfArray):
                firstNum = nums[i]
                secondNum = nums[j]
                aList = [i, j]
                someTotal = firstNum + secondNum

                someLeftOver = target - someTotal

                returnedValue = dictOfNums.get(someLeftOver, None)
                duplicateAnswer = None
                someTempList = []

                if returnedValue != None and len(returnedValue) <= 2:
                    duplicateAnswer = self.checkForDuplicate(aList, returnedValue)
                    if duplicateAnswer == False:
                        someTempList = [i, j, returnedValue[0], returnedValue[1]]
                        oneAnswerList = [nums[someTempList[0]], nums[someTempList[1]], nums[someTempList[2]],
                            nums[someTempList[3]]]
                        someTempList.sort()
                        answer.append(oneAnswerList)
                elif returnedValue != None:
                    duplicateAnswer = self.checkTablesForAnswer(aList, returnedValue, answer, nums)
                    if len(duplicateAnswer) > 0:
                        someTempList = [i, j, duplicateAnswer[0], duplicateAnswer[1]]
                        oneAnswerList = [nums[someTempList[0]], nums[someTempList[1]], nums[someTempList[2]],
                            nums[someTempList[3]]]
                        
                        someTempList.sort()
                        answer.append(oneAnswerList)
                
                '''if(someTempList != []):
                    oneAnswerList = [nums[someTempList[0]], nums[someTempList[1]], nums[someTempList[2]],
                            nums[someTempList[3]]]
                    oneAnswerList.sort()
                    found = self.checkAnswerTable(oneAnswerList, answer)
                    if found == False:
                        #tempers.append(someTempList)
                        oneAnswerList = [nums[someTempList[0]], nums[someTempList[1]], nums[someTempList[2]],
                            nums[someTempList[3]]]
                        answer.append(oneAnswerList)'''

        return answer

    def checkAnswerTable(self, oneList: List[int], answerList: List[int]) -> Boolean:

        answer = False

        for aList in answerList:
            if oneList == aList:
                answer = True
                break
        
        return answer

    def checkTablesForAnswer(self, aKey: List[int], answerList: List[int], totalAnswers: List[int], 
    numArray: List[int]) -> List[int]:
        '''
        Takes aKey (int) and checks if there are any Duplicates in nums []
        '''
        foundDuplicate = True
        index = 0
        aList = []

        while index + 1 < len(answerList) and foundDuplicate == True:
            firstKey = answerList[index]
            secondKey = answerList[index+1]
            aList = [firstKey, secondKey]

            foundDuplicate = self.checkForDuplicate(aKey, aList)

            if foundDuplicate == False:
                actualNumberList = [numArray[firstKey], numArray[secondKey], numArray[aKey[0]], 
                numArray[aKey[1]]]
                actualNumberList.sort()
                foundDuplicate = self.checkAnswerTable(actualNumberList, totalAnswers)
                
            index += 2

        if foundDuplicate == True:
            return []
        else:
            return aList

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
    twos = [2,2,2,2,2]
    tester2 = [1,0,-1,0,-2,2]
    largeTest = [10, 2, 3, 4, 5, 9, 7, 8]
    anotherTest = [1,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5
    ,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5,-2,-5,-4,-3,3,3,5]
    rawr = [-3,-2,-1,0,0,1,2,3]
    hugeList = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,20,20,20,
    20,20,20,20,20,20,20,20,20,20,20,20,
    20,20,20,20,20,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
    30,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,50,50,50,50,50,50,
    50,50,50,50,50,50,50,50,50,50,50,50,50,50,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,
    60,60,60,60,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,80,80,80,80,80,80,
    80,80,80,80,80,80,80,80,80,80,80,80,
    80,80,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90]



    lengthOfArray = len(nums)
    target = 0
    meow = Solution()
    #TODO Create a Dictionary with Keys of the Total
    aDictOfNums = meow.createTablesTwo(tester2)
    aValuePair = aDictOfNums.get((1, 2), 1)
    answer = meow.biggestSumTwo(aDictOfNums, tester2, target)
    blah = 12

if __name__ == "__main__":
    main()