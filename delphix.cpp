#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

bool isDirectory(string directory)
{
    struct stat fileInfo;
    stat(directory.c_str(), &fileInfo);
    if (S_ISDIR(fileInfo.st_mode))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void find_and_exec(string mDirectoryToSearch, const char* executable)
{
    mDirectoryToSearch.append("/");
    DIR* directory = opendir(mDirectoryToSearch.c_str());
    if ( directory == NULL)
    {
        system("echo Not A Directory");
        return;
    }
    else
    {
        struct dirent* mDirent; //readdir returns a pointer to a dirent structure
        while((mDirent = readdir(directory)) != NULL) //for all items in Directory readdir parses the directory to dirent*
        {   
            string mDirentDName = mDirent->d_name; //contains file items including subdirectories
            if (mDirentDName != "." && mDirentDName != "..") //to bypass ../
            {
                if (isDirectory(mDirectoryToSearch + mDirentDName)) // if is directory I want to traverse deeper dfs approach
                {
                    find_and_exec(mDirectoryToSearch + mDirentDName , executable);
                }
                else
                {   
                    string mPath = mDirectoryToSearch + mDirentDName;
                    if(is_regular_file(mPath.c_str()))
                    {
                        string mExecute = executable;
                        mExecute.append(" ");
                        mExecute.append(mPath);
                        system(mExecute.c_str());
                    }
                }
            }
            //when hits here should backtrack to the next directory in a parent folder.
        }
        closedir(directory);
    }
}

int main(int argc, char *argv[])
{
    string mCommand = "/bin/echo";
    const char* mExecute = mCommand.c_str(); //gets rid of compile warnings
    find_and_exec("/home", mExecute);
    
    //find_and_exec("/home", argv[1]);
    
    /*
    
    This following line is unclear to me because Coder Pad is not passing in any arguements into argv[1].
    
    "Each invocation of the executable should have the file that was just found passed in as argv[1]."
    
    Because Coder Pad is not passing in anything into argv[1],
    I have left my code to manually set the command and root directory.
    so to test this functionality please uncomment line 74 and comment out lines 70-72. 
    
    Thanks for the interview, it was a great learning experience.
    */
    return 0;
}
/*

#
# # 
# # Your previous Plain Text content is preserved below:
# # 
# # This is just a simple shared plaintext pad, with no execution capabilities.
# # 
# # When you know what language you'd like to use for your interview,
# # simply choose it from the dropdown in the top bar.
# # 
# # You can also change the default language your pads are created with
# # in your account settings: https://coderpad.io/profile
# # 
# # Enjoy your interview!
# # 
# # 
# # ===== Preface =====
# # 
# # We believe that this question works best when implemented in C or
# # C++. If you're reading this, you should have already expressed a
# # desire to program in one of these languages. If you would prefer
# # to program in a different language, please reach out to us so we
# # can provide a more appropriate question!
# # 
# # 
# # ===== Intro =====
# # 
# # As a programmer, a common workflow is to run some program against
# # every file in your codebase -- searching for references to a
# # feature you're removing, running a lint or style checking program,
# # or deleting it all when you're ready to start from scratch. :-)
# # One simple way to do these tasks is with the Unix shell command:
# # 
# #     $ find /path/to/codebase/ -exec /path/to/executable {} \;
# # 
# # We would like you to implement something very similar as a function
# # find_and_exec() that recursively searches a directory structure and
# # runs an executable on each regular file it finds. Each invocation
# # of the executable should have the file that was just found passed
# # in as argv[1].
# # 
# # The order you process the files in does not matter. To avoid
# # interleaving output from the various subprocesses, your code
# # should run each invocation sequentially rather than in parallel.
# # Purely for ease of implementation, we'd recommend using system()
# # to run subprocesses instead of fork() and exec().
# # 
# # You can assume that we will only test your function on "ordinary"
# # directory structures. You only need to handle regular files and
# # directories; no symlinks, pipes, sockets, block / character
# # special files, etc.
# # 
# # Finally, please help us by keeping this question and your answer
# # secret so that every candidate has a fair chance in future Delphix
# # interviews. Thank you!
# # 
# # 
# # ===== Steps =====
# # 
# # 1.  Choose the language you want to code in from the menu
# #     labeled "Plain Text" in the top right corner of the
# #     screen. You will see a "Run" button appear on the top
# #     left -- clicking this will send your code to a Linux
# #     server and compile / run it. Output will appear on the
# #     right side of the screen.
# #     
# #     For information about what libraries are available for
# #     your chosen language, see:
# # 
# #       https://coderpad.io/languages
# # 
# # 2.  Implement a function whose method signature looks like this:
# # 
# #       void find_and_exec(char *top_level_dir, char *executable);
# # 
# #     For example, find_and_exec("/home", "/bin/echo") might print
# #     something like:
# # 
# #       /home/coderpad/.bash_logout
# #       /home/coderpad/.bashrc
# #       /home/coderpad/.profile
# #       /home/coderpad/execute
# #       /home/coderpad/initshell
# #       /home/coderpad/README_IF_YOU_ARE_HACKING_ME
# #       /home/coderpad/solution
# #       /home/coderpad/solution.c
# # 
# #     If you want to change the signature to deal with error
# #     conditions or some other complexity not captured by the one
# #     above, go for it! Just add a comment telling us what you
# #     changed and why.
# # 
# # 3.  Add any tests for your code to the main() method of your
# #     program so that we can easily run them.
# # 
# # 
# # ====== FAQs =====
# # 
# # Q:  How do I know if my solution is correct?
# # A:  Make sure you've read the prompt carefully and you're
# #     convinced your program does what you think it should
# #     in the common case. If your program does what the prompt 
# #     dictates, you will get full credit. We do not use an
# #     auto-grader, so we do not have any values for you to
# #     check correctness against.
# #     
# # Q:  If I need a clarification, who should I ask?
# # A:  Send all questions to the email address that sent you
# #     this document, and an engineer at Delphix will get
# #     back to you ASAP (we're pretty quick during normal
# #     business hours).
# # 
# # Q:  How long should this question take me?
# # A:  Approximately 1 hour, but it could take more or less
# #     depending on your experience with relevant library calls
# #     and the language you choose.
# # 
# # Q:  When is this due?
# # A:  We will begin grading your answer 24 hours after it is
# #     sent to you, so that is the deadline.
# # 
# # Q:  How do I turn in my solution?
# # A:  Anything you've typed into this document will be saved.
# #     Email us when you are done with your solution. We will
# #     respond confirming we've received the solution within
# #     24 hours.
# # 
# # Q:  Can I use any external resources to help me?
# # A:  Absolutely! Feel free to use any online resources you
# #     like, but please don't collaborate with anyone else.
# # 
# # Q:  Can I use my favorite library in my program?
# # A:  Unfortunately, there is no way to load external
# #     libraries into CoderPad, so you must stick to what
# #     they provide out of the box for your language:
# # 
# #       https://coderpad.io/languages
# # 
# #     If you really want to use something that's not
# #     available, email the person who sent you this link
# #     and we will work with you to find a solution.
# # 
# # Q:  Why does my program terminate unexpectedly in
# #     CoderPad, and why can't I read from stdin or pass
# #     arguments on the command line?
# # A:  CoderPad places a limit on the runtime and amount of
# #     output your code can use, but you should be able to
# #     make your code fit within those limits. You can hard
# #     code any arguments or inputs to the program in your
# #     main() method or in your tests. CoderPad also kills
# #     subprocesses when your main program exits, so to exit
# #     cleanly with asynchronous subprocesses you must use
# #     waitpid() or something equivalent.
# # 
# # Q:  I'm a Vim/Emacs fan -- is there any way to use those
# #     keybindings? What about changing the tab width? Font
# #     size?
# # A:  Yes! Hit the button at the bottom of the screen that
# #     looks like a keyboard.
# #  */
