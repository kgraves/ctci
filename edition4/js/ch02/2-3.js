function Node(data, next) {
  this.data = data;
  this.next = next;
};

function removeNode(n) {
  if (!n || !n.next) {
    return false;
  } else {
    n.data = n.next.data;
    n.next = n.next.next;
    return true;
  }
}

// tests
var assert = require('assert');

describe('removeNode', function() {

  it('should fail when n is falsy', function() {
    assert.equal(removeNode(null), false);
  });

  it('should fail when n.next is falsy', function() {
    var n = new Node(1, null);
    assert.equal(removeNode(n), false);
  });

  it('should succeed when n is the first node in a list', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.equal(removeNode(head), true);
    assert.equal(head.data, n1.data);
    assert.equal(head.next, n1.next);
  });

  it('should succeed when n is in the middle of a list', function() {
    var n3 = new Node('4', null);
    var n2 = new Node('3', n3);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.equal(removeNode(n1), true);
    assert.equal(n1.data, n2.data);
    assert.equal(n1.next, n2.next);
  });

  it('should succeed when n is the second to last in a list', function() {
    var n3 = new Node('4', null);
    var n2 = new Node('3', n3);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.equal(removeNode(n2), true);
    assert.equal(n2.data, n3.data);
    assert.equal(n2.next, n3.next);
  });

});
