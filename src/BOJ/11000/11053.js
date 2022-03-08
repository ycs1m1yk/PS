const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [n, ...arr] = fs.readFileSync(filePath).toString().trim().split(/\s/);

function getLowerBound(begin, end, key, ...s) {
  let mid;
  while (begin < end) {
    mid = Math.floor((begin + end) / 2);
    if (s[mid] < key) {
      begin = mid + 1;
      continue;
    }
    end = mid;
  }

  let ret = Math.floor((begin + end) / 2);
  return key <= s[ret] ? ret : end + 1;
}

let series = [0];
for (let i = 0; i < arr.length; i++) {
  let key = +arr[i];
  if (series[series.length - 1] < key) series.push(key);
  else {
    let lb = getLowerBound(0, series.length - 1, key, ...series);
    if (lb !== series.length) series[lb] = key;
  }
}

console.log(series.length - 1);
