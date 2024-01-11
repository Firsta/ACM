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
use std::cmp::{max, min};
use std::rc::Rc;

pub fn max_ancestor_diff(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    fn help(
        root: &Option<Rc<RefCell<TreeNode>>>,
        result: &mut i32,
    ) -> Option<(i32 /*max*/, i32 /*min*/)> {
        match root {
            Some(root) => {
                let root = root.borrow();
                let l = help(&root.left, result);
                let r = help(&root.right, result);
                if l.is_none() && r.is_none() {
                    Some((root.val, root.val))
                } else {
                    let subtree_max = max(l.unwrap_or((-1, 100001)).0, r.unwrap_or((-1, 100001)).0);
                    let subtree_min = min(l.unwrap_or((-1, 100001)).1, r.unwrap_or((-1, 100001)).1);
                    *result = max(
                        *result,
                        max(
                            (root.val - subtree_max).abs(),
                            (root.val - subtree_min).abs(),
                        ),
                    );
                    Some((max(subtree_max, root.val), min(subtree_min, root.val)))
                }
            }
            None => None,
        }
    }

    let mut result = -1;
    help(&root, &mut result);
    result
}

fn main() {
    println!(
        "{}",
        max_ancestor_diff(Some(Rc::new(RefCell::new(TreeNode {
            val: 0,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None
            }))),
            right: None
        }))))
    );
}
