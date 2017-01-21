#ifndef BitVectorDef
#define BitVectorDef

class BitVector
{
public:
    ////// G6
    BitVector();
    ~BitVector();
    BitVector(const BitVector& source);
    BitVector(BitVector&& source);
    BitVector& operator=(const BitVector& rhs);
    BitVector& operator=(BitVector&& rhs);
    /////////////////

    void change(size_t index, bool value); // Value = 0 or 1

    bool empty() const;
    size_t len() const;

    void resize(size_t new_size);
    void reserve(size_t how_much);

    void clear();

private:

    void copy(unsigned long long* _data, size_t _size);
    void assign(unsigned long long*& _data, size_t& _size);

    unsigned long long* data;
    size_t size;

    static const short dataSize = 64;
};

#endif // BitVectorDef
