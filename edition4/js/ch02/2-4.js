function Node(data, next) {
  this.data = data;
  this.next = next;
};

function listToNumber(head) {
  var num = 0;
  var place = 0;
  var curr = head;

  while (curr) {
    num += curr.data * (Math.pow(10, place));

    curr = curr.next
    place += 1;
  }

  return num;
}

function add(head1, head2) {
  return listToNumber(head1) + listToNumber(head2);
}

// tests
var assert = require('assert');

describe('add', function() {

  it('should return 0 when given to null pointers', function() {
    var actual = add(null, null);
    assert.equal(actual, 0);
  });

  it('should add two numbers when given a null point and one list', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head = new Node('1', n1);

    var actual = add(head, null);
    assert.equal(actual, 321);
  });

  it('should add two numbers when given two lists', function() {
    var n2 = new Node('3', null);
    var n1 = new Node('2', n2);
    var head1 = new Node('1', n1);

    var n3 = new Node('3', null);
    var n4 = new Node('2', n2);
    var head2 = new Node('1', n1);

    var actual = add(head1, head2);
    assert.equal(actual, 642);
  });

});
