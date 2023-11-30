pub fn minimum_one_bit_operations(n: i32) -> i32 {
    let mut n = n;
    let mut dp0 = 0;
    let mut dp1 = 0;
    let mut k = 0;
    let mut loop_count = 0u32;
    while n > 0 {
        if n % 2 == 0 {
            dp1 = dp1 + 1 + k;
        } else {
            let new_dp0 = dp1 + 1 + k;
            let new_dp1 = dp0;
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        k += i32::pow(2, loop_count);
        loop_count += 1;
        n /= 2;
        // println!("{} {} {} {}", n, k, dp0, dp1);
    }
    dp0
}

fn main() {
    println!("{}", minimum_one_bit_operations(6));
}
