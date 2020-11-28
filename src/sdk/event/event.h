#pragma once

#ifdef DLL_EXP
#define DLL_EXP extern "C" _declspec(dllimport) 
#else
#define DLL_EXP extern "C" _declspec(dllexport) 
#endif
#include"../api/api.h"
#define ERbot namespace Event
#define INFO void info(PluginInfo& info)
#define EVENT void event(string dir)
#define QUEUE_IGNORE 0 // 忽略此消息或事件
#define QUEUE_CONTINUES 1 // 让后续插件继续执行
#define QUEUE_INTERCEPT 2 // 拦截事件阻止框架继续传递
#define RESPONSE_IGNORE 0 // 忽略请求
#define RESPONSE_PASS 1 // 通过请求
#define RESPONSE_REFUSE 2 // 拒绝请求
DLL_EXP text __stdcall ER_Create();
DLL_EXP int32 __stdcall ER_Event(text bot, int32 type, int32 subtype, text from, text obja, text objb, text msg, text flag, text id, text message, int32 point);
DLL_EXP void __stdcall ER_SetUp();
DLL_EXP void __stdcall ER_DestroyPlugin();
ERbot{
	//获取插件信息
	void info(PluginInfo& info);
	//加载事件
	void event(string dir);
//初始化
	void onInit(function<bool()> fun);
//被启用
	void onEnable(function<void()> fun);
//被关闭
	void onDisable(function<void()> fun);
//打开设置
	void onSet(function<void()> fun);
#define FUNC(ReturnType, FuncName, ...) void on##FuncName(function<ReturnType(##FuncName e)> fun);
#include"event.inc"
#undef FUNC
}
