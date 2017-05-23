function Node(value, left, right) {
  this.value = value;
  this.left = left;
  this.right = right;
}

function isInSubtree(root, value) {
  // base cases
  if (!root) return false;
  if (root.value === value) return true;

  return isInSubtree(root.left, value) || isInSubtree(root.right, value);
}

/**
 * Find the fist common ancestor shared between v1, and v2.
 *
 * This algorithm assumes that both values exist in the given tree.
 */
function firstCommonAncestor(root, v1, v2) {
  if (isInSubtree(root.left, v1) && isInSubtree(root.left, v2)) {
    return firstCommonAncestor(root.left, v1, v2);
  }
  if (isInSubtree(root.right, v1) && isInSubtree(root.right, v2)) {
    return firstCommonAncestor(root.right, v1, v2);
  }

  // if v1 and v2 are not found on one side of root,
  // then root must straddle both values.
  return root.value;
}

// tests
var assert = require('assert');

describe('firstCommonAncestor', function() {
  var root = null;

  before(function() {
    // create binary tree
    var five = new Node(
      5,
      new Node(4),
      new Node(3)
    );
    var eight = new Node(
      8,
      new Node(6),
      null
    );
    root = new Node(1, five, eight);
  });

  it('should find the values', function() {
    assert.equal(firstCommonAncestor(root, 4, 3), 5);
    assert.equal(firstCommonAncestor(root, 4, 6), 1);
    assert.equal(firstCommonAncestor(root, 4, 8), 1);
    assert.equal(firstCommonAncestor(root, 6, 8), 8);
  });

});
