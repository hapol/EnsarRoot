#include "E105DSSDGeo.h"
#include "FairGeoNode.h"

ClassImp(E105DSSDGeo)

// -----   Default constructor   -------------------------------------------
E105DSSDGeo::E105DSSDGeo()
  : FairGeoSet()
{
  // Constructor
  // fName has to be the name used in the geometry for all volumes.
  // If there is a mismatch the geometry cannot be build.
  fName="torino";
  maxSectors=0;
  maxModules=10;
}

// -------------------------------------------------------------------------

const char* E105DSSDGeo::getModuleName(Int_t m)
{
  /** Returns the module name of E105DSSD number m
      Setting E105DSSD here means that all modules names in the
      ASCII file should start with E105DSSD otherwise they will
      not be constructed
  */
  sprintf(modName,"torino%i",m+1);
  return modName;
}

const char* E105DSSDGeo::getEleName(Int_t m)
{
  /** Returns the element name of Det number m */
  sprintf(eleName,"torino%i",m+1);
  return eleName;
}
