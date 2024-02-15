pub fn largest_perimeter(nums: Vec<i32>) -> i64 {
    let mut nums: Vec<i64> = nums.iter().map(|x| *x as i64).collect();
    nums.sort();

    let mut s = nums.iter().sum();

    for i in (0..nums.len()).rev() {
        // println!("{} {} {}", s, nums[i] as i64, (s - nums[i] as i64));
        if s - nums[i] > nums[i] {
            return s;
        }
        s -= nums[i];
    }

    -1
}

fn main() {
    println!("{}", largest_perimeter(vec![1, 12, 1, 2, 5, 50, 3]));
}
