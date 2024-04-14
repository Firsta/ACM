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

pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, left: bool, sum: &mut i32) {
        match node {
            None => (),
            Some(node) => {
                let node = node.borrow();
                if node.left.is_none() && node.right.is_none() && left {
                    *sum += node.val;
                }
                dfs(&node.left, true, sum);
                dfs(&node.right, false, sum);
            }
        }
    }

    let mut sum = 0;
    dfs(&root, false, &mut sum);
    sum
}
fn main() {
    assert_eq!(
        sum_of_left_leaves(Some(Rc::new(RefCell::new(TreeNode {
            val: 3,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 9,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 20,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 15,
                    left: None,
                    right: None,
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 7,
                    left: None,
                    right: None,
                }))),
            }))),
        })))),
        24
    );
}
