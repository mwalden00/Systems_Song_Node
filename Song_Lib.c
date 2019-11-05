#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Song_Lib.h"
//#include "Song_Node.h"

void add_song(struct song_node ** lib, char * artist, char * name)
{
	struct song_node * song = malloc(sizeof(struct song_node));
	strcpy(song->name, name);
	strcpy(song->artist, artist);
	while (*lib) {
		lib++;
	}
	*lib = song;
}

struct song_node * lib_find_song(struct song_node ** lib, char * artist, char * name)
{
	while (*lib) {
		if ((strcmp((*lib)->artist, artist) == 0) && (strcmp((*lib)->name, name) == 0)) {
			printf("Song found! ");
			print_node(*lib);
			return *lib;
		}
		lib++;
	}
	printf("Song not found");
	return NULL;
}

struct song_node ** find_artist(struct song_node ** lib, char * artist)
{
	struct song_node * to_return[27];
	int i = 0;
	while (*lib) {
		if (strcmp((*lib)->artist, artist) == 0) {
			if (i == 0) printf("Artist found! ");
			to_return[i] = *lib;
			print_node(*lib);
			printf(" | ");
			i++;
		}
		lib++;
	}
	if (i == 0) printf("artist not found");
	printf("\n");
	return to_return;
}

void print_letter(struct song_node ** lib, char ch)
{
	while (*lib != 0x0) {
		if ((*lib)->artist[0] == ch) {
			print_node(*lib);
			printf(" | ");
		}
		lib += 1;
	}
	printf("\n");
}

void print_artist(struct song_node ** lib, char * artist)
{
	printf("Printing [%s]\n", artist);
	while (*lib) {
		if (strcmp((*lib)->artist, artist) == 0) {
			printf("[%s: %s]\n", (*lib)->artist, (*lib)->name);
		}
		lib++;
	}
}

void print_lib(struct song_node ** lib) {
	while(*lib != 0x0) {
		print_node(*lib);
		printf(" | ");
		lib += 1;
	}
	printf("\n");
}

void shuffle(struct song_node ** lib) {
	srand(time(NULL));
	int randlen = rand() % (len_lib(lib));
	int i = 0;
	for (i = 0; i < randlen; i++) {
		int j = 0;
		struct song_node ** libcpy = lib;
		int randint = rand() % (len_lib(lib));
		while (j < randint) {
			j++;
			libcpy++;
		}
		print_node(*libcpy);
		printf("\n");
	}
}

int len_lib(struct song_node **lib) {
	int i = 0;
	while(*lib) {
		i++;
		lib++;
	}
	return i;
}

void delete_song(struct song_node ** lib, char * artist, char * name) {
	while(*lib) {
		if (strcmp((*lib)->artist, artist) == 0) {
			break;
		}
		lib+=1;
	}
	free(*lib);
	do {
		*lib = *(lib + 1);
		lib+=1;
	} while (*lib);
}


void clear(struct song_node ** lib) {
	while(*lib) {
		printf("freeing node: ");
		print_node(*lib);
		printf("\n");
		free(*lib);
		lib+=1;
	}
}
