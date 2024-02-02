fn calc_dig_cnt(n: i32) -> usize {
    let mut l = n;
    let mut cnt = 0;
    while l > 0 {
        cnt += 1;
        l /= 10;
    }
    cnt
}

fn gen_dig(tail: i32, len: i32) -> i32 {
    let mut d = 0;
    for i in (tail - len + 1)..=tail {
        d = d * 10 + i;
    }
    d
}

pub fn sequential_digits(low: i32, high: i32) -> Vec<i32> {
    let low_dig_cnt = calc_dig_cnt(low);
    let high_dig_cnt = std::cmp::min(calc_dig_cnt(high), 9);

    // 1,000,000,000
    let mut nums = Vec::new();
    for i in low_dig_cnt..=high_dig_cnt {
        for j in i..=9 {
            nums.push(gen_dig(j as i32, i as i32));
        }
    }

    let mut ans = Vec::new();
    for &x in nums.iter() {
        if x >= low {
            if x <= high {
                ans.push(x);
            } else {
                break;
            }
        }
    }
    ans
}

fn main() {
    println!("{:?}", sequential_digits(1000, 13000));
}
