use std::cell::RefCell;
use std::rc::Rc;

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

pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
    fn help(root: &Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        match root {
            None => 0,
            Some(r) => {
                if r.borrow().val < low {
                    help(&r.borrow().right, low, high)
                } else if r.borrow().val > high {
                    help(&r.borrow().left, low, high)
                } else {
                    r.borrow().val
                        + help(&r.borrow().right, low, high)
                        + help(&r.borrow().left, low, high)
                }
            }
        }
    }
    help(&root, low, high)
}

fn main() {
    let r = Some(Rc::new(RefCell::new(TreeNode {
        val: 1,
        left: None,
        right: None,
    })));
    println!("{}", range_sum_bst(r, 0, 3));
}
