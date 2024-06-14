pub fn min_increment_for_unique(nums: Vec<i32>) -> i32 {
    let mut nums = nums;
    nums.sort();

    let mut cnts = Vec::new();
    let mut c = (-1, 0);
    for n in nums.into_iter() {
        if c.0 == -1 {
            c = (n, 1);
        } else {
            if n != c.0 {
                cnts.push(c.clone());
                c = (n, 1);
            } else {
                c.1 += 1;
            }
        }
    }
    cnts.push(c.clone());

    let mut ans = 0;
    let mut rest = 0;
    for i in 0..cnts.len() {
        let this_cnt = cnts[i].1 + rest;
        if this_cnt > 1 {
            let to_move = this_cnt - 1;

            if i == cnts.len() - 1 {
                ans += to_move * (to_move + 1) / 2;
            } else {
                let gap = cnts[i + 1].0 - cnts[i].0 - 1;
                if gap >= to_move {
                    rest = 0;
                    ans += to_move * (to_move + 1) / 2;
                } else {
                    rest = to_move - gap;
                    ans += gap * (gap + 1) / 2 + (gap + 1) * rest;
                }
            }
        }
    }

    ans
}

fn main() {
    assert_eq!(min_increment_for_unique(vec![3, 2, 1, 2, 1, 7]), 6);
}
