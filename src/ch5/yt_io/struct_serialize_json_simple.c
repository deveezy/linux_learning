// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// const char* PERSON_FORMAT_IN  = "(%[^,], %d, %c)";
// const char* PERSON_FORMAT_OUT = "(%s, %d, %c)\n";

// const char* PERSON_JSON_FORMAT_IN  = "{\n\t\"name\": \"%[^\"]\",\n\t\"name\": %d,\n\t\"gender\": \"%c\"\n}";
// const char* PERSON_JSON_FORMAT_OUT = "{\n\t\"name\": \"%s\",\n\t\"name\": %d,\n\t\"gender\": \"%c\"\n}";


// typedef struct 
// {
//     char name[20];
//     int  age;
//     char gender;
// } Person;

// int main()
// {
//     Person p1 =
//     {
//         .name   = "Andrew",
//         .age    = 22,
//         .gender = 'M'
//     };

//     FILE* file = fopen("people.dat", "w+");
//     if (!file) return 1;
//     fprintf(file, PERSON_JSON_FORMAT_OUT, p1.name, p1.age, p1.gender);

//     fseek(file, 0, SEEK_SET);

//     Person p2;
//     fscanf(file, PERSON_JSON_FORMAT_IN, p2.name, &p2.age, &p2.gender);
//     printf(PERSON_JSON_FORMAT_OUT, p2.name, p2.age, p2.gender);
//     fclose(file);
//     return 0;
// }