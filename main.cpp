#include "bin_tree.h"
int main()
{
    bin_tree tr;
    tr.add_node(5);
    tr.add_node(10);
    tr.add_node(1);
    tr.add_node(3);
    tr.add_node(4);
    tr.add_node(11);
    tr.add_node(2);
    tr.print();
    return 0;
}