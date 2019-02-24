#include <iostream>
#include <string>
#include <vector>

#include "io.h"


int main(int argc, char *argv[])
{
    std::string file_path = "./description/network_fussbook.txt";
    std::vector<node_t> nodes = load_graph_desc(file_path);
    //node_t *node = get_node_highest_degree(nodes);
    int total_nodes = get_total_node(nodes);
    int total_edges = get_total_edge(nodes);


    std::cout << "nodes: " << total_nodes << " | edges: "<< total_edges << std::endl;            


    return 0;
}