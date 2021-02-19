# Assignment 6: Binary Search Tree
## node
Primary data structure used in conjunction with BiTree.
#### Attributes
##### int *id*
Integer value contained within the node to allow for the searching and sorting within the tree.

##### int *value*
Integer value contained within the node that contains the information being stored.

##### node* *parent* = nullptr
Parent of the current node. When equals nullptr that means this node is the root. (or that the tree is broken)

##### node* *link_l* = nullptr
Link to the left half of the tree. All following nodes are less than the current node.

##### node* *link_r* = nullptr
Link to the right half of the tree. All following nodes are greater than the current node.


## BinaryTree
Linked List that intelligently locates where to place a given number so the tree may remain sorted for binary search.

#### Private Attributes
##### node* root = nullptr
Number at the top of the tree to begin all algorithms.

#### Public Functions
##### node* find(int value)
Check the root. If it matches *value*, return that node. If it desnt, go to the right link if its larger and the left link if its smaller. Repeat.

##### int insert(int value)
Use an algorithm similar to find(), however when it reaches a node  where it cannot continue due to null links, create a new node and attach it. Throws an error if you try to put an item in that already exists.

##### int remove(int value)
No clue; need to implement the first two first.

## Testing
### Testing states  
- State 1: empty  
NULL

- State 2: 1 item  
1

- State 3: consecutive numbers  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5  
&nbsp;&nbsp;&nbsp;&nbsp;4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1
- State 4: unconsecutive numbers  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;&nbsp;4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0

#### Testing functions
##### print_state()
prints the current tree in the same form as on the README  

##### set_state_*()
* is replaced with one of the testing states above. A tree is manually created to match that state.

### Tests
#### Structure itself
Manually create a BinaryTree, and verify within the memory viewer that the tree works properly.

#### find()
- **Test 1: find item not in tree**  
tree state: state 3  
input: 9  
output: error
- **Test 2: find root**  
starting state: state 3  
input: 4  
output: 4
- **Test 3: find item in middle layers**  
starting state: state 3  
input: 6  
output: 6
- **Test 4: find item on a final layer**  
starting state: state 3  
input: 3  
output: 3
- **Test 5: find item in empty tree**
starting state: state 1
input: 1
output: error

#### insert()
- **Test 1: insert item in empty tree**  
starting state: state 1  
final state:  
1  
input:  1
output: 0
- **Test 2: insert item already in tree**  
starting state: state 3
final state: unchanged  
input: 3  
output: 1
- **Test 3: insert item into gap so it has to shift items**  
starting state: state 4  
final state:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;8  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;&nbsp;4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0  
input: 8  
output: success
- **Test 4: insert item at final layer**  
starting state:  state 3
final state:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;8
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5  
&nbsp;&nbsp;&nbsp;&nbsp;4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1  
input: 8  
output: 0
