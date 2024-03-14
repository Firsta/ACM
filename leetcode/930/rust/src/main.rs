pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
    let mut zero_prefixes = Vec::new();

    let mut zero_prefix = 0;

    for &n in nums.iter() {
        if n == 0 {
            zero_prefix += 1;
        } else {
            zero_prefixes.push(zero_prefix);
            zero_prefix = 0;
        }
    }

    zero_prefixes.push(zero_prefix);

    // println!("{:?}", zero_prefixes);

    let goal = goal as usize;

    if goal > zero_prefixes.len() - 1 {
        0
    } else if goal == 0 {
        let mut result = 0;
        for &z in zero_prefixes.iter() {
            result += z * (z + 1) / 2;
        }
        result
    } else {
        let mut result = 0;
        for i in 0..=zero_prefixes.len() - goal - 1 as usize {
            result += (zero_prefixes[i] + 1) * (zero_prefixes[i + goal] + 1);
        }
        result
    }
}

fn main() {
    assert_eq!(num_subarrays_with_sum(vec![1, 0, 1, 0, 1], 2), 4);
    assert_eq!(num_subarrays_with_sum(vec![1, 0, 1, 0, 1], 4), 0);
    assert_eq!(num_subarrays_with_sum(vec![0, 0, 0, 0, 0], 0), 15);
}
