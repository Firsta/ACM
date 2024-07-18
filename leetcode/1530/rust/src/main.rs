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
pub fn count_pairs(root: Option<Rc<RefCell<TreeNode>>>, distance: i32) -> i32 {
    fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        ok: &mut Vec<Vec<bool>>,
        distance: i32,
        idx: &mut i32,
    ) -> Vec<(i32, i32)> {
        match root {
            None => Vec::new(),
            Some(root) => {
                let root = root.borrow();
                if root.left.is_none() && root.right.is_none() {
                    let ret = vec![(idx.clone(), 0)];
                    *idx += 1;
                    ret
                } else {
                    let mut left_dis: Vec<(i32, i32)> = dfs(&root.left, ok, distance, idx)
                        .into_iter()
                        .map(|x| (x.0, x.1 + 1))
                        .collect();
                    let mut right_dis: Vec<(i32, i32)> = dfs(&root.right, ok, distance, idx)
                        .into_iter()
                        .map(|x| (x.0, x.1 + 1))
                        .collect();
                    for &l in left_dis.iter() {
                        for &r in right_dis.iter() {
                            if l.1 + r.1 <= distance {
                                ok[l.0 as usize][r.0 as usize] = true;
                                ok[r.0 as usize][l.0 as usize] = true;
                            }
                        }
                    }

                    left_dis.append(&mut right_dis);
                    left_dis
                }
            }
        }
    }
    let mut ok = vec![vec![false; 1025]; 1025];
    let mut idx = 0;
    dfs(&root, &mut ok, distance, &mut idx);
    let mut ans = 0;
    for i in 0..1025 {
        for j in i + 1..1025 {
            if ok[i][j] {
                ans += 1;
            }
        }
    }
    ans
}
fn main() {
    assert_eq!(
        count_pairs(
            Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 2,
                    left: None,
                    right: Some(Rc::new(RefCell::new(TreeNode {
                        val: 4,
                        left: None,
                        right: None,
                    }))),
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None,
                }))),
            }))),
            3
        ),
        1
    );
}
