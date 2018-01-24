# OpenACC-PGI-NBODY
## Getting Started
clone this repo on to your machine
```
git clone https://github.com/alexshi0000/OpenACC-PGI-NBODY/edit/master/README.md
```
## Prerequisites
make sure you have a NVIDIA gpu. Recommended: NVIDIA Tesla k20, NVIDIA GTX 780 or better. Update your gpu drivers 
```
sudo apt-get purge nvidia* 
sudo add-apt-repository ppa:graphics-drivers
sudo apt-get update
sudo apt-get install nvidia-370 (or better)
```
shutdown your computer and check your new driver using
```
nvidia-smi
```
install glut
```
sudo apt-get install freeglut3 freeglut3-dev
```
install PGI or CRAY compiler
https://developer.nvidia.com/openacc-toolkit
Install the latest version of CUDA here
http://developer.download.nvidia.com/compute/cuda/7.5/Prod/docs/sidebar/CUDA_Installation_Guide_Linux.pdf

## Installation
