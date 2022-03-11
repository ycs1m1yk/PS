const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs").readFileSync(filePath).toString().trim();

let answer = "";
for (let i = 0; i < input.length; i++) {
  if (i === 0) {
    answer = answer + parseInt(input[i], 8).toString(2);
  } else {
    answer = answer + parseInt(input[i], 8).toString(2).padStart(3, "0");
  }
}
console.log(answer);
