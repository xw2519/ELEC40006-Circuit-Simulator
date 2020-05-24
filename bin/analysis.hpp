
#ifndef analysis_hpp
#define analysis_hpp

// Support functions
#include "header.hpp"
#include "circuit.hpp"

class analysis
{
    private: // -------------------------------------------------------------------

        Eigen::MatrixXf A;
        Eigen::VectorXf b;
        Eigen::VectorXf x;

        int N, M, vcount;

    public: //-----------------------------------------------------------------------

        // To be implemented
        ~analysis();

        void makeDenseMatrix(circuit& input);

        // Stamp new values into existing matrix
        void update();

        // Solve for matrix x
        void solve();

        // Output the content of matrix 'x'
        void print();
    
};

#endif