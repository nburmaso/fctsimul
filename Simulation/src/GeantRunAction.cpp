#include "GeantRunAction.hpp"

#include "G4RunManager.hh"
#include "GeantSimulationDataFormats.hpp"
#include "GeantSimulationWorld.hpp"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TRandomGen.h"

using namespace Simulation;

void GeantRunAction::BeginOfRunAction(const G4Run*)
{
  gRandom = new TRandomMT64();
  gRandom->SetSeed(std::time(nullptr));

  tMCTracks = new TTree("mctracks", "MC tracks");
  tMCTracks->Branch("mcEventID", &mcTrack.mcEventID);
  tMCTracks->Branch("mcTrackID", &mcTrack.mcTrackID);
  tMCTracks->Branch("pdgID", &mcTrack.pdgID);
  tMCTracks->Branch("motherID", &mcTrack.motherID);
  tMCTracks->Branch("vx", &mcTrack.vx);
  tMCTracks->Branch("vy", &mcTrack.vy);
  tMCTracks->Branch("vz", &mcTrack.vz);
  tMCTracks->Branch("px", &mcTrack.px);
  tMCTracks->Branch("py", &mcTrack.py);
  tMCTracks->Branch("pz", &mcTrack.pz);

  tMCPoints = new TTree("mcpoints", "MC points");
  tMCPoints->Branch("fEventID", &mcPoint.fEventID);
  tMCPoints->Branch("fTrackID", &mcPoint.fTrackID);
  tMCPoints->Branch("fVolumeIndex", &mcPoint.fVolumeIndex);
  tMCPoints->Branch("fELoss", &mcPoint.fELoss);
  tMCPoints->Branch("fTime", &mcPoint.fTime);
  tMCPoints->Branch("fPosInX", &mcPoint.fPosInX);
  tMCPoints->Branch("fPosInY", &mcPoint.fPosInY);
  tMCPoints->Branch("fPosInZ", &mcPoint.fPosInZ);
  tMCPoints->Branch("fPosOutX", &mcPoint.fPosOutX);
  tMCPoints->Branch("fPosOutY", &mcPoint.fPosOutY);
  tMCPoints->Branch("fPosOutZ", &mcPoint.fPosOutZ);

  fList = new TList();
  fList->Add(tMCTracks);
  fList->Add(tMCPoints);
}

void GeantRunAction::EndOfRunAction(const G4Run*)
{
  auto* fout = new TFile(SimWorld::fMcFNameRootOut.c_str(), "recreate");
  fList->Write();
  fout->Close();
}

void GeantRunAction::AddMcTrackToTree(G4Track* track)
{
  auto* gRunManager = G4RunManager::GetRunManager();
  int eventID = gRunManager->GetCurrentEvent()->GetEventID();
  G4ParticleDefinition* part = track->GetDefinition();
  auto p3 = track->GetMomentum();
  int pdg = part->GetPDGEncoding();
  mcTrack.mcEventID = eventID;
  mcTrack.mcTrackID = track->GetTrackID();
  mcTrack.pdgID = pdg;
  mcTrack.motherID = track->GetParentID();
  mcTrack.vx = track->GetVertexPosition().getX();
  mcTrack.vy = track->GetVertexPosition().getY();
  mcTrack.vz = track->GetVertexPosition().getZ();
  mcTrack.px = p3.x();
  mcTrack.py = p3.y();
  mcTrack.pz = p3.z();
  tMCTracks->Fill();
}

void GeantRunAction::AddMcPointToTree(int eventID, int trackID, int volumeIndex,
                                      double eLoss, double t,
                                      const G4ThreeVector& posIn,
                                      const G4ThreeVector& posOut)
{
  mcPoint.fEventID = eventID;
  mcPoint.fTrackID = trackID;
  mcPoint.fVolumeIndex = volumeIndex;
  mcPoint.fELoss = eLoss;
  mcPoint.fTime = t;
  mcPoint.fPosInX = posIn.getX();
  mcPoint.fPosInY = posIn.getY();
  mcPoint.fPosInZ = posIn.getZ();
  mcPoint.fPosOutX = posOut.getX();
  mcPoint.fPosOutY = posOut.getY();
  mcPoint.fPosOutZ = posOut.getZ();
  tMCPoints->Fill();
}