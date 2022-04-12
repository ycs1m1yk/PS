const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

/**
 * processing input
 */
const [N, M] = input[0].split(" ").map((el) => +el);
const initialMap = [...Array(N)].map((v, i, a) =>
  input[i + 1].split(" ").map((el) => +el)
);
const dirLenPairs = [...Array(M)].map((v, i, a) =>
  input[i + N + 1].split(" ").map((el) => +el)
);

// ←, ↓, →, ↑ : 반시계방향
const dr = [0, 1, 0, -1];
const dc = [-1, 0, 1, 0];
// ↑, ↓, ←, → : 입력받은 d
const dr2 = [-1, 1, 0, 0];
const dc2 = [0, 0, -1, 1];

class GridMap {
  constructor(initialMap, n) {
    this.map = [...initialMap];
    this.rowLength = n;
    this.center = [(n - 1) / 2, (n - 1) / 2];
    this.flatten = [];
    this.explodedMarblesCount = [0, 0, 0];
  }

  printMap() {
    let result = "";
    for (const row of this.map) {
      result += row.join(" ") + "\n";
    }
    console.log(result);
  }

  // map을 중심에서부터 반시계반향으로 flat
  flatFromCenterCCW() {
    let flatten = [];
    let direction = 0;
    let distance = 1;
    let [r, c] = this.center;
    while (c !== -1) {
      for (let i = 0; i < Math.floor(distance); i++) {
        r = r + dr[direction];
        c = c + dc[direction];
        if (c === -1) {
          break;
        }
        if (this.map[r][c] !== 0) {
          flatten.push(this.map[r][c]);
        }
      }
      direction = (direction + 1) % 4;
      distance += 0.5;
    }
    this.flatten = [...flatten];
  }

  remapFromFlatten() {
    let newMap = [...Array(this.rowLength)].map(() =>
      Array(this.rowLength).fill(0)
    );
    let direction = 0;
    let distance = 1;
    let [r, c] = this.center;
    let flattenIdx = 0;
    while (flattenIdx < this.flatten.length) {
      for (let i = 0; i < Math.floor(distance); i++) {
        r = r + dr[direction];
        c = c + dc[direction];
        newMap[r][c] = this.flatten[flattenIdx];
        flattenIdx += 1;
        if (flattenIdx === this.flatten.length) {
          break;
        }
      }
      direction = (direction + 1) % 4;
      distance += 0.5;
    }
    this.map = [...newMap];
  }

  // 블리자드 마법 시전 후: phase1
  updateAfterBlizzard(d, s) {
    let [r, c] = this.center;
    for (let i = 0; i < s; i++) {
      r = r + dr2[d - 1];
      c = c + dc2[d - 1];
      this.map[r][c] = 0;
    }
    this.flatFromCenterCCW();
  }

  // 4개이상 연속된 구슬 폭발: phase2
  updateAfterExplosion() {
    let newFlatten = [];
    let target = this.flatten[0];
    let length = 1;
    let hasMoreThanFourStraightMarbles = false;

    // 마지막 구슬까지 처리하기 위해서
    this.flatten.push(0);
    for (let i = 1; i < this.flatten.length; i++) {
      const now = this.flatten[i];
      if (now === target) {
        length += 1;
      } else {
        if (length >= 4) {
          hasMoreThanFourStraightMarbles = true;
          // 폭발한 구슬 카운트
          this.explodedMarblesCount[target - 1] += length;
        } else {
          for (let cnt = 0; cnt < length; cnt++) {
            newFlatten.push(target);
          }
        }
        target = now;
        length = 1;
      }
    }
    this.flatten = [...newFlatten];
    if (hasMoreThanFourStraightMarbles) {
      this.updateAfterExplosion();
    }
  }

  // 구슬 변화: phase3
  updateAfterMarbleChange() {
    let newFlatten = [];
    let target = this.flatten[0];
    let length = 1;

    // 마지막 구슬까지 처리하기 위해서
    this.flatten.push(0);
    for (let i = 1; i < this.flatten.length; i++) {
      const now = this.flatten[i];
      if (now === target) {
        length += 1;
      } else {
        newFlatten.push(length);
        newFlatten.push(target);

        target = now;
        length = 1;
      }
    }
    const limit = this.rowLength * this.rowLength - 1;
    this.flatten = [...newFlatten].slice(0, limit);
    this.remapFromFlatten();
  }
}

const gridMap = new GridMap(initialMap, N);

for (const [d, s] of dirLenPairs) {
  // phase 1
  gridMap.updateAfterBlizzard(d, s);
  // phase 2
  gridMap.updateAfterExplosion();
  // phase 3
  gridMap.updateAfterMarbleChange();
}

[cnt1, cnt2, cnt3] = gridMap.explodedMarblesCount;
console.log(1 * cnt1 + 2 * cnt2 + 3 * cnt3);
