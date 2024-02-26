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

pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
    fn same(p: &Option<Rc<RefCell<TreeNode>>>, q: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if p.is_none() && q.is_none() {
            true
        } else if p.is_some() && q.is_some() {
            let p = p.as_ref().unwrap().borrow();
            let q = q.as_ref().unwrap().borrow();
            if p.val != q.val {
                false
            } else {
                same(&p.left, &q.left) && same(&p.right, &q.right)
            }
        } else {
            false
        }
    }
    same(&p, &q)
}

fn main() {
    assert!(is_same_tree(
        Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: None
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: None
            }))),
        }))),
        Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: None
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: None
            }))),
        })))
    ));
}
