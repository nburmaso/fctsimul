#pragma once

#include "GeantDetectorConstruction.hpp"
#include "GeantEventAction.hpp"
#include "GeantRunAction.hpp"
#include "GeantSteppingAction.hpp"

namespace Simulation
{

class SimWorld
{
 public:
  SimWorld() = default;
  ~SimWorld() = default;

  inline static std::string partG4Name{"mu+"};
  inline static double particleM{0.1056}; // GeV/c^2
  inline static double particleP{1.};     // GeV/c

  inline static G4VPhysicalVolume* fPhysWorld{nullptr};
  inline static G4LogicalVolume* fScoringVol{nullptr};
  inline static FCTGeometry::GeantDetectorConstruction* fDetector{nullptr};

  inline static GeantRunAction* fRunAction{nullptr};
  inline static GeantEventAction* fEventAction{nullptr};
  inline static GeantSteppingAction* fStepAction{nullptr};

  inline static std::string fMcFNameRootOut{"mctracks.root"};
};

class GeneratorPars
{
 public:
  GeneratorPars() = default;
  ~GeneratorPars() = default;
};

class DetectorPars
{
 public:
  DetectorPars() = default;
  ~DetectorPars() = default;

  inline static double padSizeX{5.};  // mm
  inline static double padSizeY{10.}; // mm
  inline static int nLayers{};
  inline static std::vector<double> layersZ{};
  inline static std::vector<double> layersInR{};
  inline static std::vector<double> layersOutR{};
};

} // namespace Simulation
