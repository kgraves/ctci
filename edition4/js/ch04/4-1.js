var Node = function(value, left, right) {
  this.value = value;
  this.left = left || null;
  this.right = right || null;
};

var printTree = function(root) {
  if (!root) return;

  printTree(root.left);
  console.log(root.value);
  printTree(root.right);
};

var minDepth = function(root) {
  if (!root) return 0;

  return 1 + Math.min(minDepth(root.left), minDepth(root.right));
};

var maxDepth = function(root) {
  if (!root) return 0;

  return 1 + Math.max(minDepth(root.left), minDepth(root.right));
};

var isBalanced = function(root, depth) {
  return maxDepth(root) - minDepth(root) <= 1;
};

var two = new Node(
  2,
  new Node(1),
  new Node(3)
);
var six = new Node(
  6,
  new Node(5),
  new Node(7)
);
var root = new Node(4, two, six);

console.log('tree is balanced? ' + isBalanced(root) );
