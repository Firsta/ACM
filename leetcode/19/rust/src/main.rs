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

pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
    let mut dummy = Box::new(ListNode { val: 0, next: head });
    let mut fast = dummy.clone();

    let mut n = n;
    while n > 0 {
        fast = fast.next.unwrap();
        n -= 1;
    }

    let mut slow = dummy.as_mut();
    while fast.next.is_some() {
        fast = fast.next.unwrap();
        slow = slow.next.as_mut().unwrap();
    }

    let next = slow.next.as_ref().unwrap();
    slow.next = next.next.clone();
    dummy.next
}

fn main() {
    println!(
        "{:?}",
        remove_nth_from_end(
            Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode { val: 2, next: None }))
            })),
            1
        ),
    );

    println!(
        "{:?}",
        remove_nth_from_end(Some(Box::new(ListNode { val: 1, next: None })), 1),
    );
}
