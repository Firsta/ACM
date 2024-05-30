pub fn count_triplets(arr: Vec<i32>) -> i32 {
    let n = arr.len();
    let mut ans = 0;
    for i in 0..n - 1 {
        for j in i + 1..n {
            let mut t = 0;
            for k in i..=j {
                t ^= arr[k];
            }
            if t == 0 {
                ans += (j - i) as i32;
            }
        }
    }
    ans
}

fn main() {
    assert_eq!(count_triplets(vec![2, 3, 1, 6, 7]), 4);
    assert_eq!(count_triplets(vec![1, 1, 1, 1, 1]), 10);
}
