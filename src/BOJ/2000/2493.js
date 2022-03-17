const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const N = +input[0];
const towerHeights = input[1].split(" ").map((el) => +el);
var stack = [];
var ans = Array(N).fill(0);
for (var i = N - 1; i >= 0; i--) {
  while (
    stack.length &&
    towerHeights[i] > towerHeights[stack[stack.length - 1]]
  ) {
    ans[stack.pop()] = i + 1;
  }
  stack.push(i);
}

console.log(ans.join(" "));
