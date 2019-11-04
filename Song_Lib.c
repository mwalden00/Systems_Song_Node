#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Song_Lib.h"

void add_song(struct song_node ** lib, char * artist, char * name)
{
	struct song_node * song = malloc(sizeof(struct song_node));
	strcpy(song->name, name);
	strcpy(song->artist, artist);
	while (lib != NULL) {
		lib++;
	}
	*lib = song;
}

struct song_node * lib_find_song(struct song_node ** lib, char * artist, char * name)
{
	while (lib) {
		if ((strcmp((*lib)->artist, artist) == 0) && (strcmp((*lib)->name, name) == 0)) {
			return *lib;
		}
		lib++;
	}
	return NULL;
}

struct song_node * find_artist(struct song_node ** lib, char * artist)
{
	struct song_node * to_return[27];
	int i = 0;
	while (lib != NULL) {
		if (strcmp((*lib)->artist, artist) == 0) {
			to_return[i] = *lib;
			i++;
		}
		lib++;
	}
	return to_return[0];
}

void print_letter(struct song_node ** lib, char ch)
{
	while (lib != NULL) {
		if ((*lib)->artist[0] == ch) {
			printf("%s: %s\n", (*lib)->artist, (*lib)->name);
		}
	}
}

void print_artist(struct song_node ** lib, char * artist)
{
	while (lib != NULL) {
		if (strcmp((*lib)->artist, artist) == 0) {
			printf("%s: %s\n", (*lib)->artist, (*lib)->name);
		}
		lib++;
	}
}

void print_lib(struct song_node ** lib) {
	while(lib) {
		print_list(*lib);
		lib++;
	}
}

void shuffle(struct song_node ** lib) {
	srand(time(NULL));
	int randint = rand() * len(lib);
	int randlen = rand() * len(lib);
	int i = 0; int j = 0;
	struct song_node *libcpy = *lib;

	for(j = 0; j < randlen; j++) {
		for(i = 0; i < randint; i++) libcpy++;
		get_rand(libcpy);
		libcpy = *lib;
	}
}

void delete_song(struct song_node ** lib, char * artist, char * name) {
	while(lib++) remove_node(*lib, artist, name);
}
void clear(struct song_node ** lib) {
	while(lib++) free_list(*lib);
}
