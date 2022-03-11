const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const N = Number(require("fs").readFileSync(filePath).toString().trim());

if (N === 0) {
  console.log(0);
  process.exit();
}

let twoCount = 0,
  fiveCount = 0;
for (let i = 1; i <= N; i++) {
  let iCopy = i;
  while (iCopy % 2 === 0) {
    iCopy /= 2;
    twoCount++;
  }
  while (iCopy % 5 === 0) {
    iCopy /= 5;
    fiveCount++;
  }
}
console.log(Math.min(twoCount, fiveCount));
