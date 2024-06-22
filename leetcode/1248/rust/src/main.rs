pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
    let mut left_of_odds = Vec::new();
    let mut right_of_odds = Vec::new();

    let mut left = 0;
    let mut odd = Vec::new();
    for n in nums.iter() {
        if n % 2 == 1 {
            left_of_odds.push(left);
            odd.push(1);
            left = 0;
        } else {
            odd.push(0);
            left += 1;
        }
    }

    let mut right = 0;
    for n in nums.iter().rev() {
        if n % 2 == 1 {
            right_of_odds.push(right);
            right = 0;
        } else {
            right += 1;
        }
    }
    right_of_odds.reverse();

    // println!("{:?}\n{:?}", left_of_odds, right_of_odds);

    let mut ans = 0;
    let odd_cnt = left_of_odds.len();
    for i in 0..odd_cnt {
        let tail = i + k as usize - 1;
        if tail < odd_cnt {
            ans += 1;
            ans += left_of_odds[i];
            ans += right_of_odds[tail];
            ans += left_of_odds[i] * right_of_odds[tail];
        }
    }

    ans
}
fn main() {
    assert_eq!(
        number_of_subarrays(
            vec![
                45627, 50891, 94884, 11286, 35337, 46414, 62029, 20247, 72789, 89158, 54203, 79628,
                25920, 16832, 47469, 80909
            ],
            1
        ),
        28
    );
}
