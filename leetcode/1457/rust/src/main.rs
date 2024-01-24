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

pub fn pseudo_palindromic_paths(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let mut c = vec![0; 9];
    fn help(root: &Option<Rc<RefCell<TreeNode>>>, c: &mut Vec<u32>, ret: &mut i32) {
        match root {
            None => (),
            Some(r) => {
                let r = r.borrow();
                c[r.val as usize - 1] += 1;
                if r.left.is_none() && r.right.is_none() {
                    let mut odd = 0;
                    for i in c.iter() {
                        if i % 2 == 1 {
                            odd += 1;
                        }
                    }
                    if odd <= 1 {
                        *ret += 1;
                    }
                }
                help(&r.left, c, ret);
                help(&r.right, c, ret);
                c[r.val as usize - 1] -= 1;
            }
        }
    }
    let mut ret = 0;
    help(&root, &mut c, &mut ret);
    ret
}

fn main() {
    println!(
        "{}",
        pseudo_palindromic_paths(Some(Rc::new(RefCell::new(TreeNode {
            val: 9,
            left: None,
            right: None
        }))))
    );
}
