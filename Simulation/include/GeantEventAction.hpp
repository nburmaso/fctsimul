#pragma once

#include "G4UserEventAction.hh"
#include "GeantRunAction.hpp"

namespace Simulation
{

class GeantEventAction final : public G4UserEventAction
{
 public:
  explicit GeantEventAction(GeantRunAction* runAction) : fRunAction(runAction)
  {
  }

  ~GeantEventAction() override = default;

  virtual void BeginOfEventAction(const G4Event* event);

  virtual void EndOfEventAction(const G4Event* event);

  GeantRunAction* getRunAction() { return fRunAction; }

  bool isTrackStored(int trackID)
  {
    return (std::count(vTrackIDs.begin(), vTrackIDs.end(), trackID) != 0);
  }

  void addTrackID(int trackID) { vTrackIDs.push_back(trackID); }

 private:
  GeantRunAction* fRunAction;
  std::vector<int> vTrackIDs{};
};

} // namespace Simulation
