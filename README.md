# _cub3d
*Simple version of Raycaster-Game Wolfenstein 3D*

**How to use**

1. You can create your own map by simple rules:
- R  - screen resolution
- NO - texture path
- SO - texture path
- WE - texture path
- EA - texture path
- S  - sprite path
- F  - floor color in rgb
- C  - ceilling color in rgb
- Map: 1 - wall, 0 - void, 2 - sprite, NSWE - player

```
*simple map*

111111111111111111
111000000000000011
1220000N00000000001
1000000000000002211
11111111111111111
```

map extension - .cub, texture extension - .xpm

2. Control key
- W - move forward
- S, D - move left/right
- keyleft, keyright - rotate the viewing angle left/right
- ESC - close program

3. Start
- <make default> start default map with Wolfenstein 3D textures. 
- <make custom> start custom map with custom textures (created by PS)
- make && ./cub3D path_to/textutes
  
  
**Result**
![cub3d.gif](https://github.com/budelphine/_cub3d/blob/main/cub3d.gif)

