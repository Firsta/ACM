pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
    fn partition(nums: &mut Vec<i32>, l: usize, r: usize) -> usize {
        let mut i = l;
        let mut j = r + 1;
        let v = nums[l];
        // println!("{:?} {} {}", nums, l, r);
        loop {
            loop {
                i += 1;
                if nums[i] >= v || i == r {
                    break;
                }
            }
            loop {
                j -= 1;
                if nums[j] <= v || j == l {
                    break;
                }
            }
            if i >= j {
                break;
            } else {
                nums.swap(i, j);
            }
        }
        nums.swap(l, j);
        j
    }
    fn sort(nums: &mut Vec<i32>, l: usize, r: usize) {
        if r <= l {
            return;
        } else {
            let j = partition(nums, l, r);
            // println!("{} {} {}", l, r, j);
            if j > 0 {
                sort(nums, l, j - 1);
            }
            sort(nums, j + 1, r);
        }
    }

    let mut nums = nums;
    let n = nums.len();
    sort(&mut nums, 0, n - 1);
    nums
}
fn main() {
    assert_eq!(sort_array(vec![5, 2, 3, 1]), vec![1, 2, 3, 5]);
    assert_eq!(sort_array(vec![5, 1, 1, 2, 0, 0]), vec![0, 0, 1, 1, 2, 5]);
}
