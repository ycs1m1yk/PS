const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [N, ...input] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

const meetings = input.map((el) => el.split(" ").map(Number));
meetings.sort((a, b) => {
  return a[1] === b[1] ? a[0] - b[0] : a[1] - b[1];
});

console.log(meetings);
var newBegin = -1;
var newEnd = -1;
var ans = 0;
for (const [begin, end] of meetings) {
  if (newEnd <= begin) {
    newBegin = begin;
    newEnd = end;
    ans++;
  }
}
console.log(ans);
