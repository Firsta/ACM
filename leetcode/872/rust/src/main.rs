use std::{cell::RefCell, rc::Rc};

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

pub fn leaf_similar(
    root1: Option<Rc<RefCell<TreeNode>>>,
    root2: Option<Rc<RefCell<TreeNode>>>,
) -> bool {
    fn help1(root: &Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
        match root {
            None => (),
            Some(root) => {
                let r = root.borrow();
                if r.left.is_none() && r.right.is_none() {
                    v.push(r.val);
                }
                help1(&r.left, v);
                help1(&r.right, v);
            }
        }
    }

    let mut v1 = Vec::new();
    help1(&root1, &mut v1);
    let mut v2 = Vec::new();
    help1(&root2, &mut v2);

    // println!("{:?}", v1);
    // println!("{:?}", v2);

    if v1.len() != v2.len() {
        return false;
    }

    for (pos, v) in v1.iter().enumerate() {
        if *v != v2[pos] {
            return false;
        }
    }

    true
}

fn main() {
    println!(
        "{}",
        leaf_similar(
            Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None,
            }))),
            Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None,
            })))
        )
    );
}
