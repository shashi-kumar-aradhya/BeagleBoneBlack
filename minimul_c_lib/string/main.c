#include "string.h"

int main() {
	char array[100];
	char array_0[100] = "shashi";
	int i = strlen(array_0);
	strncpy(array, array_0, 3);
	strncat(array, array_0, 3);
	int j = strcmp("shashi", "shaShi");
	int k = strncmp("shashi", "shaShi", 4);
	return 0;
}
