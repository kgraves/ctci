function Node(data, next) {
  this.data = data;
  this.next = next;
};

function findNthToLast(head, n) {
  if (!head || !n || n < 0) {
    return null;
  } else {
    var tail = head;
    var i = 0;

    while (i<n-1) {
      if (!tail.next) {
        return null;
      }

      tail = tail.next;
      i += 1;
    }

    var target = head;
    while (tail.next) {
      tail = tail.next;
      target = target.next;
    }

    return target;
  }
}

// tests
var assert = require('assert');

describe('findNthToLast', function() {

  it('should fail when n is falsy', function() {
    assert.equal(findNthToLast({}, undefined), null);
    assert.equal(findNthToLast({}, -1), null);
  });

  it('should fail when head is falsy', function() {
    assert.equal(findNthToLast(undefined, -1), null);
    assert.equal(findNthToLast(null, -1), null);
    assert.equal(findNthToLast(), null);
  });

  it('should succeed and find the last node', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.deepEqual(findNthToLast(head, 1), n2);
  });

  it('should succeed and find the 2nd to last node', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.deepEqual(findNthToLast(head, 2), n1);
  });

  it('should succeed and find head', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.deepEqual(findNthToLast(head, 3), head);
  });

});
