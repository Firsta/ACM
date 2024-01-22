pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
    let n = nums.len();
    let mut c = vec![false; n];
    let mut result = Vec::new();
    let mut s = 0;
    for &x in nums.iter() {
        s += x;
        if c[x as usize - 1] {
            result.push(x);
        } else {
            c[x as usize - 1] = true;
        }
    }
    result.push((n * (n + 1) / 2) as i32 - s + result[0]);
    result
}

fn main() {
    println!("{:?}", find_error_nums(vec![1,2,2,4]));
}
