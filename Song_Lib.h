#include "Song_Node.h"

void add_song(struct song_node **, char *, char *);
struct song_node * lib_find_song(struct song_node **, char *, char *);
struct song_node * find_artist(struct song_node **, char *);
void print_letter(struct song_node **, char);
void print_artist(struct song_node **, char *);
void print_lib(struct song_node **);
void shuffle(struct song_node **);
void delete_song(struct song_node **, char *, char *);
void clear(struct song_node **);