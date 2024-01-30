pub fn eval_rpn(tokens: Vec<String>) -> i32 {
    let mut stack: Vec<String> = Vec::new();
    for s in tokens.iter() {
        match s.as_str() {
            "+" => {
                let a = stack.pop().unwrap().parse::<i32>().unwrap();
                let b = stack.pop().unwrap().parse::<i32>().unwrap();
                stack.push((a + b).to_string());
            }
            "-" => {
                let a = stack.pop().unwrap().parse::<i32>().unwrap();
                let b = stack.pop().unwrap().parse::<i32>().unwrap();
                stack.push((b - a).to_string());
            }
            "*" => {
                let a = stack.pop().unwrap().parse::<i32>().unwrap();
                let b = stack.pop().unwrap().parse::<i32>().unwrap();
                stack.push((a * b).to_string());
            }
            "/" => {
                let a = stack.pop().unwrap().parse::<i32>().unwrap();
                let b = stack.pop().unwrap().parse::<i32>().unwrap();
                stack.push((b / a).to_string());
            }
            _ => {
                stack.push(s.to_string());
            }
        }
        // println!("{:?}", stack);
    }
    stack.pop().unwrap().parse::<i32>().unwrap()
}

fn main() {
    println!(
        "{}",
        eval_rpn(vec![
            "4".to_string(),
            "13".to_string(),
            "5".to_string(),
            "/".to_string(),
            "+".to_string()
        ])
    );
}
