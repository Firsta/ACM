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
pub fn reverse_odd_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    fn dfs(
        level: i32,
        left: &Option<Rc<RefCell<TreeNode>>>,
        right: &Option<Rc<RefCell<TreeNode>>>,
    ) {
        if let Some(left) = left {
            let mut left = left.borrow_mut();
            let mut right = right.as_ref().unwrap().borrow_mut();
            if level % 2 == 1 {
                let t = left.val;
                left.val = right.val;
                right.val = t;
            }

            dfs(level + 1, &left.left, &right.right);
            dfs(level + 1, &left.right, &right.left);
        }
    }
    fn solve(root: &Option<Rc<RefCell<TreeNode>>>) {
        if let Some(root) = root {
            let root = root.borrow();
            dfs(1, &root.left, &root.right);
        }
    }
    solve(&root);
    root
}

fn main() {
    println!("Hello world!");
}
