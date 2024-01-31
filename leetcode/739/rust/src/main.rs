pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
    let mut s = Vec::new();
    let mut answer = vec![0; temperatures.len()];
    for i in 0..temperatures.len() {
        while !s.is_empty() && temperatures[s[s.len() - 1]] < temperatures[i] {
            answer[s[s.len() - 1]] = i - s[s.len() - 1];
            s.pop();
        }
        s.push(i);
    }
    answer.iter().map(|x| *x as i32).collect()
}

fn main() {
    assert_eq!(daily_temperatures(vec![73,74,75,71,69,72,76,73]), vec![1,1,4,2,1,1,0,0]);
    assert_eq!(daily_temperatures(vec![30,40,50,60]), vec![1,1,1,0]);
    assert_eq!(daily_temperatures(vec![30,60,90]), vec![1,1,0]);
}
