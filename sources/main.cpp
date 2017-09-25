//Koshkina_Uliana

#include "stack.hpp"
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	try {
		Stack<char> StackChar(2);
		StackChar.push('W');
		StackChar.push('O');
		StackChar.push('C');
		StackChar.push('S');
		StackChar.push('O');
		StackChar.push('M');

		size_t _StackChar_count = StackChar.count();
		for(size_t i = 0; i < _StackChar_count; i++) {
			cout << StackChar.pop();
		}

		cout << endl << endl;

		Stack<int> StackInt;
		for(int i = 0; i < 6; i++) {
			StackInt.push(1+rand()%999);
		}

		size_t _StackInt_count = StackInt.count();
		for(size_t i = 0; i < _StackInt_count; i++) {
			cout << StackInt.pop() << endl;
		}

	} catch(const exception& e) {
		cout << endl << e.what() << endl;
	}
}