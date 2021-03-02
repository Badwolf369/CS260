# Assignment 7: Hashtable
### Extra Things
#### Struct ***node***
Contains x variables.
*id* long containing the id, aka hash code, to find the node
*collisionCode* String containing the key of the node to be able to resolve collisions

*Value* integer containing the value of the node.  
*parent* node pointer pointing to the node attached one level up.  
*child_r* node pointer pointing to the node attached one level down with a higher id.  
*child_l* node pointer pointing to the node attached one level down with a lower id.  
*sibling* node pointer pointing to the node attached as a linked list to resolve collisions.

#### Binary Search Tree
Refer to the README in the `Assignment 6` folder

### Helper functions
#### String b63_to_long(String *number*)
Converts a number of base-63 to an unsigned long.
```
get the length of the number (len)
get the value of the first digit (c)
get the base (b)
create a variable (total)
loop till we reach the end:
    total += c*(b^len-1)
    len -= 1
    c = next letter
```

## Simple hash table
#### Hash function:
The hash function I use is an interesting one. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63) which will return the exact index as the code. Because we do not have room to make a list that could contain *all* possible keys as that would be basically infinite, the function will return the index of the first 3 digits.

#### Insert(String *key*, int *value*)
Converts the first 3 digits of *key* into a long, then overwrites the item at that index with *value*.

#### Contains(String *key*)
Converts the first 3 digits of *key* into a long, then returns the nodeptr at that index. If the index is empty it returns null.

#### Delete
Converts the first 3 digits of *key* into a long, then sets the item at that index to nullptr.

## Smart hash table
#### Hash function
Exactly the same hash function as the simple table. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63). The difference here is in storing the numbers. They will be stored as a binary search tree, rather than an array, allowing us to store an infinite number of keys and values. Horribly inneficient? Yup. Dont have to deal with collisions? Also yup. Dynamic memory? Third Yup.  
It would be interesting to experiment with different hash functions that both allow dynamic memory while approaching the O(1) average case.
#### insert(String *key*, int *value*)
Converts the key into a long, then uses the **insert()** function from the BST to insert the item in the proper place. If a hash code already in the tree is entered, it will check the collision code. If the collision code matches *key*, then that node will be overwritten. If the collision code is different then it will check for a *sibling* node. If none exists, it creates one. If one exists it checks that node's collision code. Continues until a node is created or the matching collision code is found.
#### contains(String *key*)
Converts the key into a long, then uses the **find()** function from the BST to locate the proper item. Before returning anything, the collision code is checked. If it matches *key*, then that node is returned. If not then the *sibling* node will be checked. If *sibling* node is empty then it returns null.
#### delete(String *key*)
Same as Contains, but when the correct node is found, rather than merely returning it, it is saved for later and the BST **remove()** function is used on it, then the saved node is returned. The BST **remove()** function is slightly modified so that if sibling nodes exist, the eldest sibling node, the one right at the top, will replace the deleted node.
