#include "scorestate.h"

DECOMP_SIZE_ASSERT(ScoreState, 0x0C);

// OFFSET: LEGO1 0x1000de20
MxBool ScoreState::VTable0x14() {
  return FALSE;
}

// OFFSET: LEGO1 0x1000de30
MxBool ScoreState::SetFlag()
{
  m_playCubeTutorial = TRUE;
  return TRUE;
}
