# WriterPuma
A lightweight, native text editor built with GTK4 and C.

---

## Features

- [x] Native GTK4 window
- [x] Open files
- [x] Save files
- [ ] Syntax highlighting
- [ ] Multiple tabs
- [ ] Find & replace
- [ ] Preferences / settings

---

## Dependencies

Make sure you have the following installed:

```bash
# Arch Linux
sudo pacman -S gtk4 gcc make

# Ubuntu / Debian
sudo apt install libgtk-4-dev gcc make
```

Optional (for development with LSP support):
```bash
# Arch Linux
sudo pacman -S clang clangd

# Ubuntu / Debian
sudo apt install clangd
```

---

## Build & Run

```bash
# Clone the repo
git clone https://github.com/josyrus/WriterPuma.git
cd WriterPuma

# Compile
make

# Run
./build/main
```

To clean build artifacts:
```bash
make clean
```

---

## Project Structure

```
WriterPuma/
├── src/                  # Source files
│   ├── main.c            # Entry point
│   ├── file_manager.c    # Open/save file logic
│   └── open_puma_ui_controller.c  # UI event handling
├── ui/
│   └── core.c            # Core UI layout and widgets
├── include/              # Header files
├── build/                # Compiled output (git-ignored)
├── test/                 # Test files
└── Makefile
```

---

## Requirements

- GCC 12+
- GTK 4.x

---

## License

MIT License — see [LICENSE](LICENSE) for details.
