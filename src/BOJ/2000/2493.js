const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n");

const N = +input[0];
var heightsMap = [[1e8 + 1, 0]].concat(
  input[1].split(" ").map((el) => [+el, 0])
);

for (var i = 1; i <= N; i++) {
  const cur = heightsMap[i][0];
  if (heightsMap[i - 1][0] > cur) heightsMap[i][1] = i - 1;
  else {
    var target = heightsMap[i - 1][1];
    while (target) {
      if (heightsMap[target][0] > cur) {
        break;
      }
      target = heightsMap[target][1];
    }
    heightsMap[i][1] = target;
  }
}

const ans = heightsMap.map((el) => el[1]);
ans.shift();
console.log(ans.join(" "));
