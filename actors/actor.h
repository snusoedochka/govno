#ifndef ACTOR_H
#define ACTOR_H

#include "../cell_object.h"
#include "../cells/cell.h"
#include "../logger/observer/observable.h"
#include "../logger/special_messages/game_message.h"
#include "../logger/special_messages/event_message.h"
#include "../logger/special_messages/mistake_message.h"

class actor : public cell_object, public observable
{
	public:

	// Properties
	virtual size_t getHealth() const;
	virtual void setHealth(size_t hp);
	virtual size_t getMaxHealth() const;
	virtual void setMaxHealth(size_t max_hp);
	virtual size_t getDamageThreshold() const; //the same
	virtual void setDamageThreshold(size_t dmg_thres);
	virtual double getDamageResistance() const; //aded const
	virtual void setDamageResistance(double dmg_res);

	virtual unsigned int getTeamID() const;
	virtual void setTeamID(unsigned int tid);
    virtual const std::string getName() const;

	// Events
	virtual void onTurn();

	virtual bool canMove(cell& to_where);

	virtual size_t takeDamage(size_t dmg);
	virtual size_t healDamage(size_t heal);
	virtual void onDeath()/* = 0*/;

	virtual void onWalkedIn(actor& by_who);
	virtual void onWalkOn(cell& to_where);

    void addObserver(observer * o) override;
    void notify(message * message) override;

	private:

	size_t health, max_health;
	size_t dmg_thres;
	double dmg_res;
    observer * obs;

	unsigned int team_id;
};
//std::ostream& operator<<(std::ostream& os, const actor& ac);
#endif
