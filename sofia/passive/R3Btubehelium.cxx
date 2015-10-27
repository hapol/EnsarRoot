//									------
// Author: Jose Luis Rodriguez <joseluis.rodriguez.sanchez@usc.es>      ------
//									------
//         Last Update: 29/09/11					------
//----------------------------------------------------------------------------

/* Generated by Together */

#include "FairGeoLoader.h"
#include "FairGeoInterface.h"
#include "FairGeoRootBuilder.h"
#include "FairRuntimeDb.h"
#include "TObjArray.h"
#include "FairRun.h"
#include "FairGeoVolume.h"
#include "FairGeoNode.h"

#include "R3Btubehelium.h"
#include "R3BGeoPassivePar.h"
//#include "R3BGeoTarget.h"

// includes for modeling
#include "TGeoManager.h"
#include "TParticle.h"
#include "TVirtualMC.h"
#include "TGeoMatrix.h"
#include "TGeoMaterial.h"
#include "TGeoMedium.h"
#include "TGeoBBox.h"
#include "TGeoPara.h"
#include "TGeoTube.h"
#include "TGeoSphere.h"
#include "TGeoPcon.h"
#include "TGeoBoolNode.h"
#include "TGeoPgon.h"

#include <iostream>

using namespace std;

R3Btubehelium::~R3Btubehelium()
{
if (fTargetName ) delete fTargetName;
}


R3Btubehelium::R3Btubehelium()
{
fTargetName=NULL;
}

R3Btubehelium::R3Btubehelium(const char * name,  const char * title)
  : R3BModule(name ,title)
{

fTargetName =  new TString(name);

}

void R3Btubehelium::ConstructGeometry(){

 if (*fTargetName == "HeliumPipe") return  ConstructGeometry1();

}


void R3Btubehelium::ConstructGeometry1(){

    cout << endl;
    cout << "-I- R3Btubehelium:: ConstructGeometry1() "<< endl;
    cout << "-I- R3Btubehelium Pipe type: Helium   "<< endl;
    cout << endl;

   Double_t dx,dy,dz,dz1,dz2,dz3;
   Double_t a, rmax, rmin;
   Double_t thx, phx, thy, phy, thz, phz;
   Double_t  phi1, phi2;
   Double_t z, density, w;
   Int_t nel, numed;

   // MATERIALS, MIXTURES AND TRACKING MEDIA

   // --  Material: Iron 
    Double_t radl    =        0.;
    Double_t absl    =        0.;
 
    TGeoMedium * pMedFe=NULL;

   if (gGeoManager->GetMedium("Iron") ){
       pMedFe=gGeoManager->GetMedium("Iron");
   }else{
    a       = 55.850000;
    z       = 26.000000;
    density = 7.870000;
    radl    = 1.757717;
    absl    = 169.994418;
    TGeoMaterial* pMatFe = new TGeoMaterial("Iron", a,z,density,radl,absl);
    pMatFe->SetIndex(701);
    // Medium: Fe
    numed   = 23;  // medium number
    Double_t par[8];
    par[0]  = 0.000000; // isvol
    par[1]  = 0.000000; // ifield
    par[2]  = 0.000000; // fieldm
    par[3]  = 0.000000; // tmaxfd
    par[4]  = 0.000000; // stemax
    par[5]  = 0.000000; // deemax
    par[6]  = 0.000100; // epsil
    par[7]  = 0.000000; // stmin
    pMedFe = new TGeoMedium("Iron", numed,pMatFe, par);
   }


   // Mixture: Mylar
	TGeoMedium * pMedMylar=NULL;
	if (gGeoManager->GetMedium("mylar") ){
		pMedMylar=gGeoManager->GetMedium("mylar");
	}else{ 
		nel     = 3;
		density = 1.390000;
		TGeoMixture*
		pMylarMaterial = new TGeoMixture("Mylar", nel,density);
		a = 12.010700;   z = 6.000000;   w = 0.363636;  // C
		pMylarMaterial->DefineElement(0,a,z,w);
		a = 1.007940;   z = 1.000000;   w = 0.454545;  // H
		pMylarMaterial->DefineElement(1,a,z,w);
		a = 15.999400;   z = 8.000000;   w = 0.181818;  // O
		pMylarMaterial->DefineElement(2,a,z,w);
		// Medium: Mylar
		numed   = 805;  // medium number
		pMylarMaterial->SetIndex(numed);
		Double_t par[8];
		par[0]  = 0.000000; // isvol
		par[1]  = 0.000000; // ifield
		par[2]  = 0.000000; // fieldm
		par[3]  = 0.000000; // tmaxfd
		par[4]  = 0.000000; // stemax
		par[5]  = 0.000000; // deemax
		par[6]  = 0.000100; // epsil
		par[7]  = 0.000000; // stmin
		pMedMylar = new TGeoMedium("Mylar", numed, pMylarMaterial, par);
	}

 
  // Mixture: Air
  TGeoMedium * pAirMedium=NULL;
   if (gGeoManager->GetMedium("Air") ){
       pAirMedium=gGeoManager->GetMedium("Air");
  }else{
    nel     = 2;
    density = 0.001290;
    TGeoMixture*
	pAirMaterial = new TGeoMixture("Air", nel,density);
    a = 14.006740;   z = 7.000000;   w = 0.700000;  // N
    pAirMaterial->DefineElement(0,a,z,w);
    a = 15.999400;   z = 8.000000;   w = 0.300000;  // O
    pAirMaterial->DefineElement(1,a,z,w);
    pAirMaterial->SetIndex(1);
    // Medium: Air
    numed   = 1;  // medium number
    Double_t par[8];
    par[0]  = 0.000000; // isvol
    par[1]  = 0.000000; // ifield
    par[2]  = 0.000000; // fieldm
    par[3]  = 0.000000; // tmaxfd
    par[4]  = 0.000000; // stemax
    par[5]  = 0.000000; // deemax
    par[6]  = 0.000100; // epsil
    par[7]  = 0.000000; // stmin
    pAirMedium = new TGeoMedium("Air", numed,pAirMaterial, par);
  }

   // Material: Helium

    TGeoMedium * pMedHe=NULL;
   if (gGeoManager->GetMedium("He") ){
       pMedHe=gGeoManager->GetMedium("He");
   }else{
       a       = 4.0026;
       z       = 2.000000;
       density = 0.000166;
    TGeoMaterial*
	pMatHe = new TGeoMaterial("He", a,z,density);
    pMatHe->SetIndex(766);
    numed   =766;  // medium number
    Double_t par[8];
       par[0]  = 0.000000; // isvol
       par[1]  = 0.000000; // ifield
       par[2]  = 0.000000; // fieldm
       par[3]  = 0.000000; // tmaxfd
       par[4]  = 0.000000; // stemax
       par[5]  = 0.000000; // deemax
       par[6]  = 0.000100; // epsil
       par[7]  = 0.000000; // stmin
       pMedHe = new TGeoMedium("He", numed,pMatHe,par);
   }

  
   // Material: Vacuum

   TGeoMedium * pMedVac=NULL;
   if (gGeoManager->GetMedium("vacuum") ){
       cout << "-I- TGeoManager: Vacuum Medium already defined " << endl;
       pMedVac=gGeoManager->GetMedium("vacuum");
   }else{
     a       = 1.e-16;
     z       = 1.e-16;
     density = 1.e-16;
     radl    = 1.757717;
     absl    = 169.994418;
     TGeoMaterial*
	pMat17 = new TGeoMaterial("vacuum", a,z,density,radl,absl);
     pMat17->SetIndex(150);
     numed   = 150;  // medium number
     Double_t par[8];
      par[0]  = 0.000000; // isvol
      par[1]  = 0.000000; // ifield
      par[2]  = 0.000000; // fieldm
      par[3]  = 0.000000; // tmaxfd
      par[4]  = 0.000000; // stemax
      par[5]  = 0.000000; // deemax
      par[6]  = 0.000100; // epsil
      par[7]  = 0.000000; // stmin
     pMedVac = new TGeoMedium("vacuum", numed,pMat17, par);
   }

    //WORLD

   TGeoVolume *pAWorld  =  gGeoManager->GetTopVolume();

   TGeoRotation *rot_t = new TGeoRotation("rot");
   rot_t->RotateY(-13.0);

   // Defintion of the Mother Volume

   TGeoShape *pCBWorld = new TGeoBBox("box",
				      100.0/2.0,
				      100.0/2.0,
				      205.0/2.0);

   TGeoVolume*
       pWorld  = new TGeoVolume("Helium_pipe",pCBWorld, pAirMedium);

   TGeoCombiTrans *t0 = new TGeoCombiTrans(-57.0,0.0,15.0+568.0,rot_t);//
   TGeoCombiTrans *pGlobalc = GetGlobalPosition(t0);

   // add the sphere as Mother Volume
   pAWorld->AddNodeOverlap(pWorld, 0,pGlobalc);
 
  //*******  Beam line  ******************************

   // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = 0.000000;
   
   TGeoCombiTrans* pMatrix1 = new TGeoCombiTrans("", dx,dy,dz,0);

   // Shape: sofiae8 type: TGeoTubeSeg
   rmin = 48.50000;
   rmax = 49.00000;
   dz   = 200.0000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_1 = new TGeoTubeSeg("helium_1",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_1 = new TGeoVolume("heliumlog_1",helium_1, pMedFe);
   heliumlog_1->SetVisLeaves(kTRUE);
   heliumlog_1->SetLineColor(17);

   // Position Volume
   TGeoCombiTrans* pGlobal1 = GetGlobalPosition(pMatrix1);
   pWorld->AddNode(heliumlog_1, 0, pGlobal1);



   // Shape: sofiae8 type: TGeoTubeSeg
   rmin = 0.000000;
   rmax = 48.50000;
   dz   = 180.0000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_2 = new TGeoTubeSeg("helium_2",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_2 = new TGeoVolume("heliumlog_2",helium_2, pMedHe);
  // heliumlog_2->SetVisLeaves(kTRUE);
  // heliumlog_2->SetLineColor(2);
  
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = -10.00;
   
   TGeoCombiTrans* pMatrix2 = new TGeoCombiTrans("", dx,dy,dz,0);


   // Position Volume
   TGeoCombiTrans* pGlobal2 = GetGlobalPosition(pMatrix2);
   pWorld->AddNode(heliumlog_2, 0, pGlobal2);



   // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = 30.0/2.0+60.6+25.0;
   
   TGeoCombiTrans* pMatrix3 = new TGeoCombiTrans("", dx,dy,dz, 0);

   // Shape: sofiae9 type: TGeoTubeSeg
   rmin = 49.00000;
   rmax = 53.75000;
   dz   = 1.200000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_3 = new TGeoTubeSeg("helium_3",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_3 = new TGeoVolume("heliumlog_3",helium_3, pMedFe);
   heliumlog_3->SetVisLeaves(kTRUE);
   heliumlog_3->SetLineColor(17);

   // Position Volume
   TGeoCombiTrans* pGlobal3 = GetGlobalPosition(pMatrix3);
   pWorld->AddNode(heliumlog_3, 0, pGlobal3);

   // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = -30.0/2.0-60.6-25.0;

   TGeoCombiTrans* pMatrix4 = new TGeoCombiTrans("", dx,dy,dz,0);

   // Shape: sofiae10 type: TGeoTubeSeg
   rmin = 49.00000;
   rmax = 53.75000;
   dz   = 1.200000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_4 = new TGeoTubeSeg("helium_4",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_4 = new TGeoVolume("heliumlog_4",helium_4, pMedFe);
   heliumlog_4->SetVisLeaves(kTRUE);
   heliumlog_4->SetLineColor(17);

   // Position Volume
   TGeoCombiTrans* pGlobal4 = GetGlobalPosition(pMatrix4);
   pWorld->AddNode(heliumlog_4, 0, pGlobal4);


    // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = -30.0/2.0-60.6-25.0;
   // Rotation: 
   thx = 90.000000;    phx = 0.000000;
   thy = 90.000000;    phy = 90.000000;
   thz = 0.000000;    phz = 0.000000;
   TGeoRotation *pRot11 = new TGeoRotation("",thx,phx,thy,phy,thz,phz);
  
   
   TGeoCombiTrans* pMatrix5 = new TGeoCombiTrans("", dx,dy,dz, pRot11);

   // Shape: sofiae10 type: TGeoTubeSeg
   rmin = 0.000000;
   rmax = 48.50000;
   dz   = 0.005000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_5 = new TGeoTubeSeg("helium_5",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_5 = new TGeoVolume("heliumlog_5",helium_5, pMedMylar);
   heliumlog_5->SetVisLeaves(kTRUE);
   heliumlog_5->SetLineColor(28);

   // Position Volume
   TGeoCombiTrans* pGlobal5 = GetGlobalPosition(pMatrix5);
   pWorld->AddNode(heliumlog_5, 0, pGlobal5);


  
    // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = 30.0/2.0+60.6+25.0;
  
   TGeoCombiTrans* pMatrix6 = new TGeoCombiTrans("", dx,dy,dz,0);

   // Shape: sofiae10 type: TGeoTubeSeg
   rmin = 0.000000;
   rmax = 48.50000;
   dz   = 0.005000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_6 = new TGeoTubeSeg("helium_6",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_6 = new TGeoVolume("heliumlog_6",helium_6, pMedMylar);
   heliumlog_6->SetVisLeaves(kTRUE);
   heliumlog_6->SetLineColor(28);

   // Position Volume
   TGeoCombiTrans* pGlobal6 = GetGlobalPosition(pMatrix6);
   pWorld->AddNode(heliumlog_6, 0, pGlobal6);

   
    // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = 30.0/2.0+60.6+25.0-19.995;
  
   TGeoCombiTrans* pMatrix7 = new TGeoCombiTrans("", dx,dy,dz,0);

   // Shape: sofiae10 type: TGeoTubeSeg
   rmin = 0.000000;
   rmax = 48.50000;
   dz   = 0.005000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_7 = new TGeoTubeSeg("helium_7",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_7 = new TGeoVolume("heliumlog_7",helium_7, pMedMylar);
   heliumlog_7->SetVisLeaves(kTRUE);
   heliumlog_7->SetLineColor(28);

   // Position Volume
   TGeoCombiTrans* pGlobal7 = GetGlobalPosition(pMatrix7);
   pWorld->AddNode(heliumlog_7, 0, pGlobal7);


   // TRANSFORMATION MATRICES
   // Combi transformation: 
   dx = 0.000000;
   dy = 0.000000;
   dz = 30.0/2.0+60.6+25.0-19.995;
   
   TGeoCombiTrans* pMatrix8 = new TGeoCombiTrans("", dx,dy,dz, 0);

   // Shape: sofiae9 type: TGeoTubeSeg
   rmin = 49.00000;
   rmax = 53.75000;
   dz   = 1.200000;
   phi1 = 0.000000;
   phi2 = 360.0000;
   TGeoShape *helium_8 = new TGeoTubeSeg("helium_8",rmin,rmax,dz/2.,phi1,phi2);
   // Volume:
   TGeoVolume* heliumlog_8 = new TGeoVolume("heliumlog_8",helium_8, pMedFe);
   heliumlog_8->SetVisLeaves(kTRUE);
   heliumlog_8->SetLineColor(17);

   // Position Volume
   TGeoCombiTrans* pGlobal8 = GetGlobalPosition(pMatrix8);
   pWorld->AddNode(heliumlog_8, 0, pGlobal8);



}

ClassImp(R3Btubehelium)