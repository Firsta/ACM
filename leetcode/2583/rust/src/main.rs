use std::{cell::RefCell, rc::Rc};

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

pub fn kth_largest_level_sum(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i64 {
    fn dfs(v: &mut Vec<i64>, root: &Option<Rc<RefCell<TreeNode>>>, l: usize) {
        match root {
            None => (),
            Some(x) => {
                let x = x.borrow();
                if v.len() < l + 1 {
                    v.push(0);
                }
                v[l] += x.val as i64;
                dfs(v, &x.left, l + 1);
                dfs(v, &x.right, l + 1);
            }
        }
    }
    let mut v = Vec::new();
    dfs(&mut v, &root, 0);
    // println!("{:?}", v);
    v.sort_by(|a, b| b.cmp(&a));
    if v.len() < k as usize {
        -1
    } else {
        v[k as usize - 1]
    }
}

fn main() {
    assert_eq!(
        kth_largest_level_sum(
            Some(Rc::new(RefCell::new(TreeNode {
                val: 5,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 8,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 2,
                        left: Some(Rc::new(RefCell::new(TreeNode {
                            val: 4,
                            left: None,
                            right: None,
                        }))),
                        right: Some(Rc::new(RefCell::new(TreeNode {
                            val: 6,
                            left: None,
                            right: None,
                        }))),
                    }))),
                    right: Some(Rc::new(RefCell::new(TreeNode {
                        val: 1,
                        left: None,
                        right: None,
                    }))),
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 9,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 3,
                        left: None,
                        right: None,
                    }))),
                    right: Some(Rc::new(RefCell::new(TreeNode {
                        val: 7,
                        left: None,
                        right: None,
                    }))),
                }))),
            }))),
            2
        ),
        13
    );
}
