#!python
import os

#--------
# Config files
#--------
SDL2_INCLUDE_PATH = 'C:\\SDL2-2.0.5\\include'
SDL2_LIB_PATH = 'C:\\SDL2-2.0.5\\lib\\x86'
IMGUI_PATH = 'imgui'
#--------
# folder dir and output folder or file
#--------

projectname = 'sfml_scene'				#holds the project name
projectpackage = 'src'						#holds the project folder
#buildroot = './bin/' + projectmode			#holds the root of the build directory tree
builddir = './' + projectpackage  			#holds the build directory for this project
#targetpath = buildroot + '/' + projectname	#holds the path to the executable in the build directory
#-------

#thirdparty_libs = []
#thirdparty_includes = []

#--include files
include_packages = []
include_packages.append('SFML-2.4.2\\include')
include_packages.append('imgui')

#--engine node packages
core_packages = []

#--lib
lib_packages = []
lib_packages.append('imgui')
lib_packages.append('opengl32')

lib_packages.append('sfml-window')
lib_packages.append('sfml-system')
#lib_packages.append('sfml-audio')
lib_packages.append('sfml-graphics')
#lib_packages.append('sfml-network')
#lib_packages.append('sfml-main')
#lib_packages.append('flac')
#lib_packages.append('freetype')
#lib_packages.append('jpeg')
#lib_packages.append('ogg')
#lib_packages.append('vorbisenc')
#lib_packages.append('vorbisfile')


dll_packages = []
dll_packages.append('sfml-audio-2')
dll_packages.append('sfml-graphics-2')
dll_packages.append('sfml-network-2')
dll_packages.append('sfml-system-2')
dll_packages.append('sfml-window-2')

#dll_packages.append('sfml-audio-d-2')
#dll_packages.append('sfml-graphics-d-2')
#dll_packages.append('sfml-network-d-2')
#dll_packages.append('sfml-system-d-2')
#dll_packages.append('sfml-window-d-2')

#--add list
lib_packages += core_packages
include_packages +=core_packages

lib_files = []

SFML_LIBS = 'SFML-2.4.2\\lib'
SFML_BIN = 'SFML-2.4.2\\bin\\'
#SFML_LIBS = 'C:\\sfml-build\\lib\\Release'

#lib_files.append("SFML-2.4.2\\lib\\sfml-graphics-s.lib")
lib_files.append(SFML_LIBS + "\\sfml-graphics.lib")
lib_files.append(SFML_LIBS + "\\sfml-audio.lib")
lib_files.append(SFML_LIBS + "\\sfml-network.lib")
lib_files.append(SFML_LIBS + "\\sfml-system.lib")
lib_files.append(SFML_LIBS + "\\sfml-window.lib")