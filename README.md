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
sq   5,0,0  5,5,5 10   255,0,0
tr  -3,-5,-2   3,-5,-3   0,5,0   255,255,255
cy  -5,-1,0    0,1,0   4  2   0,255,0
```
### explanation of each line.
In RT file, you can divide each line by multiple `\n` and each elements in line is devided multiple spaces.<br>

``Resolution``
this meas Windowsaize.
```rt
R 500   100
```
First Capital `R` meas, this line is Resolution line. Second varinable means window width(500),  third varinable means window hitgh(100).<br>
If the window size is larger than your desctop Window size, the window size resize. Width and hight have to unsig.<br>

``Ambient light``
This line means ambient light.
```rt
A 0.1  255,255,255
```
`A` means anbient light. Second double paramerter is light strength ratio. Normaly, this is around `0.1`. <br>This parameter have to `0 ~ 1`<br>
Next elements means RGB color in range `0 ~ 255`(int).<br>

``light``
This line means spot light.
```rt
l  15,15,-15   0.9   255,255,255
```
``l``means lgith line.<br>
Second double paramerter is light strength ratio. Normaly, this is around `0.1`. This parameter have to `0 ~ 1`<br>
Next elements means RGB color in range `0 ~ 255`(int).<br>

``camera``
This line means camera information.<br>
```rt
c    0,20,0    0,-1,0    60
```
``c`` means camera line.<br>
Second elements means x,y,z coordinates of the view point.<br>
Third elements means 3d normalized orientation vector in range `-1 ~ 1`. Last elements Horizontal field of view in degrees in range `0 ~ 180`<br>

``sphere``
This line means sphere.<br>
```rt
sp  5,0,0   3   255,0,0
```
``sp`` means sphere line. Second elements means x,y,z coordinates of the sphere centor(`type double`).<br>
Third elements means the sphere diameter(`type double`).Last elements means RGB color(`type int`).<br>

``plane``
This line means plane.<br>
```rt
pl  0,-4,0    0,1,0   100,100,100
```
``pl`` means plane line. Second elements means x,y,z coordinates of the point on the plane(`type double`).<br>
Third elements means the 3d normalized orientation vector in range `-1 ~ 1`(`type double`). Last elements <br>means RGB color(`type int`).<br>

``square``
This line means square.<br>
```rt
sq   5,0,0  5,5,5   10    255,0,0
```
``sq`` means plane line. Second elements means x,y,z coordinates of the centor of the square(`type double`).<br>
Third elements means the 3d normalized orientation vector in range `-1 ~ 1`(`type double`).<br>
Forth elements means the square's size(`type int`)<br>
Last elements means RGB color(`type int`).<br>

``triangle``
This line means .<br>
```rt
tr  -3,-5,-2   3,-5,-3   0,5,0   255,255,255
```
``tr`` means triangle line.Second to forth elements means x,y,z coordinates of the eghe of the triangle.<br>
Last elements means RGB color(`type int`).<br>


``cylinder``

This line means sphere.<br>
```rt
cy  -5,-1,0    0,1,0   4  2   0,255,0
```
``cy`` means cylinder line.Second elements means x,y,z coordinates of the cylinder's bottom plane centor.<br>
Third elements means the 3d normalized orientation vector in range `-1 ~ 1`(`type double`).<br>
Forth elements means cylinder diameter(`type double`).<br>
Fifth elements means cylinder height(`type double`).<br>
Last elements means RGB color(`type int`).<br>