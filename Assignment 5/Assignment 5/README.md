# Assignment 5: Auto Sorting List Operations
## Struct node
#### Attributes
##### int *value*
value contained within the node.

##### node* *parent* = nullptr
Parent of the current node. When equals nullptr that means this node is the root. (or that the list is broken)

##### node* *link_l* = nullptr
Link to the left half of the tree. All included nodes are less than this node.

##### node* *link_r* = nullptr
Link to the right half of the tree. All included nodes are greater than this one.


## Smart List
List that intelligently locates where to place a given number so the list may remain sorted for binary sort.

#### Private Attributes
##### node* root = nullptr
Number near the center of the list to begin search.

#### Public Functions
##### node* find(int value)
Check the root. If it matches *value*, return that node. If it desnt, go to the right link if its larger; the left link if its smaller. Check again.

##### int insert(int value)
Use an algorithm similar to find(), however when it reaches a node  where it cannot continue due to null links, create a new node and attach it. Throws an error if you try to put an item in that already exists

##### int remove(int value)
No clue; need to implement the first two first.

## Testing
### Testing states  
- State 1: empty  
NULL

- State 2: 1 item  
1

- State 3: consecutive list  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5  
&nbsp;&nbsp;&nbsp;&nbsp;4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1
- State 4: unconsecutive list  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;9  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;6  
&nbsp;&nbsp;&nbsp;&nbsp;4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0

#### Testing functions
##### print_state()
prints the current list in the same form as we use it here    
 
### Tests
#### Structure itself
Manually create a SmartList, and verify within the memory viewer that the list works properly.

#### find()
- **Test 1: find item not in list**  
list state: state 3  
input: 9  
output: error
- **Test 2: find root**  
list state: state 3  
input: 4  
output: 4
- **Test 3: find item in middle layers**  
list state: state 3  
input: 6  
output: 6
- **Test 4: find item on a final layer**  
list state: state 3  
input: 3  
output: 3
- **Test 5: find item in empty list**
list state: state 1
input: 1
output: error

#### insert()
- **Test 1: insert item in empty list**  
starting list state: state 1  
final list state:  
1  
input:  1
output: 0  
- **Test 2: insert item already in list**  
starting list state: state 3
final list state: unchanged  
input: 3  
output: 1  
- **Test 3: insert item into gap so it has to shift items**  
starting list state: state 4  
final list state:  
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
starting list state:  state 3
final list state:  
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
