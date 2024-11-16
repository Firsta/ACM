pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let k = k as usize;
    let mut i = k - 1;
    while i > 0 && nums[i - 1] + 1 == nums[i] {
        i -= 1
    }
    let mut a = k - i;
    let mut ans = vec![if a == k { nums[k - 1] } else { -1 }];
    for i in k..nums.len() {
        if nums[i] == nums[i - 1] + 1 {
            a += 1;
        } else {
            a = 1;
        }
        ans.push(if a >= k { nums[i] } else { -1 });
    }

    ans
}

fn main() {
    assert_eq!(
        results_array(vec![1, 2, 3, 4, 3, 2, 5], 3),
        vec![3, 4, -1, -1, -1]
    );
    assert_eq!(results_array(vec![2, 2, 2, 2, 2], 4), vec![-1, -1]);
    assert_eq!(
        results_array(vec![3, 2, 3, 2, 3, 2], 2),
        vec![-1, 3, -1, 3, -1]
    );
    assert_eq!(results_array(vec![1, 3, 4], 2), vec![-1, 4]);
}
