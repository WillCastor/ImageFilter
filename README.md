# ImageFilter
efficient c++ image filter, all algorithms finish in O(1) time
## Layer blend mode
### source picture
![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/test.jpg)


blend mode      | parameter                       | result
----------------|---------------------------------|-------------------------------------------------------------------------------------
normal          | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/normal.jpg)
darken          | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/darken.jpg)
multiply        | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/multiply.jpg)
color burn      | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/color_burn.jpg)
linear burn     | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/linear_burn.jpg)
lighten         | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/lighten.jpg)
screen          | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/screen.jpg)
color doge      | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/color_doge.jpg)
linear doge     | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/linear_doge.jpg)
overlay         | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/overlay.jpg)
hard light      | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/hardlight.jpg)
soft light      | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/softlight.jpg)
linear light    | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/linear_light.jpg)
pin light       | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/pin_light.jpg)
difference      | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/difference.jpg)
exclusion       | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/exclusion.jpg)
subtract        | (r:200,g:200,b:100,opacity:0.6) |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/subtract.jpg)
