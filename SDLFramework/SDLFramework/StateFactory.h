#pragma once
#include "IAnimalState.h"
#include "StateEnum.h"

static class StateFactory
{
	private:

	protected:

	public:
		StateFactory();
		~StateFactory();

		IAnimalState* CreateNewSate(StateEnum number);
};
