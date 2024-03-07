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

pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut len = 0;
    let mut x = head.clone();
    while x.is_some() {
        len += 1;
        x = x.unwrap().next.clone();
    }

    len /= 2;
    x = head.clone();
    while len > 0 {
        x = x.unwrap().next.clone();
        len -= 1;
    }
    x
}

fn main() {
    println!(
        "{:?}",
        middle_node(Some(Box::new(ListNode { val: 1, next: None })))
    );
}
