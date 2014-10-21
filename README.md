Voxel game engine 2D
=====
This is a game engine which supports Voxels.

For Voxel definition please see wikipedia at:
http://en.wikipedia.org/wiki/Voxel

The engine is supposed to be handling 2D game Voxels.

Libaries:
 - SDL
 - SDL\_image
 - SDL\_mixer
 - pugixml (google)

The game uses XML configuration for scene loading.

The main part of the game is the scene, which is a simple plane.
The plane is split into voxels,little squares. The look of squares is defined by the configuration
