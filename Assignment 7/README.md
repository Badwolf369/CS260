# Assignment 7: Hashtable
### Helper functions
#### String change_base(String number, int curBase, int newBase)
pretty self explanatory, changes a number *number* from its current base *cur*

## Simple hash table
#### Hash function:
The hash function I use is an interesting one. It is going to convert bases, with the key being a number in base alphabet-length (a-z, A-Z, 0-9 and spaces would be base 63) which will return the exact index for the code. Because we do not have room to make a list that could contain *all* possible keys as that would be basically infinite, the function will return the index of the first 3 digits.

#### Insert


#### Contains

#### Delete

## Smart hash table
#### Hash function:
Almost exactly the same hash function as the simple table. It is going to convert bases, with the key being a number in base alphabet-length (a-z, 0-9 and spaces would be base 37). Because we do not have room to make a list that could contain *all* of these, since that would be almost 1.4*10^43 values, the function will return the index of the first 3 digits, al

#### Insert

#### Contains

#### Delete
