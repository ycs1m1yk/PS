const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [N, seq, M, ...questions] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

const sequence = [0].concat(seq.split(" "));
var cache = Array.from(Array(+N + 1), () => Array(+N + 1).fill(-1));

const dp = (S, E) => {
  if (sequence[S] != sequence[E]) {
    return (cache[S][E] = 0);
  }
  if (E - S <= 1) {
    return (cache[S][E] = 1);
  }
  if (cache[S][E] != -1) {
    return cache[S][E];
  }

  return (cache[S][E] = dp(S + 1, E - 1));
};

var ans = [];
for (const question of questions) {
  const [S, E] = question.split(" ").map((el) => +el);
  ans.push(dp(S, E));
}
console.log(ans.join("\n"));
