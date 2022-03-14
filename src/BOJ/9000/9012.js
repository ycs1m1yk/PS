const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [T, ...psArr] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\r|\n/);

for (const ps of psArr) {
  if (ps.length % 2) {
    console.log("NO");
  } else {
    let pStack = [];
    for (const p of ps) {
      if (p === "(") pStack.push(p);
      else {
        if (pStack.length) pStack.pop();
        else {
          pStack.push(p);
          break;
        }
      }
    }
    console.log(pStack.length ? "NO" : "YES");
  }
}
