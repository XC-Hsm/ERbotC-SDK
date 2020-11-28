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
#define QUEUE_IGNORE 0 // ���Դ���Ϣ���¼�
#define QUEUE_CONTINUES 1 // �ú����������ִ��
#define QUEUE_INTERCEPT 2 // �����¼���ֹ��ܼ�������
#define RESPONSE_IGNORE 0 // ��������
#define RESPONSE_PASS 1 // ͨ������
#define RESPONSE_REFUSE 2 // �ܾ�����
DLL_EXP text __stdcall ER_Create();
DLL_EXP int32 __stdcall ER_Event(text bot, int32 type, int32 subtype, text from, text obja, text objb, text msg, text flag, text id, text message, int32 point);
DLL_EXP void __stdcall ER_SetUp();
DLL_EXP void __stdcall ER_DestroyPlugin();
ERbot{
	//��ȡ�����Ϣ
	void info(PluginInfo& info);
	//�����¼�
	void event(string dir);
//��ʼ��
	void onInit(function<bool()> fun);
//������
	void onEnable(function<void()> fun);
//���ر�
	void onDisable(function<void()> fun);
//������
	void onSet(function<void()> fun);
#define FUNC(ReturnType, FuncName, ...) void on##FuncName(function<ReturnType(##FuncName e)> fun);
#include"event.inc"
#undef FUNC
}
