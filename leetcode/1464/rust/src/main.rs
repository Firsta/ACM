pub fn max_product(nums: Vec<i32>) -> i32 {
    let mut l = 0;
    let mut ll = 0;
    for &n in nums.iter() {
        if n >= l {
            ll = l;
            l = n;
        } else if n > ll {
            ll = n;
        }
    }
    (ll - 1) * (l - 1)
}

fn main() {
    println!("{}", max_product(vec![1,5,4,5]));
}
