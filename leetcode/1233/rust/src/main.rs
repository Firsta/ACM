use std::collections::HashMap;

#[derive(Default, Debug)]
struct TrieNode {
    is_end_of_word: bool,
    children: HashMap<String, TrieNode>,
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

    pub fn insert(&mut self, path: &Vec<String>) {
        let mut current_node = &mut self.root;

        for s in path.iter() {
            current_node = current_node.children.entry(s.clone()).or_default();
        }
        current_node.is_end_of_word = true;
    }

    pub fn has_prefix(&self, path: &Vec<String>) -> bool {
        let mut current_node = &self.root;

        for i in 0..path.len() - 1 {
            match current_node.children.get(&path[i]) {
                Some(node) => current_node = node,
                None => return false,
            }
            if current_node.is_end_of_word {
                return true;
            }
        }
        false
    }
}

pub fn remove_subfolders(folder: Vec<String>) -> Vec<String> {
    let folder = folder
        .into_iter()
        .map(|s| s.split("/").map(|x| x.to_string()).collect::<Vec<String>>())
        .collect::<Vec<Vec<String>>>();
    let mut trie = Trie::new();
    for path in folder.iter() {
        trie.insert(path);
    }
    folder
        .into_iter()
        .filter(|x| !trie.has_prefix(&x))
        .map(|x| x.join("/"))
        .collect()
}

fn main() {
    assert_eq!(
        remove_subfolders(vec![
            "/a".to_string(),
            "/a/b".to_string(),
            "/c/d".to_string(),
            "/c/d/e".to_string(),
            "/c/f".to_string(),
        ]),
        vec!["/a".to_string(), "/c/d".to_string(), "/c/f".to_string()]
    );
}
