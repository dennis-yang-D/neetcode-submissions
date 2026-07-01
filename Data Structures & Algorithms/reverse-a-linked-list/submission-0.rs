// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//     pub val: i32,
//     pub next: Option<Box<ListNode>>,
// }
//
// impl ListNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         ListNode { next: None, val }
//     }
// }

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // 1 -> 2 -> 3
        // node A = 1, node B = 2
        // Point B to A
        // Set A to B
        // Increment B

        if head.as_ref().is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }
        let mut left = None;
        let mut right = head;

        while let Some(mut node) = right {
            let temp = node.next.take();
            node.next = left;
            left = Some(node);
            right = temp;
        }

        return left;
    }
}
