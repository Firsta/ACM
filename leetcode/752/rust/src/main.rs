use std::collections::{HashSet, VecDeque};

pub fn open_lock(deadends: Vec<String>, target: String) -> i32 {
    let dead_locks: HashSet<usize> =
        HashSet::from_iter(deadends.into_iter().map(|x| x.parse::<usize>().unwrap()));
    if dead_locks.contains(&0) {
        return -1;
    }

    let mut q = VecDeque::new();
    let mut done = vec![false; 10000];

    q.push_back((0usize, 0usize));
    done[0] = true;

    let target: usize = target.parse().unwrap();

    while !q.is_empty() {
        // println!("{:?}", q.len());
        let (num, step) = q.pop_front().unwrap();

        if num == target {
            return step as i32;
        }

        for i in [10000, 1000, 100, 10] {
            let t = num % i / (i / 10);

            let new_t = (t + 1) % 10;
            let new_num = num - t * (i / 10) + new_t * (i / 10);
            if !done[new_num] && !dead_locks.contains(&new_num) {
                done[new_num] = true;
                q.push_back((new_num, step + 1));
            }

            let new_t = (t + 10 - 1) % 10;
            let new_num = num - t * (i / 10) + new_t * (i / 10);
            if !done[new_num] && !dead_locks.contains(&new_num) {
                done[new_num] = true;
                q.push_back((new_num, step + 1));
            }
        }
    }

    -1
}

fn main() {
    assert_eq!(
        open_lock(
            vec![
                "8887".to_string(),
                "8889".to_string(),
                "8878".to_string(),
                "8898".to_string(),
                "8788".to_string(),
                "8988".to_string(),
                "7888".to_string(),
                "9888".to_string(),
            ],
            "8888".to_string(),
        ),
        -1
    );
}
