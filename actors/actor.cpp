#include "actor.h"

size_t actor::getHealth() const { return health; }
void actor::setHealth(size_t hp) { health = hp; }
size_t actor::getMaxHealth() const { return max_health; }
void actor::setMaxHealth(size_t max_hp) { max_health = max_hp; }
size_t actor::getDamageThreshold() const { return dmg_thres; }
void actor::setDamageThreshold(size_t dmg_thres) { this->dmg_thres = dmg_thres; }
double actor::getDamageResistance() const { return dmg_res; }
void actor::setDamageResistance(double dmg_res) { this->dmg_res = dmg_res; }

unsigned int actor::getTeamID() const { return team_id; }
void actor::setTeamID(unsigned int tid) { this->team_id = tid; }
void actor::onTurn() {}

const std::string actor::getName() const { return "Actor"; }

bool actor::canMove(cell& to_where)
{
	if(!to_where.is_passable())
		return false;
	if(to_where.has_object())
		return false;

	return true;
}

size_t actor::takeDamage(size_t dmg)
{
	size_t new_dmg = (dmg >= getDamageThreshold() ? dmg - getDamageThreshold() : 0)
			 * (1.0 - (getDamageResistance() >= 1.0 ? 1.0 : getDamageResistance()));
	setHealth(new_dmg < getHealth() ? getHealth() - new_dmg : 0);
    //notifyObserver();
    if(getHealth() == 0) onDeath();

    return new_dmg;
}
size_t actor::healDamage(size_t heal)
{
    size_t healed = getMaxHealth() - getHealth() > heal ? heal : getMaxHealth() - getHealth();
    setHealth(getMaxHealth() - getHealth() > heal ? getHealth() + heal : getMaxHealth());
    //notifyObserver();

    return healed;
}

void actor::onDeath() {}

void actor::onWalkedIn(actor& by_who) {}
void actor::onWalkOn(cell& to_where) {}

void actor::addObserver(observer *o)
{
    obs = o;
}

void actor::notify(message * message)
{
    obs->update(message);
}
/*
std::ostream& operator<<(std::ostream& os, const actor& ac)
{
    os << ac.getName()
       << ">> health: " << ac.getHealth() << " / " << ac.getMaxHealth()
       << " || DT: " << ac.getDamageThreshold()
       << " || DR: " << ac.getDamageResistance()
       << " || Team ID: " << ac.getTeamID();
    return os;
}*/