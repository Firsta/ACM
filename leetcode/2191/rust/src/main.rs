pub fn sort_jumbled(mapping: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
    fn m(n: i32, mapping: &Vec<i32>) -> i32 {
        if n == 0 {
            return mapping[0];
        }
        let mut ret = 0;
        let mut x = 1;
        while n / x > 0 {
            let t = (n / x) % 10;
            ret += x * mapping[t as usize];
            x *= 10;
        }

        ret
    }

    let mut nums = nums
        .into_iter()
        .enumerate()
        .map(|x| (x.0, x.1, m(x.1.clone(), &mapping)))
        .collect::<Vec<(usize, i32, i32)>>();
    nums.sort_by(|a, b| {
        if a.2 == b.2 {
            a.0.cmp(&b.0)
        } else {
            a.2.cmp(&b.2)
        }
    });
    // println!("{:?}", nums);

    nums.into_iter().map(|x| x.1).collect()
}

fn main() {
    assert_eq!(
        sort_jumbled(
            vec![9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
            vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        ),
        vec![9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    );
    assert_eq!(
        sort_jumbled(vec![8, 9, 4, 0, 2, 1, 3, 5, 7, 6], vec![991, 338, 38]),
        vec![338, 38, 991]
    );
}
