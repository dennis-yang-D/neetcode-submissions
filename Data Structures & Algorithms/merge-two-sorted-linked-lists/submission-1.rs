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
    pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = Box::new(ListNode{val: 0, next: None});
        let mut tail: &mut ListNode = head.as_mut();

        let mut l1 = list1;
        let mut l2 = list2;

        while let (Some(node1), Some(node2)) = (&l1, &l2) {
            let ListNode { val: v1, next: ref n1 } = **node1;
            let ListNode { val: v2, next: ref n2 } = **node2;

            if v1 < v2 {
                tail.next = Some(node1.clone());
                l1 = n1.clone();
            }
            else {
                tail.next = Some(node2.clone());
                l2 = n2.clone();
            }
            tail = tail.next.as_mut().unwrap();
        }

        if let Some(node1) = &l1
        {tail.next = l1;}
        else
        {tail.next = l2;}

        if head.next.is_none() {
            return None;
        }

        return Some(head.next.unwrap());
    }
}
