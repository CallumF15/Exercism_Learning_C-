namespace hellmath {
  
// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.

    enum AccountStatus
    {
        troll,
        guest,
        user,
        mod
    };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.

    enum Action
    {
        read,
        write,
        remove
    };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.

    bool display_post(AccountStatus posterStatus, AccountStatus viewerStatus){
        if(viewerStatus != AccountStatus::troll)
        {         
            if(posterStatus == AccountStatus::troll)
                return false;

            return true;
        }else
            return true;
    }

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.

    //read -> guests, users, trolls, mods
    //write -> users, trolls,  mods
    //remove -> mods

    bool permission_check(Action action, AccountStatus accountStatus)
    {
        if (action == Action::read)
            return true;
        
        if (action == Action::remove && accountStatus == AccountStatus::mod)
            return true;

        if (action == Action::write && accountStatus != AccountStatus::guest)
            return true;

        return false;
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.

    //guests -> none
    //Trolls -> trolls
    //Users  -> Mods/users
    //Mods   -> mods/users
    
    bool valid_player_combination(AccountStatus player1Status, AccountStatus player2Status){
        if(player1Status == AccountStatus::guest || player2Status == AccountStatus::guest) 
            return false; //guests cant play

         if (player1Status == AccountStatus::troll || player2Status == AccountStatus::troll) 
             return player1Status == AccountStatus::troll && player2Status == AccountStatus::troll;

        return true;  //must be a user/mod
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

    //trolls -> 
    //guests -> trolls
    //Users  -> guests/trolls
    //mods   -> users, guests, trolls

    bool has_priority(AccountStatus hasPriority, AccountStatus target)
    {
        if (hasPriority == AccountStatus::troll)
            return false;
        
        if (hasPriority == AccountStatus::guest)
            return target == AccountStatus::troll;
        
        if (hasPriority == AccountStatus::user)
            return target == AccountStatus::guest || target == AccountStatus::troll;

        //mod
        return target != AccountStatus::mod; //but other user can't be mod
    }
}  // namespace hellmath
