pub fn rearrange_array(nums: Vec<i32>) -> Vec<i32> {
    let mut i = 0;
    let mut j = 0;

    let mut result = Vec::new();
    let n = nums.len();
    while i < n && j < n {
        while i < n && nums[i] < 0 {
            i += 1;
        }
        while j < n && nums[j] > 0 {
            j += 1;
        }
        result.push(nums[i]);
        result.push(nums[j]);
        i += 1;
        j += 1;
    }

    result
}

fn main() {
    println!("{:?}", rearrange_array(vec![3, 1, -2, -5, 2, -4]));
}
