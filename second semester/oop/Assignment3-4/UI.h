#pragma once
#include "MaterialController.h"

typedef struct
{
	Controller* ctrl;
} UI;

typedef void(*filter)(UI*);

void customFilterUI(UI*);
void getAvailableMaterialsUI(UI*);

UI* createUI(Controller* c);

void startUI(UI* ui);

void destroyUI(UI* ui);