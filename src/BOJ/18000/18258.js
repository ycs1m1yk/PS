const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const [N, ...commands] = require("fs")
  .readFileSync(filePath)
  .toString()
  .trim()
  .split(/\r\n|\r|\n/);

class Node {
  constructor(item, next = null) {
    this.item = item;
    this.next = next;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  /**
   * @param {*} item
   */
  push(item) {
    const node = new Node(item);
    if (!this.head) {
      this.head = node;
      this.tail = this.head;
    } else {
      this.tail.next = node;
      this.tail = this.tail.next;
    }
    this.size += 1;
  }

  /**
   * @return {*}
   */

  pop() {
    if (this.head) {
      const headItem = this.head.item;
      let temp = new Node(0, this.head.next);
      this.head = null;
      this.head = temp.next;
      temp = null;

      this.size -= 1;

      return headItem;
    }
    return -1;
  }

  /**
   * @return {boolean}
   */
  empty() {
    return !this.head;
  }

  /**
   * @return {item}
   */
  front() {
    if (this.empty()) return -1;
    return this.head.item;
  }

  /**
   * @return {item}
   */
  back() {
    if (this.empty()) return -1;
    return this.tail.item;
  }
}

let queue = new Queue();
let output = [];
for (const line of commands) {
  const [command, value] = line.split(" ");
  switch (command) {
    case "push":
      queue.push(value);
      break;
    case "pop":
      output.push(queue.pop());
      break;
    case "size":
      output.push(queue.size);
      break;
    case "empty":
      output.push(queue.empty() ? 1 : 0);
      break;
    case "front":
      output.push(queue.front());
      break;
    case "back":
      output.push(queue.back());
      break;
  }
}
console.log(output.join("\n"));
