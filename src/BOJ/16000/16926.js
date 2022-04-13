const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

const [N, M, R] = input[0].split(" ").map((el) => +el);
const initialMap = [...Array(N)].map((v, i, a) =>
  input[i + 1].split(" ").map((el) => +el)
);

// ↓, →, ↑, ← : 반시계방향
const dr = [1, 0, -1, 0];
const dc = [0, 1, 0, -1];

const checkBoundOut = (r, c, rlb, rub, clb, cub) => {
  return r < rlb || r > rub || c < clb || c > cub;
};

const updatePosAndDir = (r, c, d) => {
  let [nr, nc, nd] = [r, c, d];
  nr -= dr[nd];
  nc -= dc[nd];
  nd = (nd + 1) % 4;
  nr += dr[nd];
  nc += dc[nd];

  return [nr, nc, nd];
};

const resultMap = [...Array(N)].map(() => [...Array(M).fill(0)]);
const rounds = Math.min(N, M) / 2;
// solve
for (let round = 0; round < rounds; round++) {
  const rowLowerBound = round;
  const colLowerBound = round;
  const rowUpperBound = N - 1 - round;
  const colUpperBound = M - 1 - round;
  const len = 2 * (N - round + (M - round)) - 4;

  const distanceFromBegin = R % len;
  let r = round;
  let c = round;
  let direction = 0;
  // 시작점 변경
  for (let i = 0; i < distanceFromBegin; i++) {
    r += dr[direction];
    c += dc[direction];
    if (
      checkBoundOut(
        r,
        c,
        rowLowerBound,
        rowUpperBound,
        colLowerBound,
        colUpperBound
      )
    ) {
      [r, c, direction] = updatePosAndDir(r, c, direction);
    }
  }
  // 한바퀴 원소 기록
  let nr = round;
  let nc = round;
  let nDirection = 0;
  for (let i = 0; i < len; i++) {
    resultMap[r][c] = initialMap[nr][nc];
    // resultMap
    r += dr[direction];
    c += dc[direction];
    if (
      checkBoundOut(
        r,
        c,
        rowLowerBound,
        rowUpperBound,
        colLowerBound,
        colUpperBound
      )
    ) {
      [r, c, direction] = updatePosAndDir(r, c, direction);
    }

    // initialMap
    nr += dr[nDirection];
    nc += dc[nDirection];
    if (
      checkBoundOut(
        nr,
        nc,
        rowLowerBound,
        rowUpperBound,
        colLowerBound,
        colUpperBound
      )
    ) {
      [nr, nc, nDirection] = updatePosAndDir(nr, nc, nDirection);
    }
  }
}
let ans = "";
for (const row of resultMap) {
  ans += row.join(" ") + "\n";
}
console.log(ans);
