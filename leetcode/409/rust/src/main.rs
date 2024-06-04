use std::collections::HashMap;

pub fn longest_palindrome(s: String) -> i32 {
    let mut m = HashMap::new();

    for c in s.chars() {
        m.entry(c).and_modify(|e| *e += 1).or_insert(1);
    }

    let mut has_odd = false;
    let mut ans = 0;

    for v in m.values() {
        if v % 2 == 1 {
            has_odd = true;
            ans += *v - 1;
        } else {
            ans += *v
        }
    }

    if has_odd {
        ans += 1;
    }

    ans
}

fn main() {
    assert_eq!(longest_palindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth".to_string()), 983);
}
