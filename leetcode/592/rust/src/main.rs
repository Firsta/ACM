#[derive(Debug)]
struct Fraction {
    nominator: i32,
    denominator: i32,
}

fn gcd(mut n: i32, mut m: i32) -> i32 {
    assert!(n != 0 && m != 0);
    while m != 0 {
        if m < n {
            std::mem::swap(&mut m, &mut n);
        }
        m %= n;
    }
    n
}

impl Fraction {
    pub fn new(s: &str) -> Self {
        let ps: Vec<&str> = s.split('/').collect();
        Self {
            nominator: ps[0].parse().unwrap(),
            denominator: ps[1].parse().unwrap(),
        }
    }

    pub fn zero() -> Self {
        Self {
            nominator: 0,
            denominator: 1,
        }
    }

    pub fn add(self, f: Fraction) -> Self {
        Self {
            nominator: self.nominator * f.denominator + f.nominator * self.denominator,
            denominator: self.denominator * f.denominator,
        }
    }

    pub fn sub(self, f: Fraction) -> Self {
        Self {
            nominator: self.nominator * f.denominator - f.nominator * self.denominator,
            denominator: self.denominator * f.denominator,
        }
    }

    pub fn gcd(self) -> Self {
        if self.nominator == 0 {
            Self {
                nominator: 0,
                denominator: 1,
            }
        } else {
            let n = self.nominator.abs();
            let m = self.denominator;
            let g = gcd(n, m);
            Self {
                nominator: self.nominator / g,
                denominator: self.denominator / g,
            }
        }
    }

    pub fn to_string(&self) -> String {
        format!(
            "{}/{}",
            self.nominator.to_string(),
            self.denominator.to_string()
        )
    }
}

pub fn fraction_addition(expression: String) -> String {
    let parts: Vec<&str> = expression
        .as_str()
        .split(|c: char| c == '+' || c == '-')
        .collect();

    // println!("{:?}", parts);

    let signs: Vec<char> = expression
        .as_str()
        .chars()
        .filter(|c| *c == '+' || *c == '-')
        .collect();

    // println!("{:?}", signs);

    let mut pi = 0;
    let mut si = 0;

    let mut sum = Fraction::zero();

    if parts[pi].is_empty() {
        pi += 1;
        sum = sum.sub(Fraction::new(parts[pi]));
        pi += 1;
        si += 1;
    } else {
        sum = sum.add(Fraction::new(parts[pi]));
        pi += 1;
    }

    while pi < parts.len() {
        sum = match signs[si] {
            '+' => sum.add(Fraction::new(parts[pi])),
            '-' => sum.sub(Fraction::new(parts[pi])),
            _ => panic!(),
        };
        pi += 1;
        si += 1;
    }

    sum.gcd().to_string()
}

fn main() {
    assert_eq!(fraction_addition("1/3-1/2".to_string()), "-1/6".to_string());
}
