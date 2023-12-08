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

use std::rc::Rc;
use std::cell::RefCell;
pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
    println!("{:?}", root);
    fn help(root: &Option<Rc<RefCell<TreeNode>>>) -> String {
        match root {
            Some(node) => {
                let b = node.borrow();

                let mut result = b.val.to_string();

                if b.left.is_some() {
                    result.push_str(&"(".to_string());
                    result.push_str(&help(&b.left));
                    result.push_str(&")".to_string());
                } else if b.right.is_some() {
                    result.push_str(&"()".to_string());
                }

                if b.right.is_some() {
                    result.push_str(&"(".to_string());
                    result.push_str(&help(&b.right));
                    result.push_str(&")".to_string());
                }

                result
            },
            None => "".to_string()
        }
    }
    
    help(&root)
}

fn main() {
    let tree = Some(Rc::new(RefCell::new(TreeNode {val: 1, left: None, right: None})));
    println!("{}", tree2str(tree));
}
