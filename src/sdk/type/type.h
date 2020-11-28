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
string t2s(text text);//GBK����תANSI����
text s2t(string str);//ANSI����תGBK����
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
// �����Ϣ
struct PluginInfo {
	string name;
	string author;
	string version;
	string desc;
};
// �����б���Ϣ
struct FriendListInfo {
	int64 id; // QQ��
	string remark; // ��ע
	string group; // ���ڷ���
};
// Ⱥ�б���Ϣ
struct GroupListInfo {
	int64 id; // Ⱥ��
	string name; // Ⱥ��
	int64 owner; // Ⱥ��QQ
	bool admin; // �Ƿ��ǹ���Ա��Ⱥ��ʱҲΪtrue����ͨ��Ⱥ��QQ����
};
// Ⱥ��Ա��Ϣ
struct GroupMemberInfo {
	int64 id; // QQ��
	string nick; // �ǳ�
	string card; // Ⱥ��Ƭ
	int32 point; // Ⱥ��Ծ����
	int32 lv; // Ⱥ��Ծ�ȼ�
	int64 joinTime; // ��Ⱥʱ�����10λ
	int64 lastTime; // �����ʱ�����10λ
	int32 banTime; // ����ʱ�䣬����Խ���ʱ�䣬��
	bool isFriend; // �Ƿ��Ǻ���
};
// Ⱥ��Ա�б���Ϣ
struct GroupMemberListInfo {
	int32 num; // Ⱥ����
	int32 max; // Ⱥ��������
	int64 owner; // Ⱥ��QQ
	vector<int64> admins; // Ⱥ����Ա�˺��б�
	vector<GroupMemberInfo> member; // Ⱥ��Ա��Ϣ�б�
};
// ������״̬��Ϣ
struct BotInfo {
	int64 id; // QQ��
	string nick; // �ǳ�
	string state; // ����״̬
	string speed; // ��Ϣ�ٶ�
	int64 recvNum; // ������Ϣ��
	int64 sendNum; // ������Ϣ��
	string onlineTime; // ����ʱ��
};
// ������Ϣ
struct FriendInfo {
	int64 id; // QQ��
	string nick; // �ǳ�
	uint8 gender; // �Ա�255���ء�0�С�1Ů
	int32 age; // ����
	string country; // ����
	string province; // ʡ��
	string city; // ����
	string headimg; // ͷ���ַ
};
// �ȼ���Ϣ
struct GradeInfo {
	string vip; // ��Ա��Ϣ
	int32 lv; // �ȼ�
	int32 activeDays; // ��Ծ����
	int32 upgradeDays; // ����ʣ������
};
// ������Ϣ
struct GiftInfo {
	int32 id; // ����ID
	string name; // ��������
	int32 value; // �����ֵ
	int32 getTime; // ������ʱ���
	int32 expireTime; // �������ʱ���
};
// ��ϢĿ�����
struct target {
	int64 bot; // ��Ӧ���QQ
	int32 type; // Ŀ������1.����. 2.Ⱥ. 3.������. 4.Ⱥ��ʱ. 5.��������ʱ. 6. ��ҳ��ʱ. 7.������֤�ظ�
	int64 group; // Ŀ��Ⱥ��
	int64 qq; // Ŀ���˺�
};
// ˽����Ϣ�¼�����
struct PrivateMessage {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1.����. 2.Ⱥ��ʱ. 3.��������ʱ. 4. ��ҳ��ʱ. 5.������֤�ظ�
	target target; // ��ϢĿ�����
	int64 group; // ��ʱ��Ϣ��Ⱥ�Ż��������
	int64 qq; // �Է�QQ��
	int64 flag; // ��Ϣ���
	int32 id; // ��ϢID
	string msg; // ��Ϣ�ı�����
};
// Ⱥ��Ϣ�¼�����
struct GroupMessage {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	target target; // ��ϢĿ�����
	int64 group; // ��ԴȺ��
	int64 qq; // �Է�QQ��
	int64 flag; // ��Ϣ���
	int32 id; // ��ϢID
	string msg; // ��Ϣ�ı�����
};
// ��������Ϣ�¼�����
struct DiscussMessage {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	target target; // ��ϢĿ�����
	int64 discuss; // ��ԴȺ��
	int64 qq; // �Է�QQ��
	int64 flag; // ��Ϣ���
	int32 id; // ��ϢID
	string msg; // ��Ϣ�ı�����
};
// ������������¼�����
struct FriendAddRequest {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1.������Ӻ���. 2.������Ӻ���
	int64 qq; // �Է�QQ
	string msg; // ������Ϣ����
};
// ���������Ӧ�¼�����
struct FriendAddResponse {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1.ͬ����Ӻ���. 2. �ܾ���Ӻ���
	int64 qq; // �Է�QQ
	string msg; // �ܾ�ʱ�ĸ�������
};
// ������ɾ���¼�����
struct BeFriendDelete {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	int64 qq; // �Է�QQ
};
// Ⱥ��������¼�����
struct GroupAddRequest {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1 ���������Ⱥ.  2 ĳ�������Ҽ�Ⱥ
	int64 group; // Ⱥ��
	int64 qq; // ��Ⱥ��QQ
	int64 inviter; // ������QQ
};
// Ⱥ��Ա�����¼�����
struct GroupMemberIncrease {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1 ĳ�˱���׼����  2 �Ҽ���ĳ��Ⱥ  3 ĳ�˱����������Ⱥ
	int64 group; // Ⱥ��
	int64 qq; // ��Ⱥ��QQ
	int64 admin; // �����߻�������QQ
};
// Ⱥ��Ա�뿪�¼�����
struct GroupMemberDecrease {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1 ĳ����Ⱥ  2 ĳ�˱������߳�Ⱥ
	int64 group; // Ⱥ��
	int64 qq; // ��Ⱥ��QQ
	int64 admin; // ����ԱQQ
};
// Ⱥ����ɢ�¼�����
struct GroupDissmiss {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	int64 group; // Ⱥ��
	int64 qq; // ��ɢ��QQ
};
// Ⱥ����Ա�ı��¼�����
struct GroupManagerChange {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1 ĳ�˳�Ϊ����  2 ĳ�˱�ȡ������
	int64 group; // Ⱥ��
	int64 qq; // ���ı�QQ
};
// Ⱥ��Ա��Ƭ�ı��¼�����
struct GroupMemberCardChange {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	int64 group; // Ⱥ��
	int64 qq; // �ı���QQ
	string card; // �ı��Ⱥ��Ƭ
};
// Ⱥ���ı��¼�����
struct GroupNameChange {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	int64 group; // Ⱥ��
	string name; // �ı��Ⱥ��
};
// Ⱥ�����¼�����
struct GroupBanSpeak {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1 ����ȫȺ���� 2 �ر�ȫȺ����
	int64 group; // Ⱥ��
	int64 qq; // ����ԱQQ
};
// Ⱥ��Ա�����¼�����
struct GroupMemberBanSpeak {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1. ĳ�˱�����. 2.ĳ�˱��������
	int64 group; // Ⱥ��
	int64 qq; // ������QQ
	int64 admin; // ����ԱQQ
	int32 time; // ����ʱ��, ��λ: ��, ��Χ: 1��-30��
};
// Ⱥ�����ı��¼�����
struct GroupAnonymousChange {
	int64 bot; // ������QQ
	int32 type; // �¼�������,1.Ⱥ��������. 2.Ⱥ�����ر�
	int64 group; // Ⱥ��
	int64 qq; // ����ԱQQ
};
// Ⱥ������Ϣ�¼�����
struct GroupMemberRemoveMessage {
	int64 bot; // ������QQ
	int32 type; // �¼�������,�̶�Ϊ1
	int64 group; // Ⱥ��
	int64 qq; // ������QQ
	int64 flag; // ��Ϣ���
	int32 id; // ��ϢID
};
// �Ա�
#define GENDER_MALE 1 // ����
#define GENDER_FEMALE 2 // Ů��
// ����״̬
#define STATUS_ONLINE 1 // ����
#define STATUS_QME 2 // Q�Ұ�
#define STATUS_LEAVE 3 // �뿪
#define STATUS_BUSY 4 // æµ
#define STATUS_DND 5 // �������
#define STATUS_CLOAKING 6 // ����
// ��֤��ʽ
#define VERIFY_NONE 0 // �����κ�����Ӻ���
#define VERIFY_NEED_VERIFYCATION 1 // ��Ҫ��֤
#define VERIFY_NEED_CORRECT_ANSWER 3 // ��Ҫ��ȷ��
#define VERIFY_NEED_ANSWER_QUESTION 4 // ��Ҫ�ش�����
#define VERIFY_ALERADY_FRIEND 99 // �Ѿ��Ǻ���

#endif