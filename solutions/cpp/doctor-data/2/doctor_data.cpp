#include "doctor_data.h"

namespace heaven
{
    Vessel::Vessel(std::string name, int generation, star_map::System current_system)
        : name{std::move(name)},  //transfer string avoiding allocation/copy
          generation{generation},
          current_system{current_system}      //member initialization list 
    {
    }

    Vessel Vessel::replicate(std::string name)
    {
        return Vessel(name, ++generation);
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

    std::string get_older_bob(Vessel& a, Vessel& b) 
    {
        return (a.generation < b.generation) ? a.name : b.name;
    }
    
    bool in_the_same_system(Vessel& system1, Vessel& system2) 
    {
        return system1.current_system == system2.current_system;
    }
}



         