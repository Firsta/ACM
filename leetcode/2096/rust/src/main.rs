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
pub fn get_directions(
    root: Option<Rc<RefCell<TreeNode>>>,
    start_value: i32,
    dest_value: i32,
) -> String {
    use std::collections::HashMap;

    fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        parent: &mut HashMap<i32, (i32, char)>,
        last: Option<(i32, char)>,
        depth: &mut HashMap<i32, i32>,
        d: i32,
    ) {
        match root {
            Some(root) => {
                let root = root.borrow();

                depth.insert(root.val, d);
                if let Some(last) = last {
                    parent.insert(root.val, last);
                }

                dfs(&root.left, parent, Some((root.val, 'L')), depth, d + 1);
                dfs(&root.right, parent, Some((root.val, 'R')), depth, d + 1);
            }
            None => (),
        }
    }

    let mut depth = HashMap::new();
    let mut parent = HashMap::new();
    dfs(&root, &mut parent, None, &mut depth, 0);

    let mut s_st = Vec::new();
    let mut d_st = Vec::new();

    let mut s = start_value;
    let mut d = dest_value;

    let ss = depth.get(&s).unwrap().clone();
    let ds = depth.get(&d).unwrap().clone();

    if ds > ss {
        for _ in 0..ds - ss {
            let p = parent.get(&d).unwrap().clone();
            d_st.push(p.1);
            d = p.0;
        }
    } else {
        for _ in 0..ss - ds {
            let p = parent.get(&s).unwrap().clone();
            s_st.push(p.1);
            s = p.0;
        }
    }

    while s != d {
        let p = parent.get(&s).unwrap().clone();
        s_st.push(p.1);
        s = p.0;

        let p = parent.get(&d).unwrap().clone();
        d_st.push(p.1);
        d = p.0;
    }

    let mut ans = vec!['U'; s_st.len()];
    for i in (0..d_st.len()).rev() {
        ans.push(d_st[i]);
    }

    ans.into_iter().collect()
}
fn main() {
    assert_eq!(
        get_directions(
            Some(Rc::new(RefCell::new(TreeNode {
                val: 5,
                left: Some(Rc::new(RefCell::new(TreeNode {
                    val: 1,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 3,
                        left: None,
                        right: None,
                    }))),
                    right: None,
                }))),
                right: Some(Rc::new(RefCell::new(TreeNode {
                    val: 2,
                    left: Some(Rc::new(RefCell::new(TreeNode {
                        val: 6,
                        left: None,
                        right: None,
                    }))),
                    right: Some(Rc::new(RefCell::new(TreeNode {
                        val: 4,
                        left: None,
                        right: None,
                    }))),
                }))),
            }))),
            3,
            6,
        ),
        "UURL".to_string()
    );
}
