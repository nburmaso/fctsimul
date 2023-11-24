#include "GeantDetectorConstruction.hpp"

#include "G4Box.hh"
#include "G4FieldManager.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4Tubs.hh"
#include "G4UniformMagField.hh"
#include "G4VPhysicalVolume.hh"
#include "GeantDetector.hpp"

G4VPhysicalVolume* FCTGeometry::GeantDetectorConstruction::Construct()
{
  using namespace CLHEP; // Geant4 units

  G4NistManager* nist = G4NistManager::Instance();
  G4Material* siMat = nist->FindOrBuildMaterial("G4_Si");
  G4Material* worldMat = nist->FindOrBuildMaterial("G4_Galactic");

  auto* solidWorld = new G4Box("World", 500 * cm, 500 * cm,
                               500 * cm); // half-dimensions
  auto* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
  fPhysWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "World",
                                 nullptr, false, 0, false);

  for (auto i = 0; i < layersZ->size(); ++i) {
    auto posZ = layersZ->at(i);
    auto inR = layersInR->at(i);
    auto outR = layersOutR->at(i);
    auto* solidSi = new G4Tubs("SiLayer", inR * cm, outR * cm,
                               0.5 * layersThick * cm, 0., 2. * M_PI);
    auto* logicSi = new G4LogicalVolume(solidSi, siMat, "SiLayer");
    new G4PVPlacement(nullptr, G4ThreeVector(0., 0., posZ * cm), logicSi,
                      "SiLayer" + std::to_string(i), logicWorld, false, 0,
                      false);
    if (i == layersZ->size() - 1)
      fScoringVolume = logicSi;
  }

  // setting uniform magnetic field to the world
  double fieldX = 0;
  double fieldY = 0.5;
  double fieldZ = 0;
  auto* magField = new G4UniformMagField(
    G4ThreeVector(fieldX * tesla, fieldY * tesla, fieldZ * tesla));
  auto* fieldMgr = new G4FieldManager();
  fieldMgr->SetDetectorField(magField);
  fieldMgr->CreateChordFinder(magField);
  logicWorld->SetFieldManager(fieldMgr, true);

  return fPhysWorld;
}
