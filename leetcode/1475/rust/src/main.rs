pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
    let mut prices = prices;
    for i in 0..prices.len() {
        for j in i + 1..prices.len() {
            if prices[j] <= prices[i] {
                prices[i] -= prices[j];
                break;
            }
        }
    }
    prices
}

fn main() {
    assert_eq!(final_prices(vec![8, 4, 6, 2, 3]), vec![4, 2, 4, 2, 3]);
}
