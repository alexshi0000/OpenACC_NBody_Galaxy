# OpenACC-PGI-NBODY
## Getting Started
#### clone this repository on to your machine
```
git clone https://github.com/alexshi0000/OpenACC-PGI-NBODY/edit/master/README.md
```
## Prerequisites
#### make sure you have a NVIDIA gpu. Recommended: NVIDIA Tesla k20 or GTX 780Ti. Update your gpu drivers.
```
sudo apt-get purge nvidia* 
sudo add-apt-repository ppa:graphics-drivers
sudo apt-get update
sudo apt-get install nvidia-370 (or better)
```
#### shutdown your computer and check your new driver
```
nvidia-smi
sudo apt-get install freeglut3 freeglut3-dev
```
#### install PGI compiler

https://developer.nvidia.com/openacc-toolkit

#### how to install CUDA

http://developer.download.nvidia.com/compute/cuda/7.5/Prod/docs/sidebar/CUDA_Installation_Guide_Linux.pdf

## Installation
#### using make
```
sudo apt install make
```

```
./../src/make pgi
```
##### or
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
## Gallery
![Alt Text](https://github.com/alexshi0000/OpenACC-PGI-NBODY/blob/master/test/galaxyevo1.gif)
![Alt Text](https://github.com/alexshi0000/OpenACC-PGI-NBODY/blob/master/test/galaxyevo2.gif)
#### total time to realize: ~10 minutes
