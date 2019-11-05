#include "Song_Lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_line()
{
	printf("====================================\n\n");
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

	printf("Testing random\n");
	print_node(get_rand(lib_node));
	printf("\n");
	print_node(get_rand(lib_node));
	printf("\n");
	print_node(get_rand(lib_node));
	printf("\n");
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
	struct song_node *a[27];
	struct song_node *p[27];
	struct song_node *r[27];
	struct song_node *lib[27];
	add_song(a, "ac /dc", "thunderstruck");
	add_song(p, "pearl jam", "alive");
	add_song(p, "pearl jam", "even flow");
	add_song(p, "pearl jam", "yellow ledbetter");
	add_song(p, "pink floyd", "time");
	add_song(p, "presidents of the united states of america", "peaches");
	add_song(r, "radiohead", "paranoid android");
	add_song(r, "radiohead", "street spirit (fade out)");
	add_song(lib, "ac /dc", "thunderstruck");
	add_song(lib, "pearl jam", "alive");
	add_song(lib, "pearl jam", "even flow");
	add_song(lib, "pearl jam", "yellow ledbetter");
	add_song(lib, "pink floyd", "time");
	add_song(lib, "presidents of the united states of america", "peaches");
	add_song(lib, "radiohead", "paranoid android");
	add_song(lib, "radiohead", "street spirit (fade out)");
	
	print_line();

	printf("Testing print_library\n");
	printf("a list\n");
	print_lib(a);
	printf("p list\n");
	print_lib(p);
	printf("r list\n");
	print_lib(r);
	print_line();

	printf("Testing print_letter\n");
	printf("p list\n");
	print_letter(lib, 'p');
	print_line();

	printf("Testing find\n");
	printf("looking for [pearl jam: alive]\n");
	lib_find_song(lib,"pearl jam", "alive");
	printf("\nlooking for [pearl jam: time]\n");
	lib_find_song(lib,"pearl jam", "time");
	printf("\n");
	print_line();

	printf("Testing find artist");
	printf("looking for [pearl jam]\n");
	find_artist(lib, "pearl jam");
	printf("looking for [pink floyd]\n");
	find_artist(lib, "pink floyd");
	printf("looking for [bob dylan]\n");
	find_artist(lib, "bob dylan");
	print_line();

	printf("Testing remove song\n");
	printf("removing: [pearl jam: alive]\n");
	delete_song(lib, "pearl jam", "alive");
	printf("a list\n");
	print_letter(lib,'a');
	printf("p list\n");
	print_letter(lib,'p');
	printf("r list\n");
	print_letter(lib,'r');
	print_line();

	printf("Testing clear library\n");
	clear(lib);
	print_line();

	printf("Adding songs to empty library\n");
	struct song_node * new[27];
	add_song(new, "ac /dc", "thunderstruck");
	add_song(new, "pearl jam", "alive");
	add_song(new, "pearl jam", "even flow");
	add_song(new, "pearl jam", "yellow ledbetter");
	add_song(new, "pink floyd", "time");
	add_song(new, "presidents of the united states of america", "peaches");
	printf("a list\n");
	print_lib(a);
	printf("p list\n");
	print_lib(p);
	print_line();

	printf("Testing print_artist\n");
	print_artist(new, "pearl jam");
	printf("\n");
	print_artist(new, "ac /dc");
	print_line();

	printf("Testing shuffle\n");
	shuffle(new);
	print_line();


	/*printf("MISC TESTS\n");
	print_line();
	printf("Length of list %d\n", len_node(lib_node));
	print_line();
	print_node(find_song(lib_node, "pearl jam", "daughter")); printf("\n");*/
	return 0;
}
