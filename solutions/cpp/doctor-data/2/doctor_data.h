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
        public: 
            Vessel(std::string name, int generation, star_map::System current_system = star_map::System::Sol); //default to Sol
            Vessel replicate(std::string name);
            void make_buster();
            bool shoot_buster();

            //Order important
            std::string name{};//1
            int generation{};  //2
            star_map::System current_system; //3
            int busters {}; //must use {} otherwise garbage value
         
    };    

    // Use references (&) to avoid making copies of Vessel objects when passing them
    // into the functions. The original objects are accessed directly.
    std::string get_older_bob(Vessel& value1, Vessel& value2);
    bool in_the_same_system(Vessel& value1, Vessel& value2);
}

#endif
