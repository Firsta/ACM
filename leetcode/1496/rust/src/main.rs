use std::collections::HashMap;
use std::collections::HashSet;

pub fn is_path_crossing(path: String) -> bool {
    let mut x = 0;
    let mut y = 0;
    let mut passed = HashMap::new();
    if passed.get(&x).is_none() {
        passed.insert(x, HashSet::new());
    }
    passed.get_mut(&x).unwrap().insert(y);
    for c in path.chars() {
        match c {
            'N' => {
                y += 1;
            },
            'S' => {
                y -= 1;
            },
            'E' => {
                x += 1;
            },
            'W' => {
                x -= 1;
            },
            _ => (),
        }
        
        match passed.get(&x) {
            None => {
                passed.insert(x, HashSet::new());
            },
            Some(s) => {
                if s.contains(&y) {
                    return true;
                }
            },
        }
        passed.get_mut(&x).unwrap().insert(y);
    }
    false
}

fn main() {
    println!("{}", is_path_crossing("NES".to_string()));
}
