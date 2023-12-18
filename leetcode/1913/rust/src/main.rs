pub fn max_product_difference(nums: Vec<i32>) -> i32 {
    let mut max = 0;
    let mut maxx = 0;
    let mut min = 10001;
    let mut minn = 10001;
    for i in 0..nums.len() {
        if nums[i] > max {
            maxx = max;
            max = nums[i];
        } else if nums[i] > maxx {
            maxx = nums[i];
        }

        if nums[i] < min {
            minn = min;
            min = nums[i];
        } else if nums[i] < minn {
            minn = nums[i];
        }
    }
    max * maxx - min * minn
}

fn main() {
    println!("{}", max_product_difference(vec![4,2,5,9,7,4,8]));
}
