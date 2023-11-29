pub fn hammingWeight (n: u32) -> i32 {
    let mut num = 0;
    let mut n = n;
    while n > 0 {
        if n % 2 == 1 {
            num += 1;
        }
        n /= 2;
    }
    num
}

fn main() {
    println!("{}", hammingWeight(3));
}
