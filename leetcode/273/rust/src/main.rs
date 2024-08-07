use std::collections::HashMap;

fn foo1(seg: &str) -> String {
    match seg {
        "1" => "One".to_string(),
        "2" => "Two".to_string(),
        "3" => "Three".to_string(),
        "4" => "Four".to_string(),
        "5" => "Five".to_string(),
        "6" => "Six".to_string(),
        "7" => "Seven".to_string(),
        "8" => "Eight".to_string(),
        "9" => "Nine".to_string(),
        _ => panic!(),
    }
}

fn foo2(seg: &str) -> String {
    if seg.chars().nth(1).unwrap() == '0' {
        return match seg.chars().nth(0).unwrap() {
            '1' => "Ten".to_string(),
            '2' => "Twenty".to_string(),
            '3' => "Thirty".to_string(),
            '4' => "Forty".to_string(),
            '5' => "Fifty".to_string(),
            '6' => "Sixty".to_string(),
            '7' => "Seventy".to_string(),
            '8' => "Eighty".to_string(),
            '9' => "Ninety".to_string(),
            _ => panic!(),
        };
    }
    if seg.chars().nth(0).unwrap() == '1' {
        match seg {
            "10" => "Ten".to_string(),
            "11" => "Eleven".to_string(),
            "12" => "Twelve".to_string(),
            "13" => "Thirteen".to_string(),
            "14" => "Fourteen".to_string(),
            "15" => "Fifteen".to_string(),
            "16" => "Sixteen".to_string(),
            "17" => "Seventeen".to_string(),
            "18" => "Eighteen".to_string(),
            "19" => "Nineteen".to_string(),
            _ => panic!(),
        }
    } else {
        let mut ret = match seg.chars().nth(0).unwrap() {
            '2' => "Twenty".to_string(),
            '3' => "Thirty".to_string(),
            '4' => "Forty".to_string(),
            '5' => "Fifty".to_string(),
            '6' => "Sixty".to_string(),
            '7' => "Seventy".to_string(),
            '8' => "Eighty".to_string(),
            '9' => "Ninety".to_string(),
            _ => panic!(),
        };
        ret.push_str(&" ".to_string());
        ret.push_str(&foo1(&seg[1..]));
        ret
    }
}

fn foo3(seg: &str) -> String {
    let mut ret = foo1(&seg[0..1]);
    ret.push_str(&" Hundred".to_string());
    let t = seg[1..].parse::<i32>().unwrap().to_string();
    if t != "0".to_string() {
        match t.len() {
            0 => (),
            1 => {
                ret.push_str(&" ".to_string());
                ret.push_str(&foo1(&t));
            }
            2 => {
                ret.push_str(&" ".to_string());
                ret.push_str(&foo2(&t));
            }
            _ => panic!(),
        }
    }

    ret
}

pub fn number_to_words(num: i32) -> String {
    if num == 0 {
        return "Zero".to_string();
    }
    let s = HashMap::from([(0, ""), (1, "Thousand"), (2, "Million"), (3, "Billion")]);

    let num_str = num.to_string();
    let n = num_str.len();

    let mut v = Vec::new();

    let mut seg = String::new();
    for i in (0..n).rev() {
        seg.push(num_str.as_bytes()[i] as char);
        if seg.len() == 3 {
            seg = seg.chars().rev().collect::<String>();
            seg = seg.parse::<i32>().unwrap().to_string();

            if seg != "0".to_string() {
                v.push(match seg.len() {
                    1 => foo1(&seg),
                    2 => foo2(&seg),
                    3 => foo3(&seg),
                    _ => panic!(),
                });
            } else {
                v.push("".to_string());
            }
            // println!("{}", seg);
            seg.clear();
        }
    }
    if seg.len() > 0 {
        seg = seg.chars().rev().collect::<String>();
        seg = seg.parse::<i32>().unwrap().to_string();
        v.push(match seg.len() {
            1 => foo1(&seg),
            2 => foo2(&seg),
            3 => foo3(&seg),
            _ => panic!(),
        });
    }

    // println!("{}", seg);

    // println!("{:?}", v);

    let mut v = v
        .into_iter()
        .enumerate()
        .map(|(i, x)| {
            if x.is_empty() {
                return x;
            }
            if i > 0 {
                format!("{} {}", x, s.get(&i).unwrap())
            } else {
                x
            }
        })
        .collect::<Vec<String>>();

    v.reverse();

    // println!("{:?}", v);

    // println!("{}", foo3(&"100"));
    // println!("{}", foo3(&"101"));
    // println!("{}", foo3(&"112"));
    // println!("{}", foo3(&"131"));

    v.into_iter()
        .filter(|x| !x.is_empty())
        .collect::<Vec<String>>()
        .join(" ")
        .trim()
        .to_string()
}
fn main() {
    assert_eq!(number_to_words(1000010), "One Million Ten".to_string());
}
