const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [str, M, ...commands] = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/(?! )\s/);

let lString = Array.from(str);
let rString = [];

// ** shift, unshift는 O(n)이므로 rString에 push, pop 연산 후 .reverse.join("")
for (const command of commands) {
  const [cmd, input] = command.split(" ");
  if (cmd === "L") {
    if (lString.length) {
      rString.push(lString.pop());
    }
    continue;
  }
  if (cmd === "D") {
    if (rString.length) {
      lString.push(rString.pop());
    }
    continue;
  }
  if (cmd === "B") {
    if (lString.length) {
      lString.pop();
    }
    continue;
  }
  if (cmd === "P") {
    lString.push(input);
    continue;
  }
}
console.log(lString.join("") + rString.reverse().join(""));
