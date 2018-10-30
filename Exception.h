//
// Created by Yang ziJ on 2018/10/30.
//

#ifndef UNTITLED5_EXCEPTION_H
#define UNTITLED5_EXCEPTION_H


#include <exception>
#include <boost/utility/string_ref.hpp>
#include <boost/exception/exception.hpp>
#include "Config.h"

class Exception final : public virtual std::exception,
public virtual boost::exception{
public:
    typedef boost::string_ref string_ref_type;
private:
    std::string m_msg;
    int_t m_code;
public:
    Exception(int_t x,string_ref_type msg):m_code(x),m_msg(msg){}
    Exception(int_t x=NGX_ERROR):Exception(x,""){}
    Exception(string_ref_type msg):Exception(NGX_ERROR,msg){}
    virtual ~Exception() noexcept {}

    int_t code()const {
        return m_code;
    }

    virtual const char * what()const noexcept override {
        return m_msg.c_str();
    }

public:
    static void railse(int_t rc=NGX_ERROR,string_ref_type msg=""){
        throw Exception(rc,msg);
    }

    //检测条件是否满足
    static void require(bool cond ,int_t e=NGX_ERROR){
        if(!cond){
            railse(e);

        }
    }

    //检测错误码，默认是OK
    static void require(int_t rc,int_t x=NGX_OK){
        require(rc==x,rc);
    }

    //检测是否是空指针
    template <typename  T>
    static void requrie(T *p,int_t e=NGX_ERROR){
        require(p!= nullptr,e);
    }

    static void fall(bool cond,int_t e=NGX_ERROR){
        if(cond){
            railse(e);
        }
    }
};




#endif //UNTITLED5_EXCEPTION_H
