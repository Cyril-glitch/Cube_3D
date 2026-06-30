*This project has been created as part of the 42 curriculum by cycolonn, nmichaud.*

# 🐺 cub3D - Technical Documentation

## 1. Description
**cub3D** is an introduction to the fundamentals of 3D graphics rendering using raycasting. Inspired by the legendary game *Wolfenstein 3D* (1992), this project challenges us to create a realistic 3D representation of a labyrinth from a strictly 2D map. 

The project highlights complex mathematical concepts such as the DDA (Digital Differential Analyzer) algorithm, vector geometry, Field of View (FOV) projection, and texture mapping, all handled entirely on the CPU using the basic MiniLibX graphic library.

<p align="center">
  <img src="./assets/CUB3D_DEMO.gif" alt="CUB3D Demo" height="100%" width="100%">
</p>

---

<br />

## 2. Instructions (How to Compile and Run)
To compile and launch the game engine, use the following commands:

---

<br />

    # Clone the repo
    git clone https://github.com/Cyril-glitch/cub3d.git

    # Compile the project
    cd cub3d
    make

    # Run the simulation with a valid map
    # Format: ./cub3D [path_to_map.cub]
    ./cub3D maps/level_01.cub

**Controls:**
* `W`, `A`, `S`, `D` - Move the player.
* `LEFT` / `RIGHT` Arrows or Mouse - Rotate the camera.
* `E` - Open or close doors.
* `ESC` - Exit the game cleanly.

---

<br />

## 3. Technical Choices & Engine Features
Our implementation follows specific technical decisions to optimize rendering and ensure strict adherence to the 42 Norm:

---

<br />

* **Map Validation (BFS / Flood Fill)**: Strict parsing of the `.cub` file using a Breadth-First Search approach to ensure the map is entirely enclosed by walls. Any misconfiguration results in a clean exit.
* **Raycasting Engine (DDA)**: Calculates the distance to the nearest wall for every vertical slice of the screen, correcting the "fisheye" effect using perpendicular wall distance.
* **Floor & Ceiling Casting**: Rendering the floor and ceiling pixel by pixel using horizontal scanlines and depth-to-distance interpolation for a realistic perspective effect.
* **Sprite Rendering & Z-Buffer**: Monsters and items are rendered using a 1D Z-Buffer to handle depth. Sprites are sorted by distance and drawn strictly if they are not hidden behind walls.
* **MiniLibX Optimization**: Direct memory access to images using `get_data_addr` and custom `put_pixel` functions to draw entire frames in an off-screen buffer before pushing them to the window.

---

<br />

## 4. Resources
Here are the essential references, mathematical documentation, and tools used to build this project:

---

<br />

* **Official Documentation**:
    * [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - The unofficial but essential guide to using the 42 graphic library.
* **Articles & Tutorials**:
    * [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - The absolute reference for understanding DDA and Wolfenstein 3D rendering mathematics.

### 🤖 Use of Artificial Intelligence (AI)
In accordance with the project rules, Artificial Intelligence (specifically Google's Gemini) was utilized strictly as an educational tutor for the following tasks:
* **Mathematical Understanding**: Deciphering and breaking down the complex vector mathematics behind the Frustum calculation, Raycasting (DDA), and the Floor Casting (Scanline) algorithm.
* **Breadth-First Search (BFS) Explanations**: Understanding the logic, implementation, and optimization of the BFS algorithm to properly validate the 2D map and ensure it is strictly enclosed by walls.
