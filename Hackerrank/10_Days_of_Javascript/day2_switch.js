'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function getLetter(s) {
    let letter;
    // Write your code here
    var set0 = new Set(['a','e','i','o','u']);
    var set1 = new Set(['b','c','d','f','g']);
    var set2 = new Set(['h','j','k','l','m']);
    if (set0.has(s[0])) {
        letter = 'A';
    } else if (set1.has(s[0])) {
        letter = 'B';
    } else if (set2.has(s[0])) {
        letter = 'C';
    } else {
        letter = 'D';
    }
    
    return letter;
}


function main() {
    const s = readLine();
    
    console.log(getLetter(s));
}