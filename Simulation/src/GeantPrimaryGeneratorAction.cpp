#include "GeantPrimaryGeneratorAction.hpp"

#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "GeantSimulationWorld.hpp"

#include "TRandomGen.h"
#include "TVector3.h"
#include "TLorentzVector.h"

using namespace Simulation;

GeantPrimaryGeneratorAction::GeantPrimaryGeneratorAction()
  : fParticleGun(new G4ParticleGun(1))
{
}

GeantPrimaryGeneratorAction::~GeantPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void GeantPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
  fParticleGun->SetParticleDefinition(
    G4ParticleTable::GetParticleTable()->FindParticle(SimWorld::partG4Name));
  fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., 0.));
  double pt = gRandom->Uniform(500., 5000.);
  double eta = gRandom->Uniform(-5., -3.);
  double phi = gRandom->Uniform(0., 2. * M_PI);
  TLorentzVector p4;
  p4.SetPtEtaPhiM(pt, eta, phi, SimWorld::particleM);
  G4ThreeVector p(p4.Px(), p4.Py(), p4.Pz());

  fParticleGun->SetParticleMomentum(p);
  fParticleGun->GeneratePrimaryVertex(event);

  printf("Particle momentum = %.3f\n", p.mag());
}
