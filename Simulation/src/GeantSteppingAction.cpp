#include "GeantSteppingAction.hpp"

#include "G4RunManager.hh"
#include "G4Step.hh"
#include "GeantDetectorConstruction.hpp"
#include "GeantEventAction.hpp"
#include "GeantRunAction.hpp"

void Simulation::GeantSteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) { // need to do it once
    // gRunManager->GetCurrentEvent()->GetEventID();
    const auto* detectorConstruction =
      dynamic_cast<const FCTGeometry::GeantDetectorConstruction*>(
        G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();
  }

  auto* volume = step->GetPreStepPoint()
                   ->GetTouchableHandle()
                   ->GetVolume()
                   ->GetLogicalVolume();

  if (volume != fScoringVolume) {
    return;
  }

  G4StepPoint* pointIn = step->GetPreStepPoint();
  G4StepPoint* pointOut = step->GetPostStepPoint();
  G4Track* track = step->GetTrack();
  G4StepStatus statusIn = pointIn->GetStepStatus();
  G4StepStatus statusOut = pointOut->GetStepStatus();
  G4TrackStatus statusTrack = track->GetTrackStatus();

  // considering only primary and secondary particles for now
  if (track->GetParentID() == 0 || track->GetParentID() == 1) {
    fEventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    if (statusIn == fGeomBoundary || statusIn == fUndefined) {
      fELoss = 0;
      fTime = pointIn->GetGlobalTime();
      fPosIn = pointIn->GetPosition();
    }

    if (step->IsFirstStepInVolume()) {
      if (!fEventAction->isTrackStored(track->GetTrackID())) {
        fEventAction->addTrackID(track->GetTrackID());
        fEventAction->getRunAction()->AddMcTrackToTree(track);
      }
    }

    fELoss += step->GetTotalEnergyDeposit();

    if (statusOut == fGeomBoundary || statusTrack != fAlive) {
      fTrackID = track->GetTrackID();
      fPosOut = pointOut->GetPosition();
      fEventAction->getRunAction()->AddMcPointToTree(
        fEventID, fTrackID, -1, fELoss, fTime, fPosIn, fPosOut);
    }
  }
}
