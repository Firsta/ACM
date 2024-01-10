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
use std::cmp::max;
use std::rc::Rc;

struct StartNode {
    depth: i32,
    dist_to_current_node: i32,
}

pub fn amount_of_time(root: Option<Rc<RefCell<TreeNode>>>, start: i32) -> i32 {
    fn help(
        root: &Option<Rc<RefCell<TreeNode>>>,
        result: &mut i32,
        start_node_val: i32,
    ) -> (Option<StartNode>, i32 /*max depth*/) {
        match root {
            Some(root) => {
                let root = root.borrow();

                let (start_left, left_depth) = help(&root.left, result, start_node_val);
                let (start_right, right_depth) = help(&root.right, result, start_node_val);

                let start_node = if start_left.is_some() {
                    let start = start_left.unwrap();
                    *result = max(
                        *result,
                        max(start.depth, start.dist_to_current_node + right_depth),
                    );

                    Some(StartNode {
                        depth: start.depth,
                        dist_to_current_node: start.dist_to_current_node + 1,
                    })
                } else if start_right.is_some() {
                    let start = start_right.unwrap();
                    *result = max(
                        *result,
                        max(start.depth, start.dist_to_current_node + left_depth),
                    );

                    Some(StartNode {
                        depth: start.depth,
                        dist_to_current_node: start.dist_to_current_node + 1,
                    })
                } else if root.val == start_node_val {
                    let max_depth = max(left_depth, right_depth);
                    *result = max(*result, max_depth);

                    Some(StartNode {
                        depth: max_depth,
                        dist_to_current_node: 1,
                    })
                } else {
                    None
                };

                let max_depth = std::cmp::max(left_depth, right_depth) + 1;

                (start_node, max_depth)
            }
            None => (None, 0),
        }
    }

    let mut result = -1;
    help(&root, &mut result, start);
    result
}

//   1
//  5       3
//   4     10 6
//  9 2

fn main() {
    println!(
        "{}",
        amount_of_time(
            Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None
            }))),
            1
        )
    );
}
