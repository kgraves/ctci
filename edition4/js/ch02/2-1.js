function Node(data, next) {
  this.data = data;
  this.next = next;
};

function deleteNode(head, target) {

  if (head === target) {
    // head is target, set head to second element and return
    head = head.next;
  } else {
    // start at the second element
    var curr = head.next;
    var prev = head;
    // prev = curr;
    // curr = curr.next;

    while(curr) {
      if (curr === target) {
        prev.next = curr.next;
      }

      prev = curr;
      curr = curr.next;
    }
  }

  return head;
}

/**
 * Deletes duplicates from list with an additional buffer.
 */
function deleteDups(head) {
  var buffer = {};
  var curr = head;

  while(curr) {
    if (buffer[curr.data]) {
      head = deleteNode(head, curr);
    } else {
      buffer[curr.data] = curr;
    }

    curr = curr.next
  }

  return head;
}

// tests
var assert = require('assert');

describe('deleteNode', function() {

  it('should delete the head', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    head = deleteNode(head, head);
    assert.equal(head.data, n1.data);
  });

  it('should delete the node', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    head = deleteNode(head, n1);
    assert.equal(head.next.data, n2.data);
  });

});

describe('deleteDups', function() {

  it('should not delete anything', function() {
    var n3 = new Node('4', null);
    var n2 = new Node('3', n3);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    assert.deepEqual(deleteDups(head), head);
  });

  it('should delete duplicates', function() {
    var n3 = new Node('3', null);
    var n2 = new Node('2', n3);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);
    head = deleteDups(head);
    assert.equal(head.data, '1');
    assert.equal(head.next.data, '2');
    assert.equal(head.next.next.data, '3');
  });

  it('should delete everything but head', function() {
    var n3 = new Node('1', null);
    var n2 = new Node('1', n3);
    var n1 = new Node('1', n2);
    var head = new Node('1', n1);
    head = deleteDups(head);
    assert.equal(head.data, '1');
    assert.equal(head.next, null);
  });

});
