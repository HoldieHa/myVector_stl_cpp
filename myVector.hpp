#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include <iostream>
#include <initializer_list>

#define __SIZE_ALLOCATE (5ULL)
#define __DEFAULT_VALUE (0U)
#define __ERROR_VALUE (0xFFFFU)

template<class T>
class myVector
{
private:
    size_t sz;
    size_t capa;
    T* ptr;

    void reallocateArr(void);
public:
    class myIterator;
    myVector(void);
    myVector(std::initializer_list<T> ls);
    myVector(const size_t sz, const T value);
    myVector(const size_t sz);
    myVector(const myVector& src);
    ~myVector();
    size_t size(void);
    size_t capacity(void);
    bool empty(void);
    T& front(void);
    T& back(void);
    T* data(void);
    T& at(const size_t index);
    T& operator[](const size_t index);
    myIterator begin(void);
    myIterator end(void);
    void insert(const myIterator& iterator, const T data);
    void push_back(const T data);
    void push_front(const T data);
    void erease(myVector<T>::myIterator iterator);
    void erease(myVector<T>::myIterator start_iter, myVector<T>::myIterator end_iter);
    void clear(void);
    void display(void);
};

template<class T>
class myVector<T>::myIterator
{
public:
    T* ptr_iter;
public:
    explicit myIterator(T* p = nullptr);
    ~myIterator();
    T& operator*(void) const;
    myIterator operator+(const unsigned int num) const;
    int operator-(const myIterator& iter) const;
    myIterator operator-(const unsigned int num) const;
    myIterator operator++(void);
    myIterator operator--(void);
    bool operator>=(const myIterator& iter) const;
    bool operator>(const myIterator& iter) const;
    bool operator<=(const myIterator& iter) const;
    bool operator<(const myIterator& iter) const;
    bool operator!=(const myIterator& iter) const;
};

#include "myVector.tpp"

#endif /* _MY_VECTOR_H_ */
