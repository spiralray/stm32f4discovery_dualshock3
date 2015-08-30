stm32f4discovery_dualshock3
=================

Sample program of wired DUALSHOCK3

This program was made with the help of [ChiaYen Kan](https://www.youtube.com/watch?v=amEsLdh6Qe8). Thank you!

## NOTICE
SpiralRay uses following INTELLECTUAL PROPERTIES under each licence.
Those source code are included in this project.

## LIBRARIES
* [Nemui Trinomius's TFT/OLED Control Sample with ChaN's FatFs.](http://nemuisan.blog.bai.ne.jp/?eid=192848)

* Andrew Brown's [stm32plus](https://github.com/andysworkshop/stm32plus). 
  Using [this fork](https://github.com/spiralray/stm32plus) to support STM32F103CBT6
  

* [rosserial](http://wiki.ros.org/rosserial)

## Usage
First, install [GNU Tools for ARM Embedded Processors](https://launchpad.net/gcc-arm-embedded) and add PATH.

Second, Install stm32plus using [this project](https://gist.github.com/0dfe899d1230ff1a5522.git) (Ubuntu or OS X is required)

```
git clone https://gist.github.com/0dfe899d1230ff1a5522.git install_stm32plus
cd install_stm32plus
sh install_stm32plus.sh
```

the library will be built on ~/workspace

And finally, clone this project into ~/workspace
