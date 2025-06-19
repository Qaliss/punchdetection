# Data filters for smoother data

## Raw Data
Raw data after cleaning data. When recording data, the stream was scaled down to fit in EEPROM on the Arduino Nano. The data was then re-scaled back to raw values. This leads to some rounding issues, but more or less gets the job done. 

![image](https://github.com/user-attachments/assets/dcea788e-0d55-4634-b19c-9dbd142536da)


## Moving Average
Traverses through the datapoints, taking an average of the neighboring values for smoother graphs. 

![image](https://github.com/user-attachments/assets/ebdbad79-4c2f-4d91-ac28-8fdb0f55e80d)

## Savitzky-Golay
A moving window where a low-degree polynomial is generated to fit the points in that window. 

![image](https://github.com/user-attachments/assets/fc622305-2396-4c6b-b257-e32bbdebddce)


## Gaussian Filter
Applies a weighted average based on the distance of points. Closer points get more weight, farther points get less weight. 

![image](https://github.com/user-attachments/assets/b40b0ef1-71b7-4b03-99b3-42e3159c3873)

## Butterworth Filter
Transforms the data into a frequency, cuts out the top frequencies (hyperparameter that can be tuned), then reverts back to data. 

![image](https://github.com/user-attachments/assets/ab864d12-734b-4bdd-b837-7d9d0f487a83)


