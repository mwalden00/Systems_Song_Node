#include "Song_Node.h"
#include "Song_Lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_line()
{
	printf("====================================\n\n");
}

void print_song(struct song_node *sn, char *artist, char *song) {
	printf("looking for [%s: %s]\n", artist, song);
	if(find_song(sn, artist, song) != NULL)
		printf("\tnode found! %s: %s\n", artist, song);
	else printf("\tnode not found\n");
}

void print_songcmp(struct song_node *sn, char *artist1, char *song1,
                   char *artist2, char *song2) {
	printf("Comparing [%s: %s] to [%s: %s]\n", artist1, song1, artist2, song2);
	printf("\t%d\n",
	       song_cmp(find_song(sn, artist1, song1),
	                find_song(sn, artist2, song2)));
}

void print_remove(struct song_node *sn, char *artist, char *song) {
	printf("Removing [%s: %s]\n\t", artist, song);
	if(!find_song(sn, artist, song)) printf("%s - %s not found\n", artist, song);
	print_library(remove_node(sn, artist, song));
}

/*void print_artist(struct song_node *sn, char *artist) {
	printf("looking for [%s]\n", artist);
	if(find_artist(sn, artist) != NULL) {
		printf("artist found! ");
		print_library(find_artist(sn, artist));
	} else printf("\tartist not found\n");
}*/

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
	printf("Testing print_list:\n\t");
	print_library(lib_node);
	print_line();

	printf("Testing print_node:\n\t");
	print_node(lib_node); printf("\n");
	print_line();

	printf("Testing find_node:\n");
	print_song(lib_node, "pearl jam", "even flow");
	print_song(lib_node, "pearl jam", "daughter");
	print_line();

	printf("Testing find_first:\n");
	print_node(find_first(lib_node, "pink floyd"));
	printf("\n");
	print_node(find_first(lib_node, "pearl jam"));
	printf("\n");
	print_node(find_first(lib_node, "presidents of the united states of america"));
	printf("\n");
	print_line();

	printf("Testing songcmp (healper function):\n");
	print_songcmp(lib_node, "pearl jam", "even flow", "pearl jam", "even flow");
	print_songcmp(lib_node, "pearl jam", "even flow", "pearl jam", "alive");
	print_songcmp(lib_node, "pearl jam", "alive", "pearl jam", "even flow");
	print_songcmp(lib_node, "pearl jam", "even flow", "pink floyd", "time");
	print_line();

	printf("Testing remove:\n");
	print_remove(lib_node, "pearl jam", "alive");
	print_remove(lib_node, "pearl jam", "yellow ledbetter");
	print_remove(lib_node, "pink floyd", "alive");
	print_line();

	printf("Testing free_list:\n");
	free_list(lib_node);
	printf("list after free_list:\n\n");
	print_line();


	printf("MUSIC LIBRARY TESTS\n\n");
	struct song_node **lib = malloc(3 * sizeof(struct song_node));
	struct song_node *a = malloc(sizeof(struct song_node));
	struct song_node *p = malloc(sizeof(struct song_node));
	struct song_node *r = malloc(sizeof(struct song_node));
	*lib = a;
	*(lib + 1) = p;
	*(lib + 2) = r;
	print_line();

	printf("Testing print_library\n");


	printf("MISC TESTS\n");
	print_line();
	printf("Length of list %d\n", len(lib_node));
	print_line();
	print_node(find_song(lib_node, "pearl jam", "daughter")); printf("\n");
	return 0;
}
