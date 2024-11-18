pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
    let n = code.len();
    let mut ans = Vec::new();
    let mut code = code;
    if k != 0 {
        let kk = if k < 0 {
            code.reverse();
            -k as usize
        } else {
            k as usize
        };
        let mut sum = 0;
        for i in 0..kk {
            sum += code[i];
        }
        for i in 0..n {
            sum -= code[i];
            sum += code[(i + kk as usize) % n];
            ans.push(sum);
        }

        if k < 0 {
            ans.reverse();
        }
    } else {
        for _ in 0..n {
            ans.push(0);
        }
    }

    ans
}

fn main() {
    assert_eq!(decrypt(vec![5, 7, 1, 4], 3), vec![12, 10, 16, 13]);
    assert_eq!(decrypt(vec![1, 2, 3, 4], 0), vec![0, 0, 0, 0]);

    assert_eq!(decrypt(vec![2, 4, 9, 3], -2), vec![12, 5, 6, 13]);
}
