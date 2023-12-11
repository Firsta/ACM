pub fn find_special_integer(arr: Vec<i32>) -> i32 {
    let l = arr.len();
    let candidates = [arr[l / 4], arr[l / 2], arr[l * 3 / 4]];
    for &n in candidates.iter() {
        let left = arr.partition_point(|&x| x < n);
        let right = arr.partition_point(|&x| x <= n);
        if right - left > (l / 4) as usize {
            return n
        }
    }
    -1
}

fn main() {
    println!("{}", find_special_integer(vec![1,2,2,6,6,6,6,7,10]));
}
