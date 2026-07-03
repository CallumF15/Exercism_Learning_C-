#include "doctor_data.h"

using namespace heaven;

Vessel::Vessel(std::string name, int generation)
{
    this->name = name; 
    this->generation = generation;
    this->current_system = star_map::System::Sol;
}

Vessel::Vessel(std::string name, int generation, star_map::System current_system)
{
    this->name = name; 
    this->generation = generation;
    this->current_system = current_system;
}

Vessel Vessel::replicate(std::string name)
{
    return Vessel(name, ++this->generation);
}

void Vessel::make_buster()
{
    busters++;
}

bool Vessel::shoot_buster(){
    if(busters > 0) //ensure we can't go below 0
    {
        busters--;
        return true;
    }
        
    return false;
}

namespace heaven {

    std::string get_older_bob(Vessel a, Vessel b)
    {
        return (a.generation < b.generation) ? a.name : b.name;
    }
    
    bool in_the_same_system(Vessel system1, Vessel system2)
    {
        return system1.current_system == system2.current_system;
    }

}
         