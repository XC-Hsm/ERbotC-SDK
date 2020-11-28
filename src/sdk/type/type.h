#pragma once

#ifndef _TYPE_H_
#define _TYPE_H_
#define WIN32_LEAN_AND_MEAN
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<vector>
#include"../third_party/json.hpp"
using namespace std;
using json = nlohmann::json;
typedef signed char             int8;
typedef unsigned char           uint8;
typedef short int               int16;
typedef int                     int32;
#if __WORDSIZE == 64
typedef long int                int64;
#else
typedef long long int           int64;
#endif
typedef int32					ebool;
typedef const char* text;
typedef const uint8* bin;
string t2s(text text);//GBK编码转ANSI编码
text s2t(string str);//ANSI编码转GBK编码
int64 s2l(string str);
string l2s(int64 num);
int32 s2i(string str);
string i2s(int32 num);
int64 t2l(text text);
text l2t(int64 num);
int32 t2i(text text);
text i2t(int32 num);
string u2s(wstring str);
wstring s2u(string str);
bin f2b(string path);
vector<int64> s2ls(string str, string p);
// 插件信息
struct PluginInfo {
	string name;
	string author;
	string version;
	string desc;
};
// 好友列表信息
struct FriendListInfo {
	int64 id; // QQ号
	string remark; // 备注
	string group; // 所在分组
};
// 群列表信息
struct GroupListInfo {
	int64 id; // 群号
	string name; // 群名
	int64 owner; // 群主QQ
	bool admin; // 是否是管理员，群主时也为true，可通过群主QQ区分
};
// 群成员信息
struct GroupMemberInfo {
	int64 id; // QQ号
	string nick; // 昵称
	string card; // 群名片
	int32 point; // 群活跃积分
	int32 lv; // 群活跃等级
	int64 joinTime; // 加群时间戳，10位
	int64 lastTime; // 最后发言时间戳，10位
	int32 banTime; // 禁言时间，距禁言结束时间，秒
	bool isFriend; // 是否是好友
};
// 群成员列表信息
struct GroupMemberListInfo {
	int32 num; // 群人数
	int32 max; // 群人数上限
	int64 owner; // 群主QQ
	vector<int64> admins; // 群管理员账号列表
	vector<GroupMemberInfo> member; // 群成员信息列表
};
// 机器人状态信息
struct BotInfo {
	int64 id; // QQ号
	string nick; // 昵称
	string state; // 在线状态
	string speed; // 消息速度
	int64 recvNum; // 接收消息数
	int64 sendNum; // 发送消息数
	string onlineTime; // 在线时间
};
// 好友信息
struct FriendInfo {
	int64 id; // QQ号
	string nick; // 昵称
	uint8 gender; // 性别，255隐藏、0男、1女
	int32 age; // 年龄
	string country; // 国家
	string province; // 省份
	string city; // 城市
	string headimg; // 头像地址
};
// 等级信息
struct GradeInfo {
	string vip; // 会员信息
	int32 lv; // 等级
	int32 activeDays; // 活跃天数
	int32 upgradeDays; // 升级剩余天数
};
// 礼物信息
struct GiftInfo {
	int32 id; // 礼物ID
	string name; // 礼物名称
	int32 value; // 礼物价值
	int32 getTime; // 礼物获得时间戳
	int32 expireTime; // 礼物过期时间戳
};
// 消息目标对象
struct target {
	int64 bot; // 对应框架QQ
	int32 type; // 目标类型1.好友. 2.群. 3.讨论组. 4.群临时. 5.讨论组临时. 6. 网页临时. 7.好友验证回复
	int64 group; // 目标群组
	int64 qq; // 目标账号
};
// 私聊消息事件参数
struct PrivateMessage {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1.好友. 2.群临时. 3.讨论组临时. 4. 网页临时. 5.好友验证回复
	target target; // 消息目标对象
	int64 group; // 临时消息的群号或讨论组号
	int64 qq; // 对方QQ号
	int64 flag; // 消息序号
	int32 id; // 消息ID
	string msg; // 消息文本内容
};
// 群消息事件参数
struct GroupMessage {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	target target; // 消息目标对象
	int64 group; // 来源群号
	int64 qq; // 对方QQ号
	int64 flag; // 消息序号
	int32 id; // 消息ID
	string msg; // 消息文本内容
};
// 讨论组消息事件参数
struct DiscussMessage {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	target target; // 消息目标对象
	int64 discuss; // 来源群号
	int64 qq; // 对方QQ号
	int64 flag; // 消息序号
	int32 id; // 消息ID
	string msg; // 消息文本内容
};
// 好友添加请求事件参数
struct FriendAddRequest {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1.单向添加好友. 2.请求添加好友
	int64 qq; // 对方QQ
	string msg; // 附加消息内容
};
// 好友添加响应事件参数
struct FriendAddResponse {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1.同意添加好友. 2. 拒绝添加好友
	int64 qq; // 对方QQ
	string msg; // 拒绝时的附加理由
};
// 被好友删除事件参数
struct BeFriendDelete {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	int64 qq; // 对方QQ
};
// 群添加请求事件参数
struct GroupAddRequest {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1 有人申请加群.  2 某人邀请我加群
	int64 group; // 群号
	int64 qq; // 入群者QQ
	int64 inviter; // 邀请者QQ
};
// 群成员加入事件参数
struct GroupMemberIncrease {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1 某人被批准加入  2 我加入某个群  3 某人被邀请加入了群
	int64 group; // 群号
	int64 qq; // 入群者QQ
	int64 admin; // 审批者或邀请者QQ
};
// 群成员离开事件参数
struct GroupMemberDecrease {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1 某人退群  2 某人被管理踢出群
	int64 group; // 群号
	int64 qq; // 入群者QQ
	int64 admin; // 管理员QQ
};
// 群被解散事件参数
struct GroupDissmiss {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	int64 group; // 群号
	int64 qq; // 解散者QQ
};
// 群管理员改变事件参数
struct GroupManagerChange {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1 某人成为管理  2 某人被取消管理
	int64 group; // 群号
	int64 qq; // 被改变QQ
};
// 群成员名片改变事件参数
struct GroupMemberCardChange {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	int64 group; // 群号
	int64 qq; // 改变者QQ
	string card; // 改变的群名片
};
// 群名改变事件参数
struct GroupNameChange {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	int64 group; // 群号
	string name; // 改变的群名
};
// 群禁言事件参数
struct GroupBanSpeak {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1 开启全群禁言 2 关闭全群禁言
	int64 group; // 群号
	int64 qq; // 管理员QQ
};
// 群成员禁言事件参数
struct GroupMemberBanSpeak {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1. 某人被禁言. 2.某人被解除禁言
	int64 group; // 群号
	int64 qq; // 被禁言QQ
	int64 admin; // 管理员QQ
	int32 time; // 禁言时长, 单位: 秒, 范围: 1秒-30天
};
// 群匿名改变事件参数
struct GroupAnonymousChange {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,1.群匿名开启. 2.群匿名关闭
	int64 group; // 群号
	int64 qq; // 管理员QQ
};
// 群撤回消息事件参数
struct GroupMemberRemoveMessage {
	int64 bot; // 机器人QQ
	int32 type; // 事件子类型,固定为1
	int64 group; // 群号
	int64 qq; // 被禁言QQ
	int64 flag; // 消息序号
	int32 id; // 消息ID
};
// 性别
#define GENDER_MALE 1 // 男性
#define GENDER_FEMALE 2 // 女性
// 在线状态
#define STATUS_ONLINE 1 // 在线
#define STATUS_QME 2 // Q我吧
#define STATUS_LEAVE 3 // 离开
#define STATUS_BUSY 4 // 忙碌
#define STATUS_DND 5 // 请勿打扰
#define STATUS_CLOAKING 6 // 隐身
// 验证方式
#define VERIFY_NONE 0 // 允许任何人添加好友
#define VERIFY_NEED_VERIFYCATION 1 // 需要验证
#define VERIFY_NEED_CORRECT_ANSWER 3 // 需要正确答案
#define VERIFY_NEED_ANSWER_QUESTION 4 // 需要回答问题
#define VERIFY_ALERADY_FRIEND 99 // 已经是好友

#endif