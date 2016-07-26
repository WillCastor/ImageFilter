# ImageFilter
efficient c++ image filter, all algorithms finish in O(1) time
## Layer blend mode
### source picture
![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/test.jpg)
## Filter
### basic
filter name     | parameter                       | result
----------------|---------------------------------|---------------------------------------------------------------------------------------------------
soft light      | (opacity:1.0)                   |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/filter_basic_softlight.jpg)
warming up      | (opacity:0.7)                   |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/filter_basic_warming_up.jpg)

### lomo
filter name     | parameter                       | result
----------------|---------------------------------|---------------------------------------------------------------------------------------------------
film            | (opacity:1.0)                   |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/filter_lomo_film.jpg)
impression      | (opacity:0.8)                   |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/filter_lomo_impression.jpg)
youth           | (opacity:0.8)                   |![image](https://github.com/vxh7/ImageFilter/raw/master/doc/images/filter_lomo_youth.jpg)
