#include <utility> // Has std::move
#include "../Header/BitVector.h"

////////////////////////////////////// G6

BitVector::BitVector()
    : data(nullptr)
    , size(0)
{ }

BitVector::~BitVector()
{
    delete[] data;
}

BitVector::BitVector(const BitVector& source)
    : data(nullptr)
    , size(0)
{
    copy(source.data, source.size);
}

BitVector::BitVector(BitVector&& source)
    : data(nullptr)
    , size(0)
{
    assign(source.data, source.size);
}

BitVector& BitVector::operator=(const BitVector& rhs)
{
    if(this != &rhs)
        copy(rhs.data, rhs.size);
    return *this;
}

BitVector& BitVector::operator=(BitVector&& rhs)
{
    if(this != &rhs)
        assign(rhs.data, rhs.size);
    return *this;
}

////////////////////////////////////// Public

void BitVector::change(size_t index, bool value)
{
    int pos = index % dataSize;
    index = index / dataSize;

    if(index >= size)
        resize(index+1);

    if(value)
        data[index] |= 1 << (pos-1);
    else
        data[index] &= ~(1 << (pos-1));
}

bool BitVector::empty() const
{
    return size == 0;
}

size_t BitVector::len() const
{
    return size * dataSize;
}

void BitVector::resize(size_t new_size)
{
    if(new_size == size)
        return;
    if(new_size == 0)
        clear();

    unsigned long long* tmp = new unsigned long long[new_size];

    if(new_size > size)
    {
        for(int i = 0; i < size; i++)
            tmp[i] = data[i];
        for(int i = size; i < new_size; i++)
            tmp[i] = 0;
    }
    else
        for(int i = 0; i < new_size; i++)
            tmp[i] = data[i];

    size = new_size;
    delete[] data;
    data = tmp;
}

void BitVector::reserve(size_t how_much)
{
    resize(size + how_much);
}

void BitVector::clear()
{
    delete[] data;
    size = 0;
}

void BitVector::copy(unsigned long long* _data, size_t _size)
{
    unsigned long long* tmp = new unsigned long long[_size];

    for(int i = 0; i < _size; i++)
        tmp[i] = _data[i];

    if(size != 0)
        clear();

    data = tmp;
    size = _size;
}

void BitVector::assign(unsigned long long*& _data, size_t& _size)
{
    if(size != 0)
        clear;

    data = _data;
    size = _size;

    _data = nullptr;
    _size = 0;
}











