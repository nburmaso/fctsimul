#pragma once

#include <utility>

#include "G4ThreeVector.hh"

namespace Simulation
{

class GeantMcPoint
{
 public:
  GeantMcPoint(int eventID, int trackID, int volumeIndex, double eLoss,
               double t, G4ThreeVector posIn, G4ThreeVector posOut)
    : fEventID(eventID),
      fTrackID(trackID),
      fVolumeIndex(volumeIndex),
      fELoss(eLoss),
      fTime(t),
      fPosIn(std::move(posIn)),
      fPosOut(std::move(posOut))
  {
  }

  ~GeantMcPoint() = default;

  [[nodiscard]] int GetEventID() const { return fEventID; }
  [[nodiscard]] int GetTrackID() const { return fTrackID; }
  [[nodiscard]] int GetVolumeIndex() const { return fVolumeIndex; }
  [[nodiscard]] double GetELoss() const { return fELoss; }
  [[nodiscard]] double GetTime() const { return fTime; }
  G4ThreeVector GetPosIn() { return fPosIn; }
  G4ThreeVector GetPosOut() { return fPosOut; }
  void Print();

 private:
  int fEventID{};
  int fTrackID{};
  int fVolumeIndex{};
  double fELoss{};
  double fTime{};
  G4ThreeVector fPosIn{};
  G4ThreeVector fPosOut{};
};

} // namespace Simulation