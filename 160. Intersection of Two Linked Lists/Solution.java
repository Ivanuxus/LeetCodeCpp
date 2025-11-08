import java.util.List;

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode currentA = headA;
        ListNode currentB = headB;
        int skipA = 0;
        int skipB = 0;
        while (true) {
            while (true) {
                if (currentA == currentB) {
                    System.out.printf("Intersected at %d, skipA:%d, skipB:%d", currentA.val, skipA, skipB);
                    return currentA;
                }
                if (currentB == null || currentB.next == null) {
                    currentB = headB;
                    skipB = 0;
                    break;
                }
                skipB += 1;
                currentB = currentB.next;
            }
            skipA += 1;
            currentA = currentA.next;
            if (currentA == null) {
                return null;
            }
        }
    }

    public ListNode getLinkedListFromArray(int[] list) {
        ListNode head = new ListNode(0);
        ListNode current = head;
        for (int i = 0; i < list.length; i++) {
            current.val = list[i];
            if (i + 1 < list.length) {
                current.next = new ListNode(0);
                current = current.next;

            }
        }
        return head;
    }

    public ListNode[] AddToArray(ListNode[] array, ListNode elem) {
        ListNode[] newArray = new ListNode[array.length + 1];
        for (int i = 0; i < array.length; i++) {
            newArray[i] = array[i];
        }
        newArray[array.length] = elem;
        return newArray;
    }

    public ListNode[] makeIntersection(ListNode headA, ListNode headB) {
        ListNode[] result = {};
        ListNode currentA = headA;
        ListNode currentB = headB;
        int skipA = 0;
        int skipB = 0;
        while (true) {
            while (true) {
                if (currentA.val == currentB.val) {
                    System.out.printf("Intersected at %d, skipA:%d, skipB:%d\nTrying to check equality to the end.", currentA.val, skipA, skipB);
                    boolean equality = true;
                    ListNode buffA = currentA;
                    ListNode buffB = currentB;
                    while (true) {
                        if (currentA.val != currentB.val) {
                            equality = false;
                        }
                        if (currentA.next == null && currentB.next == null && equality) {
                            System.out.print("This is the same endings");
                            currentA = buffA;
                            currentB = buffB;

                            break;
                        }
                        if (currentA.next != null && currentB.next != null) {
                            currentB = currentB.next;
                            currentA = currentA.next;
                        }
                        if (currentA.next == null && currentB.next != null || currentA.next != null && currentB.next == null) {
                            equality = false;
                            currentA = buffA;
                            currentB = buffB;
                            break;
                        }
                    }
                    if (equality) {
                        currentB.next = currentA.next;
                        result = AddToArray(result, headA);
                        result = AddToArray(result, headB);
                        return result;
                    }

                }
                skipB += 1;
                currentB = currentB.next;
                if (currentB == null) {
                    currentB = headB;
                    skipB = 0;
                    break;
                }
            }
            skipA += 1;
            currentA = currentA.next;
            if (currentA == null) {
                return result;
            }
        }
    }

    public static void main(String[] args) {
        Solution S = new Solution();
        int[] listA = {2, 6, 4};
        int[] listB = {1, 5};
        ListNode[] arrays = {};
        ListNode LLA = S.getLinkedListFromArray(listA);
        ListNode LLB = S.getLinkedListFromArray(listB);
        if (S.makeIntersection(LLA, LLB).length > 0) {
            arrays = S.makeIntersection(LLA, LLB);
            System.out.print("\n\n");
            S.getIntersectionNode(arrays[0], arrays[1]);
        } else {
            System.out.print("Non-existence of Intersection\n");
        }

    }
}