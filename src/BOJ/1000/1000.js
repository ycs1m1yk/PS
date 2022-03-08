let fs = require("fs");
let input = fs.readFileSync("test.txt").toString().split("\n");

const data = input[0].split(" ").map((el) => +el);
const A = data[0];
const B = data[1];

console.log(A + B);
