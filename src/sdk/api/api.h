#pragma once

#ifndef _API_H_
#define _API_H_
#include"../util/type.h"
namespace code {
	//艾特某人
	string at(int64 qq);
	string face(int32 id);
	string image(string path);
}
namespace api {
	//取框架版本名，返回ERbot Air或ERbot Pro
	string getFrameName();
	//取框架版本号
	string getVer();
	//取当前框架内部时间戳
	int32 getTimeStamp();
	//取框架日志
	string getLog();
	//是否启用
	bool isEnable();
	//禁用插件自身
	void disabledPlugin();
	//输出日志，在框架记录页输出一行信息
	void log(string msg);
	void log(int32 msg);
	void log(int64 msg);
	//取昵称
	string getNick(int64 bot, int64 qq);
	//发送普通文本消息
	void sendMsg(target tar, string msg);
	//发送XML文本消息
	void sendXml(target tar, string msg);
	//发送JSON文本消息
	void sendJson(target tar, string msg);
	//发送好友普通文本消息
	void sendFriendMsg(int64 bot, int64 qq, string msg);
	//发送群普通文本消息
	void sendGroupMsg(int64 bot, int64 group, string msg);
	//发送讨论组普通文本消息
	void sendDiscussMsg(int64 bot, int64 discuss, string msg);
	//发送群临时普通文本消息
	void sendGruopTempMsg(int64 bot, int64 group, int64 qq, string msg);
	//发送讨论组临时普通文本消息
	void sendDiscussTempMsg(int64 bot, int64 discuss, int64 qq, string msg);
	//发送网页临时普通文本消息
	void sendWebTempMsg(int64 bot, int64 qq, string msg);
	//发送好友验证回复普通文本消息
	void sendFriendVerifyMsg(int64 bot, int64 qq, string msg);
	//发送好友XML消息
	void sendFriendXml(int64 bot, int64 qq, string msg);
	//发送群XML消息
	void sendGroupXml(int64 bot, int64 group, string msg);
	//发送讨论组XML消息
	void sendDiscussXml(int64 bot, int64 discuss, string msg);
	//发送群临时XML消息
	void sendGruopTempXml(int64 bot, int64 group, int64 qq, string msg);
	//发送讨论组临时XML消息
	void sendDiscussTempXml(int64 bot, int64 discuss, int64 qq, string msg);
	//发送网页临时XML消息
	void sendWebTempXml(int64 bot, int64 qq, string msg);
	//发送好友验证回复XML消息
	void sendFriendVerifyXml(int64 bot, int64 qq, string msg);
	//发送好友JSON消息
	void sendFriendJson(int64 bot, int64 qq, string msg);
	//发送群JSON消息
	void sendGroupJson(int64 bot, int64 group, string msg);
	//发送讨论组JSON消息
	void sendDiscussJson(int64 bot, int64 discuss, string msg);
	//发送群临时JSON消息
	void sendGruopTempJson(int64 bot, int64 group, int64 qq, string msg);
	//发送讨论组临时JSON消息
	void sendDiscussTempJson(int64 bot, int64 discuss, int64 qq, string msg);
	//发送网页临时JSON消息
	void sendWebTempJson(int64 bot, int64 qq, string msg);
	//发送好友验证回复JSON消息
	void sendFriendVerifyJson(int64 bot, int64 qq, string msg);
	//取好友列表
	vector<FriendListInfo> getFriendList(int64 bot);
	//取好友账号列表
	vector<int64> getFriendNumberList(int64 bot);
	//取群列表
	vector<GroupListInfo> getGroupList(int64 bot);
	//取群号列表
	vector<int64> getGroupNumberList(int64 bot);
	//取群成员列表
	GroupMemberListInfo getGroupMemberList(int64 bot, int64 group);
	//取群成员账号列表
	vector<int64> getGroupMemberNumberList(int64 bot, int64 group);
	//取群管理员账号列表
	vector<int64> getGroupAdminList(int64 bot, int64 group);
	//取机器人状态信息
	BotInfo getStateInfo(int64 bot);
	//置机器人状态, 设置机器人在线状态+附加信息
	void setStatus(int64 bot, int32 state, string msg);
	//取群公告
	string getGroupNotice(int64 bot, int64 group);
	//取图片链接, 根据图片码取得图片下载连接
	string getPicLink(int64 bot, int64 group, string msg);
	//上传群语音, 上传QQ语音，成功返回语音GUID  失败返回空字符串
	string uploadGroupVoice(int64 bot, int64 group, bin voice);
	//上传群聊图片, 上传群或讨论组图片，成功返回该图片GUID，失败返回空字符串
	string uploadGroupPic(int64 bot, int64 group, bin pic);
	//上传私聊图片, 上传好友或临时会话图片 ，成功返回该图片GUID，失败返回空字符串
	string uploadPrivatePic(int64 bot, int64 qq, bin pic);
	//申请加群, 申请加群.为了避免广告、群发行为。出现验证码时将会直接失败不处理  ER Pro才可用
	bool joinGroup(int64 bot, int64 group, string msg);
	//退出群
	void quitGroup(int64 bot, int64 group);
	//发送好友语音, 好友语音上传并发送  ER Pro才可用
	bool sendFriendVoice(int64 bot, int64 qq, bin voice);
	//申请加好友, 主动加好友, 当对象设置需要正确回答问题或不允许任何人添加时无条件失败   Pro才可用
	bool addFriend(int64 bot, int64 qq, string msg);
	//置好友黑名单, 将好友拉入黑名单或解除
	void setBlackList(int64 bot, int64 qq, bool black);
	//置群成员禁言, 禁言群成员
	bool ban(int64 bot, int64 group, int64 qq, int32 time);
	//置全体禁言, 禁言群
	bool allBan(int64 bot, int64 group, bool enable);
	//取群成员是否被禁言, 根据群号 + QQ判断指定群员是否被禁言  获取失败的情况下亦会返回false
	bool isBan(int64 bot, int64 group, int64 qq);
	//置群匿名开关, 开关群匿名消息发送功能
	bool setAnon(int64 bot, int64 group, bool enable);
	//取讨论组号列表
	vector<int64> getDiscussList(int64 bot);
	//取讨论组成员账号列表
	vector<int64> getDiscussMemberList(int64 bot, int64 discuss);
	//发送好友窗口抖动, 向好友发起窗口抖动，调用此Api腾讯会限制频率
	bool shakeWindow(int64 bot, int64 qq);
	//取好友信息, 获取好友资料 此方式为http，调用时应自行注意控制频率
	FriendInfo getFriendInfo(int64 bot, int64 qq);
	//取好友等级, 返回好友等级
	int32 getFriendLevel(int64 bot, int64 qq);
	//删除好友
	bool deleteFriend(int64 bot, int64 qq);
	//置群屏蔽, 屏蔽或接收某群消息
	void setShieldedGroup(int64 bot, int64 group, bool enable);
	//置群管理员, 设置或取消群管理员
	bool setAdmin(int64 bot, int64 group, int64 qq, bool enable);
	//撤回群消息, 消息撤回（成功返回空，失败返回腾讯给出的理由）
	string withdrawMsg(int64 bot, int64 group, int64 flag, int32 id);
	//置输入状态, 置正在输入状态（发送消息后会打断状态）
	void setInput(int64 bot, int64 qq);
	//取目标好友添加方式, 取对象好友添加验证方式 返回常量 VERIFY_
	int32 getQQAddMode(int64 bot, int64 qq);
	//取好友是否在线, 查询对象是否在线
	bool isOnline(int64 bot, int64 qq);
	//取好友在线状态, 整数型, 公开, 查询对象在线状态   返回常量 STATUS_ 离线也返回隐身
	int32 getOnlineState(int64 bot, int64 qq);
	//取群人数, 查询对象群当前人数和上限人数
	int32 getGroupMemberNum(int64 bot, int64 group, int32& max);
	int32 getGroupMemberNum(int64 bot, int64 group);
	//是否允许网页临时会话, 查询对方是否允许网页咨询发起的临时会话消息（非讨论组和群临时）
	bool getWpa(int64 bot, int64 qq);
	//发送群签到, QQ群签到
	bool signIn(int64 bot, int64 group, string location, string content);
	//取群成员名片
	string getGroupCard(int64 bot, int64 group, int64 qq);
	//取群名
	string getGroupName(int64 bot, int64 group);
	//添加账号, 向框架帐号列表添加一个Q.当该Q已存在时则覆盖密码  ER Pro才可用
	bool addQQ(int64 bot, string password, bool autologin);
	//删除账号, 删除框架帐号列表内指定QQ，不可在执行登录过程中删除QQ否则有几率引起错误   ER Pro才可用
	void delQQ(int64 bot);
	//登录账号, 登录指定QQ，应确保QQ号码在列表中已存在
	void login(int64 bot);
	//退出账号, 令指定QQ下线，应确保QQ号码已在列表中且在线
	void logout(int64 bot);
	//是否是好友, 是否QQ好友（双向）
	bool isFriend(int64 bot, int64 qq);
	//点赞, 调用一次点一下，成功返回空，失败返回理由如：每天最多给他点十个赞哦，调用此Api时应注意频率，每人每日可被赞10次，每日每Q最多可赞50人
	string like(int64 bot, int64 qq);
	//置群成员名片, 修改对象群名片
	bool setGroupCard(int64 bot, int64 group, int64 qq, string card);
	//置群成员踢出, 将对象移除群
	void kickGroupMember(int64 bot, int64 group, int64 qq, bool block);
	//退出讨论组
	void quitDiscuss(int64 bot, int64 discuss);
	//置讨论组成员踢出, 将对象移除讨论组
	void KickDiscussMember(int64 bot, int64 discuss, int64 qq);
	//置讨论组名称, 修改讨论组名称
	void setDiscussName(int64 bot, int64 discuss, string name);
	//置好友备注, 修改好友备注姓名
	void setFriendsRemark(int64 bot, int64 qq, string remark);
	//取好友备注, 取好友备注姓名（成功返回备注，失败或无备注返回空）
	string getFriendsRemark(int64 bot, int64 qq);
	//取框架全部QQ, 取框架所有QQ列表 包括未登录以及登录失败的QQ
	vector<int64> getQQList();
	//取框架在线QQ, 取框架在线可用的QQ列表
	vector<int64> getOnlineQQlist();
	//取框架离线QQ, 取框架离线QQ列表
	vector<int64> getOffLineList();
	//取好友QQ达人天数, 查询对象或自身QQ达人天数（返回实际天数 失败返回 - 1）
	int32 getExpertDays(int64 bot, int64 qq);
	//取语音下载地址
	string getVoiceLink(int64 bot, string msg);
	//处理群验证事件
	void handleGroupEvent(int64 bot, int32 type, int64 qq, int64 group, int64 seq, int32 method, string msg);
	//处理好友验证事件, 某人请求添加好友验证处理
	void handleFriendEvent(int64 bot, int64 qq, int32 method, string msg);
	//取讨论组名称
	string getDiscussName(int64 bot, int64 discuss);
	//置机器人昵称
	void setNick(int64 bot, string nick);
	//置机器人性别
	void setGender(int64 bot, int32 gender);
	//置个性签名
	void setSign(int64 bot, string sign);
	//取好友性别, 1男 2女  未知或失败返回 - 1
	int32 getGender(int64 bot, int64 qq);
	//取好友Q龄, 成功返回Q龄 失败返回 - 1
	int32 getQQAge(int64 bot, int64 qq);
	//取好友年龄, 成功返回年龄 失败返回 - 1
	int32 getAge(int64 bot, int64 qq);
	//取好友个性签名
	string getSign(int64 bot, int64 qq);
	//取好友个人说明
	string getPerExp(int64 bot, int64 qq);
	//取好友邮箱
	string getEmail(int64 bot, int64 qq);
	//置头像, 上传头像
	bool setHead(int64 bot, bin pic);
	//置封面
	bool setPhotoWall(int64 bot, bin pic);
	//取讨论组链接, 通过讨论组号获取加群连接
	string getDiscussLink(int64 bot, int64 discuss);
	//加入讨论组_链接, 通过连接加入讨论组
	string joinDiscuss(int64 bot, string link);
	//邀请好友加入讨论组, 成功返回空 失败返回理由
	string inviteDiscuss(int64 bot, int64 discuss, int64 qq);
	//创建讨论组, 创建一个讨论组 成功返回讨论组ID 失败返回原因
	string createDiscuss(int64 bot, int64 qq);
	//邀请好友入群_管理员, 管理员邀请对象入群，频率过快会失败
	void adminInviteGroup(int64 bot, int64 group, int64 qq);
	//邀请好友入群_群员, 非管理员邀请对象入群，频率过快会失败
	void noAdminInviteGroup(int64 bot, int64 group, int64 qq);
	//TEA加密
	string teaEncrypt(string content, string key);
	//TEA解密
	string teaDecrypt(string content, string key);
	//取群ID, 群号转群ID
	int64 getGroupID(int64 group);
	//取群号, 群ID转群号
	int64 getGroupNumber(int64 group);
	//发送数据包, 向服务器发送原始封包（成功返回服务器返回的包 失败返回空）
	string sendPack(int64 bot, string pack);
	//取等级, 获取等级 活跃天数 升级剩余活跃天数
	GradeInfo getQQLevel(int64 bot);
	//发布群公告，调用此API应保证响应QQ为管理员 成功返回空, 失败返回错误信息
	string publicGroupNotic(int64 bot, int64 group, string title, string content);
	//抽取群礼物，需群聊等级LV5后  貌似已失效
	int32 takeGift(int64 bot);
	//查询群礼物  ER Pro才可用
	vector<GiftInfo> checkGift(int64 bot);
	//发送群礼物, 送群礼物
	bool sendGift(int64 bot, int64 group, int64 qq, int32 giftid);
	//发布群作业, QQ群作业发布
	string publicHomeWork(int64 bot, int64 group, string name, string title, string content);
	//取成员群聊等级, 查询对象或自身群聊等级
	string getGroupChatLv(int64 bot, int64 group, int64 qq);
	//取SessionKey, 获取会话SessionKey密钥  Pro可用
	string getSessionKey(int64 bot);
	//取Clientkey, 取得机器人网页操作用参数Clientkey  Pro可用
	string getClientkey(int64 bot);
	//取长Clientkey, 取得机器人网页操作用参数长Clientkey  Pro可用
	string getLongClientkey(int64 bot);
	//取长Ldw, 取得机器人网页操作用参数长Ldw  Pro可用
	string getLongLdw(int64 bot);
	//取Bkn, 取得机器人网页操作用参数Bkn或G_tk  Pro可用
	string getBkn(int64 bot);
	//取长Bkn, 取得机器人网页操作用参数长Bkn或长G_tk  Pro可用
	string getLongBkn(int64 bot);
	//取pskey, 取得机器人网页操作用的P_skey  Pro可用
	string getPskey(int64 bot, string url);
	//取Cookies, 取得机器人网页操作用的Cookies  Pro可用
	string getCookies(int64 bot);
}
#endif