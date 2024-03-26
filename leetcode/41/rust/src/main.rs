pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
    let mut has_one = false;
    let n = nums.len();
    for i in 0..n {
        if nums[i] == 1 {
            has_one = true;
        }
        if nums[i] <= 0 || nums[i] > n as i32 {
            nums[i] = 1;
        }
    }

    if has_one {
        for i in 0..n {
            let value = nums[i].abs();
            if value == n as i32 {
                nums[0] = -nums[0].abs();
            } else {
                nums[value as usize] = -nums[value as usize].abs();
            }
        }

        for i in 1..n {
            if nums[i] > 0 {
                return i as i32;
            }
        }

        if nums[0] > 0 {
            return n as i32;
        }

        n as i32 + 1
    } else {
        1
    }
}

fn main() {
    assert_eq!(first_missing_positive(vec![1, 2, 0]), 3);
    assert_eq!(first_missing_positive(vec![3, 4, -1, 1]), 2);
    assert_eq!(first_missing_positive(vec![7, 8, 9, 11, 12]), 1);
}
