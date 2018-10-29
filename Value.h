//
// Created by Yang ziJ on 2018/10/30.
//

#ifndef UNTITLED5_VALUE_H
#define UNTITLED5_VALUE_H

#include "UnsetValue.h"

class Value final{
public:
    Value()= default;
    ~Value()= default;

public:

    template <typename T,typename  ...Args>
    static void unset(T &v,Args & ...args){
        v=UnsetValue::get();
        unset(args...);
    }
    static void unset(){}

    template <typename T>
    static bool invalid(const T &v){
        return v== static_cast<T>(UnsetValue::get());
    }
    template <typename T,typename U>
    static void init(T &x, const U &v){
        if(invalid(x)){
            x=v;
        }
    }
    template <typename T,typename U,typename V>
    static void merge(T &c,const U &p,const V &d){
        if (invalid(c)){
            c=invalid(p)?d:p;
        }
    }

};


#endif //UNTITLED5_VALUE_H
