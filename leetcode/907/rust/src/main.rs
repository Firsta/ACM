pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
    let n = arr.len();
    let mut kickout_time = vec![n - 1; n];
    let mut dp = Vec::new();
    let mut stack = Vec::new();
    for i in 0..arr.len() {
        let t = arr[i];
        let mut c = 1;
        while stack.len() > 0 && arr[stack[stack.len() - 1]] > t {
            let d = stack.pop().unwrap();
            c += dp[d];
            kickout_time[d] = i - 1;
        }
        stack.push(i);
        dp.push(c);
    }

    // println!("{:?} {:?}", dp, kickout_time);

    let mut result = 0;
    for i in 0..n {
        let t = dp[i] * arr[i];
        let k = kickout_time[i] - i;
        result = (result + t as i64 * (k + 1) as i64) % (10i64.pow(9) + 7) as i64;
    }

    result as i32
}

fn main() {
    println!("{}", sum_subarray_mins(vec![11, 81, 94, 43, 3]));
}
