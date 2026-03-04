# Final Algorithm Programming Project

This repository contains a pair of C programs written for an academic final project. The code analyses Indonesian corn (maize) statistics for **harvest area**, **production**, and **productivity** across 34 provinces over the years **2020‑2023**. It reads data from plain text files and provides console-based reports, sorting, searching and simple calculations.

> ⚠️ `Group1Pertanian.c` and `TubesAlpro.c` are nearly identical – the latter appears to be an earlier/alternate version of the same program. You can build and run either one.

---

## 🔍 Data files
The data shipped with the repository are plain CSV-like text files (no header rows). They were derived from the original CSV to simplify parsing.

| Filename                      | Description                                                  | Format per line                                           |
|------------------------------|--------------------------------------------------------------|-----------------------------------------------------------|
| `LuasPanen.txt`              | Harvest area (hectares) per province/year                    | `PROVINCE,2023,2022,2021,2020`                            |
| `Produksi.txt`               | Corn production (tons)                                        | `PROVINCE,2023,2022,2021,2020`                            |
| `Produktivitas.txt`          | Corn productivity (quintals per hectare)                     | `PROVINCE,2023,2022,2021,2020`                            |
| `Luas Panen, Produksi, ...`  | original CSV (for reference)                                 | —                                                         |

All three data files list the same 34 Indonesian provinces.

---

## ✅ Features
The console menu allows the user to:

1. **Display raw data & averages** for all provinces.
2. **Sort data** – by province name or by a specific year (ascending/descending).
3. **Search** for statistics of a single province.
4. **Compute totals** for Indonesia and optionally compare a province.
5. **View highest/lowest** values for a given year and category.
6. Exit the program.

> Each action clears the screen and returns to the main menu when done.

---

## 🛠 Build & run
You just need a C compiler (e.g. `gcc`, `clang`, or `Visual Studio` on Windows).

### Compile with GCC (Windows PowerShell example)
```powershell
cd "c:\Users\Mitch\Downloads\Final-Algorithm-Programming-Project"

gcc -o pertanian Group1Pertanian.c
# or compile the alternate version:
#gcc -o pertanian TubesAlpro.c
```

### Run
```powershell
./pertanian
```
The program expects the three `.txt` files to be in the same working directory.

> Windows users may need to use `pertanian.exe` instead of `./pertanian`.

---

## 📋 Usage notes
- Input is read via `scanf` and `fgets`; strings are upper‑cased for case‑insensitive matching.
- Sorting is implemented with simple bubble‑sort routines.
- All calculations use floating‑point types and print two decimals.

You can navigate the numbered menus and choose sub‑options as prompted. Invalid choices will often repeat the prompt.

---

## 💡 Potential improvements
- Refactor to remove code duplication between the two source files.
- Replace bubble sort with a more efficient algorithm or `qsort` from the standard library.
- Add command‑line arguments to bypass the interactive menu for scripting.
- Validate user input more robustly.
- Store data in a binary format or use dynamic memory for scalability.

---

## 📁 Repository structure
```
Final-Algorithm-Programming-Project/
├── Group1Pertanian.c      # main implementation
├── TubesAlpro.c           # alternate/duplicate implementation
├── LuasPanen.txt          # harvest area data
├── Produksi.txt           # production data
├── Produktivitas.txt      # productivity data
├── Luas Panen,...csv      # original CSV dataset
└── README.md              # this file
```

---

## 📞 Contact / Credits
This project was developed by **Group 1** for an algorithm programming class. Feel free to modify or extend the code for learning purposes.

---

Happy coding! 🌽