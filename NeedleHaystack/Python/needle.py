class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        needleThing = NeedleThing(haystack, needle)
        return needleThing.findNeedle()


class NeedleThing:

    def __init__(self, strOne: str, strTwo: str) -> None:

        self.haystack = strOne
        self.needle = strTwo
        pass

    def findNeedle(self):

        if len(self.needle) == 0:
            return 0
        else:

            sizeOfNeedle = len(self.needle)
            sizeOfHaystack = len(self.haystack)
            answer = -1

            for i in range(0, sizeOfHaystack):

                someChar = self.haystack[i]

                if (someChar == self.needle[0] and sizeOfNeedle + i - 1 < sizeOfHaystack):
                    haystackSub = self.haystack[i:sizeOfNeedle+i]

                    if (haystackSub == self.needle):
                        answer = i
                        return i

            return answer


def main():
    needle = "ll"
    haystack = "hello"
    haystack = "aaaaa"
    needle = "bba"
    hayTwo = "a"
    needleTwo = "a"

    print(needle[0])

    needleThing = NeedleThing(hayTwo, needleTwo)

    answer = needleThing.findNeedle()
    print(answer)


if __name__ == "__main__":
    main()
