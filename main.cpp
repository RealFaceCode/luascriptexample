#include <iostream>
#include "luaScript.h"

int HelloCpp(LuaScript& lua)
{
    auto str = lua.toString(1);
    std::cout << "This came from cpp : " << str << std::endl;
    return lua.getRetValCount();
}

int main(int, char**)
{
    LuaScript script("../../test.lua");

    FuncInfo info;

    std::string rStr = "";
    long long argInt = 42;

    FuncDescription desc;
    desc.addArg(argInt);
    desc.addRetVal(rStr);

    info = script.regFunc("HelloLua", desc);        // register lua defined function
    if(info != FuncInfoType::OK)
        std::cout << info.getDesc() << std::endl;

    info = script.regFunc(::HelloCpp, "HelloCpp");  // register cpp defined function
    if(info != FuncInfoType::OK)
        std::cout << info.getDesc() << std::endl;

    info = script.compile();
    if(info != FuncInfoType::OK)
        std::cout << info.getDesc() << std::endl;

    info = script.doFunc("HelloLua");
    if(info != FuncInfoType::OK)
        std::cout << info.getDesc() << std::endl;

    std::cout << rStr << std::endl;

    return 0;
}
