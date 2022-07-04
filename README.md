# I2C Detect

A simple sketch to scan for attached i2c addresses and to display their respective addresses.

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

Show device at the address `0x3C`.