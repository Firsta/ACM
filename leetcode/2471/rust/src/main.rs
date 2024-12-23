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
pub fn minimum_operations(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let mut q = Vec::new();
    q.push(root.unwrap().clone());
    let mut ans = 0;
    while !q.is_empty() {
        let mut v: Vec<i32> = q.iter().map(|x| x.borrow().val).collect();
        let mut sorted = v.clone();
        let mut loc = std::collections::HashMap::new();
        for i in 0..v.len() {
            loc.insert(v[i], i);
        }
        sorted.sort();
        for i in 0..v.len() {
            if v[i] != sorted[i] {
                let t = v[i];
                let l = loc.get(&sorted[i]).unwrap().clone();
                v[i] = v[l];
                loc.insert(v[l], i);
                v[l] = t;
                loc.insert(t, l);
                ans += 1;
            }
        }

        let mut new_q = Vec::new();
        for q in q {
            let qq = q.borrow();
            if let Some(q) = &qq.left {
                new_q.push(q.clone());
            }
            if let Some(q) = &qq.right {
                new_q.push(q.clone());
            }
        }
        q = new_q;
    }
    ans
}
fn main() {
    assert_eq!(
        minimum_operations(Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 4,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 7,
                    left: None,
                    right: None,
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 6,
                    left: None,
                    right: None,
                }))),
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 8,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 9,
                        left: None,
                        right: None,
                    }))),
                    right: None,
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 5,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 10,
                        left: None,
                        right: None,
                    }))),
                    right: None,
                }))),
            }))),
        })))),
        3
    );
}
