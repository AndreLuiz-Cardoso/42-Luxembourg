<h1 align=center>
	<b>Minishell</b>
</h1>

<p align=center>
	The <b>minishell</b> project aims to recreate a simplified Unix shell, focusing on replicating essential command behavior, process handling, pipes, redirections, and signal management. It is a fundamental step in the 42 School curriculum to consolidate knowledge in parsing, command execution, memory management, and Unix system programming.
</p>

---

<div align="center">
    <img src="https://github.com/AndreLuiz-Cardoso/42_badges_utils/blob/main/minishellm.png?raw=true"/>
</div>

---

## 🧠 About the Project

**minishell** is a minimalist version of a Unix shell. It interprets and executes user-typed commands, offering key functionalities like:

- Command execution with arguments
- Pipe handling (`|`)
- Redirections (`<`, `>`, `>>`, `<<`)
- Built-in commands (`cd`, `echo`, `env`, `export`, `unset`, `pwd`, `exit`)
- Environment variable expansion (`$VAR`, `$?`)
- Proper handling of single and double quotes
- Signal handling (`SIGINT`, `SIGQUIT`)

---

## ⚙️ Features

### ✅ Command Execution

The shell interprets user input and runs programs found in the system’s `PATH`. It also gracefully handles errors like unknown commands (`command not found`).

### 🔁 Supported Built-in Commands

- `echo`: with support for `-n` flag
- `cd`: changes directory with fallback to `$HOME`
- `pwd`: prints current working directory
- `export`: adds or modifies environment variables
- `unset`: removes environment variables
- `env`: prints the current environment
- `exit`: exits the shell

### 🧵 Pipes & Redirections

`minishell` supports combining commands via `|` and handles:

- `>`: redirect output to a file
- `>>`: append output to a file
- `<`: redirect input from a file
- `<<`: here-document, reads input until a delimiter

### 💬 Expansions

- Environment variable expansion with `$VAR`, and `$?` (last exit status)
- Support for `~` as `$HOME`
- Accurate quote interpretation (no expansion in single quotes)

### 📛 Signal Handling

Gracefully manages `SIGINT` (Ctrl+C) and `SIGQUIT` (Ctrl+\) with different behavior in prompt, child processes, and here-docs.

---

## 🔍 Architecture & Execution Cycle

1. **Prompt**: displays `<minishell>` and reads input using `readline()`
2. **Parsing**: handles quotes, pipes, and redirection symbols
3. **Tokenization**: splits the input line into command tokens and arguments
4. **Execution**:
   - Detects built-ins
   - Locates binaries in `PATH` if not a built-in
   - Handles redirections
   - Uses `fork()` and `execve()` for process creation
   - Manages pipes with `pipe()`
5. **Signal Management**: sets up different signal handlers per context
6. **Cleanup**: releases memory and resets the shell for the next command

---

## 🧪 Usage Examples

```bash
<minishell> echo Hello World
Hello World

<minishell> ls | grep ".c" > files.txt

<minishell> export VAR=42
<minishell> echo $VAR
42

<minishell> cat << EOF
> testing here-doc
> EOF
```
## 🚫 Error Handling

Robust error handling is a key part of `minishell`, ensuring that user mistakes are caught and appropriate messages are displayed. The shell handles:

- **Syntax Errors**: Detects malformed commands involving pipes (`|`) or redirections (`<`, `>`, `>>`, `<<`) and prints an appropriate error.
- **Command Not Found**: If a command isn't found in the environment’s `PATH`, a clear `command not found` message is shown.
- **File Handling Errors**: When input/output redirection involves non-existent or inaccessible files, the shell gracefully notifies the user (e.g., `No such file or directory`).
- **Directory Errors in `cd`**: Invalid directories passed to `cd` result in an error indicating the path doesn’t exist or is not accessible.
- **Export Errors**: Variables passed to `export` are validated, and malformed variables (e.g., missing `=` or invalid names) are rejected.
- **Exit Status Propagation**: The special variable `$?` always reflects the last command’s exit code, ensuring scripts and conditional logic behave correctly.

---

## 🛠️ Technical Highlights

### 🔐 Sophisticated Redirection Handling

The shell uses `open()`, `dup2()`, and `close()` to implement robust I/O redirections. Special attention is paid to:

- Handling `<<` here-documents via temporary files
- Avoiding file descriptor leaks
- Respecting quoting rules inside heredocs

### 🧵 Multi-Process Execution with Pipes

Using `fork()`, `pipe()`, and `execve()`, the shell allows the user to execute pipelines (`cmd1 | cmd2 | cmd3`) with precise control over input/output streams between child processes.

### 📦 Dynamic Environment Management

Instead of relying on system-provided `envp`, `minishell` builds and manages its own environment structure. This supports:

- Real-time changes using `export` and `unset`
- Manual PATH parsing for executable resolution
- `HOME` detection and usage

### 🚨 Signal Handling

Signals are handled with fine granularity to mimic real shell behavior:

- In the **prompt**: `Ctrl+C` clears the line and redraws the prompt, while `Ctrl+\` is ignored.
- In **child processes**: Signals like `SIGQUIT` are correctly forwarded (e.g., during `cat` or `sleep`).
- In **here-docs**: Signals are managed to allow clean exits from multiline input.

---

## 🧬 Code Structure Overview

The codebase is modular and split across key components:

| File           | Purpose                                      |
|----------------|----------------------------------------------|
| `main.c`       | Main loop and initialization                 |
| `split_cmd.c`  | Parses and splits user input into commands   |
| `run_pipe.c`   | Executes commands with or without pipes      |
| `redir_in.c`   | Handles input redirection and here-docs      |
| `ft_echo.c`    | Implementation of `echo` builtin             |
| `ft_cd.c`      | Implementation of `cd` builtin               |
| `ft_env.c`     | Handles environment setup and `env`          |
| `ft_export.c`  | Adds/modifies environment variables          |
| `signal.c`     | Signal setup and handlers                    |
| `token.c`      | Expands variables and handles quoting        |

---

## 💡 Final Thoughts

The **minishell** project is more than just a coding exercise — it’s a deep dive into the fundamentals of Unix programming. It demonstrates the ability to:

- Write safe, efficient C code
- Build a process management system from scratch
- Handle asynchronous behavior with signals
- Manage memory and resources manually

This shell mimics real-world behavior and lays the groundwork for more advanced interpreters or scripting tools. It's a clear testament to low-level programming mastery.

---

## 🧠 Credits

Developed by André Luiz Cardoso as part of the [42 School](https://42.fr/) curriculum. Built with a focus on robustness, performance, and real Unix compliance.

---


