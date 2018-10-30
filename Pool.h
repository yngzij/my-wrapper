//
// Created by Yang ziJ on 2018/10/30.
//

#ifndef UNTITLED5_POOL_H
#define UNTITLED5_POOL_H

#include "Exception.h"
#include "Wrapper.h"
#include <ngx_core.h>
#include <cassert>


//struct ngx_core_t;
//struct ngx_p_pool_t;

class Pool final : public Wrapper<ngx_pool_t> {
    typedef Wrapper<ngx_pool_t> super_type;
    typedef Pool this_type;
public:
    ~Pool() = default;

    Pool(ngx_pool_t *p) : super_type(p) {}


    template<typename T>
    Pool(T *x):Pool(x->pool) {}

public:
    template<typename T, bool no_excetion = false>
    T *palloc() const {
        auto p = ngx_pcalloc(get(), sizeof(T));
        if (!p) {
            if (no_excetion) {
                return nullptr;
            }
            Exception::railse();
        }
        assert(p);
        return new(p) T();
    }

public:
    template<typename T>
    T *alloc() const {
        return palloc<T, false>();
    }

    template<typename T>
    T *alloc_noexcept() const {
        return palloc<T, true>();
    }

public:
    template<typename T>
    T *nalloc(std::size_t n) const {
        auto p = ngx_pnalloc(get(), n);
        Exception::require(p);
        return reinterpret_cast<T *>(p);
    }

    template<typename T, typename  ...Args>
    T *construct(const Args &...args) const {
        auto p = ngx_pcalloc(get(), sizeof(T));
        Exception::require(p);
        return new(p)T(args...);
    }
public:
    template<typename F, typename T>
    ngx_pool_cleanup_t *cleanup(F func, T *data, std::size_t size = 0) const {
        auto p = ngx_pool_cleanup_add(get(), size);
        Exception::require(p);
        p->handler = func;
        if (data) {
            p->data = data;
        }
        return p;
    }

public:
    template <typename  T>
    static void destory(void *p){
        (reinterpret_cast<T *>(p))->~t();
    }
    template <typename  T>
    void cleanup(T *data)const {
        cleanup(&this_type::destory<T>,data);
    }
};


#endif //UNTITLED5_POOL_H
