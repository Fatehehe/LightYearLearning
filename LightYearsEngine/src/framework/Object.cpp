#include "framework/Object.h"
#include "framework/Core.h"
#include <memory>

namespace ly{
    Object::Object()
    : mIsPendingDestroy{false}
    {
    }

    Object::~Object()
    {
        LOG("Object destroyed");
    }

    void Object::Destroy()
    {
        mIsPendingDestroy = true;
    }

    weak<Object> Object::GetWeakRef() 
    {
        #if _LIBCPP_STD_VER >= 17
        return weak_from_this();
        #endif
    }

     weak<const Object> Object::GetWeakRef() const{
        #if _LIBCPP_STD_VER >= 17
        return weak_from_this();
        #endif
     }
}
