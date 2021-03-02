# Assignment 7: Hashtable
### Extra Things
#### Struct ***node***
Contains 7 variables.
*id* long containing the id, aka hash code, to find the node
*collisionCode* String containing the key of the node to be able to resolve collisions

*Value* integer containing the value of the node.  

*parent* node pointer pointing to the node attached one level up.  
*child_r* node pointer pointing to the node attached one level down with a higher id.  
*child_l* node pointer pointing to the node attached one level down with a lower id.  
*sibling* node pointer pointing to the node attached as a linked list to resolve collisions.

#### Binary Search Tree
Refer to the README in the `Assignment 6` folder

#### Helper functions
##### Long b63_to_long(String *number*)
Converts a number of base-63 to an unsigned long.
```
get the length of the number (len)
get the value of the first digit (c); the value of c is determined using a string containing the entire predefined "alphabet" and then using the function String::find() to get its position in the alphabet, which is its value
get the base (b), determined by the length of the alphabet
create a variable (total)
loop till we reach the end:
    total += c*(b^len-1)
    len -= 1
    c = next letter
```

## Simple hash table
#### Hash function:
The hash function I use is an interesting one. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63) which will return the exact index as the code. Because we do not have room to make a list that could contain *all* possible keys as that would be basically infinite, the function will return the index of the first 3 digits, and they will be mapped to a list with 16 items per slot when full.

##### Tests
#1: 1 digit
input: 'A'
output: 36

#2: 2 digits
input: An
output: 2291

#3: 3 digits
input: Ant
output: 83126

#4 4+ digits
input: Ants
output: 83126 (only first 3 digits)


#### Insert(string *key*, int *value*)
Converts the first 3 digits of *key* into a long, then overwrites the item at that index with *value*.

##### Tests
*using smaller array(9 slots) and alphabet("abc") and keys(2 digits) for testing*

#1: adding to empty slot
starting state: [x, x, x, x, x, x, x, x, x]
input: c, 2
output: 2
final state: [x, x, 2, x, x, x, x, x, x]

#2: overwriting collision
starting state: [x, x, 3, x, x, x, x, x, x]
input: c, 2
output: 2
final state: [x, x, 2, x, x, x, x, x, x]


#### Contains(string *key*)
Converts the first 3 digits of *key* into a long, then returns the nodeptr at that index. If the index is empty it returns null.

##### Tests
*using smaller array(9 slots) and alphabet("abc") and keys(2 digits) for testing*

#1: empty slot
starting state: [x, x, x, x, x, x, x, x, x]
input: c
output: empty

#2: non-empty slot
starting state: [1, 2, 3, 4, 5, 6, 7, 8, 9]
input: c
output: 3


#### remove(string *key*)
Converts the first 3 digits of *key* into a long, then sets the item at that index to nullptr.

##### Tests
*using smaller array(9 slots) and alphabet("abc") and keys(2 digits) for testing*

#1: deleting empty slot
starting state: [x, x, x, x, x, x, x, x, x]
input: c
output: error
final state: [x, x, x, x, x, x, x, x, x]

#2: overwriting collision
starting state: [1, 2, 3, 4, 5, 6, 7, 8, 9]
input: c
output: 3
final state: [1, 2, x, 4, 5, 6, 7, 8, 9]


## Smart hash table
#### Hash function
Exactly the same hash function as the simple table. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63). The difference here is in storing the numbers. They will be stored as a binary search tree, rather than an array, allowing us to store an infinite number of keys and values. Horribly inneficient? Yup. Dont have to deal with collisions? Also yup. Dynamic memory? Third Yup.  
It would be interesting to experiment with different hash functions that both allow dynamic memory while approaching the O(1) average case.
#### insert(String *key*, int *value*)
Converts the key into a long, then uses the **insert()** function from the BST to insert the item in the proper place. If a hash code already in the tree is entered, it will check the collision code. If the collision code matches *key*, then that node will be overwritten. If the collision code is different then it will check for a *sibling* node. If none exists, it creates one. If one exists it checks that node's collision code. Continues until a node is created or the matching collision code is found.
#### contains(String *key*)
Converts the key into a long, then uses the **find()** function from the BST to locate the proper item. Before returning anything, the collision code is checked. If it matches *key*, then that node is returned. If not then the *sibling* node will be checked. If *sibling* node is empty then it returns null.
#### remove(String *key*)
Same as **contains()**, but when the correct node is found, rather than merely returning it, it is saved for later and the BST **remove()** function is used on it, then the saved node is returned. The BST **remove()** function is slightly modified so that if sibling nodes exist, the eldest sibling node, the one right at the top, will replace the deleted node.
