# 🎮 so_long 125/100

so_long is a game developed in C using the MLX library. It combines classic 2D gameplay with some bonus features. In this project, you'll find not only the basic mechanics of map traversal and collectible gathering, but also bonus elements like enemies that cause a Game Over on collision and animated sprites that bring the game world to life.

---

## Features

### **Mandatory Part**

- **Map-Based Gameplay**:  
  The game is set on a map defined by a `.ber` file that outlines the walls, empty spaces, collectibles, player start position, and exit. The map must be rectangular and completely enclosed by walls.

- **Basic Controls**:  
  The player can move using the WASD keys or the arrow keys. The objective is to collect all coins (collectibles) and reach the exit.

### **Bonus Part**

- **Enemies**:  
  Bonus enemies patrol the map. If the player collides with an enemy, the game immediately ends with a Game Over.

- **Animated Sprites**:  
  Both the player and the enemies feature animated sprites. These animations update periodically, adding fluidity and dynamism to the game visuals.

---

## How Flood Fill (Backtracking) Works

To ensure that every level is playable, so_long uses a **Flood Fill** algorithm (backtracking) during map validation. Here’s how it works:

1. **Starting Point**:  
   The algorithm begins at the player’s starting position.

2. **Recursive Traversal**:  
   It recursively explores all adjacent cells (up, down, left, right), marking visited cells to avoid infinite loops. This guarantees that each accessible cell is considered only once.

3. **Object Verification**:  
   As it traverses the map, it checks for essential elements such as the exit and collectibles. Counters keep track of the number of exits and collectibles found during the search.

4. **Validation Outcome**:  
   If the algorithm successfully visits all accessible cells and finds all required objects (one exit and at least one collectible), the map is deemed valid. Otherwise, the map is flagged as invalid.

This backtracking technique is crucial to prevent unsolvable maps and ensures a smooth gaming experience.

---

## Installation & Compilation

To compile so_long, simply run:

```sh
make
```
This command will compile the mandatory part of the project. If you want the bonus features as well, ensure your Makefile is set up to compile all components.

### Cleaning Up

- `make clean` – Removes object files.
- `make fclean` – Removes object files and the final executable/library.
- `make re` – Fully recompiles the madatory part of the project.
- `make rebonus` – Fully recompiles the complete project (Mandatory and Bonus).

## Usage

After compilation, run the game by passing a map file with a .ber extension:

```sh
./so_long map.ber
```
Controls
Movement: Use WASD or the arrow keys.

Objective: Collect all the coins, avoid enemies, and reach the exit.

---

## Notes

- **Render Optimization**:  
  Currently, the game redraws the entire map on every frame, regardless of whether a cell has changed or not. While this approach is simple and works well for small maps, it can negatively impact performance on larger maps or less powerful devices.  
  **Future Improvement**: Optimize rendering to update only the cells that change, reducing unnecessary drawing operations.

---

## License

This project was developed as part of the 42 School curriculum and serves as a practical exercise in C programming, graphics rendering using MLX, and algorithmic map validation. Special thanks to the community for providing invaluable resources and tutorials.

