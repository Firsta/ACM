pub fn total_money(n: i32) -> i32 {
    let whole_week_count = n / 7;

    let mut rest = 0;
    for i in (whole_week_count + 1)..(whole_week_count + 1 + (n % 7)) {
        rest += i
    }

    7 * whole_week_count * (whole_week_count - 1) / 2 + 28 * whole_week_count + rest
}

fn main() {
    println!("{}", total_money(20));
}
