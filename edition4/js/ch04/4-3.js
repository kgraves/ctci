function Node(value, left, right) {
  this.value = value;
  this.left = left;
  this.right = right;
}

function binSearch(lo, hi, array) {
  if (lo > hi) return null;

  var curr = Math.ceil((hi + lo) / 2);
  var node = new Node(array[curr]);

  node.left = binSearch(lo, curr-1, array);
  node.right = binSearch(curr+1, hi, array);

  return node;
}

function printTree(root) {
  if (!root) return;

  printTree(root.left);
  console.log(root.value);
  printTree(root.right);
};

function main() {
  var a = [1,2,3,4,5,6,7,8,9,10];
  // var root = null;

  var root = binSearch(0, a.length-1, a);
  printTree(root);
}

main();
