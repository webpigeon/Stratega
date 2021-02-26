#pragma once
#include <vector>
#include <Stratega/ForwardModel/Action.h>

namespace SGA::Widgets
{
	struct ActionsSettings
	{
		std::vector<Action> actionHumanSelected;
		std::vector<ActionTarget> selectedTargets;
		int actionTypeSelected = -1;
		//Human player
		std::unordered_set<int> selectedEntities;

		bool waitingForPosition = false;

		void reset()
		{
			actionTypeSelected = -1;
			selectedTargets.clear();
			actionHumanSelected.clear();
			selectedEntities.clear();
			waitingForPosition = false;
		}
	};
	
	/// <summary>
	/// Displays a widget for selecting the action
	/// </summary>
	/// <param name="state">The current GameState</param>
	/// <param name="fowSettings">The settings that will use to draw the possible actions</param>
	/// <returns></returns>
	std::vector<Action> getWidgetResult(GameState& state, ActionsSettings& settings, int playerID);

	std::vector<Action> getEntityActions(GameState& state, ActionsSettings& settings, int playerID);
	std::vector<Action> getPlayerActions(GameState& state, ActionsSettings& settings, int playerID);
	
	void assignPosition(const GameState& state, ActionsSettings& settings, Vector2f position);
}
