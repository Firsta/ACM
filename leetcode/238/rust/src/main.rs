pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
    let mut result = Vec::with_capacity(nums.len());
    let mut p = 1;
    for &n in nums.iter() {
        result.push(p);
        p *= n;
    }

    p = 1;
    for i in (0..nums.len()).rev() {
        result[i] = result[i] * p;
        p *= nums[i];
    }

    result
}

fn main() {
    assert_eq!(product_except_self(vec![1, 2, 3, 4]), vec![24, 12, 8, 6]);
    assert_eq!(
        product_except_self(vec![-1, 1, 0, -3, 3]),
        vec![0, 0, 9, 0, 0]
    );
}
