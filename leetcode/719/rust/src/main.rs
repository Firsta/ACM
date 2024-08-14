pub fn smallest_distance_pair(nums: Vec<i32>, k: i32) -> i32 {
    let mmax = nums.iter().max().unwrap();
    let mmin = nums.iter().min().unwrap();
    let max_dis = mmax - mmin;

    let mut dis_cnt = vec![0; max_dis as usize + 1];
    let n = nums.len();
    for i in 0..n {
        for j in i + 1..n {
            dis_cnt[(nums[j] - nums[i]).abs() as usize] += 1;
        }
    }

    let mut k = k;
    // println!("{:?}", dis_cnt);
    for (idx, cnt) in dis_cnt.into_iter().enumerate() {
        k -= cnt;
        if k <= 0 {
            return idx as i32;
        }
    }
    0
}
fn main() {
    assert_eq!(smallest_distance_pair(vec![1, 3, 1], 1), 0);
    assert_eq!(smallest_distance_pair(vec![1, 1, 1], 2), 0);
    assert_eq!(smallest_distance_pair(vec![1, 6, 1], 3), 5);
}
