const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

// 12시 방향부터 시계방향으로 8개 방향
const dr = [-1, -1, 0, 1, 1, 1, 0, -1];
const dc = [0, 1, 1, 1, 0, -1, -1, -1];

let T = +input[0];
let inputIdx = 1;
let ans = "";
while (T--) {
  const [N, D] = input[inputIdx++].split(" ").map((el) => +el);
  const X = [...Array(N)].map(() => [
    ...input[inputIdx++].split(" ").map((el) => +el),
  ]);
  const newX = [...X].map((row) => [...row]);

  const cr = (N - 1) / 2;
  const cc = (N - 1) / 2;
  const delta = (D / 45 + 8) % 8;
  for (let i = 1; i <= (N - 1) / 2; i++) {
    for (let d = 0; d < 8; d++) {
      const r = cr + i * dr[d];
      const c = cc + i * dc[d];
      const nr = cr + i * dr[(d + delta) % 8];
      const nc = cc + i * dc[(d + delta) % 8];
      newX[nr][nc] = X[r][c];
    }
  }

  for (const row of newX) {
    ans += row.join(" ") + "\n";
  }
}
console.log(ans);
