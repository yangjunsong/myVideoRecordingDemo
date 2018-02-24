#pragma once

//�̻߳������

#include "aqueue.h"
#include "i_aqueue_callback.h"

#include <string>

using namespace std;
class XThreadMgr;

class XThreadBase : public i_asynobj_events
{
public:
	XThreadBase(const string& obj_id_, XThreadMgr* mgr_);
	~XThreadBase(void);

	/************************************************************************
	* ���ƣ�OnTimer
	* ˵����//��ʱ��ʵ����ʵ�ָú�����
	* ������id��ʱ���¼�ID
	* ����ֵ����
	/************************************************************************/
	virtual void OnTimer(int id) = 0;

	/************************************************************************
	* ���ƣ�OnAttach
	* ˵�������Ӷ����̳߳ɹ��¼�
	* ��������
	* ����ֵ����
	/************************************************************************/
	virtual void OnAttach() = 0;

	/************************************************************************
	* ���ƣ�OnDetach
	* ˵�������̷߳����¼�
	* ��������
	* ����ֵ����
	/************************************************************************/
	virtual void OnDetach() = 0;

	/************************************************************************
	* ���ƣ�OnMsg
	* ˵������Ӧ�����̵߳���Ϣ
	* ������cmd ����ID,lparm,wparam
	* ����ֵ����
	/************************************************************************/
	virtual void OnMsg(int cmd_, long long  lparm_, long long wparam_) = 0;

	/************************************************************************
	* ���ƣ�get_id
	* ˵������ȡ���첽�����ID
	* ��������
	* ����ֵ������ID
	/************************************************************************/
	string get_id();

	/************************************************************************
	* ���ƣ�get_mgr
	* ˵������ȡ��ǰ�첽���������
	* ��������
	* ����ֵ������ID
	/************************************************************************/
	XThreadMgr* get_mgr();

	/************************************************************************
	* ���ƣ�add_timer
	* ˵�������ض����Ƿ񱻳�ʼ��
	* ��������
	* ����ֵ������ID
	/************************************************************************/
	void add_timer(int tmid_, int tmout_);


private:
	/************************************************************************/
	/* �첽����̳�ʵ��																								 */
	/************************************************************************/
	virtual void attach_event();
	virtual void dettach_event();
	virtual void timer_event(int id_);
	virtual void msg_event(aqueue::aqueue_msg_t* msg_);
protected:
	bool _isStaring;//��ʶ���߳��Ƿ����ڹ���
private:
	string  _obj_id;//����ID
	XThreadMgr* _aobj_mgr;//�첽���������

private:
	XThreadBase(const XThreadBase&);
	const XThreadBase &operator = (const XThreadBase&);
};