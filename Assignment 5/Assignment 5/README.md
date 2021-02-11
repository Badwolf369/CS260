# Assignment 5: Auto Sorting List Operations


## Struct node
#### Attributes
##### int *value*
value contained within the node.

##### node* *parent* = nullptr
Parent of the current node. When equals null that means this node is the root.

##### node* *link_l* = nullptr
Link to the left half of the tree. All included nodes are less than this node.

##### node* *link_r* = nullptr
Link to the right half of the tree. All included nodes are greater than this one.


## Smart List
List that intelligently locates where to place a given number so the list may remain sorted for binary sort.

#### Private Attributes
##### node* root
Number near the center of the list to begin search.

#### Public Functions
##### node* find(int value)
Check the root. If it matches *value*, return that node. Otherwise, go to the right link if its larger; the left link if its smaller. Check again.

##### insert(int value)
Use an algorithm similar to find(), however when it reaches a node  where it cannot continue due to null links, create a new node and attach it.

##### remove(int value)
No clue; need to implement the first two first.


## Tests
#### Structure itself
Manually create a SmartList, and verify within the memory viewer that the list works properly.

#### find()
Manually create a SmartList, then verify that the position returned is the correct one with the value.

#### insert()