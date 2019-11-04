#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Song_Node.h"

void print_node(struct song_node * sn)
{
	if (sn != NULL) {
		printf("%s: %s", sn->artist, sn->name);
	}
}

void print_library(struct song_node * sn)
{
	while (sn != NULL) {
		print_node(sn);
		printf(" | ");
		sn = sn->next;
	}
	printf("\n");
}

struct song_node * insert_front(struct song_node * sn, char * artist, char * name)
{
	struct song_node * sn2 = malloc(sizeof(struct song_node));
	strcpy(sn2->name, name);
	strcpy(sn2->artist, artist);
	sn2->next = sn;
	return sn2;
}

int song_cmp(struct song_node * sn1, struct song_node * sn2)
{
	char * a1 = sn1->artist;
	char * n1 = sn1->name;
	char * a2 = sn2->artist;
	char * n2 = sn2->name;
	int acmp = strcmp(a1,a2);
	if (acmp != 0) return acmp;
	return strcmp(n1,n2);
}

struct song_node * insert_sorted(struct song_node * lib, char * artist, char * name)
{
	struct song_node * song = malloc(sizeof(struct song_node));
	strcpy(song->name, name);
	strcpy(song->artist, artist);
	if (lib == NULL) return song;
	struct song_node * pre = lib;
	struct song_node * sn = pre->next;
	if (song_cmp(pre, song) <= 0) return insert_front(pre, artist, name);
	while (sn != NULL) {
		if (song_cmp(pre, song) <= 0) {
			pre->next = insert_front(sn, artist, name);
			return lib;
		}
		pre = sn;
		sn = pre->next;
	}
	pre->next = insert_front(sn, artist, name);
	return lib;
}

struct song_node * find_song(struct song_node * lib, char * artist, char * name)
{
	while(lib) {
		if(strcmp(lib->name, name) == 0 && strcmp(lib->name, name) == 0) return lib;
		lib = lib->next;
	}
	return NULL;
}

struct song_node * find_first(struct song_node * lib, char * artist)
{
	while (lib != NULL) {
		if (strcmp(lib->artist, artist) == 0) return lib;
		lib = lib->next;
	}
	return NULL;
}

/*
struct song_node * find_artist(struct song_node * lib, char * artist)
{
	if(find_first(lib, artist) == NULL) return NULL;
	struct song_node *val = malloc(sizeof(struct song_node));
	val = find_first(lib, artist);
	val->next = NULL;
	lib = find_first(lib, artist);

	while(find_first(lib, artist) != NULL) {
		lib = find_first(lib, artist);
		val = insert_front(val, lib->name, lib->artist);
	}
	return val;
}
*/

struct song_node * get_randn(struct song_node * sn, int len)
{
	srand(time(NULL));
	int randint = rand() * len;
	int i = 0;

	for(; i < randint; i++) sn = sn->next;
	return sn;
}

struct song_node * get_rand(struct song_node * sn)
{
	get_randn(sn, len_node(sn));
}

struct song_node * get_previous(struct song_node *sn, struct song_node *val) {
  while(sn) {
    if(song_cmp(sn->next, val) == 0) return sn;
    sn = sn->next;
  }
  return NULL;
}

struct song_node * remove_node(struct song_node * sn, char *artist, char * name) {
	struct song_node *val = find_song(sn, artist, name);
  if(!val) return sn;
	struct song_node *return_val = (song_cmp(val, sn) == 0) ? sn->next : sn;

	if(get_previous(sn, val)) get_previous(sn, val)->next = val->next;
	free_nullify(val);
	return return_val;
}

/*
struct song_node * remove_node(struct song_node * sn, char * artist, char * name)
{
	struct song_node * next = sn;
	// should_remove_val checks to see if the names and songs match
	int should_remove_val = (strncmp(next->name, name, 100) || name == NULL) &&
		(strncmp(next->artist, artist, 100) || artist == NULL);
	if(should_remove_val) {
		struct song_node *tmp = (next->next) ? next->next : NULL;
		free_nullify(sn);
		return tmp;
	}
	next = sn->next;
	while(next) {
		if(should_remove_val) {
			free_nullify(next);
			return sn;
		}
		next = next->next;
	}
	return sn;
}
*/

struct song_node * free_list(struct song_node *sn) {
	if(!sn) return NULL;

	struct song_node * prev = sn;
	struct song_node * node = sn->next;

  printf("freeing node: %s - %s", sn->artist, sn->name);
	free_nullify(sn);
	while(node && node->next) {
		prev = node;
		node = node->next;
    printf("freeing node: %s - %s\n", prev->artist, prev->name);
		free_nullify(prev);
	}
  printf("freeing node: %s - %s\n",
	       (node != 0x0) ? node->artist : node->next->artist,
	       (node != 0x0) ? node->name : node->next->name);
	return (node != 0x0) ? free_nullify(node) : free_nullify(node->next);
}

struct song_node * free_nullify(struct song_node *val) {
  //strcpy(val->artist, NULL);
  //strcpy(val->name, NULL);
	free(val);
	val = 0x0;
	return NULL;
}

int len_node(struct song_node *sn) {
	int len = 0;
	struct song_node *node = sn;

	while(node) {
		len++;
		node = node->next;
	}
	return len;
}
