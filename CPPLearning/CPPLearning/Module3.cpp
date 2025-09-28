#include <iostream>
#include <cassert>
using namespace std;

class IndexOutOfBoundsException {};

template <typename T>
class Array {
private:
    T* m_ptr = { nullptr };
    int m_size = { 0 };

    bool IsValidIndex(int index) const {
        return (index >= 0) && (index < m_size);
    }

public:
    Array() = default;

    explicit Array(int size) {
        if (size != 0) {
            m_ptr = new T[size]{};
            m_size = size;
        }
    }

    // Custom copy constructor
    Array(const Array& source) {
        if (!source.isEmpty()) {
            m_size = source.m_size;

            m_ptr = new T[m_size]{};
            for (int i = 0; i < m_size; i++) {
                m_ptr[i] = source.m_ptr[i];
            }
        }
    }

    // Assignment operator using copy & swap
    Array& operator=(Array source) {
        swap(*this, source);
        return *this;
    }

    // Swap function
    friend void swap(Array& a, Array& b) noexcept {
        using std::swap;
        swap(a.m_ptr, b.m_ptr);
        swap(a.m_size, b.m_size);
    }

    // Move constructor
    Array(Array&& source) noexcept {
        m_ptr = source.m_ptr;
        m_size = source.m_size;

        source.m_ptr = nullptr;
        source.m_size = 0;
    }

    // Destructor
    ~Array() {
        delete[] m_ptr;
    }

    int Size() const {
        return m_size;
    }

    bool isEmpty() const {
        return (m_size == 0);
    }

    // Bounds checking
    T& operator[](int index) {
        if (!IsValidIndex(index)) {
            throw IndexOutOfBoundsException{};
        }
        return m_ptr[index];
    }

    T operator[](int index) const {
        if (!IsValidIndex(index)) {
            throw IndexOutOfBoundsException{};
        }
        return m_ptr[index];
    }
};

// Output operator
template <typename T>
ostream& operator<<(ostream& os, const Array<T>& a) {
    os << "[";
    for (int i = 0; i < a.Size(); i++) {
        os << a[i] << ' ';
    }
    os << "]";
    return os;
}

int main() {
    /*IntArray a{ 10 };
    for (int i = 0; i < a.Size(); i++) {
        a[i] = (i + 1) * 10;
    }

    cout << "Array elements: " << a << '\n';*/

    //------------------------------------------

    /*IntArray a{ 3 };
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    IntArray b = a;

    cout << " a = " << a << '\n';
    cout << " b = " << b << '\n';

    b[1] = 100;
    cout << " a = " << a << '\n';
    cout << " b = " << b << '\n';*/

    //------------------------------------------

    Array<int> numbers(5);
    for (int i = 0; i < numbers.Size(); i++) {
        numbers[i] = i * 10;
    }
    cout << numbers << endl;  

    Array<string> words(3);
    words[0] = "Hello";
    words[1] = "Template";
    words[2] = "World";
    cout << words << endl;

}