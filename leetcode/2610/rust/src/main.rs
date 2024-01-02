pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut c = vec![0; nums.len()];
    for i in nums.iter() {
        c[(i - 1) as usize] += 1;
    }
    let mut result = Vec::new();
    loop {
        let mut v = Vec::new();
        for i in 0..c.len() {
            if c[i] > 0 {
                v.push((i + 1) as i32);
                c[i] -= 1;
            }
        }
        if v.is_empty() {
            break;
        } else {
            result.push(v);
        }
    }
    result
}

fn main() {
    println!("{:?}", find_matrix(vec![1,3,4,1,2,3,1]));
}
