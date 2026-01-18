#include "weapon/Shooter.h"

namespace ly{
    void Shooter::Shoot()
    {
        if(CanShoot() && !IsOnCooldown()){
            ShootImplt();
        }
    }

    Shooter::Shooter(Actor *owner)
    :   mOwner{owner}
    {
    
    }
}