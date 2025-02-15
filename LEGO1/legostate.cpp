#include "legostate.h"

DECOMP_SIZE_ASSERT(LegoState, 0x08);

// OFFSET: LEGO1 0x10005f40
LegoState::~LegoState()
{
}

// OFFSET: LEGO1 0x10005f90
MxBool LegoState::VTable0x14() {
  return TRUE;
}

// OFFSET: LEGO1 0x10005fa0
MxBool LegoState::SetFlag() {
  return FALSE;
}

// OFFSET: LEGO1 0x10005fb0
MxResult LegoState::VTable0x1C(LegoFileStream *p_legoFileStream)
{
  if (p_legoFileStream->IsWriteMode()) {
    p_legoFileStream->FUN_10006030(this->ClassName());
  }
  return SUCCESS;
}

// OFFSET: LEGO1 0x10006030
LegoFileStream *LegoFileStream::FUN_10006030(MxString p_str)
{
  const char *data = p_str.GetData();
  MxU32 fullLength = strlen(data);

  MxU16 limitedLength = fullLength;
  Write(&limitedLength, sizeof(limitedLength));
  Write(data, (MxS16) fullLength);

  return this;
}