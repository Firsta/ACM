pub fn majority_element(nums: Vec<i32>) -> i32 {
    let mut now = std::i32::MAX;
    let mut cnt = 0;

    for &n in nums.iter() {
        if cnt == 0 {
            now = n;
            cnt = 1;
        } else {
            cnt += if n == now { 1 } else { -1 };
        }
    }
    now
}

fn main() {
    println!("{}", majority_element(vec![2, 2, 1, 1, 1, 2, 2]));
}
