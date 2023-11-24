#pragma once

#include "G4Track.hh"
#include "G4UserRunAction.hh"
#include "GeantSimulationDataFormats.hpp"
#include "TFile.h"
#include "TList.h"
#include "TTree.h"

class G4Run;
class TList;

namespace Simulation
{

class RecoTrack;
class McTrack;
class McPoint;

class GeantRunAction final : public G4UserRunAction
{
 public:
  GeantRunAction() = default;
  ~GeantRunAction() override = default;

  void BeginOfRunAction(const G4Run*) override;
  void EndOfRunAction(const G4Run*) override;

  void AddMcTrackToTree(G4Track* track);
  void AddMcPointToTree(int eventID, int trackID, int volumeIndex, double eLoss,
                        double t, const G4ThreeVector& posIn,
                        const G4ThreeVector& posOut);

  TList* GetList() { return fList; }
  TTree* tMCTracks;
  TTree* tMCPoints;

  RecoTrack recoTrack{};
  McTrack mcTrack{};
  McPoint mcPoint{};

 private:
  TList* fList;
};

} // namespace Simulation
