#include "AMFANN.h"


#define NHIDDENLAYERS 1
//#include <TStopwatch>



int main()
{
    
    
  //  TStopwatch timer;
    
    unsigned nVars = 2;
    unsigned hllist[NHIDDENLAYERS] = {2};
    vector<unsigned> hiddentopology(&hllist[0],&hllist[0]+NHIDDENLAYERS);
    
    
    AMFANN nn(nVars, hiddentopology);
    
    
    vector<double> testcase;
    testcase.push_back( 0.0);     testcase.push_back( 1.0);
    
    
    
  //  nn.printTopology();
  //  nn.getScore(testcase);
  //  nn.printTopology();
    
    
    vector< vector <double> > signal;
    vector< vector <double> > background;
    
    
    signal.push_back ( vector <double>() );
    signal.back().push_back(1.0 ); signal.back().push_back(0.0);
    
    signal.push_back ( vector <double>() );
    signal.back().push_back(0.0 ); signal.back().push_back(1.0);
    
    background.push_back ( vector <double>() );
    background.back().push_back(0.0 );  background.back().push_back(0.0);
    
    background.push_back ( vector <double>()  );
    background.back().push_back(1.0 );  background.back().push_back(1.0);
    
    
    
    
    
    nn.train(1000,signal,background);
    
    
    //nn.getScore( signal[1] );
    
    //nn.printTopology();
    
    //cout << "Signal 1 0  = " << nn.getScore(signal[0]) << endl;
    //cout << "Signal 0 1  = " << nn.getScore(signal[1]) << endl;
    
   // cout << "Background 0 0 = " << nn.getScore(background[0]) << endl;
    //cout << "Background 1 1 = " << nn.getScore(background[1]) << endl;
    
    cout << "finished" << endl;

    
    
    
    
    
}