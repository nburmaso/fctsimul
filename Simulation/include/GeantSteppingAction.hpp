#pragma once

#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4UserSteppingAction.hh"

namespace Simulation
{
class GeantEventAction;

class GeantSteppingAction final : public G4UserSteppingAction
{
 public:
  explicit GeantSteppingAction(GeantEventAction* eventAction)
    : G4UserSteppingAction(),
      fEventAction(eventAction),
      fScoringVolume(nullptr),
      fTrackID(),
      fELoss(),
      fTime(),
      fPosIn(),
      fPosOut()
  {
  }

  ~GeantSteppingAction() override = default;
  void UserSteppingAction(const G4Step*) override;

 private:
  GeantEventAction* fEventAction;
  G4LogicalVolume* fScoringVolume;
  int fEventID;
  int fTrackID;
  double fELoss;
  double fTime;
  G4ThreeVector fPosIn;
  G4ThreeVector fPosOut;
};
} // namespace Simulation