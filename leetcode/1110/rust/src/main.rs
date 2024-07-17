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
pub fn del_nodes(
    root: Option<Rc<RefCell<TreeNode>>>,
    to_delete: Vec<i32>,
) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
    use std::collections::HashSet;
    fn dfs(
        root: Option<Rc<RefCell<TreeNode>>>,
        last: Option<(Rc<RefCell<TreeNode>>, bool)>,
        last_deleted: bool,
        delete: &HashSet<i32>,
        ans: &mut Vec<Option<Rc<RefCell<TreeNode>>>>,
    ) {
        match root {
            Some(rr) => {
                let left_clone = rr.borrow().left.clone();
                let right_clone = rr.borrow().right.clone();
                let val = rr.borrow().val.clone();

                let nld = if delete.contains(&val) {
                    if let Some((last, left)) = last {
                        match left {
                            true => {
                                last.borrow_mut().left = None;
                            }
                            false => {
                                last.borrow_mut().right = None;
                            }
                        }
                    }
                    true
                } else {
                    if last_deleted {
                        ans.push(Some(rr.clone()));
                    }
                    false
                };

                dfs(left_clone, Some((rr.clone(), true)), nld, delete, ans);
                dfs(right_clone, Some((rr.clone(), false)), nld, delete, ans);
            }
            None => (),
        }
    }

    let delete = HashSet::from_iter(to_delete.into_iter());
    let mut ans = Vec::new();
    dfs(root.clone(), None, true, &delete, &mut ans);

    ans
}

fn main() {
    let x = del_nodes(
        Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: None,
                    right: None,
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 5,
                    left: None,
                    right: None,
                }))),
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 6,
                    left: None,
                    right: None,
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 7,
                    left: None,
                    right: None,
                }))),
            }))),
        }))),
        vec![3, 5],
    );
    assert_eq!(x.len(), 3);
}
