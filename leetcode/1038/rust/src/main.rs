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

pub fn bst_to_gst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    fn dfs(root: &mut Option<Rc<RefCell<TreeNode>>>, add: i32) -> i32 {
        match root {
            Some(root) => {
                let mut root = root.borrow_mut();
                let t = root.val.clone();
                let right_sum = dfs(&mut root.right, add);
                root.val += right_sum + add;
                let left_sum = dfs(&mut root.left, right_sum + t + add);

                left_sum + right_sum + t
            }
            None => 0,
        }
    }

    let mut root = root;
    dfs(&mut root, 0);
    root
}

fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    match root {
        Some(root) => {
            let root = root.borrow();
            let mut v = dfs(&root.left);
            v.push(root.val);
            let mut rv = dfs(&root.right);
            v.append(&mut rv);
            v
        }
        None => Vec::new(),
    }
}

fn main() {
    let t = bst_to_gst(Some(Rc::new(RefCell::new(TreeNode {
        val: 4,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 0,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None,
                }))),
            }))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 6,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 5,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 7,
                left: None,
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 8,
                    left: None,
                    right: None,
                }))),
            }))),
        }))),
    }))));

    // println!("{:?}", dfs(&t));
    assert_eq!(dfs(&t), vec![36, 36, 35, 33, 30, 26, 21, 15, 8]);
}
