pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
    let n = arr.len();

    let mut sorted = arr.clone();
    sorted.sort();
    let mut h0 = vec![0; n];
    let mut h1 = vec![0; n];
    let mut ans = 0;
    for i in 0..n {
        h0[sorted[i] as usize] += 1;
        h1[arr[i] as usize] += 1;
        if h0 == h1 {
            ans += 1;
            h0 = vec![0; n];
            h1 = vec![0; n];
        }
    }

    ans
}

fn main() {
    assert_eq!(max_chunks_to_sorted(vec![4, 3, 2, 1, 0]), 1);
    assert_eq!(max_chunks_to_sorted(vec![1, 0, 2, 3, 4]), 4);
}
