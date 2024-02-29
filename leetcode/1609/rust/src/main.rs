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
use std::collections::VecDeque;
use std::rc::Rc;

pub fn is_even_odd_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
    let root_val = root.as_ref().unwrap().borrow().val;
    if root_val % 2 == 0 {
        false
    } else {
        let mut qs = [VecDeque::new(), VecDeque::new()];
        let mut turn = 0usize;
        qs[turn].push_back(root.unwrap().clone());

        while !qs[turn].is_empty() {
            while !qs[turn].is_empty() {
                let n = qs[turn].pop_front().unwrap();
                if n.borrow().left.is_some() {
                    qs[1 - turn].push_back(n.borrow().left.clone().unwrap());
                }
                if n.borrow().right.is_some() {
                    qs[1 - turn].push_back(n.borrow().right.clone().unwrap());
                }
            }

            let mut last = None;
            // println!("{:?}", qs[1 - turn]);
            for v in qs[1 - turn].iter() {
                let val = v.borrow().val;
                if val % 2 != turn as i32 {
                    return false;
                }
                if let Some(last) = last {
                    if turn == 0 {
                        if val >= last {
                            return false;
                        }
                    } else {
                        if val <= last {
                            return false;
                        }
                    }
                }
                last = Some(val);
            }

            turn = 1 - turn;
        }

        true
    }
}

fn main() {
    assert!(!is_even_odd_tree(Some(Rc::new(RefCell::new(TreeNode {
        val: 5,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 9,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 4,
                left: None,
                right: None,
            }))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 7,
                left: None,
                right: None,
            }))),
            right: None,
        }))),
    })))))
}
