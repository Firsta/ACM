pub fn prime_sub_operation(nums: Vec<i32>) -> bool {
    let mut prime = Vec::new();
    let mut is_prime = vec![true; 1001];
    for i in 2..1000 {
        if is_prime[i] {
            prime.push(i as i32);
            if i * i <= 1000 {
                let mut j = i * i;
                while j <= 1000 {
                    is_prime[j] = false;
                    j += i;
                }
            }
        }
    }

    let mut after = Vec::new();

    for i in 0..nums.len() {
        let pivit = if i == 0 {
            nums[0]
        } else {
            nums[i] - after.last().unwrap()
        };

        if pivit <= 0 {
            return false;
        } else if pivit <= 2 {
            after.push(nums[i]);
        } else if pivit > 997 {
            after.push(nums[i] - 997);
        } else {
            let p = prime.partition_point(|x| *x < pivit);
            after.push(nums[i] - prime[p - 1]);
        }
    }

    // println!("{:?}", prime);

    true
}

fn main() {
    assert_eq!(prime_sub_operation(vec![4, 9, 6, 10]), true);
    assert_eq!(prime_sub_operation(vec![5, 8, 3]), false);
}
