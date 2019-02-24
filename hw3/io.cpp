#include "io.h"

#include <iostream>
#include <fstream>

std::vector<node_t> load_graph_desc(std::string file_path)
{
    std::vector<node_t> node_list;
    char *path = new char[file_path.size() + 1];
    std::copy(file_path.begin(), file_path.end(), path);
    path[file_path.size()] = '\0';

	FILE *file = fopen(path, "r");
	if (!file)
	{
		fprintf(stderr, "Failed to open file when loading, check the file path\n");
		return node_list;
	}
    std::ifstream f(path);
    delete[] path;


    int node_from, node_to;
    std::string s_1, s_2, s_3;

    while (f >> node_from >> s_1 >> s_2 >> s_3 >> node_to)
    {
        node_t *from = add_node(node_from, node_list);
        node_t *to = add_node(node_to, node_list);
        if (from)
        {
            node_list.push_back(*from);
            std::cout << "         " << from->label << std::endl;
        }
        else
        {
            /*
                node_t *get_node(int i, std::vector<node_t> node_list)
                is a function in graph.cpp:22

                by running GDB, I can see that get_node() will return a pointer to node_t
                BUT the pointer to node_t can not be assigned to node_t from in the next line
            */
            from = get_node(node_from, node_list); //DEBUG
            std::cout << node_from << " is added " << " | added label " << from->label << std::endl;
        }
        if (to)
        {
            node_list.push_back(*to);
            std::cout << "         " << to->label << std::endl;
        }
        else
        {
            to = get_node(node_to, node_list); //DEBUG
            std::cout << node_to << " is added" << " | added label " << to->label << std::endl;            
        }
        
        std::cout << "break before node " << from->label << " to "<< to->label << std::endl;

        add_edge(from, to, node_list);

        std::cout << "-----------------------------" << std::endl;
    }

    return node_list;
}