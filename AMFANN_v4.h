#ifndef __AMFANNV4__
#define __AMFANNV4__

#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include "Eigen/Dense"
#include "Eigen/SVD"


#define IMPROVEMENT_ATTEMPTS 10

using namespace std;
using namespace Eigen;

class AMFANN
{
public:
   
    AMFANN(const unsigned nVars, const vector<unsigned> topology);

    
    double getScore( const vector<double> &input);
    
    unsigned train(unsigned ncycles, const vector <vector <double> > &signal, const vector <vector <double> > &background );
    
    void printTopology();
    
private:
    
    void feedForward();
    void calcgrad();
    bool updateWeights();
    unsigned linesearch();
    double getError();
    
    unsigned m_nInputs;
    unsigned m_nWeights;
    unsigned m_nhiddenLayers;

    vector< unsigned > m_neuronTopology;
    
   
    vector<double> m_combinedError;
    
    vector<MatrixXd> m_weights;
    
  
    
    vector<MatrixXd> m_sums;
    vector<MatrixXd> m_values;
    
    MatrixXd m_error;
    MatrixXd m_iHessian;
    
    double m_alpha; //scaling factor for step size
    double m_lastnsteps;
    
    vector<MatrixXd> m_delta;
    vector<MatrixXd> m_gradient;
    
    
    VectorXd m_fullGradientVector;
    VectorXd m_fullWeightVector;
    
    MatrixXd m_input;
    MatrixXd m_expected;
    
    VectorXd m_oldWeights;
    VectorXd m_oldGradient;
    VectorXd m_direction;
    
    
    
    
    vector<MatrixXd> m_lastweightchange;
    
    
    static MatrixXd activationFunction( const MatrixXd& x);
    static double activationFunction(double x) { return 1 / ( 1 + exp( -1 * x)) ;}
    
    static MatrixXd activationFunctionDerivative( const MatrixXd& x);
    static double activationFunctionDerivative( double x)   { return  exp(-1 * x) / (( 1 + exp( -1 * x)) * ( 1 + exp( -1 * x) )) ; }
    
    
    
};


#endif