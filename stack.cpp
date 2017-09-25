//Koshkina_Uliana_stack

#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class Stack {
public:
    Stack() : array_size_(100), count_(0) { //стек из 100 элементов, 0 элементов в стеке
	    array_ = new T[array_size_]; //выделение памяти под элементы
	};

    Stack(size_t _size) : array_size_(_size), count_(0) { //крнструктор с размерностью
	    array_ = new T[array_size_];
	};

    size_t count() const { //метод(функция), возвращающий кол-во элементов в стеке
    	return count_;
    };

    void push(T const &item) { //"заполнение"
    	if(count_ == array_size_) {
			T* new_array_ = new T[array_size_*2]; //выделяем память (новую)
			for(int i = 0; i < array_size_; i++) {
				new_array_[i] = array_[i]; //переносим данные в новый массив из старого
			}
			array_size_ = array_size_ * 2;

			delete[] array_; //удаляем старый массив
			array_ = new_array_; // указание на новый массив

			array_[count_++] = item;
		} else {
			array_[count_++] = item; //добавляем значения в массив
		}
	};

    T pop() {
		if(count_ == 0) throw runtime_error("Warning: stack's empty..."); //"исключение", если выход за пределы массива
		return array_[--count_];
	};

    ~Stack() {
	    delete[] array_;
	};

private:
    T* array_;
    size_t array_size_;
    size_t count_;
};


int main() {
	srand(time(NULL));
	try {
		Stack<char> StackChar(2); //обЪект класса Stack, тип char, размерность 2
		StackChar.push('W'); //начинаем добавлять элементы
		StackChar.push('O');
		StackChar.push('C');
		StackChar.push('S');
		StackChar.push('O');
		StackChar.push('M');

		size_t _StackChar_count = StackChar.count();
		for(size_t i = 0; i < _StackChar_count; i++) { //удаление элементов
			cout << StackChar.pop();
		}

		cout << endl << endl;

		Stack<int> StackInt; //обЪект класса Stack, тип int, размерность 2
		for(int i = 0; i < 6; i++) {
			StackInt.push(1+rand()%999); //рандомный счетчик цифр
		}

		size_t _StackInt_count = StackInt.count();
		for(size_t i = 0; i < _StackInt_count; i++) {
			cout << StackInt.pop() << endl; //удаление
		}

	} catch(const exception& e) {
		cout << endl << e.what() << endl; //"ловим исключенияы"
	}
}
