const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [num, ...input] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

const N = +num;
const arr = input.map((el) => el.split(" ").map(Number));
const dr = [-1, 0, 1, 0]; // up, right, down, left
const dc = [0, 1, 0, -1];

// 교실 자리 맵: (r,c) = 학생넘버
const classMap = [...Array(N)].map(() => new Array(N).fill(0));
// 인접한 빈자리 맵: (r,c) = 인접 빈자리의 수
const adjEmptyMap = [...Array(N)].map(() => [
  3,
  ...[...Array(N - 2)].map(() => 4),
  3,
]);
adjEmptyMap[0] = adjEmptyMap[0].map((el) => el - 1);
adjEmptyMap[N - 1] = adjEmptyMap[N - 1].map((el) => el - 1);

// 학생배열: [학생넘버, row, col]
let students = [];
const findPosOfStudent = (students, s) => {
  const index = students.findIndex((el) => el[0] === s);
  if (index === -1) {
    return [-1, -1];
  }
  const row = students[index][1];
  const col = students[index][2];
  return [row, col];
};

/**
 * 학생들 앉히기
 */
for (let i = 0; i < N * N; i++) {
  const [student, ...friends] = arr[i];
  // 첫번째 학생 앉히기
  if (i === 0) {
    classMap[1][1] = student;
    students.push([student, 1, 1]);
    for (let i = 0; i < 4; i++) {
      adjEmptyMap[1 + dr[i]][1 + dc[i]]--;
    }
    continue;
  }

  let maxFavorites = 0;
  const adjFavMap = [...Array(N)].map(() => new Array(N).fill(0));
  // 인접좋아요맵에 체크
  for (const f of friends) {
    const [r, c] = findPosOfStudent(students, f);
    if (r != -1) {
      for (let i = 0; i < 4; i++) {
        const nr = r + dr[i];
        const nc = c + dc[i];
        if (nr > -1 && nr < N && nc > -1 && nc < N && classMap[nr][nc] === 0) {
          adjFavMap[nr][nc]++;
          maxFavorites = Math.max(maxFavorites, adjFavMap[nr][nc]);
        }
      }
    }
  }
  const adjFavMapSpread = [].concat.apply([], adjFavMap);
  const posArr = [];
  let lastIndex = -1;
  // 인접좋아수 제일 높은 칸들 뽑기
  while (1) {
    lastIndex = adjFavMapSpread.indexOf(maxFavorites, lastIndex + 1);
    if (lastIndex === -1) {
      break;
    }
    const r = Math.floor(lastIndex / N);
    const c = lastIndex % N;
    // 빈자리만 추가
    if (classMap[r][c] === 0) posArr.push([r, c]);
  }
  // 자리후보 뽑기
  const candidates = []; // [인접빈칸수, row, col]
  for (const [r, c] of posArr) {
    candidates.push([adjEmptyMap[r][c], r, c]);
  }
  // sort([desc, inc, inc])
  candidates.sort((a, b) => {
    const left = b[0] * 100000 + a[1] * 1000 + a[0];
    const right = a[0] * 100000 + b[1] * 1000 + b[0];
    return left - right;
  });

  // 자리에 앉히기
  const [adjEmpty, fRow, fCol] = candidates[0];
  classMap[fRow][fCol] = student;
  students.push([student, fRow, fCol]);
  for (let i = 0; i < 4; i++) {
    const nr = fRow + dr[i];
    const nc = fCol + dc[i];
    if (nr > -1 && nr < N && nc > -1 && nc < N) {
      adjEmptyMap[nr][nc]--;
    }
  }
}

// 만족도의 총합 계산
let totalScore = 0;
for (let r = 0; r < N; r++) {
  for (let c = 0; c < N; c++) {
    const student = classMap[r][c];
    const friends = arr.find((el) => el[0] === student).slice(1);
    let favCnt = 0;
    for (let i = 0; i < 4; i++) {
      const nr = r + dr[i];
      const nc = c + dc[i];
      if (nr > -1 && nr < N && nc > -1 && nc < N) {
        if (friends.includes(classMap[nr][nc])) {
          favCnt++;
        }
      }
    }
    if (favCnt) {
      totalScore += Math.pow(10, favCnt - 1);
    }
  }
}

console.log(totalScore);
