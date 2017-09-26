//Koshkina_Uliana

#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    Stack() : array_size_(size_t(100)), array_(new T[100]) {};

    Stack(size_t _size) : array_size_(_size), array_(new T[_size]) {};

    size_t count() const {
    	return count_;
    };

    void push(T const &item) {
    	if(count_ == array_size_) {
			T* new_array_ = new T[array_size_*2];
			for(size_t i = 0; i < array_size_; i++) {
				new_array_[i] = array_[i];
			}
			array_size_ = array_size_ * 2;

			delete[] array_;
			array_ = new_array_;
		}
		
		array_[count_++] = item;
	};

    T pop() {
		if(count_ == 0) throw runtime_error("Warning: stack's empty...");
		return array_[--count_];
	};

    ~Stack() {
	    delete[] array_;
	};

private:
    T* array_;
    size_t array_size_;
    size_t count_ = 0;
};