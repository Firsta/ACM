pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let n = nums.len();

    let mut ans = Vec::new();
    for i in 0..2i32.pow(n as u32) {
        let mut v = Vec::new();
        for j in 0..n {
            if i & (1 << j) != 0 {
                v.push(nums[j]);
            }
        }
        ans.push(v);
    }

    ans
}

fn main() {
    assert_eq!(
        subsets(vec![1, 2, 3]),
        vec![
            vec![],
            vec![1],
            vec![2],
            vec![1, 2],
            vec![3],
            vec![1, 3],
            vec![2, 3],
            vec![1, 2, 3]
        ]
    );
}
