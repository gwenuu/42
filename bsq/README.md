# BSQ

## Description
BSQ finds and prints the biggest possible square that fits on a map while avoiding obstacles, replacing the empty cells of that square with a "full" character.

## Usage
```bash
./bsq map_file [map_file2 ...]
./bsq < map_file
cat map_file | ./bsq
```
- Accepts 1 to n files as arguments.
- If no arguments are given, reads a single map from **stdin**.
- Multiple files → outputs are separated by an empty line.

## Map File Format
```
<number_of_lines><empty_char><obstacle_char><full_char>
<map content>
```
- First line: a valid positive number (line count) followed by 3 distinct printable characters (empty, obstacle, full).
- All map lines must be the same length.
- At least one line, at least one cell.
- Only the 3 defined characters may appear on the map.

**Example:**

Input (`example_file`):
```
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o.................
```

Command:
```bash
./bsq example_file
```

Output:
```
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o.................
```

## Rules
- Biggest square found; ties broken by **topmost**, then **leftmost** position.
- Invalid file/map → prints `map error`, then continues to the next file (if any).

## Build
```bash
make
```
- Produces the `bsq` executable.
- Makefile must not relink.

## Allowed Functions
`open`, `close`, `read`, `write`, `malloc`, `free`, `exit`
