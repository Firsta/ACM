pub fn beautiful_subsets(nums: Vec<i32>, k: i32) -> i32 {
    let n = nums.len();

    let mut ans = -1;
    for i in 0..2i32.pow(n as u32) {
        let mut v = Vec::new();
        for j in 0..n {
            if (i & 1 << j) != 0 {
                v.push(nums[j]);
            }
        }
        let mut ok = true;

        if v.len() > 1 {
            for kk in 0..v.len() {
                for w in 0..v.len() {
                    if (v[kk] - v[w]).abs() == k as i32 {
                        ok = false;
                        break;
                    }
                }
            }
        }
        // println!("this: {:?} {}", v, ok);

        if ok {
            // println!("{:?}", v);
            ans += 1;
        }
    }

    ans
}

fn main() {
    assert_eq!(beautiful_subsets(vec![2, 4, 6], 2), 4);
    assert_eq!(beautiful_subsets(vec![1], 1), 1);
}
