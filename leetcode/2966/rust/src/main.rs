pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
    nums.sort();
    let n = nums.len();
    let mut answer = Vec::new();
    for i in 0..n / 3 {
        // println!("{}", i);
        let d = nums[(i + 1) * 3 - 1] - nums[i * 3];
        if d > k {
            return Vec::new();
        } else {
            answer.push(vec![nums[i * 3], nums[i * 3 + 1], nums[i * 3 + 2]]);
        }
    }
    answer
}

fn main() {
    println!("{:?}", divide_array(vec![1, 3, 4, 8, 7, 9, 3, 5, 1], 2));
}
