pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
    let mut people = people;
    people.sort();

    let mut i = people.len() - 1;
    let mut j = 0;

    let mut ans = 0;
    while j < i {
        let r = limit - people[i];
        i -= 1;
        if people[j] <= r {
            j += 1;
        }
        ans += 1;
    }
    if i == j {
        ans += 1;
    }

    ans
}

fn main() {
    assert_eq!(num_rescue_boats(vec![1, 2], 3), 1);
    assert_eq!(num_rescue_boats(vec![3, 2, 2, 1], 3), 3);
    assert_eq!(num_rescue_boats(vec![3, 5, 3, 4], 5), 4);
}
