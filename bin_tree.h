#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <stdio.h>

class node_bin_tree
{
private:
    int data = 0;
    node_bin_tree *left = nullptr;
    node_bin_tree *right = nullptr;
    node_bin_tree() = default;
    ~node_bin_tree() = default;
    friend class bin_tree;
};

class bin_tree
{
private:
    node_bin_tree *root = nullptr;

public:
    bin_tree() = default;
    ~bin_tree()
    {
        delete_tree();
    };
    void add_node(int x)
    {
        if (root == nullptr)
        {
            root = new node_bin_tree;
            root->data = x;
        }
        else
        {
            add_node_subtree(root, x);
        }
    }
    void add_node_subtree(node_bin_tree *curr, int x)
    {
        if (curr->data < x)
        {
            if (curr->right == nullptr)
            {
                node_bin_tree *r = new node_bin_tree;
                r->data = x;
                curr->right = r;
                return;
            }
            else
            {
                add_node_subtree(curr->right, x);
            }
        }
        else
        {
            if (curr->left == nullptr)
            {
                node_bin_tree *l = new node_bin_tree;
                l->data = x;
                curr->left = l;
                return;
            }
            else
            {
                add_node_subtree(curr->left, x);
            }
        }
    }
    void delete_tree()
    {
        if (root != nullptr)
        {
            delete_tree_subtree(root);
        }
    }
    void delete_tree_subtree(node_bin_tree *curr)
    {
        if (curr->left != nullptr)
        {
            delete_tree_subtree(curr->left);
        }
        if (curr->right != nullptr)
        {
            delete_tree_subtree(curr->right);
        }
        delete curr;
    }
    void print()
    {
        if (root != nullptr)
        {
            for (int i = 0; i < 80; i++)
            {
                printf(" ");
            }
            printf(" %d\n", root->data);
            int l = 1;
            bool flag = true;
            while (flag)
            {
                flag = false;
                for (int i = 0; i < 80 - l; i++)
                {
                    printf(" ");
                }
                print_subtree(root, 0, l, flag);
                printf("\n");
                // printf("l = %d\n", l);
                l++;
            }
        }
    }
    void print_subtree(node_bin_tree *curr, int s, int l, bool &flag)
    {
        if (curr == nullptr)
        {
            printf("  ");
            return;
        }
        if (s == l)
        {
            printf("%d  ", curr->data);
            flag = true;
            return;
        }
        print_subtree(curr->left, s + 1, l, flag);
        print_subtree(curr->right, s + 1, l, flag);
    }
};

#endif