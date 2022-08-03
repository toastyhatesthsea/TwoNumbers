public class ReverseInt {
    private int theInt;

    public int reverseTheInt() {
        int answer = 0;

        while (theInt != 0) {
            int lastDigit = theInt % 10;
            int answerBeforeMultiply = answer;

            answer *= 10;
            answer += lastDigit;

            if (((answer - lastDigit) / 10) != answerBeforeMultiply) {
                return 0;
            }

            theInt /= 10;
        }
        return answer;
    }

    public ReverseInt(int someInt) {
        theInt = someInt;
    }
}

class ReverseTesters {
    public static void main(String[] aksjaksjkaStrings) {

        int smallInt = 123;
        ReverseInt someReverse = new ReverseInt(smallInt);
        someReverse.reverseTheInt();

    }
}