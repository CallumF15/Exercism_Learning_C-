namespace targets {
// TODO: Insert the code for the alien class here

class Alien{

    private:
    int health;
    
    public:
    int x_coordinate;
    int y_coordinate;
    
    Alien(int x, int y){
        this->x_coordinate = x;
        this->y_coordinate = y;

        health = 3;
    }

    bool hit(){
        if(is_alive())
            health--;

        return true;
    }

    bool is_alive(){
        return health > 0;
    }

    bool teleport(int x_new, int y_new){
        this->x_coordinate = x_new;
        this->y_coordinate = y_new;
        
        return true;
    }

    bool collision_detection(Alien alien){
        if(alien.x_coordinate == this->x_coordinate && 
            alien.y_coordinate == this->y_coordinate)
            return true;
        else 
            return false;
    }

    int get_health(){
        return health;
    }
};
    
}  // namespace targets
