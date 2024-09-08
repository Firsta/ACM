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

fn to_vec(head: &Option<Box<ListNode>>) -> Vec<i32> {
    match head {
        None => Vec::new(),
        Some(head) => {
            let mut t = to_vec(&head.next);
            t.push(head.val);
            t
        }
    }
}

pub fn split_list_to_parts(head: Option<Box<ListNode>>, k: i32) -> Vec<Option<Box<ListNode>>> {
    let mut v = to_vec(&head);
    v.reverse();
    let k = k as usize;
    let l = v.len() / k;
    let mut r = v.len() % k;
    let mut i = 0;
    let mut ans = Vec::new();
    while i < v.len() {
        let mut last = None;
        let len = l + if r > 0 {
            r -= 1;
            1
        } else {
            0
        };
        for j in (i..i + len).rev() {
            let t = Some(Box::new(ListNode {
                val: v[j],
                next: last,
            }));
            last = t;
        }
        ans.push(last);
        i += len;
    }

    for _ in 0..k - ans.len() {
        ans.push(None);
    }

    ans
}

fn main() {
    assert_eq!(
        split_list_to_parts(
            Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode {
                    val: 2,
                    next: Some(Box::new(ListNode { val: 3, next: None })),
                })),
            })),
            5,
        )
        .iter()
        .map(|x| {
            let mut t = to_vec(x);
            t.reverse();
            t
        })
        .collect::<Vec<Vec<i32>>>(),
        vec![vec![1], vec![2], vec![3], vec![], vec![]]
    );

    assert_eq!(
        split_list_to_parts(
            Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode {
                    val: 2,
                    next: Some(Box::new(ListNode {
                        val: 3,
                        next: Some(Box::new(ListNode {
                            val: 4,
                            next: Some(Box::new(ListNode {
                                val: 5,
                                next: Some(Box::new(ListNode {
                                    val: 6,
                                    next: Some(Box::new(ListNode {
                                        val: 7,
                                        next: Some(Box::new(ListNode {
                                            val: 8,
                                            next: Some(Box::new(ListNode {
                                                val: 9,
                                                next: Some(Box::new(ListNode {
                                                    val: 10,
                                                    next: None
                                                }))
                                            }))
                                        }))
                                    }))
                                }))
                            }))
                        }))
                    })),
                })),
            })),
            3,
        )
        .iter()
        .map(|x| {
            let mut t = to_vec(x);
            t.reverse();
            t
        })
        .collect::<Vec<Vec<i32>>>(),
        vec![vec![1, 2, 3, 4], vec![5, 6, 7], vec![8, 9, 10]]
    );
}
