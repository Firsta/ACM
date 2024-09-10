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

pub fn gcd(mut n: i32, mut m: i32) -> i32 {
    assert!(n != 0 && m != 0);
    while m != 0 {
        if m < n {
            std::mem::swap(&mut m, &mut n);
        }
        m %= n;
    }
    n
}

pub fn insert_greatest_common_divisors(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    match head {
        None => None,
        Some(head) => match head.next {
            None => Some(head),
            Some(next) => Some(Box::new(ListNode {
                val: head.val,
                next: Some(Box::new(ListNode {
                    val: gcd(head.val, next.val),
                    next: insert_greatest_common_divisors(Some(next)),
                })),
            })),
        },
    }
}

fn main() {
    fn to_vec(head: Option<Box<ListNode>>) -> Vec<i32> {
        match head {
            None => Vec::new(),
            Some(head) => {
                let mut v = to_vec(head.next);
                v.push(head.val);
                v
            }
        }
    }
    assert_eq!(
        to_vec(insert_greatest_common_divisors(Some(Box::new(ListNode {
            val: 18,
            next: Some(Box::new(ListNode {
                val: 6,
                next: Some(Box::new(ListNode {
                    val: 10,
                    next: Some(Box::new(ListNode { val: 3, next: None }))
                }))
            }))
        })))),
        vec![3, 1, 10, 2, 6, 6, 18]
    );
}
