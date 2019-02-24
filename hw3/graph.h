#ifndef GRAPH_H
# define GRAPH_H

#include <vector>
#include <cstdbool>

typedef struct graph_node node_t;

struct graph_node
{
    int label;
    bool visited;
    //std::vector<node_t*> *adjacency;
    std::vector<node_t> *adjacency;
};

node_t *add_node(int label, std::vector<node_t> node_list);
node_t *get_node(int i, std::vector<node_t> node_list);
void add_edge(node_t *node_from, node_t *node_to, std::vector<node_t> node_list);
node_t *get_node_highest_degree(std::vector<node_t> node_list);
int get_total_node(std::vector<node_t> node_list);
int get_total_edge(std::vector<node_t> node_list);


#endif