use std::collections::HashMap;

pub fn subarrays_div_by_k(nums: Vec<i32>, k: i32) -> i32 {
    let mut sum = 0;
    let mut ans = 0;

    let mut m = HashMap::new();
    m.insert(0, 1);
    for n in nums.into_iter() {
        sum += n;
        let mo = ((sum % k) + k) % k;
        ans += m.get(&mo).unwrap_or(&0);
        m.entry(mo).and_modify(|e| *e += 1).or_insert(1);
    }

    ans
}

fn main() {
    assert_eq!(subarrays_div_by_k(vec![4, 5, 0, -2, -3, 1], 5), 7);
}
