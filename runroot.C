#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "TFile.h"
#include "TSystem.h"
#include "TTree.h"
#include "TStopwatch.h"



#include "AMFANN.h"


#define NHIDDENLAYERS 1

using namespace std;



// ---------------------------------------------------------------
int main(int argc, char** argv)
{
    //TStopwatch timer;
    
    
    //Get the training file
    TFile* inputFile = new TFile("/Users/adam/atlas/neuralnet/julianROOTfile/fout_all_-1_NOMINAL_Jan31_newTrainingOnJun14NTuples_reversed_4_4.root");
    
    //The variables of intrest
    float mindijetmass;
    float mbb;
    float mbb_mindr;
    float aplanarity_jet;
    float mclosest;
    float drbb_maxpt;
    float mindrhl;
    float nhiggs30;
    float maxdrhl;
    float maxdeta;
    
    
    // load the signal events
    TTree* s = (TTree*)inputFile->Get("outputtree_ttH125_NOMINAL");
    int nsignal = s->GetEntries();
    
    s->SetBranchAddress("mindijetmass",&mindijetmass);
    s->SetBranchAddress("mbb",&mbb);
    s->SetBranchAddress("mbb_mindr",&mbb_mindr);
    s->SetBranchAddress("aplanarity_jet",&aplanarity_jet);
    s->SetBranchAddress("mclosest",&mclosest);
    s->SetBranchAddress("drbb_maxpt",&drbb_maxpt);
    s->SetBranchAddress("mindrhl",&mindrhl);
    s->SetBranchAddress("nhiggs30",&nhiggs30);
    s->SetBranchAddress("maxdrhl",&maxdrhl);
    s->SetBranchAddress("maxdeta",&maxdeta);
    

    cout << "Loading " << nsignal << " signal events " << endl;
    vector< vector <double> > signal;
    for (unsigned i = 0; i < nsignal; i++)
    {
        s->GetEvent(i);
        
        signal.push_back ( vector <double>() );
        
        signal.back().push_back(mindijetmass);
  /*      signal.back().push_back( mbb);
        signal.back().push_back( mbb_mindr);
        signal.back().push_back(aplanarity_jet);
        signal.back().push_back(mclosest);
        signal.back().push_back(drbb_maxpt);
        signal.back().push_back(mindrhl);
        signal.back().push_back(nhiggs30);
        signal.back().push_back(maxdrhl); */
        signal.back().push_back(maxdeta);

        
    }
    
    

    TTree* b = (TTree*)inputFile->Get("outputtree_ttb_NOMINAL");
    int nbackground = b->GetEntries();
    
    b->SetBranchAddress("mindijetmass",&mindijetmass);
    b->SetBranchAddress("mbb",&mbb);
    b->SetBranchAddress("mbb_mindr",&mbb_mindr);
    b->SetBranchAddress("aplanarity_jet",&aplanarity_jet);
    b->SetBranchAddress("mclosest",&mclosest);
    b->SetBranchAddress("drbb_maxpt",&drbb_maxpt);
    b->SetBranchAddress("mindrhl",&mindrhl);
    b->SetBranchAddress("nhiggs30",&nhiggs30);
    b->SetBranchAddress("maxdrhl",&maxdrhl);
    b->SetBranchAddress("maxdeta",&maxdeta);

    
    cout << "Loading " << nbackground << " background events " << endl;
    vector< vector <double> > background;
    for (unsigned i = 0; i < nbackground; i++)
    {
        b->GetEvent(i);
        
        background.push_back ( vector <double>() );
        
        background.back().push_back(mindijetmass);
  /*      background.back().push_back( mbb);
        background.back().push_back( mbb_mindr);
        background.back().push_back(aplanarity_jet);
        background.back().push_back(mclosest);
        background.back().push_back(drbb_maxpt);
        background.back().push_back(mindrhl);
        background.back().push_back(nhiggs30);
        background.back().push_back(maxdrhl); */
        background.back().push_back(maxdeta);
        
        
    }

    unsigned hllist[NHIDDENLAYERS] = {3};
    vector<unsigned> hiddentopology(&hllist[0],&hllist[0]+NHIDDENLAYERS);
    AMFANN nn(2, hiddentopology);
    
    
    
   nn.train(1000,signal,background);
    
    
    /*
    unsigned nVars = 2;
    unsigned hllist[NHIDDENLAYERS] = {12};
    vector<unsigned> hiddentopology(&hllist[0],&hllist[0]+NHIDDENLAYERS);
    
    
    AMFANN nn(nVars, hiddentopology);
    
    
    vector<double> testcase;
    testcase.push_back( 0.0);     testcase.push_back( 1.0);
    
    
    signal.push_back ( vector <double>() );
    signal.back().push_back(1.0 ); signal.back().push_back(0.0);
    
    signal.push_back ( vector <double>() );
    signal.back().push_back(0.0 ); signal.back().push_back(1.0);
    
    background.push_back ( vector <double>() );
    background.back().push_back(0.0 );  background.back().push_back(0.0);
    
    background.push_back ( vector <double>()  );
    background.back().push_back(1.0 );  background.back().push_back(1.0);
    
    
    
    
    
    nn.train(1000,signal,background);
     */

    
    cout << "Finished" << endl;
}