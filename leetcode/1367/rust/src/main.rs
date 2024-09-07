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
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::rc::Rc;
pub fn is_sub_path(head: Option<Box<ListNode>>, root: Option<Rc<RefCell<TreeNode>>>) -> bool {
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
    let mut v = to_vec(&head);
    v.reverse();

    fn find(root: &Option<Rc<RefCell<TreeNode>>>, now: &mut Vec<i32>, goal: &Vec<i32>) -> bool {
        match root {
            None => {
                // println!("{:?} {:?}", now, goal);
                if now.len() < goal.len() {
                    false
                } else {
                    for i in 0..=now.len() - goal.len() {
                        let mut ok = true;
                        for j in 0..goal.len() {
                            if now[i + j] != goal[j] {
                                ok = false;
                                break;
                            }
                        }
                        if ok {
                            return true;
                        }
                    }
                    false
                }
            }
            Some(root) => {
                let root = root.borrow();
                now.push(root.val);
                let ret = find(&root.left, now, goal) || find(&root.right, now, goal);
                now.pop();
                ret
            }
        }
    }

    // println!("{:?}", v);

    let mut now = Vec::new();
    find(&root, &mut now, &v)
}

fn main() {
    assert_eq!(
        is_sub_path(
            Some(Box::new(ListNode {
                val: 4,
                next: Some(Box::new(ListNode {
                    val: 2,
                    next: Some(Box::new(ListNode { val: 8, next: None }))
                }))
            })),
            Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: None,
                    right: Some(Rc::new(RefCell::new(TreeNode {
                        val: 2,
                        left: Some(Rc::new(RefCell::new(TreeNode {
                            val: 1,
                            left: None,
                            right: None
                        }))),
                        right: None
                    })))
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 2,
                        left: Some(Rc::new(RefCell::new(TreeNode {
                            val: 4,
                            left: None,
                            right: None
                        }))),
                        right: Some(Rc::new(RefCell::new(TreeNode {
                            val: 8,
                            left: Some(Rc::new(RefCell::new(TreeNode {
                                val: 1,
                                left: None,
                                right: None
                            }))),
                            right: Some(Rc::new(RefCell::new(TreeNode {
                                val: 3,
                                left: None,
                                right: None
                            })))
                        })))
                    }))),
                    right: None
                })))
            })))
        ),
        true
    );
}
