//Koshkina_Uliana

using namespace std;

template <typename T>
class Stack {
public:
    Stack() {
    	array_size_ = 100;
	    array_ = new T[array_size_];
	};
template <typename T>
   Stack<T> :: Stack() : array_size_(_size), array_ (new T[array_size_]),count_(0) {}

    void push(T const &item) {
    	if(count_ == array_size_) {
			T* new_array_ = new T[array_size_*2];
			for(size_t i = 0; i < array_size_; i++) {
				new_array_[i] = array_[i];
			}
			array_size_ = array_size_ * 2;

			delete[] array_;
			array_ = new_array_;

		} else {
			array_[count_++] = item;
		}
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
