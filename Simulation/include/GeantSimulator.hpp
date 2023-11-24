#pragma once

#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "GeantActionInitialization.hpp"
#include "GeantDetectorConstruction.hpp"
#include "GeantSimulationWorld.hpp"
#include "QBBC.hh"

namespace Simulation
{

class GeantSimulator
{
 public:
  GeantSimulator() = default;
  ~GeantSimulator() = default;

  static int runSimulation(int argc, char* argv[])
  {
    auto* ui = new G4UIExecutive(argc, argv);

    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    G4long seed = time(nullptr);
    G4Random::setTheSeed(seed);
    CLHEP::HepRandom::setTheSeed(seed);

    DetectorPars::nLayers = 9;

    DetectorPars::layersZ = {-442.0, -444.0, -446.0, -448.0, -450.0,
                             -460.0, -470.0, -480.0, -490.0};

    DetectorPars::layersInR = {6.0, 6.0, 6.0, 6.0, 6.1, 6.2, 6.3, 6.5, 6.6};

    DetectorPars::layersOutR = {44.1, 44.3, 44.5, 44.7, 44.9,
                                45.9, 46.9, 47.9, 48.9};

    auto* detConstruction = new FCTGeometry::GeantDetectorConstruction();
    detConstruction->layersZ = &DetectorPars::layersZ;
    detConstruction->layersInR = &DetectorPars::layersInR;
    detConstruction->layersOutR = &DetectorPars::layersOutR;

    auto* runManager = new G4RunManager;
    runManager->SetUserInitialization(new QBBC()); // physics list
    runManager->SetUserInitialization(new GeantActionInitialization());
    runManager->SetUserInitialization(detConstruction);

    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/control/execute run.mac");
    // ui->SessionStart();

    // delete ui;
    delete visManager;
    delete runManager;
    return 0;
  }
};

} // namespace Simulation
