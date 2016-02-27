function Node(data, next) {
  this.data = data;
  this.next = next;
};

function findLoopBeginning(head) {
  var n1 = head;
  var n2 = head;

  while (n2.next !== null) {
    n1 = n1.next;
    n2 = n2.next.next;

    if (n1.data === n2.data) {
      break;
    }
  }

  if (!n2.next) {
    return null;
  }

  n1 = head;
  while (n1 !== n2) {
    n1 = n1.next;
    n2 = n2.next;
  }

  return n1;
}

// tests
var assert = require('assert');

describe('findLoopBeginning', function() {

  it('should fail when there is no loop', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);

    var actual = findLoopBeginning(head);
    assert.equal(actual, null);
  });

  it('should succeed and return the start when there is a loop', function() {
    var n9 = new Node('3', null);
    var n8 = new Node('2', n9);
    var n7 = new Node('1', n8);
    var n6 = new Node('3', n7);
    var n5 = new Node('2', n6);
    var n4 = new Node('1', n5);
    var n3 = new Node('3', n4);
    var n2 = new Node('2', n3);
    var n1 = new Node('1', n2);
    var head = new Node('0', n1);
    n9.next = n4;

    var actual = findLoopBeginning(head);
    assert.equal(actual, n4);
  });

});
