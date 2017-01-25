function Node(value, left, right) {
  this.value = value;
  this.left = left;
  this.right = right;
}

function createLists(root, lists, depth) {
  if (!root) return;

  lists[depth] = lists[depth] || [];
  lists[depth].push(root.value);
  createLists(root.left, lists, depth+1);
  createLists(root.right, lists, depth+1);
}

function main() {
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
  var lists = [];

  createLists(root, lists, 0);
  console.log(lists);
}

main();
