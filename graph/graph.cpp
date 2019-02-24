#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*
Suppose you are the inventor of a social network (call it Fussbook). The attached file, net-
work_fussbook.txt, describes the friendships between individuals on Fussbook. Assume that all
relationships are symmetric, i.e., the graph is undirected.

(a) Write a small program that takes a filename as input, opens and parses the file, and outputs
the number of nodes and edges in the network.

(b) Suppose you are tasked with finding the “most well-connected” person on Fussbook. In
your view, which concept from graph theory (discussed in class) is a plausible measure of
well-connectedness?

(c) Write another small program that automatically determines the most well-connected person in
Fussbook.

Repeat parts a and c for a rival social network (call it Instaface); a description of friend
relationships on this network is given in network_instaface.txt.

*/

int main(int argc, char *argv[])
{
    std::string file_name;
    std::cout << "input the file name: ";
    getline (std::cin, file_name);
    std::string file_directory = "./";
    std::string file_path  = file_directory + file_name;

    char *path = new char[file_path.size() + 1];
    std::copy(file_path.begin(), file_path.end(), path);
    path[file_path.size()] = '\0';
    
	FILE *file = fopen(path, "r");
	if (!file)
	{
		fprintf(stderr, "Failed to open file, check the file path\n");
		return 0;
	}

    //init file stream
    std::ifstream f(path);
    delete[] path;

    //find size of adjacency list
    int adjacency_size;
    int next_from, next_to;
    std::string s_1, s_2, s_3;
    while (f >> next_from >> s_1 >> s_2 >> s_3 >> next_to)
    {
        std::cout << next_from << " " << next_to << std::endl;
        if (adjacency_size < next_from)
        {
            adjacency_size = next_from;
        }
        if (adjacency_size < next_to)
        {
            adjacency_size = next_to;
        }
    }
    adjacency_size++;

    //initialize adjacnecy list
    int i, j;
    int ** adjacency = new int *[adjacency_size];
    for (i=0; i<adjacency_size; i++)
    {
        adjacency[i] = new int[adjacency_size];
    }

    for (i=0; i<adjacency_size; i++)
    {
        for (j=0; j<adjacency_size; j++)
        {
            adjacency[i][j] = 0;
        }
    }



    //set file stream back to beginning
    f.clear();
    f.seekg(0, std::ios::beg);

    int node_from, node_to;
    while (f >> node_from >> s_1 >> s_2 >> s_3 >> node_to)
    {
        adjacency[node_from][node_to] = 1;
        adjacency[node_to][node_from] = 1;
    }


    std::cout << std::endl << std::endl << std::endl<< "adjacency list of graph" << std::endl;
    printf("    ");
    for (int i=0; i<adjacency_size; i++)
    {
        printf("  %d", i);
    }
    printf("\n");    
    for (i=0; i<adjacency_size*3+5; i++)
    {
        printf("-");
    }
    printf("\n");
    for (i=0; i<adjacency_size; i++)
    {
        printf("%2d |", i);
        for (j=0; j<adjacency_size; j++)
        {
            printf (" %2d", adjacency[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<adjacency_size*3+5; i++)
    {
        printf("-");
    }
    printf("\n");


    int nodes, edges, degrees, degrees_max, node_highest_degree;
    nodes = edges = degrees = degrees_max = node_highest_degree = 0;

    for (i=0; i<adjacency_size; i++)
    {
        for (j=0; j<adjacency_size; j++)
        {
            if (adjacency[i][j] == 1)
            {
                nodes++;
                i++;
                if (i < adjacency_size)
                {
                    j = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }

    for (i=0; i<adjacency_size; i++)
    {
        for (j=0; j<adjacency_size; j++)
        {
            if (adjacency[i][j] == 1)
            {
                edges++;
            }
        }
    }

    for (i=0; i<adjacency_size; i++)
    {
        for (j=0; j<adjacency_size; j++)
        {
            if (adjacency[i][j] == 1)
            {
                degrees++;
            }
        }
        if (degrees > degrees_max)
        {
            degrees_max = degrees;
            node_highest_degree = i;
        }
        degrees = 0;
    }

    std::cout << "number of nodes: " << nodes << std::endl;
    std::cout << "number of edges: " << edges/2 << std::endl;
    std::cout << "most connected node is: " << node_highest_degree << " the degree is: " << degrees_max << std::endl;




    f.close();
    for (i=0; i<adjacency_size; i++)
    {
        delete [] adjacency[i];
    }
    delete [] adjacency;

    return 0;
}