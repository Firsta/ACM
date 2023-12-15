use std::collections::HashMap;

pub fn dest_city(paths: Vec<Vec<String>>) -> String {
    // println!("{:?}", paths);
    let mut lc = HashMap::new();
    for i in 0..paths.len() {
        match lc.get(&paths[i][0]) {
            Some(c) => {
                let x = *c;
                lc.insert(&paths[i][0], x + 1);
            },
            None => {
                // println!("None");
                lc.insert(&paths[i][0], 1);
                // println!("{:?}", lc);
            }
        }
        if lc.get(&paths[i][1]).is_none() {
            // println!("{:?}", lc);
            lc.insert(&paths[i][1], 0);
        }
        // println!("{:?}", lc);
    }
    for (key, value) in &lc {
        if *value == 0 {
            return key.to_string();
        }
    }
    "".to_string()
}

fn main() {
    println!("{}", dest_city(vec![vec!["London".to_string(),"New York".to_string()], vec!["New York".to_string(),"Lima".to_string()], vec!["Lima".to_string(),"Sao Paulo".to_string()]]));
}
