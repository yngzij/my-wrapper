//
// Created by Yang ziJ on 2018/10/30.
//

#ifndef UNTITLED5_UNSETVALUE_H
#define UNTITLED5_UNSETVALUE_H


class UnsetValue final{
public:
    template <typename T>
    operator T()const {
        return static_cast<T>(-1);
    }
    template <typename T>
    operator T*()const{
    //    return static_cast<T *>(-1);
        return reinterpret_cast<T *>(-1);
    }
    static const UnsetValue& get(){
        static UnsetValue const v={};
        return v;
    }
};



#endif //UNTITLED5_UNSETVALUE_H
