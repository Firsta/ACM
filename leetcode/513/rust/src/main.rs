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

pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        depth: usize,
        last_depth: &mut usize,
        result: &mut i32,
    ) {
        match root {
            None => (),
            Some(r) => {
                let r = r.borrow();
                if depth > *last_depth {
                    *last_depth = depth;
                    *result = r.val;
                }
                dfs(&r.left, depth + 1, last_depth, result);
                dfs(&r.right, depth + 1, last_depth, result);
            }
        }
    }

    let mut last_depth = 0;
    let mut result = 0;
    dfs(&root, 1, &mut last_depth, &mut result);
    result
}

fn main() {
    assert_eq!(
        find_bottom_left_value(Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: None,
            right: None
        })))),
        1
    );
    assert_eq!(
        find_bottom_left_value(Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: None
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: None,
                right: None
            })))
        })))),
        2
    );
}
