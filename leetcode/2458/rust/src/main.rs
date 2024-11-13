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

pub fn tree_queries_0(root: Option<Rc<RefCell<TreeNode>>>, queries: Vec<i32>) -> Vec<i32> {
    fn dfs_height(
        root: &Option<Rc<RefCell<TreeNode>>>,
        left_heights: &mut HashMap<i32, i32>,
        right_heights: &mut HashMap<i32, i32>,
    ) -> i32 {
        match root {
            None => -1,
            Some(root) => {
                let root = root.borrow();
                let l = dfs_height(&root.left, left_heights, right_heights);
                let r = dfs_height(&root.right, left_heights, right_heights);
                left_heights.insert(root.val, l + 1);
                right_heights.insert(root.val, r + 1);
                std::cmp::max(l + 1, r + 1)
            }
        }
    }

    let mut left_heights = HashMap::new();
    let mut right_heights = HashMap::new();
    let h = dfs_height(&root, &mut left_heights, &mut right_heights);

    // println!("{:?}", left_heights);
    // println!("{:?}", right_heights);

    fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        left_heights: &HashMap<i32, i32>,
        right_heights: &HashMap<i32, i32>,
    ) -> HashMap<i32, i32> {
        match root {
            None => HashMap::new(),
            Some(root) => {
                let root = root.borrow();
                let l = dfs(&root.left, left_heights, right_heights);
                let r = dfs(&root.right, left_heights, right_heights);
                let mut ret = HashMap::new();
                let left_height = left_heights.get(&root.val).unwrap().clone();
                let right_height = right_heights.get(&root.val).unwrap().clone();
                if left_height == right_height {
                    return ret;
                } else if left_height > right_height {
                    ret.insert(root.left.as_ref().unwrap().borrow().val, right_height);
                    for (k, v) in l.iter() {
                        ret.insert(*k, std::cmp::max(v + 1, right_height));
                    }
                } else {
                    ret.insert(root.right.as_ref().unwrap().borrow().val, left_height);
                    for (k, v) in r.iter() {
                        ret.insert(*k, std::cmp::max(v + 1, left_height));
                    }
                }
                ret
            }
        }
    }

    let m = dfs(&root, &left_heights, &right_heights);

    queries
        .into_iter()
        .map(|x| *m.get(&x).unwrap_or_else(|| &h))
        .collect()
}

pub fn tree_queries(root: Option<Rc<RefCell<TreeNode>>>, queries: Vec<i32>) -> Vec<i32> {
    fn dfsl(
        root: &Option<Rc<RefCell<TreeNode>>>,
        current_h: i32,
        max_h: &mut i32,
        m: &mut HashMap<i32, i32>,
    ) {
        match root {
            None => (),
            Some(root) => {
                let root = root.borrow();
                m.insert(root.val, *max_h);
                *max_h = std::cmp::max(*max_h, current_h);
                dfsl(&root.left, current_h + 1, max_h, m);
                dfsl(&root.right, current_h + 1, max_h, m);
            }
        }
    }

    fn dfsr(
        root: &Option<Rc<RefCell<TreeNode>>>,
        current_h: i32,
        max_h: &mut i32,
        m: &mut HashMap<i32, i32>,
    ) {
        match root {
            None => (),
            Some(root) => {
                let root = root.borrow();
                m.insert(root.val, *max_h);
                *max_h = std::cmp::max(*max_h, current_h);
                dfsr(&root.right, current_h + 1, max_h, m);
                dfsr(&root.left, current_h + 1, max_h, m);
            }
        }
    }

    let mut max_h = 0;
    let mut l = HashMap::new();
    dfsl(&root, 0, &mut max_h, &mut l);

    max_h = 0;
    let mut r = HashMap::new();
    dfsr(&root, 0, &mut max_h, &mut r);

    queries
        .into_iter()
        .map(|x| *std::cmp::max(l.get(&x).unwrap(), r.get(&x).unwrap()))
        .collect()
}

fn main() {
    assert_eq!(
        tree_queries(
            Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 2,
                        left: None,
                        right: None
                    }))),
                    right: None
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 6,
                        left: None,
                        right: None
                    }))),
                    right: Some(Rc::new(RefCell::new(TreeNode {
                        val: 5,
                        left: None,
                        right: Some(Rc::new(RefCell::new(TreeNode {
                            val: 7,
                            left: None,
                            right: None
                        })))
                    })))
                })))
            }))),
            vec![4],
        ),
        vec![2]
    );
}
