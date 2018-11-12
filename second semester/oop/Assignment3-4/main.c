#include "UI.h"
#include <crtdbg.h>
#include <stdlib.h>

int main()
{
	testsDynamicArray();
	testsPlanetRepo();
	testsMaterialController();

	MaterialRepo* repo = createRepo();
	OperationsStack* operationStack = createStack();
	OperationsStack* redoStack = createStack();
	Controller* ctrl = createController(repo, operationStack, redoStack);

	addMaterialCtrl(ctrl, "milk", "someSupplier", 30, (DATE) { 12, 3, 2020});
	addMaterialCtrl(ctrl, "cheese", "zuzu", 23, (DATE) {12,3, 2018});
	addMaterialCtrl(ctrl, "bread", "someSupplier", 12, (DATE) { 2, 3, 2018 });
	addMaterialCtrl(ctrl, "sugar", "zuzu", 60, (DATE) { 1, 12, 2019 });
	addMaterialCtrl(ctrl, "flour", "someSupplier", 36, (DATE) { 22, 5, 2019 });
	addMaterialCtrl(ctrl, "salt", "zuzu", 34, (DATE) { 4, 7, 2024 });
	addMaterialCtrl(ctrl, "yeast", "zuzu", 65, (DATE) { 15, 6, 2021 });
	addMaterialCtrl(ctrl, "water", "someSupplier", 35, (DATE) { 11, 4, 2021 });
	addMaterialCtrl(ctrl, "oil", "zuzu", 30, (DATE) { 10, 1, 2022 });
	addMaterialCtrl(ctrl, "sweetener", "someSupplier", 320, (DATE) { 25, 3, 2017 });
	addMaterialCtrl(ctrl, "eggs", "zuzu", 13, (DATE) { 14, 5, 2019 });
	UI* ui = createUI(ctrl);

	startUI(ui);
	
	destroyUI(ui);
	_CrtDumpMemoryLeaks();

	return 0;
}
 