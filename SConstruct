#!python 
import platform
import os
import sys
import glob
from build_support import *
from build_config import *

print("Scons Script Build!")
projectmode = ARGUMENTS.get('mode', 'release')   #holds current mode
projecttool = 'window'

#check if the user has been naughty: only 'debug' or 'release' allowed
if not (projectmode in ['debug','release']):
	print("Error: expected 'debug' or 'release', found: " + projectmode)

#tell the user what we're doing
print('**** Compiling in ' + projectmode + ' mode...')

#--------
# application folder dir and output folder
#--------
buildroot = './bin/' + projectmode	#holds the root of the build directory tree
targetpath = buildroot + os.sep + projectname	#holds the path to the executable in the build directory
#-------

if projecttool == 'window': #window tool default to vs2017
	#http://scons.org/doc/0.97/HTML/scons-man.html
	#need to lanuch vcvars32.bat script so it can be add to os.environ else it will display 'cl' is not recognized as an internal or external command
	#this will deal with the Visual Studio 
	env = Environment(ENV = os.environ) #this load user complete external environment
else:
	#default current tool from os
	env = Environment(ENV = os.environ) #this load user complete external environment
	#pass

system = platform.system()

#--------
# Operating System Checks and Tools
#--------
if system=='Windows':
	print("**** Window Tool")
	# Something to do with link error
	#https://msdn.microsoft.com/en-us/library/y0zzbyt4.aspx
	#env.Append(LINKFLAGS=['/SUBSYSTEM:CONSOLE'])
	if projectmode == 'debug':
		#env.Append(CPPDEFINES = ['SFML_STATIC'])
		#env.Append(CPPFLAGS=['_DEBUG'])
		#env.Append(CPPFLAGS=['WINDOW'])
		pass
	if projectmode == 'release':
		pass
	#env.Append(CPPDEFINES = ['SFML_STATIC']) 
	#env.Append(CPPFLAGS=['-DOPENGL_ENABLED'])
	
	env.Append(CPPPATH=include_packages) #include files
	#build lib file
	#--imgui
	env.Library(buildroot + os.sep +  'imgui',Glob(SRC_PATH + os.sep  + IMGUI_PATH + os.sep +  '*.cpp')) #Imgui
	#--SFML
	#env.Library(buildroot + 'sfml' , lib_files,CCFLAGS='-MD -MF')
	#env.Library(buildroot + 'sfml-graphics' , SFML_LIBS + '\\sfml-graphics.lib')
	#env.Library(buildroot + 'sfml-system.' , SFML_LIBS + '\\sfml-system.lib')
	#env.Library(buildroot + 'sfml-window' , SFML_LIBS + '\\sfml-window.lib')
	#env.Library(buildroot + 'sfml' , Glob(SFML_LIBS +"\\*.lib"))

	if projectmode == 'release':
		lib_files.append(SFML_LIBS + os.sep + "sfml-graphics.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-audio.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-network.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-system.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-window.lib")
		env.Library(buildroot + os.sep +'sfml' , lib_files)
		#pass
	if projectmode == 'debug':
		lib_files.append(SFML_LIBS + os.sep + "sfml-graphics-s-d.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-audio-s-d.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-network-s-d.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-system-s-d.lib")
		lib_files.append(SFML_LIBS + os.sep + "sfml-window-s-d.lib")
		env.Library(buildroot + os.sep + 'sfml' , lib_files)
		#pass

	#copy file or folder to bin dir
	#http://scons.org/doc/1.2.0/HTML/scons-user/c2848.html
	#SFML library.dll
	for basename in dll_packages:
		env.Install(buildroot, SFML_BIN + basename + ".dll") #copy dll to output
	#env.Install(buildroot,Glob("SFML-2.4.2\\bin\\*.dll") #copy dll to output
	#exeute application 
	env.Program(targetpath, Glob(builddir + os.sep + '*.cpp'), LIBS=lib_packages, LIBPATH=['.',SFML_LIBS, buildroot])
print("**** Scons Script End!")
