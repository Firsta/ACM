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
      right: None
    }
  }
}

pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    fn help(root: &Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
        match root {
            Some(root) => {
                let b = root.borrow();
                if b.left.is_some() {
                    help(&b.left, v);
                }
                v.push(b.val);
                if b.right.is_some() {
                    help(&b.right, v);
                }
            },
            None => ()
        }
    }
    let mut v = Vec::new();
    help(&root, &mut v);
    v
}

fn main() {
    let tree = Some(Rc::new(RefCell::new(TreeNode {val: 1, left: None, right: None})));
    println!("{:?}", inorder_traversal(tree));
}
