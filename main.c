#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FILE_NODE, DIRECTORY_NODE }node_type;

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

typedef struct node {
    node_type file_type;
    extension file_ext;
    struct node *parent_node;
    struct node **nodes_inside;
    char name[256];
    char path[256];
    int children_count;
} node;


node *node_constructor(node_type file_type, char *name, char *path, node *parent_node) {
    node *new_node = malloc(sizeof(node));
    new_node->children_count = 0;
    new_node->file_type = file_type;
    new_node->parent_node = parent_node;
    strcpy(new_node->name, name);
    strcpy(new_node->path, path);
    new_node->nodes_inside = NULL;
    return new_node;
}

void update_node_ext(node *file_to_update) {
    char tmp[256];
    if(file_to_update->file_type == DIRECTORY_NODE) {
        printf("THIS IS A DIRECTORY >:c");
    } else {
        int i=0;
        int j=0;
        int is_dot = 0;
        char *name = file_to_update->name;
        while (name[i] != '\0') {
            if(is_dot == 1) {
                tmp[j] = name[i];
                j++; 
            }
            if(name[i] == '.') {
                is_dot = 1;
            }
            i++;
        }
    }

    if (strcmp(tmp, "txt") == 0) {
        file_to_update->file_ext = EXT_TXT;
        printf("Znaleziono txt\n");
    } else if (strcmp(tmp, "pdf") == 0) {
        file_to_update->file_ext = EXT_PDF;
        printf("Znaleziono pdf\n");
    } else if (strcmp(tmp, "doc") == 0) {
        file_to_update->file_ext = EXT_DOC;
        printf("Znaleziono doc\n");
    } else if (strcmp(tmp, "docx") == 0) {
        file_to_update->file_ext = EXT_DOCX;
        printf("Znaleziono docx\n");
    } else if (strcmp(tmp, "xls") == 0) {
        file_to_update->file_ext = EXT_XLS;
        printf("Znaleziono xls\n");
    } else if (strcmp(tmp, "xlsx") == 0) {
        file_to_update->file_ext = EXT_XLSX;
        printf("Znaleziono xlsx\n");
    } else if (strcmp(tmp, "ppt") == 0) {
        file_to_update->file_ext = EXT_PPT;
        printf("Znaleziono ppt\n");
    } else if (strcmp(tmp, "pptx") == 0) {
        file_to_update->file_ext = EXT_PPTX;
        printf("Znaleziono pptx\n");
    } else if (strcmp(tmp, "jpg") == 0) {
        file_to_update->file_ext = EXT_JPG;
        printf("Znaleziono jpg\n");
    } else if (strcmp(tmp, "jpeg") == 0) {
        file_to_update->file_ext = EXT_JPEG;
        printf("Znaleziono jpeg\n");
    } else if (strcmp(tmp, "png") == 0) {
        file_to_update->file_ext = EXT_PNG;
        printf("Znaleziono png\n");
    } else if (strcmp(tmp, "gif") == 0) {
        file_to_update->file_ext = EXT_GIF;
        printf("Znaleziono gif\n");
    } else if (strcmp(tmp, "mp3") == 0) {
        file_to_update->file_ext = EXT_MP3;
        printf("Znaleziono mp3\n");
    } else if (strcmp(tmp, "wav") == 0) {
        file_to_update->file_ext = EXT_WAV;
        printf("Znaleziono wav\n");
    } else if (strcmp(tmp, "flac") == 0) {
        file_to_update->file_ext = EXT_FLAC;
        printf("Znaleziono flac\n");
    } else if (strcmp(tmp, "mp4") == 0) {
        file_to_update->file_ext = EXT_MP4;
        printf("Znaleziono mp4\n");
    } else if (strcmp(tmp, "mkv") == 0) {
        file_to_update->file_ext = EXT_MKV;
        printf("Znaleziono mkv\n");
    } else if (strcmp(tmp, "avi") == 0) {
        file_to_update->file_ext = EXT_AVI;
        printf("Znaleziono avi\n");
    } else if (strcmp(tmp, "zip") == 0) {
        file_to_update->file_ext = EXT_ZIP;
        printf("Znaleziono zip\n");
    } else if (strcmp(tmp, "rar") == 0) {
        file_to_update->file_ext = EXT_RAR;
        printf("Znaleziono rar\n");
    } else if (strcmp(tmp, "7z") == 0) {
        file_to_update->file_ext = EXT_7Z;
        printf("Znaleziono 7z\n");
    } else if (strcmp(tmp, "tar") == 0) {
        file_to_update->file_ext = EXT_TAR;
        printf("Znaleziono tar\n");
    } else if (strcmp(tmp, "gz") == 0) {
        file_to_update->file_ext = EXT_GZ;
        printf("Znaleziono gz\n");
    } else if (strcmp(tmp, "html") == 0) {
        file_to_update->file_ext = EXT_HTML;
        printf("Znaleziono html\n");
    } else if (strcmp(tmp, "css") == 0) {
        file_to_update->file_ext = EXT_CSS;
        printf("Znaleziono css\n");
    } else if (strcmp(tmp, "js") == 0) {
        file_to_update->file_ext = EXT_JS;
        printf("Znaleziono js\n");
    } else if (strcmp(tmp, "json") == 0) {
        file_to_update->file_ext = EXT_JSON;
        printf("Znaleziono json\n");
    } else if (strcmp(tmp, "xml") == 0) {
        file_to_update->file_ext = EXT_XML;
        printf("Znaleziono xml\n");
    } else if (strcmp(tmp, "c") == 0) {
        file_to_update->file_ext = EXT_C;
        printf("Znaleziono c\n");
    } else if (strcmp(tmp, "cpp") == 0) {
        file_to_update->file_ext = EXT_CPP;
        printf("Znaleziono cpp\n");
    } else if (strcmp(tmp, "h") == 0) {
        file_to_update->file_ext = EXT_H;
        printf("Znaleziono h\n");
    } else if (strcmp(tmp, "py") == 0) {
        file_to_update->file_ext = EXT_PY;
        printf("Znaleziono py\n");
    } else if (strcmp(tmp, "sh") == 0) {
        file_to_update->file_ext = EXT_SH;
        printf("Znaleziono sh\n");
    } else if (strcmp(tmp, "sql") == 0) {
        file_to_update->file_ext = EXT_SQL;
        printf("Znaleziono sql\n");
    } else if (strcmp(tmp, "exe") == 0) {
        file_to_update->file_ext = EXT_EXE;
        printf("Znaleziono exe\n");
    } else if (strcmp(tmp, "dll") == 0) {
        file_to_update->file_ext = EXT_DLL;
        printf("Znaleziono dll\n");
    } else {
        file_to_update->file_ext = EXT_UNKNOWN;
        printf("Nieznane rozszerzenie: %s\n", tmp);
    }

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
    node *main_directory = node_constructor(DIRECTORY_NODE, "MainDir", "/", NULL);

    node *subdir1 = node_constructor(DIRECTORY_NODE, "SubDir1", "/SubDir1", main_directory);
    node *subdir2 = node_constructor(DIRECTORY_NODE, "SubDir2", "/SubDir2", main_directory);
    node *subsubdir = node_constructor(DIRECTORY_NODE, "SubSubDir", "/SubDir2/SubSubDir", subdir2);

    node *file1 = node_constructor(FILE_NODE, "file1.txt", "/SubDir1/file1.txt", subdir1);
    node *file2 = node_constructor(FILE_NODE, "file2.txt", "/SubDir1/file2.txt", subdir1);
    node *file3 = node_constructor(FILE_NODE, "file3.txt", "/SubDir2/SubSubDir/file3.txt", subsubdir);
    node *rootfile = node_constructor(FILE_NODE, "rootfile.txt", "/rootfile.txt", main_directory);

    add_children_to_node(main_directory, subdir1);
    add_children_to_node(main_directory, subdir2);
    add_children_to_node(main_directory, rootfile);

    add_children_to_node(subdir1, file1);
    add_children_to_node(subdir1, file2);

    add_children_to_node(subdir2, subsubdir);
    add_children_to_node(subsubdir, file3);

    update_node_ext(file1);
    update_node_ext(file2);
    update_node_ext(file3);
    update_node_ext(rootfile);

    check_and_free_graph(main_directory);

    // printf("___________________________________________________ \n");
    // tree(main_directory, 0);

    // check_and_free_graph(main_directory);
    // printf("___________________________________________________ \n");
    // char *x = file1->name;
    // int i=0;
    // while(x[i] != '.') {
    //     printf("%c\n", x[i]);
    //     i++;
    // }

    // printf("%s\n", x);
    update_node_ext(file1);
    return 0;
}
