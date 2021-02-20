#pragma once
#include <optional>
#include <vector>
#include <Stratega/Representation/Vector2.h>
#include <Stratega/Representation/Path.h>
#include <Stratega/ForwardModel/Action.h>

namespace SGA
{
	struct Entity
	{
		Entity():
			typeID(0),
			id(0),
			ownerID(0),
			position(),
		    path(),
		    movementSpeed(2),
		    collisionRadius(0.5),
			lineOfSightRange(5)
		{
		}

		int typeID;
		int id;
		int ownerID;
		Vector2f position;
		std::vector<ActionInfo> attachedActions;
		std::vector<double> parameters;
		bool shouldRemove=false;
		float lineOfSightRange;

		//RTS Stuff
		Path path;
		double movementSpeed;
		float collisionRadius;

		//Continuous Action
		std::vector<Action> continuousAction;
		bool isNeutral() const;
	};
}