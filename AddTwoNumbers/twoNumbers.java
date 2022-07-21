import java.util.*;

public class twoNumbers {
    public static void main(String[] asldkasldksd) {
        System.out.println("What");
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        ListNode answer = new ListNode();
        while (l1 != null || l2 != null) 
        {
            int valueOne = Integer.MAX_VALUE;
            int valueTwo = Integer.MAX_VALUE;
            int numbersValid = 0;
            Stack<Integer> someListOfNumbers = new Stack<>();

            if (l1 != null) 
            {
                valueOne = l1.val;
                numbersValid += 1;
                someListOfNumbers.push(valueOne);
            }
            if( l2 != null) 
            {
                valueTwo = l2.val;
                numbersValid += 1;
                someListOfNumbers.push(valueTwo);
            }

            int total = Solution.processTwoNumbers(someListOfNumbers);

        }

        return new ListNode();
    }

    public static int processTwoNumbers(Stack<Integer> someListOfIntegers)
    {
        int answer = Integer.MAX_VALUE;

        while(!someListOfIntegers.isEmpty()) 
        {
            answer += someListOfIntegers.pop();
        }

        return answer;
    }
}
