pub fn buy_choco(prices: Vec<i32>, money: i32) -> i32 {
    let mut m = 101;
    let mut mm = 101;
    for &i in prices.iter() {
        if i < m {
            mm = m;
            m = i;
        } else if i < mm {
            mm = i;
        }
    }
    if m + mm > money {
        money
    } else {
        money - m - mm
    }
}

fn main() {
    println!("{}", buy_choco(vec![1,2,2], 3));
}
