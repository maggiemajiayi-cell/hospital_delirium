# hospital_delirium

An Arduino-based wearable system designed to monitor physiological and motion signals to support early detection of delirium risk in hospital and elder-care settings.

## Overview
This project explores the use of low-cost embedded hardware and sensor fusion to identify early physiological indicators associated with delirium. The wearable integrates pulse and motion sensing, processes real-time data on-device, and evaluates threshold-based indicators through repeated experimental trials.

The goal is to improve early monitoring while maintaining comfort, simplicity, and reliability for older adult users.

## Features
- Pulse monitoring using optical heart-rate sensing  
- Motion detection for activity and rest pattern analysis  
- Sensor calibration and noise reduction  
- Threshold-based event detection logic  
- Compact, wearable hardware form factor optimized for comfort  

## Hardware Components
- Arduino microcontroller  
- Pulse sensor (optical heart-rate sensor)  
- Motion sensor (accelerometer)  
- Supporting passive components and wearable enclosure  

## Methodology
- Calibrated raw sensor signals to account for baseline drift and user variability  
- Tested multiple detection thresholds to balance sensitivity and reliability  
- Validated data consistency across repeated trials  
- Iteratively refined hardware layout to reduce size and improve wearability  

## Results
- Achieved stable and repeatable sensor readings across test sessions  
- Improved detection reliability through threshold tuning  
- Produced a functional wearable prototype suitable for trial testing  

## Limitations & Future Work
- Incorporate additional physiological signals (e.g., SpO₂, temperature)  
- Implement onboard data logging or wireless transmission  
- Explore machine learning–based classification for improved accuracy  
- Conduct extended user trials in real clinical environments  

## Repository Structure

