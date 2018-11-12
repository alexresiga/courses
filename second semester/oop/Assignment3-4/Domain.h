#pragma once
#include <time.h>
typedef struct {
	char name[100];
	char supplier[100];
	int quantity;
	struct tm expirationDate;
} Material;