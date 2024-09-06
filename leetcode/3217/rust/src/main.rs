use std::collections::HashSet;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn modified_list(nums: Vec<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    fn m(nums: &HashSet<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            None
        } else {
            let h = head.unwrap();
            let val = h.val;
            if nums.contains(&h.val) {
                m(nums, h.next)
            } else {
                Some(Box::new(ListNode {
                    val,
                    next: m(nums, h.next),
                }))
            }
        }
    }
    let s: HashSet<i32> = HashSet::from_iter(nums);

    m(&s, head)
}

fn main() {
    let mut l = Some(Box::new(ListNode::new(2)));
    for _ in 0..99999 {
        let t = Some(Box::new(ListNode { val: 1, next: l }));
        l = t;
    }
    let p = modified_list(vec![1], l).unwrap();
    assert!(p.next.is_none());
    assert_eq!(p.val, 2);
}
