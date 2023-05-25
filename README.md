# ✨ FRACT'OL ✨

<img width="993" alt="yes 1" src="https://github.com/DjoykeAbyah/FRACT-OL/assets/115019123/831d13fb-3296-47a2-a5a0-9ad544779bc4">

This project is about creating graphically beautiful fractals!

This is a small fractal exploration program called "fract'ol". It allows you to display and interact with various types of fractals, including the Julia set and the Mandelbrot set. The program utilizes the MLX42 library for graphical rendering.

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Wishlist](#wishlist)

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
- use the arrow keys to move the fractal around!
- you can adjust the number of iterations with the + and - keys (try it, it's fun!)
- when you choose the julia set right click hold with your mouse and move around for some extra fractal magic!

![gif1](https://github.com/DjoykeAbyah/FRACT-OL/assets/115019123/93064cba-edc9-4232-b097-57493514862d)

![gif3](https://github.com/DjoykeAbyah/FRACT-OL/assets/115019123/8e0f67cc-ba69-47b2-9207-84af18184b1e)


## Features
- Display the Julia set and the Mandelbrot set.
- Zoom in and out using the mouse wheel, allowing infinite zooming within the limits of the computer.
- Create different Julia sets by passing different parameters to the program.
- Support for additional parameters as rendering options.


## Wishlist
- Changing colors with a simple press on a key
- Adding different fractals
- Zoom on mouse position
- Gradient flow between iterations

<img width="994" alt="yes 2" src="https://github.com/DjoykeAbyah/FRACT-OL/assets/115019123/d75a881e-a900-414d-b41b-e9b251cd607f">

