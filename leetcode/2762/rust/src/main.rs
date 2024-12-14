use std::collections::BTreeMap;

pub fn continuous_subarrays(nums: Vec<i32>) -> i64 {
    let mut j = 0;
    let mut ans = 0;
    let mut m = BTreeMap::new();
    for i in 0..nums.len() {
        j = std::cmp::max(j, i);
        while j < nums.len() {
            if m.is_empty() {
                m.insert(nums[j], 1);
                j += 1;
            } else {
                let mmin = m.first_key_value().unwrap().0.clone();
                let mmax = m.last_key_value().unwrap().0.clone();
                // println!("m: {} {}", mmin, mmax);
                if (nums[j] - mmin).abs() <= 2 && (nums[j] - mmax).abs() <= 2 {
                    m.entry(nums[j]).and_modify(|e| *e += 1).or_insert(1);
                    j += 1;
                } else {
                    break;
                }
            }
        }
        let l = j - i;
        ans += l as i64;
        // println!("{} {}", i, j);

        let cnt = m.get(&nums[i]).unwrap().clone();
        if cnt == 1 {
            m.remove(&nums[i]);
        } else {
            m.insert(nums[i], cnt - 1);
        }
    }
    ans
}

fn main() {
    assert_eq!(continuous_subarrays(vec![5, 4, 2, 4]), 8);
    assert_eq!(continuous_subarrays(vec![1, 2, 3]), 6);
    assert_eq!(
        continuous_subarrays(vec![65, 66, 67, 66, 66, 65, 64, 65, 65, 64]),
        43
    );
}
