// https://www.nowcoder.com/practice/8a7bff7ab0d345d5ac5c82e41d9f7115

function fizzBuzz(num) {
    if (typeof num != "number") {
        return false;
    } else if (num % 15 === 0) {
        return "fizzbuzz";
    } else if (num % 3 === 0) {
        return "fizz";
    } else if (num % 5 === 0) {
        return "buzz";
    }
    return num;
}