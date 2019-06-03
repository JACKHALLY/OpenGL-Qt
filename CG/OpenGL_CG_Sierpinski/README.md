# Description
1. Choose three fixed points T<sub>0</sub>, T<sub>1</sub>, and T<sub>2</sub> to form some triangle, as shown in the following figure.

![the initial three points](./figs/description_fig1.png)

2. Choose the inital point P<sub>0</sub> to be drawn by selecting one of the points T<sub>0</sub>, T<sub>1</sub>, and T<sub>2</sub> at random.

Now iterate the following steps until the pattern is satifyingly filled in.

3. Choose one of the three points T<sub>0</sub>, T<sub>1</sub>, and T<sub>2</sub> at random, call it T.
4. Construct the next point P<sub>k</sub> as the midpoint between T and previously found point P<sub>k-1</sub>. That is,
$$P_k = midpoint of P_{k-1} and T$$
5. draw P<sub>k</sub>

## Example
The following figure shows a few iterations of the foregoing procedure. Suppose the initial point P<sub>0</sub> happens to be T<sub>0</sub>, and let T<sub>1</sub> to chosen next. Then P<sub>1</sub> is formed so that it lies halfway between T<sub>0</sub> and T<sub>1</sub>. Suppose T<sub>2</sub> is chosen next, so that P<sub>2</sub> lies between P<sub>1</sub> and T<sub>2</sub>. Next, suppose T<sub>1</sub> is chosen again, so that P<sub>3</sub> is formed as shown, etc.

![a few itreations of Sierpinski](./figs/description_fig2.png)

# Result
![the result of Sierpinski](./figs/result.png)
