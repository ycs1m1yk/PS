const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs").readFileSync(filePath).toString().trim();

var openingCount = 0;
var openingIdxs = [];
var pairs = [];
for (var i = 0; i < input.length; i++) {
  if (input[i] === "(") {
    openingCount++;
    openingIdxs.push(i);
  } else if (input[i] === ")") {
    pairs.push([openingIdxs.pop(), i]);
  }
}

var bits = [];
const bitLength = pairs.length;
for (var i = 1; i < Math.pow(2, bitLength); i++) {
  bits.push(i.toString(2).padStart(bitLength, 0));
}

var ans = new Set();
var inputArr = Array(...input);
for (const bit of bits) {
  var deletingIdxs = [];
  for (var i = 0; i < bitLength; i++) {
    if (+bit[i]) {
      deletingIdxs.push(pairs[i][0]);
      deletingIdxs.push(pairs[i][1]);
    }
  }
  const expression = inputArr.filter((v, i, a) => {
    return deletingIdxs.indexOf(i) === -1;
  });
  ans.add(expression.join(""));
}
console.log([...ans].sort().join("\n"));
