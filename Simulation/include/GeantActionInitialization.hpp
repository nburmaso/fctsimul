#pragma once

#include "G4VUserActionInitialization.hh"

namespace Simulation
{

class GeantActionInitialization final : public G4VUserActionInitialization
{
 public:
  GeantActionInitialization() = default;
  ~GeantActionInitialization() override = default;

  void BuildForMaster() const override;
  void Build() const override;
};

} // namespace Simulation