# miniRT
<p align="center">
  <img src="https://github.com/Firemanarg/minirt/assets/35619327/0b80e4bd-4301-4541-b1d8-e669af93f010" alt="miniRT Logo">
  <img src="https://github.com/Firemanarg/minirt/assets/35619327/f785397b-9a6e-42c4-9269-39fa68025615" alt="miniRT Title">
  <br>
  MiniRT is a graphic project from 42School curriculum.<br>It consists in an implementation of a basic render engine<br>using the raytracing technique.
</p>

## Table of Contents
- [Table of Contents](#table-of-contents)
- [About the Project](#about-the-project)
  - [Introduction](#introduction)
    - [Supported Objects](#supported-objects)
  - [Preview](#preview)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)

## About the Project
### Introduction
This project is a straightforward implementation of ray tracing, as part of the 42School projects. It is capable of rendering a scene specified by a file containing 3D objects and more.<br>
Ray tracing is a technique used to generate realistic images by simulating lights and shadows. It involves projecting rays from the camera to each screen pixel, then detecting collisions to calculate the color of that pixel.
<br>
<p align="center">
  <img width=400 src="https://github.com/Firemanarg/minirt/assets/35619327/27dd4c5c-2936-4f52-9fc3-361282c4c794">
  <br>
  <a href="https://developer.nvidia.com/discover/ray-tracing">Ray Tracing basics</a>
</p>
To render images, the program requires a scene file containing all the objects in a scene. The program reads and parses the file into abstract data structures. It then iterates through each pixel, projecting a ray (with the camera as the origin of the ray) and calculates the pixel's color by checking if it is influenced by light. After calculating the colors of all pixels, the image is generated. This process may take longer when there are numerous objects in the scene.<br>

#### Supported Objects
- <b>Camera:</b> Definitions of the view for the render;
- <b>Ambient Light:</b> Basic light to define the darkest level of shadows;
- <b>Light:</b> Point light in 3d space;
- <b>Sphere:</b> 3d sphere in 3d space;
- <b>Cylinder:</b> 3d cylinder in 3d space;
- <b>Plane:</b> Infinite plane in 3d space, rendered by both sides (top and bottom);
- <b>Cone (bonus only):</b> 3d cone in 3d space.

### Preview
<table>
  <tr>
    <tc>
      <img width=400 src="https://github.com/Firemanarg/minirt/assets/35619327/c8075061-1cb9-4af5-b963-56618b0c90bf">
    </tc>
    <tc>
      <img width=400 src="https://github.com/Firemanarg/minirt/assets/35619327/5b1b6ad1-1ca2-47db-90ac-802229618c28">
    </tc>
  </tr>
</table>

## Getting Started

### Prerequisites
### Installation

## Usage
