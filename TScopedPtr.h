#ifndef M2_TSCOPEDPTR_TSCOPEDPTR_H
#define M2_TSCOPEDPTR_TSCOPEDPTR_H
#include <iostream>

template<class T>
class TScopedPtr
{
    T* myPtr;
public:
    TScopedPtr(TScopedPtr const &) = delete;
    TScopedPtr & operator=(TScopedPtr const &) = delete;

    explicit TScopedPtr(T * p = nullptr)
    {
        myPtr = p;
    }

    ~TScopedPtr()
    {
        if(myPtr != nullptr)
        {
            delete myPtr;
        }
    }

    void reset(T * p = nullptr)
    {
        delete myPtr;
        myPtr = p;
    }

    T & operator*() const
    {
        return *myPtr;
    }

    T * operator->() const
    {
        return myPtr;
    }

    T * get() const throw()
    {
        return myPtr;
    }

    void swap(TScopedPtr & b) throw()
    {
        std::swap(myPtr, b.myPtr);
    }

    bool operator! () const throw()
    {
        return myPtr == nullptr;
    }

    explicit operator bool() const throw()
    {
        return myPtr != nullptr;
    }
};

template<class T>
inline bool operator==(TScopedPtr<T> const & p, std::nullptr_t) throw()
{
    return !p;

}

template<class T>
inline bool operator==(std::nullptr_t, TScopedPtr<T> const & p) throw()
{
    return !p;
}

template<class T>
inline bool operator!=(TScopedPtr<T> const & p, std::nullptr_t) throw()
{
    return (bool)p;
}

template<class T>
inline bool operator!=(std::nullptr_t, TScopedPtr<T> const & p) throw()
{
    return (bool)p;
}

template<class T>
inline void swap(TScopedPtr<T> & a, TScopedPtr<T> & b) throw()
{
    a.swap(b);
}

// get_pointer(p) is a generic way to say p.get()
template<class T>
inline T * get_pointer(TScopedPtr<T> const & p) throw()
{
    return p.get();
}

#endif //M2_TSCOPEDPTR_TSCOPEDPTR_H
