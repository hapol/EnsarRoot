// ************************************************************
// *****         EnsarSiGenerator header file                    
// ***** 							
// *****  Gamma Generator of different Si* cascades 	
// *****  with Angular Correlations and Branching Rations	
// *****  from primary reaction  Al+p-> Si*-> Si+gammas
// ***** 									 
// *****   Works with the Si_12643_cascade.dat data file	    
// *****   or any file with the same data structure	       
// ***** 							   
// ***** elisabet.galiana@usc.es			       
// ***** Universidad de Santiago de Compostela    
// ***** Dpto. Física de Partículas                         
// ***** 						  
// ************************************************************


#ifndef ENSAR_SIGENERATOR_H
#define ENSAR_SIGENERATOR_H

#include "FairGenerator.h"

#include <iostream>
#include <fstream>

using namespace std;


class FairPrimaryGenerator;

class EnsarSiGenerator : public FairGenerator
{
 public:
  
  /** Default constructor. **/
  EnsarSiGenerator();
  
  /** Constructor.  **/
  EnsarSiGenerator(const char* inputFile, Int_t state); //file name of Si* and number of Si* state (1 for 0.012643  and  2 for 0.012900->not done!) 
  
  /** Destructor. **/
  virtual ~EnsarSiGenerator();
  
  /** Modifiers **/
  //void SetpEnergy      (Double32_t Ep=0.0015)  {fpEnergy = Ep;  };//GeV
  
  /** Initializer **/
  Bool_t Init();
  
  /** Creates an event **/
    virtual Bool_t ReadEvent(FairPrimaryGenerator* primGen);
    
 private:
    ifstream*     fInputFile;   //! Input file stream
    const Char_t* fFileName; 	//! Input file Name
    Int_t* fstate;		//Number of each states
    Double_t* fener;		//Energy of the states
    Double_t* fprob;		//Probability of the states
    Double_t* fnLevel_tot;	//Number of Levels
    Double_t* fener_i;		//Initial energy of each level
    Double_t* fener_f;		//Final energy of each level
    Double_t* fener_gamma;	//Gamma energy
    Double_t* fBR;		//Branching Ratios
    Double_t** fA;		//Angular Coeficients A2 and A4
    ClassDef(EnsarSiGenerator,1);
    void CloseInput();
    void ReadParameters();
    
};


#endif


