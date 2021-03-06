#ifndef Particle_h
#define Particle_h
#include "Vector.h"
#include "Setup.h"
#include <vector>

struct particles_data {
    particles_data( double mass = 0, double charge = 0, double step_length = 0): 
                    m(mass), q(charge), step(step_length) {};
    double m;
    double q;
    double step;
};

static bool VERBOSE = 0;

static std::random_device rd;
static std::default_random_engine gen( rd() );

class Particle {

protected:
    Particle( int id, Vector* x_0, double e, double theta_0, double phi_0 );
    Vector* x;                      // position of the particle
    std::vector<Vector*>* position; // vector containing all the positions
    double  step_length;            // cm propagation step
    int     p_id;                   // id of the particle
    double  mass;                   // mass of the particle
    double  charge;                 // charge of the particle
    double  energy;                 // energy of the particle
    double  p;                      // momentum of the particle
    double  v;                      // speed of the particle
    double  theta;                  // azimuthal angle of the particle' momentum
    double  phi;                    // angle on x,y plane of the particle' momentum
    //std::mt19937 gen;
    //std::random_device rd;
    //std::default_random_engine gen;
    
public:
    int                   nPos;
    int                   getID();
    double                getMass();
    double                getCharge();
    double                getEnergy();
    double                getP();
    Vector*               getX();
    double                getSpeed();
    double                getTheta();
    double                getPhi();
    void                  updatePosition();
    void                  hitPM( double distance, double theta_prime, double phi_prime ); 
    Vector*               getLastPosition();
    std::vector<Vector*>* getPositionList();
    
    static particles_data my_particles[30];
    static void setParticlesData();
    
};

#endif
