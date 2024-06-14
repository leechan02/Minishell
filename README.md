# Minishell

Minishell is a simple Unix shell implementation in C designed to provide basic shell functionalities, such as command parsing and execution, handling built-in commands, and managing I/O redirections. This README provides an in-depth look at its features and code structure.

## Table of Contents
1. [Features](#features)
2. [Code Structure](#code-structure)
3. [Built-in Commands](#built-in-commands)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Contributing](#contributing)

## Features

### Command Parsing
Minishell parses commands by:
1. **Quote and Pipe Handling**: Detects quotes and splits tokens based on pipes.
2. **Token Division**: Divides tokens using spaces and redirection operators (`< > << >>`).
3. **I/O Redirection Check**: Scans tokens for input/output redirection.
4. **Variable Replacement**: Replaces `$` prefixed strings with corresponding environment variables.
5. **Quote Removal**: Removes quotes from the processed tokens.

### Command Execution
Minishell executes commands by:
1. **Handling Here Documents (`<<`)**: Processes here documents and replaces them with temporary files.
2. **Command Execution**: Differentiates between single and piped commands, and executes built-in or external commands accordingly.

## Code Structure
The Minishell project is organized into several key components:

### Main Components
- **main.c**: The entry point of the shell.
- **parser.c**: Contains functions for parsing commands.
- **executor.c**: Manages the execution of parsed commands.
- **builtins.c**: Implements built-in shell commands.
- **signals.c**: Handles signal management for the shell.
- **utils.c**: Utility functions for common tasks.

### Key Functions
- **parse_command**: Parses the input command string.
- **execute_command**: Executes parsed commands.
- **handle_redirection**: Manages input and output redirections.
- **expand_variables**: Replaces environment variables in commands.
- **remove_quotes**: Removes quotes from command arguments.

### Error Handling
Minishell includes robust error handling to manage:
- Invalid commands
- Syntax errors
- Memory leaks (checked using tools like `valgrind`)

## Built-in Commands
Minishell supports the following built-in commands:
- `echo`: Displays a line of text.
- `cd`: Changes the current directory.
- `pwd`: Prints the current working directory.
- `export`: Sets environment variables.
- `unset`: Unsets environment variables.
- `env`: Displays the environment variables.
- `exit`: Exits the shell.

## Installation
To install and compile Minishell, follow these steps:
1. Clone the repository:
   ```sh
   git clone https://github.com/leechan02/Minishell.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Minishell
   ```
3. Compile the shell:
   ```sh
   make
   ```

## Usage
To start using Minishell, run the following command:
```sh
./minishell
```
You can then enter commands as you would in a standard Unix shell.
