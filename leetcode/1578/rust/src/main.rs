pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
    let mut dp = 0;
    let mut former = None;
    for now_i in 0..colors.len() {
        match former {
            None => {
                former = Some(now_i);
            },
            Some(former_i) => {
                let former_char = colors.as_bytes()[former_i] as char;
                let now_char = colors.as_bytes()[now_i] as char;
                if former_char == now_char {
                    if needed_time[former_i] < needed_time[now_i] {
                        dp = dp + needed_time[former_i];
                        former = Some(now_i);
                    } else {
                        dp = dp + needed_time[now_i];
                    }
                } else {
                    former = Some(now_i);
                }
            },
        }
        // println!("{} {}", now_i, dp);
    }
    dp
}

fn main() {
    println!("{}", min_cost("aabaa".to_string(), vec![1,2,3,4,1]));
}
