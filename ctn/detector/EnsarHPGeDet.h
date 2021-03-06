// -------------------------------------------------------------------------
// -----                     EnsarHPGeDet header file                    -----
// -----                 Created 11/09/12  by P.Cabanelas              -----
// -------------------------------------------------------------------------

/**  EnsarHPGeDet.h
 **/


#ifndef ENSARHPGEDET_H
#define ENSARHPGEDET_H

#include "EnsarDetector.h"

#include "TLorentzVector.h"

class TClonesArray;
class EnsarHPGeDetPoint;
class EnsarHPGeDetHit;
class FairVolume;
class TGeoRotation;


class EnsarHPGeDet : public EnsarDetector
{

 public:

  /** Default constructor **/
  EnsarHPGeDet();


  /** Standard constructor.
   *@param name    detetcor name
   *@param active  sensitivity flag
   **/
  EnsarHPGeDet(const char* name, Bool_t active);


  /** Destructor **/
  virtual ~EnsarHPGeDet();


  /** Virtual method ProcessHits
   **
   ** Defines the action to be taken when a step is inside the
   ** active volume. Creates a EnsarHPGeDetPoint and adds it to the
   ** collection.
   *@param vol  Pointer to the active volume
   **/
  virtual Bool_t ProcessHits(FairVolume* vol = 0);


  /** Virtual method BeginEvent
   **
   ** If verbosity level is set, print hit collection at the
   ** end of the event and resets it afterwards.
   **/
  virtual void BeginEvent();

	
  /** Virtual method EndOfEvent
   **
   ** Added support for EnsarHPGeDetCrystalHit
   ** If verbosity level is set, print hit collection at the
   ** end of the event and resets it afterwards.
   **/
  virtual void EndOfEvent();


  /** Virtual method Register
   **
   ** Registers the hit collection in the ROOT manager.
   **/
  virtual void Register();


  /** Accessor to the hit collection **/
  virtual TClonesArray* GetCollection(Int_t iColl) const;


  /** Virtual method Print
   **
   ** Screen output of hit collection.
   **/
  virtual void Print() const;


  /** Virtual method Reset
   **
   ** Clears the hit collection
   **/
  virtual void Reset();


  /** Virtual method CopyClones
   **
   ** Copies the hit collection with a given track index offset
   *@param cl1     Origin
   *@param cl2     Target
   *@param offset  Index offset
   **/
  virtual void CopyClones(TClonesArray* cl1, TClonesArray* cl2,
			  Int_t offset);


  /** Virtual method Construct geometry
   **
   ** Constructs the STS geometry
   **/
  virtual void ConstructGeometry();

	
  virtual void Initialize();
  virtual void SetSpecialPhysicsCuts();
  void SetEnergyCutOff( Double_t cutE ){fCutE = cutE;}
  Double_t  GetEnergyCutOff ( ) {return fCutE;}


 void SetNonUniformity(Double_t nonU);

  private:

    /** Track information to be stored until the track leaves the
	active volume. **/
    Int_t          fTrackID;           //!  track index
    Int_t          fTrackPID;          //!  particle identification
    Int_t          fVolumeID;          //!  volume id
    Int_t          fParentTrackID;     //!  parent track index
    Int_t          fUniqueID;          //!  particle unique id (e.g. if Delta electron, fUniqueID=9)
    TLorentzVector fPosIn, fPosOut;    //!  position
    TLorentzVector fMomIn, fMomOut;    //!  momentum
    Double32_t     fTime;              //!  time
    Double32_t     fLength;            //!  length
    Double32_t     fELoss;             //!  energy loss
    Double32_t     fEinc;              //!  incident energy
    Double32_t     fCutE;              //!  energy cut
    Int_t          fNSteps;            //!  number of steps
    Double_t       fNonUniformity;     //! Adding some non-uniformity preliminary description
    Int_t          fPosIndex;          //!
    Bool_t         kGeoSaved;          //!
    TList*         flGeoPar;	       //!

    TClonesArray*  fHPGeDetCollection;              //!  The point collection
    TClonesArray*  fHPGeDetHitCollection;           //!  The hit collection

	
    /** Private method AddHit
     **
     ** Adds a HPGeDetPoint to the PointCollection
     **/
    EnsarHPGeDetPoint* AddHit(Int_t trackID, Int_t volumeID,
                        Int_t trackPID, Int_t parentTrackID, Int_t uniqueID,
			TVector3 posIn, TVector3 pos_out,
                        TVector3 momIn, TVector3 momOut,
                        Double_t time, Double_t length, Double_t eLoss);

    /** Private method AddFullHit
     **
     ** Adds a HPGeDetHit to the HitCollection
     **/
    EnsarHPGeDetHit* AddFullHit(Int_t trackID, Int_t volumeID,
                              Int_t trackPID, Int_t parentTrackID, Int_t uniqueID,
                              Double_t energy, Double_t time, Int_t steps, Double_t einc);
	
    /** Private method NUSmearing
     **
     ** Smears the energy according to some non-uniformity distribution 
     ** Very simple preliminary scheme where the NU is introduced as a flat random
     ** distribution with limits fNonUniformity (%) of the energy value.
     **/
    Double_t NUSmearing(Double_t inputEnergy);


    /** Private method ResetParameters
     **
     ** Resets the private members for the track parameters
     **/
    void ResetParameters();
	
    TGeoRotation* createMatrix( Double_t phi, Double_t theta, Double_t psi);

    ClassDef(EnsarHPGeDet,1);
};


inline void EnsarHPGeDet::ResetParameters() {
  fTrackID = fVolumeID = fParentTrackID = fTrackPID = fUniqueID = 0;
  fPosIn.SetXYZM(0.0, 0.0, 0.0, 0.0);
  fPosOut.SetXYZM(0.0, 0.0, 0.0, 0.0);
  fMomIn.SetXYZM(0.0, 0.0, 0.0, 0.0);
  fMomOut.SetXYZM(0.0, 0.0, 0.0, 0.0);
  fTime = fLength = fELoss = 0;
  fPosIndex = 0;
};

#endif 
