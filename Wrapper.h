//
// Created by Yang ziJ on 2018/10/30.
//

#ifndef UNTITLED5_WRAPPER_H
#define UNTITLED5_WRAPPER_H

#include <boost/type_traits.hpp>

template <typename  T>
class Wrapper{
public:
    typedef  typename boost::remove_pointer<T>::type wrapped_type;
    typedef wrapped_type & reference_type;
    typedef wrapped_type *pointer_type;



    pointer_type get()const {
        return m_ptr;
    }
    operator bool()const {
        return get();
    }
    operator pointer_type ()const {
        return get();
    }
    pointer_type operator->()const{
        return get();
    }

private:
    pointer_type m_ptr= nullptr;
protected:
    Wrapper(pointer_type *x):m_ptr(x){}
    Wrapper(reference_type x):m_ptr(&x){}
    ~Wrapper()= default;

};

#endif //UNTITLED5_WRAPPER_H
