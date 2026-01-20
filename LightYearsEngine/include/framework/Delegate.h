#pragma once
#include <functional>
#include "framework/Core.h"
#include "framework/Object.h"

namespace ly{
    template<typename... Args>
    class Delegate
    {
    public:
    
        template<typename ClassName>
        void BindAction(weak<Object> obj, void(ClassName::*callBack)(Args...)){
            std::function<bool(Args...)> callbackFunc = [obj, callBack](Args... args)->bool{
                if(!obj.expired()){
                    (static_cast<ClassName*>(obj.lock().get())->*callBack)(args...);
					return true;
                }
                return false;
            }; 
            mCallbacks.push_back(callbackFunc);
        }
        

        void Broadcast(Args... args){
            for(auto iter = mCallbacks.begin(); iter != mCallbacks.end();){
                if((*iter)(args...)){
                    ++iter;
                }else{
                    iter = mCallbacks.erase(iter);
                }
            }
        }

    private:
        List<std::function<bool(Args...)>> mCallbacks;
    };
}