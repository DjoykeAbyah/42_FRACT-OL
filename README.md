# ❄️ FRACT-OL ❄️
This project is about creating graphically beautiful fractals!

This is a small fractal exploration program called "fractol". It allows you to display and interact with various types of fractals, including the Julia set and the Mandelbrot set. The program utilizes the MLX42 library for graphical rendering.

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
2. Compile the program using the provided Makefile:
<pre>
to compile the proggram use the following command:
```shell
make
```


## Usage
Run the program with the following command:

``` bash ./fractol mandelbrot or ./fractol julia nbr nbr ```

- `nbr`: Additional rendering options for the julia set.

If no parameters are provided or an invalid parameter is given, the program displays a list of available parameters and exits properly.

## Features
- Display the Julia set and the Mandelbrot set.
- Zoom in and out using the mouse wheel, allowing infinite zooming within the limits of the computer.
- Create different Julia sets by passing different parameters to the program.
- Support for additional parameters as rendering options.
