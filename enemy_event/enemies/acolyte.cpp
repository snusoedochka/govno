#include "acolyte.h"

acolyte::acolyte()
{
	initView();

	max_ap = 8;
	detection_dist = 25;

    setHealth(40);
	setMaxHealth(50);
	setDamageThreshold(5);
	setDamageResistance(0.2);

	atk_action = new action_shoot_ballistic(4, 3, 1/*20*/);
	mv_action = new action_move(1.0);
}
const std::string acolyte::getName() { return "Acolyte"; }