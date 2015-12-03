#pragma once
#include "Animal.h"
#include "StateEnum.h"

static class StateFactory
{
	private:

	protected:

	public:
		State<Animal>* CreateNewSate(StateEnum number);
};
