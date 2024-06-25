# Configure opengl and glfw in linux (wsl fedora)

https://github.com/dhrubasaha08/WSL-Dev-Environment-C-CPP-OpenGL (WSL Ubuntu)

sudo dnf install git cmake g++ python

sudo dnf group install "C Development Tools and Libraries" "Development Tools"

Follow this tutorial - https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Linux
sudo dnf install glew-devel SDL2-devel SDL2_image-devel glm-devel freetype-devel

You can install the X11 dependencies and/or Wayland dependencies (In the GLFW site says that it does not need this libraries to build or run programs that use GLFW)

sudo dnf install libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel - X11 (Fedora)
sudo dnf install wayland-devel libxkbcommon-devel wayland-protocols-devel extra-cmake-modules - Wayland (Fedora)
sudo apt-get install libxcursor-dev libxi-dev libxinerama-dev libxrandr-dev - X11 (Ubuntu)
sudo dnf install wayland-dev libxkbcommon-dev wayland-protocols-dev extra-cmake-modules - Wayland (Ubuntu)

Go to the GLFW github and clone the repository
git clone https://github.com/glfw/glfw.git

cmake -S glfw -B glfw/build -D BUILD_SHARED_LIBS=ON - this is important so that the GLFW is build as a shared library

cd glfw/build and run make command

sudo make install

You may have to add the directory where the libglfw.so is to the environment variable $LD_LIBRARY_PATH, in my case was /usr/local/lib64/

I'am using Visual Studio Code with the extensions C/C++ and C/C++ Extension Pack.

Add to your task.json under args, this "-lglfw", "-lGLU", "-lGL". You can try to run this in the terminal aswell

Install glew - https://glew.sourceforge.net/install.html

git clone https://github.com/nigels-com/glew.git

cd glew

make extensions

make

sudo make install

add "-lGLEW" in the task.json or in the g++ command


