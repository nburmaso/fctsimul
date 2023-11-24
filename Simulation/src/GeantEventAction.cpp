#include "GeantEventAction.hpp"

using namespace Simulation;

void GeantEventAction::BeginOfEventAction(const G4Event* /* iEvent */)
{
  vTrackIDs.clear();
}

void GeantEventAction::EndOfEventAction(const G4Event* /* iEvent */)
{
  vTrackIDs.clear();
}
