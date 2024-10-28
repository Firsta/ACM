pub fn longest_square_streak(nums: Vec<i32>) -> i32 {
    let mut nums = nums;
    nums.sort();
    let mut used = std::collections::HashMap::new();
    for n in nums.iter() {
        used.entry(*n).and_modify(|e| *e = false).or_insert(false);
    }

    let mut ans = -1;
    for n in nums.iter() {
        if *used.get(n).unwrap() == false {
            let mut n = *n;
            let mut t = 1;
            loop {
                let next = n.checked_mul(n);
                if next.is_none() {
                    break;
                } else {
                    let next = next.unwrap();
                    if used.get(&next).is_some() {
                        used.insert(next, true);
                        t += 1;
                        n = next;
                    } else {
                        break;
                    }
                }
            }
            if t >= 2 {
                ans = std::cmp::max(ans, t);
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(longest_square_streak(vec![4, 3, 6, 16, 8, 2]), 3);
}
