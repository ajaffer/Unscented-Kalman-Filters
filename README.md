# Unscented-Kalman-Filters


I ran my algorithm using the two dataset, the result is depicted below:

### Dataset 1: 
```
Accuracy - RMSE:
x: 0.0805515
y: 0.087509
vx: 0.186273
vy: 0.221425
```

![alt text](RMSE-Dataset-1.png "RMSE Dataset 1")

### Initialization of values 
I chose the following initial values

```Process noise standard deviation longitudinal acceleration in m/s^2
  std_a_ = 0.80;```

 ```Process noise standard deviation yaw acceleration in rad/s^2
  std_yawdd_ = (M_PI / 8);```

```x = initial_x, initial_y, 4.3, M_PI / 9, M_PI / 18;```

```P_ << 0.0043, -0.0013, 0.0030, -0.0022, -0.0020,
        -0.0013, 0.0077, 0.0011, 0.0071, 0.0060,
        0.0030, 0.0011, 0.0054, 0.0007, 0.0008,
        -0.0022, 0.0071, 0.0007, 0.0098, 0.0100,
        -0.0020, 0.0060, 0.0008, 0.0100, 0.0123;```