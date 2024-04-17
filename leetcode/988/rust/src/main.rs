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
pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, current_str: &mut String, min_str: &mut String) {
        match root {
            Some(root) => {
                let root = root.borrow();
                current_str.push(('a' as u8 + root.val as u8) as char);
                if root.left.is_none() && root.right.is_none() {
                    let t = current_str.clone().chars().rev().collect::<String>();
                    if t.cmp(&min_str).is_lt() {
                        *min_str = t.clone();
                    }
                } else {
                    dfs(&root.left, current_str, min_str);
                    dfs(&root.right, current_str, min_str);
                }
                current_str.pop();
            }
            None => (),
        }
    }

    let mut ans = String::new();
    ans.push(('a' as u8 + 26) as char);
    let mut cur = String::new();
    dfs(&root, &mut cur, &mut ans);

    ans
}

fn main() {
    assert_eq!(
        smallest_from_leaf(Some(Rc::new(RefCell::new(TreeNode {
            val: 0,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: None,
                    right: None
                })))
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: None,
                    right: None
                })))
            })))
        })))),
        "dba".to_string()
    );
}
