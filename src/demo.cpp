#include"sdk/sdk.h"

ERbot{
	INFO{
		info.name = "demo";
		info.author = "�ǳ�";
		info.version = "1.0.0.0";
		info.desc = "����C++SDK�Ŀհײ��";
	}
	EVENT{
		//��ʼ��
		/*onInit([]() {
			//��������ص����ʱ�������¼�,ͨ�������ڿ���������û���װ�����
			api::log("��ʼ��");
			return true;//true �������� false ��ֹ����
		});
		/*������
		onEnable([]() {
			//��������ú󴥷����¼�,���ڲ������������������
			api::log("������");
		});*/
		/*������
		//onDisable([]() {
			//��������á���ж�ػ����˳�ʱ�������¼�,���ڽ��������ͷ���Դ
			api::log("������");
		});*/
		/*������
		onSet([]() {
			//�˴����ز�����ô���
			MessageBoxW(NULL,L"����һ�����ô���",L"����",MB_OK);
		});*/
		/*�յ�˽����Ϣ
		onPrivateMessage([](PrivateMessage e) {
			return QUEUE_IGNORE;
		});*/
		//�յ�Ⱥ��Ϣ
		onGroupMessage([](GroupMessage e) {
			api::sendMsg(e.target, code::at(e.qq) + "��������һ����Ϣ:" + e.msg);
			return QUEUE_IGNORE;
		});
		/*�յ���������Ϣ
		onDiscussMessage([](DiscussMessage e) {
			return QUEUE_IGNORE;
		});*/
		/*�����������
		onFriendAddRequest([](FriendAddRequest e) {
			return QUEUE_IGNORE;
		});*/
		/*���������Ӧ
		onFriendAddResponse([](FriendAddResponse e) {
			return QUEUE_IGNORE;
		});*/
		/*������ɾ��
		onBeFriendDelete([](BeFriendDelete e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ�������
		onGroupAddRequest([](GroupAddRequest e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ��Ա����
		onGroupMemberIncrease([](GroupMemberIncrease e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ��Ա�뿪
		onGroupMemberDecrease([](GroupMemberDecrease e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ����ɢ
		onGroupDissmiss([](GroupDissmiss e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ����Ա�ı�
		onGroupManagerChange([](GroupManagerChange e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ��Ա��Ƭ�ı�
		onGroupMemberCardChange([](GroupMemberCardChange e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ���ı�
		onGroupNameChange([](GroupNameChange e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ����
		onGroupBanSpeak([](GroupBanSpeak e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ��Ա����
		onGroupMemberBanSpeak([](GroupMemberBanSpeak e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ�����ı�
		onGroupAnonymousChange([](GroupAnonymousChange e) {
			return QUEUE_IGNORE;
		});*/
		/*Ⱥ������Ϣ
		onGroupMemberRemoveMessage([](GroupMemberRemoveMessage e) {
			return QUEUE_IGNORE;
		});*/
	}
}