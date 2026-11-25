# Glove For Deaf 🧤

An embedded system that translates sign language into text on an LCD.
Final project for the AMIT embedded systems course.

## Overview

Five flexible (flex) sensors are mounted on the fingers of a glove.
Each sensor detects the bending of its finger. According to the posture
of the fingers, the corresponding word is displayed on the LCD.
When a new word is detected, the old word is cleared.

## Demo Video

[![Glove For Deaf Demo](https://img.youtube.com/vi/p42csw2ilu4/0.jpg)](https://youtu.be/p42csw2ilu4)

## Features

- 5 flex sensors, one on each finger
- Fast response to finger motion
- At least 15 supported words
- Old word is cleared when a new one is activated
- Layered architecture (APP / HAL / MCAL)

## Components

- Microcontroller: **ATmega32**
- 5x flexible sensors
- Glove
- LCD (16x2)
- Wires

## Project Structure

| Folder | Description |
|--------|-------------|
| `APP`  | Main application logic (private submodule, source not publicly available) |@'
# Glove For Deaf 🧤

An embedded system that translates sign language into text on an LCD.
Final project for the AMIT embedded systems course.

## Overview

Five flexible (flex) sensors are mounted on the fingers of a glove.
Each sensor detects the bending of its finger. According to the posture
of the fingers, the corresponding word is displayed on the LCD.
When a new word is detected, the old word is cleared.

## Demo Video

[![Glove For Deaf Demo](https://img.youtube.com/vi/p42csw2ilu4/0.jpg)](https://youtu.be/p42csw2ilu4)

## Features

- 5 flex sensors, one on each finger
- Fast response to finger motion
- At least 15 supported words
- Old word is cleared when a new one is activated
- Layered architecture (APP / HAL / MCAL)

## Components

- Microcontroller: **ATmega32**
- 5x flexible sensors
- Glove
- LCD (16x2)
- Wires

## Project Structure

| Folder | Description |
|--------|-------------|
| `APP`  | Main application logic (private submodule, source not publicly available) |
| `HAL`  | Hardware drivers: `HADC` (ADC handling), `LCD` |
| `MCAL` | Microcontroller drivers: `DIO`, `MADC` registers |
| `utils`| Common types (`STD_TYPES.h`) and bit-math macros (`bit_math.h`) |

> **Note:** The `APP` folder is a private Git submodule, so it will appear empty
> or inaccessible unless you have been granted access.

## How It Works

1. Each flex sensor is connected to an ADC channel.
2. The ADC reads the bending value of each finger.
3. The application compares the readings with thresholds to detect the posture.
4. The matching word is printed on the LCD.

## Tools

- Atmel Studio
- Embedded C

## Author

Omar - AMIT Embedded Systems Training
