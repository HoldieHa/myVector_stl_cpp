/****************************************------VECTOR------*******************************************************************/
template<typename T>
void myVector<T>::reallocateArr(void)
{
    T* ptr_tmp = new T[capa + __SIZE_ALLOCATE];

    for (auto i = 0; i < capa; i++)
    {
        ptr_tmp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = ptr_tmp;
    capa += __SIZE_ALLOCATE;
}

template<class T>
myVector<T>::myVector(void) : sz{0U}, capa{1U}
{
    ptr = new T[capa];
}

template<typename T>
myVector<T>::myVector(std::initializer_list<T> ls) : sz{ls.size()}, capa{ls.size() + __SIZE_ALLOCATE}
{
    size_t index = 0;

    ptr = new T[capa];
    for (auto element : ls)
    {
        *(ptr + index) = element;
        ++index;
    }
}

template<typename T>
myVector<T>::myVector(const size_t sz, const T value) : sz{sz}, capa{sz + __SIZE_ALLOCATE}
{
    size_t index = 0;

    ptr = new T[capa];
    for (index = 0; index < sz; index++)
    {
        ptr[index] = value;
    }
}

template<typename T>
myVector<T>::myVector(const size_t sz) : myVector(sz, (T)__DEFAULT_VALUE) {};

template<typename T>
myVector<T>::myVector(const myVector& src)
{
    ptr = new T[sz];

    for (auto element : src.ptr)
    {
        *ptr = element;
    }
}

template<typename T>
myVector<T>::~myVector()
{
    delete[] ptr;
}

template<typename T>
bool myVector<T>::empty(void)
{
    return (sz == 0U);
}

template<typename T>
size_t myVector<T>::size(void)
{
    return sz;
}

template<typename T>
size_t myVector<T>::capacity(void)
{
    return capa;
}

template<typename T>
T* myVector<T>::data(void)
{
    return ptr;
}

template<typename T>
T& myVector<T>::front(void)
{
    return at(0);
}

template<typename T>
T& myVector<T>::back(void)
{
    return at(sz - 1U);
}

template<typename T>
T& myVector<T>::operator[](const size_t index)
{
    return *(begin() + index);
}

template<typename T>
T& myVector<T>::at(const size_t index)
{
    if ((index >= 0) && (index < sz))
    {
        return ptr[index];
    }
    else
    {
        std::cout << "Error: position is out of vector" << std::endl;
        exit(0);
    }
}

template<typename T>
typename myVector<T>::myIterator myVector<T>::begin(void)
{
    return myIterator(ptr);
}

template<typename T>
typename myVector<T>::myIterator myVector<T>::end(void)
{
    return begin() + sz;
}

template<typename T>
void myVector<T>::insert(const myIterator& iterator, const T data)
{
    if ((iterator <= end()) && (iterator >= begin()))
    {
        auto range = 0;
        myIterator iter(iterator.ptr_iter);

        if (sz == capa)
        {
            range = iterator.ptr_iter - begin().ptr_iter;
            reallocateArr();
            iter = begin() + range;
        }
        for (auto iter_tmp = end(); iter_tmp != iter; --iter_tmp)
        {
            *(iter_tmp) = *(iter_tmp - 1U);
        }
        ++sz;
        *(iter) = data;
    }
    else
    {
        std::cout << "Error: position is out of vector" << std::endl;
        exit(0);
    }
}

template<typename T>
void myVector<T>::push_front(const T data)
{
    insert(begin(), data);
}

template<typename T>
void myVector<T>::push_back(const T data)
{
    if (sz == capa)
    {
        reallocateArr();
    }
    ptr[sz] = data;
    ++sz;
}

template<typename T>
void myVector<T>::erease(myVector<T>::myIterator iterator)
{
    if ((iterator < end()) && (iterator >= begin()))
    {
        for (auto iter_tmp = iterator; iter_tmp != end(); ++iter_tmp)
        {
            *(iter_tmp) = *(iter_tmp + 1U);
        }
        --sz;
    }
    else
    {
        std::cout << "Error: position is out of vector" << std::endl;
        exit(0);
    }
}

template<typename T>
void myVector<T>::erease(myVector<T>::myIterator start_iter, myVector<T>::myIterator end_iter)
{
    auto range = end_iter - start_iter;

    if ((start_iter < end()) && (start_iter >= begin()) && (end_iter < end()) && (end_iter >= begin()))
    {
        for (auto iter_tmp = start_iter; (iter_tmp + range) != end(); ++iter_tmp)
        {
            *(iter_tmp) = *(iter_tmp + range);
        }
        sz -= range;
    }
    else
    {
        std::cout << "Error: position is out of vector" << std::endl;
        exit(0);
    }
}

template<typename T>
void myVector<T>::clear(void)
{
    sz = 0;
}

template<typename T>
void myVector<T>::display(void)
{
    std::cout << "[ ";
    for (auto i = 0; i < sz; ++i)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

/****************************************------ITERATOR------*******************************************************************/

template<typename T>
myVector<T>::myIterator::myIterator(T* p) : ptr_iter{p} {};

template<typename T>
myVector<T>::myIterator::~myIterator(void) {}

template<typename T>
T& myVector<T>::myIterator::operator*(void) const
{
    return *ptr_iter;
}

template<typename T>
typename myVector<T>::myIterator myVector<T>::myIterator::operator+(const unsigned int num) const
{
    myIterator tmp(ptr_iter);
    tmp.ptr_iter = ptr_iter + num;
    return tmp;
}

template<typename T>
int myVector<T>::myIterator::operator-(const myIterator& iter) const
{
    int range = ptr_iter - iter.ptr_iter;
    return range;
}

template<typename T>
typename myVector<T>::myIterator myVector<T>::myIterator::operator-(const unsigned int num) const
{
    myIterator tmp(ptr_iter);
    tmp.ptr_iter = ptr_iter - num;
    return tmp;
}

template<typename T>
typename myVector<T>::myIterator myVector<T>::myIterator::operator++(void)
{
    ++ptr_iter;
    return *this;
}

template<typename T>
typename myVector<T>::myIterator myVector<T>::myIterator::operator--(void)
{
    --ptr_iter;
    return *this;
}

template<typename T>
bool myVector<T>::myIterator::operator>=(const myIterator& iter) const
{
    return (ptr_iter >= iter.ptr_iter);
}

template<typename T>
bool myVector<T>::myIterator::operator>(const myIterator& iter) const
{
    return (ptr_iter > iter.ptr_iter);
}

template<typename T>
bool myVector<T>::myIterator::operator<=(const myIterator& iter) const
{
    return (ptr_iter <= iter.ptr_iter);
}

template<typename T>
bool myVector<T>::myIterator::operator<(const myIterator& iter) const
{
    return (ptr_iter < iter.ptr_iter);
}

template<typename T>
bool myVector<T>::myIterator::operator!=(const myIterator& iter) const
{
    return (ptr_iter != iter.ptr_iter);
}