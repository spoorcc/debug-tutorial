#include <stdio.h>

#define MAX_BUF_SIZE (100)
#define FIRST_FILE_NAME "foo.0"
#define SECOND_FILE_NAME "foo.1"
#define MY_SYM_LINK "foo.link"

int main()
{

    /* Create a file: foo.0 */
    f0 = open(FIRST_FILE_NAME, O_RDWR | OCREAT, S_IRUSR | S_IRGRP | S_IROTH); 

    /* Create a second file: foo.1 */
    f1 = open(SECOND_FILE_NAME, O_RDWR | OCREAT, S_IRUSR | S_IRGRP | S_IROTH); 

    /* create symlink to first file: foo_link --> foo.0 */
    symlink("my_sym_link", FIRST_FILE_NAME);

    /* switch symlink from first to second file foo --> foo.1 */

}

int switch_sym_link(char* file_name_ptr)
{
   char buf[MAX_BUF_SIZE];
   int bufsize = 0;
   int file_index = 0;

   bufsize = readlink(file_name_ptr, buf, MAX_BUF_SIZE);

   buf[bufsize+1] = '\0';


   int index_of_int = strlen(file_name_ptr+1); 

   file_index = atoi(buf[index_of_int]);


}
