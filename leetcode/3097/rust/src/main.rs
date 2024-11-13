pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
    if k == 0 {
        return 1;
    }
    let n = nums.len();
    let mut j = 0;
    let mut bit_cnt = vec![0; 32];

    fn cal(bit_cnt: &Vec<i32>) -> i32 {
        let mut ret = 0;
        for k in (0..32).rev() {
            ret = ret * 2 + if bit_cnt[k] > 0 { 1 } else { 0 };
        }
        ret
    }

    let mut ans = 1000000;
    for i in 0..n {
        j = std::cmp::max(j, i);
        while cal(&bit_cnt) < k && j < n {
            for k in 0..32 {
                if (nums[j] >> k) & 1 > 0 {
                    bit_cnt[k] += 1;
                }
            }
            j += 1;
        }
        // println!("{} {}", j, cal(&bit_cnt));
        if cal(&bit_cnt) < k {
            break;
        } else {
            ans = std::cmp::min(ans, j - i);
        }

        for k in 0..32 {
            if (nums[i] >> k) & 1 > 0 {
                bit_cnt[k] -= 1;
            }
        }
    }

    match ans {
        1000000 => -1,
        _ => ans as i32,
    }
}

fn main() {
    assert_eq!(minimum_subarray_length(vec![1, 2], 0), 1);

    assert_eq!(minimum_subarray_length(vec![2, 25, 32, 1], 59), 3);
    assert_eq!(minimum_subarray_length(vec![1, 2, 3], 2), 1);
    assert_eq!(minimum_subarray_length(vec![2, 1, 8], 10), 3);
}
