#include"api.h"
namespace code {
	string at(int64 qq) {
		return "[at=" + l2s(qq) + "] ";
	}
	string face(int32 id) {
		return "[Face" + i2s(id) + ".gif]";
	}
	string image(string path) {
		return "[pic=" + path + "]";
	}
}
namespace api {
	namespace raw {
#define FUNC(ReturnType, FuncName, ...) typedef ReturnType (__stdcall *Api_##FuncName)(__VA_ARGS__);
#include"api.inc"
#undef FUNC
		const auto dll = GetModuleHandleW(L"ERapi.dll");
#define FUNC(ReturnType, FuncName, ...) \
	Api_##FuncName FuncName = (Api_##FuncName)GetProcAddress(dll, "Api_" #FuncName);
#include"api.inc"
#undef FUNC
	}
	string getFrameName() {
		return t2s(raw::GetFrameName());
	}
	string getVer() {
		return t2s(raw::GetVer());
	}
	int32 getTimeStamp() {
		return raw::GetTimeStamp();
	}
	string getLog() {
		return t2s(raw::GetLog());
	}
	bool isEnable() {
		return raw::IsEnable();
	}
	void disabledPlugin() {
		raw::DisabledPlugin();
	}
	void log(string msg) {
		raw::OutPut(s2t(msg));
	}
	void log(int64 msg) {
		raw::OutPut(l2t(msg));
	}
	void log(int32 msg) {
		raw::OutPut(i2t(msg));
	}
	string getNick(int64 bot, int64 qq) {
		return t2s(raw::GetNick(l2t(bot), l2t(qq)));
	}
	void sendMsg(target tar, string msg) {
		raw::SendMsg(l2t(tar.bot), tar.type, tar.group ? l2t(tar.group) : "", tar.qq ? l2t(tar.qq) : "", s2t(msg));
	}
	void sendXml(target tar, string msg) {
		raw::SendXml(l2t(tar.bot), tar.type, tar.group ? l2t(tar.group) : "", tar.qq ? l2t(tar.qq) : "", s2t(msg), 0);
	}
	void sendJson(target tar, string msg) {
		raw::SendJson(l2t(tar.bot), tar.type, tar.group ? l2t(tar.group) : "", tar.qq ? l2t(tar.qq) : "", s2t(msg));
	}
	void sendFriendMsg(int64 bot, int64 qq, string msg) {
		raw::SendMsg(l2t(bot), 1, "", l2t(qq), s2t(msg));
	}
	void sendGroupMsg(int64 bot, int64 group, string msg) {
		raw::SendMsg(l2t(bot), 2, l2t(group), "", s2t(msg));
	}
	void sendDiscussMsg(int64 bot, int64 discuss, string msg) {
		raw::SendMsg(l2t(bot), 3, l2t(discuss), "", s2t(msg));
	}
	void sendGruopTempMsg(int64 bot, int64 group, int64 qq, string msg) {
		raw::SendMsg(l2t(bot), 4, l2t(group), l2t(qq), s2t(msg));
	}
	void sendDiscussTempMsg(int64 bot, int64 discuss, int64 qq, string msg) {
		raw::SendMsg(l2t(bot), 5, l2t(discuss), l2t(qq), s2t(msg));
	}
	void sendWebTempMsg(int64 bot, int64 qq, string msg) {
		raw::SendMsg(l2t(bot), 6, "", l2t(qq), s2t(msg));
	}
	void sendFriendVerifyMsg(int64 bot, int64 qq, string msg) {
		raw::SendMsg(l2t(bot), 7, "", l2t(qq), s2t(msg));
	}
	void sendFriendXml(int64 bot, int64 qq, string msg) {
		raw::SendXml(l2t(bot), 1, "", l2t(qq), s2t(msg), 0);
	}
	void sendGroupXml(int64 bot, int64 group, string msg) {
		raw::SendXml(l2t(bot), 2, l2t(group), "", s2t(msg), 0);
	}
	void sendDiscussXml(int64 bot, int64 discuss, string msg) {
		raw::SendXml(l2t(bot), 3, l2t(discuss), "", s2t(msg), 0);
	}
	void sendGruopTempXml(int64 bot, int64 group, int64 qq, string msg) {
		raw::SendXml(l2t(bot), 4, l2t(group), l2t(qq), s2t(msg), 0);
	}
	void sendDiscussTempXml(int64 bot, int64 discuss, int64 qq, string msg) {
		raw::SendXml(l2t(bot), 5, l2t(discuss), l2t(qq), s2t(msg), 0);
	}
	void sendWebTempXml(int64 bot, int64 qq, string msg) {
		raw::SendXml(l2t(bot), 6, "", l2t(qq), s2t(msg), 0);
	}
	void sendFriendVerifyXml(int64 bot, int64 qq, string msg) {
		raw::SendXml(l2t(bot), 7, "", l2t(qq), s2t(msg), 0);
	}
	void sendFriendJson(int64 bot, int64 qq, string msg) {
		raw::SendJson(l2t(bot), 1, "", l2t(qq), s2t(msg));
	}
	void sendGroupJson(int64 bot, int64 group, string msg) {
		raw::SendJson(l2t(bot), 2, l2t(group), "", s2t(msg));
	}
	void sendDiscussJson(int64 bot, int64 discuss, string msg) {
		raw::SendJson(l2t(bot), 3, l2t(discuss), "", s2t(msg));
	}
	void sendGruopTempJson(int64 bot, int64 group, int64 qq, string msg) {
		raw::SendJson(l2t(bot), 4, l2t(group), l2t(qq), s2t(msg));
	}
	void sendDiscussTempJson(int64 bot, int64 discuss, int64 qq, string msg) {
		raw::SendJson(l2t(bot), 5, l2t(discuss), l2t(qq), s2t(msg));
	}
	void sendWebTempJson(int64 bot, int64 qq, string msg) {
		raw::SendJson(l2t(bot), 6, "", l2t(qq), s2t(msg));
	}
	void sendFriendVerifyJson(int64 bot, int64 qq, string msg) {
		raw::SendJson(l2t(bot), 7, "", l2t(qq), s2t(msg));
	}
	vector<FriendListInfo> getFriendList(int64 bot) {
		vector<FriendListInfo> l;
		string s = t2s(raw::GetFriendList(l2t(bot)));
		json j = json::parse(s);
		if (j["errcode"] == 0) {
			json j1 = j["result"];
			for (auto i1 = j1.begin(); i1 != j1.end(); ++i1) {
				string g = i1.value()["gname"].is_string() ? i1.value()["gname"].get<string>() : "我的好友";
				json j2 = i1.value()["mems"];
				for (auto i2 = j2.begin(); i2 != j2.end(); ++i2) {
					FriendListInfo f;
					f.id = i2.value()["uin"].get<int64>();
					f.remark = i2.value()["name"].get<string>();
					f.group = g;
					l.push_back(f);
				}
			}
		}
		return l;
	}
	vector<int64> getFriendNumberList(int64 bot) {
		return s2ls(raw::GetFriendList_B(l2t(bot)), "\r\n");
	}
	vector<GroupListInfo> getGroupList(int64 bot) {
		vector<GroupListInfo> l;
		string s = t2s(raw::GetGroupList_B(l2t(bot)));
		json j = json::parse(s);
		if (j["errcode"] == 0) {
			json j1 = j["join"];
			for (auto i1 = j1.begin(); i1 != j1.end(); ++i1) {
				GroupListInfo g;
				g.id = i1.value()["gc"].get<int64>();
				g.name = i1.value()["gn"].get<string>();
				g.owner = i1.value()["owner"].get<int64>();
				g.admin = false;
				l.push_back(g);
			}
			json j2 = j["manage"];
			for (auto i2 = j2.begin(); i2 != j2.end(); ++i2) {
				GroupListInfo g;
				g.id = i2.value()["gc"].get<int64>();
				g.name = i2.value()["gn"].get<string>();
				g.owner = i2.value()["owner"].get<int64>();
				g.admin = true;
				l.push_back(g);
			}
			json j3 = j["create"];
			for (auto i3 = j3.begin(); i3 != j3.end(); ++i3) {
				GroupListInfo g;
				g.id = i3.value()["gc"].get<int64>();
				g.name = i3.value()["gn"].get<string>();
				g.owner = i3.value()["owner"].get<int64>();
				g.admin = true;
				l.push_back(g);
			}
		}
		return l;
	}
	vector<int64> getGroupNumberList(int64 bot) {
		return s2ls(raw::GetGroupList_A(l2t(bot)), "\r\n");
	}
	GroupMemberListInfo getGroupMemberList(int64 bot, int64 group) {
		GroupMemberListInfo l;
		string s = t2s(raw::GetGroupMemberList_C(l2t(bot), l2t(group)));
		json j = json::parse(s);
		if (j["errcode"] == 0) {
			l.num = j["mem_num"].get<int32>();
			l.max = j["max_num"].get<int32>();
			l.owner = j["owner"].get<int64>();
			json j1 = j["adm"];
			for (auto i1 = j1.begin(); i1 != j1.end(); ++i1) {
				l.admins.push_back(i1.value().get<int64>());
			}
			json j2 = j["members"];
			for (auto i2 = j2.begin(); i2 != j2.end(); ++i2) {
				GroupMemberInfo g;
				g.id = t2l(s2t(i2.key()));
				g.nick = i2.value()["nk"].get<string>();
				g.card = i2.value()["cd"].get<string>();
				g.point = i2.value()["lp"].get<int32>();
				g.lv = i2.value()["ll"].get<int32>();
				g.banTime = i2.value()["sut"].get<int32>();
				g.joinTime = i2.value()["jt"].get<int64>();
				g.lastTime = i2.value()["lst"].get<int64>();
				g.isFriend = i2.value()["fr"].get<int32>();
				l.member.push_back(g);
			}
		}
		return l;
	}
	vector<int64> getGroupMemberNumberList(int64 bot, int64 group) {
		return s2ls(raw::GetGroupMemberList_B(l2t(bot), l2t(group)), "\r\n");
	}
	vector<int64> getGroupAdminList(int64 bot, int64 group) {
		return s2ls(raw::GetAdminList(l2t(bot), l2t(group)), "\r\n");
	}
	BotInfo getStateInfo(int64 bot) {
		BotInfo b;
		vector<string> l;
		string s = t2s(raw::GetStatus(l2t(bot))) + "|";
		if (s != "|") {
			int size = s.size();
			for (int pos, i = 0; i < size; i++) {
				pos = s.find("|", i);
				if (pos < size)
				{
					string st = s.substr(i, pos - i);
					l.push_back(st);
					i = pos;
				}
			}
			if (l.size() == 7) {
				b.nick = l[0];
				b.id = t2l(s2t(l[1]));
				b.state = l[2];
				b.speed = l[3];
				b.recvNum = t2l(s2t(l[4]));
				b.sendNum = t2l(s2t(l[5]));
				b.onlineTime = l[6];
			}
		}
		return b;
	}
	void setStatus(int64 bot, int32 state, string msg) {
		raw::SetStatus(l2t(bot), state, s2t(msg));
	}
	string getGroupNotice(int64 bot, int64 group) {
		return t2s(raw::GetNotice(l2t(bot), l2t(group)));
	}
	string getPicLink(int64 bot, int64 group, string msg) {
		return t2s(group ? (raw::GetPicLink(l2t(bot), 1, l2t(group), s2t(msg))) : (raw::GetPicLink(l2t(bot), 2, "", s2t(msg))));
	}
	string uploadGroupVoice(int64 bot, int64 group, bin voice) {
		return t2s(raw::UpLoadVoice(l2t(bot), l2t(group), voice));
	}
	string uploadGroupPic(int64 bot, int64 group, bin pic) {
		return t2s(raw::UpLoadPic(l2t(bot), 2, l2t(group), pic));
	}
	string uploadPrivatePic(int64 bot, int64 qq, bin pic) {
		return t2s(raw::UpLoadPic(l2t(bot), 1, l2t(qq), pic));
	}
	bool joinGroup(int64 bot, int64 group, string msg) {
		return raw::JoinGroup(l2t(bot), l2t(group), s2t(msg));
	}
	void quitGroup(int64 bot, int64 group) {
		raw::QuitGroup(l2t(bot), l2t(group));
	}
	bool sendFriendVoice(int64 bot, int64 qq, bin voice) {
		return raw::SendVoice(l2t(bot), l2t(qq), voice);
	}
	bool addFriend(int64 bot, int64 qq, string msg) {
		return raw::AddFriend(l2t(bot), l2t(qq), s2t(msg));
	}
	void setBlackList(int64 bot, int64 qq, bool black) {
		if (black) {
			raw::AddBkList(l2t(bot), l2t(qq));
		}
		else {
			raw::DelBkList(l2t(bot), l2t(qq));
		}
	}
	bool ban(int64 bot, int64 group, int64 qq, int32 time) {
		return raw::Shutup(l2t(bot), l2t(group), l2t(qq), time);
	}
	bool allBan(int64 bot, int64 group, bool enable) {
		return raw::Shutup(l2t(bot), l2t(group), "", enable ? 1 : 0);
	}
	bool isBan(int64 bot, int64 group, int64 qq) {
		return raw::IsShutup(l2t(bot), l2t(group), l2t(qq));
	}
	bool setAnon(int64 bot, int64 group, bool enbale) {
		return raw::SetAnon(l2t(bot), l2t(group), enbale);
	}
	vector<int64> getDiscussList(int64 bot) {
		return s2ls(raw::GetDisGroupList(l2t(bot)), "\r\n");
	}
	vector<int64> getDiscussMemberList(int64 bot, int64 discuss) {
		return s2ls(raw::GetDisGroupMemberList(l2t(bot), l2t(discuss)), "\r\n");
	}
	bool shakeWindow(int64 bot, int64 qq) {
		return raw::ShakeWindow(l2t(bot), l2t(qq));
	}
	FriendInfo getFriendInfo(int64 bot, int64 qq) {
		FriendInfo f;
		string s = t2s(raw::GetObjInfo(l2t(bot), l2t(qq)));
		json j = json::parse(s);
		if (j["retcode"] == 0) {
			f.id = j["result"]["buddy"]["info_list"][0]["uin"].get<int64>();
			f.nick = j["result"]["buddy"]["info_list"][0]["nick"].get<string>();
			f.gender = j["result"]["buddy"]["info_list"][0]["gender"].get<int8>();
			f.age = j["result"]["buddy"]["info_list"][0]["age"].get<int32>();
			f.country = j["result"]["buddy"]["info_list"][0]["country"].get<string>();
			f.province = j["result"]["buddy"]["info_list"][0]["province"].get<string>();
			f.city = j["result"]["buddy"]["info_list"][0]["city"].get<string>();
			f.headimg = j["result"]["buddy"]["info_list"][0]["url"].get<string>();
		}
		return f;
	}
	int32 getFriendLevel(int64 bot, int64 qq) {
		return raw::GetObjLevel(l2t(bot), l2t(qq));
	}
	bool deleteFriend(int64 bot, int64 qq) {
		return raw::DelFriend(l2t(bot), l2t(qq));
	}
	void setShieldedGroup(int64 bot, int64 group, bool enable) {
		raw::SetShieldedGroup(l2t(bot), l2t(group), enable);
	}
	bool setAdmin(int64 bot, int64 group, int64 qq, bool enable) {
		return raw::SetAdmin(l2t(bot), l2t(group), l2t(qq), enable);
	}
	string withdrawMsg(int64 bot, int64 group, int64 flag, int32 id) {
		return t2s(raw::WithdrawMsg(l2t(bot), l2t(group), l2t(flag), i2t(id)));
	}
	void setInput(int64 bot, int64 qq) {
		raw::BeInput(l2t(bot), l2t(qq));
	}
	int32 getQQAddMode(int64 bot, int64 qq) {
		return t2i(raw::GetQQAddMode(l2t(bot), l2t(qq)));
	}
	bool isOnline(int64 bot, int64 qq) {
		return raw::IsOnline(l2t(bot), l2t(qq));
	}
	int32 getOnlineState(int64 bot, int64 qq) {
		return raw::GetOnlineState(l2t(bot), l2t(qq));
	}
	int32 getGroupMemberNum(int64 bot, int64 group, int32& max) {
		int32 num = 0;
		vector<int64> l = s2ls(raw::GetGroupMemberNum(l2t(bot), l2t(group)), "/");
		if (l.size() == 2) {
			max = (int32)l[1];
			num = (int32)l[0];
		}
		return num;
	}
	int32 getGroupMemberNum(int64 bot, int64 group) {
		int32 max;
		return getGroupMemberNum(bot, group, max);
	}
	bool getWpa(int64 bot, int64 qq) {
		return raw::GetWpa(l2t(bot), l2t(qq));
	}
	bool signIn(int64 bot, int64 group, string location, string content) {
		return raw::SignIn(l2t(bot), l2t(group), s2t(location), s2t(content));
	}
	string getGroupCard(int64 bot, int64 group, int64 qq) {
		return t2s(raw::GetGroupCard(l2t(bot), l2t(group), l2t(qq)));
	}
	string getGroupName(int64 bot, int64 group) {
		return t2s(raw::GetGroupName(l2t(bot), l2t(group)));
	}
	bool addQQ(int64 bot, string password, bool autologin) {
		return raw::AddQQ(l2t(bot), s2t(password), autologin);
	}
	void delQQ(int64 bot) {
		raw::DelQQ(l2t(bot));
	}
	void login(int64 bot) {
		raw::Login(l2t(bot));
	}
	void logout(int64 bot) {
		raw::Logout(l2t(bot));
	}
	bool isFriend(int64 bot, int64 qq) {
		return raw::IfFriend(l2t(bot), l2t(qq));
	}
	string like(int64 bot, int64 qq) {
		return t2s(raw::UpVote(l2t(bot), l2t(qq)));
	}
	bool setGroupCard(int64 bot, int64 group, int64 qq, string card) {
		return raw::SetGroupCard(l2t(bot), l2t(group), l2t(qq), s2t(card));
	}
	void kickGroupMember(int64 bot, int64 group, int64 qq, bool block) {
		raw::KickGroupMBR(l2t(bot), l2t(group), l2t(qq), block);
	}
	void quitDiscuss(int64 bot, int64 discuss) {
		raw::QuitDisGroup(l2t(bot), l2t(discuss));
	}
	void KickDiscussMember(int64 bot, int64 discuss, int64 qq) {
		raw::KickDisGroupMBR(l2t(bot), l2t(discuss), l2t(qq));
	}
	void setDiscussName(int64 bot, int64 discuss, string name) {
		raw::SetDisGroupName(l2t(bot), l2t(discuss), s2t(name));
	}
	void setFriendsRemark(int64 bot, int64 qq, string remark) {
		raw::SetFriendsRemark(l2t(bot), l2t(qq), s2t(remark));
	}
	string getFriendsRemark(int64 bot, int64 qq) {
		return t2s(raw::GetFriendsRemark(l2t(bot), l2t(qq)));
	}
	vector<int64> getQQList() {
		return s2ls(raw::GetQQList(), "\r\n");
	}
	vector<int64> getOnlineQQlist() {
		return s2ls(raw::GetOnlineQQlist(), "\r\n");
	}
	vector<int64> getOffLineList() {
		return s2ls(raw::GetOffLineList(), "\r\n");
	}
	int32 getExpertDays(int64 bot, int64 qq) {
		return raw::GetExpertDays(l2t(bot), l2t(qq));
	}
	string getVoiceLink(int64 bot, string msg) {
		return t2s(raw::GetGuidVoiceLink(l2t(bot), s2t(msg)));
	}
	void handleGroupEvent(int64 bot, int32 type, int64 qq, int64 group, int64 seq, int32 method, string msg) {
		raw::HandleGroupEvent(l2t(bot), type, l2t(qq), l2t(group), l2t(seq), method, s2t(msg));
	}
	void handleFriendEvent(int64 bot, int64 qq, int32 method, string msg) {
		raw::HandleFriendEvent(l2t(bot), l2t(qq), method, s2t(msg));
	}
	string getDiscussName(int64 bot, int64 discuss) {
		return t2s(raw::GetDisGroupName(l2t(bot), l2t(discuss)));
	}
	void setNick(int64 bot, string nick) {
		raw::SetNick(l2t(bot), s2t(nick));
	}
	void setGender(int64 bot, int32 gender) {
		raw::SetGender(l2t(bot), i2t(gender));
	}
	void setSign(int64 bot, string sign) {
		raw::SetSign(l2t(bot), s2t(sign));
	}
	int32 getGender(int64 bot, int64 qq) {
		return raw::GetGender(l2t(bot), l2t(qq));
	}
	int32 getQQAge(int64 bot, int64 qq) {
		return raw::GetQQAge(l2t(bot), l2t(qq));
	}
	int32 getAge(int64 bot, int64 qq) {
		return raw::GetAge(l2t(bot), l2t(qq));
	}
	string getSign(int64 bot, int64 qq) {
		return t2s(raw::GetSign(l2t(bot), l2t(qq)));
	}
	string getPerExp(int64 bot, int64 qq) {
		return t2s(raw::GetPerExp(l2t(bot), l2t(qq)));
	}
	string getEmail(int64 bot, int64 qq) {
		return t2s(raw::GetEmail(l2t(bot), l2t(qq)));
	}
	bool setHead(int64 bot, bin pic) {
		return raw::UpLoad(l2t(bot), pic);
	}
	bool setPhotoWall(int64 bot, bin pic) {
		return raw::PhotoWallUpload(l2t(bot), pic);
	}
	string getDiscussLink(int64 bot, int64 discuss) {
		return t2s(raw::GetDisGroup(l2t(bot), l2t(discuss)));
	}
	string joinDiscuss(int64 bot, string link) {
		return t2s(raw::SetDisGroup(l2t(bot), s2t(link)));
	}
	string inviteDiscuss(int64 bot, int64 discuss, int64 qq) {
		return t2s(raw::InviteDisGroup(l2t(bot), l2t(discuss), l2t(qq)));
	}
	string createDiscuss(int64 bot, int64 qq) {
		return t2s(raw::CreateDisGroup(l2t(bot), l2t(qq)));
	}
	void adminInviteGroup(int64 bot, int64 group, int64 qq) {
		raw::AdminInviteGroup(l2t(bot), l2t(group), l2t(qq));
	}
	void noAdminInviteGroup(int64 bot, int64 group, int64 qq) {
		raw::NoAdminInviteGroup(l2t(bot), l2t(group), l2t(qq));
	}
	string teaEncrypt(string content, string key) {
		return t2s(raw::TeaEncrypt(s2t(content), s2t(key)));
	}
	string teaDecrypt(string content, string key) {
		return t2s(raw::TeaDecrypt(s2t(content), s2t(key)));
	}
	int64 getGroupID(int64 group) {
		return t2l(raw::GNGetGid(l2t(group)));
	}
	int64 getGroupNumber(int64 group) {
		return t2l(raw::GidGetGN(l2t(group)));
	}
	string sendPack(int64 bot, string pack) {
		return t2s(raw::SendPack(l2t(bot), s2t(pack)));
	}
	GradeInfo getQQLevel(int64 bot) {
		GradeInfo g;
		vector<string> l;
		string s = t2s(raw::GetQQLevel(l2t(bot))) + "->";
		int size = s.size();
		for (int pos, i = 0; i < size; i++) {
			pos = s.find("->", i);
			if (pos < size)
			{
				string st = s.substr(i, pos - i);
				l.push_back(st);
				i = pos + 1;
			}
		}
		if (l.size() == 4) {
			g.vip = l[1].substr(l[1].find(":", 0) + 1);
			g.lv = stoi(l[2].substr(l[2].find(":", 0) + 1));
			g.activeDays = stoi(l[3].substr(l[3].find(":", 0) + 1));
			g.upgradeDays = stoi(l[4].substr(l[4].find(":", 0) + 1));
		}
		return g;
	}
	string publicGroupNotic(int64 bot, int64 group, string title, string content) {
		string s = t2s(raw::PBGroupNotic(l2t(bot), l2t(group), s2t(title), s2t(content)));
		json j = json::parse(s);
		string e = j["em"].get<string>();
		if (e == "") {
			e = "结果解析失败";
		}
		return e;
	}
	int32 takeGift(int64 bot) {
		string s = t2s(raw::TakeGift(l2t(bot)));
		json j = json::parse(s);
		return j["lucky_code"].get<int32>();
	}
	vector<GiftInfo> checkGift(int64 bot) {
		vector<GiftInfo> l;
		string s = t2s(raw::CheckGift(l2t(bot)));
		json j = json::parse(s);
		json j1 = j["history"];
		for (auto i1 = j1.begin(); i1 != j1.end(); ++i1) {
			GiftInfo g;
			g.id = i1.value()["pid"].get<int32>();
			g.name = i1.value()["name"].get<string>();
			g.value = i1.value()["value"].get<int32>();
			g.getTime = i1.value()["time"].get<int32>();
			g.expireTime = i1.value()["expired_time"].get<int32>();
			l.push_back(g);
		}
		return l;
	}
	bool sendGift(int64 bot, int64 group, int64 qq, int32 giftid) {
		string s = t2s(raw::GiveGift(l2t(bot), l2t(group), l2t(qq), i2t(giftid)));
		json j = json::parse(s);
		return !j["ec"].get<int32>();
	}
	string publicHomeWork(int64 bot, int64 group, string name, string title, string content) {
		string s = t2s(raw::PBHomeWork(l2t(bot), l2t(group), s2t(name), s2t(title), s2t(content)));
		json j = json::parse(s);
		return j["retcode"].get<int32>() ? j["msg"].get<string>() : "";
	}
	string getGroupChatLv(int64 bot, int64 group, int64 qq) {
		return t2s(raw::GetGroupChatLv(l2t(bot), l2t(group), l2t(qq)));
	}
	string getSessionKey(int64 bot) {
		return t2s(raw::SessionKey(l2t(bot)));
	}
	string getClientkey(int64 bot) {
		return t2s(raw::GetClientkey(l2t(bot)));
	}
	string getLongClientkey(int64 bot) {
		return t2s(raw::GetLongClientkey(l2t(bot)));
	}
	string getLongLdw(int64 bot) {
		return t2s(raw::GetLongLdw(l2t(bot)));
	}
	string getBkn(int64 bot) {
		return t2s(raw::GetBkn(l2t(bot)));
	}
	string getLongBkn(int64 bot) {
		return t2s(raw::GetBkn32(l2t(bot)));
	}
	string getPskey(int64 bot, string url) {
		string p = "";
		if (url == "t.qq.com") {
			p = t2s(raw::GetBlogPsKey(l2t(bot)));
		}
		else if (url == "qzone.qq.com") {
			p = t2s(raw::GetZonePsKey(l2t(bot)));
		}
		else if (url == "qun.qq.com") {
			p = t2s(raw::GetGroupPsKey(l2t(bot)));
		}
		else if (url == "ke.qq.com") {
			p = t2s(raw::GetClassRoomPsKey(l2t(bot)));
		}
		return p;
	}
	string getCookies(int64 bot) {
		return t2s(raw::GetCookies(l2t(bot)));
	}
}