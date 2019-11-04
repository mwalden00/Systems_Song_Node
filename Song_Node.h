struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

void print_node(struct song_node *);
void print_library(struct song_node *);

struct song_node * insert_front(struct song_node *, char *, char *);
struct song_node * insert_sorted(struct song_node *, char *, char *);
struct song_node * find_song(struct song_node *, char *, char *);
struct song_node * find_first(struct song_node *, char *);
struct song_node * get_rand(struct song_node *);
struct song_node * get_randn(struct song_node *, int);
struct song_node * remove_node(struct song_node *, char *, char *);
struct song_node * free_list(struct song_node *);

int song_cmp(struct song_node *, struct song_node *);
struct song_node * free_nullify(struct song_node *);
int len_node(struct song_node *);
