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
use std::collections::HashMap;
use std::rc::Rc;
pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, m: &mut HashMap<usize, i32>, level: usize) {
        match root {
            Some(root) => {
                let root = root.borrow();
                m.entry(level)
                    .and_modify(|e| {
                        if *e < root.val {
                            *e = root.val;
                        }
                    })
                    .or_insert(root.val);
                dfs(&root.left, m, level + 1);
                dfs(&root.right, m, level + 1);
            }
            None => (),
        }
    }
    let mut m = HashMap::new();
    dfs(&root, &mut m, 0);
    let mut ans = vec![0; m.len()];
    for i in 0..m.len() {
        ans[i] = m.get(&i).unwrap().clone();
    }
    ans
}

fn main() {
    assert_eq!(
        largest_values(Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 5,
                    left: None,
                    right: None
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None
                })))
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 9,
                    left: None,
                    right: None
                })))
            })))
        })))),
        vec![1, 3, 9]
    );
}
