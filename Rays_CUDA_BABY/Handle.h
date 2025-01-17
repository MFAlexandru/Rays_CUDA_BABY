
#ifndef HANDLE_H
#define HANDLE_H
#include <algorithm>
template <class T> class Handle {
public:
    Handle(): p(0) { }
    Handle(const Handle& s): p(0) { if (s.p) p = s.p; }
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    Handle(T* t): p(t) { }

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;
private:
    T* p;
};

template<class T> Handle<T>& Handle<T>::operator=(const Handle& rhs) {
    if (&rhs != this) {
        delete p;
        p = rhs.p ? rhs.p : 0;
    }
    return *this;
}

template <class T> T& Handle<T>::operator*() const {
    if (p)
        return *p;
}

template <class T> T* Handle<T>::operator->() const {
    if (p)
        return p;
}

#endif