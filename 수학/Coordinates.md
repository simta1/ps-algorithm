### 두 점 $ (x1, x2), (y1, y2) $을 지나는 방정식 :   

$ \frac {y - y1}{x - x1}= \frac{y2 - y1}{x2 - x1}$   
$=> (y2 - y1)(x-x1) + (x1 - x2)(y-y1) = 0$   


```cpp
// ax + by + c = 0
a = y2 - y1;
b = x1 - x2;
c = -a * x1 - b * y1;
```

### $(mx, my)$에서 내린 수선의 발 $(x, y)$:

$\frac {y2 - y1}{x2 - x1} \cdot \frac {y - my}{x - mx} = -1$   
$\frac {y - y1}{x - x1} = \frac {y2 - y1}{x2 - x1}$   



$(y - my)(y2 - y1) + (x - mx)(x2 - x1) = 0$   
$(y2 - y1)(x - x1) + (x1 - x2)(y - y1) = 0$   

```cpp
// -bx + ay = c
//  ax + by = d
a = y2 - y1;
b = x1 - x2;
c = a * my - b * mx;
d = a * x1 + b * y1;
x = (-b * c + a * d) / (a * a + b * b)
y = (a * c + b * d) / (a * a + b * b)
```