# 🏆 Corewar

<div align="center">
  
  [![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/your-username/corewar)
</div>

## 🚀 About The Project

**Corewar** is a programming game where champions written in a special assembly language battle in a virtual arena. Champions' programs are executed by a virtual machine, and the last program standing wins! This project includes an assembler, a virtual machine, and a visualizer to watch the battle unfold.

## ✨ Features

- **Assembler:** Compiles champion programs from assembly to bytecode
- **Virtual Machine:** Executes champion programs in the arena
- **Visualizer:** Real-time graphical representation of the battle
- **Champion Editor:** Tools to create and test your own warriors

## 📥 Installation

```bash
# Clone the repository
git clone https://github.com/your-username/corewar.git

# Navigate to the project directory
cd corewar

# Build the project
make
```

## 💻 Usage

### Assembling a Champion

```bash
./asm path/to/champion.s
```

This will create a champion.cor file containing the compiled bytecode.

### Running a Battle

```bash
./corewar [-dump N] [-v N] [-n N] <champion1.cor> <champion2.cor> ...
```

Options:
- `-dump N`: Dumps memory after N cycles
- `-v N`: Verbosity level
- `-n N`: Sets the number of the next player

### Using the Visualizer

```bash
./corewar -v 31 <champion1.cor> <champion2.cor> ...
```

## 🧠 Components

### The Virtual Machine

The VM is where champions fight. It:
- Creates a circular memory space for the battle
- Loads the compiled champions
- Executes their instructions
- Declares a winner

### The Assembly Language

Champions are written in a simple assembly language with operations like:

| Instruction | Description |
|-------------|-------------|
| `live`      | Tell the VM that the player is alive |
| `ld`        | Load a value into a register |
| `st`        | Store a register's value |
| `add`       | Add two registers into a third |
| `sub`       | Subtract two registers into a third |
| `and/or/xor`| Bitwise operations |
| `zjmp`      | Jump if zero |
| `fork`      | Create a copy of the program |
| `ldi/sti`   | Indirect load/store |

### Example Champion

```assembly
.name "Warrior"
.comment "Ready for battle!"

start:
    sti r1, %:live, %1
    
live:
    live %1
    zjmp %:live
```
