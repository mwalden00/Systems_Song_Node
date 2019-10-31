#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Song_Node.h"

void print_node(struct song_node * sn) {
    if (sn != NULL) {
        printf("%s: %s", sn->artist, sn->name);
    }
}

void print_library(struct song_node * sn) {
    while (sn != NULL) {
        print_node(sn);
        printf(" | ");
        sn = sn->next;
    }
    printf("\n");
}

struct song_node * insert_front(struct song_node * sn,\
                                char * artist, char * name) {
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

struct song_node * insert_sorted(struct song_node * sn){}
struct song_node * find_song(char * artist, char * name){}
struct song_node * find_first(char * artist){}
struct song_node * get_rand(){}
struct song_node * remove_node(struct song_node * sn, char * artist, char * name) {
  struct song_node * next = sn; //TODO: rename next
  // should_remove_val checks to see if the names and songs match
  int should_remove_val = (strncpy(next->name, name, 100) || name == NULL) &&
    (strncpy(next->artist, artist, 100) || artist == NULL);
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
    if(!next->next) return sn;
    next = next->next;
  }
  return sn;
}

struct song_node * free_list(struct song_node *sn) {
    if(!sn) return NULL;
    printf("Freeing sn:\n");

    struct song_node * prev = sn;
    struct song_node * node = sn->next;

    free_nullify(prev);
    while(node && node->next) {
        prev = node;
        node = node->next;
        free_nullify(prev);
    }
    return (node) ? free_nullify(node) : free_nullify(node->next);
}

struct song_node * free_nullify(struct song_node *val) {
    printf("Freeing node: %s  %s\n", val->name, val->artist);
    free(val);
    val = NULL;
    return NULL;
}
