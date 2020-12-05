#include"event.h"
ERbot{
	function<bool()> fInit = []() {return true; };
	function<void()> fEnable = []() {};
	function<void()> fDisable = []() {};
	function<void()> fSet = []() {};
#define FUNC(ReturnType, FuncName, ...) function<##ReturnType(##FuncName e)> f##FuncName = [](##FuncName e) {return QUEUE_IGNORE; };
#include"event.inc"
#undef FUNC
	void onInit(function<bool()> fun) {
		fInit = fun;
	}
	void onEnable(function<void()> fun) {
		fEnable = fun;
	}
	void onDisable(function<void()> fun) {
		fDisable = fun;
	}
	void onSet(function<void()> fun) {
		fSet = fun;
	}
#define FUNC(ReturnType, FuncName, ...) void on##FuncName(function<##ReturnType(##FuncName e)> fun) {\
		f##FuncName = fun;\
	}
#include"event.inc"
#undef FUNC
}

DLL_EXP text __stdcall ER_Create() {
	PluginInfo i;
	Event::info(i);
	char fullPath[MAX_PATH];
	GetModuleFileNameA(NULL, fullPath, MAX_PATH);
	string d = t2s(fullPath);
	d = d.substr(0, d.find_last_of("\\")) + "\\Config\\" + i.name + "\\";
	CreateDirectoryA(d.c_str(), NULL);
	string inf = "插件名称{" + i.name + "}\r\n插件版本{" + i.version + "}\r\n插件作者{" + i.author + "}\r\n插件说明{" + i.desc + "}\r\n插件skey{8956RTEWDFG3216598WERDF3}\r\n插件sdk{S3}";
	Event::event(d);
	auto size = inf.size();
	auto cstr = new char[size + 1];
	std::memcpy(cstr, inf.c_str(), size + 1);
	return cstr;
	//return s2t(inf);
}
DLL_EXP int32 __stdcall ER_Event(text b, int32 type, int32 subtype, text f, text a, text p, text m, text n, text i, text message, int32 point) {
	int32 ret = 0;
	int64 bot = t2l(b);
	int64 from = t2l(f);
	int64 obja = t2l(a);
	int64 objb = t2l(p);
	int64 flag = t2l(n);
	int32 id = t2i(i);
	string msg = s2t(t2s(m));
	switch (type) {
	case 1009:
	case 1010:
	case 2025:
	case 1: {
		ret = Event::fPrivateMessage({ bot, 1, {bot, 1, 0, from }, 0, from, flag, id, msg });
		break;
	}
	case 2021:
	case 2022:
	case 2024:
	case 2:ret = Event::fGroupMessage({ bot, 1, {bot, 2, from, obja }, from, obja, flag, id, msg }); break;
	case 2023:
	case 2026:
	case 3:ret = Event::fDiscussMessage({ bot, 1, { bot, 3, from, obja }, from, obja, flag, id, msg }); break;
	case 4:ret = Event::fPrivateMessage({ bot, 2, { bot, 4, from, obja }, from, obja, flag, id, msg }); break;
	case 5:ret = Event::fPrivateMessage({ bot, 3, { bot, 5, from, obja }, from, obja, flag, id, msg }); break;
	case 6:ret = Event::fPrivateMessage({ bot, 4, { bot, 6, 0, from }, 0, from, flag, id, msg }); break;
	case 7:ret = Event::fPrivateMessage({ bot, 5, { bot, 7, 0, from }, 0, from, flag, id, msg }); break;
	case 12000:ret = (Event::fInit() ? 10 : 20); break;
	case 12002:ret = 2; Event::fDisable(); break;
	case 12005:ret = 2; Event::fEnable(); break;
	case 1000:ret = Event::fFriendAddRequest({ bot, 1, obja, msg }); break;
	case 1001:ret = Event::fFriendAddRequest({ bot, 2, obja, msg }); break;
	case 1011:ret = Event::fFriendAddResponse({ bot, 1, obja, msg }); break;
	case 1012:ret = Event::fFriendAddResponse({ bot, 2, obja, msg }); break;
	case 1003:ret = Event::fBeFriendDelete({ bot, 2, obja }); break;
	case 2001:ret = Event::fGroupAddRequest({ bot, 1, from, obja, -1 }); break;
	case 2002:ret = Event::fGroupAddRequest({ bot, 1, from, objb, obja }); break;
	case 2003:ret = Event::fGroupAddRequest({ bot, 2, from, bot, obja }); break;
	case 2005:ret = Event::fGroupMemberIncrease({ bot, 1, from, objb, obja }); break;
	case 2006:ret = Event::fGroupMemberDecrease({ bot, 1, from, obja, -1 }); break;
	case 2007:ret = Event::fGroupMemberDecrease({ bot, 2, from, objb, obja }); break;
	case 2008:ret = Event::fGroupDissmiss({ bot, 1, from, obja }); break;
	case 2009:ret = Event::fGroupManagerChange({ bot, 1, from, obja }); break;
	case 2010:ret = Event::fGroupManagerChange({ bot, 2, from, obja }); break;
	case 2011:ret = Event::fGroupMemberCardChange({ bot, 1, from, obja, msg }); break;
	case 2012:ret = Event::fGroupNameChange({ bot, 1, from, msg }); break;
	case 2014:ret = Event::fGroupMemberBanSpeak({ bot, 1, from, objb, obja, atoi(m) }); break;
	case 2015:ret = Event::fGroupMemberBanSpeak({ bot, 2, from, objb, obja, 0 }); break;
	case 2016:ret = Event::fGroupBanSpeak({ bot, 1, from, obja }); break;
	case 2017:ret = Event::fGroupBanSpeak({ bot, 2, from, obja }); break;
	case 2018:ret = Event::fGroupAnonymousChange({ bot, 1, from, obja }); break;
	case 2019:ret = Event::fGroupAnonymousChange({ bot, 2, from, obja }); break;
	case 2020:ret = Event::fGroupMemberRemoveMessage({ bot, 1, from, obja, flag, id }); break;
	default:break;
	}
	return ret;
}
DLL_EXP void __stdcall ER_SetUp() {
	Event::fSet();
}
DLL_EXP void __stdcall ER_DestroyPlugin() {
	Event::fDisable();
}
