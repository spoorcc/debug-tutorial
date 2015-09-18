#include <stdio.h>

#define MAX_BUF_SIZE (100)

int main()
{

    /* Create a file: foo.0 */
 

    /* Create a second file: foo.1 */


    /* create symlink to first file: foo_link --> foo.0 */


    /* switch symlink from first to second file foo_link --> foo.1 */

}

int switch_sym_link(char* file_name_ptr)
{
   char buf[MAX_BUF_SIZE];
   int bufsize = 0;

   bufsize = readlink(file_name_ptr, buf, MAX_BUF_SIZE);

   buf[bufsize+1] = '\0'

   /* TODO: Add atoi use */   
}
