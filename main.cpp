#include "UnsetValue.h"
#include <cstdio>
#include "Value.h"
#include "Exception.h"
#include "Pool.h"
#include "Alloctor.h"
#include <ngx_palloc.h>
#include <vector>

int main(){
    auto  *pool=new ngx_pool_t;
    std::vector<char,Alloctor<char>>v(pool);
    return 0;
}
