#ifndef INFOCENTERSTATE_H
#define INFOCENTERSTATE_H

#include "legostate.h"

#include "decomp.h"

// VTABLE 0x100d93a8
// SIZE 0x94
class InfocenterState : public LegoState
{
public:
  InfocenterState();
  virtual ~InfocenterState();

  // OFFSET: LEGO1 0x10071840
  inline virtual const char *ClassName() const override // vtable+0x0c
  { 
    // 0x100f04dc
    return "InfocenterState";
  }

  // OFFSET: LEGO1 0x10071850
  inline virtual MxBool IsA(const char *name) const override // vtable+0x10
  {
    return !strcmp(name, InfocenterState::ClassName()) || LegoState::IsA(name);
  }

  inline MxU32 GetInfocenterBufferElement(MxS32 p_index) { return m_buffer[p_index]; }

private:
  // Members should be renamed with their offsets before use
  /*
    struct UnkStruct
    {
      undefined4 unk1;
      undefined2 unk2;
      undefined2 unk3;
      undefined2 unk4;
    };

    undefined2 unk1;
    undefined2 unk2;
    undefined4 unk3;
    undefined4 padding1;
    void *unk4;
    undefined2 unk5;
    undefined2 unk6;
    undefined2 unk7;
    undefined2 padding2;
    void *unk8;
    undefined2 unk9;
    undefined2 unk10;
    undefined2 unk11;
    undefined2 padding3;
    UnkStruct unk12[6];
    undefined4 unk13;
  */

  undefined pad[0x70];
  MxU32 m_buffer[7]; // 0x78
};

#endif // INFOCENTERSTATE_H
