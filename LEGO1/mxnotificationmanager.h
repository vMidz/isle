#ifndef MXNOTIFICATIONMANAGER_H
#define MXNOTIFICATIONMANAGER_H

#include "mxcore.h"
#include "mxcriticalsection.h"
#include "mxnotificationparam.h"
#include "mxtypes.h"

#include "compat.h"

class MxNotification
{
public:
  MxNotification(MxCore *p_target, MxNotificationParam *p_param);
  ~MxNotification();

  inline MxCore *GetTarget() { return m_target; }
  inline MxNotificationParam *GetParam() { return m_param; }

private:
  MxCore *m_target; // 0x0
  MxNotificationParam *m_param; // 0x4
};

class MxIdList : public list<MxU32>
{};

class MxNotificationPtrList : public list<MxNotification *>
{};

// VTABLE 0x100dc078
class MxNotificationManager : public MxCore
{
private:
  MxNotificationPtrList *m_queue; // 0x8
  MxNotificationPtrList *m_sendList; // 0xc
  MxCriticalSection m_lock; // 0x10
  MxS32 m_unk2c; // 0x2c
  MxIdList m_listenerIds; // 0x30
  MxBool m_active; // 0x3c

public:
  MxNotificationManager();
  virtual ~MxNotificationManager(); // vtable+0x0 (scalar deleting destructor)

  virtual MxResult Tickle(); // vtable+0x8
  // TODO: Where does this method come from?
  virtual MxResult Create(MxU32 p_frequencyMS, MxBool p_createThread); // vtable+0x14
  void Register(MxCore *p_listener);
  void Unregister(MxCore *p_listener);
  MxResult Send(MxCore *p_listener, MxNotificationParam *p_param);

  inline MxNotificationPtrList *GetQueue() { return m_queue; }

private:
  void FlushPending(MxCore *p_listener);
};

#endif // MXNOTIFICATIONMANAGER_H
