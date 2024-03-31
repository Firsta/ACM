use std::collections::BTreeMap;

pub fn foo(nums: &Vec<i32>, min_k: i32, max_k: i32) -> i64 {
    let mut m = BTreeMap::new();

    let mut left = 0;
    let mut result = 0;

    for right in 0..nums.len() {
        let right_num = nums[right];

        m.entry(right_num).and_modify(|e| *e += 1).or_insert(1);

        while let Some((mmin, _)) = m.first_key_value() {
            if *mmin < min_k {
                let left_num = nums[left];
                let x = m.get(&left_num).unwrap();
                if *x == 1 {
                    m.remove(&left_num);
                } else {
                    m.insert(left_num, x - 1);
                }

                left += 1;
            } else {
                break;
            }
        }

        while let Some((mmax, _)) = m.last_key_value() {
            if *mmax > max_k {
                let left_num = nums[left];
                let x = m.get(&left_num).unwrap();
                if *x == 1 {
                    m.remove(&left_num);
                } else {
                    m.insert(left_num, x - 1);
                }

                left += 1;
            } else {
                break;
            }
        }

        result += right + 1 - left;
        // println!("{} {} {}", left, right, result);
    }

    result as i64
}

pub fn foo1(nums: &Vec<i32>, min_k: i32, max_k: i32) -> i64 {
    let mut m = BTreeMap::new();

    let mut left = 0;
    let mut result = 0;

    for right in 0..nums.len() {
        let right_num = nums[right];

        m.entry(right_num).and_modify(|e| *e += 1).or_insert(1);

        while let Some((mmin, _)) = m.first_key_value() {
            if *mmin < min_k {
                let left_num = nums[left];
                let x = m.get(&left_num).unwrap();
                if *x == 1 {
                    m.remove(&left_num);
                } else {
                    m.insert(left_num, x - 1);
                }

                left += 1;
            } else {
                break;
            }
        }

        while let Some((mmax, _)) = m.last_key_value() {
            if *mmax >= max_k {
                let left_num = nums[left];
                let x = m.get(&left_num).unwrap();
                if *x == 1 {
                    m.remove(&left_num);
                } else {
                    m.insert(left_num, x - 1);
                }

                left += 1;
            } else {
                break;
            }
        }

        result += right + 1 - left;
        // println!("{} {} {}", left, right, result);
    }

    result as i64
}

pub fn foo2(nums: &Vec<i32>, min_k: i32, max_k: i32) -> i64 {
    let mut m = BTreeMap::new();

    let mut left = 0;
    let mut result = 0;

    for right in 0..nums.len() {
        let right_num = nums[right];

        m.entry(right_num).and_modify(|e| *e += 1).or_insert(1);

        while let Some((mmin, _)) = m.first_key_value() {
            if *mmin <= min_k {
                let left_num = nums[left];
                let x = m.get(&left_num).unwrap();
                if *x == 1 {
                    m.remove(&left_num);
                } else {
                    m.insert(left_num, x - 1);
                }

                left += 1;
            } else {
                break;
            }
        }

        while let Some((mmax, _)) = m.last_key_value() {
            if *mmax > max_k {
                let left_num = nums[left];
                let x = m.get(&left_num).unwrap();
                if *x == 1 {
                    m.remove(&left_num);
                } else {
                    m.insert(left_num, x - 1);
                }

                left += 1;
            } else {
                break;
            }
        }

        result += right + 1 - left;
        // println!("{} {} {}", left, right, result);
    }

    result as i64
}

pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
    foo(&nums, min_k, max_k) - foo1(&nums, min_k, max_k) - foo2(&nums, min_k, max_k)
        + foo(&nums, min_k + 1, max_k - 1)
    // [min_k, max_k)
    // (2, 6]

    // foo [2, 6]
    // [2] [2,4] ([4]) [2,4,6] ([4,6] [6]) [2,4,6,3] ([4,6,3] [6,3] [3] [6])

    // foo1 [2, 6)
    // [2] [2, 4] [4]

    // foo2 (2, 6]
    // [4] [4,6] [6] [4,6,3] [6,3] [3] [6]

    // [2, 6] - (2, 6] - [2, 6) + (2, 6)
}

// [1,2,4,6,3,8,6]
// 2
// 6
fn main() {
    assert_eq!(count_subarrays(vec![1, 3, 5, 2, 7, 5], 1, 5), 2);
    assert_eq!(count_subarrays(vec![1, 1, 1, 1], 1, 1), 10);
}
