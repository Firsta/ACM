use std::collections::HashMap;

#[derive(Default, Debug)]
struct TrieNode {
    is_end_of_word: bool,
    children: HashMap<char, TrieNode>,
}

#[derive(Default, Debug)]
pub struct Trie {
    root: TrieNode,
}

impl Trie {
    pub fn new() -> Self {
        Trie {
            root: TrieNode::default(),
        }
    }

    pub fn insert(&mut self, word: &str) {
        let mut current_node = &mut self.root;

        for c in word.chars() {
            current_node = current_node.children.entry(c).or_default();
        }
        current_node.is_end_of_word = true;
    }

    pub fn common_prefix(&self, word: &str) -> i32 {
        let mut current_node = &self.root;

        let mut ans = 0;
        for c in word.chars() {
            match current_node.children.get(&c) {
                Some(node) => {
                    current_node = node;
                    ans += 1;
                }
                None => return ans,
            }
        }

        ans
    }
}

pub fn longest_common_prefix(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {
    let arr1: Vec<String> = arr1.into_iter().map(|x| x.to_string()).collect();
    let arr2: Vec<String> = arr2.into_iter().map(|x| x.to_string()).collect();

    let mut trie = Trie::new();
    for a in arr1.into_iter() {
        trie.insert(&a);
    }

    let mut ans = 0;
    for a in arr2.into_iter() {
        ans = std::cmp::max(ans, trie.common_prefix(&a));
    }

    ans
}

fn main() {
    assert_eq!(longest_common_prefix(vec![1, 10, 100], vec![1000]), 3);
    assert_eq!(longest_common_prefix(vec![1, 2, 3], vec![4, 4, 4]), 0);
}
