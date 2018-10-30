//
// Created by Yang ziJ on 2018/10/30.
//

#ifndef UNTITLED5_ALLOCTOR_H
#define UNTITLED5_ALLOCTOR_H

#include <boost/core/ignore_unused.hpp>
#include "Wrapper.h"
#include <ngx_core.h>
#include <ngx_palloc.h>


template <typename  T>
class Alloctor :public Wrapper<ngx_pool_t>{
public:
    typedef Wrapper<ngx_pool_t >super_type;
    typedef Alloctor this_type;
public:
    typedef  std::size_t size_type;
    typedef  T *  pointer;
    typedef T  value_type;
public:
    Alloctor(ngx_pool_t *p):super_type(p){};
    ~Alloctor()=default;

public:
    pointer allocate(size_type n){
        return reinterpret_cast<pointer_type >(ngx_pnalloc(get(),n*sizeof(T)));
    }

    void deallocate(pointer ptr, size_type n){
        boost::ignore_unused(n);
        ngx_pfree(get(),ptr);

    }
};


#endif //UNTITLED5_ALLOCTOR_H
