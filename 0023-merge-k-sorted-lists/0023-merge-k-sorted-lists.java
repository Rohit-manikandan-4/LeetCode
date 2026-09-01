import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            (a, b) -> a.val - b.val
        );

        // Add the first node of every non-empty list
        for (ListNode list : lists) {
            if (list != null) {
                pq.add(list);
            }
        }

        // Dummy node to simplify building the result
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        while (!pq.isEmpty()) {

            // Get the smallest node
            ListNode node = pq.poll();

            // Add it to the result
            current.next = node;
            current = current.next;

            // Add the next node from the same list
            if (node.next != null) {
                pq.add(node.next);
            }
        }

        return dummy.next;
    }
}