const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const N = Number(require("fs").readFileSync(filePath).toString().trim());

let fiveCount = 0;
for (let i = 5; i <= N; i *= 5) {
  fiveCount += parseInt(N / i);
}
console.log(fiveCount);
