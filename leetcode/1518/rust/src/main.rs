pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
    let mut ans = num_bottles;

    let mut emptys = num_bottles;

    while emptys >= num_exchange {
        ans += emptys / num_exchange;
        emptys = emptys % num_exchange + emptys / num_exchange;
    }

    ans
}

fn main() {
    assert_eq!(num_water_bottles(9, 3), 13);
    assert_eq!(num_water_bottles(15, 4), 19);
}
