use std::collections::HashMap;

pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
    let mut diffs = Vec::new();
    for i in 0..nums.len() {
        let mut m = HashMap::new();
        for j in 0..i {
            let d = nums[i] as i64 - nums[j] as i64;
            let n = m.get(&d).unwrap_or_else(|| &0) + 1;
            m.insert(d, n);
        }
        diffs.push(m);
    }
    // println!("{:?}", diffs);
    
    let mut result = 0;
    let mut dp: Vec<HashMap<i64, i32>> = Vec::new();
    for i in 0..nums.len() {
        let mut m = HashMap::new();
        for j in 0..i {
            let d = nums[i] as i64 - nums[j] as i64;
            let mut c = diffs[j].get(&d).unwrap_or_else(|| &0).clone();
            c += dp[j].get(&d).unwrap_or_else(|| &0);
            if c > 0 {
                result += c;
                let n = m.get(&d).unwrap_or_else(|| &0) + c;
                m.insert(d, n);
            }
        }
        dp.push(m);
    }
    // println!("{:?}", dp);
    
    result
}

fn main() {
    println!("{}", number_of_arithmetic_slices(vec![2,4,6,8,10]));
}
