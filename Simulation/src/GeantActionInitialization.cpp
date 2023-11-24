#include "GeantEventAction.hpp"
#include "GeantActionInitialization.hpp"
#include "GeantPrimaryGeneratorAction.hpp"
#include "GeantRunAction.hpp"
#include "GeantSteppingAction.hpp"

void Simulation::GeantActionInitialization::BuildForMaster() const
{
  auto* runAction = new GeantRunAction();
  SetUserAction(runAction);
}

void Simulation::GeantActionInitialization::Build() const
{
  SetUserAction(new GeantPrimaryGeneratorAction());

  auto* runAction = new GeantRunAction();
  SetUserAction(runAction);

  auto* eventAction = new GeantEventAction(runAction);
  SetUserAction(eventAction);

  SetUserAction(new GeantSteppingAction(eventAction));
}
