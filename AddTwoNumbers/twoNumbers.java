import java.util.*;

public class twoNumbers 
{
    public static void main(String[] asldkasldksd) {
        System.out.println("What");
        Solution someSolution = new Solution();
        int []arrayOne = {9, 3};
        int []arrayTwo = {5, 4};
        ListNode l1 = ListNode.fromArrayToListNode(arrayOne);
        ListNode l2 = ListNode.fromArrayToListNode(arrayTwo);


        int []testArrayOne = {2,4,3};
        int []testArrayTwo = {5,6,4};

        int []longNines = {9,9,9,9,9,9,9};
        int []shortNines = {9,9,9,9};

        ListNode l3 = ListNode.fromArrayToListNode(testArrayOne);
        ListNode l4 = ListNode.fromArrayToListNode(testArrayTwo);

        ListNode answer = someSolution.addTwoNumbers(l3, l4);
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

    public static ListNode fromArrayToListNode(int[] somearray)
    {
        ListNode answer = new ListNode();
        ListNode current = answer;

        for(int i=0; i<somearray.length; i++)
        {
            current.val = somearray[i];
            current.next = new ListNode();
            current = current.next;
        }

        return answer;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode answer = new ListNode();
        ListNode current = answer; // Keeps track of Node we're currently adding answers to
        Stack<Integer> someListOfNumbers = new Stack<>();
        while (l1.next != null || l2.next != null || !someListOfNumbers.empty()) 
        {
            int valueOne = Integer.MAX_VALUE;
            int valueTwo = Integer.MAX_VALUE;

            if (l1.next != null) {
                valueOne = l1.val;
                l1 = l1.next;
                someListOfNumbers.push(valueOne);
            }
            if (l2.next != null) {
                valueTwo = l2.val;
                l2 = l2.next;
                someListOfNumbers.push(valueTwo);
            }

            int total = Solution.processTwoNumbers(someListOfNumbers, current);
            current = current.next;

            if(total != Integer.MAX_VALUE)
            {
                System.out.println("haha");
                someListOfNumbers.push(total);
            }

        }

        return answer;
    }

    public static int processTwoNumbers(Stack<Integer> someListOfIntegers, ListNode current) 
    {
        int answer = Integer.MAX_VALUE;

        while (!someListOfIntegers.isEmpty()) 
        {
            if (answer == Integer.MAX_VALUE) 
            {
                answer = 0;
            }
            answer += someListOfIntegers.pop();

        }
        int leftOverDigit = Integer.MAX_VALUE;
        int secondDigit;

        if (answer / 10 >= 1 || answer / 10 <= -1) // Checking to see if numbers are more than ONE digit
        {
            leftOverDigit = 1;
            
        } 
        secondDigit = answer % 10;

        current.val = secondDigit;
        current.next = new ListNode();
       
        return leftOverDigit;
    }
}
