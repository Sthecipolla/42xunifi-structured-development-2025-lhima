#ifndef FILESYSTEM_H
# define FILESYSTEM_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>

FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
#endif