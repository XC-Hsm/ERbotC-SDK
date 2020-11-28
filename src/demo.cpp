#include"sdk/sdk.h"

ERbot{
	INFO{
		info.name = "demo";
		info.author = "星尘";
		info.version = "1.0.0.0";
		info.desc = "基于C++SDK的空白插件";
	}
	EVENT{
		//初始化
		/*onInit([]() {
			//插件被加载到框架时触发本事件,通常发生在框架启动或用户安装插件后
			api::log("初始化");
			return true;//true 允许启用 false 禁止启用
		});
		/*被启用
		onEnable([]() {
			//插件被启用后触发本事件,用于插件加载配置启动服务
			api::log("已启用");
		});*/
		/*被禁用
		//onDisable([]() {
			//插件被禁用、被卸载或框架退出时触发本事件,用于结束服务释放资源
			api::log("被禁用");
		});*/
		/*打开设置
		onSet([]() {
			//此处加载插件设置窗口
			MessageBoxW(NULL,L"这是一个设置窗口",L"设置",MB_OK);
		});*/
		/*收到私聊消息
		onPrivateMessage([](PrivateMessage e) {
			return QUEUE_IGNORE;
		});*/
		//收到群消息
		onGroupMessage([](GroupMessage e) {
			api::sendMsg(e.target, code::at(e.qq) + "您发送了一条消息:" + e.msg);
			return QUEUE_IGNORE;
		});
		/*收到讨论组消息
		onDiscussMessage([](DiscussMessage e) {
			return QUEUE_IGNORE;
		});*/
		/*好友添加请求
		onFriendAddRequest([](FriendAddRequest e) {
			return QUEUE_IGNORE;
		});*/
		/*好友添加响应
		onFriendAddResponse([](FriendAddResponse e) {
			return QUEUE_IGNORE;
		});*/
		/*被好友删除
		onBeFriendDelete([](BeFriendDelete e) {
			return QUEUE_IGNORE;
		});*/
		/*群添加请求
		onGroupAddRequest([](GroupAddRequest e) {
			return QUEUE_IGNORE;
		});*/
		/*群成员加入
		onGroupMemberIncrease([](GroupMemberIncrease e) {
			return QUEUE_IGNORE;
		});*/
		/*群成员离开
		onGroupMemberDecrease([](GroupMemberDecrease e) {
			return QUEUE_IGNORE;
		});*/
		/*群被解散
		onGroupDissmiss([](GroupDissmiss e) {
			return QUEUE_IGNORE;
		});*/
		/*群管理员改变
		onGroupManagerChange([](GroupManagerChange e) {
			return QUEUE_IGNORE;
		});*/
		/*群成员名片改变
		onGroupMemberCardChange([](GroupMemberCardChange e) {
			return QUEUE_IGNORE;
		});*/
		/*群名改变
		onGroupNameChange([](GroupNameChange e) {
			return QUEUE_IGNORE;
		});*/
		/*群禁言
		onGroupBanSpeak([](GroupBanSpeak e) {
			return QUEUE_IGNORE;
		});*/
		/*群成员禁言
		onGroupMemberBanSpeak([](GroupMemberBanSpeak e) {
			return QUEUE_IGNORE;
		});*/
		/*群匿名改变
		onGroupAnonymousChange([](GroupAnonymousChange e) {
			return QUEUE_IGNORE;
		});*/
		/*群撤回消息
		onGroupMemberRemoveMessage([](GroupMemberRemoveMessage e) {
			return QUEUE_IGNORE;
		});*/
	}
}