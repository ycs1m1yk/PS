const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const infix = require("fs").readFileSync(filePath).toString().trim();

const open = "(";
const close = ")";
const isp = { "(": 0, "+": 1, "-": 1, "*": 2, "/": 2 }; // in-stack precedence
const icp = { "(": 3, "+": 1, "-": 1, "*": 2, "/": 2 }; // incoming precedence

var postfix = [];
var stack = [];
for (const e of infix) {
  if (e >= "A" && e <= "Z") {
    postfix.push(e);
  } else if (e === close) {
    while (stack[stack.length - 1] != open) {
      postfix.push(stack.pop());
    }
    stack.pop();
  } else {
    if (!stack.length) {
      stack.push(e);
    } else {
      var top = stack[stack.length - 1];
      while (isp[top] >= icp[e]) {
        postfix.push(stack.pop());
        top = stack[stack.length - 1];
      }
      stack.push(e);
    }
  }
}
while (stack.length) {
  postfix.push(stack.pop());
}
console.log(postfix.join(""));
