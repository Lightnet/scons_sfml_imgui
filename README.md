Project Name: scons_sfml_imgui

License: CCO

Information: Simple compiler build test with scons script from python.

Compile default set to release build. Window 10 32bit. VS2017

Configs:(Window 10 Config Current build)
=======
To this project needed to install python to 2.7.x 32bit window with scons (http://scons.org/) installed with path varaible into the system. Scons is an tool builder like Visual Studio tool community but simpler and Visual Studio Code with using tasks clicks. Trying to keep it to bare minimal. If your on window. Before you build, check to have visual studio tool community install c/c++. The purpose for this project is to keep thing very simple and port to platform without much needed another need config and build for linux and mac os. Just test build.

Configs:
 * build_config.py
 * SConstruct (Scons build script compiler config)
 * .vscode
 * vsbuild_debug
 * vsbuild_release

Programs and Codes:
 * Visual Studio Code 
 * Viusal Studio Tool VS2017
 * Python 2.7.x
  * scons http://scons.org/
 * SFML 2.4.2 (Current in folder for testing purpose)
 * IMGUI 1.51 (Config setting for SMFL)

Credits:
 * https://github.com/eliasdaler/imgui-sfml

 Information: Help with the imgui setup build with SFML.

  * https://www.sfml-dev.org/tutorials/2.4/window-opengl.php

 Information: This deal with the 2D and 3D render together. For Simple cube and imgui render example hud type.

Notes:
 * lib warrnings first time build will show error. After that there is no errors when compile again.
 * Tends to get Dlls or Libs errors.