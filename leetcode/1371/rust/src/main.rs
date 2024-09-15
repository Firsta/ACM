pub fn find_the_longest_substring(s: String) -> i32 {
    let mut h = std::collections::HashMap::new();
    h.insert(0, 0);
    let mut ans = 0;
    let mut p = 0;
    for (i, c) in s.chars().enumerate() {
        let i = i + 1;
        p = p ^ match c {
            'a' => 1 << 0,
            'e' => 1 << 1,
            'i' => 1 << 2,
            'o' => 1 << 3,
            'u' => 1 << 4,
            _ => 0,
        };
        let mut change = false;
        match h.get(&p) {
            None => {
                change = true;
            }
            Some(j) => {
                ans = std::cmp::max(ans, i - j);
            }
        }
        if change {
            h.insert(p, i);
        }
    }
    ans as i32
}

fn ok(s: &str) -> bool {
    let mut cnt = vec![0; 26];
    for c in s.chars() {
        cnt[c as usize - 'a' as usize] += 1;
    }
    for vowel in ['a', 'e', 'i', 'o', 'u'] {
        if cnt[vowel as usize - 'a' as usize] % 2 != 0 {
            println!("{}", vowel);
            return false;
        }
    }
    true
}

pub fn find_the_longest_substring2(s: String) -> i32 {
    let mut ans = 0;
    let n = s.len();

    for i in 0..n {
        for j in i..n {
            if ok(&s[i..=j]) {
                if j - i + 1 > ans {
                    println!("{} {}", i, j);
                    ans = j - i + 1;
                }
            }
        }
    }
    ans as i32
}

fn main() {
    assert_eq!( find_the_longest_substring("tyrwpvlifrgjghlcicyocusukhmjbkfkzsjhkdrtsztchhazhmcircxcauajyzlppedqyzkcqvffyeekjdwqtjegerxbyktzvrxwgfjnrfbwvhiycvoznriroroamkfipazunsabwlseseeiimsmftchpafqkquovuxhhkpvphwnkrtxuiuhbcyqulfqyzgjjwjrlfwwxotcdtqsmfeingsxyzbpvmwulmqfrxbqcziudixceytvvwcohmznmfkoetpgdntrndvjihmxragqosaauthigfjergijsyivozzfrlpndygsmgjzdzadsxarjvyxuecqlszjnqvlyqkadowoljrmkzxvspdummgraiutxxxqgotqnxwjwfotvqglqavmsnmktsxwxcpxhuujuanxueuymzifycytalizwnvrjeoipfoqbiqdxsnclcvoafqwfwcmuwitjgqghkiccwqvloqrxbfjuxwriltxhmrmfpzitkwhitwhvatmknyhzigcuxfsosxetioqfeyewoljymhdwgwvjcdhmkpdfbbztaygvbpwqxtokvidtwfdhmhpomyfhhjorsmgowikpsdgcbazapkmsjgmfyuezaamevrbsmiecoujabrbqebiydncgapuexivgvomkuiiuuhhbszsflntwruqblrnrgwrnvcwixtxycifdebgnbbucqpqldkberbovemywoaxqicizkcjbmbxikxeizmzdvjdnhqrgkkqzmspdeuoqrxswqrajxfglmqkdnlescbjzurknjklikxxqqaqdekxkzkscoipolxmcszbebqpsizhwsxklzulmjotkrqfaeivhsedfynxtbzdrviwdgicusqucczgufqnaslpwzjhgtphnovlrgz".to_string()), 831);
}
