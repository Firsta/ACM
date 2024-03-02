pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
    let mut result = Vec::with_capacity(nums.len());

    let n = nums.len();
    let (mut i, mut j) = (0i32, n as i32 - 1);

    while i <= j {
        if nums[i as usize].abs() <= nums[j as usize].abs() {
            result.push(nums[j as usize].pow(2));
            j -= 1;
        } else {
            result.push(nums[i as usize].pow(2));
            i += 1;
        }
    }

    result.reverse();
    result
}

fn main() {
    assert_eq!(
        sorted_squares(vec![-4, -1, 0, 3, 10],),
        vec![0, 1, 9, 16, 100]
    );

    assert_eq!(
        sorted_squares(vec![-7, -3, 2, 3, 11],),
        vec![4, 9, 9, 49, 121]
    );
}
