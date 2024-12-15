use std::collections::{BTreeMap, HashMap};

fn main() {
    let arr = vec![7, 7, 7, 7, 7, 7];
    println!("{}", min_set_size(arr));
}

fn min_set_size(arr: Vec<i32>) -> i32 {
    let mut ans = 0;
    let size = arr.len();
    let mut tem = 0;
    let mut map: HashMap<i32, i32> = HashMap::new();
    for i in arr {
        *map.entry(i).or_default() += 1;
    }
    let mut vec: Vec<_> = map.iter().collect();
    vec.sort_by(|a, b| b.1.cmp(a.1));
    for i in vec {
        tem += i.1;
        ans += 1;
        if tem >= (size / 2) as i32 {
            break;
        }
    }
    ans
}