#include <string>

#ifndef HELPERS_H_INCLUDE
#define HELPERS_H_INCLUDE

string alphabet_conversion(string oldAlphabet, string newAlphabet, string number) {
	if (newAlphabet.length() < oldAlphabet.length()) {
		/*
		get the length of the number (len)
		get the value of the first digit (c); the value of c is determined using a string containing the entire predefined "alphabet" and then using the function String::find() to get its position in the alphabet, which is its value
		get the base (b), determined by the length of the alphabet
		create a variable (total)
		loop till we reach the end:
			total += c*(b^len-1)
			len -= 1
			c = next letter
		*/

		int len = number.length();
		for (int i = 0; i < number.length(); i++, len--) {

		}
	}
	else if (newAlphabet.length() > oldAlphabet.length()) {
		//expand the number into base 10
		int total = 0;
		int val;
		for (int i = 0; i < number.length(); i++) {
			total += oldAlphabet.find(number[i]);
			total *= oldAlphabet.length();
		}

	}
	else {
		return number;
	}
}

#endif
