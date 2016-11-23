var STATES = {
  UNVISITED: 'unvisited',
  VISITED: 'visited',
  VISITING: 'visiting',
};

var Node = function(adjacent, state) {
  this.adjacent = adjacent;
  this.state = state || STATES.UNVISITED;
};

var search = function(start, end) {
  var q = []; // queue
  start.state = STATES.VISITING;
  q.push(start);
  var curr = null;

  while(q.length > 0) {
    curr = q.pop();

    if (curr != null) {
      for (var i=0; i<curr.adjacent.length; i++) {
        var n = curr.adjacent[i];

        if (n.state == STATES.UNVISITED) {
          if (n == end) {
            return true;
          } else {
            n.state = STATES.VISITING;
            q.push(n);
          }
        }
      };

      curr.state = STATES.VISITED;
    }
  }

  return false;
};

/**
  *     2 -- 3
 * 1 -< 4 -- 5
  *     6 -- 7
 */
var n3 = new Node([]);
var n2 = new Node([n3]);

var n5 = new Node([]);
var n4 = new Node([n5]);

var n7 = new Node([]);
var n6 = new Node([n7]);

var n1 = new Node([n2, n4, n6]);


console.log('is there a route b/w start and end? ' + search(n1, n4));
