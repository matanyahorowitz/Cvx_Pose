//
//  ICP.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "ICP.h"

ICP::ICP()
{
    i_R = Matrix4f::Identity();
    i_T << 0,0,0;
}

ICP::~ICP()
{
    kd_free( this->tree );
}

void ICP::setSolver(SolverSettings s)
{
    this->settings = s;
}

void ICP::setModel( DMat & m )
{
    this->num_pts = m.cols();
    this->model = m;
    this->initKDTree();
}

void ICP::setObservation( DMat & o )
{
    this->observation = o;
}

void ICP::initKDTree()
{
    this->tree = kd_create(3);
    for (int i=0; i<this->num_pts; i++) {
        kd_insert3f( this->tree, model(1,i), model(2,i), model(3,i) );
    }
}

void ICP::align()
{
    c_R = i_R;
    c_T = i_T;
    
    //First do a coarse alignment.
    
    //Second, do a fine alignment.
}


void ICP::singleIteration()
{
    //Solve correspondence
    
    //First, transform according to current pose estimate
    DMat data = c_R * observation + c_T * MatrixXd::Constant(1,observation.cols());
    Vector1d match = solveCorrespondence(data);
}

Vector1d ICP::solveCorrespondence( DMat & data )
{
    
}