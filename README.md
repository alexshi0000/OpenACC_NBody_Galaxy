# OpenACC-PGI-NBODY
## Getting Started
#### clone this repository on to your machine
```
git clone https://github.com/alexshi0000/OpenACC-PGI-NBODY
```
## Prerequisites
#### NVIDIA gpu. recommended: NVIDIA Tesla k20 or higher. update drivers
```
sudo apt-get purge nvidia* 
sudo add-apt-repository ppa:graphics-drivers
sudo apt-get update
sudo apt-get install nvidia-370 (or better)
```
#### shutdown and check for new driver using smi. install glut
```
nvidia-smi
sudo apt-get install freeglut3 freeglut3-dev
```
#### install PGI compiler

https://developer.nvidia.com/openacc-toolkit

#### how to install CUDA (version 6 and up)

http://developer.download.nvidia.com/compute/cuda/7.5/Prod/docs/sidebar/CUDA_Installation_Guide_Linux.pdf

## Installation
#### using make
```
sudo apt install make
```

```
./../src/make pgi
```
#### or
```
sudo chmod +x ./../src/pgi_make.sh
./../src/pgi_make.sh
```
## Run
#### on linux
```
./../bin/main
```
#### on windows
```
./../bin/main.exe
```
## Results
 - particles: 112,640 
 - realization time: ~ 29 minutes
 
![Alt Text](https://github.com/alexshi0000/OpenACC-PGI-NBODY/blob/master/test/galaxyevo1.gif) 

- particles: 33,693
- realization time: ~ 9 minutes

![Alt Text](https://github.com/alexshi0000/OpenACC-PGI-NBODY/blob/master/test/galaxyevo2.gif)

## Hardware Specifications

#### CPU
AMD Phenom II X6 1090T @ 3.6GHz Six Core (HDT)
#### GP GPU
ASUS ROG Strix GeForce® GTX 1060, core clock @ 2133mhz, mem clock @ 9200mhz
#### RAM
8 gb 1666mhz kingston hyper x blu
