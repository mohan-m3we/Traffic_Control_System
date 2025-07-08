
---

# 🚦 Traffic Control System

Hi, this is **mohan-m3we (Mohan M)** 👋
This project is a **2D OpenGL-based simulation** of a traffic control system, developed using **C++ and GLUT**. It demonstrates basic graphics, keyboard interaction, and animation concepts using OpenGL.

---

## 🧠 Project Overview

* Simulates **day/night cycles**, traffic lights, moving cars, clouds, and sky elements
* Real-time interaction using keyboard for toggling signals and time of day
* Additional features include **aeroplane** and **comet** simulation via menu

---

## 🛠️ Technologies Used

* **C++**
* **OpenGL / GLUT** (Graphics Library)
* **Code::Blocks** IDE (Recommended for setup)
* **Windows Environment**

---

## ▶️ How to Run This Project

### 🧰 Step 1: Set Up Code::Blocks with OpenGL

To configure Code::Blocks for OpenGL programming, follow this tutorial:
📺 [YouTube Guide - Setup CodeBlocks with OpenGL](https://www.youtube.com/watch?v=ISK6_7YpmS0&t=132s&ab_channel=MoinulTutorials)

> Make sure you have Code::Blocks IDE and OpenGL libraries (GL/glut.h, etc.) properly installed.

---

### 🏁 Step 2: Build and Run

1. Open Code::Blocks
2. Create a new **Console Application** (select **C++** as the language)
3. Replace the contents of the main `.cpp` file with `traffic_control.cpp` code
4. Add required OpenGL libraries in project settings:

   ```
   -lglu32
   -lopengl32
   -lfreeglut
   ```
5. Click **Build and Run**

---

## ⌨️ Keyboard Controls

| Key | Action                |
| --- | --------------------- |
| `g` | Switch to Green Light |
| `r` | Switch to Red Light   |
| `d` | Day Mode              |
| `n` | Night Mode            |

---

## 🖱️ Right-Click Menu Options

* **Aeroplane** – Animates a plane in the sky
* **Comet** – Animates a comet in the night sky
* **Exit** – Closes the program

---

## 📷 Visual Output

* Blue sky with sun (day) or black sky with moon (night)
* Traffic signal circles (green or red)
* Animated car moving across the road
* Clouds and sky elements with movement
* Optional plane and comet animations

---

## 🌟 Like This Project?

If you found this project helpful or interesting, please consider giving it a ⭐️ on [GitHub](https://github.com/mohan-m3we/Traffic_Control_System)!

---

