#pragma once

namespace Simulation
{

class RecoTrack
{
 public:
  RecoTrack() = default;
  ~RecoTrack() = default;

  int eventID;
  int trackID;
  int mcLabel;
  double z;
  double x;
  double y;
  double tx;
  double ty;
  double qp;
  double covM[15];
};

class McTrack
{
 public:
  McTrack() = default;
  ~McTrack() = default;

  int mcEventID;
  int mcTrackID;
  int pdgID;
  int motherID;
  double vx; // vertex coordinates
  double vy; // vertex coordinates
  double vz; // vertex coordinates
  double px;
  double py;
  double pz;
};

class McPoint
{
 public:
  McPoint() = default;
  ~McPoint() = default;
  int fEventID{};
  int fTrackID{};
  int fVolumeIndex{};
  double fELoss{};
  double fTime{};
  double fPosInX{};
  double fPosInY{};
  double fPosInZ{};
  double fPosOutX{};
  double fPosOutY{};
  double fPosOutZ{};
};

} // namespace Simulation
