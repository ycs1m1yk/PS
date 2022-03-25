const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [N, ...circles] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\n/);

var xIntercopts = [];
for (var i = 0; i < circles.length; i++) {
  const [x, r] = circles[i].split(" ").map(Number);
  xIntercopts.push(["l", i, x - r]);
  xIntercopts.push(["r", i, x + r]);
}
xIntercopts.sort((a, b) => a[2] - b[2]);

var stack = [];
for (const [lr, i, x] of xIntercopts) {
  if (lr === "l") {
    stack.push(i);
  } else {
    const top = stack[stack.length - 1];
    if (i === top) stack.pop();
    else {
      console.log("NO");
      process.exit();
    }
  }
}
console.log("YES");
