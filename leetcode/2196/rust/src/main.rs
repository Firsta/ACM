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
pub fn create_binary_tree(descriptions: Vec<Vec<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
    use std::collections::HashMap;

    let mut nodes = HashMap::new();
    let mut parents = HashMap::new();

    let mut root = descriptions[0][0];
    for d in descriptions.into_iter() {
        if !nodes.contains_key(&d[0]) {
            nodes.insert(
                d[0],
                Rc::new(RefCell::new(TreeNode {
                    val: d[0],
                    left: None,
                    right: None,
                })),
            );
        }
        if !nodes.contains_key(&d[1]) {
            nodes.insert(
                d[1],
                Rc::new(RefCell::new(TreeNode {
                    val: d[1],
                    left: None,
                    right: None,
                })),
            );
        }
        if d[2] == 1 {
            nodes.get_mut(&d[0]).unwrap().borrow_mut().left =
                Some(nodes.get(&d[1]).unwrap().clone());
        } else {
            nodes.get_mut(&d[0]).unwrap().borrow_mut().right =
                Some(nodes.get(&d[1]).unwrap().clone());
        }

        parents.insert(d[1], d[0]);
    }

    while let Some(nr) = parents.get(&root) {
        root = *nr;
    }

    Some(nodes.get(&root).unwrap().clone())
}

fn main() {
    let t = create_binary_tree(vec![vec![1, 2, 1], vec![2, 3, 0], vec![3, 4, 1]]);

    fn dfs(r: &Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        match r {
            Some(r) => {
                let r = r.borrow();
                let mut v = dfs(&r.left);
                v.push(r.val);
                v.append(&mut dfs(&r.right));
                v
            }
            None => Vec::new(),
        }
    }

    assert_eq!(dfs(&t), [2, 4, 3, 1]);
}
