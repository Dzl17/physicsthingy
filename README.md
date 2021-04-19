# Physics Thingy
Little personal learning project I'm working on.
Heavily based (at least for now) on [this arcticle by Maddy Thorson](https://maddythorson.medium.com/celeste-and-towerfall-physics-d24bd2ae0fc5), developer of Celeste and Towerfall.

## Structure
- **Actors** are objects that interact with the level geometry.
- **Solids** are objects that "conform" the level, and do not check for collision between each other.

Both classes must be extended to be used.
