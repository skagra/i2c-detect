# I2C Detect

An *Arduino* sketch to scan for attached `i2c` devices and to display their respective addresses.

Output takes the following format:

```
I2C Detect

Scanning for I2C devices

08  -- -- -- -- -- -- -- -- 
10  -- -- -- -- -- -- -- -- 
18  -- -- -- -- -- -- -- -- 
20  -- -- -- -- -- -- -- -- 
28  -- -- -- -- -- -- -- -- 
30  -- -- -- -- -- -- -- -- 
38  -- -- -- -- 3C -- -- -- 
40  -- -- -- -- -- -- -- -- 
48  -- -- -- -- -- -- -- -- 
50  -- -- -- -- -- -- -- -- 
58  -- -- -- -- -- -- -- -- 
60  -- -- -- -- -- -- -- -- 
68  -- -- -- -- -- -- -- -- 
70  -- -- -- -- -- -- -- -- 

Done
```

The above shows a device detected at the address `0x3C`.