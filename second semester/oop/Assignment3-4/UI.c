#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI* ui)
{
	destroyController(ui->ctrl);

	free(ui);
}

void printMenu()
{	
	printf("\n===========================\n");
	printf("1 - add a material.\n");
	printf("2 - list all material.\n");
	printf("3 - Remove a specific material.\n");
	printf("4 - Update an existing material.\n");
	printf("5 - List all material past their expiration date which contain a given string or that have quantity given between two values.\n");
	printf("6 - See all materials for a given supplier.\n");
	printf("7 - Undo.\n");
	printf("8 - Redo.\n");
	printf("9 - Lab activity4\n");
	printf("0 - to exit.\n");
	printf("===========================\n");

}

int userCommand(int command)
{
	if (command >= 0 && command <= LONG_MAX)
		return 1;
	return 0;
}

int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

int addMaterialUI(UI* ui)
{
	char name[50], supplier[30];
	int qty;
	DATE date;

	fgetc(stdin); // read the newline, to prevent it from going further to fgets
	readStringWithSpaces("Please input the name: ", 50, name);
	
	readStringWithSpaces("Please input the supplier: ", 50, supplier);

	printf_s("Please input material quantity: ");
	scanf("%d", &qty);

	printf_s("Please input expiration date: ");
	scanf("%d", &date.day); 
	scanf("%d", &date.month);
	scanf("%d", &date.year);

	return addMaterialCtrl(ui->ctrl, name, supplier, qty, date);
}

int removeMaterialUI(UI* ui)
{
	char name[50], supplier[50];
	DATE date;

	fgetc(stdin);
	readStringWithSpaces("Please input the name: ", 50, name);

	readStringWithSpaces("Please input the supplier: ", 50, supplier);

	printf_s("Please input expiration date: ");
	scanf("%d", &date.day);
	scanf("%d", &date.month);
	scanf("%d", &date.year);

	return removeMaterial(ui->ctrl, name, supplier, date);
}

int updateMaterialUI(UI* ui)
{
	char name[50] ,supplier[30];
	DATE date;
	int qty;
	fgetc(stdin);

	readStringWithSpaces("Please input the name: ", 50, name);

	readStringWithSpaces("Please input the supplier: ", 50, supplier);

	printf_s("Please input expiration date: ");
	scanf("%d", &date.day);
	scanf("%d", &date.month);
	scanf("%d", &date.year);

	


	printf_s("Please input new material quantity: ");
	scanf("%d", &qty);

	Material* m = createMaterial(name, supplier, qty, date);

	return updateMaterial(ui->ctrl, m);
}

void listMaterials(UI* ui)
{
	MaterialRepo* repo = getRepo(ui->ctrl);
	int length = getLengthRepo(repo);
	
	if (length == 0)
	{
		char* str = "There are no stored materials.\n";
		printf("%s", str);
	}

	for (int i = 0; i < length; ++i)
	{
		
		toString(getMaterial(repo, i));
	}
}

void chooseFilter(UI* ui)
{
	int userChoice;
	printf("Choose fitler option(1 for problem statement filter/ 2 for custom filter): ");
	scanf("%d", &userChoice);

	filter chosenFilter = NULL;

	chosenFilter = (userChoice == 1) ? &getAvailableMaterialsUI : &customFilterUI;
	chosenFilter(ui);
}

void customFilterUI(UI* ui)
{
	int low, high;
	printf("Enter lower bound for quantity range: ");
	scanf("%d", &low);

	printf("Enter upper bound for quantity range: ");
	scanf("%d", &high);

	DynamicArray* res = customFilter(ui->ctrl, low, high);
	int length = getLength(res);
	if (length == 0)
		printf("There are no items that match your search criteria.");

	for (int i = 0; i < length; ++i)
		toString(get(res, i));

}

void getAvailableMaterialsUI(UI* ui)
{
	char query[200];
	printf("String to be searched: ");
	fgetc(stdin);
	fgets(query, sizeof(query), stdin);

	if (query[0] == '\n')
		query[0] = '\0';
	else 
		for (int i = 0; i < sizeof(query); i++)
		{
			if (query[i] == '\n')
				query[i] = "\0";
			break;
		}


	DynamicArray* repo = getAvailableMaterials(ui->ctrl, query);
	int length = getLength(repo);
	if (length == 0)
		printf("There are no items that match your search criteria.");
	
	for (int i = 0; i < length; ++i)
		toString(get(repo, i));
	
}

void givenSupplierUI(UI* ui)
{
	char query[200];
	printf("Enter supplier: ");
	scanf("%s", query);

	int qty;
	printf("Enter quantity: ");
	scanf("%d", &qty);

	char user[10];
	printf("Choose preffered sorting:(asc/desc): ");
	scanf("%s", user);
	
	sorting sort = NULL;

	sort = (!strcmp(user, "asc")) ?  &ascendingSort : &descendingSort;

	DynamicArray* repo = givenSupplier(ui->ctrl, query, qty, sort);

	int length = getLength(repo);
	if (length == 0)
		printf("There are no materials with that supplier in short supply.");
	for (int i = 0; i < length; ++i)
	{
		toString(get(repo, i));
	}

}

void lab4ActivityUI(UI* ui)
{
	char query[200];
	printf("Enter supplier: ");
	scanf("%s", query);
	sorting sort = NULL;
	DynamicArray* res = lab4Activity(ui->ctrl, query);
	int length = getLength(res);
	if (length == 0)
		printf("There are no materials with that supplier.");
	for (int i = 0; i < length; ++i)
	{
		toString(get(res, i));
	}
}

void startUI(UI* ui)
{
	

	while (1)
	{
		printMenu();

		int command = readIntegerNumber("Input command: ");
		while (userCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 1)
		{
			int res = addMaterialUI(ui);
			if (res == 1)
				printf("Material added succesfully!\n");
			else printf("There were some issues adding the input material :(\n");
		}
		else if (command == 2)
		{
			listMaterials(ui);
		}

		else if (command == 3)
		{
			int res = removeMaterialUI(ui);
			if (res == 1)
				printf("Material deleted successfully.\n");
			else printf("There is no material with the given information.\n");
		}

		else if (command == 4)
		{
			int res = updateMaterialUI(ui);
			if (res == 1)
				printf("Material updated successfully.\n");
			else printf("There is no material with the given information.\n");

		}

		else if (command == 5)
		{

			chooseFilter(ui);

		}
		else if (command == 6)
		{
			givenSupplierUI(ui);
		}
		else if (command == 7)
		{
			int res = undo(ui->ctrl);
			if (res == 1)
				printf("LPO was undone successfully.\n");
			else printf("There are no operations left to be undone.\n");
		}

		else if (command == 8)
		{
			int res = redo(ui->ctrl);
			if (res == 1)
				printf("Succesful redo.\n");
			else printf("No operation can be redone.\n");
		}
		else if (command == 9)
		{
			lab4ActivityUI(ui);
		}
		else if (command == 0)
			break;

	
	}
}