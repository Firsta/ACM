pub fn divide_players(skill: Vec<i32>) -> i64 {
    let mut skill: Vec<i64> = skill.into_iter().map(|x| x as i64).collect();
    skill.sort();

    let n = skill.len();

    let mut i = 0;
    let mut j = n - 1;

    let e = skill[i] + skill[j];
    let mut ans = skill[i] * skill[j];

    i += 1;
    j -= 1;

    while i < j {
        if skill[i] + skill[j] != e {
            return -1;
        } else {
            ans += skill[i] * skill[j]
        }
        i += 1;
        j -= 1;
    }

    ans
}

fn main() {
    assert_eq!(divide_players(vec![3, 2, 5, 1, 3, 4]), 22);
    assert_eq!(divide_players(vec![3, 4]), 12);
    assert_eq!(divide_players(vec![1, 1, 2, 3]), -1);
}
