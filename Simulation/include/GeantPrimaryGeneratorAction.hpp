#pragma once

#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4Event;

namespace Simulation
{

class GeantPrimaryGeneratorAction final : public G4VUserPrimaryGeneratorAction
{
 public:
  GeantPrimaryGeneratorAction();
  ~GeantPrimaryGeneratorAction() override;
  void GeneratePrimaries(G4Event*) override;

 private:
  G4ParticleGun* fParticleGun;
};

} // namespace Simulation
