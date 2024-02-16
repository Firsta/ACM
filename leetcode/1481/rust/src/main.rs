use std::collections::HashMap;

pub fn find_least_num_of_unique_ints(arr: Vec<i32>, k: i32) -> i32 {
    let mut m = HashMap::with_capacity(arr.len());
    for i in arr.iter() {
        m.entry(i).and_modify(|x| *x += 1).or_insert(1);
    }

    let mut v: Vec<(&i32, i32)> = m.into_iter().collect();

    v.sort_by(|a, b| b.1.cmp(&a.1));

    // println!("{:?}", v);
    let mut result = v.len() as i32;
    let mut k = k;
    while result > 0 && k >= v[result as usize - 1].1 {
        // println!("{} {}", k, result);
        k -= v[result as usize - 1].1;
        result -= 1;
    }

    result
}

fn main() {
    println!(
        "{}",
        find_least_num_of_unique_ints(vec![4, 3, 1, 1, 3, 3, 2], 3)
    );
}
