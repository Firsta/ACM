use std::cell::RefCell;
use std::rc::Rc;

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

pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, p: i32, sum: &mut i32) {
        match node {
            None => (),
            Some(node) => {
                let node = node.borrow();
                let p = p * 10 + node.val;
                if node.left.is_none() && node.right.is_none() {
                    *sum += p;
                } else {
                    dfs(&node.left, p, sum);
                    dfs(&node.right, p, sum);
                }
            }
        }
    }

    let p = 0;
    let mut sum = 0;
    dfs(&root, p, &mut sum);
    sum
}

fn main() {
    assert_eq!(
        sum_numbers(Some(Rc::new(RefCell::new(TreeNode {
            val: 4,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 9,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 5,
                    left: None,
                    right: None
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 1,
                    left: None,
                    right: None
                })))
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 0,
                left: None,
                right: None
            })))
        })))),
        1026
    );
}
