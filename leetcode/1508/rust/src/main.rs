pub fn range_sum(nums: Vec<i32>, n: i32, left: i32, right: i32) -> i32 {
    let mut prefix_sums = vec![0];
    let mut sum = 0;

    for n in nums.iter() {
        sum += *n;
        prefix_sums.push(sum);
    }

    let mut sums = Vec::new();
    let n = n as usize;
    for l in 1..=n {
        for b in 0..n - l + 1 {
            sums.push(prefix_sums[b + l] - prefix_sums[b]);
        }
    }
    sums.sort();

    let mut ans = 0;
    let left = left as usize;
    let right = right as usize;

    for i in left - 1..right {
        ans = (ans + sums[i]) % (10i32.pow(9) + 7);
    }

    ans
}

fn main() {
    assert_eq!(range_sum(vec![1, 2, 3, 4], 4, 1, 5), 13);
}
