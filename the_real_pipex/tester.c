#include <unistd.h>
#include <stdlib.h>

void test_pipex(char *program_path) {
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd2[] = {"grep", "main", NULL};
    char *file_in = "test_input.txt";
    char *file_out = "test_output.txt";

    // Test 1: Normal operation
    dup2(open(file_in, O_RDONLY), STDIN_FILENO);
    dup2(open(file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
    execlp(program_path, "pipex", cmd1[0], cmd2[0], NULL);

    // Test 2: Empty input file
    close(STDIN_FILENO);
    open("/dev/null", O_RDONLY);
    dup2(open(file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
    execlp(program_path, "pipex", cmd1[0], cmd2[0], NULL);

    // Test 3: Non-existent input file
    close(STDIN_FILENO);
    dup2(open("non_existent_file", O_RDONLY), STDIN_FILENO);
    dup2(open(file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
    execlp(program_path, "pipex", cmd1[0], cmd2[0], NULL);

    // Test 4: Invalid command
    close(STDIN_FILENO);
    dup2(open(file_in, O_RDONLY), STDIN_FILENO);
    dup2(open(file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
    execlp(program_path, "pipex", "invalid_command", cmd2[0], NULL);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        write(2, "Usage:./tester <path_to_pipex>\n", 33);
        return 1;
    }
    test_pipex(argv[1]);
    return 0;
}
