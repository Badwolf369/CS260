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
Check the root. If it matches *value*, return that node. If it desnt, recurse to the right link if its larger and the left link if its smaller.

##### node* insert(int value)
Use an algorithm similar to find(), however when it reaches a node  where it cannot continue due to null links, create a new node and attach it. Throws an error if you try to put an item in that already exists.  

##### node* remove(int value)
Find the node using the exact same algorithm as find(), then do one of the following:
- If the node has no children, just delete it no problem.  
- If the node has a single child, then the child will replace the node.
- If the node has 2 children, find what is called an in-order successor, which for this is the lowest number in the right side of the tree. the in-order successor will then replace the deleted node, and the deleted node's children become the successors's children.  

Thankyou to Geeks for Geeks for the help with the deletion methods, especially the the third method.
https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/


## Testing
### Testing states  
- State 1: empty  
NULL

- State 2: 1 item  
1

- State 3: consecutive numbers

                /7
            /6
                \5
        4
                /3
            \2
                \1
- State 4: unconsecutive numbers

                /9
            /7
                \6
        4
                /3
            \1
                \0
- State 5: missing children
                    
                
            /6
                \5
        4
                
            \2
                

#### Testing functions
##### print_state()
prints the current tree in the same form as on the README  

##### set_state_*()
* is replaced with one of the testing states above. A tree is manually created to match that state.

### Tests
#### Structure itself
Manually create a BinaryTree, and verify within the memory viewer that the tree works properly.

#### find()
- **Test 1: find item in empty tree**  
starting state: state 1  
input: 1  
output: error
- **Test 2: find item not in tree**  
tree state: state 3  
input: 9  
output: error
- **Test 3: find root**  
starting state: state 3  
input: 4  
output: 4
- **Test 4: find item in middle layers**  
starting state: state 3  
input: 6  
output: 6
- **Test 5: find item on a final layer**  
starting state: state 3  
input: 3  
output: 3

#### insert()
- **Test 1: insert item in empty tree**  
starting state: state 1  
final state:  
1  
input:  1
output: error
- **Test 2: insert item already in tree**  
starting state: state 3
final state: unchanged  
input: 3  
output: 3
- **Test 3: insert item normally**  
starting state:  state 3
final state:

                    /8  
                /7  
            /6  
                \5  
        4  
                /3  
            \2  
                \1  
input: 8  
output: 8

#### remove()
- **Test 1: Remove item from empty list**  
starting state: state 1  
final state: unchanged  
input: 1  
output: error
- **Test 2: Remove item that doesnt exist in list**  
starting state: state 3  
final state: unchanged  
input: 8  
output: error
- **Test 3: Remove item with no children**  
starting state: state 5  
final state:
 
            /6
        4  
            \2
input: 5  
output: 5
- **Test 4: Remove item with 1 child**  
starting state: state 5  
final state:   

            /5
        4
            \2
input: 6  
output: 6
- **Test 5: Remove item with 2 children**  
starting state: state 3  
final state: 

            /6
        5  
            \2
input: 4  
output: 4
