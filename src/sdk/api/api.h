#pragma once

#ifndef _API_H_
#define _API_H_
#include"../util/type.h"
namespace code {
	//����ĳ��
	string at(int64 qq);
	string face(int32 id);
	string image(string path);
}
namespace api {
	//ȡ��ܰ汾��������ERbot Air��ERbot Pro
	string getFrameName();
	//ȡ��ܰ汾��
	string getVer();
	//ȡ��ǰ����ڲ�ʱ���
	int32 getTimeStamp();
	//ȡ�����־
	string getLog();
	//�Ƿ�����
	bool isEnable();
	//���ò������
	void disabledPlugin();
	//�����־���ڿ�ܼ�¼ҳ���һ����Ϣ
	void log(string msg);
	void log(int32 msg);
	void log(int64 msg);
	//ȡ�ǳ�
	string getNick(int64 bot, int64 qq);
	//������ͨ�ı���Ϣ
	void sendMsg(target tar, string msg);
	//����XML�ı���Ϣ
	void sendXml(target tar, string msg);
	//����JSON�ı���Ϣ
	void sendJson(target tar, string msg);
	//���ͺ�����ͨ�ı���Ϣ
	void sendFriendMsg(int64 bot, int64 qq, string msg);
	//����Ⱥ��ͨ�ı���Ϣ
	void sendGroupMsg(int64 bot, int64 group, string msg);
	//������������ͨ�ı���Ϣ
	void sendDiscussMsg(int64 bot, int64 discuss, string msg);
	//����Ⱥ��ʱ��ͨ�ı���Ϣ
	void sendGruopTempMsg(int64 bot, int64 group, int64 qq, string msg);
	//������������ʱ��ͨ�ı���Ϣ
	void sendDiscussTempMsg(int64 bot, int64 discuss, int64 qq, string msg);
	//������ҳ��ʱ��ͨ�ı���Ϣ
	void sendWebTempMsg(int64 bot, int64 qq, string msg);
	//���ͺ�����֤�ظ���ͨ�ı���Ϣ
	void sendFriendVerifyMsg(int64 bot, int64 qq, string msg);
	//���ͺ���XML��Ϣ
	void sendFriendXml(int64 bot, int64 qq, string msg);
	//����ȺXML��Ϣ
	void sendGroupXml(int64 bot, int64 group, string msg);
	//����������XML��Ϣ
	void sendDiscussXml(int64 bot, int64 discuss, string msg);
	//����Ⱥ��ʱXML��Ϣ
	void sendGruopTempXml(int64 bot, int64 group, int64 qq, string msg);
	//������������ʱXML��Ϣ
	void sendDiscussTempXml(int64 bot, int64 discuss, int64 qq, string msg);
	//������ҳ��ʱXML��Ϣ
	void sendWebTempXml(int64 bot, int64 qq, string msg);
	//���ͺ�����֤�ظ�XML��Ϣ
	void sendFriendVerifyXml(int64 bot, int64 qq, string msg);
	//���ͺ���JSON��Ϣ
	void sendFriendJson(int64 bot, int64 qq, string msg);
	//����ȺJSON��Ϣ
	void sendGroupJson(int64 bot, int64 group, string msg);
	//����������JSON��Ϣ
	void sendDiscussJson(int64 bot, int64 discuss, string msg);
	//����Ⱥ��ʱJSON��Ϣ
	void sendGruopTempJson(int64 bot, int64 group, int64 qq, string msg);
	//������������ʱJSON��Ϣ
	void sendDiscussTempJson(int64 bot, int64 discuss, int64 qq, string msg);
	//������ҳ��ʱJSON��Ϣ
	void sendWebTempJson(int64 bot, int64 qq, string msg);
	//���ͺ�����֤�ظ�JSON��Ϣ
	void sendFriendVerifyJson(int64 bot, int64 qq, string msg);
	//ȡ�����б�
	vector<FriendListInfo> getFriendList(int64 bot);
	//ȡ�����˺��б�
	vector<int64> getFriendNumberList(int64 bot);
	//ȡȺ�б�
	vector<GroupListInfo> getGroupList(int64 bot);
	//ȡȺ���б�
	vector<int64> getGroupNumberList(int64 bot);
	//ȡȺ��Ա�б�
	GroupMemberListInfo getGroupMemberList(int64 bot, int64 group);
	//ȡȺ��Ա�˺��б�
	vector<int64> getGroupMemberNumberList(int64 bot, int64 group);
	//ȡȺ����Ա�˺��б�
	vector<int64> getGroupAdminList(int64 bot, int64 group);
	//ȡ������״̬��Ϣ
	BotInfo getStateInfo(int64 bot);
	//�û�����״̬, ���û���������״̬+������Ϣ
	void setStatus(int64 bot, int32 state, string msg);
	//ȡȺ����
	string getGroupNotice(int64 bot, int64 group);
	//ȡͼƬ����, ����ͼƬ��ȡ��ͼƬ��������
	string getPicLink(int64 bot, int64 group, string msg);
	//�ϴ�Ⱥ����, �ϴ�QQ�������ɹ���������GUID  ʧ�ܷ��ؿ��ַ���
	string uploadGroupVoice(int64 bot, int64 group, bin voice);
	//�ϴ�Ⱥ��ͼƬ, �ϴ�Ⱥ��������ͼƬ���ɹ����ظ�ͼƬGUID��ʧ�ܷ��ؿ��ַ���
	string uploadGroupPic(int64 bot, int64 group, bin pic);
	//�ϴ�˽��ͼƬ, �ϴ����ѻ���ʱ�ỰͼƬ ���ɹ����ظ�ͼƬGUID��ʧ�ܷ��ؿ��ַ���
	string uploadPrivatePic(int64 bot, int64 qq, bin pic);
	//�����Ⱥ, �����Ⱥ.Ϊ�˱����桢Ⱥ����Ϊ��������֤��ʱ����ֱ��ʧ�ܲ�����  ER Pro�ſ���
	bool joinGroup(int64 bot, int64 group, string msg);
	//�˳�Ⱥ
	void quitGroup(int64 bot, int64 group);
	//���ͺ�������, ���������ϴ�������  ER Pro�ſ���
	bool sendFriendVoice(int64 bot, int64 qq, bin voice);
	//����Ӻ���, �����Ӻ���, ������������Ҫ��ȷ�ش�����������κ������ʱ������ʧ��   Pro�ſ���
	bool addFriend(int64 bot, int64 qq, string msg);
	//�ú��Ѻ�����, �������������������
	void setBlackList(int64 bot, int64 qq, bool black);
	//��Ⱥ��Ա����, ����Ⱥ��Ա
	bool ban(int64 bot, int64 group, int64 qq, int32 time);
	//��ȫ�����, ����Ⱥ
	bool allBan(int64 bot, int64 group, bool enable);
	//ȡȺ��Ա�Ƿ񱻽���, ����Ⱥ�� + QQ�ж�ָ��ȺԱ�Ƿ񱻽���  ��ȡʧ�ܵ��������᷵��false
	bool isBan(int64 bot, int64 group, int64 qq);
	//��Ⱥ��������, ����Ⱥ������Ϣ���͹���
	bool setAnon(int64 bot, int64 group, bool enable);
	//ȡ��������б�
	vector<int64> getDiscussList(int64 bot);
	//ȡ�������Ա�˺��б�
	vector<int64> getDiscussMemberList(int64 bot, int64 discuss);
	//���ͺ��Ѵ��ڶ���, ����ѷ��𴰿ڶ��������ô�Api��Ѷ������Ƶ��
	bool shakeWindow(int64 bot, int64 qq);
	//ȡ������Ϣ, ��ȡ�������� �˷�ʽΪhttp������ʱӦ����ע�����Ƶ��
	FriendInfo getFriendInfo(int64 bot, int64 qq);
	//ȡ���ѵȼ�, ���غ��ѵȼ�
	int32 getFriendLevel(int64 bot, int64 qq);
	//ɾ������
	bool deleteFriend(int64 bot, int64 qq);
	//��Ⱥ����, ���λ����ĳȺ��Ϣ
	void setShieldedGroup(int64 bot, int64 group, bool enable);
	//��Ⱥ����Ա, ���û�ȡ��Ⱥ����Ա
	bool setAdmin(int64 bot, int64 group, int64 qq, bool enable);
	//����Ⱥ��Ϣ, ��Ϣ���أ��ɹ����ؿգ�ʧ�ܷ�����Ѷ���������ɣ�
	string withdrawMsg(int64 bot, int64 group, int64 flag, int32 id);
	//������״̬, ����������״̬��������Ϣ�����״̬��
	void setInput(int64 bot, int64 qq);
	//ȡĿ�������ӷ�ʽ, ȡ������������֤��ʽ ���س��� VERIFY_
	int32 getQQAddMode(int64 bot, int64 qq);
	//ȡ�����Ƿ�����, ��ѯ�����Ƿ�����
	bool isOnline(int64 bot, int64 qq);
	//ȡ��������״̬, ������, ����, ��ѯ��������״̬   ���س��� STATUS_ ����Ҳ��������
	int32 getOnlineState(int64 bot, int64 qq);
	//ȡȺ����, ��ѯ����Ⱥ��ǰ��������������
	int32 getGroupMemberNum(int64 bot, int64 group, int32& max);
	int32 getGroupMemberNum(int64 bot, int64 group);
	//�Ƿ�������ҳ��ʱ�Ự, ��ѯ�Է��Ƿ�������ҳ��ѯ�������ʱ�Ự��Ϣ�����������Ⱥ��ʱ��
	bool getWpa(int64 bot, int64 qq);
	//����Ⱥǩ��, QQȺǩ��
	bool signIn(int64 bot, int64 group, string location, string content);
	//ȡȺ��Ա��Ƭ
	string getGroupCard(int64 bot, int64 group, int64 qq);
	//ȡȺ��
	string getGroupName(int64 bot, int64 group);
	//����˺�, �����ʺ��б����һ��Q.����Q�Ѵ���ʱ�򸲸�����  ER Pro�ſ���
	bool addQQ(int64 bot, string password, bool autologin);
	//ɾ���˺�, ɾ������ʺ��б���ָ��QQ��������ִ�е�¼������ɾ��QQ�����м����������   ER Pro�ſ���
	void delQQ(int64 bot);
	//��¼�˺�, ��¼ָ��QQ��Ӧȷ��QQ�������б����Ѵ���
	void login(int64 bot);
	//�˳��˺�, ��ָ��QQ���ߣ�Ӧȷ��QQ���������б���������
	void logout(int64 bot);
	//�Ƿ��Ǻ���, �Ƿ�QQ���ѣ�˫��
	bool isFriend(int64 bot, int64 qq);
	//����, ����һ�ε�һ�£��ɹ����ؿգ�ʧ�ܷ��������磺ÿ����������ʮ����Ŷ�����ô�ApiʱӦע��Ƶ�ʣ�ÿ��ÿ�տɱ���10�Σ�ÿ��ÿQ������50��
	string like(int64 bot, int64 qq);
	//��Ⱥ��Ա��Ƭ, �޸Ķ���Ⱥ��Ƭ
	bool setGroupCard(int64 bot, int64 group, int64 qq, string card);
	//��Ⱥ��Ա�߳�, �������Ƴ�Ⱥ
	void kickGroupMember(int64 bot, int64 group, int64 qq, bool block);
	//�˳�������
	void quitDiscuss(int64 bot, int64 discuss);
	//���������Ա�߳�, �������Ƴ�������
	void KickDiscussMember(int64 bot, int64 discuss, int64 qq);
	//������������, �޸�����������
	void setDiscussName(int64 bot, int64 discuss, string name);
	//�ú��ѱ�ע, �޸ĺ��ѱ�ע����
	void setFriendsRemark(int64 bot, int64 qq, string remark);
	//ȡ���ѱ�ע, ȡ���ѱ�ע�������ɹ����ر�ע��ʧ�ܻ��ޱ�ע���ؿգ�
	string getFriendsRemark(int64 bot, int64 qq);
	//ȡ���ȫ��QQ, ȡ�������QQ�б� ����δ��¼�Լ���¼ʧ�ܵ�QQ
	vector<int64> getQQList();
	//ȡ�������QQ, ȡ������߿��õ�QQ�б�
	vector<int64> getOnlineQQlist();
	//ȡ�������QQ, ȡ�������QQ�б�
	vector<int64> getOffLineList();
	//ȡ����QQ��������, ��ѯ���������QQ��������������ʵ������ ʧ�ܷ��� - 1��
	int32 getExpertDays(int64 bot, int64 qq);
	//ȡ�������ص�ַ
	string getVoiceLink(int64 bot, string msg);
	//����Ⱥ��֤�¼�
	void handleGroupEvent(int64 bot, int32 type, int64 qq, int64 group, int64 seq, int32 method, string msg);
	//���������֤�¼�, ĳ��������Ӻ�����֤����
	void handleFriendEvent(int64 bot, int64 qq, int32 method, string msg);
	//ȡ����������
	string getDiscussName(int64 bot, int64 discuss);
	//�û������ǳ�
	void setNick(int64 bot, string nick);
	//�û������Ա�
	void setGender(int64 bot, int32 gender);
	//�ø���ǩ��
	void setSign(int64 bot, string sign);
	//ȡ�����Ա�, 1�� 2Ů  δ֪��ʧ�ܷ��� - 1
	int32 getGender(int64 bot, int64 qq);
	//ȡ����Q��, �ɹ�����Q�� ʧ�ܷ��� - 1
	int32 getQQAge(int64 bot, int64 qq);
	//ȡ��������, �ɹ��������� ʧ�ܷ��� - 1
	int32 getAge(int64 bot, int64 qq);
	//ȡ���Ѹ���ǩ��
	string getSign(int64 bot, int64 qq);
	//ȡ���Ѹ���˵��
	string getPerExp(int64 bot, int64 qq);
	//ȡ��������
	string getEmail(int64 bot, int64 qq);
	//��ͷ��, �ϴ�ͷ��
	bool setHead(int64 bot, bin pic);
	//�÷���
	bool setPhotoWall(int64 bot, bin pic);
	//ȡ����������, ͨ��������Ż�ȡ��Ⱥ����
	string getDiscussLink(int64 bot, int64 discuss);
	//����������_����, ͨ�����Ӽ���������
	string joinDiscuss(int64 bot, string link);
	//������Ѽ���������, �ɹ����ؿ� ʧ�ܷ�������
	string inviteDiscuss(int64 bot, int64 discuss, int64 qq);
	//����������, ����һ�������� �ɹ�����������ID ʧ�ܷ���ԭ��
	string createDiscuss(int64 bot, int64 qq);
	//���������Ⱥ_����Ա, ����Ա���������Ⱥ��Ƶ�ʹ����ʧ��
	void adminInviteGroup(int64 bot, int64 group, int64 qq);
	//���������Ⱥ_ȺԱ, �ǹ���Ա���������Ⱥ��Ƶ�ʹ����ʧ��
	void noAdminInviteGroup(int64 bot, int64 group, int64 qq);
	//TEA����
	string teaEncrypt(string content, string key);
	//TEA����
	string teaDecrypt(string content, string key);
	//ȡȺID, Ⱥ��תȺID
	int64 getGroupID(int64 group);
	//ȡȺ��, ȺIDתȺ��
	int64 getGroupNumber(int64 group);
	//�������ݰ�, �����������ԭʼ������ɹ����ط��������صİ� ʧ�ܷ��ؿգ�
	string sendPack(int64 bot, string pack);
	//ȡ�ȼ�, ��ȡ�ȼ� ��Ծ���� ����ʣ���Ծ����
	GradeInfo getQQLevel(int64 bot);
	//����Ⱥ���棬���ô�APIӦ��֤��ӦQQΪ����Ա �ɹ����ؿ�, ʧ�ܷ��ش�����Ϣ
	string publicGroupNotic(int64 bot, int64 group, string title, string content);
	//��ȡȺ�����Ⱥ�ĵȼ�LV5��  ò����ʧЧ
	int32 takeGift(int64 bot);
	//��ѯȺ����  ER Pro�ſ���
	vector<GiftInfo> checkGift(int64 bot);
	//����Ⱥ����, ��Ⱥ����
	bool sendGift(int64 bot, int64 group, int64 qq, int32 giftid);
	//����Ⱥ��ҵ, QQȺ��ҵ����
	string publicHomeWork(int64 bot, int64 group, string name, string title, string content);
	//ȡ��ԱȺ�ĵȼ�, ��ѯ���������Ⱥ�ĵȼ�
	string getGroupChatLv(int64 bot, int64 group, int64 qq);
	//ȡSessionKey, ��ȡ�ỰSessionKey��Կ  Pro����
	string getSessionKey(int64 bot);
	//ȡClientkey, ȡ�û�������ҳ�����ò���Clientkey  Pro����
	string getClientkey(int64 bot);
	//ȡ��Clientkey, ȡ�û�������ҳ�����ò�����Clientkey  Pro����
	string getLongClientkey(int64 bot);
	//ȡ��Ldw, ȡ�û�������ҳ�����ò�����Ldw  Pro����
	string getLongLdw(int64 bot);
	//ȡBkn, ȡ�û�������ҳ�����ò���Bkn��G_tk  Pro����
	string getBkn(int64 bot);
	//ȡ��Bkn, ȡ�û�������ҳ�����ò�����Bkn��G_tk  Pro����
	string getLongBkn(int64 bot);
	//ȡpskey, ȡ�û�������ҳ�����õ�P_skey  Pro����
	string getPskey(int64 bot, string url);
	//ȡCookies, ȡ�û�������ҳ�����õ�Cookies  Pro����
	string getCookies(int64 bot);
}
#endif