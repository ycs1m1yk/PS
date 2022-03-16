const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [N, arr] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\r|\n/);

const scores = arr.split(" ").map((el) => +el);
scores.sort((a, b) => b - a);

let highScore = scores[0];
let total = 0;
for (const score of scores) {
  total += (score / highScore) * 100;
}
const ans = total / +N;
console.log(ans);
