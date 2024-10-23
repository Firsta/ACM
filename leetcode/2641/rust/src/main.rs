// Definition for a binary tree node.
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

pub fn level_sum(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    fn dfs(v: &mut Vec<i32>, root: &Option<Rc<RefCell<TreeNode>>>, l: usize) {
        match root {
            None => (),
            Some(x) => {
                let x = x.borrow();
                if v.len() < l + 1 {
                    v.push(0);
                }
                v[l] += x.val;
                dfs(v, &x.left, l + 1);
                dfs(v, &x.right, l + 1);
            }
        }
    }
    let mut v = Vec::new();
    dfs(&mut v, &root, 0);
    v
}

pub fn replace_value_in_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    let v = level_sum(&root);
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, delta: i32, l: usize, v: &Vec<i32>) {
        match root {
            None => (),
            Some(x) => {
                let mut x = x.borrow_mut();
                x.val = (v[l] - delta) as i32;

                let next_delta = match x.left.as_ref() {
                    Some(x) => x.borrow().val,
                    None => 0,
                } + match x.right.as_ref() {
                    Some(x) => x.borrow().val,
                    None => 0,
                };

                dfs(&x.left, next_delta, l + 1, v);
                dfs(&x.right, next_delta, l + 1, v);
            }
        }
    }
    let delta = match root.as_ref() {
        Some(x) => x.borrow().val,
        None => 0,
    };
    dfs(&root, delta, 0, &v);
    root
}

fn main() {
    let ret = replace_value_in_tree(Some(Rc::new(RefCell::new(TreeNode {
        val: 5,
        left: Some(Rc::new(RefCell::new(TreeNode {
            val: 4,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 10,
                left: None,
                right: None,
            }))),
        }))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 9,
            left: None,
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 7,
                left: None,
                right: None,
            }))),
        }))),
    }))));
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
        match root {
            None => (),
            Some(x) => {
                let x = x.borrow();
                v.push(x.val);
                dfs(&x.left, v);
                dfs(&x.right, v);
            }
        }
    }
    let mut v = Vec::new();
    dfs(&ret, &mut v);
    assert_eq!(v, vec![0, 0, 7, 7, 0, 11]);
}
