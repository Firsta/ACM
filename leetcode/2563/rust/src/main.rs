pub fn count_fair_pairs(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
    let mut nums = nums;
    nums.sort();

    // println!("{:?}", nums);

    let mut ans = 0;
    for i in 1..nums.len() {
        let li = nums[0..i].partition_point(|x| *x + nums[i] < lower);
        let ui = nums[0..i].partition_point(|x| *x + nums[i] <= upper);

        // println!("{} {}", li, ui);
        ans += (ui - li) as i64;
    }

    ans
}

fn main() {
    assert_eq!(count_fair_pairs(vec![0, 1, 7, 4, 4, 5], 3, 6), 6);
    assert_eq!(count_fair_pairs(vec![1, 7, 9, 2, 5], 11, 11), 1);
}
