fn cal(n: &i32) -> i32 {
    let mut n = n.clone();
    let mut ret = 0;
    while n > 0 {
        if n % 2 == 1 {
            ret += 1;
        }
        n /= 2;
    }
    ret
}

pub fn can_sort_array(nums: Vec<i32>) -> bool {
    let mut e = Vec::new();
    let mut t = Vec::new();
    let mut l = None;
    for n in nums.iter() {
        let s = cal(n);
        l = match l {
            None => {
                t.push(*n);
                Some(s)
            }
            Some(x) => {
                if s != x {
                    t.sort();
                    e.append(&mut t);
                    t.push(*n);
                    Some(s)
                } else {
                    t.push(*n);
                    Some(x)
                }
            }
        };
    }
    t.sort();
    e.append(&mut t);

    // println!("{:?}", e);

    let mut nums = nums;
    nums.sort();
    e == nums
}

fn main() {
    assert_eq!(can_sort_array(vec![8, 4, 2, 30, 15]), true);
    assert_eq!(can_sort_array(vec![1, 2, 3, 4, 5]), true);
    assert_eq!(can_sort_array(vec![3, 16, 8, 4, 2]), false);
}
