#pragma once

#include <vector>

class GeantHit
{
 public:
  GeantHit() = default;
  ~GeantHit() = default;

  void AddDigiIndex(int index) { fDigiIndices.push_back(index); }
  auto GetNDigiIndices() { return fDigiIndices.size(); }
  int GetDigiIndex(int i) { return fDigiIndices[i]; }
  [[nodiscard]] double X() const { return fX; }
  [[nodiscard]] double Y() const { return fY; }
  [[nodiscard]] double Z() const { return fZ; }
  [[nodiscard]] double Dx() const { return fDx; }
  [[nodiscard]] double Dy() const { return fDy; }
  [[nodiscard]] double Dz() const { return fDz; }
  [[nodiscard]] int GetLayer() const { return fLayer; }
  [[nodiscard]] int GetAmplitude() const { return fAmplitude; }

  void SetXYZ(double x, double y, double z)
  {
    fX = x;
    fY = y;
    fZ = z;
  }

  void SetDxDyDz(double dx, double dy, double dz)
  {
    fDx = dx;
    fDy = dy;
    fDz = dz;
  }

  void SetLayer(int layer) { fLayer = layer; }
  void SetAmplitude(int adc) { fAmplitude = adc; }

 private:
  double fX;
  double fY;
  double fZ;
  double fDx;
  double fDy;
  double fDz;
  int fLayer;
  int fAmplitude;
  std::vector<int> fDigiIndices;
};
