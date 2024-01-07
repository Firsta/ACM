use std::collections::HashMap;

pub fn number_of_arithmetic_slices(nums: Vec<i32>) -> i32 {
    // diffs[i] saves counts of all possible diffs created by nums[i] minus its former items.
    // e.g. diffs[10][2] = 3 means there is 3 item before nums[10] such that nums[10] minus one of these items is 2.

    // initialize Vec with capacity can save time.
    let mut diffs = Vec::with_capacity(nums.len());
    for i in 0..nums.len() {
        let mut m = HashMap::new();
        for j in 0..i {
            // use i64 to save diff because diff of two i32 integers may overflow the range of i32
            let d = nums[i] as i64 - nums[j] as i64;
            m.entry(d).and_modify(|x| *x += 1).or_insert(1);
        }
        diffs.push(m);
    }
    // println!("{:?}", diffs);

    let mut result = 0;
    // dp[i] saves counts of all arithmetic subsequences the end with nums[i].
    // e.g. dp[3][4] = 7 means that there are 7 arithmetic subsequences that end with nums[3] and difference between any two consecutive elements in these subsequences is 4.
    let mut dp: Vec<HashMap<i64, i32>> = Vec::with_capacity(nums.len());
    for i in 0..nums.len() {
        let mut m = HashMap::new();
        for j in 0..i {
            let d = nums[i] as i64 - nums[j] as i64;
            // two items plus a new item can construct a new arithmetic subsequence.
            // (an arithmetic subsequence consists of at lease 3 elements)
            let mut c = diffs[j].get(&d).unwrap_or_else(|| &0).clone();
            // an existing arithmetic subsequence plus a new item can construct a new arithmetic subsequence.
            c += dp[j].get(&d).unwrap_or_else(|| &0);
            if c > 0 {
                result += c;
                m.entry(d).and_modify(|x| *x += c).or_insert(c);
            }
        }
        dp.push(m);
    }
    // println!("{:?}", dp);

    result
}

fn main() {
    println!("{}", number_of_arithmetic_slices(vec![2, 4, 6, 8, 10]));
}
