#include "Song_Node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_line()
{
	printf("====================================\n\n");
}
int main()
{
	char lib_arr[7][2][100] = {
		{"radiohead", "street spirint (fade out)"},
		{"radiohead", "paranoid android"},
		{"pink floyd", "time"},
		{"pearl jam", "yellow ledbetter"},
		{"pearl jam", "even flow"},
		{"pearl jam", "alive"},
		{"ac/dc", "thunderstruck"}
	};
	int i = 0;
	struct song_node * lib_node = malloc(7 * sizeof(struct song_node));
	// This line is here so that we don't insert_front for an empty node
	strcpy(lib_node->name, lib_arr[i][0]); strcpy(lib_node->artist, lib_arr[i][1]);
	for(i = 1; i < 7; i++) {
		lib_node = insert_front(lib_node, lib_arr[i][0], lib_arr[i][1]);
		//printf("lib_arr[%d][0] = %s ", i, lib_arr[i][0]);
		//printf("lib_arr[%d][1] = %s\n", i, lib_arr[i][1]);
	}
	//struct song_node * test_node = malloc(sizeof(struct song_node));
	//strcpy(test_node->name, "Boo");
	//strcpy(test_node->artist, "Ghost");
	//test_node->next = NULL;
	//struct song_node * test_node2 = malloc(sizeof(struct song_node));
	//strcpy(test_node2->name, test_node->name);
	//strcpy(test_node2->name, test_node->name);
	//test_node2->next = NULL;

	printf("LINKED LIST TESTS\n");
	print_line();
	//print_node(test_node);
	printf("Testing print_list:\n");
	print_library(lib_node);
	print_line();
	printf("Testing print_node:\n");
	print_node(lib_node);
	print_line();
	printf("Testing find_node");
	return 0;
}
