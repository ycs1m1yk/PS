const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const N = Number(require("fs").readFileSync(filePath).toString().trim());

const MOD = 1e7;
var factorialNum = 1;
for (var i = 1; i <= N; i++) {
  factorialNum *= i;
  factorialNum %= MOD;
  if (i % 5 === 0) {
    var expOfTen = 0;
    var iCopy = i;
    while (iCopy % 5 === 0) {
      iCopy /= 5;
      expOfTen++;
    }
    factorialNum /= Math.pow(10, expOfTen);
  }
}
console.log(factorialNum % 10);
