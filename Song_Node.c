#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

struct song_node * insert_front(struct song_node * sn,\
char * artist, char * name) 
{
	struct song_node * sn2 = malloc(sizeof(struct song_node));
	str_cpy(sn2->name, name);
	str_cpy(sn2->artist, artist);
	sn2->next = sn;
	return sn2;
}

int song_cmp(struct song_node * sn1, struct song_node * sn2)
{
	char * a1 = sn1->artist;
	char * n1 = sn1->name;
	char * a2 = sn2->artist;
	char * n2 = sn2->name;
	int acmp = str_cmp(a1,a2);
	if (acmp != 0) return acmp;
	return str_cmp(n1,n2); 
}

struct song_node * insert_sorted(struct song_node * sn){}
struct song_node * find_song(char * artist, char * name){}
struct song_node * find_first(char * artist){}
struct song_node * get_rand(){}
struct song_node * remove_node(char * artist, char * name){}
struct song_node * free_list(struct song_node * sn){}