const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const N = +fs.readFileSync(filePath).toString().trim();
let cache = Array(N + 1).fill(-1);

function dp(width) {
  if (width === 2) return (cache[width] = 3);
  if (cache[width] !== -1) return cache[width];

  cache[width] = dp(width - 2) + 2;
  for (let i = 2; i <= width - 2; i += 2) cache[width] += 2 * dp(i);

  return cache[width];
}

if (N % 2 === 1) console.log(0);
else console.log(dp(N));
