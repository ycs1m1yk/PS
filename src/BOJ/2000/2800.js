const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = require("fs").readFileSync(filePath).toString().trim();

var openingCount = 0;
var openingIdxs = [];
var pairMap = new Map();
for (var i = 0; i < input.length; i++) {
  if (input[i] === "(") {
    openingCount++;
    openingIdxs.push(i);
  } else if (input[i] === ")") {
    pairMap.set(openingIdxs.pop(), i);
  }
}

var bits = [];
const bitLength = pairMap.size;
for (var i = 1; i < Math.pow(2, bitLength); i++) {
  bits.push(i.toString(2).padStart(bitLength, 0));
}

var output = new Set();
var inputArr = Array(...input);
for (const bit of bits) {
  var deletingIdxs = [];
  var bitIdx = 0;
  for (const [key, value] of pairMap) {
    if (bit[bitIdx++] === "1") {
      deletingIdxs.push(key);
      deletingIdxs.push(value);
    }
  }
  const expression = inputArr.filter((v, i, a) => {
    return deletingIdxs.indexOf(i) === -1;
  });
  output.add(expression.join(""));
}
console.log([...output].sort().join("\n"));
