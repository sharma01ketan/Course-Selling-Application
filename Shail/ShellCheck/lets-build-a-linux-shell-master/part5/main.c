#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
#include "source.h"
#include "parser.h"
#include "executor.h"


int main(int argc, char **argv)
{
    //cmd is the input that I have scanned
    char *cmd;

    initsh();
    
    //do a few things depending on my input
    do
    {
        print_prompt1();
        cmd = read_cmd();
        if(!cmd)
        {
            exit(EXIT_SUCCESS);
        }
        if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }
        if(strcmp(cmd, "exit\n") == 0)
        {
            free(cmd);
            break;
        }
	struct source_s src;
        src.buffer   = cmd;
        src.bufsize  = strlen(cmd);
        src.curpos   = INIT_SRC_POS;
        parse_and_execute(&src);
        free(cmd);
    } while(1);
    exit(EXIT_SUCCESS);
}


char *read_cmd(void)
{
    char buf[1024];
    char *ptr = NULL;
    char ptrlen = 0;
    while(fgets(buf, 1024, stdin))
    {
        int buflen = strlen(buf);//length of the current input
        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
        else
        {
            //it reallocates memory using realloc to accomodate 
            //the existing content and the new line
            // ptr = pointer to the previously allocated mempory block
            // ptrlen = length of the commands stored in ptr
            // buflen = length of the current input being read 
            // ptrlen + buflen + 1
            // ptrlen = existing accumulated command length
            // buflen = length of the current line being read 
            // +1 = additional space for the null terminator 
            char *ptr2 = realloc(ptr, ptrlen+buflen+1);
            if(ptr2)
            {
                //making ptr pointing to the whole command
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }
        if(!ptr)
        {
            fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
            return NULL;
        }
        //copies the current line (buf) to the end of the accumulated command ('ptr')
        strcpy(ptr+ptrlen, buf);
        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
            {
                return ptr;
            }
            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            print_prompt2();
        }
        ptrlen += buflen;
    }
    return ptr;
}


int parse_and_execute(struct source_s *src)
{
    skip_white_spaces(src);

    struct token_s *tok = tokenize(src);

    if(tok == &eof_token)
    {
        return 0;
    }

    while(tok && tok != &eof_token)
    {
        struct node_s *cmd = parse_simple_command(tok);

        if(!cmd)
        {
            break;
        }

        do_simple_command(cmd);
        free_node_tree(cmd);
        tok = tokenize(src);
    }
    return 1;
}




//char buf[] = "This is a sample command line with a backslash at the end\\\n";
/*
Now, let's analyze this string:

buf contains the string "This is a sample command line with a backslash at the end\\\n"
buflen would be the length of this string, which is 53 characters (including the newline character).
The condition buf[buflen - 2] != '\\' in this case checks if the second-to-last character in buf is not a backslash ('\\'). In this example:

buf[buflen - 2] refers to buf[53 - 2], which is buf[51].
buf[51] contains the character '\\'.
Therefore, in this particular example, the condition buf[buflen - 2] != '\\' evaluates to false because the second-to-last character in the string is indeed a backslash ('\\'). This means the line continuation condition is met, indicating that the command continues onto the next line.

If the condition were true (if the second-to-last character was not a backslash), it would signify the end of the command line, indicating that the command is complete and doesn't continue onto the next line.

So, in summary, in this context:

buf[buflen - 2] != '\\' evaluates to false in the provided example because the second-to-last character is a backslash.
This signifies that the command likely continues onto the next line due to the backslash acting as a line continuation marker.
*/