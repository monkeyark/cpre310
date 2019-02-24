#include "graph.h"

#include <iostream>

node_t *add_node(int label, std::vector<node_t> node_list)
{
    node_t *node = (node_t *) malloc(sizeof(node_t));
    for (node_t n : node_list)
    {
        if (label == n.label)
        {
            return NULL;
        }
    }
    
    node->label = label;
    node->visited = false;
    node->adjacency = NULL;
    return node;
}

node_t *get_node(int i, std::vector<node_t> node_list)
{
    for (node_t n : node_list)
    {
        if (i == n.label)
        {
            node_t *node = &n;
            std::cout << "get node" << "         " << node->label << std::endl;
            return node;
        }
    }
    return NULL;
}

void add_edge(node_t *node_from, node_t *node_to, std::vector<node_t> node_list)
{
    // node_t from = *get_node(node_from->label, node_list);
    // node_t to = *get_node(node_to->label, node_list);
    if ((*node_from).adjacency == NULL)
    {
        std::cout << "node from ajacency is null" << std::endl;
        std::vector<node_t> node;
        node_from->adjacency = &node;
    }
    else
    {
        (*node_from).adjacency->push_back((*node_to));
    }
    
    if ((*node_to).adjacency == NULL)
    {
        std::cout << "node to ajacency is null" << std::endl;
        std::vector<node_t> node;
        node_to->adjacency = &node;
    }
    else
    {
        (*node_to).adjacency->push_back((*node_from));
    }
    
}

node_t *get_node_highest_degree(std::vector<node_t> node_list)
{
    int max_degree = -1;
    node_t *node = NULL;

    for (node_t n : node_list)
    {
        if ((int) n.adjacency->size() > max_degree)
        {
            node = &n;
        }
    }
    return node;
}

int get_total_node(std::vector<node_t> node_list)
{
    return (int) node_list.size();
}

int get_total_edge(std::vector<node_t> node_list)
{
    int edges = 0;
    for (node_t n : node_list)
    {
        if (n.adjacency->size() > 0)
        {
            edges += n.adjacency->size();
        }
    }
    return edges;
}