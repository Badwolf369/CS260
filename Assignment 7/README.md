# Assignment 7: Hashtable
### Helper functions
#### String b63_to_long(String number)
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
The hash function I use is an interesting one. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63) which will return the exact index for the code. Because we do not have room to make a list that could contain *all* possible keys as that would be basically infinite, the function will return the index of the first 3 digits.

#### Insert(String key)
Converts the first 3 digits of *key* into a long, then overwrites the item at that index with the new value.  


#### Contains


#### Delete

## Smart hash table
#### Hash function:
Exactly the same hash function as the simple table. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63). The difference here is in storing the numbers. They will be stored as a binary search tree, rather than an array, allowing us to store an infinite number of keys and values. Horribly inneficient? Yup. Dont have to deal with collisions? Also yup.

#### Insert

#### Contains

#### Delete
