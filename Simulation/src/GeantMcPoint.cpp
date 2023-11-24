#include "GeantMcPoint.hpp"

void Simulation::GeantMcPoint::Print()
{
  printf("McPoint:");
  printf(" trackID=%3i", fTrackID);
  printf(" eloss=%5.2f", fELoss); // MeV
  printf(" time=%4.1f", fTime);   // ns
  printf(" posIn=(%5.1f,%5.1f,%7.1f)", fPosIn.x(), fPosIn.y(),
         fPosIn.z()); // mm
  printf(" posOut=(%5.1f,%5.1f,%7.1f)", fPosOut.x(), fPosOut.y(),
         fPosOut.z()); // mm
  printf(" \n");
}
