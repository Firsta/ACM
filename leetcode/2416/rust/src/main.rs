use std::collections::HashMap;

#[derive(Default, Debug)]
struct TrieNode {
    pass_count: i32,
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
            current_node.pass_count += 1;
        }
    }

    pub fn prefix_count(&self, word: &str) -> i32 {
        let mut current_node = &self.root;

        let mut ans = 0;
        for c in word.chars() {
            match current_node.children.get(&c) {
                Some(node) => {
                    if node.pass_count >= 0 {
                        ans += node.pass_count;
                    }
                    current_node = node;
                }
                None => panic!(),
            }
        }

        ans
    }
}

pub fn sum_prefix_scores(words: Vec<String>) -> Vec<i32> {
    let mut trie = Trie::new();
    for w in words.iter() {
        trie.insert(w);
    }

    let mut ans = Vec::new();
    for w in words.into_iter() {
        ans.push(trie.prefix_count(&w));
    }

    ans
}

fn main() {
    assert_eq!(
        sum_prefix_scores(vec![
            "abc".to_string(),
            "ab".to_string(),
            "bc".to_string(),
            "b".to_string()
        ]),
        vec![5, 4, 3, 2]
    );
}
