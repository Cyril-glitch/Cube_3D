*This project has been created as part of the 42 curriculum by cycolonn, nmichaud.*

# 🐺 cub3D - Technical Documentation

## 📖 1. Description
**cub3D** is a deep dive into the fundamentals of 3D graphics rendering using the mathematical principles of raycasting. Inspired by the legendary game *Wolfenstein 3D* (1992), this project challenges us to create a realistic 3D representation of a labyrinth starting from a strictly 2D map file. 

The primary goal is to navigate a dynamic maze from a first-person perspective, creating the illusion of 3D depth using only 2D calculations. To achieve this, the project relies heavily on complex mathematical concepts: the DDA (Digital Differential Analyzer) algorithm for precise ray-wall intersections, vector geometry for camera plane and player movement, Field of View (FOV) projection, and dynamic texture mapping.

Built entirely in **C** and strictly adhering to the 42 Norm, the engine processes everything on the CPU using the minimalistic MiniLibX graphic library. Despite these constraints, it features fully textured walls, a textured floor and ceiling rendered via horizontal scanlines, and animated, depth-sorted sprites (using a 1D Z-buffer), pushing the limits of what a basic C environment can render in real-time.

<p align="center">
  <img src="./assets/demo/CUB3D_DEMO.gif" alt="CUB3D Demo" height="100%" width="100%">
</p>

---

<br />

## 🚀 2. Instructions (How to Compile and Run)
To compile and launch the game engine, use the following commands:

---

<br />

```bash
# Clone the repo
git clone [https://github.com/Cyril-glitch/cub3d.git](https://github.com/Cyril-glitch/cub3d.git)

# Compile the project
cd cub3d
make

# Run the simulation with a valid map
# Format: ./cub3D [path_to_map.cub]
./cub3D /config/map.cub
```

**🎮 Controls:**
* 🚶 `W`, `A`, `S`, `D` - Move the player.
* 🔄 `LEFT` / `RIGHT` Arrows or Mouse - Rotate the camera.
* 🚪 `E` - Open or close doors.
* ❌ `ESC` - Exit the game cleanly.

---

<br />

## 🛠️ 3. Technical Choices & Engine Features
Our implementation follows specific technical decisions to optimize rendering and ensure strict adherence to the 42 Norm:

---

<br />

* 🧠 **Enemy Pathfinding (BFS)**: Implementation of a Breadth-First Search algorithm to allow sprites (monsters) to dynamically calculate the shortest path and follow the player through the labyrinth.
* 📏 **Raycasting Engine (DDA)**: Calculates the distance to the nearest wall for every vertical slice of the screen, correcting the "fisheye" effect using perpendicular wall distance.
* 🏁 **Floor & Ceiling Casting**: Rendering the floor and ceiling pixel by pixel using horizontal scanlines and depth-to-distance interpolation for a realistic perspective effect.
* 👾 **Sprite Rendering & Z-Buffer**: Monsters and items are rendered using a 1D Z-Buffer to handle depth. Sprites are sorted by distance and drawn strictly if they are not hidden behind walls.
* ⚡ **MiniLibX Optimization**: Direct memory access to images using `get_data_addr` and custom `put_pixel` functions to draw entire frames in an off-screen buffer before pushing them to the window.

---

<br />

## 📚 4. Resources
Here are the essential references, mathematical documentation, and tools used to build this project:

---

<br />

* 📄 **Official Documentation**:
    * [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - The unofficial but essential guide to using the 42 graphic library.
* 🔗 **Articles & Tutorials**:
    * [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - The absolute reference for understanding DDA and Wolfenstein 3D rendering mathematics.
    * [Lodev's Floorcasting Tutorial](https://lodev.org/cgtutor/raycasting2.html) - The reference for understanding horizontal scanline rendering and floor/ceiling texture mapping.
    * [Lodev's Sprite Casting](https://lodev.org/cgtutor/raycasting3.html) - The logic behind sprite positioning, animation, and Z-buffer usage in a raycaster.
    * [Breadth-First Search (BFS)](https://en.wikipedia.org/wiki/Breadth-first_search) - Wikipedia's overview of the BFS algorithm, serving as the foundation for our enemy pathfinding and tracking system.

### 🤖 Use of Artificial Intelligence (AI)
In accordance with the project rules, Artificial Intelligence (specifically Google's Gemini) was utilized strictly as an educational tutor for the following tasks:
* 📐 **Mathematical Understanding**: Deciphering and breaking down the complex vector mathematics behind the Frustum calculation, Raycasting (DDA), and the Floor Casting (Scanline) algorithm.
* 🔍 **Breadth-First Search (BFS) Explanations**: Understanding the logic, implementation, and optimization of the BFS algorithm to create a dynamic pathfinding system for monsters to follow the player.
