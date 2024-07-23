pub fn frequency_sort(nums: Vec<i32>) -> Vec<i32> {
    let mut c = vec![0; 201];

    let n = nums.len();
    for n in nums.into_iter() {
        c[(n + 100) as usize] += 1;
    }

    let mut s: Vec<(i32, i32)> = c
        .into_iter()
        .enumerate()
        .filter(|x| x.1 > 0)
        .map(|x| (x.0 as i32 - 100, x.1))
        .collect();
    s.sort_by(|a, b| {
        if a.1 == b.1 {
            b.0.cmp(&a.0)
        } else {
            a.1.cmp(&b.1)
        }
    });

    let mut ans = Vec::with_capacity(n);
    for (n, c) in s.into_iter() {
        for _ in 0..c {
            ans.push(n);
        }
    }

    ans
}
fn main() {
    assert_eq!(
        frequency_sort(vec![1, 1, 2, 2, 2, 3]),
        vec![3, 1, 1, 2, 2, 2]
    );
    assert_eq!(frequency_sort(vec![2, 3, 1, 3, 2]), vec![1, 3, 3, 2, 2]);
}
