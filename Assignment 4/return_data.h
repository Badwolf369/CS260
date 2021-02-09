#ifndef RETURN_DATA_INCLUDE
#define RETURN_DATA_INCLUDE

//trying something new with errors. Don't know if I like it
//found it on stack exchange here (the first answer by Peter): https://stackoverflow.com/questions/34701407/how-to-return-error-through-a-function-whose-return-type-is-int

struct return_data {
	int value = 0;
	short error = 0;
};

#endif