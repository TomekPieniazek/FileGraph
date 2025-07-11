#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FILE_NODE, DIRECTORY_NODE }node_type;

typedef struct node {
    node_type file_type;
    struct node *parent_node;
    struct node **nodes_inside;
    char name[256];
    char path[256];
    int children_count;
} node;

// TODO!
typedef enum {
    EXT_UNKNOWN = 0,
    EXT_TXT,
    EXT_PDF,
    EXT_DOC,
    EXT_DOCX,
    EXT_XLS,
    EXT_XLSX,
    EXT_PPT,
    EXT_PPTX,
    EXT_JPG,
    EXT_JPEG,
    EXT_PNG,
    EXT_GIF,
    EXT_MP3,
    EXT_WAV,
    EXT_FLAC,
    EXT_MP4,
    EXT_MKV,
    EXT_AVI,
    EXT_ZIP,
    EXT_RAR,
    EXT_7Z,
    EXT_TAR,
    EXT_GZ,
    EXT_HTML,
    EXT_CSS,
    EXT_JS,
    EXT_JSON,
    EXT_XML,
    EXT_C,
    EXT_CPP,
    EXT_H,
    EXT_PY,
    EXT_SH,
    EXT_SQL,
    EXT_EXE,
    EXT_DLL,

    EXT_TOTAL_COUNT
} extension;


node *node_constructor(node_type is_file, char *name, char *path, node *parent_node) {
    node *new_node = malloc(sizeof(node));
    new_node->children_count = 0;
    new_node->file_type = is_file;
    new_node->parent_node = parent_node;
    strcpy(new_node->name, name);
    strcpy(new_node->path, path);
    new_node->nodes_inside = NULL;
    return new_node;
}

void add_children_to_node(node *parent_node, node *node_to_add) {
    parent_node->children_count+=1;
    parent_node->nodes_inside = realloc(parent_node->nodes_inside, sizeof(node *) * parent_node->children_count);
    parent_node->nodes_inside[parent_node->children_count - 1] = node_to_add;
    node_to_add->parent_node = parent_node;
}

void tree(node *main_node, int depth) {
    for(int i=0; i<main_node->children_count; i++){
        if (main_node->nodes_inside[i]->file_type == DIRECTORY_NODE) {
            for (int j=0; j<depth; j++) {
                printf("    ");
            }
            printf("Directory: %s \n", main_node->nodes_inside[i]->name);
            tree(main_node->nodes_inside[i], depth+1);
        } else {
            for (int j=0; j<depth; j++) {
                printf("    ");
            }
            printf("File: %s \n", main_node->nodes_inside[i]->name);
        }
    }
}

int is_directory_in(node *parent_dir) {
    for(int i=0; i<parent_dir->children_count; i++) {
        if (parent_dir->nodes_inside[i]->file_type == DIRECTORY_NODE) {
            return 1;
        }
    }
    return 0;
}

void free_graph(node *main_node) {
    for(int i=0; i<main_node->children_count; i++){
        if (main_node->nodes_inside[i]->file_type == DIRECTORY_NODE) {
            free_graph(main_node->nodes_inside[i]);
        } else {
            printf("Deleted file: %s \n", main_node->nodes_inside[i]->name);
            free(main_node->nodes_inside[i]);
            
        }
    }
    printf("Deleted directory: %s \n", main_node->name);
    free(main_node->nodes_inside);
    free(main_node);
}

void check_and_free_graph(node *main_directory) {
    free_graph(main_directory);
    if(main_directory == NULL) {
        printf("Memory has been cleaned succesfully :3 \n");
    } else {
        printf("Something went wrong :c");
    }
    
}


int main(void) {
    node *main_directory = node_constructor(0, "MainDir", "/", NULL);

    node *subdir1 = node_constructor(0, "SubDir1", "/SubDir1", main_directory);
    node *subdir2 = node_constructor(0, "SubDir2", "/SubDir2", main_directory);
    node *subsubdir = node_constructor(0, "SubSubDir", "/SubDir2/SubSubDir", subdir2);

    node *file1 = node_constructor(1, "file1.txt", "/SubDir1/file1.txt", subdir1);
    node *file2 = node_constructor(1, "file2.txt", "/SubDir1/file2.txt", subdir1);
    node *file3 = node_constructor(1, "file3.txt", "/SubDir2/SubSubDir/file3.txt", subsubdir);
    node *rootfile = node_constructor(1, "rootfile.txt", "/rootfile.txt", main_directory);

    add_children_to_node(main_directory, subdir1);
    add_children_to_node(main_directory, subdir2);
    add_children_to_node(main_directory, rootfile);

    add_children_to_node(subdir1, file1);
    add_children_to_node(subdir1, file2);

    add_children_to_node(subdir2, subsubdir);
    add_children_to_node(subsubdir, file3);

    printf("___________________________________________________ \n");
    tree(main_directory, 0);

    check_and_free_graph(main_directory);
    return 0;
}
