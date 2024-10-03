use std::collections::HashMap;

pub fn min_subarray_0(nums: Vec<i32>, p: i32) -> i32 {
    let sum = nums.iter().sum::<i32>();
    let n = nums.len();
    let mut ans = None;
    for i in 0..n {
        for j in i..n {
            let mut ss = 0;
            for k in i..=j {
                ss += nums[k];
            }
            if (sum - ss) % p == 0 {
                if j - i + 1 == 7 {
                    println!("{} {}", i, j);
                }
                ans = match ans {
                    None => Some(j - i + 1),
                    Some(x) => Some(std::cmp::min(x, j - i + 1)),
                }
            }
        }
    }

    match ans {
        None => -1,
        Some(ans) => ans as i32,
    }
}

pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
    let nums: Vec<i64> = nums.into_iter().map(|x| x as i64).collect();
    let p = p as i64;

    let sum = nums.iter().sum::<i64>();
    if sum % p == 0 {
        0
    } else {
        
        let n = nums.len();

        let mut m = HashMap::<i64, Vec<usize>>::new();
        let mut ans = None;

        let mut prefix_sum = 0;
        for i in 0..n {
            prefix_sum += nums[i];
            if prefix_sum % p == 0 {
                let rm_cnt = n - i - 1;
                ans = match ans {
                    None => Some(rm_cnt),
                    Some(x) => if x > rm_cnt {
                        Some(rm_cnt)
                    } else {
                        Some(x)
                    },
                };
            }
            if prefix_sum % p == 0 {
                let rm_cnt = n - i - 1;
                ans = match ans {
                    None => Some(rm_cnt),
                    Some(x) => if x > rm_cnt {
                        Some(rm_cnt)
                    } else {
                        Some(x)
                    },
                };
            }
            if i != n - 1 && (sum - prefix_sum) % p == 0 {
                let rm_cnt = i + 1;
                ans = match ans {
                    None => Some(rm_cnt),
                    Some(x) => if x > rm_cnt {
                        Some(rm_cnt)
                    } else {
                        Some(x)
                    },
                };
            }
            let r = prefix_sum % p;
            m.entry(r).and_modify(|e| e.push(i)).or_insert(vec![i]);
        }
        
        let mut suffix_sum = 0;
        for i in (0..nums.len()).rev() {
            suffix_sum += nums[i];
            let r = suffix_sum % p;
            let rr = match r {
                0 => 0,
                _ => p - r,
            };

            if m.get(&rr).is_none() || m.get(&rr).unwrap()[0] >= i {
                continue;
            }

            let pp = m.get(&rr).unwrap().partition_point(|&x| x < i) - 1;
            let ii = m.get(&rr).unwrap()[pp];
            println!("{} {} {} {}", i, pp, r, rr);
            let rm_cnt = i - ii - 1;
            ans = match ans {
                None => Some(rm_cnt),
                Some(x) => if x > rm_cnt {
                    Some(rm_cnt)
                } else {
                    Some(x)
                },
            };
        }
        
        match ans {
            None => -1,
            Some(ans) => ans as i32,
        }
    }
}

fn main() {
    assert_eq!( min_subarray(vec![8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2], 148), 7);
}
