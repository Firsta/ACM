pub fn missing_number(nums: Vec<i32>) -> i32 {
    let n = nums.len() as i32;
    let mut s = (n + 1) * n / 2;
    for &n in nums.iter() {
        s -= n;
    }
    s
}

fn main() {
    println!("{}", missing_number(vec![9, 6, 4, 2, 3, 5, 7, 0, 1]));
}
