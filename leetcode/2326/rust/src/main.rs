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

pub fn spiral_matrix(m: i32, n: i32, head: Option<Box<ListNode>>) -> Vec<Vec<i32>> {
    fn foo(head: Option<Box<ListNode>>, ans: &mut Vec<Vec<i32>>, dir: i32, cur: (i32, i32)) {
        match head {
            None => (),
            Some(head) => {
                ans[cur.0 as usize][cur.1 as usize] = head.val;

                let next = match dir {
                    0 => (cur.0, cur.1 + 1),
                    1 => (cur.0 + 1, cur.1),
                    2 => (cur.0, cur.1 - 1),
                    3 => (cur.0 - 1, cur.1),
                    _ => panic!(),
                };

                let m = ans.len();
                let n = ans[0].len();
                if next.0 < 0
                    || next.0 >= m as i32
                    || next.1 < 0
                    || next.1 >= n as i32
                    || ans[next.0 as usize][next.1 as usize] != -1
                {
                    let dir = (dir + 1) % 4;
                    let next = match dir {
                        0 => (cur.0, cur.1 + 1),
                        1 => (cur.0 + 1, cur.1),
                        2 => (cur.0, cur.1 - 1),
                        3 => (cur.0 - 1, cur.1),
                        _ => panic!(),
                    };
                    foo(head.next, ans, dir, next);
                } else {
                    foo(head.next, ans, dir, next);
                }
            }
        }
    }

    let mut ans = vec![vec![-1; n as usize]; m as usize];
    foo(head, &mut ans, 0, (0, 0));
    ans
}
fn main() {
    assert_eq!(
        spiral_matrix(
            3,
            5,
            Some(Box::new(ListNode {
                val: 3,
                next: Some(Box::new(ListNode {
                    val: 0,
                    next: Some(Box::new(ListNode {
                        val: 2,
                        next: Some(Box::new(ListNode {
                            val: 6,
                            next: Some(Box::new(ListNode {
                                val: 8,
                                next: Some(Box::new(ListNode {
                                    val: 1,
                                    next: Some(Box::new(ListNode {
                                        val: 7,
                                        next: Some(Box::new(ListNode {
                                            val: 9,
                                            next: Some(Box::new(ListNode {
                                                val: 4,
                                                next: Some(Box::new(ListNode {
                                                    val: 2,
                                                    next: Some(Box::new(ListNode {
                                                        val: 5,
                                                        next: Some(Box::new(ListNode {
                                                            val: 5,
                                                            next: Some(Box::new(ListNode {
                                                                val: 0,
                                                                next: None
                                                            }))
                                                        }))
                                                    }))
                                                }))
                                            }))
                                        }))
                                    }))
                                }))
                            }))
                        }))
                    }))
                }))
            }))
        ),
        vec![
            vec![3, 0, 2, 6, 8],
            vec![5, 0, -1, -1, 1],
            vec![5, 2, 4, 9, 7]
        ]
    );
    assert_eq!(
        spiral_matrix(
            1,
            4,
            Some(Box::new(ListNode {
                val: 0,
                next: Some(Box::new(ListNode {
                    val: 1,
                    next: Some(Box::new(ListNode { val: 2, next: None }))
                }))
            }))
        ),
        vec![vec![0, 1, 2, -1]]
    );
}
