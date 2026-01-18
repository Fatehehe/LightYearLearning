#pragma once

#include <string>

std::string GetResourceDir(){
#ifdef NDEBUG //release build  
    return "assets/";
#else
    return "/Users/fatakhillahkhaqo/Documents/Learnings/CPP/LightYears/LightYearsGame/assets/";
#endif
}
