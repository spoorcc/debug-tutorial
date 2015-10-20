#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE (20)
#define FIRST_FILE_NAME "foo.0"
#define SECOND_FILE_NAME "foo.1"
#define MY_SYM_LINK "foo"

void switch_sym_link(const char* file_name_ptr);

int main()
{

    /* Create two files: foo.0, foo.1 */
    FILE *f0 = fopen(FIRST_FILE_NAME, "w"); 
    FILE *f1 = fopen(SECOND_FILE_NAME, "w"); 

    /* Create symlink to first file: foo_link --> foo.0 */
    remove(MY_SYM_LINK);
    symlink(FIRST_FILE_NAME, MY_SYM_LINK);

    /* Switch symlink from first to second file foo.0 --> foo.1 */
    switch_sym_link(MY_SYM_LINK);

    fclose(f0);
    fclose(f1);
    
    return 0;
}

/**
 * \brief Moves symlink to point to next file with integer extension 
 *
 * \example
 *    foo --> foo.0
 *            foo.1
 * 
 *            foo.0
 *    foo --> foo.1
 *
 */
void switch_sym_link(const char* file_name_ptr)
{
   char buf[MAX_BUF_SIZE];
   int bufsize = 0;
   int file_index = 0;

   /* Get the file where thesymlink points to */
   bufsize = readlink(file_name_ptr, buf, MAX_BUF_SIZE);

   /* readlink returns a buffer which is not \0 ended */
   buf[bufsize+1] = '\0';

   printf("Currently pointing to %s\n", buf);

   /* Cannot create symlink when it already exists */
   remove(file_name_ptr);

   /* +1 to skip over dot */
   int index_of_int = strlen(file_name_ptr)+1; 

   /* Convert integer extension chars to int */
   file_index = atoi(buf + index_of_int);

   /* Create the new filename to point to and create the link */
   file_index++;
   sprintf(buf, "%s.%d", file_name_ptr, file_index);
   symlink(buf, file_name_ptr);

   printf("Now pointing to %s\n", buf);
}
