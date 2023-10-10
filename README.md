# oneTri

Application for live-coding fragment shaders.

All dependencies are self-contained in this project using git's submodule system.

## Installation

```
git clone https://github.com/eqdiag/oneTri
cd oneTri
mkdir build
cd build
cmake ..
```

## Available Variables
  *  `aspect` = Aspect ratio of window 
  *  `mouse` = Mouse (X,Y) location where X,Y range from [0,1]
  *  `time` = Time (measured in seconds) since start of shader program
  *  `uv` = Coordinates of fragment/pixel normalized to [0,1] range

## Usage
For default fragment shader basic.fs run:
```
./oneTri
```
For custom fragment shader fragShader.fs run:
```
./oneTri fragShader.fs 
```

## Keyboard Controls

  * `R` Reload shader program
  * `ESC` Exit program


## Future Additions
* Hot reloading shader
                       
## Copyright and Attribution
Copyright (c) 2023 eqdiag. Released under the [MIT License](https://github.com/eqdiag/oneTri/blob/main/LICENSE.md).
