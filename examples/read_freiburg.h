/** Example pose estimation problem for the Stanford Bunny. Settings allow for the testing of all pose estimation techniques.

\author Matanya Horowitz
\date July 18 2013
*/

#ifndef READ_FREIBURG_H
#define READ_FREIBURG_H

#include "../src/common.h"
#include "../src/ICP.h"

#include <iostream>
#include <fstream>
#include <sstream>


int read_freiburg(std::string file_path, int start_line, int end_line, pcl::PointCloud<PointT>::Ptr model_cloud) {
    std::cout << "Reading in Freiburg data at :" << file_path;
   
    std::ifstream fin;
    std::string input;
    fin.open(file_path);
    
    std::cout << "Freiburg file opened\n";
    if( !fin.good() )
    {
        std::cout << "Error reading in file. Quitting.\n";
        return 0;
    }
   
    float x,y,z,ia,ib;
    bool error = false;
    
    std::cout << "Reading in point cloud data\n";
    int line_num = 0;
    while( true ) {
       
       if( line_num < start_line ) {
          line_num++;
          continue;
       }
       
       if( line_num == end_line ) {
          break;
       }
        
        std::getline(fin, input);
        if( !fin ) { //end of line?
            std::cout << "End of file reached.\n";
            break;
        }
        
        std::istringstream buffer(input);
        buffer >> x >> y >> z >> ia >> ib;
        
        pcl::PointXYZ pt;
        pt.x = x;
        pt.y = y;
        pt.z = z;
        
        model_cloud->push_back(pt);
        
        if (!buffer)
        {
            std::cout<<"Error reading line " << line_num << "\n";
            error=true;
            break;
        }
        line_num++;
    }
    
    if( error ) {
        std::cout << "Error reading in bunny vertices at line " << line_num << ". Quitting.\n";
        return 0;
    }
   
   return 1;
}

#endif