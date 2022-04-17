const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const stdin = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);
const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

const matFuncs = [
  null,
  (mat) => [...mat].reverse(),
  (mat) => mat.map((row) => [...row].reverse()),
  (mat) => {
    const n = mat.length;
    const m = mat[0].length;
    const newMat = [...Array(m)].map(() => [...Array(n)]);
    for (let c = 0; c < n; c++) {
      for (let r = 0; r < m; r++) {
        newMat[r][c] = mat[n - 1 - c][r];
      }
    }
    return newMat;
  },
  (mat) => matFuncs[3](matFuncs[3](matFuncs[3](mat))),
  (mat) => {
    const halfN = mat.length / 2;
    const halfM = mat[0].length / 2;
    const top = mat.slice(0, halfN);
    const bottom = mat.slice(halfN);
    const section1 = top.map((row) => row.slice(0, halfM));
    const section2 = top.map((row) => row.slice(halfM));
    const section3 = bottom.map((row) => row.slice(halfM));
    const section4 = bottom.map((row) => row.slice(0, halfM));

    /**
     * 1 2 -> 4 1
     * 4 3    3 2
     */
    return [
      ...section4.map((row, i) => [...row, ...section1[i]]),
      ...section3.map((row, i) => [...row, ...section2[i]]),
    ];
  },
  (mat) => matFuncs[5](matFuncs[5](matFuncs[5](mat))),
];

// 연산줄이는 함수
const reducer = (arr) => {
  const nArr = arr.reduce((nArr, el) => {
    if (el === 4) return nArr.concat(3, 3, 3);
    if (el === 6) return nArr.concat(5, 5, 5);
    return nArr.concat(el);
  }, []);
  let reduced = [nArr[0]];
  let isReduced = false;
  let s = 0;
  let e = 0;
  while (e++ < nArr.length - 1) {
    if (nArr[s] === nArr[e]) reduced.push(nArr[e]);
    else {
      // 연산 1,2는 2번마다 원점, 3-6은 4번마다 원점
      const divisor = nArr[s] <= 2 ? 2 : 4;
      const times = Math.floor((e - s) / divisor);
      if (times && !((e - s) % divisor)) isReduced = true;
      for (let i = 0; i < divisor * times; i++) reduced.pop();

      s = e;
      reduced.push(nArr[s]);
    }
  }

  if (isReduced) {
    reduced = [...reducer(reduced)];
  }
  return reduced;
};

const [N, M, R] = input().split(" ").map(Number);
const mat = [...Array(N)].map(() => [...input().split(" ").map(Number)]);
const cmds = input().split(" ").map(Number);
const reducedCmds = reducer(cmds);
const resultMat = reducedCmds.reduce(
  (resultMat, cmd) => matFuncs[cmd](resultMat),
  mat
);
const ans = resultMat.reduce((str, row) => (str += row.join(" ") + "\n"), "");
console.log(ans);
