# ❄️ FRACT'OL ❄️
![image](https://im3.ezgif.com/tmp/ezgif-3-8859c06f30.png)
This project is about creating graphically beautiful fractals!

This is a small fractal exploration program called "fract'ol". It allows you to display and interact with various types of fractals, including the Julia set and the Mandelbrot set. The program utilizes the MLX42 library for graphical rendering.

## Table of Contents
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)

## Requirements
- MLX42 library
- C compiler
- Standard C libraries (open, close, read, write, malloc, free, perror, strerror, exit)
- Math library (-lm compiler option)

## Installation
1. Clone the repository or download the source code files.
2. Compile the program using the provided Makefile by simply running:

```$ make```


## Usage
To embark on a fractal adventure, run the program with the following command:

``` $ ./fractol mandelbrot```

or

```$ ./fractol julia nbr nbr ```

- `nbr`: lets you play around with additional options for the Julia set..
![image](https://im3.ezgif.com/tmp/ezgif-3-c5645b814a.gif![image](https://github.com/DjoykeAbyah/FRACT-OL/assets/115019123/994c8fc7-5df4-4f60-8641-4e6472ededaf)
)

## Features
- Display the Julia set and the Mandelbrot set.
- Zoom in and out using the mouse wheel, allowing infinite zooming within the limits of the computer.
- Create different Julia sets by passing different parameters to the program.
- Support for additional parameters as rendering options.

![image](https://im3.ezgif.com/tmp/ezgif-3-e8569e9688.png)
