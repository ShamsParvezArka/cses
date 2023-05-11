use std::io;

fn parse_vec_i32() -> Vec<i32> {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let vector: Vec<i32> = input.trim()
        .split_whitespace()
        .into_iter()
        .map(|e| e.trim().parse().unwrap())
        .collect();

    return vector
}

fn parse_vec_char() -> Vec<char> {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let vector: Vec<char> = input.trim()
        .chars()
        .filter(|e| *e != ' ')
        .collect();

    return vector
}

fn main() {
    let raw: Vec<i32> = parse_vec_i32();
    let raw_char: Vec<char> = parse_vec_char();
    println!("{:?}", raw);
    println!("{:?}", raw_char);
}

