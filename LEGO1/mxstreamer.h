#ifndef MXSTREAMER_H
#define MXSTREAMER_H

#include <list>

#include "decomp.h"
#include "mxcore.h"
#include "mxparam.h"
#include "mxstreamcontroller.h"
#include "mxtypes.h"

// NOTE: This feels like some kind of templated class, maybe something from the
//       STL. But I haven't figured out what yet (it's definitely not a vector).
class MxStreamerSubClass1
{
public:
  inline MxStreamerSubClass1(undefined4 size);

  ~MxStreamerSubClass1() { delete [] m_buffer; }

  undefined4 GetSize() { return m_size; }

  void SetBuffer(undefined *p_buf) { m_buffer = p_buf; }

private:
  undefined *m_buffer;
  undefined4 m_size;
  undefined4 m_unk08;
};

class MxStreamerSubClass2 : public MxStreamerSubClass1
{
public:
  inline MxStreamerSubClass2() : MxStreamerSubClass1(0x40) {}
};

class MxStreamerSubClass3 : public MxStreamerSubClass1
{
public:
  inline MxStreamerSubClass3() : MxStreamerSubClass1(0x80) {}
};

class MxStreamerNotification : public MxParam
{
public:
  inline MxStreamerNotification(MxParamType p_type, MxCore *p_sender, MxStreamController *p_ctrlr) : MxParam(p_type, p_sender)
  {
    m_controller = p_ctrlr;
  }

  virtual ~MxStreamerNotification() override {}

  virtual MxParam *Clone() override;

  MxStreamController *GetController() { return m_controller; }

private:
  MxStreamController *m_controller;
};

// VTABLE 0x100dc710
// SIZE 0x2c
class MxStreamer : public MxCore
{
public:
  enum OpenMode
  {
    e_DiskStream,
    e_RAMStream
  };

  MxStreamer();
  virtual ~MxStreamer() override; // vtable+0x0

  __declspec(dllexport) MxStreamController *Open(const char *p_name, MxU16 p_openMode);
  __declspec(dllexport) MxLong Close(const char *p_name);

  virtual MxLong Notify(MxParam &p) override; // vtable+0x4

  // OFFSET: LEGO1 0x100b9000
  inline virtual const char *ClassName() const override // vtable+0x0c
  {
    // 0x1010210c
    return "MxStreamer";
  }

  // OFFSET: LEGO1 0x100b9010
  inline virtual MxBool IsA(const char *p_name) const override // vtable+0x10
  {
    return !strcmp(p_name, MxStreamer::ClassName()) || MxCore::IsA(p_name);
  }

  virtual MxResult Init(); // vtable+0x14

  MxStreamController *GetOpenStream(const char *p_name);

  MxResult AddStreamControllerToOpenList(MxStreamController *p_stream);

  MxResult MxStreamer::Unknown100b99b0(MxDSAction* p_action);

private:
  list<MxStreamController *> m_openStreams; // 0x8
  MxStreamerSubClass2 m_subclass1; // 0x14
  MxStreamerSubClass3 m_subclass2; // 0x20

};

// VTABLE 0x100d8350
// SIZE 0x14
class MxUnknown1 : public MxParam
{
public:
  inline MxUnknown1(MxParamType p_type, MxCore *p_sender, MxDSAction *p_action, MxBool p_reallocAction) : MxParam(p_type, p_sender)
  {
    MxDSAction *oldAction = p_action;
    this->m_realloc = p_reallocAction;
    if (p_reallocAction)
    {
      this->m_action = new MxDSAction();
    }
    else
    {
      this->m_action = oldAction;
      return;
    }

    this->m_action->SetAtomId(oldAction->m_atomId);

    this->m_action->m_objectId = oldAction->m_objectId;
    this->m_action->m_unk24 = oldAction->m_unk24;
  }

  inline virtual MxUnknown1::~MxUnknown1() override // 0x100511e0
  {
    if (this->m_realloc == FALSE)
    {
      return;
    }
    if (this->m_action)
    {
      delete this->m_action;
    }
  }

  virtual MxParam *Clone() override; // vtable+0x4

  MxDSAction *m_action; // 0xc
  MxBool m_realloc;      // 0x10
};

// VTABLE 0x100d8358
// SIZE 0x14
class MxUnknown2 : public MxUnknown1
{

public:
  inline MxUnknown2(MxParamType p_type, MxCore *p_sender, MxDSAction *p_action, MxBool p_reallocAction)
      : MxUnknown1(p_type, p_sender, p_action, p_reallocAction) {}

  inline virtual ~MxUnknown2() override {}; // 0x100513a0

  virtual MxParam *Clone() override; // vtable+0x4
};

#endif // MXSTREAMER_H
