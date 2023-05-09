use std::io;
use std::collections::HashSet;

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let mut set: HashSet<i32> = HashSet::new();
    for e in input.split(',') {
        if set.contains(&e.parse().unwrap()) {
            println!("true");
            return 
        } else {
            set.insert(e.parse().unwrap());
        }
    }
    println!("false");
}








