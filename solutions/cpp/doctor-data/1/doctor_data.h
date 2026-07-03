#if !defined(DOCTOR_DATA_H)
#define DOCTOR_DATA_H

#include <string>

namespace star_map{

    enum System{
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Sol,
        Omicron2Eridani
    };
}

namespace heaven {

    class Vessel 
    {
        private:
            
        public:
            star_map::System current_system;
            std::string name{};
            int generation {};
            int busters {};
    
            Vessel(std::string name, int generation);
            Vessel(std::string name, int generation, star_map::System system);
                
            Vessel replicate(std::string name);
        
            void make_buster();
            bool shoot_buster();

           
    };
    
    std::string get_older_bob(Vessel value1, Vessel value2);
    bool in_the_same_system(Vessel value1, Vessel value2);
}

#endif
