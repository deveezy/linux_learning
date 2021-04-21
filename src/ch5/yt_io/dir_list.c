// #include <stdio.h>
// #include <string.h>
// #include <dirent.h>

// void list_files(const char* path)
// {
//     DIR* dir = opendir(path);
//     if (!dir) return;

//     struct dirent* entity;

//     while ((entity = readdir(dir)))
//     {
//         if (strcmp(entity->d_name, ".") == 0  || strcmp(entity->d_name, "..") == 0)
//             continue;

//         if (entity->d_type == DT_DIR)
//         {
//             char new_path[100] = { 0 };
//             strcat(new_path, path);
//             strcat(new_path, "/");
//             strcat(new_path, entity->d_name);
//             list_files(new_path);
//         }
//         printf("%s\n", entity->d_name);
//     }

//     closedir(dir);
// }

// int main()
// {
//     list_files(".");
//     return 0;
// }