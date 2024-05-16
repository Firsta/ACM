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
pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(root) => {
                let root = root.borrow();
                if root.left.is_none() && root.right.is_none() {
                    root.val == 1
                } else {
                    let l = dfs(&root.left);
                    let r = dfs(&root.right);
                    match root.val {
                        2 => l || r,
                        3 => l && r,
                        _ => panic!(),
                    }
                }
            }
            None => panic!(),
        }
    }

    dfs(&root)
}
fn main() {
    assert_eq!(
        evaluate_tree(Some(Rc::new(RefCell::new(TreeNode {
            val: 2,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 0,
                    left: None,
                    right: None
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 1,
                    left: None,
                    right: None
                })))
            })))
        })))),
        true
    );
}
