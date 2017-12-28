#include <iostream>
#include "tools.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth)
{
  // VectorXd RMSE(4);
  // RMSE << 1, 1, 1, 1;
  // return RMSE;
  cout << "** CalculateRMSE" << endl;

  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
  if (estimations.size() != ground_truth.size() || estimations.size() == 0)
  {
    cout << "Invalid estimation or ground_truth data" << endl;
    return rmse;
  }

  //accumulate squared residuals
  for (unsigned int i = 0; i < estimations.size(); ++i)
  {

    VectorXd residual = estimations[i] - ground_truth[i];

    //coefficient-wise multiplication
    residual = residual.array() * residual.array();
    rmse += residual;
  }

  //calculate the mean
  rmse = rmse / estimations.size();

  //calculate the squared root
  rmse = rmse.array().sqrt();

  //return the result
  cout << "rmse: " << rmse << endl;
  cout << "|| CalculateRMSE" << endl;

  return rmse;
}

VectorXd Tools::PolarToCartesian(const VectorXd& raw_measurements_) {
	VectorXd x(2);
	// cout << "** PolarToCartesian()" << endl;

  //recover state parameters
	float rho = raw_measurements_(0);
	float phi = raw_measurements_(1);
	float rhoDot = raw_measurements_(2);

	// cout << "polar (rho, phi, rhoDot) (" << rho << 
	// 	", " << phi << 
	// 	", " << rhoDot << ")" << endl;

	//compute the Cartesian vector
	x << rho * cos(phi),
			 rho * sin(phi);
	
	// cout << "cartesian (x,y) (" << x[0] << "," << x[1] << ")" << endl;		 

	// cout << "|| PolarToCartesian()" << endl;
	
	return x;  
}