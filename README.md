# 42_get_next_line

### Small Description
  - This project is a subtle introduction to the world of X Window System, for that we use the Minilibx from the 42 School. We aim to render fractals using only the CPU, without the aid of threads or the GPU.

### How are the Fractals Draw
  - We iterate over a function ($P(z) = z^2 + c$) and check if the point we started goes to infinity or stays bounded to the starting point. The color is based on how fast the point goes about the treshhold, which in our case if (|z| > 2). If it stays in a pattern close to the starting point, it belongs to the mandelbrot set and it's colored black.