## raytracing_by_c
ratracing using C.

in minilibx-linux folder, you have to put "mlx.h" and "libminilibx_Linux.a" from this repogitory<br>
https://github.com/42Paris/minilibx-linux

## Usage

The scene must be correctly formatted.<br>
This project is using the ``Minilibx`` using the Metal framework and therefore should work only on macOS 10.13+.<br>

## Features :
* Objects : ``sphere`` ``triangle`` ``cube`` ``square`` ``plane`` ``cylinder`` 


```shell
# Compile the binary
make
# Execute the binary with a .rt file
./miniRT [scene_path]
```

## about RT file :
We use RT file to show images.
this is RT file example
```rt
R 500 100
A 0.1 255,255,255


l  15,15,-15   0.9   255,255,255
l  15,-15,-15  0.9    255,255,255
c    0,20,0    0,-1,0    60
C     -20,3,0  1,0,0    60

sp  5,0,0   3   255,0,0
pl  0,-4,0    0,1,0   100,100,100
sq   5,0,0   10   255,0,0
tr  -3,-5,-2   3,-5,-3   0,5,0   255,255,255
cy  -5,-1,0    0,1,0   4  2   0,255,0
```
### explanation of each line.
In RT file, you can divide each line by multiple `\n` and each elements in line is devided multiple spaces.
``Resolution``
this meas Windowsaize.
```rt
R 500   100
```
First Capital ``R`` meas, this line is Resolution line. Second varinable means window width(500),  third varinable means window hitgh(100).<br>
If the window size is larger than your desctop Window size, the window size resize. Width and hight have to unsig.<br>

``Ambient light``
this line means ambient light.

```rt
A 0.1  255,255,255
```

``light``
This line means spot light.


``sphere``
This line means sphere.

``plane``


``square``


``triangle``


``cylinder``

