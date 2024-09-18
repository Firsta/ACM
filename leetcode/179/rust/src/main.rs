pub fn largest_number(nums: Vec<i32>) -> String {
    let mut nums = nums
        .into_iter()
        .map(|n| n.to_string())
        .collect::<Vec<String>>();
    nums.sort_by(|a, b| {
        let aa = a.clone();
        let bb = b.clone();

        let mut a = a.clone();
        a.push_str(&bb);
        let mut b = b.clone();
        b.push_str(&aa);

        b.cmp(&a)
    });
    let mut begin = 0;
    while begin < nums.len() && nums[begin] == "0" {
        begin += 1;
    }
    if begin == nums.len() {
        "0".to_string()
    } else {
        nums[begin..].join("")
    }
}
fn main() {
    assert_eq!(largest_number(vec![10, 2]), "210".to_string());
    assert_eq!(largest_number(vec![3, 30, 34, 5, 9]), "9534330".to_string());
    assert_eq!(largest_number(vec![0, 0]), "0".to_string());
}
