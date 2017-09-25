## Homework I
Данная домашняя работа посвящена изучению шаблонов и работы с классами.

## Tasks
- [x] Реализовать шаблонный класс `stack`, со следующим интерфейсом:

## Tutorial

```ShellSession
template <typename T>
class stack
{
public:
    stack();
    size_t count() const;
    void push(T const &);
    T pop();
private:
    T * array_;
    size_t array_size_;
    size_t count_;
};
```
## Terminal message
```ShellSession
MOSCOW

194
333
910
248
640
502
```
