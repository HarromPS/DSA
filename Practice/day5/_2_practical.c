#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <process.h>

int main() {
    // Get the process ID of the parent
    int parent_pid = _getpid();

    // Specify the full path to cmd.exe
    const char *cmd_path = "C:\\Windows\\System32\\cmd.exe";

    // Spawn a child process
    int child_pid = _spawnl(_P_NOWAIT, cmd_path, cmd_path, "/c", "dir", NULL);

    if (child_pid == -1) {
        perror("Spawn failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid != -1) {
        // This is the parent process

        // Wait for the child process to finish
        int status;
        _cwait(&status, child_pid, WAIT_CHILD);

        // Print parent and child process IDs
        printf("Parent process (PID: %d) waited for child process (PID: %d)\n", parent_pid, child_pid);
    }

    return 0;
}
