#pragma once

#include <memory>

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

namespace FCTGeometry
{

class GeantDetectorConstruction final : public G4VUserDetectorConstruction
{
 public:
  GeantDetectorConstruction() = default;
  ~GeantDetectorConstruction() override = default;
  G4VPhysicalVolume* Construct() override;
  [[nodiscard]] G4LogicalVolume* GetScoringVolume() const
  {
    return fScoringVolume;
  }

  std::vector<double>* layersZ{nullptr};
  std::vector<double>* layersInR{nullptr};
  std::vector<double>* layersOutR{nullptr};
  double layersThick{0.0937};

 protected:
  G4LogicalVolume* fScoringVolume{nullptr};
  G4VPhysicalVolume* fPhysWorld{nullptr};
};

} // namespace FCTGeometry
