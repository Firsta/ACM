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

fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    match root {
        Some(r) => {
            let r = r.borrow();
            let mut v = dfs(&r.left);
            v.push(r.val);
            let mut vv = dfs(&r.right);
            v.append(&mut vv);
            v
        }
        None => Vec::new(),
    }
}

pub fn balance_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    let v = dfs(&root);
    // println!("{:?}", v);

    fn dfs2(v: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if v.is_empty() {
            None
        } else {
            let mid = v.len() / 2;
            let root = Some(Rc::new(RefCell::new(TreeNode {
                val: v[mid],
                left: dfs2(&v[0..mid]),
                right: dfs2(&v[mid + 1..]),
            })));
            root
        }
    }

    dfs2(&v[..])
}

fn main() {
    let r = Some(Rc::new(RefCell::new(TreeNode {
        val: 1,
        left: None,
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 2,
            left: None,
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: None,
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 4,
                    left: None,
                    right: None,
                }))),
            }))),
        }))),
    })));

    let rr = balance_bst(r.clone());
    assert_eq!(dfs(&rr), dfs(&r));

    fn check(r: &Option<Rc<RefCell<TreeNode>>>, ok: &mut bool) -> i32 {
        match r {
            Some(x) => {
                let lh = check(&x.borrow().left, ok);
                let rh = check(&x.borrow().right, ok);
                if (lh - rh).abs() > 1 {
                    *ok = false;
                }
                std::cmp::max(lh, rh) + 1
            }
            None => 0,
        }
    }
    let mut ok = true;
    check(&rr, &mut ok);
    assert!(ok);
}
