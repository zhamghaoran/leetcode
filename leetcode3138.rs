fn main() {
    println!("{}", Solution::min_anagram_length(String::from("abba")));
}
struct Solution {}

impl Solution {
    pub fn min_anagram_length(s: String) -> i32 {
        let n = s.len();
        let check = |step: usize| -> bool{
            let mut count1 = vec![0; 26];
            for i in (0..n).step_by(step) {
                let mut count2 = vec![0; 26];
                for j in (i..i + step) {
                    count2[s.as_bytes()[j] as usize - 'a' as usize] += 1;
                }
                if i > 0 && count2 != count1 {
                    return false;
                }
                count1 = count2;
            }
            true
        };
        for i in 1..n {
            if n % i != 0 {
                continue;
            }
            if check(i) {
                return i as i32;
            }
        }
        n as i32
    }
}
